

#define WIDTH 240 // Touchscreen width in pixels
#define HEIGHT 320 // Touchscreen height in pixels
#define LIST_LENGTH 13 // Number of lines in disk list

#define ICON_SIZE 32
#define BANNER_HEIGHT 84

// This is calibration data for the raw touch data to the screen coordinates
#define TS_MINX 150
#define TS_MINY 130
#define TS_MAXX 3800
#define TS_MAXY 3800

// Touchscreen pins
#define CS_PIN  8
#define TIRQ_PIN  2

// TFT display pins
#define TFT_CS 10
#define TFT_DC 9

#define MAX_FILES 100
#define MAX_LEN 64 // Maximum file name length
#define MAX_DISPLAY_LEN 17 // Maximum length that will fit on screen
extern char diskNames[MAX_FILES][MAX_LEN];
extern int numDisks;

extern void setupGui();
extern void loopGui();
extern void displaySelector();
extern void displayError(const char *);
