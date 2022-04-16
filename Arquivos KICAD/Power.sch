EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 5
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
L Connector:Conn_01x02_Female J?
U 1 1 62283BC5
P 10600 900
AR Path="/62283BC5" Ref="J?"  Part="1" 
AR Path="/67F05B40/62283BC5" Ref="J11"  Part="1" 
F 0 "J11" H 10650 850 50  0000 C CNN
F 1 "CRYSTAL" H 10700 700 50  0000 C CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x02_P2.00mm_Vertical" H 10600 900 50  0001 C CNN
F 3 "~" H 10600 900 50  0001 C CNN
	1    10600 900 
	1    0    0    1   
$EndComp
Wire Wire Line
	1650 2200 1750 2200
$Comp
L Connector:Conn_01x02_Female J?
U 1 1 61D80C28
P 950 2200
AR Path="/61D80C28" Ref="J?"  Part="1" 
AR Path="/67F05B40/61D80C28" Ref="J13"  Part="1" 
F 0 "J13" H 978 2176 50  0000 L CNN
F 1 "BAT_IN" H 1000 2100 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x02_P2.00mm_Vertical" H 950 2200 50  0001 C CNN
F 3 "~" H 950 2200 50  0001 C CNN
	1    950  2200
	-1   0    0    -1  
$EndComp
Text GLabel 1550 650  0    50   Input ~ 0
5VA
Wire Wire Line
	2300 650  2300 750 
Wire Wire Line
	3600 1700 3600 1650
$Comp
L Device:R R?
U 1 1 61D80C32
P 2950 1150
AR Path="/61D80C32" Ref="R?"  Part="1" 
AR Path="/67F05B40/61D80C32" Ref="R36"  Part="1" 
F 0 "R36" V 3050 1050 50  0000 C CNN
F 1 "1K" V 3050 1200 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2880 1150 50  0001 C CNN
F 3 "~" H 2950 1150 50  0001 C CNN
	1    2950 1150
	0    1    -1   0   
$EndComp
$Comp
L Device:LED D?
U 1 1 61D80C38
P 3150 950
AR Path="/61D80C38" Ref="D?"  Part="1" 
AR Path="/67F05B40/61D80C38" Ref="D7"  Part="1" 
F 0 "D7" V 3250 900 50  0000 R CNN
F 1 "GREEN" H 3150 800 50  0000 R CNN
F 2 "LED_SMD:LED_1206_3216Metric" H 3150 950 50  0001 C CNN
F 3 "~" H 3150 950 50  0001 C CNN
	1    3150 950 
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3100 1150 3150 1150
Wire Wire Line
	3150 1150 3150 1100
Wire Wire Line
	3150 800  3150 650 
Wire Wire Line
	2800 1150 2700 1150
$Comp
L Device:R R?
U 1 1 61D80C48
P 2950 1300
AR Path="/61D80C48" Ref="R?"  Part="1" 
AR Path="/67F05B40/61D80C48" Ref="R37"  Part="1" 
F 0 "R37" V 2850 1200 50  0000 C CNN
F 1 "1K" V 2850 1350 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2880 1300 50  0001 C CNN
F 3 "~" H 2950 1300 50  0001 C CNN
	1    2950 1300
	0    1    -1   0   
$EndComp
Wire Wire Line
	2800 1300 2700 1300
$Comp
L Device:LED D?
U 1 1 61D80C4F
P 3400 950
AR Path="/61D80C4F" Ref="D?"  Part="1" 
AR Path="/67F05B40/61D80C4F" Ref="D8"  Part="1" 
F 0 "D8" V 3500 900 50  0000 R CNN
F 1 "RED" H 3300 800 50  0000 R CNN
F 2 "LED_SMD:LED_1206_3216Metric" H 3400 950 50  0001 C CNN
F 3 "~" H 3400 950 50  0001 C CNN
	1    3400 950 
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3400 1300 3400 1100
Wire Wire Line
	3400 800  3400 650 
Wire Wire Line
	1750 1150 1900 1150
Text Notes 700  1750 0    50   ~ 0
10K - 130mA\n5K - 250mA\n4K - 300mA\n3K - 400mA\n2K - 580mA\n1.66K - 690mA\n1.5K - 780mA\n1.33K - 900mA\n1.2K - 1A\n\n
Wire Wire Line
	1900 1000 1800 1000
Wire Wire Line
	1800 1000 1800 1650
Wire Wire Line
	1800 1650 2300 1650
Connection ~ 2300 1650
Wire Wire Line
	2300 1650 2300 1550
Wire Wire Line
	1450 1150 1400 1150
Connection ~ 1800 1650
$Comp
L Device:CP C?
U 1 1 61D80C6B
P 3900 1100
AR Path="/61D80C6B" Ref="C?"  Part="1" 
AR Path="/67AE4A42/61D80C6B" Ref="C?"  Part="1" 
AR Path="/67E43E22/61D80C6B" Ref="C?"  Part="1" 
AR Path="/67F05B40/61D80C6B" Ref="C10"  Part="1" 
F 0 "C10" H 3950 1200 50  0000 L CNN
F 1 "10uF" H 3950 1000 50  0000 L CNN
F 2 "Capacitor_SMD:C_1806_4516Metric" H 3938 950 50  0001 C CNN
F 3 "~" H 3900 1100 50  0001 C CNN
	1    3900 1100
	1    0    0    -1  
