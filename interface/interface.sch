EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A 11000 8500
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L interface-rescue:LED_RGBC-Device D1
U 1 1 60B8569E
P 9950 6250
F 0 "D1" H 9950 6750 50  0000 C CNN
F 1 "LED_RGBC" H 9950 6657 50  0000 C CNN
F 2 "SparkFun:LED-RGB-THRU" H 9950 6200 50  0001 C CNN
F 3 "~" H 9950 6200 50  0001 C CNN
	1    9950 6250
	-1   0    0    -1  
$EndComp
$Comp
L interface-rescue:R_US-Device R1
U 1 1 60B8AE24
P 9600 6050
F 0 "R1" V 9390 6050 50  0000 C CNN
F 1 "180" V 9483 6050 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 9640 6040 50  0001 C CNN
F 3 "~" H 9600 6050 50  0001 C CNN
	1    9600 6050
	0    1    1    0   
$EndComp
$Comp
L interface-rescue:R_US-Device R2
U 1 1 60B8DBF9
P 9600 6250
F 0 "R2" V 9390 6250 50  0000 C CNN
F 1 "100" V 9483 6250 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 9640 6240 50  0001 C CNN
F 3 "~" H 9600 6250 50  0001 C CNN
	1    9600 6250
	0    1    1    0   
$EndComp
$Comp
L interface-rescue:R_US-Device R3
U 1 1 60B8E598
P 9600 6450
F 0 "R3" V 9390 6450 50  0000 C CNN
F 1 "100" V 9483 6450 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 9640 6440 50  0001 C CNN
F 3 "~" H 9600 6450 50  0001 C CNN
	1    9600 6450
	0    1    1    0   
$EndComp
$Comp
L interface-rescue:Conn_01x40_Female-Connector J1
U 1 1 60B8FA63
P 650 3050
F 0 "J1" H 541 5138 50  0000 C CNN
F 1 "Conn_01x40_Female" H 541 5045 50  0000 C CNN
F 2 "interface:connector-2x20" H 650 3050 50  0001 C CNN
F 3 "~" H 650 3050 50  0001 C CNN
	1    650  3050
	-1   0    0    -1  
$EndComp
$Comp
L interface-rescue:Conn_01x14_Female-Connector J2
U 1 1 60B9DDEC
P 9700 4850
F 0 "J2" H 9728 4826 50  0000 L CNN
F 1 "Screen connector" H 9728 4733 50  0000 L CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x14_Pitch2.54mm" H 9700 4850 50  0001 C CNN
F 3 "~" H 9700 4850 50  0001 C CNN
	1    9700 4850
	1    0    0    -1  
$EndComp
$Comp
L interface-rescue:C-Device C3
U 1 1 60BA1D0D
P 3200 750
F 0 "C3" H 3315 797 50  0000 L CNN
F 1 ".1uF" H 3315 704 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Disc_D3.0mm_W1.6mm_P2.50mm" H 3238 600 50  0001 C CNN
F 3 "~" H 3200 750 50  0001 C CNN
	1    3200 750 
	1    0    0    -1  
$EndComp
$Comp
L interface-rescue:C-Device C4
U 1 1 60BBF206
P 3150 3050
F 0 "C4" H 3265 3097 50  0000 L CNN
F 1 ".1uF" H 3265 3004 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Disc_D3.0mm_W1.6mm_P2.50mm" H 3188 2900 50  0001 C CNN
F 3 "~" H 3150 3050 50  0001 C CNN
	1    3150 3050
	1    0    0    -1  
$EndComp
$Comp
L interface-rescue:C-Device C1
U 1 1 60BBF557
P 8800 950
F 0 "C1" H 8915 997 50  0000 L CNN
F 1 ".1uF" H 8915 904 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Disc_D3.0mm_W1.6mm_P2.50mm" H 8838 800 50  0001 C CNN
F 3 "~" H 8800 950 50  0001 C CNN
	1    8800 950 
	1    0    0    -1  
