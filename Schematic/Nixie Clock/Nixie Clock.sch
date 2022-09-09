EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 2
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
L Connector:USB_C_Plug_USB2.0 P1
U 1 1 631A35D4
P 1050 1300
F 0 "P1" H 1400 500 50  0000 C CNN
F 1 "USB_C_Plug_USB2.0" H 1157 2076 50  0001 C CNN
F 2 "Connector_USB:USB_C_Receptacle_XKB_U262-16XN-4BVC11" H 1200 1300 50  0001 C CNN
F 3 "https://www.usb.org/sites/default/files/documents/usb_type-c.zip" H 1200 1300 50  0001 C CNN
	1    1050 1300
	1    0    0    -1  
$EndComp
$Comp
L Device:R R17
U 1 1 631A59F0
P 7450 5850
F 0 "R17" H 7520 5896 50  0000 L CNN
F 1 "10K" H 7520 5805 50  0000 L CNN
F 2 "Resistor_SMD:R_0201_0603Metric_Pad0.64x0.40mm_HandSolder" V 7380 5850 50  0001 C CNN
F 3 "~" H 7450 5850 50  0001 C CNN
	1    7450 5850
	1    0    0    -1  
$EndComp
$Comp
L Battery_Management:TP4056 U2
U 1 1 631FE546
P 9400 3950
F 0 "U2" H 9150 4300 50  0000 C CNN
F 1 "TP4056" H 9600 4300 50  0000 C CNN
F 2 "Package_SO:MSOP-8-1EP_3x3mm_P0.65mm_EP1.95x2.15mm" H 9250 4300 50  0001 C CNN
F 3 "" H 9250 4300 50  0001 C CNN
	1    9400 3950
	1    0    0    -1  
$EndComp
$Comp
L Battery_Management:DW01 U3
U 1 1 631FF433
P 10150 5200
F 0 "U3" H 10250 5550 50  0000 C CNN
F 1 "DW01" H 9950 5550 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23-6" H 10200 5550 50  0001 C CNN
F 3 "" H 10200 5550 50  0001 C CNN
	1    10150 5200
	1    0    0    -1  
$EndComp
$Comp
L Battery_Management:AM8205 U5
U 1 1 631FFA11
P 10150 6250
F 0 "U5" H 10150 6665 50  0000 C CNN
F 1 "AM8205" H 10150 6574 50  0000 C CNN
F 2 "Package_SO:TSSOP-8_3x3mm_P0.65mm" H 10000 6550 50  0001 C CNN
F 3 "" H 10000 6550 50  0001 C CNN
	1    10150 6250
	1    0    0    -1  
$EndComp
Wire Wire Line
	1050 2200 1050 2350
Wire Wire Line
	1050 2350 900  2350
Wire Wire Line
	750  2350 750  2200
$Comp
L Regulator_Linear:AMS1117-3.3 U4
U 1 1 6320B133
P 4900 3200
F 0 "U4" H 4900 3442 50  0000 C CNN
F 1 "AMS1117-3.3" H 4900 3351 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-223-3_TabPin2" H 4900 3400 50  0001 C CNN
F 3 "http://www.advanced-monolithic.com/pdf/ds1117.pdf" H 5000 2950 50  0001 C CNN
	1    4900 3200
	1    0    0    -1  
$EndComp
$Comp
L Device:R_PHOTO R18
U 1 1 63213A51
P 7450 5350
F 0 "R18" H 7520 5396 50  0000 L CNN
F 1 "R_PHOTO" H 7520 5305 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x02_P2.00mm_Vertical" V 7500 5100 50  0001 L CNN
F 3 "~" H 7450 5300 50  0001 C CNN
	1    7450 5350
	1    0    0    -1  
$EndComp
$Comp
L Device:C C5
U 1 1 63218CDA
P 4400 3450
F 0 "C5" H 4515 3496 50  0000 L CNN
F 1 "10uF" H 4515 3405 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 4438 3300 50  0001 C CNN
F 3 "~" H 4400 3450 50  0001 C CNN
	1    4400 3450
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C6
U 1 1 63218CE0
P 5400 3450
F 0 "C6" H 5518 3496 50  0000 L CNN
F 1 "10uF" H 5518 3405 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 5438 3300 50  0001 C CNN
F 3 "~" H 5400 3450 50  0001 C CNN
	1    5400 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	5400 3300 5400 3200
Wire Wire Line
	5400 3200 5200 3200
Wire Wire Line
	4600 3200 4400 3200
Wire Wire Line
	4400 3200 4400 3300
$Comp
L power:GNDD #PWR0101
U 1 1 6321C7DC
P 4900 3750
F 0 "#PWR0101" H 4900 3500 50  0001 C CNN
F 1 "GNDD" H 4904 3595 50  0000 C CNN
F 2 "" H 4900 3750 50  0001 C CNN
F 3 "" H 4900 3750 50  0001 C CNN
	1    4900 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	4900 3750 4900 3700
Wire Wire Line
	5400 3600 5400 3700
Wire Wire Line
	5400 3700 4900 3700
Connection ~ 4900 3700
Wire Wire Line
	4900 3700 4900 3500
Wire Wire Line
	4900 3700 4400 3700
Wire Wire Line
	4400 3700 4400 3600
Text GLabel 4250 3200 0    50   Input ~ 0
5VA
Wire Wire Line
	4250 3200 4400 3200
Connection ~ 4400 3200
Text GLabel 5550 3200 2    50   Input ~ 0
3.3VR
Wire Wire Line
	5550 3200 5400 3200
Connection ~ 5400 3200
$Comp
L Connector:TestPoint TP1
U 1 1 6322A85F
P 5400 3000
F 0 "TP1" H 5458 3118 50  0000 L CNN
F 1 "3.3V" H 5458 3027 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_1.5x1.5mm" H 5600 3000 50  0001 C CNN
F 3 "~" H 5600 3000 50  0001 C CNN
	1    5400 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	5400 3000 5400 3200
Text GLabel 900  7350 0    50   Input ~ 0
3.3VR
Text GLabel 900  7450 0    50   Input ~ 0
RX
Text GLabel 1700 7350 2    50   Input ~ 0
TX
Text GLabel 1700 7450 2    50   Input ~ 0
GND
$Comp
L Connector_Generic:Conn_02x03_Counter_Clockwise J5
U 1 1 6322E71D
P 1250 7450
F 0 "J5" H 1300 7767 50  0000 C CNN
F 1 "Conn_02x03_Counter_Clockwise" H 1300 7676 50  0000 C CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_2x03_P2.00mm_Vertical" H 1250 7450 50  0001 C CNN
F 3 "~" H 1250 7450 50  0001 C CNN
	1    1250 7450
	1    0    0    -1  