$EndComp
Wire Wire Line
	3900 650  3900 950 
Text GLabel 1700 1300 0    50   Input ~ 0
BAT
Wire Wire Line
	1700 1300 1900 1300
Text GLabel 3800 3300 0    50   Input ~ 0
BAT
$Comp
L Device:CP C?
U 1 1 61D80C7A
P 3900 2850
AR Path="/61D80C7A" Ref="C?"  Part="1" 
AR Path="/67AE4A42/61D80C7A" Ref="C?"  Part="1" 
AR Path="/67E43E22/61D80C7A" Ref="C?"  Part="1" 
AR Path="/67F05B40/61D80C7A" Ref="C12"  Part="1" 
F 0 "C12" H 3950 2950 50  0000 L CNN
F 1 "10uF" H 3950 2750 50  0000 L CNN
F 2 "Capacitor_SMD:C_1806_4516Metric" H 3938 2700 50  0001 C CNN
F 3 "~" H 3900 2850 50  0001 C CNN
	1    3900 2850
	1    0    0    1   
$EndComp
Wire Wire Line
	3900 3300 3900 3000
$Comp
L Battery_Management:DW01 U?
U 1 1 61D80C82
P 3050 2250
AR Path="/61D80C82" Ref="U?"  Part="1" 
AR Path="/67F05B40/61D80C82" Ref="U11"  Part="1" 
F 0 "U11" H 2900 2600 50  0000 C CNN
F 1 "DW01" H 3200 2600 50  0000 C CNN
F 2 "Package_SO:TSSOP-8_4.4x3mm_P0.65mm" H 3100 2600 50  0001 C CNN
F 3 "" H 3100 2600 50  0001 C CNN
	1    3050 2250
	-1   0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 61D80C88
P 3600 2300
AR Path="/61D80C88" Ref="R?"  Part="1" 
AR Path="/67F05B40/61D80C88" Ref="R40"  Part="1" 
F 0 "R40" V 3700 2200 50  0000 C CNN
F 1 "1K" V 3700 2350 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 3530 2300 50  0001 C CNN
F 3 "~" H 3600 2300 50  0001 C CNN
	1    3600 2300
	0    1    1    0   
$EndComp
$Comp
L Battery_Management:AM8205 U?
U 1 1 61D80C95
P 3050 3350
AR Path="/61D80C95" Ref="U?"  Part="1" 
AR Path="/67F05B40/61D80C95" Ref="U12"  Part="1" 
F 0 "U12" H 3050 3765 50  0000 C CNN
F 1 "AM8205" H 3050 3674 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23-6" H 2900 3650 50  0001 C CNN
F 3 "" H 2900 3650 50  0001 C CNN
	1    3050 3350
	-1   0    0    -1  
$EndComp
Text GLabel 3450 2200 2    50   Input ~ 0
G1
Wire Wire Line
	3450 2200 3350 2200
Text GLabel 2500 3400 0    50   Input ~ 0
G1
$Comp
L Device:C C?
U 1 1 61D80C9E
P 2350 2250
AR Path="/61D80C9E" Ref="C?"  Part="1" 
AR Path="/67F05B40/61D80C9E" Ref="C11"  Part="1" 
F 0 "C11" H 2235 2204 50  0000 R CNN
F 1 "20pF" H 2235 2295 50  0000 R CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 2388 2100 50  0001 C CNN
F 3 "~" H 2350 2250 50  0001 C CNN
	1    2350 2250
	1    0    0    1   
$EndComp
Wire Wire Line
	3050 1850 3050 1750
Wire Wire Line
	3050 1750 2350 1750
Wire Wire Line
	2350 1750 2350 2100
$Comp
L Device:R R?
U 1 1 61D80CAA
P 2050 1750
AR Path="/61D80CAA" Ref="R?"  Part="1" 
AR Path="/67F05B40/61D80CAA" Ref="R39"  Part="1" 
F 0 "R39" V 2150 1750 50  0000 C CNN
F 1 "100" V 2250 1750 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 1980 1750 50  0001 C CNN
F 3 "~" H 2050 1750 50  0001 C CNN
	1    2050 1750
	0    1    1    0   
$EndComp
Wire Wire Line
	1650 1750 1750 1750
Text GLabel 1650 1750 0    50   Input ~ 0
BAT1+
Connection ~ 1750 1750
Wire Wire Line
	1750 1750 1900 1750
Text GLabel 2650 2200 0    50   Input ~ 0
G2
Wire Wire Line
	2650 2200 2750 2200
Text GLabel 2500 3200 0    50   Input ~ 0
G2
Wire Wire Line
	3350 3300 3400 3300
Wire Wire Line
	3400 3300 3400 3550
Wire Wire Line
	2700 3300 2750 3300
Wire Wire Line
	3350 3200 3400 3200
