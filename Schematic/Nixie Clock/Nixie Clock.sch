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
L Connector:USB_C_Plug_USB2.0 P?
U 1 1 631A35D4
P 1450 1600
F 0 "P?" H 1557 2467 50  0000 C CNN
F 1 "USB_C_Plug_USB2.0" H 1557 2376 50  0001 C CNN
F 2 "" H 1600 1600 50  0001 C CNN
F 3 "https://www.usb.org/sites/default/files/documents/usb_type-c.zip" H 1600 1600 50  0001 C CNN
	1    1450 1600
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 631A59F0
P 15400 3400
F 0 "R?" H 15470 3446 50  0000 L CNN
F 1 "R" H 15470 3355 50  0000 L CNN
F 2 "" V 15330 3400 50  0001 C CNN
F 3 "~" H 15400 3400 50  0001 C CNN
	1    15400 3400
	1    0    0    -1  
$EndComp
$Comp
L Piezo:DiscPiezo P?
U 1 1 631F4A12
P 14950 3400
F 0 "P?" H 15028 3446 50  0000 L CNN
F 1 "DiscPiezo" H 15028 3355 50  0000 L CNN
F 2 "" H 15050 3450 50  0001 C CNN
F 3 "" H 15050 3450 50  0001 C CNN
	1    14950 3400
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 631F57CF
P 14500 3350
F 0 "C?" H 14615 3396 50  0000 L CNN
F 1 "C" H 14615 3305 50  0000 L CNN
F 2 "" H 14538 3200 50  0001 C CNN
F 3 "~" H 14500 3350 50  0001 C CNN
	1    14500 3350
	1    0    0    -1  
$EndComp
$Comp
L Diode:BZD27Cxx D?
U 1 1 631F6138
P 14600 4050
F 0 "D?" H 14600 4267 50  0000 C CNN
F 1 "BZD27Cxx" H 14600 4176 50  0000 C CNN
F 2 "Diode_SMD:D_SMF" H 14600 3875 50  0001 C CNN
F 3 "https://www.vishay.com/docs/85153/bzd27series.pdf" H 14600 4050 50  0001 C CNN
	1    14600 4050
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 631F7E3E
P 15450 4050
F 0 "#PWR?" H 15450 3800 50  0001 C CNN
F 1 "GNDD" H 15454 3895 50  0000 C CNN
F 2 "" H 15450 4050 50  0001 C CNN
F 3 "" H 15450 4050 50  0001 C CNN
	1    15450 4050
	1    0    0    -1  
$EndComp
$Comp
L Device:Ferrite_Bead FB?
U 1 1 631F862B
P 15900 4050
F 0 "FB?" H 16037 4096 50  0000 L CNN
F 1 "Ferrite_Bead" H 16037 4005 50  0000 L CNN
F 2 "" V 15830 4050 50  0001 C CNN
F 3 "~" H 15900 4050 50  0001 C CNN
	1    15900 4050
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR?
U 1 1 631F993D
P 15200 4050
F 0 "#PWR?" H 15200 3800 50  0001 C CNN
F 1 "GNDA" H 15205 3877 50  0000 C CNN
F 2 "" H 15200 4050 50  0001 C CNN
F 3 "" H 15200 4050 50  0001 C CNN
	1    15200 4050
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3VA #PWR?
U 1 1 631FA4B1
P 16200 3350
F 0 "#PWR?" H 16200 3200 50  0001 C CNN
F 1 "+3.3VA" H 16215 3523 50  0000 C CNN
F 2 "" H 16200 3350 50  0001 C CNN
F 3 "" H 16200 3350 50  0001 C CNN
	1    16200 3350
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT:BC548 Q?
U 1 1 631FD488
P 15750 2400
F 0 "Q?" H 15941 2446 50  0000 L CNN
F 1 "BC548" H 15941 2355 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 15950 2325 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/BC550-D.pdf" H 15750 2400 50  0001 L CNN
	1    15750 2400
	1    0    0    -1  
$EndComp
$Comp
L Battery_Management:TP4056 U?
U 1 1 631FE546
P 14500 2350
F 0 "U?" H 14500 2931 50  0000 C CNN
F 1 "TP4056" H 14500 2840 50  0000 C CNN
F 2 "" H 14350 2700 50  0001 C CNN
F 3 "" H 14350 2700 50  0001 C CNN
	1    14500 2350
	1    0    0    -1  
$EndComp
$Comp
L Battery_Management:DW01 U?
U 1 1 631FF433
P 13550 2350
F 0 "U?" H 13550 2931 50  0000 C CNN
F 1 "DW01" H 13550 2840 50  0000 C CNN
F 2 "" H 13600 2700 50  0001 C CNN
F 3 "" H 13600 2700 50  0001 C CNN
	1    13550 2350
	1    0    0    -1  
