EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 2
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
L nixiemisc:74141DIP16 M1
U 1 1 631DB6DA
P 1800 4400
F 0 "M1" H 1800 4400 45  0001 C CNN
F 1 "74141DIP16" H 1800 4400 45  0001 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm" H 1830 4550 20  0001 C CNN
F 3 "" H 1800 4400 50  0001 C CNN
	1    1800 4400
	1    0    0    -1  
$EndComp
$Comp
L nixies-us:IN-16 N2
U 1 1 631EA90D
P 4300 1500
F 0 "N2" H 4350 2345 45  0000 C CNN
F 1 "IN-16" H 4300 1500 45  0001 L BNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_2x06_P2.00mm_Vertical" H 4330 1650 20  0001 C CNN
F 3 "" H 4300 1500 50  0001 C CNN
	1    4300 1500
	1    0    0    -1  
$EndComp
$Comp
L nixiemisc:74141DIP16 M2
U 1 1 6321C999
P 1800 3050
F 0 "M2" H 1800 3050 45  0001 C CNN
F 1 "74141DIP16" H 1800 3050 45  0001 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm" H 1830 3200 20  0001 C CNN
F 3 "" H 1800 3050 50  0001 C CNN
	1    1800 3050
	1    0    0    -1  
$EndComp
$Comp
L nixies-us:IN-16 N4
U 1 1 6321C9A5
P 5750 1500
F 0 "N4" H 5800 2345 45  0000 C CNN
F 1 "IN-16" H 5750 1500 45  0001 L BNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_2x06_P2.00mm_Vertical" H 5780 1650 20  0001 C CNN
F 3 "" H 5750 1500 50  0001 C CNN
	1    5750 1500
	1    0    0    -1  
$EndComp
Text GLabel 1100 4100 0    50   Input ~ 0
5VA
Text GLabel 1100 4000 0    50   Input ~ 0
DCDC
Wire Wire Line
	1300 4100 1200 4100
Wire Wire Line
	1100 4000 1200 4000
Wire Wire Line
	1200 4000 1200 4100
Connection ~ 1200 4100
Wire Wire Line
	1200 4100 1100 4100
Text GLabel 1100 4300 0    50   Input ~ 0
DRIVER1A
Text GLabel 1100 4400 0    50   Input ~ 0
DRIVER2A
Text GLabel 1100 4500 0    50   Input ~ 0
DRIVER3A
Text GLabel 1100 4600 0    50   Input ~ 0
DRIVER4A
Text GLabel 1100 2950 0    50   Input ~ 0
DRIVER1B
Text GLabel 1100 3050 0    50   Input ~ 0
DRIVER2B
Text GLabel 1100 3150 0    50   Input ~ 0
DRIVER3B
Text GLabel 1100 3250 0    50   Input ~ 0
DRIVER4B
Wire Wire Line
	1100 2950 1300 2950
Wire Wire Line
	1100 3050 1300 3050
Wire Wire Line
	1100 3150 1300 3150
Wire Wire Line
	1100 3250 1300 3250
Wire Wire Line
	1100 4300 1300 4300
Wire Wire Line
	1100 4400 1300 4400
Wire Wire Line
	1100 4500 1300 4500
Wire Wire Line
	1100 4600 1300 4600
$Comp
L power:GNDD #PWR?
U 1 1 6333684C
P 1200 4750
AR Path="/6333684C" Ref="#PWR?"  Part="1" 
AR Path="/633CFED4/6333684C" Ref="#PWR0122"  Part="1" 
F 0 "#PWR0122" H 1200 4500 50  0001 C CNN
F 1 "GNDD" H 1204 4595 50  0000 C CNN
F 2 "" H 1200 4750 50  0001 C CNN
F 3 "" H 1200 4750 50  0001 C CNN
	1    1200 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	1200 4200 1300 4200
Wire Wire Line
	1200 4200 1200 4750
$Comp
L power:GNDD #PWR?
U 1 1 6334359A
P 1200 3400
AR Path="/6334359A" Ref="#PWR?"  Part="1" 
AR Path="/633CFED4/6334359A" Ref="#PWR0123"  Part="1" 
F 0 "#PWR0123" H 1200 3150 50  0001 C CNN
F 1 "GNDD" H 1204 3245 50  0000 C CNN
F 2 "" H 1200 3400 50  0001 C CNN
F 3 "" H 1200 3400 50  0001 C CNN
	1    1200 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	1200 2850 1200 3400
Wire Wire Line
	1300 2850 1200 2850