Wire Wire Line
	1750 2300 1650 2300
Text GLabel 3600 3400 2    50   Input ~ 0
BAT1-
$Comp
L Battery_Management:TP4056 U?
U 1 1 61D80CC7
P 2300 1150
AR Path="/61D80CC7" Ref="U?"  Part="1" 
AR Path="/67F05B40/61D80CC7" Ref="U10"  Part="1" 
F 0 "U10" H 2100 1500 50  0000 C CNN
F 1 "TP4056" H 2500 1500 50  0000 C CNN
F 2 "Package_SO:SOIC-8_5.275x5.275mm_P1.27mm" H 2150 1500 50  0001 C CNN
F 3 "" H 2150 1500 50  0001 C CNN
	1    2300 1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	3600 3400 3350 3400
Wire Wire Line
	2750 3200 2500 3200
Wire Wire Line
	2700 3300 2700 3550
Wire Wire Line
	2750 3400 2500 3400
$Comp
L Device:Crystal Y?
U 1 1 61F05D71
P 9950 850
AR Path="/61F05D71" Ref="Y?"  Part="1" 
AR Path="/67F05B40/61F05D71" Ref="Y1"  Part="1" 
F 0 "Y1" V 9904 981 50  0000 L CNN
F 1 "84kHz" V 9995 981 50  0000 L CNN
F 2 "Crystal:Crystal_AT310_D3.0mm_L10.0mm_Vertical" H 9950 850 50  0001 C CNN
F 3 "~" H 9950 850 50  0001 C CNN
	1    9950 850 
	0    1    1    0   
$EndComp
Wire Wire Line
	9950 1000 9950 1100
Wire Wire Line
	9950 600  9950 700 
Wire Wire Line
	9950 600  10400 600 
Wire Wire Line
	10400 600  10400 800 
Wire Wire Line
	9950 1100 10400 1100
Wire Wire Line
	10400 1100 10400 900 
Wire Wire Line
	2200 1750 2350 1750
Connection ~ 2350 1750
Wire Wire Line
	3800 3300 3900 3300
Wire Wire Line
	3400 3550 2700 3550
Wire Wire Line
	3150 650  3400 650 
Connection ~ 3150 650 
Wire Wire Line
	3100 1300 3400 1300
Wire Wire Line
	2700 1000 2900 1000
Wire Wire Line
	2300 650  2900 650 
Wire Wire Line
	2900 650  2900 1000
Connection ~ 2900 650 
Wire Wire Line
	2900 650  3150 650 
Wire Wire Line
	1550 650  2300 650 
Connection ~ 2300 650 
Wire Wire Line
	1400 1150 1400 1650
Wire Wire Line
	1400 1650 1800 1650
Wire Wire Line
	3400 3200 3400 2850
Wire Wire Line
	3450 2300 3350 2300
Wire Wire Line
	3900 2300 3750 2300
Connection ~ 3900 1650
Wire Wire Line
	2300 1650 3600 1650
Wire Wire Line
	3400 650  3900 650 
Connection ~ 3400 650 
Wire Wire Line
	1750 2850 3400 2850
Wire Wire Line
	2350 2400 2350 2750
Wire Wire Line
	2350 2750 3050 2750
Wire Wire Line
	3050 2750 3050 2650
Wire Notes Line
	1750 1250 1750 900 
Wire Notes Line
	1750 900  650  900 
Wire Notes Line
	650  900  650  1700
Wire Notes Line
	650  1700 1450 1700
Wire Notes Line
	1450 1700 1450 1250
Wire Notes Line
	1450 1250 1750 1250
Connection ~ 3900 2300
Wire Wire Line
	3900 2300 3900 1650
Wire Wire Line
	3900 2300 3900 2700
Wire Wire Line
	1750 2300 1750 2400
Connection ~ 3600 1650
Wire Wire Line
	3600 1650 3900 1650
Wire Wire Line
	3900 1250 3900 1650
Connection ~ 1150 5550
Wire Wire Line
	1150 6250 1150 5550
Wire Wire Line
	2100 6200 2100 5950
Wire Wire Line
	5300 3900 5300 4050
$Comp
L Connector:TestPoint TP?
U 1 1 61AF9C42
P 5300 3900
AR Path="/61AF9C42" Ref="TP?"  Part="1" 
AR Path="/67F05B40/61AF9C42" Ref="TP6"  Part="1" 
F 0 "TP6" H 5358 4018 50  0000 L CNN
F 1 "HV" H 5358 3927 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_1.5x1.5mm" H 5500 3900 50  0001 C CNN
F 3 "~" H 5500 3900 50  0001 C CNN
	1    5300 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	4600 4050 4450 4050
Wire Wire Line
	4450 4450 4700 4450
Connection ~ 4700 4450
Wire Wire Line
	5300 5600 5300 5800
Wire Wire Line
	5300 5300 5300 5100
Wire Wire Line
	5000 4400 5000 4450
Wire Wire Line
	5000 4050 5300 4050
Connection ~ 5000 4050
Wire Wire Line
	5000 4100 5000 4050