$EndComp
$Comp
L Battery_Management:AM8205 U?
U 1 1 631FFA11
P 12800 2400
F 0 "U?" H 12800 2815 50  0000 C CNN
F 1 "AM8205" H 12800 2724 50  0000 C CNN
F 2 "" H 12650 2700 50  0001 C CNN
F 3 "" H 12650 2700 50  0001 C CNN
	1    12800 2400
	1    0    0    -1  
$EndComp
$Comp
L Timer:NE555D U?
U 1 1 632007F4
P 12850 3100
F 0 "U?" H 12850 3681 50  0000 C CNN
F 1 "NE555D" H 12850 3590 50  0000 C CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 13700 2700 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/ne555.pdf" H 13700 2700 50  0001 C CNN
	1    12850 3100
	1    0    0    -1  
$EndComp
$Comp
L Transistor_FET:BUZ11 Q?
U 1 1 63202184
P 13650 3050
F 0 "Q?" H 13855 3096 50  0000 L CNN
F 1 "BUZ11" H 13855 3005 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 13900 2975 50  0001 L CIN
F 3 "https://media.digikey.com/pdf/Data%20Sheets/Fairchild%20PDFs/BUZ11.pdf" H 13650 3050 50  0001 L CNN
	1    13650 3050
	1    0    0    -1  
$EndComp
$Comp
L Device:Transformer_1P_1S T?
U 1 1 632032FA
P 13550 3850
F 0 "T?" H 13550 4231 50  0000 C CNN
F 1 "Transformer_1P_1S" H 13550 4140 50  0000 C CNN
F 2 "Transformer_SMD:Transformer_CEEH54_Nixie" H 13550 3850 50  0001 C CNN
F 3 "~" H 13550 3850 50  0001 C CNN
	1    13550 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	1450 2500 1450 2650
Wire Wire Line
	1450 2650 1300 2650
Wire Wire Line
	1150 2650 1150 2500
$Comp
L Jumper:SolderJumper_2_Open JP?
U 1 1 63204C45
P 16200 1850
F 0 "JP?" H 16200 2055 50  0000 C CNN
F 1 "SolderJumper_2_Open" H 16200 1964 50  0000 C CNN
F 2 "" H 16200 1850 50  0001 C CNN
F 3 "~" H 16200 1850 50  0001 C CNN
	1    16200 1850
	1    0    0    -1  
$EndComp
$Comp
L Regulator_Linear:AMS1117-3.3 U?
U 1 1 6320B133
P 10100 5650
F 0 "U?" H 10100 5892 50  0000 C CNN
F 1 "AMS1117-3.3" H 10100 5801 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-223-3_TabPin2" H 10100 5850 50  0001 C CNN
F 3 "http://www.advanced-monolithic.com/pdf/ds1117.pdf" H 10200 5400 50  0001 C CNN
	1    10100 5650
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C?
U 1 1 6320D881
P 14200 3350
F 0 "C?" H 14318 3396 50  0000 L CNN
F 1 "CP" H 14318 3305 50  0000 L CNN
F 2 "" H 14238 3200 50  0001 C CNN
F 3 "~" H 14200 3350 50  0001 C CNN
	1    14200 3350
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT:BC547 Q?
U 1 1 6320F34D
P 16400 2400
F 0 "Q?" H 16591 2446 50  0000 L CNN
F 1 "BC547" H 16591 2355 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 16600 2325 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/BC550-D.pdf" H 16400 2400 50  0001 L CNN
	1    16400 2400
	1    0    0    -1  
$EndComp
$Comp
L Device:R_POT RV?
U 1 1 63211C5E
P 15200 3000
F 0 "RV?" H 15130 2954 50  0000 R CNN
F 1 "R_POT" H 15130 3045 50  0000 R CNN
F 2 "" H 15200 3000 50  0001 C CNN
F 3 "~" H 15200 3000 50  0001 C CNN
	1    15200 3000
	-1   0    0    1   
$EndComp
$Comp
L Device:R_PHOTO R?
U 1 1 63213A51
P 15650 3150
F 0 "R?" H 15720 3196 50  0000 L CNN
F 1 "R_PHOTO" H 15720 3105 50  0000 L CNN
F 2 "" V 15700 2900 50  0001 L CNN
F 3 "~" H 15650 3100 50  0001 C CNN
	1    15650 3150
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 63218CDA
P 9600 5900
F 0 "C?" H 9715 5946 50  0000 L CNN
F 1 "C" H 9715 5855 50  0000 L CNN
F 2 "" H 9638 5750 50  0001 C CNN
F 3 "~" H 9600 5900 50  0001 C CNN
	1    9600 5900
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C?
U 1 1 63218CE0
P 10600 5900
F 0 "C?" H 10718 5946 50  0000 L CNN
F 1 "CP" H 10718 5855 50  0000 L CNN
F 2 "" H 10638 5750 50  0001 C CNN
F 3 "~" H 10600 5900 50  0001 C CNN
	1    10600 5900
	1    0    0    -1  
