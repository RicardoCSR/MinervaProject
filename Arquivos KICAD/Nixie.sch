EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 5
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
L 74xx_IEEE:74141 U?
U 1 1 67B17AD3
P 5450 1500
AR Path="/67B17AD3" Ref="U?"  Part="1" 
AR Path="/67AE4A42/67B17AD3" Ref="U5"  Part="1" 
AR Path="/67E43E22/67B17AD3" Ref="U?"  Part="1" 
F 0 "U5" H 5300 2250 50  0000 C CNN
F 1 "74141" H 5300 2150 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm" H 5450 1500 50  0001 C CNN
F 3 "" H 5450 1500 50  0001 C CNN
	1    5450 1500
	-1   0    0    1   
$EndComp
Wire Wire Line
	5450 800  5600 800 
Text GLabel 5600 800  2    50   Input ~ 0
5VA
Wire Wire Line
	5450 800  5450 950 
$Comp
L Isolator:TLP521-1 U?
U 1 1 67B17A4D
P 2250 1000
AR Path="/67B17A4D" Ref="U?"  Part="1" 
AR Path="/67AE4A42/67B17A4D" Ref="U3"  Part="1" 
AR Path="/67E43E22/67B17A4D" Ref="U?"  Part="1" 
F 0 "U3" H 2100 1250 50  0000 C CNN
F 1 "TLP521-1" H 2500 1250 50  0000 C CNN
F 2 "Package_DIP:DIP-4_W7.62mm" H 2250 1200 50  0001 C CNN
F 3 "" H 2250 1200 50  0001 C CNN
	1    2250 1000
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 67B17A47
P 1650 900
AR Path="/67B17A47" Ref="R?"  Part="1" 
AR Path="/67AE4A42/67B17A47" Ref="R18"  Part="1" 
AR Path="/67E43E22/67B17A47" Ref="R?"  Part="1" 
F 0 "R18" V 1550 800 50  0000 C CNN
F 1 "330" V 1550 1000 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 1580 900 50  0001 C CNN
F 3 "~" H 1650 900 50  0001 C CNN
	1    1650 900 
	0    1    1    0   
$EndComp
Wire Wire Line
	1800 900  1950 900 
$Comp
L power:GNDD #PWR?
U 1 1 67B17A40
P 1800 1100
AR Path="/67B17A40" Ref="#PWR?"  Part="1" 
AR Path="/67AE4A42/67B17A40" Ref="#PWR019"  Part="1" 
AR Path="/67E43E22/67B17A40" Ref="#PWR?"  Part="1" 
F 0 "#PWR019" H 1800 850 50  0001 C CNN
F 1 "GNDD" V 1800 900 50  0000 C CNN
F 2 "" H 1800 1100 50  0001 C CNN
F 3 "" H 1800 1100 50  0001 C CNN
	1    1800 1100
	0    1    1    0   
$EndComp
Text GLabel 2650 900  2    50   Input ~ 0
HV
Wire Wire Line
	2650 900  2550 900 
Wire Wire Line
	1950 1100 1800 1100
$Comp
L Isolator:TLP521-1 U?
U 1 1 67B17A2C
P 2250 1450
AR Path="/67B17A2C" Ref="U?"  Part="1" 
AR Path="/67AE4A42/67B17A2C" Ref="U4"  Part="1" 
AR Path="/67E43E22/67B17A2C" Ref="U?"  Part="1" 
F 0 "U4" H 2100 1700 50  0000 C CNN
F 1 "TLP521-1" H 2500 1700 50  0000 C CNN
F 2 "Package_DIP:DIP-4_W7.62mm" H 2250 1650 50  0001 C CNN
F 3 "" H 2250 1650 50  0001 C CNN
	1    2250 1450
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 67B17A26
P 1650 1350
AR Path="/67B17A26" Ref="R?"  Part="1" 
AR Path="/67AE4A42/67B17A26" Ref="R19"  Part="1" 
AR Path="/67E43E22/67B17A26" Ref="R?"  Part="1" 
F 0 "R19" V 1550 1250 50  0000 C CNN
F 1 "330" V 1550 1450 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 1580 1350 50  0001 C CNN
F 3 "~" H 1650 1350 50  0001 C CNN
	1    1650 1350
	0    1    1    0   
$EndComp
Wire Wire Line
	1800 1350 1950 1350
Text GLabel 2650 1350 2    50   Input ~ 0
HV
Wire Wire Line
	2650 1350 2550 1350
$Comp
L Isolator:TLP521-1 U?
U 1 1 67B17A0B
P 2250 1900
AR Path="/67B17A0B" Ref="U?"  Part="1" 
AR Path="/67AE4A42/67B17A0B" Ref="U6"  Part="1" 
AR Path="/67E43E22/67B17A0B" Ref="U?"  Part="1" 
F 0 "U6" H 2100 2150 50  0000 C CNN
F 1 "TLP521-1" H 2500 2150 50  0000 C CNN
F 2 "Package_DIP:DIP-4_W7.62mm" H 2250 2100 50  0001 C CNN
F 3 "" H 2250 2100 50  0001 C CNN
	1    2250 1900
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 67B17A05
P 1650 1800
AR Path="/67B17A05" Ref="R?"  Part="1" 
AR Path="/67AE4A42/67B17A05" Ref="R23"  Part="1" 
AR Path="/67E43E22/67B17A05" Ref="R?"  Part="1" 
F 0 "R23" V 1550 1700 50  0000 C CNN
F 1 "330" V 1550 1900 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 1580 1800 50  0001 C CNN
F 3 "~" H 1650 1800 50  0001 C CNN
	1    1650 1800
	0    1    1    0   
$EndComp
Wire Wire Line
	1800 1800 1950 1800
Text GLabel 2650 1800 2    50   Input ~ 0
HV
Wire Wire Line
	2650 1800 2550 1800
$Comp
L Isolator:TLP521-1 U?
U 1 1 67B179EA
P 2250 2350
AR Path="/67B179EA" Ref="U?"  Part="1" 
AR Path="/67AE4A42/67B179EA" Ref="U7"  Part="1" 
AR Path="/67E43E22/67B179EA" Ref="U?"  Part="1" 
F 0 "U7" H 2100 2600 50  0000 C CNN
F 1 "TLP521-1" H 2500 2600 50  0000 C CNN
F 2 "Package_DIP:DIP-4_W7.62mm" H 2250 2550 50  0001 C CNN
F 3 "" H 2250 2550 50  0001 C CNN
	1    2250 2350
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 67B179E4
P 1650 2250
AR Path="/67B179E4" Ref="R?"  Part="1" 
AR Path="/67AE4A42/67B179E4" Ref="R26"  Part="1" 
AR Path="/67E43E22/67B179E4" Ref="R?"  Part="1" 
F 0 "R26" V 1550 2150 50  0000 C CNN
F 1 "330" V 1550 2350 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 1580 2250 50  0001 C CNN
F 3 "~" H 1650 2250 50  0001 C CNN
	1    1650 2250
	0    1    1    0   