$EndComp
Text GLabel 900  7550 0    50   Input ~ 0
DTR
Text GLabel 1700 7550 2    50   Input ~ 0
GND
Wire Wire Line
	1700 7550 1550 7550
Wire Wire Line
	1550 7450 1700 7450
Wire Wire Line
	1700 7350 1550 7350
Wire Wire Line
	1050 7350 900  7350
Wire Wire Line
	900  7450 1050 7450
Wire Wire Line
	1050 7550 900  7550
$Comp
L Jumper:SolderJumper_2_Open JP1
U 1 1 63235E13
P 2550 3800
F 0 "JP1" V 2550 3868 50  0000 L CNN
F 1 "SolderJumper_2_Open" H 2550 3914 50  0001 C CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Open_RoundedPad1.0x1.5mm" H 2550 3800 50  0001 C CNN
F 3 "~" H 2550 3800 50  0001 C CNN
	1    2550 3800
	0    1    1    0   
$EndComp
$Comp
L power:GNDD #PWR0102
U 1 1 63237CCB
P 1450 4500
F 0 "#PWR0102" H 1450 4250 50  0001 C CNN
F 1 "GNDD" H 1454 4345 50  0000 C CNN
F 2 "" H 1450 4500 50  0001 C CNN
F 3 "" H 1450 4500 50  0001 C CNN
	1    1450 4500
	1    0    0    -1  
$EndComp
Text GLabel 800  3750 0    50   Input ~ 0
TX
Wire Wire Line
	800  3750 950  3750
Text GLabel 800  3850 0    50   Input ~ 0
RX
Wire Wire Line
	800  3850 950  3850
Text GLabel 1600 2850 2    50   Input ~ 0
3.3VR
Wire Wire Line
	1450 2850 1600 2850
Wire Wire Line
	1450 2850 1450 3050
$Comp
L RF_Module:ESP-WROOM-02 U1
U 1 1 6324C251
P 1450 3650
F 0 "U1" H 1100 3100 50  0000 C CNN
F 1 "ESP-WROOM-02" H 1850 3100 50  0000 C CNN
F 2 "RF_Module:ESP-12E" H 2050 3100 50  0001 C CNN
F 3 "https://www.espressif.com/sites/default/files/documentation/0c-esp-wroom-02_datasheet_en.pdf" H 1500 5150 50  0001 C CNN
	1    1450 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	2550 3650 2550 3250
Wire Wire Line
	2550 3950 2550 4400
$Comp
L power:GNDA #PWR0103
U 1 1 6325976E
P 900 2450
F 0 "#PWR0103" H 900 2200 50  0001 C CNN
F 1 "GNDA" H 905 2277 50  0000 C CNN
F 2 "" H 900 2450 50  0001 C CNN
F 3 "" H 900 2450 50  0001 C CNN
	1    900  2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	900  2450 900  2350
Connection ~ 900  2350
Wire Wire Line
	900  2350 750  2350
Text GLabel 1800 700  2    50   Input ~ 0
VIN
Wire Wire Line
	1800 700  1650 700 
Text GLabel 800  3250 0    50   Input ~ 0
DTR
Wire Wire Line
	950  3250 800  3250
Text Notes 2800 3900 0    50   ~ 0
NF - Porta Gravação\nNA - Porta Uso
$Comp
L Device:R R15
U 1 1 6325D834
P 1850 5200
F 0 "R15" H 1920 5246 50  0000 L CNN
F 1 "1M" H 1920 5155 50  0000 L CNN
F 2 "Resistor_SMD:R_0201_0603Metric_Pad0.64x0.40mm_HandSolder" V 1780 5200 50  0001 C CNN
F 3 "~" H 1850 5200 50  0001 C CNN
	1    1850 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	1850 4850 1850 5050
Wire Wire Line
	1000 5550 1450 5550
Wire Wire Line
	1850 5550 1850 5350
$Comp
L power:GNDD #PWR0104
U 1 1 63260200
P 1450 5650
F 0 "#PWR0104" H 1450 5400 50  0001 C CNN
F 1 "GNDD" H 1454 5495 50  0000 C CNN
F 2 "" H 1450 5650 50  0001 C CNN
F 3 "" H 1450 5650 50  0001 C CNN
	1    1450 5650
	1    0    0    -1  
$EndComp
Wire Wire Line
	1450 5650 1450 5550
Connection ~ 1450 5550
Text GLabel 2050 4850 2    50   Input ~ 0
WAKE
$Comp
L Device:R R19
U 1 1 6326A514
P 1850 6350
F 0 "R19" H 1920 6396 50  0000 L CNN
F 1 "1M" H 1920 6305 50  0000 L CNN
F 2 "Resistor_SMD:R_0201_0603Metric_Pad0.64x0.40mm_HandSolder" V 1780 6350 50  0001 C CNN
F 3 "~" H 1850 6350 50  0001 C CNN
	1    1850 6350
	1    0    0    -1  
$EndComp
Wire Wire Line
	1850 6000 1850 6200
Wire Wire Line
	1850 6700 1850 6500
$Comp
L power:GNDD #PWR0105
U 1 1 6326A526
P 1450 6800
F 0 "#PWR0105" H 1450 6550 50  0001 C CNN
F 1 "GNDD" H 1454 6645 50  0000 C CNN
F 2 "" H 1450 6800 50  0001 C CNN
F 3 "" H 1450 6800 50  0001 C CNN
	1    1450 6800
	1    0    0    -1  
$EndComp
Wire Wire Line
	1450 6800 1450 6700
Connection ~ 1450 6700
Text GLabel 2050 6000 2    50   Input ~ 0
MODE
$Comp
L Diode:DZ2S056X0L D4
U 1 1 63277760
P 4200 1300
F 0 "D4" V 4154 1380 50  0000 L CNN
F 1 "DZ2S056X0L" H 3950 1200 50  0000 L CNN
F 2 "Diode_SMD:D_SOD-523" H 4200 1125 50  0001 C CNN
F 3 "https://industrial.panasonic.com/content/data/SC/ds/ds4/DZ2S05600L_E.pdf" H 4200 1300 50  0001 C CNN
	1    4200 1300
	0    1    1    0   
$EndComp
$Comp
L Device:R R2
U 1 1 6327E285
P 2550 1000
F 0 "R2" H 2620 1046 50  0000 L CNN
F 1 "2K2" H 2620 955 50  0000 L CNN
F 2 "Resistor_SMD:R_0201_0603Metric_Pad0.64x0.40mm_HandSolder" V 2480 1000 50  0001 C CNN
F 3 "~" H 2550 1000 50  0001 C CNN
	1    2550 1000
	-1   0    0    -1  