$EndComp
Wire Wire Line
	10600 5750 10600 5650
Wire Wire Line
	10600 5650 10400 5650
Wire Wire Line
	9800 5650 9600 5650
Wire Wire Line
	9600 5650 9600 5750
$Comp
L power:GNDD #PWR?
U 1 1 6321C7DC
P 10100 6200
F 0 "#PWR?" H 10100 5950 50  0001 C CNN
F 1 "GNDD" H 10104 6045 50  0000 C CNN
F 2 "" H 10100 6200 50  0001 C CNN
F 3 "" H 10100 6200 50  0001 C CNN
	1    10100 6200
	1    0    0    -1  
$EndComp
Wire Wire Line
	10100 6200 10100 6150
Wire Wire Line
	10600 6050 10600 6150
Wire Wire Line
	10600 6150 10100 6150
Connection ~ 10100 6150
Wire Wire Line
	10100 6150 10100 5950
Wire Wire Line
	10100 6150 9600 6150
Wire Wire Line
	9600 6150 9600 6050
$Comp
L MCU_Module:DC-DC U?
U 1 1 6321E4EE
P 17400 2950
F 0 "U?" H 17400 3275 50  0000 C CNN
F 1 "DC-DC" H 17400 3184 50  0000 C CNN
F 2 "" H 17400 2950 50  0001 C CNN
F 3 "" H 17400 2950 50  0001 C CNN
	1    17400 2950
	1    0    0    -1  
$EndComp
Text GLabel 9450 5650 0    50   Input ~ 0
5VA
Wire Wire Line
	9450 5650 9600 5650
Connection ~ 9600 5650
Text GLabel 10750 5650 2    50   Input ~ 0
3.3VR
Wire Wire Line
	10750 5650 10600 5650
Connection ~ 10600 5650
$Comp
L Connector:TestPoint TP?
U 1 1 6322A85F
P 10600 5450
F 0 "TP?" H 10658 5568 50  0000 L CNN
F 1 "3.3V" H 10658 5477 50  0000 L CNN
F 2 "" H 10800 5450 50  0001 C CNN
F 3 "~" H 10800 5450 50  0001 C CNN
	1    10600 5450
	1    0    0    -1  
$EndComp
Wire Wire Line
	10600 5450 10600 5650
Text GLabel 5650 7250 0    50   Input ~ 0
3.3VR
Text GLabel 5650 7350 0    50   Input ~ 0
RX
Text GLabel 6450 7250 2    50   Input ~ 0
TX
Text GLabel 6450 7350 2    50   Input ~ 0
GND
$Comp
L Connector_Generic:Conn_02x03_Counter_Clockwise J?
U 1 1 6322E71D
P 6000 7350
F 0 "J?" H 6050 7667 50  0000 C CNN
F 1 "Conn_02x03_Counter_Clockwise" H 6050 7576 50  0000 C CNN
F 2 "" H 6000 7350 50  0001 C CNN
F 3 "~" H 6000 7350 50  0001 C CNN
	1    6000 7350
	1    0    0    -1  
$EndComp
Text GLabel 5650 7450 0    50   Input ~ 0
DTR
Text GLabel 6450 7450 2    50   Input ~ 0
GND
Wire Wire Line
	6450 7450 6300 7450
Wire Wire Line
	6300 7350 6450 7350
Wire Wire Line
	6450 7250 6300 7250
Wire Wire Line
	5800 7250 5650 7250
Wire Wire Line
	5650 7350 5800 7350
Wire Wire Line
	5800 7450 5650 7450
$Comp
L Jumper:SolderJumper_2_Open JP?
U 1 1 63235E13
P 2550 4150
F 0 "JP?" V 2550 4218 50  0000 L CNN
F 1 "SolderJumper_2_Open" H 2550 4264 50  0001 C CNN
F 2 "" H 2550 4150 50  0001 C CNN
F 3 "~" H 2550 4150 50  0001 C CNN
	1    2550 4150
	0    1    1    0   
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 63237CCB
P 1700 4850
F 0 "#PWR?" H 1700 4600 50  0001 C CNN
F 1 "GNDD" H 1704 4695 50  0000 C CNN
F 2 "" H 1700 4850 50  0001 C CNN
F 3 "" H 1700 4850 50  0001 C CNN
	1    1700 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	1700 4850 1700 4750