Text GLabel 1100 2750 0    50   Input ~ 0
5VA
Text GLabel 1100 2650 0    50   Input ~ 0
DCDC
Wire Wire Line
	1300 2750 1200 2750
Wire Wire Line
	1100 2650 1200 2650
Wire Wire Line
	1200 2650 1200 2750
Connection ~ 1200 2750
Wire Wire Line
	1200 2750 1100 2750
$Comp
L Device:R R?
U 1 1 6335FE74
P 4100 4150
AR Path="/6335FE74" Ref="R?"  Part="1" 
AR Path="/633CFED4/6335FE74" Ref="R24"  Part="1" 
F 0 "R24" V 3900 4100 50  0000 L CNN
F 1 "20K" V 4000 4050 50  0000 L CNN
F 2 "Resistor_SMD:R_0201_0603Metric_Pad0.64x0.40mm_HandSolder" V 4030 4150 50  0001 C CNN
F 3 "~" H 4100 4150 50  0001 C CNN
	1    4100 4150
	0    1    1    0   
$EndComp
Wire Wire Line
	4350 4150 4250 4150
Text GLabel 4350 4150 2    50   Input ~ 0
N1-3
Wire Wire Line
	3200 3300 3050 3300
Text GLabel 3050 3300 0    50   Input ~ 0
GPIO5
Wire Wire Line
	5000 3500 4850 3500
Wire Wire Line
	5000 3600 5000 3500
$Comp
L power:GNDD #PWR?
U 1 1 63260DB7
P 5000 3600
AR Path="/63260DB7" Ref="#PWR?"  Part="1" 
AR Path="/633CFED4/63260DB7" Ref="#PWR0126"  Part="1" 
F 0 "#PWR0126" H 5000 3350 50  0001 C CNN
F 1 "GNDD" H 5004 3445 50  0000 C CNN
F 2 "" H 5000 3600 50  0001 C CNN
F 3 "" H 5000 3600 50  0001 C CNN
	1    5000 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	4400 3500 4250 3500
Connection ~ 4400 3500
Wire Wire Line
	4400 3650 4400 3500
Wire Wire Line
	4500 3650 4400 3650
Text GLabel 4500 3650 2    50   Input ~ 0
N2-4
Wire Wire Line
	4550 3500 4400 3500
Wire Wire Line
	4450 3300 4250 3300
Text GLabel 4450 3300 2    50   Input ~ 0
HV
$Comp
L Device:R R?
U 1 1 63260DA9
P 4700 3500
AR Path="/63260DA9" Ref="R?"  Part="1" 
AR Path="/633CFED4/63260DA9" Ref="R26"  Part="1" 
F 0 "R26" V 4500 3450 50  0000 L CNN
F 1 "470K" V 4600 3400 50  0000 L CNN
F 2 "Resistor_SMD:R_0201_0603Metric_Pad0.64x0.40mm_HandSolder" V 4630 3500 50  0001 C CNN
F 3 "~" H 4700 3500 50  0001 C CNN
	1    4700 3500
	0    1    1    0   
$EndComp
Wire Wire Line
	3650 3300 3500 3300
Wire Wire Line
	3500 3500 3650 3500
Wire Wire Line
	3500 3600 3500 3500
$Comp
L power:GNDD #PWR?
U 1 1 63260DA0
P 3500 3600
AR Path="/63260DA0" Ref="#PWR?"  Part="1" 
AR Path="/633CFED4/63260DA0" Ref="#PWR0127"  Part="1" 
F 0 "#PWR0127" H 3500 3350 50  0001 C CNN
F 1 "GNDD" H 3504 3445 50  0000 C CNN
F 2 "" H 3500 3600 50  0001 C CNN
F 3 "" H 3500 3600 50  0001 C CNN
	1    3500 3600
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 63260D9A
P 3350 3300
AR Path="/63260D9A" Ref="R?"  Part="1" 
AR Path="/633CFED4/63260D9A" Ref="R25"  Part="1" 
F 0 "R25" V 3150 3250 50  0000 L CNN
F 1 "100R" V 3250 3200 50  0000 L CNN
F 2 "Resistor_SMD:R_0201_0603Metric_Pad0.64x0.40mm_HandSolder" V 3280 3300 50  0001 C CNN
F 3 "~" H 3350 3300 50  0001 C CNN
	1    3350 3300
	0    1    1    0   
$EndComp
$Comp
L Isolator:TLP521-1 U9
U 1 1 63260D94
P 3950 3400
F 0 "U9" H 3950 3725 50  0000 C CNN
F 1 "TLP627-1" H 3950 3634 50  0000 C CNN
F 2 "Package_SO:SOP-4_3.8x4.1mm_P2.54mm" H 3950 3600 50  0001 C CNN
F 3 "" H 3950 3600 50  0001 C CNN
	1    3950 3400
	-1   0    0    -1  