$EndComp
Wire Wire Line
	1800 2250 1950 2250
Text GLabel 2650 2250 2    50   Input ~ 0
HV
Wire Wire Line
	2650 2250 2550 2250
Wire Wire Line
	3450 1500 3600 1500
Wire Wire Line
	3150 1500 3050 1500
Text GLabel 4250 1300 2    50   Input ~ 0
9
Wire Wire Line
	4250 1300 4100 1300
Text GLabel 4250 1400 2    50   Input ~ 0
8
Wire Wire Line
	4250 1400 4100 1400
Text GLabel 4250 1500 2    50   Input ~ 0
7
Wire Wire Line
	4250 1500 4100 1500
Text GLabel 4250 1600 2    50   Input ~ 0
6
Wire Wire Line
	4250 1600 4100 1600
Text GLabel 4250 1700 2    50   Input ~ 0
5
Wire Wire Line
	4250 1700 4100 1700
Text GLabel 4250 1800 2    50   Input ~ 0
4
Wire Wire Line
	4250 1800 4100 1800
Text GLabel 4250 1900 2    50   Input ~ 0
3
Wire Wire Line
	4250 1900 4100 1900
Text GLabel 4250 2000 2    50   Input ~ 0
2
Wire Wire Line
	4250 2000 4100 2000
Text GLabel 3450 2000 0    50   Input ~ 0
1
Wire Wire Line
	3450 2000 3600 2000
Text GLabel 3400 1400 0    50   Input ~ 0
RHDP
Text GLabel 3050 1500 0    50   Input ~ 0
A
Wire Wire Line
	3450 1600 3600 1600
$Comp
L Device:R R?
U 1 1 6217399B
P 3300 1600
AR Path="/6217399B" Ref="R?"  Part="1" 
AR Path="/67AE4A42/6217399B" Ref="R21"  Part="1" 
AR Path="/67E43E22/6217399B" Ref="R?"  Part="1" 
F 0 "R21" V 3350 1800 50  0000 C CNN
F 1 "4.7K" V 3300 1600 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 3230 1600 50  0001 C CNN
F 3 "~" H 3300 1600 50  0001 C CNN
	1    3300 1600
	0    1    1    0   
$EndComp
Wire Wire Line
	3150 1600 3050 1600
Text GLabel 3050 1600 0    50   Input ~ 0
B
Wire Wire Line
	2550 1100 2650 1100
Text GLabel 2650 1100 2    50   Input ~ 0
A
Wire Wire Line
	2550 1550 2650 1550
Text GLabel 2650 1550 2    50   Input ~ 0
B
Wire Wire Line
	2550 2000 2650 2000
Text GLabel 2650 2000 2    50   Input ~ 0
C
Wire Wire Line
	2550 2450 2650 2450
Text GLabel 2650 2450 2    50   Input ~ 0
D
Text GLabel 4700 1950 0    50   Input ~ 0
0
Wire Wire Line
	4700 1950 4850 1950
Text GLabel 4700 1050 0    50   Input ~ 0
9
Wire Wire Line
	4700 1050 4850 1050
Text GLabel 4700 1150 0    50   Input ~ 0
8
Wire Wire Line
	4700 1150 4850 1150
Text GLabel 4700 1250 0    50   Input ~ 0
7
Wire Wire Line
	4700 1250 4850 1250
Text GLabel 4700 1350 0    50   Input ~ 0
6
Wire Wire Line
	4700 1350 4850 1350
Text GLabel 4700 1450 0    50   Input ~ 0
5
Wire Wire Line
	4700 1450 4850 1450
Text GLabel 4700 1550 0    50   Input ~ 0
4
Wire Wire Line
	4700 1550 4850 1550
Text GLabel 4700 1650 0    50   Input ~ 0
3
Wire Wire Line
	4700 1650 4850 1650
Text GLabel 4700 1750 0    50   Input ~ 0
2
Wire Wire Line
	4700 1750 4850 1750
Text GLabel 4700 1850 0    50   Input ~ 0
1
Wire Wire Line
	4700 1850 4850 1850
Text GLabel 6200 1650 2    50   Input ~ 0
LEVEL_D
Text GLabel 6200 1550 2    50   Input ~ 0
LEVEL_C
Text GLabel 6200 1450 2    50   Input ~ 0
LEVEL_B
Text GLabel 6200 1350 2    50   Input ~ 0
LEVEL_A
Wire Wire Line
	6200 1350 6050 1350
Wire Wire Line
	6200 1450 6050 1450
Wire Wire Line
	6200 1550 6050 1550
Wire Wire Line
	6200 1650 6050 1650
Text GLabel 1350 1800 0    50   Input ~ 0
ANODE_NIXIE_C
Wire Wire Line
	1500 1800 1350 1800
Text GLabel 1350 2250 0    50   Input ~ 0
ANODE_NIXIE_D
Wire Wire Line
	1500 2250 1350 2250
Text GLabel 1350 900  0    50   Input ~ 0
ANODE_NIXIE_A
Wire Wire Line
	1500 900  1350 900 
Text GLabel 1350 1350 0    50   Input ~ 0
ANODE_NIXIE_B
Wire Wire Line
	1500 1350 1350 1350
Text GLabel 5600 700  2    50   Input ~ 0
5VD
Wire Wire Line
	5450 700  5600 700 
Wire Wire Line
	5450 700  5450 800 
Connection ~ 5450 800 
Wire Wire Line
	4950 2300 4950 2150
$Comp
L Device:R R?
U 1 1 62EF4CF0
P 5200 2150
AR Path="/67F05B40/62EF4CF0" Ref="R?"  Part="1" 
AR Path="/67AE4A42/62EF4CF0" Ref="R25"  Part="1" 
F 0 "R25" V 5407 2150 50  0000 C CNN
F 1 "1M" V 5316 2150 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 5130 2150 50  0001 C CNN
F 3 "~" H 5200 2150 50  0001 C CNN
	1    5200 2150
	0    -1   1    0   
