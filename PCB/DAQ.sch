EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:switches
LIBS:relays
LIBS:motors
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:ArduinoMega
LIBS:adc
LIBS:dac
LIBS:Nokia5110
LIBS:rtc
LIBS:sdshield
LIBS:MAX743CWE+
LIBS:DAQ-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
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
L Arduino_Mega_Header J1
U 1 1 5AA585CB
P 1900 2600
F 0 "J1" H 1900 3850 60  0000 C CNN
F 1 "Arduino_Mega_Header" H 1900 1350 60  0000 C CNN
F 2 "w_conn_misc:arduino_mega_header" H 1900 2600 60  0001 C CNN
F 3 "" H 1900 2600 60  0000 C CNN
	1    1900 2600
	1    0    0    -1  
$EndComp
$Comp
L NOKIA5110 U4
U 1 1 5AA5879D
P 4050 1500
F 0 "U4" H 4150 800 39  0000 C CNN
F 1 "NOKIA5110" H 3900 800 39  0000 C CNN
F 2 "Nokia5110:Nokia5110" H 4050 1500 39  0001 C CNN
F 3 "" H 4050 1500 39  0001 C CNN
	1    4050 1500
	0    -1   -1   0   
$EndComp
$Comp
L ADC U3
U 1 1 5AA58804
P 3650 3600
F 0 "U3" H 4050 3050 60  0000 C CNN
F 1 "ADC" H 4250 3050 60  0000 C CNN
F 2 "ADC:ADC" H 5000 3500 60  0001 C CNN
F 3 "" H 5000 3500 60  0001 C CNN
	1    3650 3600
	0    -1   -1   0   
$EndComp
$Comp
L DAC U5
U 1 1 5AA5881F
P 3200 4700
F 0 "U5" H 3400 4250 39  0000 C CNN
F 1 "DAC" H 3500 4250 39  0000 C CNN
F 2 "DAC:DAC" H 3200 4700 39  0001 C CNN
F 3 "" H 3200 4700 39  0001 C CNN
	1    3200 4700
	0    -1   -1   0   
$EndComp
$Comp
L RTC U2
U 1 1 5AA588BA
P 1750 4300
F 0 "U2" H 1750 4000 39  0000 C CNN
F 1 "RTC" H 1750 4600 39  0000 C CNN
F 2 "RTC:SDShield" H 1750 4300 39  0001 C CNN
F 3 "" H 1750 4300 39  0001 C CNN
	1    1750 4300
	1    0    0    -1  
$EndComp
$Comp
L SDshield U1
U 1 1 5AA5890F
P 1700 5000
F 0 "U1" H 1700 5200 39  0000 C CNN
F 1 "SDshield" H 1650 4500 39  0000 C CNN
F 2 "SDShield:SDShield" H 1250 5000 39  0001 C CNN
F 3 "" H 1250 5000 39  0001 C CNN
	1    1700 5000
	1    0    0    -1  
$EndComp
Text Label 1100 1550 2    39   ~ 0
3.3V
Text Label 1100 1600 2    39   ~ 0
5V
Text Label 1100 1650 2    39   ~ 0
GND
Wire Wire Line
	1400 1550 1100 1550
Wire Wire Line
	1350 1600 1100 1600
Wire Wire Line
	1400 1650 1100 1650
Wire Wire Line
	2450 1450 2700 1450
Wire Wire Line
	2400 1500 2700 1500
Wire Wire Line
	2400 1600 2700 1600
Wire Wire Line
	2450 2000 2700 2000
Wire Wire Line
	2400 2050 2700 2050
Wire Wire Line
	2450 2100 2700 2100
Wire Wire Line
	2400 2150 2700 2150
Wire Wire Line
	2450 2200 2700 2200
Wire Wire Line
	2400 2250 2700 2250