Text GLabel 1050 4100 0    50   Input ~ 0
TX
Wire Wire Line
	1050 4100 1200 4100
Text GLabel 1050 4200 0    50   Input ~ 0
RX
Wire Wire Line
	1050 4200 1200 4200
Text GLabel 1850 3200 2    50   Input ~ 0
3.3VR
Wire Wire Line
	1700 3200 1850 3200
Wire Wire Line
	1700 3200 1700 3400
$Comp
L RF_Module:ESP-WROOM-02 U?
U 1 1 6324C251
P 1700 4000
F 0 "U?" H 1350 3450 50  0000 C CNN
F 1 "ESP-WROOM-02" H 2100 3450 50  0000 C CNN
F 2 "RF_Module:ESP-12E" H 2300 3450 50  0001 C CNN
F 3 "https://www.espressif.com/sites/default/files/documentation/0c-esp-wroom-02_datasheet_en.pdf" H 1750 5500 50  0001 C CNN
	1    1700 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	2550 4000 2550 3600
Wire Wire Line
	2550 3600 2200 3600
Wire Wire Line
	2550 4300 2550 4750
Wire Wire Line
	2550 4750 1700 4750
Connection ~ 1700 4750
Wire Wire Line
	1700 4750 1700 4600
$Comp
L power:GNDA #PWR?
U 1 1 6325976E
P 1300 2750
F 0 "#PWR?" H 1300 2500 50  0001 C CNN
F 1 "GNDA" H 1305 2577 50  0000 C CNN
F 2 "" H 1300 2750 50  0001 C CNN
F 3 "" H 1300 2750 50  0001 C CNN
	1    1300 2750
	1    0    0    -1  
$EndComp
Wire Wire Line
	1300 2750 1300 2650
Connection ~ 1300 2650
Wire Wire Line
	1300 2650 1150 2650
Text GLabel 2200 1000 2    50   Input ~ 0
VIN
Wire Wire Line
	2200 1000 2050 1000
Text GLabel 1050 3600 0    50   Input ~ 0
DTR
Wire Wire Line
	1200 3600 1050 3600
Text Notes 2800 4250 0    50   ~ 0
NF - Porta Gravação\nNA - Porta Uso
$Comp
L Device:R R?
U 1 1 6325D834
P 1750 5600
F 0 "R?" H 1820 5646 50  0000 L CNN
F 1 "1M" H 1820 5555 50  0000 L CNN
F 2 "" V 1680 5600 50  0001 C CNN
F 3 "~" H 1750 5600 50  0001 C CNN
	1    1750 5600
	1    0    0    -1  
$EndComp
$Comp
L Piezo:DiscPiezo P?
U 1 1 6325D83A
P 1300 5600
F 0 "P?" H 1378 5600 50  0000 L CNN
F 1 "DiscPiezo" H 1378 5555 50  0001 L CNN
F 2 "" H 1400 5650 50  0001 C CNN
F 3 "" H 1400 5650 50  0001 C CNN
	1    1300 5600
	1    0    0    -1  
$EndComp
Wire Wire Line
	1300 5350 1300 5250
Wire Wire Line
	1300 5250 1750 5250
Wire Wire Line
	1750 5250 1750 5450
Wire Wire Line
	1300 5850 1300 5950
Wire Wire Line
	1300 5950 1750 5950
Wire Wire Line
	1750 5950 1750 5750
$Comp
L power:GNDD #PWR?
U 1 1 63260200
P 1750 6050
F 0 "#PWR?" H 1750 5800 50  0001 C CNN
F 1 "GNDD" H 1754 5895 50  0000 C CNN
F 2 "" H 1750 6050 50  0001 C CNN
F 3 "" H 1750 6050 50  0001 C CNN
	1    1750 6050
	1    0    0    -1  
$EndComp
Wire Wire Line
	1750 6050 1750 5950
Connection ~ 1750 5950
Text GLabel 2350 5250 2    50   Input ~ 0
WAKE
Connection ~ 1750 5250
Wire Wire Line
	1750 5250 2350 5250
$Comp
L Device:R R?
U 1 1 6326A514
P 1750 6750
F 0 "R?" H 1820 6796 50  0000 L CNN
F 1 "1M" H 1820 6705 50  0000 L CNN
F 2 "" V 1680 6750 50  0001 C CNN
F 3 "~" H 1750 6750 50  0001 C CNN
	1    1750 6750
	1    0    0    -1  