$EndComp
Wire Wire Line
	5450 2050 5450 2150
Wire Wire Line
	5350 2150 5450 2150
Wire Wire Line
	4950 2150 5050 2150
$Comp
L MCU_Module:DC-DC U?
U 1 1 634FF288
P 10200 5700
AR Path="/634FF288" Ref="U?"  Part="1" 
AR Path="/67F05B40/634FF288" Ref="U?"  Part="1" 
AR Path="/67AE4A42/634FF288" Ref="U9"  Part="1" 
F 0 "U9" H 10200 6025 50  0000 C CNN
F 1 "DC-DC" H 10200 5934 50  0000 C CNN
F 2 "Converter_DCDC:DCDC_2V~5V" H 10200 5700 50  0001 C CNN
F 3 "" H 10200 5700 50  0001 C CNN
	1    10200 5700
	1    0    0    -1  
$EndComp
Wire Wire Line
	10800 5950 10800 5800
Wire Wire Line
	10800 5800 10650 5800
Wire Wire Line
	9550 5800 9550 5950
Wire Wire Line
	9550 5800 9750 5800
$Comp
L Connector:TestPoint TP?
U 1 1 634FF298
P 9750 5200
AR Path="/634FF298" Ref="TP?"  Part="1" 
AR Path="/67F05B40/634FF298" Ref="TP?"  Part="1" 
AR Path="/67AE4A42/634FF298" Ref="TP3"  Part="1" 
F 0 "TP3" H 9850 5250 50  0000 L CNN
F 1 "DC_PWR" H 9400 5250 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_1.5x1.5mm" H 9950 5200 50  0001 C CNN
F 3 "~" H 9950 5200 50  0001 C CNN
	1    9750 5200
	1    0    0    -1  
$EndComp
Wire Notes Line
	11150 4950 11150 6450
Text GLabel 10900 5600 2    50   Input ~ 0
5VD
Text Notes 9150 6300 0    50   ~ 0
Modulo DC-DC 1.8 ~ 5.5V saida 5V 
$Comp
L Device:R R?
U 1 1 634FF2A4
P 9200 5300
AR Path="/634FF2A4" Ref="R?"  Part="1" 
AR Path="/67F05B40/634FF2A4" Ref="R?"  Part="1" 
AR Path="/67AE4A42/634FF2A4" Ref="R32"  Part="1" 
F 0 "R32" V 9100 5250 50  0000 L CNN
F 1 "4.7K" V 9300 5200 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 9130 5300 50  0001 C CNN
F 3 "~" H 9200 5300 50  0001 C CNN
	1    9200 5300
	0    1    1    0   
$EndComp
Wire Wire Line
	9050 5300 8950 5300
Text GLabel 8950 5300 0    50   Input ~ 0
DCDC
$Comp
L power:GNDD #PWR?
U 1 1 634FF2B2
P 9150 5950
AR Path="/634FF2B2" Ref="#PWR?"  Part="1" 
AR Path="/67F05B40/634FF2B2" Ref="#PWR?"  Part="1" 
AR Path="/67AE4A42/634FF2B2" Ref="#PWR032"  Part="1" 
F 0 "#PWR032" H 9150 5700 50  0001 C CNN
F 1 "GNDD" H 9154 5795 50  0000 C CNN
F 2 "" H 9150 5950 50  0001 C CNN
F 3 "" H 9150 5950 50  0001 C CNN
	1    9150 5950
	1    0    0    -1  
$EndComp
Wire Wire Line
	9150 5950 9150 5800
$Comp
L Device:R R?
U 1 1 634FF2B9
P 9350 5800
AR Path="/67F05B40/634FF2B9" Ref="R?"  Part="1" 
AR Path="/67AE4A42/634FF2B9" Ref="R33"  Part="1" 
F 0 "R33" V 9557 5800 50  0000 C CNN
F 1 "1M" V 9466 5800 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 9280 5800 50  0001 C CNN
F 3 "~" H 9350 5800 50  0001 C CNN
	1    9350 5800
	0    -1   1    0   
$EndComp
Wire Wire Line
	9350 5300 9550 5300
Wire Wire Line
	9500 5800 9550 5800
Connection ~ 9550 5800
Wire Wire Line
	9150 5800 9200 5800
$Comp
L Device:CP C?
U 1 1 634FF2C3
P 9550 5550
AR Path="/67F05B40/634FF2C3" Ref="C?"  Part="1" 
AR Path="/67AE4A42/634FF2C3" Ref="C5"  Part="1" 
F 0 "C5" H 9300 5600 50  0000 L CNN
F 1 "10uF" H 9200 5450 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 9588 5400 50  0001 C CNN
F 3 "~" H 9550 5550 50  0001 C CNN
	1    9550 5550
	1    0    0    -1  
$EndComp
Wire Wire Line
	9550 5300 9550 5400
Wire Wire Line
	9550 5300 9750 5300
Wire Wire Line
	9750 5300 9750 5600
Connection ~ 9550 5300
Wire Wire Line
	9550 5700 9550 5800
Wire Wire Line
	9750 5200 9750 5300
Connection ~ 9750 5300
Wire Wire Line
	10650 5600 10900 5600
Wire Notes Line
	11150 2700 11150 4900
Wire Notes Line
	8500 4900 8500 2700
Wire Notes Line
	11150 2700 8500 2700
Wire Notes Line
	8500 4900 11150 4900
Text GLabel 8950 3850 0    50   Input ~ 0
3.3VA
Text Notes 10750 4600 2    50   ~ 0
Circuito para leitura das Baterias ligadas em VBAT,\nbaseado em um circuito divisor de tensão com um\nmosfet que permite a medição sem drenar corrente \nda bateria quando não ligado.
Text GLabel 9600 3850 2    50   Input ~ 0
EN
Wire Wire Line
	10350 3400 10450 3400
Connection ~ 10350 3400
Wire Wire Line
	10350 3850 10350 3400
Wire Wire Line
	10250 3400 10350 3400
Wire Wire Line
	10450 3850 10350 3850
Wire Wire Line
	10850 3850 10850 3950
Wire Wire Line
	10850 3850 10850 3400
Wire Wire Line
	10750 3850 10850 3850
Wire Wire Line
	10750 3400 10850 3400