Wire Wire Line
	4900 4050 5000 4050
Connection ~ 5300 4050
Wire Wire Line
	5450 4050 5300 4050
Text GLabel 5450 4050 2    50   Input ~ 0
HV
Wire Wire Line
	4050 4950 5150 4950
Wire Wire Line
	4050 6450 1450 6450
Wire Wire Line
	4050 4950 4050 6450
Wire Wire Line
	5000 4450 4700 4450
$Comp
L Device:C C?
U 1 1 61C18308
P 5000 4250
AR Path="/61C18308" Ref="C?"  Part="1" 
AR Path="/67AE4A42/61C18308" Ref="C?"  Part="1" 
AR Path="/67E43E22/61C18308" Ref="C?"  Part="1" 
AR Path="/67F05B40/61C18308" Ref="C15"  Part="1" 
F 0 "C15" H 4900 4150 50  0000 C CNN
F 1 "0.47uF 400V" H 4650 4250 50  0000 C CNN
F 2 "Capacitor_SMD:C_1210_3225Metric" H 5038 4100 50  0001 C CNN
F 3 "~" H 5000 4250 50  0001 C CNN
	1    5000 4250
	1    0    0    -1  
$EndComp
$Comp
L Simulation_SPICE:DIODE D?
U 1 1 61C18302
P 4750 4050
AR Path="/67AE4A42/61C18302" Ref="D?"  Part="1" 
AR Path="/67F05B40/61C18302" Ref="D10"  Part="1" 
F 0 "D10" H 4750 4150 50  0000 C CNN
F 1 "DIODE" H 4750 4176 50  0001 C CNN
F 2 "Diode_SMD:D_2114_3652Metric_Castellated" H 4750 4050 50  0001 C CNN
F 3 "~" H 4750 4050 50  0001 C CNN
F 4 "Y" H 4750 4050 50  0001 L CNN "Spice_Netlist_Enabled"
F 5 "D" H 4750 4050 50  0001 L CNN "Spice_Primitive"
	1    4750 4050
	1    0    0    -1  
$EndComp
Connection ~ 2750 4050
Wire Wire Line
	2100 4050 2750 4050
Wire Wire Line
	2100 4950 2100 4050
Wire Wire Line
	3250 4450 3250 4400
Connection ~ 3250 4450
Wire Wire Line
	2750 4450 3250 4450
Wire Wire Line
	2750 4400 2750 4450
Connection ~ 3250 4050
Wire Wire Line
	2750 4050 3250 4050
Wire Wire Line
	2750 4100 2750 4050
$Comp
L Device:CP C?
U 1 1 61C182F0
P 2750 4250
AR Path="/61C182F0" Ref="C?"  Part="1" 
AR Path="/67AE4A42/61C182F0" Ref="C?"  Part="1" 
AR Path="/67E43E22/61C182F0" Ref="C?"  Part="1" 
AR Path="/67F05B40/61C182F0" Ref="C13"  Part="1" 
F 0 "C13" H 2800 4350 50  0000 L CNN
F 1 "100uF" H 2800 4150 50  0000 L CNN
F 2 "Capacitor_SMD:C_1806_4516Metric" H 2788 4100 50  0001 C CNN
F 3 "~" H 2750 4250 50  0001 C CNN
	1    2750 4250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3250 4550 3250 4450
Wire Wire Line
	3500 4450 3500 5150
Wire Wire Line
	3500 4450 3650 4450
Wire Wire Line
	3250 4050 3250 4100
Wire Wire Line
	3650 4050 3250 4050
$Comp
L Device:C C?
U 1 1 61C182DF
P 3250 4250
AR Path="/61C182DF" Ref="C?"  Part="1" 
AR Path="/67AE4A42/61C182DF" Ref="C?"  Part="1" 
AR Path="/67E43E22/61C182DF" Ref="C?"  Part="1" 
AR Path="/67F05B40/61C182DF" Ref="C14"  Part="1" 
F 0 "C14" H 3350 4350 50  0000 C CNN
F 1 "100nF" H 3400 4150 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 3288 4100 50  0001 C CNN
F 3 "~" H 3250 4250 50  0001 C CNN
	1    3250 4250
	1    0    0    -1  
$EndComp
Wire Wire Line
	4700 4600 4700 4450
$Comp
L Device:Transformer_1P_1S T?
U 1 1 61C182D2
P 4050 4250
AR Path="/67AE4A42/61C182D2" Ref="T?"  Part="1" 
AR Path="/67F05B40/61C182D2" Ref="T1"  Part="1" 
F 0 "T1" H 4150 4500 50  0000 C CNN
F 1 "Transformer_1P_1S" H 4050 4550 50  0001 C CNN
F 2 "Transformer_SMD:Transformer_CEEH54_Nixie" H 4050 4250 50  0001 C CNN
F 3 "~" H 4050 4250 50  0001 C CNN
	1    4050 4250
	1    0    0    -1  
$EndComp
Connection ~ 2700 6100
Wire Wire Line
	3300 5550 3200 5550
Wire Wire Line
	3300 6100 3300 5550