Text Label 2700 1450 0    39   ~ 0
SCL
Text Label 2700 1500 0    39   ~ 0
SDA
Text Label 2700 1600 0    39   ~ 0
GND
Text Label 2700 2000 0    39   ~ 0
PIN7
Text Label 2700 2050 0    39   ~ 0
PIN6
Text Label 2700 2100 0    39   ~ 0
PIN5
Text Label 2700 2150 0    39   ~ 0
PIN4
Text Label 2700 2200 0    39   ~ 0
PIN3
Text Label 2700 2250 0    39   ~ 0
PIN2
Text Label 3600 1950 2    39   ~ 0
GND
Text Label 3600 1850 2    39   ~ 0
5V
Text Label 3600 1750 2    39   ~ 0
3.3V
Text Label 3450 2700 2    39   ~ 0
5V
Text Label 3450 2800 2    39   ~ 0
GND
Text Label 3450 2900 2    39   ~ 0
SCL
Text Label 3450 3000 2    39   ~ 0
SDA
Text Label 3000 4150 2    39   ~ 0
5V
Text Label 3000 4250 2    39   ~ 0
GND
Text Label 3000 4350 2    39   ~ 0
SCL
Text Label 3000 4450 2    39   ~ 0
SDA
Text Label 1150 4100 2    39   ~ 0
5V
Text Label 1150 4200 2    39   ~ 0
GND
Text Label 1150 4300 2    39   ~ 0
PIN31
Text Label 1150 4400 2    39   ~ 0
PIN33
Text Label 1150 4500 2    39   ~ 0
PIN35
Text Label 950  4900 2    39   ~ 0
PIN4
Text Label 950  5000 2    39   ~ 0
PIN52
Text Label 950  5100 2    39   ~ 0
PIN51
Text Label 950  5200 2    39   ~ 0
PIN50
Text Label 950  5300 2    39   ~ 0
5V
Text Label 950  5400 2    39   ~ 0
GND
Wire Wire Line
	2400 3150 2700 3150
Wire Wire Line
	2450 3200 2700 3200
Wire Wire Line
	2400 3250 2700 3250
Wire Wire Line
	2450 3700 2700 3700
Wire Wire Line
	2400 3650 2700 3650
Wire Wire Line
	2450 3600 2700 3600
Text Label 2700 3150 0    39   ~ 0
PIN31
Text Label 2700 3200 0    39   ~ 0
PIN33
Text Label 2700 3250 0    39   ~ 0
PIN35
Text Label 2700 3600 0    39   ~ 0
PIN50
Text Label 2700 3650 0    39   ~ 0
PIN51
Text Label 2700 3700 0    39   ~ 0
PIN52
Wire Wire Line
	2400 3750 2700 3750
Text Label 2700 3750 0    39   ~ 0
GND
Wire Wire Line
	2450 2900 2700 2900