$EndComp
$Comp
L Piezo:DiscPiezo P?
U 1 1 6326A51A
P 1300 6750
F 0 "P?" H 1378 6750 50  0000 L CNN
F 1 "DiscPiezo" H 1378 6705 50  0001 L CNN
F 2 "" H 1400 6800 50  0001 C CNN
F 3 "" H 1400 6800 50  0001 C CNN
	1    1300 6750
	1    0    0    -1  
$EndComp
Wire Wire Line
	1300 6500 1300 6400
Wire Wire Line
	1300 6400 1750 6400
Wire Wire Line
	1750 6400 1750 6600
Wire Wire Line
	1300 7000 1300 7100
Wire Wire Line
	1300 7100 1750 7100
Wire Wire Line
	1750 7100 1750 6900
$Comp
L power:GNDD #PWR?
U 1 1 6326A526
P 1750 7200
F 0 "#PWR?" H 1750 6950 50  0001 C CNN
F 1 "GNDD" H 1754 7045 50  0000 C CNN
F 2 "" H 1750 7200 50  0001 C CNN
F 3 "" H 1750 7200 50  0001 C CNN
	1    1750 7200
	1    0    0    -1  
$EndComp
Wire Wire Line
	1750 7200 1750 7100
Connection ~ 1750 7100
Text GLabel 2350 6400 2    50   Input ~ 0
MODE
Connection ~ 1750 6400
Wire Wire Line
	1750 6400 2350 6400
$Comp
L Diode:DZ2S056X0L D?
U 1 1 63277760
P 4650 1600
F 0 "D?" V 4604 1680 50  0000 L CNN
F 1 "DZ2S056X0L" H 4400 1500 50  0000 L CNN
F 2 "Diode_SMD:D_SOD-523" H 4650 1425 50  0001 C CNN
F 3 "https://industrial.panasonic.com/content/data/SC/ds/ds4/DZ2S05600L_E.pdf" H 4650 1600 50  0001 C CNN
	1    4650 1600
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 6327E285
P 3000 1300
F 0 "R?" H 3070 1346 50  0000 L CNN
F 1 "2K2" H 3070 1255 50  0000 L CNN
F 2 "" V 2930 1300 50  0001 C CNN
F 3 "~" H 3000 1300 50  0001 C CNN
	1    3000 1300
	-1   0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 6327F12B
P 3900 2150
F 0 "R?" H 3970 2196 50  0000 L CNN
F 1 "4K7" H 3970 2105 50  0000 L CNN
F 2 "" V 3830 2150 50  0001 C CNN
F 3 "~" H 3900 2150 50  0001 C CNN
	1    3900 2150
	-1   0    0    -1  
$EndComp
$Comp
L Device:Ferrite_Bead FB?
U 1 1 63280EB6
P 4300 2450
F 0 "FB?" V 4482 2450 50  0000 C CNN
F 1 "Ferrite_Bead" H 4437 2405 50  0001 L CNN
F 2 "" V 4230 2450 50  0001 C CNN
F 3 "~" H 4300 2450 50  0001 C CNN
	1    4300 2450
	0    -1   -1   0   
$EndComp
$Comp
L Device:C C?
U 1 1 632821DA
P 4950 1600
F 0 "C?" H 5065 1646 50  0000 L CNN
F 1 "47uF" H 5065 1555 50  0000 L CNN
F 2 "" H 4988 1450 50  0001 C CNN
F 3 "~" H 4950 1600 50  0001 C CNN
	1    4950 1600
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 63285428
P 3300 1600
F 0 "R?" V 3100 1550 50  0000 L CNN
F 1 "4K7" V 3200 1500 50  0000 L CNN
F 2 "" V 3230 1600 50  0001 C CNN
F 3 "~" H 3300 1600 50  0001 C CNN
	1    3300 1600
	0    1    1    0   
$EndComp
$Comp
L Transistor_FET:2N7000 Q?
U 1 1 6328675F
P 4300 1100
F 0 "Q?" V 4642 1100 50  0000 C CNN
F 1 "2N7000" V 4551 1100 50  0000 C CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 4500 1025 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/NDS7002A-D.PDF" H 4300 1100 50  0001 L CNN
	1    4300 1100
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3150 1600 3000 1600
Wire Wire Line
	3000 1600 3000 1450
$Comp
L Transistor_BJT:BC548 Q?
U 1 1 6328BA5B
P 3800 1600
F 0 "Q?" H 3991 1646 50  0000 L CNN
F 1 "BC548" H 3991 1555 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 4000 1525 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/BC550-D.pdf" H 3800 1600 50  0001 L CNN
	1    3800 1600
	1    0    0    -1  
$EndComp
Wire Wire Line
	3900 1800 3900 1900
Wire Wire Line
	3600 1600 3450 1600