$EndComp
$Comp
L interface-rescue:C-Device C2
U 1 1 60BBF98A
P 8700 2900
F 0 "C2" H 8815 2947 50  0000 L CNN
F 1 ".1uF" H 8815 2854 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Disc_D3.0mm_W1.6mm_P2.50mm" H 8738 2750 50  0001 C CNN
F 3 "~" H 8700 2900 50  0001 C CNN
	1    8700 2900
	1    0    0    -1  
$EndComp
Text Label 6650 2850 0    50   ~ 0
GND
Text Label 4450 1450 2    50   ~ 0
GND
Text Label 3200 600  0    50   ~ 0
VCC5
Text Label 3150 2900 0    50   ~ 0
VCC5
Text Label 8800 800  0    50   ~ 0
VCC3
Text Label 8700 2750 0    50   ~ 0
VCC3
Text Label 3200 900  0    50   ~ 0
GND
Text Label 3150 3200 0    50   ~ 0
GND
Text Label 8800 1100 0    50   ~ 0
GND
Text Label 8700 3050 0    50   ~ 0
GND
Text Label 10150 6250 0    50   ~ 0
GND
Text Label 2700 4650 0    50   ~ 0
GND
Text Label 2700 2350 0    50   ~ 0
GND
Text Label 8300 2600 0    50   ~ 0
GND
Text Label 8300 4650 0    50   ~ 0
GND
Text Label 8300 3050 0    50   ~ 0
VCC3
Text Label 8300 1000 0    50   ~ 0
VCC3
Text Label 2700 3050 0    50   ~ 0
VCC5
Text Label 2700 750  0    50   ~ 0
VCC5
Text Label 9500 4250 2    50   ~ 0
VCC5
Text Label 9500 4350 2    50   ~ 0
GND
Text Label 9500 4450 2    50   ~ 0
CS
Text Label 9500 4550 2    50   ~ 0
VCC3
Text Label 9500 4650 2    50   ~ 0
DC
Text Label 9500 4750 2    50   ~ 0
SDI
Text Label 9500 4850 2    50   ~ 0
SCK
Text Label 9500 4950 2    50   ~ 0
LED
Text Label 9500 5050 2    50   ~ 0
SDO
Text Label 9500 5150 2    50   ~ 0
T_CLK
Text Label 9500 5250 2    50   ~ 0
T_CS
Text Label 9500 5350 2    50   ~ 0
T_DIN
Text Label 9500 5450 2    50   ~ 0
T_DO
Text Label 9500 5550 2    50   ~ 0
T_IRQ
$Comp
L interface-rescue:R_US-Device R4
U 1 1 60BD6520
P 9100 4950
F 0 "R4" V 8890 4950 50  0000 C CNN
F 1 "100" V 8983 4950 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 9140 4940 50  0001 C CNN
F 3 "~" H 9100 4950 50  0001 C CNN
	1    9100 4950
	0    1    1    0   
$EndComp
Wire Wire Line
	9500 4950 9250 4950
Text Label 8950 4950 2    50   ~ 0
VCC5
$Comp
L interface-rescue:74LS240-74xx U5
U 1 1 60B83719
P 2700 3850
F 0 "U5" H 2700 4836 50  0000 C CNN
F 1 "74ACT240" H 2700 4743 50  0000 C CNN
F 2 "Housings_DIP:DIP-20_W7.62mm" H 2700 3850 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74ls240.pdf" H 2700 3850 50  0001 C CNN
	1    2700 3850
	-1   0    0    -1  
$EndComp
$Comp
L interface-rescue:74LS240-74xx U4
U 1 1 60B8262F
P 2700 1550
F 0 "U4" H 2700 2536 50  0000 C CNN
F 1 "74ACT240" H 2700 2443 50  0000 C CNN
F 2 "Housings_DIP:DIP-20_W7.62mm" H 2700 1550 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74ls240.pdf" H 2700 1550 50  0001 C CNN
	1    2700 1550
	-1   0    0    -1  