$EndComp
$Comp
L Device:R R7
U 1 1 6327F12B
P 3450 1850
F 0 "R7" H 3520 1896 50  0000 L CNN
F 1 "4K7" H 3520 1805 50  0000 L CNN
F 2 "Resistor_SMD:R_0201_0603Metric_Pad0.64x0.40mm_HandSolder" V 3380 1850 50  0001 C CNN
F 3 "~" H 3450 1850 50  0001 C CNN
	1    3450 1850
	-1   0    0    -1  
$EndComp
$Comp
L Device:Ferrite_Bead FB1
U 1 1 63280EB6
P 3850 2150
F 0 "FB1" V 4032 2150 50  0000 C CNN
F 1 "Ferrite_Bead" H 3987 2105 50  0001 L CNN
F 2 "Resistor_SMD:R_0201_0603Metric_Pad0.64x0.40mm_HandSolder" V 3780 2150 50  0001 C CNN
F 3 "~" H 3850 2150 50  0001 C CNN
	1    3850 2150
	0    -1   -1   0   
$EndComp
$Comp
L Device:C C1
U 1 1 632821DA
P 4500 1300
F 0 "C1" H 4615 1346 50  0000 L CNN
F 1 "47uF" H 4615 1255 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 4538 1150 50  0001 C CNN
F 3 "~" H 4500 1300 50  0001 C CNN
	1    4500 1300
	1    0    0    -1  
$EndComp
$Comp
L Device:R R5
U 1 1 63285428
P 2850 1300
F 0 "R5" V 2650 1250 50  0000 L CNN
F 1 "4K7" V 2750 1200 50  0000 L CNN
F 2 "Resistor_SMD:R_0201_0603Metric_Pad0.64x0.40mm_HandSolder" V 2780 1300 50  0001 C CNN
F 3 "~" H 2850 1300 50  0001 C CNN
	1    2850 1300
	0    1    1    0   
$EndComp
$Comp
L Transistor_FET:2N7000 Q1
U 1 1 6328675F
P 3850 800
F 0 "Q1" V 4192 800 50  0000 C CNN
F 1 "2N7000" V 4101 800 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 4050 725 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/NDS7002A-D.PDF" H 3850 800 50  0001 L CNN
	1    3850 800 
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2700 1300 2550 1300
Wire Wire Line
	2550 1300 2550 1150
$Comp
L Transistor_BJT:BC548 Q4
U 1 1 6328BA5B
P 3350 1300
F 0 "Q4" H 3541 1346 50  0000 L CNN
F 1 "BC548" H 3541 1255 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 3550 1225 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/BC550-D.pdf" H 3350 1300 50  0001 L CNN
	1    3350 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	3450 1500 3450 1600
Wire Wire Line
	3150 1300 3000 1300
Wire Wire Line
	3450 1100 3450 700 
Wire Wire Line
	3450 700  2550 700 
Wire Wire Line
	2550 700  2550 850 
Wire Wire Line
	3650 700  3450 700 
Connection ~ 3450 700 
Wire Wire Line
	3850 1000 3850 1600
Wire Wire Line
	3850 1600 3450 1600
Connection ~ 3450 1600
Wire Wire Line
	3450 1600 3450 1700
$Comp
L power:GNDA #PWR0106
U 1 1 6329F4CB
P 3450 2250
F 0 "#PWR0106" H 3450 2000 50  0001 C CNN
F 1 "GNDA" H 3455 2077 50  0000 C CNN
F 2 "" H 3450 2250 50  0001 C CNN
F 3 "" H 3450 2250 50  0001 C CNN
	1    3450 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3450 2250 3450 2150
Wire Wire Line
	3700 2150 3450 2150
Wire Wire Line
	3450 2150 3450 2000
Connection ~ 3450 2150
Wire Wire Line
	4200 1150 4200 700 
Wire Wire Line
	4200 700  4050 700 
Wire Wire Line
	4500 1150 4500 700 
Wire Wire Line
	4500 700  4200 700 
Connection ~ 4200 700 
Wire Wire Line
	4500 1450 4500 2150
Wire Wire Line
	4500 2150 4000 2150
$Comp
L power:GNDD #PWR0107
U 1 1 632AD80B
P 4500 2250
F 0 "#PWR0107" H 4500 2000 50  0001 C CNN
F 1 "GNDD" H 4504 2095 50  0000 C CNN
F 2 "" H 4500 2250 50  0001 C CNN
F 3 "" H 4500 2250 50  0001 C CNN
	1    4500 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	4500 2250 4500 2150
Connection ~ 4500 2150
$Comp
L power:GNDD #PWR0108
U 1 1 632B100D
P 4200 1550
F 0 "#PWR0108" H 4200 1300 50  0001 C CNN
F 1 "GNDD" H 4204 1395 50  0000 C CNN
F 2 "" H 4200 1550 50  0001 C CNN
F 3 "" H 4200 1550 50  0001 C CNN
	1    4200 1550
	1    0    0    -1  
$EndComp
Wire Wire Line
	4200 1550 4200 1450
Text GLabel 2400 700  0    50   Input ~ 0
VIN
Wire Wire Line
	2400 700  2550 700 
Connection ~ 2550 700 
Text GLabel 4650 700  2    50   Input ~ 0
5VA
Wire Wire Line
	4650 700  4500 700 
Connection ~ 4500 700 
$Comp
L Diode:DZ2S036X0L D3
U 1 1 632DB553
P 5500 950
F 0 "D3" V 5454 1030 50  0000 L CNN
F 1 "DZ2S036X0L" H 5300 850 50  0000 L CNN
F 2 "Diode_SMD:D_SOD-523" H 5500 775 50  0001 C CNN
F 3 "https://industrial.panasonic.com/content/data/SC/ds/ds4/DZ2S03600L_E.pdf" H 5500 950 50  0001 C CNN
	1    5500 950 
	0    1    1    0   
$EndComp
Text GLabel 5350 700  0    50   Input ~ 0
3.3VR
Wire Wire Line
	5350 700  5500 700 
Wire Wire Line
	5500 800  5500 700 
$Comp
L Device:R R8
U 1 1 632E3861
P 5500 1900
F 0 "R8" H 5570 1946 50  0000 L CNN
F 1 "1K" H 5570 1855 50  0000 L CNN
F 2 "Resistor_SMD:R_0201_0603Metric_Pad0.64x0.40mm_HandSolder" V 5430 1900 50  0001 C CNN
F 3 "~" H 5500 1900 50  0001 C CNN
	1    5500 1900
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 632E4B2B
P 5950 950
F 0 "R1" H 6020 996 50  0000 L CNN
F 1 "1K" H 6020 905 50  0000 L CNN
F 2 "Resistor_SMD:R_0201_0603Metric_Pad0.64x0.40mm_HandSolder" V 5880 950 50  0001 C CNN
F 3 "~" H 5950 950 50  0001 C CNN
	1    5950 950 
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_SCR_AGK D5
U 1 1 632E587D
P 5950 1450
F 0 "D5" H 6038 1496 50  0000 L CNN
F 1 "Q_SCR_AGK" H 6038 1405 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" V 5950 1450 50  0001 C CNN
F 3 "~" V 5950 1450 50  0001 C CNN
	1    5950 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	5800 1550 5500 1550