Wire Wire Line
	3900 1400 3900 1000
Wire Wire Line
	3900 1000 3000 1000
Wire Wire Line
	3000 1000 3000 1150
Wire Wire Line
	4100 1000 3900 1000
Connection ~ 3900 1000
Wire Wire Line
	4300 1300 4300 1900
Wire Wire Line
	4300 1900 3900 1900
Connection ~ 3900 1900
Wire Wire Line
	3900 1900 3900 2000
$Comp
L power:GNDA #PWR?
U 1 1 6329F4CB
P 3900 2550
F 0 "#PWR?" H 3900 2300 50  0001 C CNN
F 1 "GNDA" H 3905 2377 50  0000 C CNN
F 2 "" H 3900 2550 50  0001 C CNN
F 3 "" H 3900 2550 50  0001 C CNN
	1    3900 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	3900 2550 3900 2450
Wire Wire Line
	4150 2450 3900 2450
Wire Wire Line
	3900 2450 3900 2300
Connection ~ 3900 2450
Wire Wire Line
	4650 1450 4650 1000
Wire Wire Line
	4650 1000 4500 1000
Wire Wire Line
	4950 1450 4950 1000
Wire Wire Line
	4950 1000 4650 1000
Connection ~ 4650 1000
Wire Wire Line
	4950 1750 4950 2450
Wire Wire Line
	4950 2450 4450 2450
$Comp
L power:GNDD #PWR?
U 1 1 632AD80B
P 4950 2550
F 0 "#PWR?" H 4950 2300 50  0001 C CNN
F 1 "GNDD" H 4954 2395 50  0000 C CNN
F 2 "" H 4950 2550 50  0001 C CNN
F 3 "" H 4950 2550 50  0001 C CNN
	1    4950 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	4950 2550 4950 2450
Connection ~ 4950 2450
$Comp
L power:GNDD #PWR?
U 1 1 632B100D
P 4650 1850
F 0 "#PWR?" H 4650 1600 50  0001 C CNN
F 1 "GNDD" H 4654 1695 50  0000 C CNN
F 2 "" H 4650 1850 50  0001 C CNN
F 3 "" H 4650 1850 50  0001 C CNN
	1    4650 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	4650 1850 4650 1750
Text GLabel 2850 1000 0    50   Input ~ 0
VIN
Wire Wire Line
	2850 1000 3000 1000
Connection ~ 3000 1000
Text GLabel 5100 1000 2    50   Input ~ 0
5VA
Wire Wire Line
	5100 1000 4950 1000
Connection ~ 4950 1000
$Comp
L Diode:DZ2S036X0L D?
U 1 1 632DB553
P 5950 1200
F 0 "D?" V 5904 1280 50  0000 L CNN
F 1 "DZ2S036X0L" H 5750 1100 50  0000 L CNN
F 2 "Diode_SMD:D_SOD-523" H 5950 1025 50  0001 C CNN
F 3 "https://industrial.panasonic.com/content/data/SC/ds/ds4/DZ2S03600L_E.pdf" H 5950 1200 50  0001 C CNN
	1    5950 1200
	0    1    1    0   
$EndComp
Text GLabel 5800 950  0    50   Input ~ 0
3.3VR
Wire Wire Line
	5800 950  5950 950 
Wire Wire Line
	5950 1050 5950 950 
$Comp
L Device:R R?
U 1 1 632E3861
P 5950 2150
F 0 "R?" H 6020 2196 50  0000 L CNN
F 1 "1K" H 6020 2105 50  0000 L CNN
F 2 "" V 5880 2150 50  0001 C CNN
F 3 "~" H 5950 2150 50  0001 C CNN
	1    5950 2150
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 632E4B2B
P 6400 1200
F 0 "R?" H 6470 1246 50  0000 L CNN
F 1 "1K" H 6470 1155 50  0000 L CNN
F 2 "" V 6330 1200 50  0001 C CNN
F 3 "~" H 6400 1200 50  0001 C CNN
	1    6400 1200
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_SCR_AGK D?
U 1 1 632E587D
P 6400 1700
F 0 "D?" H 6488 1746 50  0000 L CNN
F 1 "Q_SCR_AGK" H 6488 1655 50  0000 L CNN
F 2 "" V 6400 1700 50  0001 C CNN
F 3 "~" V 6400 1700 50  0001 C CNN
	1    6400 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	6250 1800 5950 1800
Wire Wire Line
	5950 1800 5950 1350
Wire Wire Line
	5950 2000 5950 1800
Connection ~ 5950 1800
Wire Wire Line
	6400 1550 6400 1450
Wire Wire Line
	6400 1050 6400 950 
Wire Wire Line
	6400 950  5950 950 