$EndComp
$Comp
L interface-rescue:74HC245-74xx U2
U 1 1 60BE1DF5
P 8300 1800
F 0 "U2" H 8300 2786 50  0000 C CNN
F 1 "74LVC245" H 8300 2693 50  0000 C CNN
F 2 "Housings_DIP:DIP-20_W7.62mm" H 8300 1800 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC245" H 8300 1800 50  0001 C CNN
	1    8300 1800
	1    0    0    -1  
$EndComp
$Comp
L interface-rescue:74HC245-74xx U3
U 1 1 60BE3C18
P 8300 3850
F 0 "U3" H 8300 4836 50  0000 C CNN
F 1 "74LVC245" H 8300 4743 50  0000 C CNN
F 2 "Housings_DIP:DIP-20_W7.62mm" H 8300 3850 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74HC245" H 8300 3850 50  0001 C CNN
	1    8300 3850
	1    0    0    -1  
$EndComp
Text Label 850  1250 0    50   ~ 0
DSK_RD_CLK
Text Label 850  1350 0    50   ~ 0
DSK_WR_DATA
Text Label 850  1150 0    50   ~ 0
GND
Text Label 850  4850 0    50   ~ 0
DSK_RD_DATA
Text Label 850  4950 0    50   ~ 0
DSK_RD_GATE
Text Label 850  1450 0    50   ~ 0
DSK_SRW
Text Label 850  4450 0    50   ~ 0
DSK_WR_PROT_IN
Text Label 850  4750 0    50   ~ 0
DSK_CYL8
Text Label 850  4550 0    50   ~ 0
DSK_ERASE_GATE
Text Label 850  1550 0    50   ~ 0
DSK_SEL1
Text Label 850  4650 0    50   ~ 0
DSK_HD
Text Label 850  4350 0    50   ~ 0
DSK_WR_PROT_IND
Text Label 850  1750 0    50   ~ 0
DSK_SEL2
Text Label 850  4250 0    50   ~ 0
DSK_PSU_SECTOR
Text Label 850  1850 0    50   ~ 0
DSK_CYL64
Text Label 850  4150 0    50   ~ 0
DSK_READY
Text Label 850  1950 0    50   ~ 0
DSK_SEL3
Text Label 850  4050 0    50   ~ 0
DSK_SECTOR
Text Label 850  2050 0    50   ~ 0
DSK_CYL16
Text Label 850  2150 0    50   ~ 0
DSK_SEL4
Text Label 850  2250 0    50   ~ 0
DSK_CYL128
Text Label 850  2350 0    50   ~ 0
DSK_CYL32
Text Label 850  2450 0    50   ~ 0
DSK_SECT2
Text Label 850  2550 0    50   ~ 0
DSK_CYL1
Text Label 850  2650 0    50   ~ 0
DSK_ADR_ACK
Text Label 850  2750 0    50   ~ 0
DSK_SEEK_INCMP
Text Label 850  2850 0    50   ~ 0
DSK_LAI
Text Label 850  3050 0    50   ~ 0
DSK_RESTORE
Text Label 850  3150 0    50   ~ 0
DSK_BIT16
Text Label 850  3250 0    50   ~ 0
DSK_STROBE
Text Label 850  3350 0    50   ~ 0
DSK_SECT8
Text Label 850  3450 0    50   ~ 0
DSK_SECT4
Text Label 850  3550 0    50   ~ 0
DSK_WR_CHK
Text Label 850  3650 0    50   ~ 0
DSK_WR_GATE
Text Label 850  3750 0    50   ~ 0
DSK_SECT1
Text Label 850  3950 0    50   ~ 0
DSK_INDEX
Text Label 850  5050 0    50   ~ 0
GND
Text Label 850  2950 0    50   ~ 0
DSK_CYL4
Text Label 2200 1250 2    50   ~ 0
DSK_RD_CLK
Text Label 3200 1250 0    50   ~ 0
RD_CLK
Text Label 7800 1300 2    50   ~ 0
DSK_WR_DATA
Text Label 7800 1400 2    50   ~ 0
DSK_SEL1
Text Label 7800 1500 2    50   ~ 0
DSK_CYL2
Text Label 7800 1600 2    50   ~ 0
DSK_CYL64
Text Label 7800 1700 2    50   ~ 0
DSK_CYL16
Text Label 7800 1800 2    50   ~ 0
DSK_SEL4
Text Label 7800 1900 2    50   ~ 0
DSK_CYL128
Text Label 7800 2000 2    50   ~ 0
DSK_CYL32
Text Label 7800 3350 2    50   ~ 0
DSK_CYL1
Text Label 7800 3450 2    50   ~ 0
DSK_CYL4
Text Label 7800 3550 2    50   ~ 0
DSK_RESTORE
Text Label 7800 3650 2    50   ~ 0
DSK_STROBE
Text Label 7800 3750 2    50   ~ 0
DSK_WR_GATE
Text Label 7800 3850 2    50   ~ 0
DSK_HEAD_SEL
Text Label 7800 3950 2    50   ~ 0
DSK_CYL8
Text Label 7800 4050 2    50   ~ 0
DSK_RD_GATE
NoConn ~ 850  4550
NoConn ~ 850  1750
NoConn ~ 850  1950
Text Label 2200 1650 2    50   ~ 0
DSK_SRW
Text Label 2200 1050 2    50   ~ 0
DSK_SECT2
Text Label 2200 1750 2    50   ~ 0
DSK_ADR_ACK
Text Label 2200 1550 2    50   ~ 0
DSK_SEEK_INCMP
Text Label 2200 1350 2    50   ~ 0
DSK_LAI
Text Label 2200 1450 2    50   ~ 0
DSK_SECT8
Text Label 2200 1150 2    50   ~ 0
DSK_SECT4
NoConn ~ 850  4350
NoConn ~ 850  4450
Text Label 9450 6050 2    50   ~ 0
LED_R
Text Label 9450 6250 2    50   ~ 0
LED_G
Text Label 9450 6450 2    50   ~ 0
LED_B
Text Label 2200 3550 2    50   ~ 0
LED_B
Text Label 2200 3450 2    50   ~ 0
LED_G
Text Label 2200 4050 2    50   ~ 0
LED_R
Text Label 3200 1950 0    50   ~ 0
GND
Text Label 3200 2050 0    50   ~ 0
GND
Text Label 3200 4250 0    50   ~ 0
GND
Text Label 3200 4350 0    50   ~ 0
GND
Text Label 3200 1650 0    50   ~ 0
SRW
Text Label 2200 3650 2    50   ~ 0
DSK_SECT1
Text Label 2200 3950 2    50   ~ 0
DSK_READY
Text Label 2200 3750 2    50   ~ 0
DSK_RD_DATA
NoConn ~ 850  4650
Text Label 8800 1300 0    50   ~ 0
WR_DATA
Text Label 3200 1050 0    50   ~ 0
SECT2
Text Label 3200 1750 0    50   ~ 0
ADR_ACK
Text Label 3200 1550 0    50   ~ 0
SEEK_INCMP
Text Label 3200 1350 0    50   ~ 0
LAI
Text Label 3200 1450 0    50   ~ 0
SECT8
Text Label 3200 3650 0    50   ~ 0
SECT1
Text Label 3200 3950 0    50   ~ 0
READY
Text Label 3200 3750 0    50   ~ 0
RD_DATA
Text Label 3200 4050 0    50   ~ 0
LED_R_PWM
Text Label 3200 3450 0    50   ~ 0
LED_G_PWM
Text Label 3200 3550 0    50   ~ 0
LED_B_PWM
Text Label 8800 1400 0    50   ~ 0
SEL1
Text Label 8800 1500 0    50   ~ 0
CYL2
Text Label 8800 1600 0    50   ~ 0
CYL64
Text Label 8800 1700 0    50   ~ 0
CYL16
Text Label 8800 1800 0    50   ~ 0
SEL4
Text Label 8800 1900 0    50   ~ 0
CYL128
Text Label 8800 2000 0    50   ~ 0
CYL32
Text Label 7800 2200 2    50   ~ 0
VCC3
Text Label 7800 2300 2    50   ~ 0
GND
Text Label 7800 4250 2    50   ~ 0
VCC3
Text Label 7800 4350 2    50   ~ 0
GND
Text Label 8800 3350 0    50   ~ 0
CYL1
Text Label 8800 3450 0    50   ~ 0
CYL4
Text Label 8800 3550 0    50   ~ 0
RESTORE
Text Label 8800 3650 0    50   ~ 0
STROBE
Text Label 8800 3750 0    50   ~ 0
WR_GATE
Text Label 8800 3850 0    50   ~ 0
HEAD_SEL
Text Label 8800 4050 0    50   ~ 0
RD_GATE
Text Label 4450 2550 2    50   ~ 0
CS
Text Label 4450 2450 2    50   ~ 0
DC
Text Label 4450 2650 2    50   ~ 0
SDI
Text Label 6650 2750 0    50   ~ 0
SCK
Text Label 4450 2750 2    50   ~ 0
SDO
Text Label 8950 5150 2    50   ~ 0
SCK
Text Label 4450 2350 2    50   ~ 0
T_CS
Text Label 4450 1750 2    50   ~ 0
T_IRQ
Text Label 8950 5350 2    50   ~ 0
SDI
Text Label 8950 5450 2    50   ~ 0
SDO
Wire Wire Line
	8950 5450 9500 5450