Wire Wire Line
	5500 1550 5500 1100
Wire Wire Line
	5500 1750 5500 1550
Connection ~ 5500 1550
Wire Wire Line
	5950 1300 5950 1200
Wire Wire Line
	5950 800  5950 700 
Wire Wire Line
	5950 700  5500 700 
Connection ~ 5500 700 
$Comp
L power:GNDD #PWR0109
U 1 1 632EE6FD
P 5500 2250
F 0 "#PWR0109" H 5500 2000 50  0001 C CNN
F 1 "GNDD" H 5504 2095 50  0000 C CNN
F 2 "" H 5500 2250 50  0001 C CNN
F 3 "" H 5500 2250 50  0001 C CNN
	1    5500 2250
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR0110
U 1 1 632F03A6
P 5950 2250
F 0 "#PWR0110" H 5950 2000 50  0001 C CNN
F 1 "GNDD" H 5954 2095 50  0000 C CNN
F 2 "" H 5950 2250 50  0001 C CNN
F 3 "" H 5950 2250 50  0001 C CNN
	1    5950 2250
	1    0    0    -1  
$EndComp
$Comp
L Transistor_FET:2N7002 Q3
U 1 1 632F2694
P 6500 1200
F 0 "Q3" H 6704 1246 50  0000 L CNN
F 1 "2N7002" H 6704 1155 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 6700 1125 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/NDS7002A-D.PDF" H 6500 1200 50  0001 L CNN
	1    6500 1200
	1    0    0    -1  
$EndComp
Wire Wire Line
	6300 1200 5950 1200
Connection ~ 5950 1200
Wire Wire Line
	5950 1200 5950 1100
Wire Wire Line
	6600 1400 6600 1900
Wire Wire Line
	6600 1900 5950 1900
Wire Wire Line
	5950 1900 5950 1600
Wire Wire Line
	5500 2050 5500 2250
Wire Wire Line
	5950 2250 5950 1900
Connection ~ 5950 1900
Wire Wire Line
	6600 1000 6600 850 
Wire Wire Line
	6600 850  7050 850 
Wire Wire Line
	7050 850  7050 1200
$Comp
L power:GNDD #PWR0111
U 1 1 633070A7
P 7050 1200
F 0 "#PWR0111" H 7050 950 50  0001 C CNN
F 1 "GNDD" H 7054 1045 50  0000 C CNN
F 2 "" H 7050 1200 50  0001 C CNN
F 3 "" H 7050 1200 50  0001 C CNN
	1    7050 1200
	1    0    0    -1  
$EndComp
Text GLabel 6100 700  2    50   Input ~ 0
3.3VA
Wire Wire Line
	6100 700  5950 700 
Connection ~ 5950 700 
$Comp
L Diode:1N5819 D1
U 1 1 63310CC5
P 9050 650
F 0 "D1" H 9200 550 50  0000 C CNN
F 1 "1N5819" H 8950 550 50  0000 C CNN
F 2 "Diode_SMD:D_SOD-523" H 9050 475 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88525/1n5817.pdf" H 9050 650 50  0001 C CNN
	1    9050 650 
	-1   0    0    1   
$EndComp
$Comp
L Diode:1N5819 D2
U 1 1 63313CB7
P 9050 850
F 0 "D2" H 9200 700 50  0000 C CNN
F 1 "1N5819" H 8950 700 50  0000 C CNN
F 2 "Diode_SMD:D_SOD-523" H 9050 675 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88525/1n5817.pdf" H 9050 850 50  0001 C CNN
	1    9050 850 
	-1   0    0    -1  
$EndComp
$Comp
L Device:R R3
U 1 1 63315E74
P 9350 1150
F 0 "R3" H 9420 1196 50  0000 L CNN
F 1 "200K" H 9420 1105 50  0000 L CNN
F 2 "Resistor_SMD:R_0201_0603Metric_Pad0.64x0.40mm_HandSolder" V 9280 1150 50  0001 C CNN
F 3 "~" H 9350 1150 50  0001 C CNN
	1    9350 1150
	1    0    0    -1  
$EndComp
$Comp
L Device:R R4
U 1 1 633169CC
P 10050 1150
F 0 "R4" H 10120 1196 50  0000 L CNN
F 1 "1M" H 10120 1105 50  0000 L CNN
F 2 "Resistor_SMD:R_0201_0603Metric_Pad0.64x0.40mm_HandSolder" V 9980 1150 50  0001 C CNN
F 3 "~" H 10050 1150 50  0001 C CNN
	1    10050 1150
	-1   0    0    -1  
$EndComp
$Comp
L Transistor_BJT:BC548 Q6
U 1 1 63319F0D
P 9250 2150
F 0 "Q6" H 9441 2196 50  0000 L CNN
F 1 "BC548" H 9441 2105 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 9450 2075 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/BC550-D.pdf" H 9250 2150 50  0001 L CNN
	1    9250 2150
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT:BC548 Q5
U 1 1 6331BFF4
P 10450 1800
F 0 "Q5" H 10641 1846 50  0000 L CNN
F 1 "BC548" H 10641 1755 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 10650 1725 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/BC550-D.pdf" H 10450 1800 50  0001 L CNN
	1    10450 1800
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT:BC548 Q2
U 1 1 6331DC48
P 10550 950
F 0 "Q2" V 10878 950 50  0000 C CNN
F 1 "BC548" V 10787 950 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 10750 875 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/BC550-D.pdf" H 10550 950 50  0001 L CNN
	1    10550 950 
	0    -1   -1   0   
$EndComp
Wire Wire Line
	9200 850  9350 850 
Wire Wire Line
	9350 850  9350 1000
Wire Wire Line
	9200 650  9350 650 
Wire Wire Line
	9350 650  9350 850 
Connection ~ 9350 850 
Wire Wire Line
	9350 850  10050 850 
Wire Wire Line
	10050 1000 10050 850 
Connection ~ 10050 850 
Wire Wire Line
	10050 850  10350 850 
Wire Wire Line
	10050 1450 10550 1450
Wire Wire Line
	10050 1300 10050 1450
Wire Wire Line
	10550 1150 10550 1450
Wire Wire Line
	10550 1600 10550 1450
Connection ~ 10550 1450
Wire Wire Line
	8900 2150 9050 2150