$Comp
L power:GNDD #PWR?
U 1 1 635B4F14
P 10850 3950
AR Path="/635B4F14" Ref="#PWR?"  Part="1" 
AR Path="/67F05B40/635B4F14" Ref="#PWR?"  Part="1" 
AR Path="/67AE4A42/635B4F14" Ref="#PWR029"  Part="1" 
F 0 "#PWR029" H 10850 3700 50  0001 C CNN
F 1 "GNDD" H 10854 3795 50  0000 C CNN
F 2 "" H 10850 3950 50  0001 C CNN
F 3 "" H 10850 3950 50  0001 C CNN
	1    10850 3950
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 635B4F1A
P 10600 3400
AR Path="/635B4F1A" Ref="R?"  Part="1" 
AR Path="/67F05B40/635B4F1A" Ref="R?"  Part="1" 
AR Path="/67AE4A42/635B4F1A" Ref="R28"  Part="1" 
F 0 "R28" V 10807 3400 50  0000 C CNN
F 1 "10K" V 10716 3400 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 10530 3400 50  0001 C CNN
F 3 "~" H 10600 3400 50  0001 C CNN
	1    10600 3400
	0    1    -1   0   
$EndComp
Connection ~ 9850 3400
Wire Wire Line
	9950 3400 9850 3400
Wire Wire Line
	9000 3400 9000 2900
Wire Wire Line
	9000 2900 9350 2900
Wire Wire Line
	9000 3400 9300 3400
Wire Wire Line
	9850 3400 9700 3400
Wire Wire Line
	9850 2900 9850 3400
Wire Wire Line
	9650 2900 9850 2900
Wire Wire Line
	9000 3850 9100 3850
Wire Wire Line
	9500 3850 9500 3700
Wire Wire Line
	9400 3850 9500 3850
Connection ~ 9000 3400
Wire Wire Line
	9000 3850 9000 3400
$Comp
L Device:R R?
U 1 1 635B4F2D
P 9250 3850
AR Path="/635B4F2D" Ref="R?"  Part="1" 
AR Path="/67F05B40/635B4F2D" Ref="R?"  Part="1" 
AR Path="/67AE4A42/635B4F2D" Ref="R30"  Part="1" 
F 0 "R30" V 9457 3850 50  0000 C CNN
F 1 "100K" V 9366 3850 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 9180 3850 50  0001 C CNN
F 3 "~" H 9250 3850 50  0001 C CNN
	1    9250 3850
	0    1    -1   0   
$EndComp
Text GLabel 8950 3400 0    50   Input ~ 0
3.3VAD
$Comp
L Transistor_FET:2N7002K Q?
U 1 1 635B4F34
P 9500 3500
AR Path="/635B4F34" Ref="Q?"  Part="1" 
AR Path="/67F05B40/635B4F34" Ref="Q?"  Part="1" 
AR Path="/67AE4A42/635B4F34" Ref="Q8"  Part="1" 
F 0 "Q8" V 9450 3200 50  0000 L CNN
F 1 "CJ2305" V 9350 3150 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 9700 3425 50  0001 L CIN
F 3 "" H 9500 3500 50  0001 L CNN
	1    9500 3500
	0    -1   -1   0   
$EndComp
$Comp
L Jumper:SolderJumper_2_Open JP?
U 1 1 635B4F3A
P 9500 2900
AR Path="/635B4F3A" Ref="JP?"  Part="1" 
AR Path="/67F05B40/635B4F3A" Ref="JP?"  Part="1" 
AR Path="/67AE4A42/635B4F3A" Ref="JP2"  Part="1" 
F 0 "JP2" H 9450 2800 50  0000 L CNN
F 1 "FLOW" H 9450 3000 50  0000 L CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Open_RoundedPad1.0x1.5mm" H 9500 2900 50  0001 C CNN
F 3 "~" H 9500 2900 50  0001 C CNN
	1    9500 2900
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 635B4F40
P 10600 3850
AR Path="/635B4F40" Ref="C?"  Part="1" 
AR Path="/67F05B40/635B4F40" Ref="C?"  Part="1" 
AR Path="/67AE4A42/635B4F40" Ref="C4"  Part="1" 
F 0 "C4" V 10350 3800 50  0000 L CNN
F 1 "100uF" V 10450 3750 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 10638 3700 50  0001 C CNN
F 3 "~" H 10600 3850 50  0001 C CNN
	1    10600 3850
	0    -1   1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 635B4F46
P 10100 3400
AR Path="/635B4F46" Ref="R?"  Part="1" 
AR Path="/67F05B40/635B4F46" Ref="R?"  Part="1" 
AR Path="/67AE4A42/635B4F46" Ref="R27"  Part="1" 
F 0 "R27" V 10307 3400 50  0000 C CNN
F 1 "10K" V 10216 3400 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 10030 3400 50  0001 C CNN
F 3 "~" H 10100 3400 50  0001 C CNN
	1    10100 3400
	0    1    -1   0   
$EndComp
Wire Wire Line
	8950 3400 9000 3400
Connection ~ 10850 3850
Wire Wire Line
	9600 3850 9500 3850
Connection ~ 9500 3850
Wire Wire Line
	8950 3850 9000 3850
Connection ~ 9000 3850
Text GLabel 10300 4000 0    50   Input ~ 0
BATERRY_LEVEL
Wire Wire Line
	10350 4000 10300 4000
Wire Wire Line
	10350 4000 10350 3850
Connection ~ 10350 3850
$Comp
L Connector_Generic:Conn_02x08_Odd_Even J10
U 1 1 635E9E3A
P 3800 1600
F 0 "J10" H 3850 2117 50  0000 C CNN
F 1 "Conn_02x08_Odd_Even" H 3850 2026 50  0000 C CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_2x08_P2.00mm_Vertical" H 3800 1600 50  0001 C CNN
F 3 "~" H 3800 1600 50  0001 C CNN
	1    3800 1600
	1    0    0    -1  
$EndComp
Wire Wire Line
	3450 1900 3600 1900
Text GLabel 3450 1900 0    50   Input ~ 0
0
$Comp
L Device:R R?
U 1 1 63638CC8
P 3300 1500
AR Path="/63638CC8" Ref="R?"  Part="1" 
AR Path="/67AE4A42/63638CC8" Ref="R20"  Part="1" 
AR Path="/67E43E22/63638CC8" Ref="R?"  Part="1" 
F 0 "R20" V 3350 1700 50  0000 C CNN
F 1 "4.7K" V 3300 1500 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 3230 1500 50  0001 C CNN
F 3 "~" H 3300 1500 50  0001 C CNN
	1    3300 1500
	0    1    1    0   
$EndComp
Wire Wire Line
	3450 1700 3600 1700
