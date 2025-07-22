void setupSD(void);
void fetchDirectory();
void sdLoadDisk(const char *);
void sdUnloadDisk();
void sdFetchCylinder(int cylNum);
void sdFlushSector();

#define SECTOR_WORDS 267         // Length of one sector on the SD card
#define CYLINDER_WORDS (SECTOR_WORDS * 24)  // Length of one cylinder
#define CYLINDER_BYTES (2 * CYLINDER_WORDS)
extern uint16_t cylinderData[];      // Data from the SD card for one cylinder