Text Label 2700 2900 0    39   ~ 0
5V
NoConn ~ 1400 1450
NoConn ~ 1350 1500
NoConn ~ 1350 1700
NoConn ~ 1400 1750
NoConn ~ 1350 1850
NoConn ~ 1400 1900
NoConn ~ 1350 1950
NoConn ~ 1400 2000
NoConn ~ 1350 2050
NoConn ~ 1400 2100
NoConn ~ 1350 2150
NoConn ~ 1400 2200
NoConn ~ 1350 2300
NoConn ~ 1400 2350
NoConn ~ 1350 2400
NoConn ~ 1400 2450
NoConn ~ 1350 2500
NoConn ~ 1400 2550
NoConn ~ 1350 2600
NoConn ~ 1400 2650
NoConn ~ 1400 2850
NoConn ~ 1350 2900
NoConn ~ 1400 2950
NoConn ~ 1350 3000
NoConn ~ 1400 3050
NoConn ~ 1350 3100
NoConn ~ 1400 3150
NoConn ~ 1350 3200
NoConn ~ 1400 3250
NoConn ~ 1350 3300
NoConn ~ 1400 3350
NoConn ~ 1350 3400
NoConn ~ 1400 3450
NoConn ~ 1350 3500
NoConn ~ 1400 3550
NoConn ~ 1350 3600
NoConn ~ 1400 3650
NoConn ~ 1350 3700
NoConn ~ 2400 3550
NoConn ~ 2450 3500
NoConn ~ 2400 3450
NoConn ~ 2450 3400
NoConn ~ 2400 3350
NoConn ~ 2450 3300
NoConn ~ 2450 3100
NoConn ~ 2400 3050
NoConn ~ 2450 3000
NoConn ~ 2400 2950
NoConn ~ 2400 2800
NoConn ~ 2450 2750
NoConn ~ 2400 2700
NoConn ~ 2450 2650
NoConn ~ 2400 2600
NoConn ~ 2450 2550
NoConn ~ 2400 2500
NoConn ~ 2450 2450
NoConn ~ 2400 2350
NoConn ~ 2450 2300
NoConn ~ 2400 1900
NoConn ~ 2450 1850
NoConn ~ 2400 1800
NoConn ~ 2450 1750
NoConn ~ 2400 1700
NoConn ~ 2450 1650
NoConn ~ 2450 1550
NoConn ~ 3450 3100
NoConn ~ 3450 3200
NoConn ~ 3450 3400
NoConn ~ 3450 3300
NoConn ~ 3450 3500
NoConn ~ 4150 3700
NoConn ~ 3000 4550
NoConn ~ 3000 4650
$Comp
L Conn_01x07 J2
U 1 1 5AA6A59F
P 5400 2000
F 0 "J2" H 5400 2400 50  0000 C CNN
F 1 "Conn_01x07" H 5400 1600 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x07_Pitch2.54mm" H 5400 2000 50  0001 C CNN
F 3 "" H 5400 2000 50  0001 C CNN
	1    5400 2000
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x08 J3
U 1 1 5AA6A620
P 5400 2950
F 0 "J3" H 5400 3350 50  0000 C CNN
F 1 "Conn_01x08" H 5400 2450 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x08_Pitch2.54mm" H 5400 2950 50  0001 C CNN
F 3 "" H 5400 2950 50  0001 C CNN
	1    5400 2950
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x08 J4
U 1 1 5AA6A693
P 5400 3950
F 0 "J4" H 5400 4350 50  0000 C CNN
F 1 "Conn_01x08" H 5400 3450 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x08_Pitch2.54mm" H 5400 3950 50  0001 C CNN
F 3 "" H 5400 3950 50  0001 C CNN
	1    5400 3950
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x07 J8
U 1 1 5AA6A89B
P 7100 3950
F 0 "J8" H 7100 4350 50  0000 C CNN
F 1 "Conn_01x07" H 7100 3550 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x07_Pitch2.54mm" H 7100 3950 50  0001 C CNN
F 3 "" H 7100 3950 50  0001 C CNN
	1    7100 3950
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x08 J7
U 1 1 5AA6A937
P 7100 2900
F 0 "J7" H 7100 3300 50  0000 C CNN
F 1 "Conn_01x08" H 7100 2400 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x08_Pitch2.54mm" H 7100 2900 50  0001 C CNN
F 3 "" H 7100 2900 50  0001 C CNN
	1    7100 2900
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x10 J6
U 1 1 5AA6A9A6
P 7100 1650
F 0 "J6" H 7100 2150 50  0000 C CNN
F 1 "Conn_01x10" H 7100 1050 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x10_Pitch2.54mm" H 7100 1650 50  0001 C CNN
F 3 "" H 7100 1650 50  0001 C CNN
	1    7100 1650
	1    0    0    -1  
