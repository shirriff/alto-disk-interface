#include "Arduino.h"
#include "board.h"
#include "gui.h"
#include "sd.h"

/*
   Handle the disk I/O.

   State signals:
   IDLE -> LOADED when a disk is loaded
   On Strobe: read track address / restore, activate address acknowledge (or LAI on error)
   Restore + Strobe: move to track 0, Address Ack
   Head select: held for duration of read/write
   SRW
   Sector mark: 5 microsecond pulse every 3.33 ms, output sector number
   Write gate: start processing data
   Read gate: start feeding data. Need to handle switching to write gate in middle of sector.
   Outputs:
   Ready: disk loaded, ready to go
   SRW: Ready and not in the middle of a seek; can perform operation.
   Addr Ack: seek has been accepted and started. 2.5 to 7.5 usec wide pulse. Happens between 22.5 and 47.5 usec after Strobe. Alternative is LAI for bad track
   Seek incomplete: a fault during the seek. Held until Restore is issued.
   Sector marks: 5 usec pulse on each sector slot
   Sector address: updated on leading edge of each sector mark.

*/

#define STATE_UNLOADED 1
#define STATE_LOADED 2

volatile int state = STATE_UNLOADED;
boolean disconnected = false;  // Running in disconnected mode



// Sector variables
IntervalTimer sectorTimer;
volatile int sectorCount;
volatile unsigned long sectorStartMicros;  // Time at sector start


// Setup board stuff
void setupBoard() {
  pinMode(SECTOR, OUTPUT);
  pinMode(RD_CLK, OUTPUT);
  pinMode(RD_DATA, OUTPUT);
  pinMode(LAI, OUTPUT);
  pinMode(SRW, OUTPUT);
  pinMode(SEEK_INCMP, OUTPUT);
  pinMode(ADR_ACK, OUTPUT);
  pinMode(READY, OUTPUT);
  pinMode(SECT1, OUTPUT);
  pinMode(SECT2, OUTPUT);
  pinMode(SECT4, OUTPUT);
  pinMode(SECT8, OUTPUT);

  digitalWrite(SECTOR, OFF);
  digitalWrite(RD_CLK, OFF);
  digitalWrite(RD_DATA, OFF);
  digitalWrite(LAI, OFF);
  digitalWrite(SRW, OFF);
  digitalWrite(SEEK_INCMP, OFF);
  digitalWrite(ADR_ACK, OFF);
  digitalWrite(READY, OFF);
  digitalWrite(SECT1, OFF);
  digitalWrite(SECT2, OFF);
  digitalWrite(SECT4, OFF);
  digitalWrite(SECT8, OFF);

  // Inputs are active-low. Outputs are also active-low, but the driver is an inverter.
  pinMode(WR_DATA, INPUT);
  pinMode(SEL1, INPUT);
  pinMode(SEL4, INPUT);
  pinMode(CYL1, INPUT);
  pinMode(CYL2, INPUT);
  pinMode(CYL4, INPUT);
  pinMode(CYL8, INPUT);
  pinMode(CYL16, INPUT);
  pinMode(CYL32, INPUT);
  pinMode(CYL64, INPUT);
  pinMode(CYL128, INPUT);
  pinMode(RESTORE, INPUT);
  pinMode(STROBE, INPUT);
  pinMode(WR_GATE, INPUT);
  pinMode(RD_GATE, INPUT);
  pinMode(HEAD_SEL, INPUT);

  // flash green, just to show board is active
  analogWrite(LED_G, 256);  // Inverted, so 256 is off
  analogWrite(LED_R, 256);
  analogWrite(LED_B, 256);
  delay(250);
  analogWrite(LED_G, 128);
  delay(250);
  analogWrite(LED_G, 256);
  led(RED);
  delay(1000);
  led(GREEN);
  delay(1000);
  led(BLUE);
  delay(1000);
  Serial.println("setupBoard done");
  if (digitalRead(RD_GATE) == 0 || digitalRead(WR_GATE) == 0 || digitalRead(STROBE) == 0) {
    Serial.println("Disconnected mode");
    disconnected = true;
  }
}