Wire Wire Line
	8950 5350 9500 5350
Wire Wire Line
	8950 5150 9500 5150
Text Label 6750 1450 0    50   ~ 0
VCC5
Text Label 6650 1650 0    50   ~ 0
VCC3
Text Label 6650 1550 0    50   ~ 0
GND
Text Label 4450 2050 2    50   ~ 0
SECT2
Text Notes 2200 850  2    50   ~ 0
outputs
Text Notes 7750 1050 2    50   ~ 0
inputs
Text Label 4450 3350 2    50   ~ 0
LAI
Text Label 6650 2450 0    50   ~ 0
SECT4
Text Label 4450 3250 2    50   ~ 0
STROBE
Text Label 4450 3650 2    50   ~ 0
SECT8
Text Label 4450 3150 2    50   ~ 0
SECTOR
Text Label 4450 3750 2    50   ~ 0
RD_DATA
Text Label 6650 1750 0    50   ~ 0
SEL1
Text Label 6650 1850 0    50   ~ 0
CYL2
Text Label 6650 1950 0    50   ~ 0
CYL64
Text Label 6650 3350 0    50   ~ 0
CYL16
Text Label 6650 3450 0    50   ~ 0
SEL4
Text Label 6650 3650 0    50   ~ 0
CYL128
Text Label 6650 3750 0    50   ~ 0
CYL32
Text Label 6650 2050 0    50   ~ 0
CYL1
Text Label 6650 2950 0    50   ~ 0
CYL4
Text Label 6650 3050 0    50   ~ 0
RESTORE
Text Label 6650 3550 0    50   ~ 0
RD_GATE
Text Label 850  1650 0    50   ~ 0
DSK_CYL2
$Comp
L interface-rescue:MountingHole-Mechanical H1
U 1 1 60CCE296
P 650 6750
F 0 "H1" H 750 6797 50  0001 L CNN
F 1 "MountingHole" H 750 6750 50  0000 L CNN
F 2 "interface:MountingHole_M3" H 650 6750 50  0001 C CNN
F 3 "~" H 650 6750 50  0001 C CNN
	1    650  6750
	1    0    0    -1  