$EndComp
Wire Wire Line
	3200 2550 3050 2550
Text GLabel 3050 2550 0    50   Input ~ 0
GPIO4
Wire Wire Line
	5000 2750 4850 2750
Wire Wire Line
	5000 2850 5000 2750
$Comp
L power:GNDD #PWR?
U 1 1 6324AB14
P 5000 2850
AR Path="/6324AB14" Ref="#PWR?"  Part="1" 
AR Path="/633CFED4/6324AB14" Ref="#PWR0128"  Part="1" 
F 0 "#PWR0128" H 5000 2600 50  0001 C CNN
F 1 "GNDD" H 5004 2695 50  0000 C CNN
F 2 "" H 5000 2850 50  0001 C CNN
F 3 "" H 5000 2850 50  0001 C CNN
	1    5000 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	4400 2750 4250 2750
Connection ~ 4400 2750
Wire Wire Line
	4400 2900 4400 2750
Wire Wire Line
	4500 2900 4400 2900
Text GLabel 4500 2900 2    50   Input ~ 0
N1-3
Wire Wire Line
	4550 2750 4400 2750
Wire Wire Line
	4450 2550 4250 2550
Text GLabel 4450 2550 2    50   Input ~ 0
HV
$Comp
L Device:R R?
U 1 1 632405BD
P 4700 2750
AR Path="/632405BD" Ref="R?"  Part="1" 
AR Path="/633CFED4/632405BD" Ref="R23"  Part="1" 
F 0 "R23" V 4500 2700 50  0000 L CNN
F 1 "470K" V 4600 2650 50  0000 L CNN
F 2 "Resistor_SMD:R_0201_0603Metric_Pad0.64x0.40mm_HandSolder" V 4630 2750 50  0001 C CNN
F 3 "~" H 4700 2750 50  0001 C CNN
	1    4700 2750
	0    1    1    0   
$EndComp
Wire Wire Line
	3650 2550 3500 2550
Wire Wire Line
	3500 2750 3650 2750
Wire Wire Line
	3500 2850 3500 2750
$Comp
L power:GNDD #PWR?
U 1 1 63239F11
P 3500 2850
AR Path="/63239F11" Ref="#PWR?"  Part="1" 
AR Path="/633CFED4/63239F11" Ref="#PWR0129"  Part="1" 
F 0 "#PWR0129" H 3500 2600 50  0001 C CNN
F 1 "GNDD" H 3504 2695 50  0000 C CNN
F 2 "" H 3500 2850 50  0001 C CNN
F 3 "" H 3500 2850 50  0001 C CNN
	1    3500 2850
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 63238ACF
P 3350 2550
AR Path="/63238ACF" Ref="R?"  Part="1" 
AR Path="/633CFED4/63238ACF" Ref="R22"  Part="1" 
F 0 "R22" V 3150 2500 50  0000 L CNN
F 1 "100R" V 3250 2450 50  0000 L CNN
F 2 "Resistor_SMD:R_0201_0603Metric_Pad0.64x0.40mm_HandSolder" V 3280 2550 50  0001 C CNN
F 3 "~" H 3350 2550 50  0001 C CNN
	1    3350 2550
	0    1    1    0   
$EndComp
$Comp
L Isolator:TLP521-1 U8
U 1 1 631E036D
P 3950 2650
F 0 "U8" H 3950 2975 50  0000 C CNN
F 1 "TLP627-1" H 3950 2884 50  0000 C CNN
F 2 "Package_SO:SOP-4_3.8x4.1mm_P2.54mm" H 3950 2850 50  0001 C CNN
F 3 "" H 3950 2850 50  0001 C CNN
	1    3950 2650
	-1   0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 6338A835
P 4100 4400
AR Path="/6338A835" Ref="R?"  Part="1" 
AR Path="/633CFED4/6338A835" Ref="R27"  Part="1" 
F 0 "R27" V 3900 4350 50  0000 L CNN
F 1 "20K" V 4000 4300 50  0000 L CNN
F 2 "Resistor_SMD:R_0201_0603Metric_Pad0.64x0.40mm_HandSolder" V 4030 4400 50  0001 C CNN
F 3 "~" H 4100 4400 50  0001 C CNN
	1    4100 4400
	0    1    1    0   
$EndComp
Wire Wire Line
	4350 4400 4250 4400
Text GLabel 4350 4400 2    50   Input ~ 0
N1-3
Wire Wire Line
	3950 4400 3850 4400