$Comp
L Device:R R10
U 1 1 6334B3D1
P 8450 2450
F 0 "R10" H 8520 2496 50  0000 L CNN
F 1 "100R" H 8520 2405 50  0000 L CNN
F 2 "Resistor_SMD:R_0201_0603Metric_Pad0.64x0.40mm_HandSolder" V 8380 2450 50  0001 C CNN
F 3 "~" H 8450 2450 50  0001 C CNN
	1    8450 2450
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR0112
U 1 1 6334BEB0
P 8450 2700
F 0 "#PWR0112" H 8450 2450 50  0001 C CNN
F 1 "GNDD" H 8454 2545 50  0000 C CNN
F 2 "" H 8450 2700 50  0001 C CNN
F 3 "" H 8450 2700 50  0001 C CNN
	1    8450 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	8450 2700 8450 2600
$Comp
L power:GNDD #PWR0113
U 1 1 6334F0F6
P 9350 2450
F 0 "#PWR0113" H 9350 2200 50  0001 C CNN
F 1 "GNDD" H 9354 2295 50  0000 C CNN
F 2 "" H 9350 2450 50  0001 C CNN
F 3 "" H 9350 2450 50  0001 C CNN
	1    9350 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	9350 2450 9350 2350
$Comp
L power:GNDD #PWR0114
U 1 1 633525A1
P 10550 2100
F 0 "#PWR0114" H 10550 1850 50  0001 C CNN
F 1 "GNDD" H 10554 1945 50  0000 C CNN
F 2 "" H 10550 2100 50  0001 C CNN
F 3 "" H 10550 2100 50  0001 C CNN
	1    10550 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	10550 2100 10550 2000
Wire Wire Line
	8450 2300 8450 2150
Wire Wire Line
	8450 2150 8600 2150
$Comp
L Device:R R9
U 1 1 63347766
P 8750 2150
F 0 "R9" V 8950 2100 50  0000 L CNN
F 1 "1K" V 8850 2100 50  0000 L CNN
F 2 "Resistor_SMD:R_0201_0603Metric_Pad0.64x0.40mm_HandSolder" V 8680 2150 50  0001 C CNN
F 3 "~" H 8750 2150 50  0001 C CNN
	1    8750 2150
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R6
U 1 1 63316F3B
P 9800 1800
F 0 "R6" V 10000 1750 50  0000 L CNN
F 1 "1K" V 9900 1750 50  0000 L CNN
F 2 "Resistor_SMD:R_0201_0603Metric_Pad0.64x0.40mm_HandSolder" V 9730 1800 50  0001 C CNN
F 3 "~" H 9800 1800 50  0001 C CNN
	1    9800 1800
	0    -1   -1   0   
$EndComp
Text GLabel 8750 650  0    50   Input ~ 0
BAT1+
Wire Wire Line
	8900 650  8750 650 
Text GLabel 8750 850  0    50   Input ~ 0
BAT2+
Wire Wire Line
	8900 850  8750 850 
Text GLabel 8300 2150 0    50   Input ~ 0
5VA
Wire Wire Line
	8300 2150 8450 2150
Connection ~ 8450 2150
Wire Wire Line
	9350 1300 9350 1800
Wire Wire Line
	9950 1800 10250 1800
Wire Wire Line
	9650 1800 9350 1800
Connection ~ 9350 1800
Wire Wire Line
	9350 1800 9350 1950
Text GLabel 10900 850  2    50   Input ~ 0
DCDC
Wire Wire Line
	10750 850  10900 850 
$Sheet
S -1250 950  1100 150 
U 633CFED4
F0 "Nixie Circuit" 50
F1 "Nixie Circuit.sch" 50
$EndSheet
Wire Wire Line
	1950 3950 2100 3950
Text GLabel 2100 3950 2    50   Input ~ 0
GPIO15
Wire Wire Line
	1950 3750 2100 3750
Text GLabel 2100 3750 2    50   Input ~ 0
GPIO13
Wire Wire Line
	1950 3850 2100 3850
Text GLabel 2100 3850 2    50   Input ~ 0
GPIO14
Wire Wire Line
	1950 3550 2100 3550
Text GLabel 2100 3550 2    50   Input ~ 0
GPIO5
Wire Wire Line
	1950 3450 2100 3450
Text GLabel 2100 3450 2    50   Input ~ 0
GPIO4
Wire Wire Line
	1450 4250 1450 4400
Wire Wire Line
	1950 3250 2550 3250
Wire Wire Line
	1450 4400 2550 4400
Connection ~ 1450 4400
Wire Wire Line
	1450 4400 1450 4500
Text GLabel 8900 3350 0    50   Input ~ 0
5VA
Wire Wire Line
	8900 3350 9400 3350
Wire Wire Line
	9800 3800 9900 3800
Wire Wire Line
	9900 3350 9400 3350
Connection ~ 9400 3350
Wire Wire Line
	9400 3350 9400 3550
Wire Wire Line
	9900 3350 9900 3800
$Comp
L Device:R R12
U 1 1 634A21DD
P 10050 3950
F 0 "R12" V 9950 3850 50  0000 L CNN
F 1 "1K" V 9950 4000 50  0000 L CNN
F 2 "Resistor_SMD:R_0201_0603Metric_Pad0.64x0.40mm_HandSolder" V 9980 3950 50  0001 C CNN
F 3 "~" H 10050 3950 50  0001 C CNN
	1    10050 3950
	0    1    1    0   
$EndComp
$Comp
L Device:R R13
U 1 1 634A88D6
P 10050 4100
F 0 "R13" V 9950 4000 50  0000 L CNN
F 1 "1K" V 9950 4150 50  0000 L CNN
F 2 "Resistor_SMD:R_0201_0603Metric_Pad0.64x0.40mm_HandSolder" V 9980 4100 50  0001 C CNN
F 3 "~" H 10050 4100 50  0001 C CNN
	1    10050 4100
	0    1    -1   0   
$EndComp
Wire Wire Line
	9900 4100 9800 4100
Wire Wire Line
	9800 3950 9900 3950
Wire Wire Line
	10200 3950 10300 3950
Connection ~ 9900 3350
$Comp
L Device:R R11
U 1 1 634C569E
P 8650 3950
F 0 "R11" V 8450 3900 50  0000 L CNN
F 1 "1K2" V 8550 3850 50  0000 L CNN
F 2 "Resistor_SMD:R_0201_0603Metric_Pad0.64x0.40mm_HandSolder" V 8580 3950 50  0001 C CNN
F 3 "~" H 8650 3950 50  0001 C CNN
	1    8650 3950
	0    1    1    0   
$EndComp
Wire Wire Line
	9000 3800 8900 3800
Wire Wire Line
	8900 3800 8900 4450
Wire Wire Line
	8900 4450 9400 4450
Wire Wire Line
	9400 4450 9400 4350
Wire Wire Line
	8800 3950 9000 3950
Wire Wire Line
	8500 3950 8400 3950
Wire Wire Line
	8400 3950 8400 4450
Wire Wire Line
	8400 4450 8900 4450