Connection ~ 5950 950 
$Comp
L power:GNDD #PWR?
U 1 1 632EE6FD
P 5950 2500
F 0 "#PWR?" H 5950 2250 50  0001 C CNN
F 1 "GNDD" H 5954 2345 50  0000 C CNN
F 2 "" H 5950 2500 50  0001 C CNN
F 3 "" H 5950 2500 50  0001 C CNN
	1    5950 2500
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 632F03A6
P 6400 2500
F 0 "#PWR?" H 6400 2250 50  0001 C CNN
F 1 "GNDD" H 6404 2345 50  0000 C CNN
F 2 "" H 6400 2500 50  0001 C CNN
F 3 "" H 6400 2500 50  0001 C CNN
	1    6400 2500
	1    0    0    -1  
$EndComp
$Comp
L Transistor_FET:2N7002 Q?
U 1 1 632F2694
P 6950 1450
F 0 "Q?" H 7154 1496 50  0000 L CNN
F 1 "2N7002" H 7154 1405 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 7150 1375 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/NDS7002A-D.PDF" H 6950 1450 50  0001 L CNN
	1    6950 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	6750 1450 6400 1450
Connection ~ 6400 1450
Wire Wire Line
	6400 1450 6400 1350
Wire Wire Line
	7050 1650 7050 2150
Wire Wire Line
	7050 2150 6400 2150
Wire Wire Line
	6400 2150 6400 1850
Wire Wire Line
	5950 2300 5950 2500
Wire Wire Line
	6400 2500 6400 2150
Connection ~ 6400 2150
Wire Wire Line
	7050 1250 7050 1100
Wire Wire Line
	7050 1100 7500 1100
Wire Wire Line
	7500 1100 7500 1450
$Comp
L power:GNDD #PWR?
U 1 1 633070A7
P 7500 1450
F 0 "#PWR?" H 7500 1200 50  0001 C CNN
F 1 "GNDD" H 7504 1295 50  0000 C CNN
F 2 "" H 7500 1450 50  0001 C CNN
F 3 "" H 7500 1450 50  0001 C CNN
	1    7500 1450
	1    0    0    -1  
$EndComp
Text GLabel 6550 950  2    50   Input ~ 0
3.3VA
Wire Wire Line
	6550 950  6400 950 
Connection ~ 6400 950 
$Comp
L Diode:1N5819 D?
U 1 1 63310CC5
P 8700 950
F 0 "D?" H 8850 850 50  0000 C CNN
F 1 "1N5819" H 8600 850 50  0000 C CNN
F 2 "Diode_THT:D_DO-41_SOD81_P10.16mm_Horizontal" H 8700 775 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88525/1n5817.pdf" H 8700 950 50  0001 C CNN
	1    8700 950 
	-1   0    0    1   
$EndComp
$Comp
L Diode:1N5819 D?
U 1 1 63313CB7
P 8700 1150
F 0 "D?" H 8850 1000 50  0000 C CNN
F 1 "1N5819" H 8600 1000 50  0000 C CNN
F 2 "Diode_THT:D_DO-41_SOD81_P10.16mm_Horizontal" H 8700 975 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88525/1n5817.pdf" H 8700 1150 50  0001 C CNN
	1    8700 1150
	-1   0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 63315E74
P 9000 1450
F 0 "R?" H 9070 1496 50  0000 L CNN
F 1 "200K" H 9070 1405 50  0000 L CNN
F 2 "" V 8930 1450 50  0001 C CNN
F 3 "~" H 9000 1450 50  0001 C CNN
	1    9000 1450
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 633169CC
P 9700 1450
F 0 "R?" H 9770 1496 50  0000 L CNN
F 1 "1M" H 9770 1405 50  0000 L CNN
F 2 "" V 9630 1450 50  0001 C CNN
F 3 "~" H 9700 1450 50  0001 C CNN
	1    9700 1450
	-1   0    0    -1  
$EndComp
$Comp
L Transistor_BJT:BC548 Q?
U 1 1 63319F0D
P 8900 2450
F 0 "Q?" H 9091 2496 50  0000 L CNN
F 1 "BC548" H 9091 2405 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 9100 2375 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/BC550-D.pdf" H 8900 2450 50  0001 L CNN
	1    8900 2450
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT:BC548 Q?
U 1 1 6331BFF4
P 10100 2100
F 0 "Q?" H 10291 2146 50  0000 L CNN
F 1 "BC548" H 10291 2055 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 10300 2025 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/BC550-D.pdf" H 10100 2100 50  0001 L CNN
	1    10100 2100
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT:BC548 Q?
U 1 1 6331DC48
P 10200 1250
F 0 "Q?" V 10528 1250 50  0000 C CNN
F 1 "BC548" V 10437 1250 50  0000 C CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 10400 1175 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/BC550-D.pdf" H 10200 1250 50  0001 L CNN
	1    10200 1250
	0    -1   -1   0   