$Comp
L Device:R R?
U 1 1 63392896
P 4100 4650
AR Path="/63392896" Ref="R?"  Part="1" 
AR Path="/633CFED4/63392896" Ref="R28"  Part="1" 
F 0 "R28" V 3900 4600 50  0000 L CNN
F 1 "20K" V 4000 4550 50  0000 L CNN
F 2 "Resistor_SMD:R_0201_0603Metric_Pad0.64x0.40mm_HandSolder" V 4030 4650 50  0001 C CNN
F 3 "~" H 4100 4650 50  0001 C CNN
	1    4100 4650
	0    1    1    0   
$EndComp
Wire Wire Line
	4350 4650 4250 4650
Text GLabel 4350 4650 2    50   Input ~ 0
N2-4
Wire Wire Line
	3950 4650 3850 4650
$Comp
L Device:R R?
U 1 1 6339289F
P 4100 4900
AR Path="/6339289F" Ref="R?"  Part="1" 
AR Path="/633CFED4/6339289F" Ref="R29"  Part="1" 
F 0 "R29" V 3900 4850 50  0000 L CNN
F 1 "20K" V 4000 4800 50  0000 L CNN
F 2 "Resistor_SMD:R_0201_0603Metric_Pad0.64x0.40mm_HandSolder" V 4030 4900 50  0001 C CNN
F 3 "~" H 4100 4900 50  0001 C CNN
	1    4100 4900
	0    1    1    0   
$EndComp
Wire Wire Line
	4350 4900 4250 4900
Text GLabel 4350 4900 2    50   Input ~ 0
N2-4
Wire Wire Line
	3950 4900 3850 4900
$Comp
L Connector:Conn_01x01_Female J6
U 1 1 642BD1EB
P 3650 4150
F 0 "J6" H 3542 3925 50  0000 C CNN
F 1 "Conn_01x01_Female" H 3542 4016 50  0000 C CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 3650 4150 50  0001 C CNN
F 3 "~" H 3650 4150 50  0001 C CNN
	1    3650 4150
	-1   0    0    1   
$EndComp
Wire Wire Line
	3950 4150 3850 4150
$Comp
L Connector:Conn_01x01_Female J7
U 1 1 642C2A26
P 3650 4400
F 0 "J7" H 3542 4175 50  0000 C CNN
F 1 "Conn_01x01_Female" H 3542 4266 50  0000 C CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 3650 4400 50  0001 C CNN
F 3 "~" H 3650 4400 50  0001 C CNN
	1    3650 4400
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Female J8
U 1 1 642C357C
P 3650 4650
F 0 "J8" H 3542 4425 50  0000 C CNN
F 1 "Conn_01x01_Female" H 3542 4516 50  0000 C CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 3650 4650 50  0001 C CNN
F 3 "~" H 3650 4650 50  0001 C CNN
	1    3650 4650
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Female J9
U 1 1 642C3EF6
P 3650 4900
F 0 "J9" H 3542 4675 50  0000 C CNN
F 1 "Conn_01x01_Female" H 3542 4766 50  0000 C CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x01_P2.00mm_Vertical" H 3650 4900 50  0001 C CNN
F 3 "~" H 3650 4900 50  0001 C CNN
	1    3650 4900
	-1   0    0    1   
$EndComp
Text GLabel 2300 2550 2    50   Input ~ 0
N1_0
Wire Wire Line
	2300 2550 2200 2550
Text GLabel 2300 2650 2    50   Input ~ 0
N1_1
Wire Wire Line
	2300 2650 2200 2650
Text GLabel 2300 2750 2    50   Input ~ 0
N1_2
Wire Wire Line
	2300 2750 2200 2750
Text GLabel 2300 2850 2    50   Input ~ 0
N1_3
Wire Wire Line
	2300 2850 2200 2850
Text GLabel 2300 2950 2    50   Input ~ 0
N1_4
Wire Wire Line
	2300 2950 2200 2950
Text GLabel 2300 3050 2    50   Input ~ 0
N1_5
Wire Wire Line
	2300 3050 2200 3050
Text GLabel 2300 3150 2    50   Input ~ 0
N1_6
Wire Wire Line
	2300 3150 2200 3150
Text GLabel 2300 3250 2    50   Input ~ 0
N1_7
Wire Wire Line
	2300 3250 2200 3250
Text GLabel 2300 3350 2    50   Input ~ 0
N1_8
Wire Wire Line
	2300 3350 2200 3350
Text GLabel 2300 3450 2    50   Input ~ 0
N1_9
Wire Wire Line
	2300 3450 2200 3450