Connection ~ 8900 4450
$Comp
L Device:CP C2
U 1 1 634E5BA5
P 11050 4000
F 0 "C2" H 11168 4046 50  0000 L CNN
F 1 "10uF" H 11168 3955 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 11088 3850 50  0001 C CNN
F 3 "~" H 11050 4000 50  0001 C CNN
	1    11050 4000
	-1   0    0    -1  
$EndComp
Wire Wire Line
	11050 3850 11050 3350
Wire Wire Line
	11050 4150 11050 4450
Connection ~ 9400 4450
Text Notes 7700 4450 0    50   ~ 0
10K - 130mA\n5K - 250mA\n4K - 300mA\n3K - 400mA\n2K - 580mA\n1.66K - 690mA\n1.5K - 780mA\n1.33K - 900mA\n1.2K - 1A
Text GLabel 8800 4100 0    50   Input ~ 0
BAT
Wire Wire Line
	8800 4100 9000 4100
$Comp
L Device:R R14
U 1 1 634FEF5C
P 9150 4600
F 0 "R14" V 9050 4500 50  0000 L CNN
F 1 "100R" V 9050 4650 50  0000 L CNN
F 2 "Resistor_SMD:R_0201_0603Metric_Pad0.64x0.40mm_HandSolder" V 9080 4600 50  0001 C CNN
F 3 "~" H 9150 4600 50  0001 C CNN
	1    9150 4600
	0    1    -1   0   
$EndComp
Text GLabel 8850 4600 0    50   Input ~ 0
BAT1+
Wire Wire Line
	10150 4800 10150 4600
$Comp
L Device:C C3
U 1 1 63524BC6
P 9450 5200
F 0 "C3" H 9565 5246 50  0000 L CNN
F 1 "20pF" H 9565 5155 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 9488 5050 50  0001 C CNN
F 3 "~" H 9450 5200 50  0001 C CNN
	1    9450 5200
	-1   0    0    -1  
$EndComp
Wire Wire Line
	9450 5050 9450 4600
Wire Wire Line
	9450 5350 9450 5750
Wire Wire Line
	9450 5750 10150 5750
Wire Wire Line
	10150 5750 10150 5600
Text GLabel 9750 5150 0    50   Input ~ 0
G2
Text GLabel 9650 6100 0    50   Input ~ 0
G2
Text GLabel 10550 5150 2    50   Input ~ 0
G1
Text GLabel 9650 6300 0    50   Input ~ 0
G1
Wire Wire Line
	9650 6300 9850 6300
Wire Wire Line
	9850 6100 9650 6100
Wire Wire Line
	10550 5150 10450 5150
Wire Wire Line
	9850 5150 9750 5150
Wire Wire Line
	9450 4600 9300 4600
Connection ~ 9450 4600
Wire Wire Line
	9450 4600 10150 4600
$Comp
L Device:R R16
U 1 1 635DA41C
P 10700 5250
F 0 "R16" V 10600 5150 50  0000 L CNN
F 1 "1K" V 10600 5300 50  0000 L CNN
F 2 "Resistor_SMD:R_0201_0603Metric_Pad0.64x0.40mm_HandSolder" V 10630 5250 50  0001 C CNN
F 3 "~" H 10700 5250 50  0001 C CNN
	1    10700 5250
	0    1    -1   0   
$EndComp
Wire Wire Line
	10550 5250 10450 5250
Wire Wire Line
	10850 5250 11050 5250
Wire Wire Line
	11050 5250 11050 4450
Connection ~ 11050 4450
$Comp
L Device:CP C4
U 1 1 635EEA54
P 11050 5750
F 0 "C4" H 11168 5796 50  0000 L CNN
F 1 "10uF" H 11168 5705 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 11088 5600 50  0001 C CNN
F 3 "~" H 11050 5750 50  0001 C CNN
	1    11050 5750
	-1   0    0    -1  
$EndComp
Wire Wire Line
	11050 5600 11050 5250
Connection ~ 11050 5250
Wire Wire Line
	9850 6200 9750 6200
Wire Wire Line
	9750 6200 9750 6500
Wire Wire Line
	9750 6500 10550 6500
Wire Wire Line
	10550 6500 10550 6200
Wire Wire Line
	10550 6200 10450 6200
Text GLabel 10850 6200 0    50   Input ~ 0
BAT
Wire Wire Line
	10850 6200 11050 6200
Wire Wire Line
	11050 5900 11050 6200
Text GLabel 10650 6300 2    50   Input ~ 0
BAT1-
Wire Wire Line
	10450 6300 10650 6300
$Comp
L power:GNDD #PWR0115
U 1 1 636378BD
P 8400 4550
F 0 "#PWR0115" H 8400 4300 50  0001 C CNN
F 1 "GNDD" H 8404 4395 50  0000 C CNN
F 2 "" H 8400 4550 50  0001 C CNN
F 3 "" H 8400 4550 50  0001 C CNN
	1    8400 4550
	1    0    0    -1  
$EndComp
Wire Wire Line
	8400 4550 8400 4450
Wire Wire Line
	8850 4600 9000 4600
Connection ~ 8400 4450
Wire Wire Line
	9400 4450 11050 4450
$Comp
L Connector:Conn_01x02_Female J3
U 1 1 63663157
P 8950 5150
F 0 "J3" H 8978 5080 50  0000 L CNN
F 1 "Conn_01x02_Female" H 8978 5035 50  0001 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x02_P2.00mm_Vertical" H 8950 5150 50  0001 C CNN
F 3 "~" H 8950 5150 50  0001 C CNN
	1    8950 5150
	1    0    0    -1  
$EndComp
Text GLabel 8600 5150 0    50   Input ~ 0
BAT1+
Wire Wire Line
	8600 5150 8750 5150
Text GLabel 8600 5250 0    50   Input ~ 0
BAT1-
Wire Wire Line
	8600 5250 8750 5250
Wire Notes Line
	8850 3700 7650 3700
Wire Notes Line
	7650 3700 7650 4500
Wire Notes Line
	7650 4500 8350 4500
Wire Notes Line
	8350 4500 8350 4050
Wire Notes Line
	8350 4050 8850 4050
Wire Notes Line
	8850 3700 8850 4050
Wire Wire Line
	9900 3350 11050 3350
Wire Wire Line
	10200 4100 10300 4100
Text GLabel 10300 3950 2    50   Input ~ 0
CHRG
Text GLabel 10300 4100 2    50   Input ~ 0
STDBY
$Comp
L Connector:Conn_01x02_Female P2
U 1 1 637CF916
P 650 5150
F 0 "P2" H 542 5243 50  0000 C CNN
F 1 "Conn_01x02_Female" H 678 5035 50  0001 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x02_P2.00mm_Vertical" H 650 5150 50  0001 C CNN
F 3 "~" H 650 5150 50  0001 C CNN
	1    650  5150
	-1   0    0    -1  