$EndComp
Wire Wire Line
	8850 1150 9000 1150
Wire Wire Line
	9000 1150 9000 1300
Wire Wire Line
	8850 950  9000 950 
Wire Wire Line
	9000 950  9000 1150
Connection ~ 9000 1150
Wire Wire Line
	9000 1150 9700 1150
Wire Wire Line
	9700 1300 9700 1150
Connection ~ 9700 1150
Wire Wire Line
	9700 1150 10000 1150
Wire Wire Line
	9700 1750 10200 1750
Wire Wire Line
	9700 1600 9700 1750
Wire Wire Line
	10200 1450 10200 1750
Wire Wire Line
	10200 1900 10200 1750
Connection ~ 10200 1750
Wire Wire Line
	8550 2450 8700 2450
$Comp
L Device:R R?
U 1 1 6334B3D1
P 8100 2750
F 0 "R?" H 8170 2796 50  0000 L CNN
F 1 "100R" H 8170 2705 50  0000 L CNN
F 2 "" V 8030 2750 50  0001 C CNN
F 3 "~" H 8100 2750 50  0001 C CNN
	1    8100 2750
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 6334BEB0
P 8100 3000
F 0 "#PWR?" H 8100 2750 50  0001 C CNN
F 1 "GNDD" H 8104 2845 50  0000 C CNN
F 2 "" H 8100 3000 50  0001 C CNN
F 3 "" H 8100 3000 50  0001 C CNN
	1    8100 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	8100 3000 8100 2900
$Comp
L power:GNDD #PWR?
U 1 1 6334F0F6
P 9000 2750
F 0 "#PWR?" H 9000 2500 50  0001 C CNN
F 1 "GNDD" H 9004 2595 50  0000 C CNN
F 2 "" H 9000 2750 50  0001 C CNN
F 3 "" H 9000 2750 50  0001 C CNN
	1    9000 2750
	1    0    0    -1  
$EndComp
Wire Wire Line
	9000 2750 9000 2650
$Comp
L power:GNDD #PWR?
U 1 1 633525A1
P 10200 2400
F 0 "#PWR?" H 10200 2150 50  0001 C CNN
F 1 "GNDD" H 10204 2245 50  0000 C CNN
F 2 "" H 10200 2400 50  0001 C CNN
F 3 "" H 10200 2400 50  0001 C CNN
	1    10200 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	10200 2400 10200 2300
Wire Wire Line
	8100 2600 8100 2450
Wire Wire Line
	8100 2450 8250 2450
$Comp
L Device:R R?
U 1 1 63347766
P 8400 2450
F 0 "R?" V 8600 2400 50  0000 L CNN
F 1 "1K" V 8500 2400 50  0000 L CNN
F 2 "" V 8330 2450 50  0001 C CNN
F 3 "~" H 8400 2450 50  0001 C CNN
	1    8400 2450
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R?
U 1 1 63316F3B
P 9450 2100
F 0 "R?" V 9650 2050 50  0000 L CNN
F 1 "1K" V 9550 2050 50  0000 L CNN
F 2 "" V 9380 2100 50  0001 C CNN
F 3 "~" H 9450 2100 50  0001 C CNN
	1    9450 2100
	0    -1   -1   0   
$EndComp
Text GLabel 8400 950  0    50   Input ~ 0
BAT1+
Wire Wire Line
	8550 950  8400 950 
Text GLabel 8400 1150 0    50   Input ~ 0
BAT2+
Wire Wire Line
	8550 1150 8400 1150
Text GLabel 7950 2450 0    50   Input ~ 0
5VA
Wire Wire Line
	7950 2450 8100 2450
Connection ~ 8100 2450
Wire Wire Line
	9000 1600 9000 2100
Wire Wire Line
	9600 2100 9900 2100
Wire Wire Line
	9300 2100 9000 2100
Connection ~ 9000 2100
Wire Wire Line
	9000 2100 9000 2250
Text GLabel 10550 1150 2    50   Input ~ 0
DCDC
Wire Wire Line
	10400 1150 10550 1150
$Sheet
S 9500 3600 1100 150 
U 633CC0C9
F0 "Sheet633CC0C8" 50
F1 "Superior Board.sch" 50
$EndSheet
$Sheet
S 9500 4100 1100 150 
U 633CFED4
F0 "Sheet633CFED3" 50
F1 "Nixie Circuit.sch" 50
$EndSheet
$EndSCHEMATC