Text GLabel 2300 3900 2    50   Input ~ 0
N2_0
Wire Wire Line
	2300 3900 2200 3900
Text GLabel 2300 4000 2    50   Input ~ 0
N2_1
Wire Wire Line
	2300 4000 2200 4000
Text GLabel 2300 4100 2    50   Input ~ 0
N2_2
Wire Wire Line
	2300 4100 2200 4100
Text GLabel 2300 4200 2    50   Input ~ 0
N2_3
Wire Wire Line
	2300 4200 2200 4200
Text GLabel 2300 4300 2    50   Input ~ 0
N2_4
Wire Wire Line
	2300 4300 2200 4300
Text GLabel 2300 4400 2    50   Input ~ 0
N2_5
Wire Wire Line
	2300 4400 2200 4400
Text GLabel 2300 4500 2    50   Input ~ 0
N2_6
Wire Wire Line
	2300 4500 2200 4500
Text GLabel 2300 4600 2    50   Input ~ 0
N2_7
Wire Wire Line
	2300 4600 2200 4600
Text GLabel 2300 4700 2    50   Input ~ 0
N2_8
Wire Wire Line
	2300 4700 2200 4700
Text GLabel 2300 4800 2    50   Input ~ 0
N2_9
Wire Wire Line
	2300 4800 2200 4800
$Comp
L nixies-us:IN-16 N3
U 1 1 6321C99F
P 2850 1500
F 0 "N3" H 2900 2345 45  0000 C CNN
F 1 "IN-16" H 2850 1500 45  0001 L BNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_2x06_P2.00mm_Vertical" H 2880 1650 20  0001 C CNN
F 3 "" H 2850 1500 50  0001 C CNN
	1    2850 1500
	1    0    0    -1  
$EndComp
$Comp
L nixies-us:IN-16 N1
U 1 1 631DE4D3
P 1400 1450
F 0 "N1" H 1450 2295 45  0000 C CNN
F 1 "IN-16" H 1400 1450 45  0001 L BNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_2x06_P2.00mm_Vertical" H 1430 1600 20  0001 C CNN
F 3 "" H 1400 1450 50  0001 C CNN
	1    1400 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	1900 1450 1800 1450
Text GLabel 1900 1450 2    50   Input ~ 0
N1-3
Wire Wire Line
	3350 1500 3250 1500
Text GLabel 3350 1500 2    50   Input ~ 0
N1-3
Wire Wire Line
	4800 1500 4700 1500
Text GLabel 4800 1500 2    50   Input ~ 0
N2-4
Wire Wire Line
	6250 1500 6150 1500
Text GLabel 6250 1500 2    50   Input ~ 0
N2-4
Text GLabel 1000 1850 0    50   Input ~ 0
N1_0
Wire Wire Line
	1000 1850 1100 1850
Text GLabel 1000 950  0    50   Input ~ 0
N1_1
Wire Wire Line
	1000 950  1100 950 
Text GLabel 1000 1050 0    50   Input ~ 0
N1_2
Wire Wire Line
	1000 1050 1100 1050
Text GLabel 1000 1150 0    50   Input ~ 0
N1_3
Wire Wire Line
	1000 1150 1100 1150
Text GLabel 1000 1250 0    50   Input ~ 0
N1_4
Wire Wire Line
	1000 1250 1100 1250
Text GLabel 1000 1350 0    50   Input ~ 0
N1_5
Wire Wire Line
	1000 1350 1100 1350
Text GLabel 1000 1450 0    50   Input ~ 0
N1_6
Wire Wire Line
	1000 1450 1100 1450
Text GLabel 1000 1550 0    50   Input ~ 0
N1_7
Wire Wire Line
	1000 1550 1100 1550
Text GLabel 1000 1650 0    50   Input ~ 0
N1_8
Wire Wire Line
	1000 1650 1100 1650
Text GLabel 1000 1750 0    50   Input ~ 0
N1_9
Wire Wire Line
	1000 1750 1100 1750
Text GLabel 2450 1900 0    50   Input ~ 0
N1_0
Wire Wire Line
	2450 1900 2550 1900
Text GLabel 2450 1000 0    50   Input ~ 0
N1_1
Wire Wire Line
	2450 1000 2550 1000
Text GLabel 2450 1100 0    50   Input ~ 0
N1_2
Wire Wire Line
	2450 1100 2550 1100
Text GLabel 2450 1200 0    50   Input ~ 0
N1_3
Wire Wire Line
	2450 1200 2550 1200
Text GLabel 2450 1300 0    50   Input ~ 0
N1_4
Wire Wire Line
	2450 1300 2550 1300