$Comp
L Device:R R?
U 1 1 6364029F
P 3300 1700
AR Path="/6364029F" Ref="R?"  Part="1" 
AR Path="/67AE4A42/6364029F" Ref="R22"  Part="1" 
AR Path="/67E43E22/6364029F" Ref="R?"  Part="1" 
F 0 "R22" V 3350 1900 50  0000 C CNN
F 1 "4.7K" V 3300 1700 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 3230 1700 50  0001 C CNN
F 3 "~" H 3300 1700 50  0001 C CNN
	1    3300 1700
	0    1    1    0   
$EndComp
Wire Wire Line
	3150 1700 3050 1700
Text GLabel 3050 1700 0    50   Input ~ 0
C
Wire Wire Line
	3450 1800 3600 1800
$Comp
L Device:R R?
U 1 1 63647975
P 3300 1800
AR Path="/63647975" Ref="R?"  Part="1" 
AR Path="/67AE4A42/63647975" Ref="R24"  Part="1" 
AR Path="/67E43E22/63647975" Ref="R?"  Part="1" 
F 0 "R24" V 3350 2000 50  0000 C CNN
F 1 "4.7K" V 3300 1800 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 3230 1800 50  0001 C CNN
F 3 "~" H 3300 1800 50  0001 C CNN
	1    3300 1800
	0    1    1    0   
$EndComp
Wire Wire Line
	3150 1800 3050 1800
Text GLabel 3050 1800 0    50   Input ~ 0
D
Wire Wire Line
	3400 1400 3600 1400
$Comp
L power:GNDD #PWR?
U 1 1 636D0B4C
P 1800 1550
AR Path="/636D0B4C" Ref="#PWR?"  Part="1" 
AR Path="/67AE4A42/636D0B4C" Ref="#PWR020"  Part="1" 
AR Path="/67E43E22/636D0B4C" Ref="#PWR?"  Part="1" 
F 0 "#PWR020" H 1800 1300 50  0001 C CNN
F 1 "GNDD" V 1800 1350 50  0000 C CNN
F 2 "" H 1800 1550 50  0001 C CNN
F 3 "" H 1800 1550 50  0001 C CNN
	1    1800 1550
	0    1    1    0   
$EndComp
Wire Wire Line
	1950 1550 1800 1550
$Comp
L power:GNDD #PWR?
U 1 1 636D3D6B
P 1800 2000
AR Path="/636D3D6B" Ref="#PWR?"  Part="1" 
AR Path="/67AE4A42/636D3D6B" Ref="#PWR024"  Part="1" 
AR Path="/67E43E22/636D3D6B" Ref="#PWR?"  Part="1" 
F 0 "#PWR024" H 1800 1750 50  0001 C CNN
F 1 "GNDD" V 1800 1800 50  0000 C CNN
F 2 "" H 1800 2000 50  0001 C CNN
F 3 "" H 1800 2000 50  0001 C CNN
	1    1800 2000
	0    1    1    0   
$EndComp
Wire Wire Line
	1950 2000 1800 2000
$Comp
L power:GNDD #PWR?
U 1 1 636D72F7
P 1800 2450
AR Path="/636D72F7" Ref="#PWR?"  Part="1" 
AR Path="/67AE4A42/636D72F7" Ref="#PWR027"  Part="1" 
AR Path="/67E43E22/636D72F7" Ref="#PWR?"  Part="1" 
F 0 "#PWR027" H 1800 2200 50  0001 C CNN
F 1 "GNDD" V 1800 2250 50  0000 C CNN
F 2 "" H 1800 2450 50  0001 C CNN
F 3 "" H 1800 2450 50  0001 C CNN
	1    1800 2450
	0    1    1    0   
$EndComp
Wire Wire Line
	1950 2450 1800 2450
$Comp
L Device:Q_SCR_AGK D?
U 1 1 63749E77
P 7000 4200
AR Path="/63749E77" Ref="D?"  Part="1" 
AR Path="/67F05B40/63749E77" Ref="D?"  Part="1" 
AR Path="/67AE4A42/63749E77" Ref="D6"  Part="1" 
F 0 "D6" H 7088 4246 50  0000 L CNN
F 1 "Q_SCR_AGK" H 7088 4155 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" V 7000 4200 50  0001 C CNN
F 3 "~" V 7000 4200 50  0001 C CNN
	1    7000 4200
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 63749E7D
P 7000 3700
AR Path="/63749E7D" Ref="R?"  Part="1" 
AR Path="/67F05B40/63749E7D" Ref="R?"  Part="1" 
AR Path="/67AE4A42/63749E7D" Ref="R29"  Part="1" 
F 0 "R29" H 7070 3746 50  0000 L CNN
F 1 "1K" H 7070 3655 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 6930 3700 50  0001 C CNN
F 3 "~" H 7000 3700 50  0001 C CNN
	1    7000 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	7000 3850 7000 3950
$Comp
L Transistor_FET:2N7002 Q?
U 1 1 63749E84
P 7600 3950
AR Path="/63749E84" Ref="Q?"  Part="1" 
AR Path="/67F05B40/63749E84" Ref="Q?"  Part="1" 
AR Path="/67AE4A42/63749E84" Ref="Q9"  Part="1" 
F 0 "Q9" H 7804 3996 50  0000 L CNN
F 1 "2N7002" H 7804 3905 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 7800 3875 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/NDS7002A-D.PDF" H 7600 3950 50  0001 L CNN
	1    7600 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	7400 3950 7000 3950
Connection ~ 7000 3950
Wire Wire Line
	7000 3950 7000 4050
$Comp
L Diode:DZ2S036X0L D?
U 1 1 63749E8D
P 6400 3700
AR Path="/63749E8D" Ref="D?"  Part="1" 
AR Path="/67F05B40/63749E8D" Ref="D?"  Part="1" 
AR Path="/67AE4A42/63749E8D" Ref="D5"  Part="1" 
F 0 "D5" V 6354 3780 50  0000 L CNN
F 1 "DZ2S036X0L" H 6250 3600 50  0000 L CNN
F 2 "Diode_SMD:D_2114_3652Metric_Castellated" H 6400 3525 50  0001 C CNN
F 3 "https://industrial.panasonic.com/content/data/SC/ds/ds4/DZ2S03600L_E.pdf" H 6400 3700 50  0001 C CNN
	1    6400 3700
	0    1    1    0   
$EndComp
Wire Wire Line
	6400 3850 6400 4300