$EndComp
$Comp
L interface-rescue:MountingHole-Mechanical H2
U 1 1 60CCE7C1
P 650 6950
F 0 "H2" H 750 6997 50  0001 L CNN
F 1 "MountingHole" H 750 6950 50  0000 L CNN
F 2 "interface:MountingHole_M3" H 650 6950 50  0001 C CNN
F 3 "~" H 650 6950 50  0001 C CNN
	1    650  6950
	1    0    0    -1  
$EndComp
$Comp
L interface-rescue:MountingHole-Mechanical H3
U 1 1 60CCE90F
P 650 7150
F 0 "H3" H 750 7197 50  0001 L CNN
F 1 "MountingHole" H 750 7150 50  0000 L CNN
F 2 "interface:MountingHole_M3" H 650 7150 50  0001 C CNN
F 3 "~" H 650 7150 50  0001 C CNN
	1    650  7150
	1    0    0    -1  
$EndComp
$Comp
L interface-rescue:MountingHole-Mechanical H4
U 1 1 60CCEB71
P 650 7350
F 0 "H4" H 750 7397 50  0001 L CNN
F 1 "MountingHole" H 750 7350 50  0000 L CNN
F 2 "interface:MountingHole_M3" H 650 7350 50  0001 C CNN
F 3 "~" H 650 7350 50  0001 C CNN
	1    650  7350
	1    0    0    -1  