Text GLabel 2450 1400 0    50   Input ~ 0
N1_5
Wire Wire Line
	2450 1400 2550 1400
Text GLabel 2450 1500 0    50   Input ~ 0
N1_6
Wire Wire Line
	2450 1500 2550 1500
Text GLabel 2450 1600 0    50   Input ~ 0
N1_7
Wire Wire Line
	2450 1600 2550 1600
Text GLabel 2450 1700 0    50   Input ~ 0
N1_8
Wire Wire Line
	2450 1700 2550 1700
Text GLabel 2450 1800 0    50   Input ~ 0
N1_9
Wire Wire Line
	2450 1800 2550 1800
Text GLabel 3900 1900 0    50   Input ~ 0
N2_0
Wire Wire Line
	3900 1900 4000 1900
Text GLabel 3900 1000 0    50   Input ~ 0
N2_1
Wire Wire Line
	3900 1000 4000 1000
Text GLabel 3900 1100 0    50   Input ~ 0
N2_2
Wire Wire Line
	3900 1100 4000 1100
Text GLabel 3900 1200 0    50   Input ~ 0
N2_3
Wire Wire Line
	3900 1200 4000 1200
Text GLabel 3900 1300 0    50   Input ~ 0
N2_4
Wire Wire Line
	3900 1300 4000 1300
Text GLabel 3900 1400 0    50   Input ~ 0
N2_5
Wire Wire Line
	3900 1400 4000 1400
Text GLabel 3900 1500 0    50   Input ~ 0
N2_6
Wire Wire Line
	3900 1500 4000 1500
Text GLabel 3900 1600 0    50   Input ~ 0
N2_7
Wire Wire Line
	3900 1600 4000 1600
Text GLabel 3900 1700 0    50   Input ~ 0
N2_8
Wire Wire Line
	3900 1700 4000 1700
Text GLabel 3900 1800 0    50   Input ~ 0
N2_9
Wire Wire Line
	3900 1800 4000 1800
Text GLabel 5350 1900 0    50   Input ~ 0
N2_0
Wire Wire Line
	5350 1900 5450 1900
Text GLabel 5350 1000 0    50   Input ~ 0
N2_1
Wire Wire Line
	5350 1000 5450 1000
Text GLabel 5350 1100 0    50   Input ~ 0
N2_2
Wire Wire Line
	5350 1100 5450 1100
Text GLabel 5350 1200 0    50   Input ~ 0
N2_3
Wire Wire Line
	5350 1200 5450 1200
Text GLabel 5350 1300 0    50   Input ~ 0
N2_4
Wire Wire Line
	5350 1300 5450 1300
Text GLabel 5350 1400 0    50   Input ~ 0
N2_5
Wire Wire Line
	5350 1400 5450 1400
Text GLabel 5350 1500 0    50   Input ~ 0
N2_6
Wire Wire Line
	5350 1500 5450 1500
Text GLabel 5350 1600 0    50   Input ~ 0
N2_7
Wire Wire Line
	5350 1600 5450 1600
Text GLabel 5350 1700 0    50   Input ~ 0
N2_8
Wire Wire Line
	5350 1700 5450 1700
Text GLabel 5350 1800 0    50   Input ~ 0
N2_9
Wire Wire Line
	5350 1800 5450 1800
Text GLabel 1350 5900 2    50   Input ~ 0
DRIVER1B
Text GLabel 1350 6000 2    50   Input ~ 0
DRIVER2B
Text GLabel 1350 6100 2    50   Input ~ 0
DRIVER3B
Text GLabel 1350 6200 2    50   Input ~ 0
DRIVER4B
Wire Wire Line
	1350 5900 1150 5900
Wire Wire Line
	1350 6000 1150 6000
Wire Wire Line
	1350 6100 1150 6100
Wire Wire Line
	1350 6200 1150 6200
Text GLabel 1350 5500 2    50   Input ~ 0
DRIVER1A
Text GLabel 1350 5600 2    50   Input ~ 0
DRIVER2A
Text GLabel 1350 5700 2    50   Input ~ 0
DRIVER3A
Text GLabel 1350 5800 2    50   Input ~ 0
DRIVER4A
Wire Wire Line
	1350 5500 1150 5500
Wire Wire Line
	1350 5600 1150 5600
Wire Wire Line
	1350 5700 1150 5700
Wire Wire Line
	1350 5800 1150 5800
Text GLabel 1350 6300 2    50   Input ~ 0
5VA
Text GLabel 1650 6300 2    50   Input ~ 0
DCDC
Wire Wire Line
	1150 6300 1250 6300