Wire Wire Line
	6400 4300 6850 4300
$Comp
L Device:R R?
U 1 1 63749E95
P 6400 4600
AR Path="/63749E95" Ref="R?"  Part="1" 
AR Path="/67F05B40/63749E95" Ref="R?"  Part="1" 
AR Path="/67AE4A42/63749E95" Ref="R31"  Part="1" 
F 0 "R31" H 6470 4646 50  0000 L CNN
F 1 "1K" H 6470 4555 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 6330 4600 50  0001 C CNN
F 3 "~" H 6400 4600 50  0001 C CNN
	1    6400 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	6400 4450 6400 4300
Connection ~ 6400 4300
$Comp
L power:GNDD #PWR?
U 1 1 63749E9D
P 7000 4850
AR Path="/63749E9D" Ref="#PWR?"  Part="1" 
AR Path="/67F05B40/63749E9D" Ref="#PWR?"  Part="1" 
AR Path="/67AE4A42/63749E9D" Ref="#PWR031"  Part="1" 
F 0 "#PWR031" H 7000 4600 50  0001 C CNN
F 1 "GNDD" H 7004 4695 50  0000 C CNN
F 2 "" H 7000 4850 50  0001 C CNN
F 3 "" H 7000 4850 50  0001 C CNN
	1    7000 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	7000 4350 7000 4600
$Comp
L power:GNDD #PWR?
U 1 1 63749EA4
P 6400 4850
AR Path="/63749EA4" Ref="#PWR?"  Part="1" 
AR Path="/67F05B40/63749EA4" Ref="#PWR?"  Part="1" 
AR Path="/67AE4A42/63749EA4" Ref="#PWR030"  Part="1" 
F 0 "#PWR030" H 6400 4600 50  0001 C CNN
F 1 "GNDD" H 6404 4695 50  0000 C CNN
F 2 "" H 6400 4850 50  0001 C CNN
F 3 "" H 6400 4850 50  0001 C CNN
	1    6400 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	6400 4850 6400 4750
$Comp
L power:GNDD #PWR?
U 1 1 63749EAB
P 8250 3900
AR Path="/63749EAB" Ref="#PWR?"  Part="1" 
AR Path="/67F05B40/63749EAB" Ref="#PWR?"  Part="1" 
AR Path="/67AE4A42/63749EAB" Ref="#PWR028"  Part="1" 
F 0 "#PWR028" H 8250 3650 50  0001 C CNN
F 1 "GNDD" H 8254 3745 50  0000 C CNN
F 2 "" H 8250 3900 50  0001 C CNN
F 3 "" H 8250 3900 50  0001 C CNN
	1    8250 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	8250 3900 8250 3650
Wire Wire Line
	8250 3650 7700 3650
Wire Wire Line
	7700 3650 7700 3750
Wire Wire Line
	7700 4600 7000 4600
Connection ~ 7000 4600
Wire Wire Line
	7000 4600 7000 4850
Wire Wire Line
	6300 3450 6400 3450
Wire Wire Line
	6400 3450 6400 3550
Wire Wire Line
	6400 3450 7000 3450
Wire Wire Line
	7000 3450 7000 3550
Connection ~ 6400 3450
Text GLabel 7700 3450 2    50   Input ~ 0
3.3VA
Wire Wire Line
	7700 3450 7000 3450
Connection ~ 7000 3450
Wire Notes Line
	5850 3150 5850 5200
Wire Notes Line
	8450 3150 5850 3150
$Comp
L Regulator_Linear:AMS1117-3.3 U?
U 1 1 63749EC4
P 5400 5650
AR Path="/63749EC4" Ref="U?"  Part="1" 
AR Path="/67F05B40/63749EC4" Ref="U?"  Part="1" 
AR Path="/67AE4A42/63749EC4" Ref="U8"  Part="1" 
F 0 "U8" H 5400 5892 50  0000 C CNN
F 1 "AMS1117-3.3" H 5400 5801 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-223-3_TabPin2" H 5400 5850 50  0001 C CNN
F 3 "http://www.advanced-monolithic.com/pdf/ds1117.pdf" H 5500 5400 50  0001 C CNN
	1    5400 5650
	1    0    0    -1  
$EndComp
Text GLabel 5900 5650 2    50   Input ~ 0
3.3VR
$Comp
L Device:CP C?
U 1 1 63749ECB
P 5800 5900
AR Path="/63749ECB" Ref="C?"  Part="1" 
AR Path="/67F05B40/63749ECB" Ref="C?"  Part="1" 
AR Path="/67AE4A42/63749ECB" Ref="C9"  Part="1" 
F 0 "C9" H 5918 5946 50  0000 L CNN
F 1 "10uF" H 5918 5855 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 5838 5750 50  0001 C CNN
F 3 "~" H 5800 5900 50  0001 C CNN
	1    5800 5900
	1    0    0    -1  
$EndComp
Wire Wire Line
	5700 5650 5800 5650
Wire Wire Line
	5800 5750 5800 5650
Wire Wire Line
	5900 5650 5800 5650
Connection ~ 5800 5650
Wire Wire Line
	5400 5950 5400 6150
Wire Wire Line
	5400 6150 5800 6150
Wire Wire Line
	5800 6150 5800 6050
Connection ~ 5400 6150
$Comp
L power:GNDD #PWR?
U 1 1 63749ED9
P 5400 6200
AR Path="/63749ED9" Ref="#PWR?"  Part="1" 
AR Path="/67F05B40/63749ED9" Ref="#PWR?"  Part="1" 
AR Path="/67AE4A42/63749ED9" Ref="#PWR037"  Part="1" 
F 0 "#PWR037" H 5400 5950 50  0001 C CNN
F 1 "GNDD" H 5404 6045 50  0000 C CNN
F 2 "" H 5400 6200 50  0001 C CNN
F 3 "" H 5400 6200 50  0001 C CNN
	1    5400 6200
	1    0    0    -1  
$EndComp
Wire Wire Line
	5400 6200 5400 6150
Text GLabel 4900 5650 0    50   Input ~ 0
5VA
$Comp
L Device:C C?
U 1 1 63749EE1
P 5000 5900
AR Path="/63749EE1" Ref="C?"  Part="1" 
AR Path="/67F05B40/63749EE1" Ref="C?"  Part="1" 
AR Path="/67AE4A42/63749EE1" Ref="C8"  Part="1" 
F 0 "C8" H 5115 5946 50  0000 L CNN
F 1 "10uF" H 5115 5855 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 5038 5750 50  0001 C CNN
F 3 "~" H 5000 5900 50  0001 C CNN
	1    5000 5900
	-1   0    0    -1  
