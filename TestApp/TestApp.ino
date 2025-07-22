/**
 * Main program.
 * Dependencies:
 * Adafruit_GFX
 * Adafruit_ILI9341
 */
#include "gui.h"
#include "board.h"
#include "sd.h"

// Main entry point
void setup(void) {
  Serial.println("setupBoard...");
  setupBoard();
  Serial.println("setupGUI...");
  setupGui();
  setupSD();

  fetchDirectory();
  displaySelector();
}


void loop()
{
  loopBoard();
}