$EndComp
NoConn ~ 4450 1650
NoConn ~ 4450 1550
NoConn ~ 4450 1850
Text Label 4450 2850 2    50   ~ 0
VCC3
NoConn ~ 350  -150
NoConn ~ 6650 4000
NoConn ~ 6650 4100
NoConn ~ 6650 4200
NoConn ~ 6650 4300
NoConn ~ 6650 4400
NoConn ~ 6650 4500
NoConn ~ 5850 4900
NoConn ~ 5700 4900
NoConn ~ 5550 4900
NoConn ~ 5400 4900
NoConn ~ 5250 4900
NoConn ~ 4450 4600
NoConn ~ 4450 4500
NoConn ~ 4450 4400
NoConn ~ 4450 4300
NoConn ~ 4450 4200
NoConn ~ 4450 4050
NoConn ~ 4450 3950
Text Label 4450 2250 2    50   ~ 0
SECT1
Text Label 6650 3150 0    50   ~ 0
RD_CLK
Text Label 4450 3450 2    50   ~ 0
WR_GATE
$Comp
L teensy:Teensy4.1 U1
U 1 1 60BDC959
P 5550 3600
F 0 "U1" H 5550 6170 50  0000 C CNN
F 1 "Teensy4.1" H 5550 6077 50  0000 C CNN
F 2 "interface:Teensy41_simple" H 5150 4000 50  0001 C CNN
F 3 "" H 5150 4000 50  0001 C CNN
	1    5550 3600
	1    0    0    -1  