$EndComp
Wire Wire Line
	850  5150 1000 5150
Wire Wire Line
	1000 5150 1000 4850
Wire Wire Line
	850  5250 1000 5250
Wire Wire Line
	1000 5250 1000 5550
Wire Wire Line
	1850 5550 1450 5550
$Comp
L Connector:Conn_01x02_Female P4
U 1 1 637E1304
P 650 6300
F 0 "P4" H 542 6393 50  0000 C CNN
F 1 "Conn_01x02_Female" H 678 6185 50  0001 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x02_P2.00mm_Vertical" H 650 6300 50  0001 C CNN
F 3 "~" H 650 6300 50  0001 C CNN
	1    650  6300
	-1   0    0    -1  
$EndComp
Wire Wire Line
	850  6300 1000 6300
Wire Wire Line
	1000 6300 1000 6000
Wire Wire Line
	850  6400 1000 6400
Wire Wire Line
	1000 6400 1000 6700
Wire Wire Line
	1850 6700 1450 6700
Text GLabel 7600 5050 2    50   Input ~ 0
PWLDR
Wire Wire Line
	7450 5500 7450 5600
$Comp
L power:GNDD #PWR0120
U 1 1 63AE91CC
P 7450 6150
F 0 "#PWR0120" H 7450 5900 50  0001 C CNN
F 1 "GNDD" H 7454 5995 50  0000 C CNN
F 2 "" H 7450 6150 50  0001 C CNN
F 3 "" H 7450 6150 50  0001 C CNN
	1    7450 6150
	1    0    0    -1  
$EndComp
Wire Wire Line
	7450 6150 7450 6000
Wire Wire Line
	7450 5050 7450 5200
Wire Wire Line
	7600 5050 7450 5050
Text GLabel 7300 5600 0    50   Input ~ 0
ANLDR
Wire Wire Line
	7300 5600 7450 5600
Connection ~ 7450 5600
Wire Wire Line
	7450 5600 7450 5700
Text GLabel 2100 4050 2    50   Input ~ 0
ANLDR
Wire Wire Line
	2100 4050 1950 4050
Text GLabel 8400 6150 0    50   Input ~ 0
CHRG
Text GLabel 8400 6250 0    50   Input ~ 0
STDBY
Text GLabel 8400 6350 0    50   Input ~ 0
WIFI
Wire Wire Line
	8400 6150 8500 6150
Wire Wire Line
	8400 6250 8700 6250
$Comp
L Device:R R20
U 1 1 63BBC210
P 8650 6350
F 0 "R20" V 8550 6250 50  0000 L CNN
F 1 "1K" V 8550 6400 50  0000 L CNN
F 2 "Resistor_SMD:R_0201_0603Metric_Pad0.64x0.40mm_HandSolder" V 8580 6350 50  0001 C CNN
F 3 "~" H 8650 6350 50  0001 C CNN
	1    8650 6350
	0    1    -1   0   
$EndComp
Wire Wire Line
	8500 6350 8400 6350
Wire Wire Line
	8800 6350 8900 6350
Text GLabel 8300 5550 0    50   Input ~ 0
5VA
$Comp
L Connector_Generic:Conn_02x02_Odd_Even J1
U 1 1 63C20CAC
P 6800 3950
F 0 "J1" H 6850 4167 50  0000 C CNN
F 1 "Conn_02x02_Odd_Even" H 6850 4076 50  0000 C CNN
F 2 "Connector_Molex:Molex_Nano-Fit_105310-xx04_2x02_P2.50mm_Vertical" H 6800 3950 50  0001 C CNN
F 3 "~" H 6800 3950 50  0001 C CNN
	1    6800 3950
	1    0    0    -1  
$EndComp
Text GLabel 6450 3950 0    50   Input ~ 0
TX
Wire Wire Line
	6450 3950 6600 3950
Text GLabel 6450 4050 0    50   Input ~ 0
RX
Wire Wire Line
	6450 4050 6600 4050
Text GLabel 7250 3950 2    50   Input ~ 0
BAT1+
Wire Wire Line
	7250 3950 7100 3950
$Comp
L power:GNDD #PWR0121
U 1 1 63C3CCF4
P 7250 4200
F 0 "#PWR0121" H 7250 3950 50  0001 C CNN
F 1 "GNDD" H 7254 4045 50  0000 C CNN
F 2 "" H 7250 4200 50  0001 C CNN
F 3 "" H 7250 4200 50  0001 C CNN
	1    7250 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	7250 4200 7250 4050
Wire Wire Line
	7250 4050 7100 4050
$Comp
L Device:LED D7
U 1 1 63CE83C1
P 8700 5850
F 0 "D7" H 8900 5750 50  0000 R CNN
F 1 "LED" H 8700 5750 50  0000 R CNN
F 2 "Resistor_SMD:R_0805_2012Metric" H 8700 5850 50  0001 C CNN
F 3 "~" H 8700 5850 50  0001 C CNN
	1    8700 5850
	0    -1   -1   0   
$EndComp
Wire Wire Line
	8700 6000 8700 6250
Wire Wire Line
	8700 5550 8700 5700
Wire Wire Line
	8300 5550 8500 5550
$Comp
L Device:LED D6
U 1 1 63D3D92A
P 8500 5850
F 0 "D6" H 8700 5750 50  0000 R CNN
F 1 "LED" H 8500 5750 50  0000 R CNN
F 2 "Resistor_SMD:R_0805_2012Metric" H 8500 5850 50  0001 C CNN
F 3 "~" H 8500 5850 50  0001 C CNN
	1    8500 5850
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D8
U 1 1 63D3DE9D
P 8900 5850
F 0 "D8" H 9100 5750 50  0000 R CNN
F 1 "LED" H 8900 5750 50  0000 R CNN
F 2 "Resistor_SMD:R_0805_2012Metric" H 8900 5850 50  0001 C CNN
F 3 "~" H 8900 5850 50  0001 C CNN
	1    8900 5850
	0    -1   -1   0   
$EndComp
Wire Wire Line
	8900 6000 8900 6350
Wire Wire Line
	8500 6000 8500 6150
Wire Wire Line
	8500 5700 8500 5550
Connection ~ 8500 5550
Wire Wire Line
	8500 5550 8700 5550
Wire Wire Line
	8900 5700 8900 5550
Wire Wire Line
	8900 5550 8700 5550
Connection ~ 8700 5550
Connection ~ 1850 4850
Wire Wire Line
	1850 4850 2050 4850
Connection ~ 1850 6000
Wire Wire Line
	1850 6000 2050 6000
Wire Wire Line
	1000 4850 1850 4850
Wire Wire Line
	1000 6000 1850 6000
Wire Wire Line
	1000 6700 1450 6700