Wire Wire Line
	1650 6300 1550 6300
Connection ~ 1250 6300
Wire Wire Line
	1250 6300 1350 6300
$Comp
L power:GNDD #PWR?
U 1 1 64657549
P 1250 6800
AR Path="/64657549" Ref="#PWR?"  Part="1" 
AR Path="/633CFED4/64657549" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 1250 6550 50  0001 C CNN
F 1 "GNDD" H 1254 6645 50  0000 C CNN
F 2 "" H 1250 6800 50  0001 C CNN
F 3 "" H 1250 6800 50  0001 C CNN
	1    1250 6800
	1    0    0    -1  
$EndComp
Wire Wire Line
	1250 6800 1250 6700
Wire Wire Line
	1250 6700 1150 6700
Wire Wire Line
	1550 6300 1550 6350
Wire Wire Line
	1550 6350 1250 6350
Wire Wire Line
	1250 6350 1250 6300
Text GLabel 1350 6500 2    50   Input ~ 0
GPIO5
Text GLabel 1350 6400 2    50   Input ~ 0
GPIO4
Wire Wire Line
	1150 6400 1350 6400
Wire Wire Line
	1150 6500 1350 6500
$Comp
L MCU_Module:DC-DC U?
U 1 1 646B4CA4
P 3700 5750
AR Path="/646B4CA4" Ref="U?"  Part="1" 
AR Path="/633CFED4/646B4CA4" Ref="U?"  Part="1" 
F 0 "U?" H 3700 6075 50  0000 C CNN
F 1 "DC-DC 170V" H 3700 5984 50  0000 C CNN
F 2 "Converter_DCDC:DCDC_2.5V_170V" H 3700 5750 50  0001 C CNN
F 3 "" H 3700 5750 50  0001 C CNN
	1    3700 5750
	1    0    0    -1  
$EndComp
$Comp
L Connector:TestPoint TP?
U 1 1 646B4CAA
P 4300 5400
AR Path="/646B4CAA" Ref="TP?"  Part="1" 
AR Path="/633CFED4/646B4CAA" Ref="TP?"  Part="1" 
F 0 "TP?" H 4358 5518 50  0000 L CNN
F 1 "170V" H 4358 5427 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_1.5x1.5mm" H 4500 5400 50  0001 C CNN
F 3 "~" H 4500 5400 50  0001 C CNN
	1    4300 5400
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 5400 4300 5650
Wire Wire Line
	4300 5650 4150 5650
$Comp
L power:GNDD #PWR?
U 1 1 646B4CB2
P 4300 6100
AR Path="/646B4CB2" Ref="#PWR?"  Part="1" 
AR Path="/633CFED4/646B4CB2" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 4300 5850 50  0001 C CNN
F 1 "GNDD" H 4304 5945 50  0000 C CNN
F 2 "" H 4300 6100 50  0001 C CNN
F 3 "" H 4300 6100 50  0001 C CNN
	1    4300 6100
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 5850 4150 5850
Wire Wire Line
	4300 5850 4300 6100
Text GLabel 4400 5650 2    50   Input ~ 0
HV
Wire Wire Line
	4400 5650 4300 5650
Connection ~ 4300 5650
Text GLabel 3050 5650 0    50   Input ~ 0
5VA
Text GLabel 3050 5550 0    50   Input ~ 0
DCDC
Wire Wire Line
	3050 5650 3150 5650
Wire Wire Line
	3150 5650 3150 5550
Wire Wire Line
	3150 5550 3050 5550
Connection ~ 3150 5650
Wire Wire Line
	3150 5650 3250 5650
$Comp
L power:GNDD #PWR?
U 1 1 646B4CC4
P 3150 6100
AR Path="/646B4CC4" Ref="#PWR?"  Part="1" 
AR Path="/633CFED4/646B4CC4" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 3150 5850 50  0001 C CNN
F 1 "GNDD" H 3154 5945 50  0000 C CNN
F 2 "" H 3150 6100 50  0001 C CNN
F 3 "" H 3150 6100 50  0001 C CNN
	1    3150 6100
	1    0    0    -1  
$EndComp
Wire Wire Line
	3150 5850 3150 6100
Wire Wire Line
	3250 5850 3150 5850
$Comp
L Connector:Conn_01x13_Female J?
U 1 1 646DCFEE
P 950 6100
F 0 "J?" H 842 6885 50  0000 C CNN
F 1 "Conn_01x13_Female" H 842 6794 50  0000 C CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x13_P2.00mm_Vertical" H 950 6100 50  0001 C CNN
F 3 "~" H 950 6100 50  0001 C CNN
	1    950  6100
	-1   0    0    -1  