$EndComp
NoConn ~ 5200 1700
NoConn ~ 5200 1800
NoConn ~ 5200 2300
NoConn ~ 5200 2200
Text Label 5200 1900 2    39   ~ 0
3.3V
Text Label 5200 2000 2    39   ~ 0
5v
Text Label 5200 2100 2    39   ~ 0
GND
Text Label 6900 1250 2    39   ~ 0
SCL
Text Label 6900 1350 2    39   ~ 0
SDA
Text Label 6900 1550 2    39   ~ 0
GND
Text Label 6900 2600 2    39   ~ 0
PIN7
Text Label 6900 2700 2    39   ~ 0
PIN6
Text Label 6900 2800 2    39   ~ 0
PIN5
Text Label 6900 2900 2    39   ~ 0
PIN4
Text Label 6900 3000 2    39   ~ 0
PIN3
Text Label 6900 3100 2    39   ~ 0
PIN2
NoConn ~ 5600 4800
NoConn ~ 5700 4800
NoConn ~ 5900 4800
NoConn ~ 6000 5300
NoConn ~ 6100 4800
NoConn ~ 6100 5300
NoConn ~ 6200 5300
NoConn ~ 6300 4800
NoConn ~ 6300 5300
NoConn ~ 6400 4800
NoConn ~ 6400 5300
NoConn ~ 6500 4800
NoConn ~ 6500 5300
NoConn ~ 6600 4800
NoConn ~ 6700 4800
NoConn ~ 6800 4800
NoConn ~ 6900 4800
NoConn ~ 7000 4800
NoConn ~ 7100 4800
NoConn ~ 7300 4800
NoConn ~ 6900 4250
NoConn ~ 6900 4150
NoConn ~ 6900 4050
NoConn ~ 6900 3950
NoConn ~ 6900 3850
NoConn ~ 6900 3750
NoConn ~ 6900 3650
NoConn ~ 5200 3650
NoConn ~ 5200 3750
NoConn ~ 5200 3850
NoConn ~ 5200 3950
NoConn ~ 5200 4050
NoConn ~ 5200 4150
NoConn ~ 5200 4250
NoConn ~ 5200 4350
NoConn ~ 5200 2650
NoConn ~ 5200 2750
NoConn ~ 5200 2850
NoConn ~ 5200 2950
NoConn ~ 5200 3050
NoConn ~ 5200 3150
NoConn ~ 5200 3250
NoConn ~ 5200 3350
NoConn ~ 6900 3300
NoConn ~ 6900 3200
NoConn ~ 6900 1450
NoConn ~ 6900 1650
NoConn ~ 6900 1750
NoConn ~ 6900 1850
NoConn ~ 6900 1950
NoConn ~ 6900 2050
NoConn ~ 6900 2150
Text Label 7300 5300 3    39   ~ 0
GND
NoConn ~ 6800 5300
NoConn ~ 6600 5300
NoConn ~ 5900 5300
NoConn ~ 5800 5300
NoConn ~ 5700 5300
Text Label 7200 4800 1    39   ~ 0
5V
NoConn ~ 5600 5300
$Comp
L Conn_02x18_Counter_Clockwise J5
U 1 1 5AA6A84A
P 6500 5000
F 0 "J5" H 6550 5900 50  0000 C CNN
F 1 "Conn_02x18_Counter_Clockwise" H 6550 4000 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x18_Pitch2.54mm" H 6500 5000 50  0001 C CNN
F 3 "" H 6500 5000 50  0001 C CNN
	1    6500 5000
	0    1    1    0   
$EndComp
Text Label 5800 4800 1    39   ~ 0
PIN35
Text Label 6000 4800 1    39   ~ 0
PIN33
Text Label 6200 4800 1    39   ~ 0
PIN31
Text Label 7100 5300 3    39   ~ 0
PIN52
Text Label 6900 5300 3    39   ~ 0
PIN51
Text Label 6700 5300 3    39   ~ 0
PIN50
NoConn ~ 7000 5300
NoConn ~ 7200 5300
Text Label 3600 1450 2    39   ~ 0
PIN5
Text Label 3600 1350 2    39   ~ 0
PIN6
Text Label 3600 1250 2    39   ~ 0
PIN7
Text Label 3600 1550 2    39   ~ 0
PIN3
Text Label 3600 1650 2    39   ~ 0
PIN2
$Comp
L C C2
U 1 1 5AA833CA
P 8050 2500
F 0 "C2" H 8075 2600 50  0000 L CNN
F 1 "0.1uF" H 8075 2400 50  0000 L CNN
F 2 "Capacitors_THT:CP_Axial_L11.0mm_D6.0mm_P18.00mm_Horizontal" H 8088 2350 50  0001 C CNN
F 3 "" H 8050 2500 50  0001 C CNN
	1    8050 2500
	0    -1   -1   0   
$EndComp
$Comp
L C C4
U 1 1 5AA8346C
P 8000 3050
F 0 "C4" H 8025 3150 50  0000 L CNN
F 1 "1uF" H 8025 2950 50  0000 L CNN
F 2 "Capacitors_THT:CP_Axial_L11.0mm_D6.0mm_P18.00mm_Horizontal" H 8038 2900 50  0001 C CNN
F 3 "" H 8000 3050 50  0001 C CNN
	1    8000 3050
	0    -1   -1   0   
$EndComp
$Comp
L C C3
U 1 1 5AA8349F
P 8050 2800
F 0 "C3" H 8075 2900 50  0000 L CNN
F 1 "10uF" H 8075 2700 50  0000 L CNN
F 2 "Capacitors_THT:CP_Axial_L11.0mm_D6.0mm_P18.00mm_Horizontal" H 8088 2650 50  0001 C CNN
F 3 "" H 8050 2800 50  0001 C CNN
	1    8050 2800
	0    -1   -1   0   