Wire Wire Line
	4600 6700 4750 6700
Wire Wire Line
	4600 6800 4600 6700
$Comp
L power:GNDD #PWR?
U 1 1 647C6A03
P 4600 6800
AR Path="/647C6A03" Ref="#PWR?"  Part="1" 
AR Path="/633CFED4/647C6A03" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 4600 6550 50  0001 C CNN
F 1 "GNDD" H 4604 6645 50  0000 C CNN
F 2 "" H 4600 6800 50  0001 C CNN
F 3 "" H 4600 6800 50  0001 C CNN
	1    4600 6800
	1    0    0    -1  
$EndComp
Wire Wire Line
	5700 6800 5550 6800
Wire Wire Line
	5700 6700 5550 6700
Wire Wire Line
	5700 6600 5550 6600
Wire Wire Line
	5700 6500 5550 6500
Wire Wire Line
	5700 6400 5550 6400
Wire Wire Line
	5700 6300 5550 6300
Wire Wire Line
	5700 6200 5550 6200
Wire Wire Line
	5700 6100 5550 6100
Text GLabel 5700 6800 2    50   Input ~ 0
DRIVER4B
Text GLabel 5700 6700 2    50   Input ~ 0
DRIVER3B
Text GLabel 5700 6600 2    50   Input ~ 0
DRIVER2B
Text GLabel 5700 6500 2    50   Input ~ 0
DRIVER1B
Text GLabel 5700 6400 2    50   Input ~ 0
DRIVER4A
Text GLabel 5700 6300 2    50   Input ~ 0
DRIVER3A
Text GLabel 5700 6200 2    50   Input ~ 0
DRIVER2A
Text GLabel 5700 6100 2    50   Input ~ 0
DRIVER1A
Text GLabel 4600 6400 0    50   Input ~ 0
3.3VA
Wire Wire Line
	4750 5800 5150 5800
Text GLabel 4750 5800 0    50   Input ~ 0
3.3VA
Wire Wire Line
	5150 7300 5150 7200
$Comp
L power:GNDD #PWR?
U 1 1 647C6A1D
P 5150 7300
AR Path="/647C6A1D" Ref="#PWR?"  Part="1" 
AR Path="/633CFED4/647C6A1D" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 5150 7050 50  0001 C CNN
F 1 "GNDD" H 5154 7145 50  0000 C CNN
F 2 "" H 5150 7300 50  0001 C CNN
F 3 "" H 5150 7300 50  0001 C CNN
	1    5150 7300
	1    0    0    -1  
$EndComp
Wire Wire Line
	5150 5900 5150 5800
Wire Wire Line
	4750 6400 4600 6400
Wire Wire Line
	4750 6600 4600 6600
Text GLabel 4600 6600 0    50   Input ~ 0
GPIO15
Wire Wire Line
	4750 6100 4600 6100
Text GLabel 4600 6100 0    50   Input ~ 0
GPIO13
Wire Wire Line
	4750 6300 4600 6300
Text GLabel 4600 6300 0    50   Input ~ 0
GPIO14
$Comp
L 74xx:74HC595 U?
U 1 1 647C6A2B
P 5150 6500
AR Path="/633CFED4/647C6A2B" Ref="U?"  Part="1" 
AR Path="/647C6A2B" Ref="U?"  Part="1" 
F 0 "U?" H 4900 7050 50  0000 C CNN
F 1 "74HC595" H 5350 7050 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm" H 5150 6500 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74hc595.pdf" H 5150 6500 50  0001 C CNN
	1    5150 6500
	1    0    0    -1  
$EndComp
Wire Wire Line
	2950 7150 3150 7150
Text GLabel 3150 7150 2    50   Input ~ 0
5VD
$Comp
L Connector:Conn_01x13_Female J?
U 1 1 647C6A33
P 2750 6650
AR Path="/633CFED4/647C6A33" Ref="J?"  Part="1" 
AR Path="/647C6A33" Ref="J?"  Part="1" 
F 0 "J?" H 2642 7435 50  0000 C CNN
F 1 "Conn_01x13_Female" H 2642 7344 50  0000 C CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x13_P2.00mm_Vertical" H 2750 6650 50  0001 C CNN
F 3 "~" H 2750 6650 50  0001 C CNN
	1    2750 6650
	-1   0    0    -1  
$EndComp
Wire Wire Line
	2950 7050 3150 7050
Wire Wire Line
	2950 6950 3150 6950
Text GLabel 3150 6950 2    50   Input ~ 0
GPIO4
Text GLabel 3150 7050 2    50   Input ~ 0
GPIO5
Wire Wire Line
	3050 6900 3050 6850
Wire Wire Line
	3350 6900 3050 6900
Wire Wire Line
	3350 6850 3350 6900
Wire Wire Line
	3050 7250 2950 7250
Wire Wire Line
	3050 7350 3050 7250
$Comp
L power:GNDD #PWR?
U 1 1 647C6A42
P 3050 7350
AR Path="/647C6A42" Ref="#PWR?"  Part="1" 
AR Path="/633CFED4/647C6A42" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 3050 7100 50  0001 C CNN
F 1 "GNDD" H 3054 7195 50  0000 C CNN
F 2 "" H 3050 7350 50  0001 C CNN
F 3 "" H 3050 7350 50  0001 C CNN
	1    3050 7350
	1    0    0    -1  
$EndComp
Wire Wire Line
	3050 6850 3150 6850
Wire Wire Line
	3450 6850 3350 6850
Connection ~ 3050 6850
Wire Wire Line
	2950 6850 3050 6850
Text GLabel 3450 6850 2    50   Input ~ 0
DCDC
Text GLabel 3150 6850 2    50   Input ~ 0
5VA
Wire Wire Line
	3150 6350 2950 6350
Wire Wire Line
	3150 6250 2950 6250
Wire Wire Line
	3150 6150 2950 6150
Wire Wire Line
	3150 6050 2950 6050
Text GLabel 3150 6350 2    50   Input ~ 0
DRIVER4A
Text GLabel 3150 6250 2    50   Input ~ 0
DRIVER3A
Text GLabel 3150 6150 2    50   Input ~ 0
DRIVER2A
Text GLabel 3150 6050 2    50   Input ~ 0
DRIVER1A
Wire Wire Line
	3150 6750 2950 6750
Wire Wire Line
	3150 6650 2950 6650
Wire Wire Line
	3150 6550 2950 6550
Wire Wire Line
	3150 6450 2950 6450
Text GLabel 3150 6750 2    50   Input ~ 0
DRIVER4B
Text GLabel 3150 6650 2    50   Input ~ 0
DRIVER3B
Text GLabel 3150 6550 2    50   Input ~ 0
DRIVER2B
Text GLabel 3150 6450 2    50   Input ~ 0
DRIVER1B
$EndSCHEMATC