$EndComp
Text GLabel 1350 6600 2    50   Input ~ 0
5VD
Wire Wire Line
	1150 6600 1350 6600
$Comp
L MCU_Module:DC-DC U?
U 1 1 64766D27
P 3700 6950
AR Path="/64766D27" Ref="U?"  Part="1" 
AR Path="/633CFED4/64766D27" Ref="U?"  Part="1" 
F 0 "U?" H 3700 7275 50  0000 C CNN
F 1 "DC-DC 5V" H 3700 7184 50  0000 C CNN
F 2 "Converter_DCDC:DCDC_2V~5V" H 3700 6950 50  0001 C CNN
F 3 "" H 3700 6950 50  0001 C CNN
	1    3700 6950
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C?
U 1 1 64766D2D
P 2850 6950
AR Path="/64766D2D" Ref="C?"  Part="1" 
AR Path="/633CFED4/64766D2D" Ref="C?"  Part="1" 
F 0 "C?" H 2968 6996 50  0000 L CNN
F 1 "10uF" H 2968 6905 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 2888 6800 50  0001 C CNN
F 3 "~" H 2850 6950 50  0001 C CNN
	1    2850 6950
	1    0    0    -1  
$EndComp
Wire Wire Line
	3250 6850 3150 6850
Wire Wire Line
	3150 6850 3150 6700
Wire Wire Line
	3150 6700 2850 6700
Wire Wire Line
	2850 6700 2850 6800
Wire Wire Line
	2850 7100 2850 7200
Wire Wire Line
	2850 7200 3150 7200
Wire Wire Line
	3150 7200 3150 7050
Wire Wire Line
	3150 7050 3250 7050
$Comp
L Device:R R?
U 1 1 64766D3B
P 2600 6700
AR Path="/64766D3B" Ref="R?"  Part="1" 
AR Path="/633CFED4/64766D3B" Ref="R?"  Part="1" 
F 0 "R?" V 2400 6650 50  0000 L CNN
F 1 "4K7" V 2500 6600 50  0000 L CNN
F 2 "Resistor_SMD:R_0201_0603Metric_Pad0.64x0.40mm_HandSolder" V 2530 6700 50  0001 C CNN
F 3 "~" H 2600 6700 50  0001 C CNN
	1    2600 6700
	0    1    1    0   
$EndComp
Wire Wire Line
	2750 6700 2850 6700
Connection ~ 2850 6700
$Comp
L power:GNDD #PWR?
U 1 1 64766D43
P 4300 7300
AR Path="/64766D43" Ref="#PWR?"  Part="1" 
AR Path="/633CFED4/64766D43" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 4300 7050 50  0001 C CNN
F 1 "GNDD" H 4304 7145 50  0000 C CNN
F 2 "" H 4300 7300 50  0001 C CNN
F 3 "" H 4300 7300 50  0001 C CNN
	1    4300 7300
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 7050 4150 7050
Wire Wire Line
	4300 7050 4300 7300
$Comp
L power:GNDD #PWR?
U 1 1 64766D4B
P 3150 7300
AR Path="/64766D4B" Ref="#PWR?"  Part="1" 
AR Path="/633CFED4/64766D4B" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 3150 7050 50  0001 C CNN
F 1 "GNDD" H 3154 7145 50  0000 C CNN
F 2 "" H 3150 7300 50  0001 C CNN
F 3 "" H 3150 7300 50  0001 C CNN
	1    3150 7300
	1    0    0    -1  
$EndComp
Wire Wire Line
	3150 7300 3150 7200
Connection ~ 3150 7200
Text GLabel 4400 6850 2    50   Input ~ 0
5VD
$Comp
L Connector:TestPoint TP?
U 1 1 64766D54
P 4300 6600
AR Path="/64766D54" Ref="TP?"  Part="1" 
AR Path="/633CFED4/64766D54" Ref="TP?"  Part="1" 
F 0 "TP?" H 4358 6718 50  0000 L CNN
F 1 "5VD" H 4358 6627 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_1.5x1.5mm" H 4500 6600 50  0001 C CNN
F 3 "~" H 4500 6600 50  0001 C CNN
	1    4300 6600
	1    0    0    -1  
$EndComp
Wire Wire Line
	4400 6850 4300 6850
Wire Wire Line
	4300 6600 4300 6850
Connection ~ 4300 6850
Wire Wire Line
	4300 6850 4150 6850
Wire Wire Line
	2450 6700 2300 6700
Text GLabel 2300 6700 0    50   Input ~ 0
DCDC
$EndSCHEMATC
