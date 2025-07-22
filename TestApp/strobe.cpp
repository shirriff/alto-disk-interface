#include "Arduino.h"
#include "board.h"
#include "sd.h"

/*
 * Handle a strobe request.
 */
void strobe() {
  Serial.println("Strobe request");
  int cylinder = 0;
  if (digitalReadFast(RESTORE) == ON) {
    Serial.println("Restore");
    led(MAGENTA);
    cylinder = -1;
  } else {
    Serial.println("Strobe");
    led(YELLOW);
    // Input bits are active-low, so xor with FF to flip them all.
    cylinder = 0xff ^ ((digitalReadFast(CYL128) << 7) | (digitalReadFast(CYL64) << 6) | (digitalReadFast(CYL32) << 5) | (digitalReadFast(CYL16) << 4) | (digitalReadFast(CYL8) << 3) | (digitalReadFast(CYL4) << 2) | (digitalReadFast(CYL2) << 1) | digitalReadFast(CYL1));
  }
  delayMicroseconds(3);    // Minimum 2.5 μs from Strobe to SRW high (max 24.5 μs). Maintenance manual 3.6.2
  digitalWrite(SRW, OFF);  // No longer ready to seek/read/write
  delayMicroseconds(20);   // Minimum 22.5 μs from Strobe to ack (max 47.5 μs). Maintenance manual 3.6.2
  if (cylinder > 202) {
    // Bad cylinder number, so issue LAI
    digitalWriteFast(LAI, ON);
    delayMicroseconds(5);  // Minimum 2.5 μs, max 7.5 μs)
    digitalWriteFast(LAI, OFF);
  } else {
    // Address ack
    digitalWriteFast(ADR_ACK, ON);
    delayMicroseconds(5);  // Minimum 2.5 μs, max 7.5 μs)
    digitalWriteFast(ADR_ACK, OFF);
    if (cylinder != -1) {
      Serial.printf("Strobe of cylinder %d\n", cylinder);
      sdFetchCylinder(cylinder);
    }
  }
  digitalWrite(SRW, ON);  // Ready to seek/read/write
  // Strobe must be removed within 5 microseconds of ack. So hopefully we won't immediately re-enter strobe().
}
