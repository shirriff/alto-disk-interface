#include "Arduino.h"

#include <Adafruit_GFX.h>    // Core graphics library
#include <SPI.h>
#include <Adafruit_ILI9341.h>
#include <XPT2046_Touchscreen.h>

#include "gui.h"
#include "board.h"

char diskNames[MAX_FILES][MAX_LEN];
int numDisks;

// Images, exported as C source code from GIMP
// Diablo banner image is 240x83
#include "diablo.c"
// 32x32 icons
#include "arrow-up.c"
#include "arrow-down.c"
#include "arrow-up-gray.c"
#include "arrow-down-gray.c"
// Buttons
#include "load.c"
#include "unload.c"

#define BUTTON_WIDTH 90

#define GUI_SELECTING 1
#define GUI_LOADED 2
#define GUI_DEBUG 3
int guiMode = GUI_SELECTING;

XPT2046_Touchscreen ts(CS_PIN, TIRQ_PIN);  // Param 2 - Touch IRQ Pin - interrupt enabled polling

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

// Disk list selector

// Clean up the file name to fit
char buf[MAX_LEN];
// str must be null-terminated and same length as buf (which will be the case since it is from diskNames[])
const char *displayName(const char *str) {
  strcpy(buf, str);
  buf[MAX_DISPLAY_LEN] = '\0'; // Truncate to display length
  char *suffix = strstr(buf, ".");
  if (suffix) {
    *suffix = '\0'; // Truncate the .DSK
  }
  return buf;
}

int listTop = 0; // Index in diskNames of the top item on the screen
int listHighlight = -1; // Index in items on screen of the highlighted item. -1 if no highlight
void displaySelector() {
  tft.fillRect(0, BANNER_HEIGHT, WIDTH, HEIGHT - BANNER_HEIGHT, ILI9341_LIGHTGREY);
  if (numDisks > LIST_LENGTH) {
    // Scroll icons
    if (listTop > 0) {
      tft.drawRGBBitmap(WIDTH - ICON_SIZE, BANNER_HEIGHT, (uint16_t *)arrowUp.pixel_data, ICON_SIZE, ICON_SIZE);
    } else {
      tft.drawRGBBitmap(WIDTH - ICON_SIZE, BANNER_HEIGHT, (uint16_t *)arrowUpGray.pixel_data, ICON_SIZE, ICON_SIZE);
    }
    if (listTop + LIST_LENGTH < numDisks) {
      tft.drawRGBBitmap(WIDTH - ICON_SIZE, HEIGHT - ICON_SIZE, (uint16_t *)arrowDown.pixel_data, ICON_SIZE, ICON_SIZE);
    } else {
      tft.drawRGBBitmap(WIDTH - ICON_SIZE, HEIGHT - ICON_SIZE, (uint16_t *)arrowDownGray.pixel_data, ICON_SIZE, ICON_SIZE);
    }
  }
  tft.setCursor(0, BANNER_HEIGHT);
  Serial.println(numDisks, DEC);
  for (int i = 0; i < numDisks && i < LIST_LENGTH; i++) {
    if (i == listHighlight) {
      tft.setTextColor(ILI9341_GREEN, ILI9341_RED);
    } else {
      tft.setTextColor(ILI9341_BLUE, ILI9341_LIGHTGREY);
    }
    tft.println(displayName(diskNames[i + listTop]));
  }
  if (listHighlight >= 0) {
    tft.drawRGBBitmap(0, HEIGHT - ICON_SIZE, (uint16_t *)load.pixel_data, BUTTON_WIDTH, ICON_SIZE);
  }
}
void debugMode(); // forward