$EndComp
Wire Wire Line
	5000 5750 5000 5650
$Comp
L Connector:TestPoint TP?
U 1 1 63749EE8
P 5800 5500
AR Path="/63749EE8" Ref="TP?"  Part="1" 
AR Path="/67F05B40/63749EE8" Ref="TP?"  Part="1" 
AR Path="/67AE4A42/63749EE8" Ref="TP4"  Part="1" 
F 0 "TP4" H 5858 5618 50  0000 L CNN
F 1 "3.3V" H 5858 5527 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_1.5x1.5mm" H 6000 5500 50  0001 C CNN
F 3 "~" H 6000 5500 50  0001 C CNN
	1    5800 5500
	1    0    0    -1  
$EndComp
Wire Wire Line
	5800 5500 5800 5650
Connection ~ 7650 5400
Wire Wire Line
	7800 5400 7650 5400
Text GLabel 7800 5400 2    50   Input ~ 0
5VG
Connection ~ 6950 5950
Wire Wire Line
	6950 6050 6950 5950
Wire Wire Line
	7650 5950 7650 5850
Connection ~ 7650 5950
Wire Wire Line
	7450 5950 7650 5950
Wire Wire Line
	6950 5950 7150 5950
Wire Wire Line
	6950 5850 6950 5950
Connection ~ 6950 5400
Wire Wire Line
	6950 5400 7650 5400
$Comp
L Device:R R?
U 1 1 63749EFC
P 7300 5950
AR Path="/67F05B40/63749EFC" Ref="R?"  Part="1" 
AR Path="/67AE4A42/63749EFC" Ref="R34"  Part="1" 
F 0 "R34" V 7507 5950 50  0000 C CNN
F 1 "1M" V 7416 5950 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 7230 5950 50  0001 C CNN
F 3 "~" H 7300 5950 50  0001 C CNN
	1    7300 5950
	0    -1   1    0   
$EndComp
Wire Wire Line
	7650 6050 7650 5950
Wire Wire Line
	7650 5550 7650 5400
Wire Wire Line
	6950 5400 6800 5400
Wire Wire Line
	6950 5550 6950 5400
$Comp
L Device:C C?
U 1 1 63749F0C
P 6950 5700
AR Path="/67F05B40/63749F0C" Ref="C?"  Part="1" 
AR Path="/67AE4A42/63749F0C" Ref="C6"  Part="1" 
F 0 "C6" H 7065 5746 50  0000 L CNN
F 1 "100nF" H 7000 5600 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 6988 5550 50  0001 C CNN
F 3 "~" H 6950 5700 50  0001 C CNN
	1    6950 5700
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C?
U 1 1 63749F12
P 7650 5700
AR Path="/67F05B40/63749F12" Ref="C?"  Part="1" 
AR Path="/67AE4A42/63749F12" Ref="C7"  Part="1" 
F 0 "C7" H 7768 5746 50  0000 L CNN
F 1 "100uF" H 7700 5600 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 7688 5550 50  0001 C CNN
F 3 "~" H 7650 5700 50  0001 C CNN
	1    7650 5700
	1    0    0    -1  
$EndComp
Text GLabel 6300 3450 0    50   Input ~ 0
3.3VR
Text GLabel 6800 5400 0    50   Input ~ 0
5VD
$Comp
L Connector:TestPoint TP?
U 1 1 63749F20
P 7800 5950
AR Path="/63749F20" Ref="TP?"  Part="1" 
AR Path="/67F05B40/63749F20" Ref="TP?"  Part="1" 
AR Path="/67AE4A42/63749F20" Ref="TP5"  Part="1" 
F 0 "TP5" V 7900 6000 50  0000 L CNN
F 1 "TestPoint" V 7800 6150 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_1.5x1.5mm" H 8000 5950 50  0001 C CNN
F 3 "~" H 8000 5950 50  0001 C CNN
	1    7800 5950
	0    1    1    0   
$EndComp
Wire Wire Line
	7800 5950 7650 5950
Wire Wire Line
	5000 5650 5100 5650
Wire Wire Line
	4900 5650 5000 5650
Connection ~ 5000 5650
Text Notes 7050 4800 0    50   ~ 0
Circuito de Entrada com \nProteção de Sobretensão 3.6Vmax\n
Wire Notes Line
	6200 5250 4650 5250
Wire Notes Line
	4650 6450 6200 6450
Wire Notes Line
	4650 5250 4650 6450
Wire Notes Line
	6200 5250 6200 6450
Wire Notes Line
	6250 5250 6250 6450
Wire Wire Line
	5000 6150 5400 6150
Wire Wire Line
	5000 6150 5000 6050
Wire Notes Line
	5850 5200 8450 5200
Wire Notes Line
	6250 5250 8450 5250
Wire Notes Line
	8450 3150 8450 5200
Wire Notes Line
	8450 5250 8450 6450
Wire Notes Line
	8450 6450 6250 6450
Wire Notes Line
	8500 6450 8500 4950
Wire Notes Line
	8500 4950 11150 4950
Wire Notes Line
	11150 6450 8500 6450
Text GLabel 10300 1200 2    50   Input ~ 0
5VD
Wire Wire Line
	10300 1200 10150 1200
Wire Wire Line
	9500 1600 9650 1600
Wire Wire Line
	9500 1700 9650 1700
Text GLabel 9500 1200 0    50   Input ~ 0
5VA
Wire Wire Line
	9500 1200 9650 1200
Text GLabel 9500 1300 0    50   Input ~ 0
5VA
Wire Wire Line
	9500 1300 9650 1300
Text GLabel 10300 1300 2    50   Input ~ 0
5VD
Wire Wire Line
	10300 1300 10150 1300
Text GLabel 9500 1400 0    50   Input ~ 0
WIFI_LED
Wire Wire Line
	9500 1400 9650 1400
Wire Wire Line
	10300 1600 10150 1600
Text GLabel 10300 1600 2    50   Input ~ 0
HV
Wire Wire Line
	10300 1700 10150 1700
