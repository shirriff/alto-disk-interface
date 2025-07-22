// Outputs: note outputs are inverted
#define SECTOR 26
#define RD_CLK 39
#define RD_DATA 32
#define LAI 28
#define SRW 24
#define SEEK_INCMP 25
#define ADR_ACK 17
#define READY 19
#define SECT1 7
#define SECT2 5
#define SECT4 16
#define SECT8 31

#define LED_R 14 // Red and blue swapped
#define LED_B 15
#define LED_G 18

// Inputs
#define WR_DATA 6
#define SEL1 23
#define SEL4 36
#define CYL1 20
#define CYL2 22
#define CYL4 41
#define CYL8 30
#define CYL16 37
#define CYL32 33
#define CYL64 21
#define CYL128 34
#define RESTORE 40
#define STROBE 27
#define WR_GATE 29
#define RD_GATE 35
#define HEAD_SEL 38

// Outputs are active-low, but are driven through inverters.
// So writing a 1 pulls the board output low, which logically enables the signal.
#define OFF 0
#define ON 1

extern void setupBoard();
extern void loopBoard();
extern void stop(); // Infinite loop
#define BLACK 0x000000
#define RED 0xff0000
#define GREEN 0x00ff00
#define BLUE 0x0000ff
#define WHITE 0xC0ff60
#define MAGENTA 0x8000ff
#define YELLOW 0x80ff00
extern void led(long); // Light LED with specified color

extern void loadDisk(char *name);
extern void unloadDisk();

extern int debug; // flag
extern volatile int sectorCount;

extern void read();
extern void write();
extern void strobe();

// Insert N nops into the code.
// Inspired by https://github.com/tni/teensy-samples and https://stackoverflow.com/questions/26983548 and https://stackoverflow.com/questions/38484512
namespace {
template<size_t N> inline static void insertNops() {
    asm volatile ("nop");
    insertNops<N-1>();
}
template<> inline void insertNops<0>() {}
}