Wire Wire Line
	2700 6100 3300 6100
Connection ~ 2100 4950
Wire Wire Line
	2800 4950 2100 4950
Wire Wire Line
	2800 5000 2800 4950
Wire Wire Line
	2800 5550 2600 5550
Connection ~ 2800 5550
Wire Wire Line
	2800 5300 2800 5550
Wire Wire Line
	2900 5550 2800 5550
$Comp
L Device:R R?
U 1 1 61C182BF
P 3050 5550
AR Path="/61C182BF" Ref="R?"  Part="1" 
AR Path="/67AE4A42/61C182BF" Ref="R?"  Part="1" 
AR Path="/67E43E22/61C182BF" Ref="R?"  Part="1" 
AR Path="/67F05B40/61C182BF" Ref="R45"  Part="1" 
F 0 "R45" V 3150 5550 50  0000 C CNN
F 1 "10K" V 2950 5550 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2980 5550 50  0001 C CNN
F 3 "~" H 3050 5550 50  0001 C CNN
	1    3050 5550
	0    -1   1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 61C182B9
P 2800 5150
AR Path="/61C182B9" Ref="R?"  Part="1" 
AR Path="/67AE4A42/61C182B9" Ref="R?"  Part="1" 
AR Path="/67E43E22/61C182B9" Ref="R?"  Part="1" 
AR Path="/67F05B40/61C182B9" Ref="R42"  Part="1" 
F 0 "R42" V 2900 5150 50  0000 C CNN
F 1 "1K" V 2700 5150 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2730 5150 50  0001 C CNN
F 3 "~" H 2800 5150 50  0001 C CNN
	1    2800 5150
	1    0    0    1   
$EndComp
Wire Wire Line
	2600 5350 3200 5350
Wire Wire Line
	3500 5700 3500 5550
$Comp
L Transistor_FET:BUZ11 Q?
U 1 1 61C182AB
P 3400 5350
AR Path="/67AE4A42/61C182AB" Ref="Q?"  Part="1" 
AR Path="/67F05B40/61C182AB" Ref="Q10"  Part="1" 
F 0 "Q10" H 3605 5396 50  0000 L CNN
F 1 "BUZ21" H 3605 5305 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 3650 5275 50  0001 L CIN
F 3 "https://media.digikey.com/pdf/Data%20Sheets/Fairchild%20PDFs/BUZ11.pdf" H 3400 5350 50  0001 L CNN
	1    3400 5350
	1    0    0    -1  
$EndComp
Wire Wire Line
	1150 6800 1150 6650
Wire Wire Line
	2700 5750 2600 5750
Wire Wire Line
	2700 6100 2700 5750
Wire Wire Line
	1500 6100 2700 6100
Wire Wire Line
	1150 5550 1600 5550
Wire Wire Line
	1150 5550 1150 5400
Wire Wire Line
	1150 4950 1400 4950
Connection ~ 1150 4950
Wire Wire Line
	1150 5100 1150 4950
Wire Wire Line
	850  4950 1150 4950
$Comp
L Transistor_BJT:BC547 Q?
U 1 1 61C18294
P 1250 6450
AR Path="/61C18294" Ref="Q?"  Part="1" 
AR Path="/67AE4A42/61C18294" Ref="Q?"  Part="1" 
AR Path="/67E43E22/61C18294" Ref="Q?"  Part="1" 
AR Path="/67F05B40/61C18294" Ref="Q11"  Part="1" 
F 0 "Q11" H 1441 6496 50  0000 L CNN
F 1 "BC547" H 1441 6405 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 1450 6375 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/BC550-D.pdf" H 1250 6450 50  0001 L CNN
	1    1250 6450
	-1   0    0    -1  
$EndComp
$Comp
L Projeto-Relogio-Pulso-2Displays-rescue:NE555-Timer-Projeto-Relogio-Pulso-2Displays-rescue U?
U 1 1 61C1828E
P 2100 5550
AR Path="/61C1828E" Ref="U?"  Part="1" 
AR Path="/67AE4A42/61C1828E" Ref="U?"  Part="1" 
AR Path="/67E43E22/61C1828E" Ref="U?"  Part="1" 
AR Path="/67F05B40/61C1828E" Ref="U13"  Part="1" 
F 0 "U13" H 2200 6000 50  0000 C CNN
F 1 "NE555" H 2300 5900 50  0000 C CNN
F 2 "Package_SO:SOIC-8_5.275x5.275mm_P1.27mm" H 2100 5550 50  0001 C CNN
F 3 "" H 2100 5550 50  0001 C CNN
	1    2100 5550
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 61C18288
P 1150 5250
AR Path="/61C18288" Ref="R?"  Part="1" 
AR Path="/67AE4A42/61C18288" Ref="R?"  Part="1" 
AR Path="/67E43E22/61C18288" Ref="R?"  Part="1" 
AR Path="/67F05B40/61C18288" Ref="R43"  Part="1" 
F 0 "R43" V 1250 5250 50  0000 C CNN
F 1 "33K" V 1050 5250 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 1080 5250 50  0001 C CNN
F 3 "~" H 1150 5250 50  0001 C CNN
	1    1150 5250
	1    0    0    1   
