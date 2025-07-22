#include <SdFat.h>
#include "board.h"
#include "gui.h"
#include "sd.h"

const uint8_t SD_CS_PIN = SS;
SdFs sd;
FsFile dir;
FsFile file;

void setupSD(void) {
  if (!sd.begin(SdioConfig(FIFO_SDIO))) {
    displayError("SD initialization failed.");
  }
}


uint16_t cylinderData[CYLINDER_WORDS];      // Data from the SD card for one cylinder

// Fetch the directory and fill in the diskNames array.
void fetchDirectory() {
  if (!dir.open("/")) {
    displayError("SD open failed.");
  }

  numDisks = 0;
  while (file.openNext(&dir, O_RDONLY) && numDisks < MAX_FILES) {
    if (file.isDirectory()) {
      // Ignore
    } else if (file.size() == 2601648) {  // Only process files of the right length
      int len = file.getName(diskNames[numDisks], MAX_LEN);
      if (len >= MAX_LEN) {
        Serial.printf("File name too long: %s\n", diskNames[numDisks]);
        continue;  // Drop the name
      }
      numDisks++;
    }
    file.close();
  }
  if (numDisks == 0) {
    displayError("No disks on SD card");
  }
  dir.close();
}

void sdLoadDisk(const char *name) {
  if (!file.open(name)) {
    Serial.printf("Open failed %s\n", name);
    displayError("open failed");
  }
  sdFetchCylinder(0);
  Serial.println("Fetch of first cylinder");  // Should fetch a whole track
}

void sdUnloadDisk() {
  file.close();
}

/**
 * Fetches a cylinder from the SD file system.
 * The file system holds 267-word sectors:
 * zero word, 2 header words,
 * 8 label words, and 256 data words.
 * This fills 24 sectors.
 */
void sdFetchCylinder(int cylNum) {
  Serial.printf("sdFetchCylinder %d\n", cylNum);
  if (!file.seekSet(CYLINDER_BYTES * cylNum)) {
    displayError("seek failed");
    return NULL;
  }
  if (!file.read(cylinderData, CYLINDER_BYTES)) {
    displayError("read failed");
    return NULL;
  }
  if (debug) {
    for (int i = 0; i < 20; i++) {
      Serial.println(((uint32_t *)cylinderData)[i], HEX);
    }
  }
  Serial.println("sdFetchSector done");
}

void sdFlushSector() {
}