// Print input vector if it changes.
// Inputs are active-low.
int lastInput = -1;
void inTest() {
  int n = 0;
  if (digitalReadFast(WR_DATA)) n |= 1;
  if (digitalReadFast(SEL1)) n |= 2;
  if (digitalReadFast(SEL4)) n |= 4;
  if (digitalReadFast(CYL1)) n |= 8;
  if (digitalReadFast(CYL2)) n |= 16;
  if (digitalReadFast(CYL4)) n |= 32;
  if (digitalReadFast(CYL8)) n |= 64;
  if (digitalReadFast(CYL16)) n |= 128;
  if (digitalReadFast(CYL32)) n |= 256;
  if (digitalReadFast(CYL64)) n |= 512;
  if (digitalReadFast(CYL128)) n |= 1024;
  if (digitalReadFast(RESTORE)) n |= 2048;
  if (digitalReadFast(STROBE)) n |= 4096;
  if (digitalReadFast(WR_GATE)) n |= 8192;
  if (digitalReadFast(RD_GATE)) n |= 16384;
  if (digitalReadFast(HEAD_SEL)) n |= 32768;

  if (n != lastInput) {
    Serial.print("Inputs: ");
    Serial.print(0x7fff ^ n, HEX);
    if (!(n & 1)) {
      Serial.print(" WR_DATA");
    }
    if (!(n & 2)) {
      Serial.print(" SEL1");
    }
    if (!(n & 4)) {
      Serial.print(" SEL4");
    }
    int cyl = (~(n >> 8)) & 0xff;

    Serial.printf(" CYL %d", cyl);

    if (!(n & 2048)) {
      Serial.print(" RESTORE");
    }

    if (!(n & 4096)) {
      Serial.print(" STROBE");
    }

    if (!(n & 8192)) {
      Serial.print(" WR_GATE");
    }

    if (!(n & 16384)) {
      Serial.print(" RD_GATE");
    }

    if (!(n & 32768)) {
      Serial.print(" HEAD_SEL");
    }
    Serial.println("");
    lastInput = n;
  }
}

int debug = 0;

int blink = 1;
unsigned long lastSectorStartMicros = 0;

// The main loop function to handle board operations.
// This returns at the end of each sector or if there is a GUI op.
void loopBoard() {
  if (debug) {
    inTest();
  }
  if (state != STATE_LOADED) {
    loopGui();
    led(BLUE);
    return;
  }
  if (lastSectorStartMicros == sectorStartMicros) {
    Serial.println("Unexpected sector in loopBoard");
    stop();
    return;
  }

  led(GREEN);
  // Start of a new sector
  lastSectorStartMicros = sectorStartMicros;
  // Check for 400 µs if any read/write/strobe request.
  while (micros() < lastSectorStartMicros + 400) {
    if (!disconnected) {
      if (digitalReadFast(RD_GATE) == 0) {
        read();
        break;
      } else if (digitalReadFast(WR_GATE) == 0) {
        write();
        break;
      } else if (digitalReadFast(STROBE) == 0) {
          strobe();
      }
    }
  }

  // Done with sector processing, so check the GUI
  loopGui();
  led(WHITE);
  // Wait for end of sector
  while (lastSectorStartMicros == sectorStartMicros) {
    loopGui();
  }
}

// Indicate a status through the LED, mostly debugging.
// LEDs are active-low so 255 is off
void led(long color) {
  analogWrite(LED_R, (color >> 16) ^ 0xff);
  analogWrite(LED_G, ((color >> 8) & 0xff) ^ 0xff);
  analogWrite(LED_B, (color & 0xff) ^ 0xff);
}

// Stop execution by going into an infinite loop
void stop() {
  // Flash red light
  while (1) {
    led(WHITE);
    delay(250);
    led(RED);
    delay(250);
  }
}

// Sector logic

void sectorPulseReset();

// Interrupt routine to update sector count
void sectorUpdate() {
  sectorStartMicros = micros();
  sectorCount = (sectorCount + 1) % 12;
  digitalWriteFast(SECT1, (sectorCount & 1) ? ON : OFF);
  digitalWriteFast(SECT2, (sectorCount & 2) ? ON : OFF);
  digitalWriteFast(SECT4, (sectorCount & 4) ? ON : OFF);
  digitalWriteFast(SECT8, (sectorCount & 8) ? ON : OFF);
  digitalWriteFast(SECTOR, ON);
  sectorTimer.begin(sectorPulseReset, 4 /* microseconds */);  // Want 5 μs width, but have 1 μs overhead
}

// I should have used a PWM for SECTOR. But since I didn't, I'll use another interrupt to turn SECTOR off.
void sectorPulseReset() {
  digitalWriteFast(SECTOR, OFF);
  sectorTimer.begin(sectorUpdate, 3333 - 5 /* microseconds */);
}

// In the real Diablo disk, sector pulses are gated by spindle speed, write check ok, and drive selected.
void startSectorPulses() {
  // Sector mark: 5 microsecond pulse every 3.33 ms, output sector number
  sectorTimer.begin(sectorUpdate, 3333 /* microseconds */);
}

void stopSectorPulses() {
  sectorTimer.end();
}

// Load the disk
void loadDisk(char *name) {
  sdLoadDisk(name);
  state = STATE_LOADED;
  digitalWrite(READY, ON);
  digitalWrite(SRW, ON);
  startSectorPulses();
}

// Unload the disk
void unloadDisk() {
  stopSectorPulses();
  sdUnloadDisk();
  state = STATE_UNLOADED;
  digitalWrite(READY, OFF);
}

