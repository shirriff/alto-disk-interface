#include "Arduino.h"
#include "board.h"
#include "sd.h"

void prepareSector(int sectorNum);
void transmitSector();

/*
 * Handle a read request.
 */
void read() {
  Serial.println("Read request");
  prepareSector(sectorCount);
  transmitSector();
}

#define SECTOR_RAW_LEN 326
// Code to transmit a sector
uint16_t rawData[SECTOR_RAW_LEN];  // Sector contents

// Process the sectorData from the dsk file, converting it to rawData to transmit.
// Specifically, the sectorData contains 266 words: 2 header words, 8 label words, and 256 data words.
// This function adds the preambles, sync bits, checksums, and postambles.
// It also reverses the data, since it is transmitted last-word-first.
// The result is the 326-word buffer of raw data to transmit.
void prepareSector(int sectorNum) {
  uint16_t *sectorData = cylinderData + sectorNum * SECTOR_WORDS;
  bzero(rawData, sizeof(rawData));
  uint16_t *rawPtr = rawData;
  rawPtr += 28;                                   // 28-word preamble
  *rawPtr++ = 1;                                  // Sync
  *rawPtr++ = sectorData[1];                      // Header
  *rawPtr++ = sectorData[0];                      // Header
  *rawPtr++ = 0x151 ^ rawData[29] ^ rawData[30];  // Checksum
  // 6 + 4 words postamble and preamble
  rawPtr += 10;
  *rawPtr++ = 1;  // Sync
  uint16_t checksum = 0x151;
  for (int i = 0; i < 8; i++) {
    // 8-word label
    uint16_t wrd = sectorData[2 + 7 - i];
    *rawPtr++ = wrd;
    checksum ^= wrd;
  }
  *rawPtr++ = checksum;
  // 6 + 4 words postamble and preamble
  rawPtr += 10;
  *rawPtr++ = 1;  // Sync
  checksum = 0x151;
  for (int i = 0; i < 256; i++) {
    // 256-word data
    uint16_t wrd = sectorData[10 + 256 - i];
    *rawPtr++ = wrd;
    checksum ^= wrd;
  }
  *rawPtr++ = checksum;
  // 6 words postamble, bringing total to 326 words
  rawPtr += 6;
  if (rawPtr - rawData != SECTOR_RAW_LEN) {
    Serial.printf("Bad data size %d instead of 326\n", rawPtr - rawData);
    stop();
  }
}

#define DELAY100 insertNops<120>()
#define DELAY200 insertNops<240>()

// It would be cool to implement this with a shift register or timers, but toggling the lines directly seems
// like the most straightforward approach.
// Pre-assembling the preamble/postamble/checksum keeps the timing even, rather than doing it while
// transmitting.
void transmitSector() {
  cli();
  for (int i = 0; i < SECTOR_RAW_LEN * 16; i++) {
    uint16_t dataWord = rawData[i >> 4];
    int dataBit = dataWord & (1 << (15 - (i % 16)));
    if (digitalReadFast(RD_GATE)) {  // Only send if RD_GATE is active XXX adjust timing
      if (dataBit) {
        // Write a 1
        digitalWriteFast(RD_CLK, ON);  // clk on
        DELAY100;
        digitalWriteFast(RD_CLK, OFF);  // clk off
        DELAY200;
        digitalWriteFast(RD_DATA, ON);  // data on
        DELAY100;
        digitalWriteFast(RD_DATA, OFF);  // data off
      } else {
        // Write a 0
        digitalWriteFast(RD_CLK, ON);  // clk on
        DELAY100;
        digitalWriteFast(RD_CLK, OFF);  // clk off
        DELAY200;
        digitalWriteFast(RD_DATA, OFF);  // data off
        DELAY100;
        digitalWriteFast(RD_DATA, OFF);  // data off
      }
      // Delay a bit shorter because of loop overhead to get 600ns total
      insertNops<130>();
    } else {
      // READ GATE blocking read
      digitalWriteFast(RD_CLK, OFF);   // clk off
      digitalWriteFast(RD_DATA, OFF);  // data off
      insertNops<330>();
      insertNops<330>();
    }
  }
  sei();
}