$EndComp
Wire Wire Line
	1500 5350 1600 5350
Wire Wire Line
	1500 6100 1500 5350
Wire Wire Line
	1400 5750 1400 4950
Wire Wire Line
	1600 5750 1400 5750
Connection ~ 1400 4950
Wire Wire Line
	2100 4950 2100 5150
Wire Wire Line
	1400 4950 2100 4950
Text GLabel 850  4950 0    50   Input ~ 0
5VD
$Comp
L Device:R R?
U 1 1 61C18274
P 5300 5450
AR Path="/61C18274" Ref="R?"  Part="1" 
AR Path="/67AE4A42/61C18274" Ref="R?"  Part="1" 
AR Path="/67E43E22/61C18274" Ref="R?"  Part="1" 
AR Path="/67F05B40/61C18274" Ref="R44"  Part="1" 
F 0 "R44" V 5400 5450 50  0000 C CNN
F 1 "470" V 5200 5450 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 5230 5450 50  0001 C CNN
F 3 "~" H 5300 5450 50  0001 C CNN
	1    5300 5450
	1    0    0    1   
$EndComp
Wire Wire Line
	5300 4550 5300 4800
Wire Wire Line
	5300 4250 5300 4050
$Comp
L Device:R R?
U 1 1 61C1826C
P 5300 4400
AR Path="/61C1826C" Ref="R?"  Part="1" 
AR Path="/67AE4A42/61C1826C" Ref="R?"  Part="1" 
AR Path="/67E43E22/61C1826C" Ref="R?"  Part="1" 
AR Path="/67F05B40/61C1826C" Ref="R41"  Part="1" 
F 0 "R41" V 5400 4400 50  0000 C CNN
F 1 "220K" V 5200 4400 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 5230 4400 50  0001 C CNN
F 3 "~" H 5300 4400 50  0001 C CNN
	1    5300 4400
	1    0    0    1   
$EndComp
$Comp
L Device:R_POT_US RV?
U 1 1 61C18266
P 5300 4950
AR Path="/61C18266" Ref="RV?"  Part="1" 
AR Path="/67AE4A42/61C18266" Ref="RV?"  Part="1" 
AR Path="/67E43E22/61C18266" Ref="RV?"  Part="1" 
AR Path="/67F05B40/61C18266" Ref="RV1"  Part="1" 
F 0 "RV1" H 5500 5100 50  0000 R CNN
F 1 "1k" H 5500 4850 50  0000 R CNN
F 2 "Potentiometer_THT:Potentiometer_Bourns_3339P_Vertical_HandSoldering" H 5300 4950 50  0001 C CNN
F 3 "~" H 5300 4950 50  0001 C CNN
	1    5300 4950
	-1   0    0    -1  
$EndComp
Wire Notes Line
	4200 550  4200 3600
Wire Notes Line
	4200 3600 600  3600
Wire Notes Line
	600  3600 600  550 
Wire Notes Line
	600  550  4200 550 
Text Notes 750  3200 0    50   ~ 0
Modulo de recarga com \nProteção de Sobrecorrente\n
Text Notes 700  3500 0    50   ~ 0
VERIFICAR CORRENTE RECOMENDADA!!
Wire Notes Line
	5650 3650 600  3650
Wire Notes Line
	600  3650 600  7050
Wire Notes Line
	600  7050 5650 7050
Wire Notes Line
	5650 7050 5650 3650
Text Notes 4400 6900 0    50   ~ 0
Flyback de 5V para 210Vmax\ncontrolado via 555NE\n\n\n
Text Notes 4250 7200 0    50   ~ 0
VERIFICAR EFICIENCIA ENERGÉTICA!!\n\n\n\n
Text Notes 4300 5150 0    50   ~ 0
Regulador da Saida\n\n
Wire Notes Line
	4250 5150 5450 5150
Wire Notes Line
	5450 5150 5450 4750
Wire Notes Line
	5450 4750 4950 4750
Wire Notes Line
	4950 4750 4950 4850
Wire Notes Line
	4950 4850 4250 4850
Wire Notes Line
	4250 4850 4250 5150
Wire Notes Line width 20 style dash_dot rgb(255, 255, 0)
	4050 4750 4050 3700
Wire Notes Line width 20 style dash_dot rgb(255, 255, 0)
	4050 3700 5600 3700
Wire Notes Line width 20 style dash_dot rgb(255, 255, 0)
	5600 3700 5600 6050
Wire Notes Line width 20 style dash_dot rgb(255, 255, 0)
	5600 6050 4150 6050
Wire Notes Line width 20 style dash_dot rgb(255, 255, 0)
	4150 6050 4150 4750
Wire Notes Line width 20 style dash_dot rgb(255, 255, 0)
	4150 4750 4050 4750
Text Notes 4200 6000 0    50   ~ 10
ISOLAR\n
Wire Notes Line
	9600 550  11100 550 
Wire Notes Line
	11100 550  11100 1150
Wire Notes Line
	11100 1150 9600 1150