void selectorTouch(TS_Point & p) {
  if (p.x >= WIDTH - ICON_SIZE) {
    if (p.y > BANNER_HEIGHT && p.y < BANNER_HEIGHT + ICON_SIZE && listTop - LIST_LENGTH >= 0) {
      // Scroll up
      listTop -= LIST_LENGTH;
      listHighlight = -1;
      displaySelector();
    } else if (p.y > HEIGHT - ICON_SIZE && listTop + LIST_LENGTH < numDisks) {
      // Scroll down
      listTop += LIST_LENGTH;
      listHighlight = -1;
      displaySelector();
    }
  } else if (p.y > BANNER_HEIGHT && p.y < HEIGHT - ICON_SIZE) {
    // Click on a line
    listHighlight = (p.y - BANNER_HEIGHT) / 16;
    if (listTop + listHighlight > numDisks) {
      listHighlight = -1;
    }
    Serial.printf("Click %d %d: line %d\n", p.x, p.y, listHighlight);
    displaySelector();
  } else if (listHighlight >= 0 && p.x < BUTTON_WIDTH && p.y > HEIGHT - ICON_SIZE) {
    // load button press
    tft.fillRect(0, BANNER_HEIGHT, WIDTH, HEIGHT - BANNER_HEIGHT, ILI9341_LIGHTGREY);
    loadDisk(diskNames[listTop + listHighlight]);
    tft.drawRGBBitmap(0, HEIGHT - ICON_SIZE, (uint16_t *)unload.pixel_data, BUTTON_WIDTH, ICON_SIZE);
    guiMode = GUI_LOADED;
    tft.setCursor(0, BANNER_HEIGHT);
    tft.setTextColor(ILI9341_BLACK, ILI9341_LIGHTGREY);
    tft.println("Disk loaded:");
    tft.println(diskNames[listTop + listHighlight]);
  }
}

void loadedTouch(TS_Point & p) {
  if (p.x < BUTTON_WIDTH && p.y > HEIGHT - ICON_SIZE) {
    // unload button press
  unloadDisk();
  guiMode = GUI_SELECTING;
  listTop = 0;
  listHighlight = -1;
  displaySelector();
  }
}

// Initialization
void setupGui() {
  Serial.println("setupGui start");

  tft.begin();

  if (!ts.begin()) {
    Serial.println("Couldn't start touchscreen controller");
    stop();
  }
  ts.setRotation(2);

  Serial.println("Touchscreen started");

  tft.fillScreen(ILI9341_BLACK);
  tft.drawRGBBitmap(0, 0, (uint16_t *)banner.pixel_data, 240, 83);

  tft.setTextSize(2);
  tft.setCursor(0, BANNER_HEIGHT);
  tft.setTextColor(ILI9341_RED, ILI9341_BLACK);
  Serial.println("setupGui done");
}

void debugMode() {
  tft.fillScreen(ILI9341_BLACK);
  tft.setCursor(0, 16);
  tft.setTextColor(ILI9341_RED, ILI9341_BLACK);
  tft.println("Debug mode");
  // guiMode = GUI_DEBUG;
  debug = 1;
  Serial.println("Debug mode");
}

void debugTouch(TS_Point & p) {
  tft.fillCircle(p.x, p.y, 3, 123); // debugging
}

bool touched = false; // True if we are handling a touch

// Main event loop
void loopGui() {
  // Getting the touchscreen code right is a bit tricky because touches get buffered.
  // What we want is to handle a new touch, rather than handling dragging.
  if (!ts.touched()) {
    touched = false;
    return;
  }

  if (ts.bufferEmpty()) {
    // no event to handle.
    return;
  }

  if (touched) {
    // Dragging
    led(WHITE);
    return;
  }

  TS_Point p;
  while (!ts.bufferEmpty()) {
    p = ts.getPoint(); // Get last point in buffer
    Serial.printf("loopGuiTouch point%d %d\n", p.x, p.y);
    led(YELLOW);

  }

  // Scale from ~0->4000 to screen coordinates
  p.x = map(p.x, TS_MINX, TS_MAXX, 0, WIDTH);
  p.y = map(p.y, TS_MINY, TS_MAXY, 0, HEIGHT);
    Serial.printf("gui got point %d %d\n", p.x, p.y);

  if (p.x > WIDTH - 100 && p.y < BANNER_HEIGHT - 8) {
    debugMode();
  }
  Serial.printf("%d %d\n", p.x, p.y);
  if (guiMode == GUI_SELECTING) {
    selectorTouch(p);
  } else if (guiMode == GUI_LOADED) {
    loadedTouch(p);
  } else if (guiMode == GUI_DEBUG) {
    debugTouch(p);
  }
  touched = true;
}

// Write an error string on the display and stop
void displayError(const char *s) {
  tft.setTextSize(3);
  tft.fillRect(0, BANNER_HEIGHT, WIDTH, HEIGHT - BANNER_HEIGHT, ILI9341_RED);
  tft.setCursor(0, BANNER_HEIGHT + 10);
  tft.setTextColor(ILI9341_BLACK, ILI9341_RED);
  tft.println(s);
  stop();
}