$EndComp
Text Label 6650 2350 0    50   ~ 0
ADR_ACK
Text Label 6650 2150 0    50   ~ 0
READY
Text Label 850  3850 0    50   ~ 0
DSK_HEAD_SEL
NoConn ~ 850  4250
NoConn ~ 850  3950
NoConn ~ 850  3550
NoConn ~ 850  3150
Text Label 3200 1150 0    50   ~ 0
SECT4
Text Label 3200 3850 0    50   ~ 0
SECTOR
Text Label 3200 3350 0    50   ~ 0
GND
NoConn ~ 2200 3350
Text Label 2200 3850 2    50   ~ 0
DSK_SECTOR
Text Label 4450 2950 2    50   ~ 0
SRW
Text Label 4450 3050 2    50   ~ 0
SEEK_INCMP
Text Label 6650 2550 0    50   ~ 0
LED_R_PWM
Text Label 6650 2250 0    50   ~ 0
LED_G_PWM
Text Label 6650 2650 0    50   ~ 0
LED_B_PWM
Text Label 4450 2150 2    50   ~ 0
WR_DATA
NoConn ~ 4450 1950
Text Label 4450 3550 2    50   ~ 0
CYL8
Text Label 8800 3950 0    50   ~ 0
CYL8
Text Notes 550  1200 0    50   ~ 0
DD
Text Notes 600  1300 0    50   ~ 0
A
Text Notes 600  1400 0    50   ~ 0
B
Text Notes 600  4900 0    50   ~ 0
C
Text Notes 600  5000 0    50   ~ 0
E
Text Notes 600  5100 0    50   ~ 0
D
Text Notes 600  1500 0    50   ~ 0
F
Text Notes 600  4500 0    50   ~ 0
H
Text Notes 600  4800 0    50   ~ 0
J
Text Notes 600  4600 0    50   ~ 0
K
Text Notes 600  1600 0    50   ~ 0
L
Text Notes 600  4700 0    50   ~ 0
M
Text Notes 600  1700 0    50   ~ 0
N
Text Notes 600  4400 0    50   ~ 0
P
Text Notes 600  1800 0    50   ~ 0
R
Text Notes 600  4300 0    50   ~ 0
S
Text Notes 600  1900 0    50   ~ 0
T
Text Notes 600  4200 0    50   ~ 0
U
Text Notes 600  2000 0    50   ~ 0
V
Text Notes 600  4100 0    50   ~ 0
W
Text Notes 600  2100 0    50   ~ 0
X
Text Notes 600  4000 0    50   ~ 0
Y
Text Notes 600  2200 0    50   ~ 0
Z
Text Notes 550  3900 0    50   ~ 0
AA
Text Notes 550  2300 0    50   ~ 0
BB
Text Notes 550  3800 0    50   ~ 0
CC
Text Notes 550  3700 0    50   ~ 0
EE
Text Notes 550  2400 0    50   ~ 0
FF
Text Notes 550  3600 0    50   ~ 0
HH
Text Notes 550  2500 0    50   ~ 0
JJ
Text Notes 550  3500 0    50   ~ 0
KK
Text Notes 550  2600 0    50   ~ 0
LL
Text Notes 550  3400 0    50   ~ 0
MM
Text Notes 550  2700 0    50   ~ 0
NN
Text Notes 550  3000 0    50   ~ 0
RR
Text Notes 550  3300 0    50   ~ 0
SS
Text Notes 550  2800 0    50   ~ 0
TT
Text Notes 550  3200 0    50   ~ 0
UU
Text Notes 550  3100 0    50   ~ 0
VV
Text Notes 550  2900 0    50   ~ 0
XX
Text Notes 1400 6300 0    50   ~ 0
Note: cylinder/sectors are numbered\nby bit values here but little-endian bit\nnumbers elsewhere.\nCYL 1 = CYL128 (BB)\nCYL 2 = CYL64 (T)\nCYL 3 = CYL32 (FF)\nCYL 4 = CYL16 (X)\nCYL 5 = CYL8 (J)\nCYL 6 = CYL4 (RR)\nCYL 7 = CYL2 (N)\nCYL 8 = CYL1 (LL)\n\nKSECT0 = BIT 8 = SECT8 (MM)\nKSECT1 = BIT 4 = SECT4 (KK)\nKSECT2 = BIT 2 = SECT2 (JJ)\nKSECT3 = BIT 1 = SECT1 (CC)
Wire Wire Line
	6650 1300 6650 1450
Wire Wire Line
	6750 1450 6650 1450
Connection ~ 6650 1450
Text Label 6650 3250 0    50   ~ 0
HEAD_SEL
$Comp
L Connector:TestPoint TP1
U 1 1 60CEA444
P 650 7750
F 0 "TP1" H 710 7869 50  0000 L CNN
F 1 "TestPoint" H 710 7776 50  0000 L CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x01_Pitch2.54mm" H 850 7750 50  0001 C CNN
F 3 "~" H 850 7750 50  0001 C CNN
	1    650  7750
	1    0    0    -1  
$EndComp
Text Label 650  7900 0    50   ~ 0
GND
Wire Wire Line
	650  7900 650  7750
Text Notes 6700 7700 0    50   ~ 0
Diablo Disk Interface V1\n
$EndSCHEMATC