Wire Notes Line
	9600 1150 9600 550 
Wire Wire Line
	1100 2500 1100 2650
Text GLabel 1350 2500 2    50   Input ~ 0
BAT1-
Wire Wire Line
	1350 2500 1100 2500
Text GLabel 1650 2200 0    50   Input ~ 0
IN_BAT+
Text GLabel 1650 2300 0    50   Input ~ 0
IN_BAT-
Wire Wire Line
	1250 2200 1150 2200
Wire Wire Line
	1250 2300 1150 2300
Text GLabel 8950 850  2    50   Input ~ 0
5VD
Wire Wire Line
	8950 850  8800 850 
Wire Wire Line
	8150 1250 8300 1250
Wire Wire Line
	1250 2200 1250 2100
Wire Wire Line
	1250 2300 1250 2400
Wire Wire Line
	1250 2400 1750 2400
Connection ~ 1750 2400
Wire Wire Line
	1750 2400 1750 2850
Wire Wire Line
	1250 2100 1750 2100
Connection ~ 1750 2100
Wire Wire Line
	1750 2100 1750 2200
Wire Wire Line
	1750 1750 1750 2100
$Comp
L Device:R R?
U 1 1 61D80C5A
P 1600 1150
AR Path="/61D80C5A" Ref="R?"  Part="1" 
AR Path="/67F05B40/61D80C5A" Ref="R35"  Part="1" 
F 0 "R35" V 1800 1150 50  0000 C CNN
F 1 "1.2K" V 1700 1150 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 1530 1150 50  0001 C CNN
F 3 "~" H 1600 1150 50  0001 C CNN
	1    1600 1150
	0    1    -1   0   
$EndComp
$Comp
L Device:LED D?
U 1 1 637888C3
P 10050 1450
AR Path="/637888C3" Ref="D?"  Part="1" 
AR Path="/67F05B40/637888C3" Ref="D9"  Part="1" 
F 0 "D9" V 10150 1400 50  0000 R CNN
F 1 "RED" H 9950 1300 50  0000 R CNN
F 2 "LED_SMD:LED_1206_3216Metric" H 10050 1450 50  0001 C CNN
F 3 "~" H 10050 1450 50  0001 C CNN
	1    10050 1450
	-1   0    0    1   
$EndComp
$Comp
L Device:R R?
U 1 1 637893A3
P 10500 1450
AR Path="/637893A3" Ref="R?"  Part="1" 
AR Path="/67F05B40/637893A3" Ref="R38"  Part="1" 
F 0 "R38" V 10400 1350 50  0000 C CNN
F 1 "1K" V 10400 1500 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 10430 1450 50  0001 C CNN
F 3 "~" H 10500 1450 50  0001 C CNN
	1    10500 1450
	0    1    -1   0   
$EndComp
Wire Wire Line
	10650 1450 10750 1450
Wire Wire Line
	10350 1450 10200 1450
Text GLabel 9750 1450 0    50   Input ~ 0
WIFI_LED
Wire Wire Line
	9750 1450 9900 1450
Wire Wire Line
	8150 1350 8300 1350
Text GLabel 850  4800 0    50   Input ~ 0
5VA
Wire Wire Line
	850  4800 1150 4800
Wire Wire Line
	1150 4800 1150 4950
Text GLabel 8150 850  0    50   Input ~ 0
5VA
Wire Wire Line
	8150 850  8300 850 
Text GLabel 8150 950  0    50   Input ~ 0
5VA
Wire Wire Line
	8150 950  8300 950 
Text GLabel 8950 950  2    50   Input ~ 0
5VD
Wire Wire Line
	8950 950  8800 950 
Text GLabel 8150 1050 0    50   Input ~ 0
WIFI_LED
Wire Wire Line
	8150 1050 8300 1050
Wire Wire Line
	8950 1250 8800 1250
Text GLabel 8950 1250 2    50   Input ~ 0
HV
Wire Wire Line
	8950 1350 8800 1350