$EndComp
$Comp
L C CC+1
U 1 1 5AA834DE
P 7950 2100
F 0 "CC+1" H 7975 2200 50  0000 L CNN
F 1 "0.01uF" H 7975 2000 50  0000 L CNN
F 2 "Capacitors_THT:CP_Axial_L11.0mm_D6.0mm_P18.00mm_Horizontal" H 7988 1950 50  0001 C CNN
F 3 "" H 7950 2100 50  0001 C CNN
	1    7950 2100
	0    1    1    0   
$EndComp
$Comp
L L LX+1
U 1 1 5AA83A00
P 9800 2100
F 0 "LX+1" V 9750 2100 50  0000 C CNN
F 1 "100uH" V 9875 2100 50  0000 C CNN
F 2 "Inductors_THT:L_Axial_L9.5mm_D4.0mm_P12.70mm_Horizontal_Fastron_SMCC" H 9800 2100 50  0001 C CNN
F 3 "" H 9800 2100 50  0001 C CNN
	1    9800 2100
	1    0    0    -1  
$EndComp
$Comp
L C CF+1
U 1 1 5AA83AD3
P 10600 2600
F 0 "CF+1" H 10625 2700 50  0000 L CNN
F 1 "100uF" H 10625 2500 50  0000 L CNN
F 2 "Capacitors_THT:C_Axial_L3.8mm_D2.6mm_P7.50mm_Horizontal" H 10638 2450 50  0001 C CNN
F 3 "" H 10600 2600 50  0001 C CNN
	1    10600 2600
	1    0    0    -1  
$EndComp
$Comp
L D_Schottky DX+1
U 1 1 5AA83B70
P 10000 2400
F 0 "DX+1" H 10000 2500 50  0000 C CNN
F 1 "D_Schottky" H 10000 2300 50  0000 C CNN
F 2 "Diodes_THT:D_A-405_P12.70mm_Horizontal" H 10000 2400 50  0001 C CNN
F 3 "" H 10000 2400 50  0001 C CNN
	1    10000 2400
	-1   0    0    1   
$EndComp
$Comp
L C C1
U 1 1 5AA83C04
P 10150 2800
F 0 "C1" H 10175 2900 50  0000 L CNN
F 1 "100uF" H 10175 2700 50  0000 L CNN
F 2 "Capacitors_THT:C_Axial_L12.0mm_D6.5mm_P15.00mm_Horizontal" H 10188 2650 50  0001 C CNN
F 3 "" H 10150 2800 50  0001 C CNN
	1    10150 2800
	1    0    0    -1  
$EndComp
$Comp
L C CF-1
U 1 1 5AA83E30
P 10500 3550
F 0 "CF-1" H 10525 3650 50  0000 L CNN
F 1 "100uF" H 10525 3450 50  0000 L CNN
F 2 "Capacitors_THT:C_Axial_L3.8mm_D2.6mm_P7.50mm_Horizontal" H 10538 3400 50  0001 C CNN
F 3 "" H 10500 3550 50  0001 C CNN
	1    10500 3550
	1    0    0    -1  
$EndComp
$Comp
L L LX-1
U 1 1 5AA83EE9
P 9800 3450
F 0 "LX-1" V 9750 3450 50  0000 C CNN
F 1 "100uH" V 9875 3450 50  0000 C CNN
F 2 "Inductors_THT:L_Axial_L9.5mm_D4.0mm_P12.70mm_Horizontal_Fastron_SMCC" H 9800 3450 50  0001 C CNN
F 3 "" H 9800 3450 50  0001 C CNN
	1    9800 3450
	1    0    0    -1  
$EndComp
$Comp
L D_Schottky DX-1
U 1 1 5AA83FB0
P 10150 3200
F 0 "DX-1" H 10150 3300 50  0000 C CNN
F 1 "D_Schottky" H 10150 3100 50  0000 C CNN
F 2 "Diodes_THT:D_A-405_P12.70mm_Horizontal" H 10150 3200 50  0001 C CNN
F 3 "" H 10150 3200 50  0001 C CNN
	1    10150 3200
	1    0    0    -1  