Text GLabel 10300 1700 2    50   Input ~ 0
HV
$Comp
L Connector_Generic:Conn_02x06_Odd_Even J?
U 1 1 6388C714
P 9850 1400
AR Path="/67F05B40/6388C714" Ref="J?"  Part="1" 
AR Path="/67AE4A42/6388C714" Ref="J8"  Part="1" 
F 0 "J8" H 9900 1817 50  0000 C CNN
F 1 "Conexao Relogio" H 9900 1726 50  0000 C CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_2x06_P2.00mm_Vertical" H 9850 1400 50  0001 C CNN
F 3 "~" H 9850 1400 50  0001 C CNN
	1    9850 1400
	1    0    0    -1  
$EndComp
Text GLabel 7800 1400 0    50   Input ~ 0
5VG
Wire Wire Line
	7800 1400 7950 1400
Text GLabel 8600 1400 2    50   Input ~ 0
3.3VR
Wire Wire Line
	8600 1400 8450 1400
Text GLabel 7800 1500 0    50   Input ~ 0
3.3VA
Wire Wire Line
	7800 1500 7950 1500
Wire Wire Line
	7950 1700 7800 1700
Text GLabel 8600 1600 2    50   Input ~ 0
BAT2+
Wire Wire Line
	8600 1600 8450 1600
Text GLabel 8600 1500 2    50   Input ~ 0
TX0
Text GLabel 8600 1700 2    50   Input ~ 0
RX0
Wire Wire Line
	8600 1500 8450 1500
Wire Wire Line
	8600 1700 8450 1700
$Comp
L Connector_Generic:Conn_02x04_Odd_Even J?
U 1 1 626F3105
P 8150 1500
AR Path="/626F3105" Ref="J?"  Part="1" 
AR Path="/61A16067/626F3105" Ref="J?"  Part="1" 
AR Path="/63AEBE91/626F3105" Ref="J?"  Part="1" 
AR Path="/63B72C77/626F3105" Ref="J?"  Part="1" 
AR Path="/67AE4A42/626F3105" Ref="J9"  Part="1" 
F 0 "J9" H 8200 1817 50  0000 C CNN
F 1 "Modulo Externo" H 8200 1726 50  0000 C CNN
F 2 "Connector_Molex:Molex_Nano-Fit_105310-xx08_2x04_P2.50mm_Vertical" H 8150 1500 50  0001 C CNN
F 3 "~" H 8150 1500 50  0001 C CNN
	1    8150 1500
	1    0    0    -1  
$EndComp
Text GLabel 7800 1600 0    50   Input ~ 0
5VA
Wire Wire Line
	7800 1600 7950 1600
$Comp
L power:GNDD #PWR?
U 1 1 6262A5BC
P 4950 2300
AR Path="/6262A5BC" Ref="#PWR?"  Part="1" 
AR Path="/67AE4A42/6262A5BC" Ref="#PWR0107"  Part="1" 
F 0 "#PWR0107" H 4950 2050 50  0001 C CNN
F 1 "GNDD" H 4954 2145 50  0000 C CNN
F 2 "" H 4950 2300 50  0001 C CNN
F 3 "" H 4950 2300 50  0001 C CNN
	1    4950 2300
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 62641A9E
P 7800 1700
AR Path="/62641A9E" Ref="#PWR?"  Part="1" 
AR Path="/67AE4A42/62641A9E" Ref="#PWR0108"  Part="1" 
F 0 "#PWR0108" H 7800 1450 50  0001 C CNN
F 1 "GNDD" V 7800 1500 50  0000 C CNN
F 2 "" H 7800 1700 50  0001 C CNN
F 3 "" H 7800 1700 50  0001 C CNN
	1    7800 1700
	0    1    1    0   
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 62651514
P 9500 1600
AR Path="/62651514" Ref="#PWR?"  Part="1" 
AR Path="/67AE4A42/62651514" Ref="#PWR0109"  Part="1" 
F 0 "#PWR0109" H 9500 1350 50  0001 C CNN
F 1 "GNDD" V 9500 1400 50  0000 C CNN
F 2 "" H 9500 1600 50  0001 C CNN
F 3 "" H 9500 1600 50  0001 C CNN
	1    9500 1600
	0    1    1    0   
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 626591A1
P 9500 1700
AR Path="/626591A1" Ref="#PWR?"  Part="1" 
AR Path="/67AE4A42/626591A1" Ref="#PWR0110"  Part="1" 
F 0 "#PWR0110" H 9500 1450 50  0001 C CNN
F 1 "GNDD" V 9500 1500 50  0000 C CNN
F 2 "" H 9500 1700 50  0001 C CNN
F 3 "" H 9500 1700 50  0001 C CNN
	1    9500 1700
	0    1    1    0   
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 62670BD3
P 7650 6050
AR Path="/62670BD3" Ref="#PWR?"  Part="1" 
AR Path="/67AE4A42/62670BD3" Ref="#PWR0111"  Part="1" 
F 0 "#PWR0111" H 7650 5800 50  0001 C CNN
F 1 "GNDD" H 7654 5895 50  0000 C CNN
F 2 "" H 7650 6050 50  0001 C CNN
F 3 "" H 7650 6050 50  0001 C CNN
	1    7650 6050
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 62678699
P 6950 6050
AR Path="/62678699" Ref="#PWR?"  Part="1" 
AR Path="/67AE4A42/62678699" Ref="#PWR0112"  Part="1" 
F 0 "#PWR0112" H 6950 5800 50  0001 C CNN
F 1 "GNDD" H 6954 5895 50  0000 C CNN
F 2 "" H 6950 6050 50  0001 C CNN
F 3 "" H 6950 6050 50  0001 C CNN
	1    6950 6050
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 62680C4A
P 9550 5950
AR Path="/62680C4A" Ref="#PWR?"  Part="1" 
AR Path="/67AE4A42/62680C4A" Ref="#PWR0113"  Part="1" 
F 0 "#PWR0113" H 9550 5700 50  0001 C CNN
F 1 "GNDD" H 9554 5795 50  0000 C CNN
F 2 "" H 9550 5950 50  0001 C CNN
F 3 "" H 9550 5950 50  0001 C CNN
	1    9550 5950
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 626902A5
P 10800 5950
AR Path="/626902A5" Ref="#PWR?"  Part="1" 
AR Path="/67AE4A42/626902A5" Ref="#PWR0114"  Part="1" 
F 0 "#PWR0114" H 10800 5700 50  0001 C CNN
F 1 "GNDD" H 10804 5795 50  0000 C CNN
F 2 "" H 10800 5950 50  0001 C CNN
F 3 "" H 10800 5950 50  0001 C CNN
	1    10800 5950
	1    0    0    -1  
$EndComp
Wire Wire Line
	7700 4150 7700 4600
$EndSCHEMATC