Text GLabel 8950 1350 2    50   Input ~ 0
HV
$Comp
L Connector_Generic:Conn_02x06_Odd_Even J12
U 1 1 638652B0
P 8500 1050
F 0 "J12" H 8550 1467 50  0000 C CNN
F 1 "Conn_02x06_Odd_Even" H 8550 1376 50  0000 C CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_2x06_P2.00mm_Vertical" H 8500 1050 50  0001 C CNN
F 3 "~" H 8500 1050 50  0001 C CNN
	1    8500 1050
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 6269F168
P 3250 4550
AR Path="/6269F168" Ref="#PWR?"  Part="1" 
AR Path="/67F05B40/6269F168" Ref="#PWR0115"  Part="1" 
F 0 "#PWR0115" H 3250 4300 50  0001 C CNN
F 1 "GNDD" H 3254 4395 50  0000 C CNN
F 2 "" H 3250 4550 50  0001 C CNN
F 3 "" H 3250 4550 50  0001 C CNN
	1    3250 4550
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 626A578A
P 3500 5700
AR Path="/626A578A" Ref="#PWR?"  Part="1" 
AR Path="/67F05B40/626A578A" Ref="#PWR0116"  Part="1" 
F 0 "#PWR0116" H 3500 5450 50  0001 C CNN
F 1 "GNDD" H 3504 5545 50  0000 C CNN
F 2 "" H 3500 5700 50  0001 C CNN
F 3 "" H 3500 5700 50  0001 C CNN
	1    3500 5700
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 626ABD03
P 2100 6200
AR Path="/626ABD03" Ref="#PWR?"  Part="1" 
AR Path="/67F05B40/626ABD03" Ref="#PWR0117"  Part="1" 
F 0 "#PWR0117" H 2100 5950 50  0001 C CNN
F 1 "GNDD" H 2104 6045 50  0000 C CNN
F 2 "" H 2100 6200 50  0001 C CNN
F 3 "" H 2100 6200 50  0001 C CNN
	1    2100 6200
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 626B220F
P 1150 6800
AR Path="/626B220F" Ref="#PWR?"  Part="1" 
AR Path="/67F05B40/626B220F" Ref="#PWR0118"  Part="1" 
F 0 "#PWR0118" H 1150 6550 50  0001 C CNN
F 1 "GNDD" H 1154 6645 50  0000 C CNN
F 2 "" H 1150 6800 50  0001 C CNN
F 3 "" H 1150 6800 50  0001 C CNN
	1    1150 6800
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 626B8747
P 5300 5800
AR Path="/626B8747" Ref="#PWR?"  Part="1" 
AR Path="/67F05B40/626B8747" Ref="#PWR0119"  Part="1" 
F 0 "#PWR0119" H 5300 5550 50  0001 C CNN
F 1 "GNDD" H 5304 5645 50  0000 C CNN
F 2 "" H 5300 5800 50  0001 C CNN
F 3 "" H 5300 5800 50  0001 C CNN
	1    5300 5800
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 626BEF43
P 4700 4600
AR Path="/626BEF43" Ref="#PWR?"  Part="1" 
AR Path="/67F05B40/626BEF43" Ref="#PWR0120"  Part="1" 
F 0 "#PWR0120" H 4700 4350 50  0001 C CNN
F 1 "GNDD" H 4704 4445 50  0000 C CNN
F 2 "" H 4700 4600 50  0001 C CNN
F 3 "" H 4700 4600 50  0001 C CNN
	1    4700 4600
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 626C54A0
P 1100 2650
AR Path="/626C54A0" Ref="#PWR?"  Part="1" 
AR Path="/67F05B40/626C54A0" Ref="#PWR0121"  Part="1" 
F 0 "#PWR0121" H 1100 2400 50  0001 C CNN
F 1 "GNDD" H 1104 2495 50  0000 C CNN
F 2 "" H 1100 2650 50  0001 C CNN
F 3 "" H 1100 2650 50  0001 C CNN
	1    1100 2650
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 626CBADD
P 3600 1700
AR Path="/626CBADD" Ref="#PWR?"  Part="1" 
AR Path="/67F05B40/626CBADD" Ref="#PWR0122"  Part="1" 
F 0 "#PWR0122" H 3600 1450 50  0001 C CNN
F 1 "GNDD" H 3604 1545 50  0000 C CNN
F 2 "" H 3600 1700 50  0001 C CNN
F 3 "" H 3600 1700 50  0001 C CNN
	1    3600 1700
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 626D2260
P 10750 1550
AR Path="/626D2260" Ref="#PWR?"  Part="1" 
AR Path="/67F05B40/626D2260" Ref="#PWR0123"  Part="1" 
F 0 "#PWR0123" H 10750 1300 50  0001 C CNN
F 1 "GNDD" H 10754 1395 50  0000 C CNN
F 2 "" H 10750 1550 50  0001 C CNN
F 3 "" H 10750 1550 50  0001 C CNN
	1    10750 1550
	1    0    0    -1  
$EndComp
Wire Wire Line
	10750 1550 10750 1450
$Comp
L power:GNDD #PWR?
U 1 1 626DF688
P 8150 1250
AR Path="/626DF688" Ref="#PWR?"  Part="1" 
AR Path="/67F05B40/626DF688" Ref="#PWR0124"  Part="1" 
F 0 "#PWR0124" H 8150 1000 50  0001 C CNN
F 1 "GNDD" V 8150 1050 50  0000 C CNN
F 2 "" H 8150 1250 50  0001 C CNN
F 3 "" H 8150 1250 50  0001 C CNN
	1    8150 1250
	0    1    1    0   
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 626F3599
P 8150 1350
AR Path="/626F3599" Ref="#PWR?"  Part="1" 
AR Path="/67F05B40/626F3599" Ref="#PWR0125"  Part="1" 
F 0 "#PWR0125" H 8150 1100 50  0001 C CNN
F 1 "GNDD" V 8150 1150 50  0000 C CNN
F 2 "" H 8150 1350 50  0001 C CNN
F 3 "" H 8150 1350 50  0001 C CNN
	1    8150 1350
	0    1    1    0   
$EndComp
$EndSCHEMATC