$EndComp
$Comp
L MAX743CWE+ IC1
U 1 1 5AA98583
P 8300 2300
F 0 "IC1" H 8650 2450 50  0000 L CNN
F 1 "MAX743CWE+" H 8850 2450 50  0000 L CNN
F 2 "Housings_DIP:DIP-16_W7.62mm" H 9450 2400 50  0001 L CNN
F 3 "https://datasheets.maximintegrated.com/en/ds/MAX743.pdf" H 9450 2300 50  0001 L CNN
F 4 "Maxim MAX743CWE+, Dual DC-DC Converter" H 9450 2200 50  0001 L CNN "Description"
F 5 "Maxim Integrated" H 9450 2100 50  0001 L CNN "Manufacturer_Name"
F 6 "MAX743CWE+" H 9450 2000 50  0001 L CNN "Manufacturer_Part_Number"
F 7 "RS" H 9450 1900 50  0001 L CNN "Supplier_Name"
F 8 "7998134" H 9450 1800 50  0001 L CNN "RS Part Number"
F 9 "2.642" H 9450 1700 50  0001 L CNN "Height"
	1    8300 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	8300 2300 8200 2300
Wire Wire Line
	8200 2300 8200 2100
Wire Wire Line
	8200 2100 8100 2100
Wire Wire Line
	8300 2400 7800 2400
Wire Wire Line
	7800 2100 7800 3300
Wire Wire Line
	8300 2500 8200 2500
Wire Wire Line
	7800 2500 7900 2500
Connection ~ 7800 2400
Wire Wire Line
	7600 2600 8300 2600
Wire Wire Line
	8250 2500 8250 2700
Connection ~ 8250 2500
Wire Wire Line
	8250 2700 8300 2700
Connection ~ 8250 2600
Wire Wire Line
	8200 2800 8300 2800
Wire Wire Line
	7800 2800 7900 2800
Connection ~ 7800 2500
Wire Wire Line
	8300 2900 8150 2900
Wire Wire Line
	8150 2900 8150 3050
Wire Wire Line
	7800 3050 7850 3050
Connection ~ 7800 2800
$Comp
L C CC-1
U 1 1 5AA99320
P 8000 3300
F 0 "CC-1" H 8025 3400 50  0000 L CNN
F 1 "0.01uF" H 8025 3200 50  0000 L CNN
F 2 "Capacitors_THT:CP_Axial_L11.0mm_D6.0mm_P18.00mm_Horizontal" H 8038 3150 50  0001 C CNN
F 3 "" H 8000 3300 50  0001 C CNN
	1    8000 3300
	0    1    1    0   
$EndComp
Wire Wire Line
	8300 3000 8300 3300
Wire Wire Line
	8300 3300 8150 3300
Wire Wire Line
	7800 3300 7850 3300
Connection ~ 7800 3050
Wire Wire Line
	7600 2600 7600 1500
Text Label 7600 1500 0    60   ~ 0
5V
Wire Wire Line
	9800 1800 9800 1950
Wire Wire Line
	9850 2400 9600 2400
Wire Wire Line
	9600 2300 10350 2300
Wire Wire Line
	10350 2300 10350 2400
Wire Wire Line
	10150 2400 10950 2400
Wire Wire Line
	10600 2400 10600 2450
Connection ~ 10350 2400
Connection ~ 10600 2400
Text Label 10950 2400 0    60   ~ 0
+15V
Text Label 10600 2750 2    60   ~ 0
GND
Wire Wire Line
	9800 2250 9800 2400
Connection ~ 9800 2400
Text Label 9600 2500 0    39   ~ 0
GND
Wire Wire Line
	9600 2600 10150 2600
Wire Wire Line
	9700 2700 9600 2700
Wire Wire Line
	10150 2600 10150 2650
Text Label 10150 2950 2    39   ~ 0
GND
Wire Wire Line
	9700 1800 9700 2700
Connection ~ 9700 2600
Connection ~ 9700 1800
Text Label 9600 2800 0    39   ~ 0
GND
Wire Wire Line
	9600 2900 9800 2900
Wire Wire Line
	9800 2900 9800 3300
Wire Wire Line
	10000 3200 9800 3200
Connection ~ 9800 3200
Wire Wire Line
	10300 3200 10950 3200
Text Label 10950 3200 0    59   ~ 0
-15V
Wire Wire Line
	9600 3000 9600 3400
Wire Wire Line
	9600 3400 10500 3400
Wire Wire Line
	10500 3400 10500 3200
Connection ~ 10500 3200
Text Label 9800 3600 0    39   ~ 0
GND
Text Label 10500 3700 2    39   ~ 0
GND
Wire Wire Line
	7600 1800 9800 1800
Connection ~ 7600 1800
$EndSCHEMATC
