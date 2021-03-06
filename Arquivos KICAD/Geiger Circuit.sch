EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 5
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
L Device:C C19
U 1 1 61A6E5AC
P 1600 1650
AR Path="/61A16067/61A6E5AC" Ref="C19"  Part="1" 
AR Path="/63AEBE91/61A6E5AC" Ref="C?"  Part="1" 
F 0 "C19" H 1715 1696 50  0000 L CNN
F 1 "100nF" H 1715 1605 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 1638 1500 50  0001 C CNN
F 3 "~" H 1600 1650 50  0001 C CNN
	1    1600 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	1600 1500 1600 1450
$Comp
L Device:R R58
U 1 1 61A6E5B3
P 1750 2800
AR Path="/61A16067/61A6E5B3" Ref="R58"  Part="1" 
AR Path="/63AEBE91/61A6E5B3" Ref="R?"  Part="1" 
F 0 "R58" V 1543 2800 50  0000 C CNN
F 1 "470K" V 1634 2800 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 1680 2800 50  0001 C CNN
F 3 "~" H 1750 2800 50  0001 C CNN
	1    1750 2800
	0    1    1    0   
$EndComp
Wire Wire Line
	1600 1800 1600 1950
Wire Wire Line
	1150 3250 1400 3250
Wire Wire Line
	1400 3250 1400 2800
$Comp
L Transistor_BJT:2N3904 Q15
U 1 1 61A6E5C8
P 2450 3250
AR Path="/61A16067/61A6E5C8" Ref="Q15"  Part="1" 
AR Path="/63AEBE91/61A6E5C8" Ref="Q?"  Part="1" 
F 0 "Q15" H 2640 3296 50  0000 L CNN
F 1 "2N3904" H 2640 3205 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 2650 3175 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N3904.pdf" H 2450 3250 50  0001 L CNN
	1    2450 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	2550 3050 2550 2800
Wire Wire Line
	2550 2800 1900 2800
Wire Wire Line
	2550 3450 2550 3600
$Comp
L Device:R R59
U 1 1 61A6E5D7
P 2850 2800
AR Path="/61A16067/61A6E5D7" Ref="R59"  Part="1" 
AR Path="/63AEBE91/61A6E5D7" Ref="R?"  Part="1" 
F 0 "R59" V 2643 2800 50  0000 C CNN
F 1 "47K" V 2734 2800 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2780 2800 50  0001 C CNN
F 3 "~" H 2850 2800 50  0001 C CNN
	1    2850 2800
	0    1    1    0   
$EndComp
Wire Wire Line
	2700 2800 2550 2800
Connection ~ 2550 2800
$Comp
L Projeto-Relogio-Pulso-2Displays-rescue:NE555-Timer-Projeto-Relogio-Pulso-2Displays-rescue U14
U 1 1 61A6E5DF
P 3500 1300
AR Path="/61A16067/61A6E5DF" Ref="U14"  Part="1" 
AR Path="/63AEBE91/61A6E5DF" Ref="U?"  Part="1" 
F 0 "U14" H 3250 1700 50  0000 C CNN
F 1 "NE555" H 3700 1700 50  0000 C CNN
F 2 "Package_SO:SOIC-8_5.275x5.275mm_P1.27mm" H 3500 1300 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/ne555.pdf" H 3500 1300 50  0001 C CNN
	1    3500 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	3000 1500 2850 1500
Wire Wire Line
	3500 1700 3500 1850
Wire Wire Line
	2150 1800 2150 1950
$Comp
L Device:R R51
U 1 1 61A6E5F4
P 2450 800
AR Path="/61A16067/61A6E5F4" Ref="R51"  Part="1" 
AR Path="/63AEBE91/61A6E5F4" Ref="R?"  Part="1" 
F 0 "R51" V 2550 850 50  0000 C CNN
F 1 "470K" V 2550 650 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2380 800 50  0001 C CNN
F 3 "~" H 2450 800 50  0001 C CNN
	1    2450 800 
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2150 600  2850 600 
Connection ~ 2850 600 
Wire Wire Line
	2850 600  3500 600 
Wire Wire Line
	2850 600  2850 1500
Wire Wire Line
	3500 600  3500 900 
Wire Wire Line
	4000 1300 4100 1300
Wire Wire Line
	4100 1300 4100 800 
Wire Wire Line
	4000 1500 4100 1500
Wire Wire Line
	4100 1500 4100 1300
Connection ~ 4100 1300
Wire Wire Line
	3000 1100 2550 1100
Wire Wire Line
	2550 1100 2550 2800
$Comp
L Device:R R57
U 1 1 61A6E606
P 2850 2500
AR Path="/61A16067/61A6E606" Ref="R57"  Part="1" 
AR Path="/63AEBE91/61A6E606" Ref="R?"  Part="1" 
F 0 "R57" V 2643 2500 50  0000 C CNN
F 1 "470K" V 2734 2500 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2780 2500 50  0001 C CNN
F 3 "~" H 2850 2500 50  0001 C CNN
	1    2850 2500
	0    1    1    0   
$EndComp
$Comp
L Device:R R55
U 1 1 61A6E60C
P 2850 2200
AR Path="/61A16067/61A6E60C" Ref="R55"  Part="1" 
AR Path="/63AEBE91/61A6E60C" Ref="R?"  Part="1" 
F 0 "R55" V 2643 2200 50  0000 C CNN
F 1 "10K" V 2734 2200 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2780 2200 50  0001 C CNN
F 3 "~" H 2850 2200 50  0001 C CNN
	1    2850 2200
	0    1    1    0   
$EndComp
Wire Wire Line
	2250 3250 2050 3250
Wire Wire Line
	2050 3250 2050 2500
Connection ~ 2050 2500
Wire Wire Line
	2050 2500 2050 2200
Wire Wire Line
	2050 2200 2700 2200
Wire Wire Line
	2050 2500 2700 2500
$Comp
L power:GNDPWR #PWR054
U 1 1 61A6E618
P 3150 2500
AR Path="/61A16067/61A6E618" Ref="#PWR054"  Part="1" 
AR Path="/63AEBE91/61A6E618" Ref="#PWR?"  Part="1" 
F 0 "#PWR054" H 3150 2300 50  0001 C CNN
F 1 "GNDPWR" V 3150 2250 50  0000 C CNN
F 2 "" H 3150 2450 50  0001 C CNN
F 3 "" H 3150 2450 50  0001 C CNN
	1    3150 2500
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3000 2500 3150 2500
$Comp
L Device:C C21
U 1 1 61A6E61F
P 5800 2400
AR Path="/61A16067/61A6E61F" Ref="C21"  Part="1" 
AR Path="/63AEBE91/61A6E61F" Ref="C?"  Part="1" 
F 0 "C21" H 5915 2446 50  0000 L CNN
F 1 "270pF" H 5915 2355 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 5838 2250 50  0001 C CNN
F 3 "~" H 5800 2400 50  0001 C CNN
	1    5800 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	5800 2550 5800 2700
Wire Wire Line
	5800 2250 5800 2200
$Comp
L Device:Speaker LS1
U 1 1 61A6E62D
P 4700 2800
AR Path="/61A16067/61A6E62D" Ref="LS1"  Part="1" 
AR Path="/63AEBE91/61A6E62D" Ref="LS?"  Part="1" 
F 0 "LS1" H 4870 2796 50  0000 L CNN
F 1 "Speaker" H 4870 2705 50  0000 L CNN
F 2 "Buzzer_Beeper:MagneticBuzzer_Kingstate_KCG0601" H 4700 2600 50  0001 C CNN
F 3 "~" H 4690 2750 50  0001 C CNN
	1    4700 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	4500 2800 4400 2800
Wire Wire Line
	3500 600  4400 600 
Connection ~ 3500 600 
Wire Wire Line
	4000 1100 4250 1100
Wire Wire Line
	4250 1100 4250 1950
Wire Wire Line
	4250 1950 3900 1950
$Comp
L Device:R R60
U 1 1 61A6E639
P 3600 3100
AR Path="/61A16067/61A6E639" Ref="R60"  Part="1" 
AR Path="/63AEBE91/61A6E639" Ref="R?"  Part="1" 
F 0 "R60" V 3393 3100 50  0000 C CNN
F 1 "1K" V 3484 3100 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 3530 3100 50  0001 C CNN
F 3 "~" H 3600 3100 50  0001 C CNN
	1    3600 3100
	0    1    1    0   
$EndComp
$Comp
L Device:R R62
U 1 1 61A6E63F
P 3900 3400
AR Path="/61A16067/61A6E63F" Ref="R62"  Part="1" 
AR Path="/63AEBE91/61A6E63F" Ref="R?"  Part="1" 
F 0 "R62" H 3830 3354 50  0000 R CNN
F 1 "10K" H 3830 3445 50  0000 R CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 3830 3400 50  0001 C CNN
F 3 "~" H 3900 3400 50  0001 C CNN
	1    3900 3400
	-1   0    0    1   
$EndComp
Wire Wire Line
	3750 3100 3900 3100
Wire Wire Line
	3900 3250 3900 3100
Connection ~ 3900 3100
$Comp
L Device:LED D15
U 1 1 61A6E648
P 3300 3450
AR Path="/61A16067/61A6E648" Ref="D15"  Part="1" 
AR Path="/63AEBE91/61A6E648" Ref="D?"  Part="1" 
F 0 "D15" V 3339 3333 50  0000 R CNN
F 1 "LED" V 3248 3333 50  0000 R CNN
F 2 "LED_SMD:LED_1206_3216Metric" H 3300 3450 50  0001 C CNN
F 3 "~" H 3300 3450 50  0001 C CNN
	1    3300 3450
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3300 3100 3450 3100
Wire Wire Line
	3300 3600 3300 3750
Wire Wire Line
	3300 3100 3300 3300
Wire Wire Line
	3900 1950 3900 3100
Wire Wire Line
	4400 600  4400 2400
Wire Wire Line
	4400 2800 3000 2800
Connection ~ 4400 2800
$Comp
L Transistor_BJT:2N3904 Q16
U 1 1 61A6E65B
P 4300 3700
AR Path="/61A16067/61A6E65B" Ref="Q16"  Part="1" 
AR Path="/63AEBE91/61A6E65B" Ref="Q?"  Part="1" 
F 0 "Q16" H 4490 3746 50  0000 L CNN
F 1 "2N3904" H 4490 3655 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 4500 3625 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N3904.pdf" H 4300 3700 50  0001 L CNN
	1    4300 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 3700 3900 3700
Wire Wire Line
	3900 3700 3900 3550
Wire Wire Line
	4500 2900 4400 2900
Wire Wire Line
	4400 2900 4400 3500
Wire Wire Line
	4400 3900 4400 4050
Connection ~ 4400 600 
$Comp
L Amplifier_Operational:LM358 U15
U 2 1 61A6E66D
P 3200 4350
AR Path="/61A16067/61A6E66D" Ref="U15"  Part="2" 
AR Path="/63AEBE91/61A6E66D" Ref="U?"  Part="2" 
F 0 "U15" H 3200 4717 50  0000 C CNN
F 1 "LM358" H 3200 4626 50  0000 C CNN
F 2 "Package_SO:SOIC-8_5.275x5.275mm_P1.27mm" H 3200 4350 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm2904-n.pdf" H 3200 4350 50  0001 C CNN
	2    3200 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	1150 3350 1400 3350
Wire Wire Line
	2750 4000 2600 4000
Wire Wire Line
	2600 4250 2750 4250
$Comp
L Device:R R65
U 1 1 61A6E67C
P 2450 4250
AR Path="/61A16067/61A6E67C" Ref="R65"  Part="1" 
AR Path="/63AEBE91/61A6E67C" Ref="R?"  Part="1" 
F 0 "R65" V 2350 4100 50  0000 C CNN
F 1 "NC" V 2350 4400 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2380 4250 50  0001 C CNN
F 3 "~" H 2450 4250 50  0001 C CNN
	1    2450 4250
	0    1    1    0   
$EndComp
$Comp
L Device:R R63
U 1 1 61A6E682
P 2450 4000
AR Path="/61A16067/61A6E682" Ref="R63"  Part="1" 
AR Path="/63AEBE91/61A6E682" Ref="R?"  Part="1" 
F 0 "R63" V 2350 3850 50  0000 C CNN
F 1 "5.1K" V 2350 4150 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2380 4000 50  0001 C CNN
F 3 "~" H 2450 4000 50  0001 C CNN
	1    2450 4000
	0    1    1    0   
$EndComp
Wire Wire Line
	2750 4250 2750 4000
Wire Wire Line
	2750 4250 2900 4250
Connection ~ 2750 4250
Wire Wire Line
	1400 3350 1400 4000
Wire Wire Line
	2150 4400 2150 4250
Wire Wire Line
	2150 4250 2300 4250
Wire Wire Line
	2900 4450 2750 4450
Wire Wire Line
	2750 4450 2750 4650
Wire Wire Line
	2750 4650 3650 4650
Wire Wire Line
	3650 4650 3650 4550
Wire Wire Line
	3650 4350 3500 4350
$Comp
L Connector:LEMO2 J16
U 1 1 61A6E694
P 4350 4550
AR Path="/61A16067/61A6E694" Ref="J16"  Part="1" 
AR Path="/63AEBE91/61A6E694" Ref="J?"  Part="1" 
F 0 "J16" H 4268 4283 50  0000 C CNN
F 1 "LEMO2" H 4268 4374 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 4350 4600 50  0001 C CNN
F 3 " ~" H 4350 4600 50  0001 C CNN
	1    4350 4550
	1    0    0    1   
$EndComp
Wire Wire Line
	4050 4550 3650 4550
Connection ~ 3650 4650
$Comp
L Connector:LEMO2 J14
U 1 1 61A6E69C
P 6250 2200
AR Path="/61A16067/61A6E69C" Ref="J14"  Part="1" 
AR Path="/63AEBE91/61A6E69C" Ref="J?"  Part="1" 
F 0 "J14" H 6430 2296 50  0000 L CNN
F 1 "LEMO2" H 6430 2205 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 6250 2250 50  0001 C CNN
F 3 " ~" H 6250 2250 50  0001 C CNN
	1    6250 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	5950 2200 5800 2200
Connection ~ 5800 2200
$Comp
L Device:R R52
U 1 1 61A6E6A4
P 5800 1850
AR Path="/61A16067/61A6E6A4" Ref="R52"  Part="1" 
AR Path="/63AEBE91/61A6E6A4" Ref="R?"  Part="1" 
F 0 "R52" H 5730 1804 50  0000 R CNN
F 1 "10M" H 5730 1895 50  0000 R CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 5730 1850 50  0001 C CNN
F 3 "~" H 5800 1850 50  0001 C CNN
	1    5800 1850
	-1   0    0    1   
$EndComp
$Comp
L Device:Jumper JP3
U 1 1 61A6E6AA
P 6050 750
AR Path="/61A16067/61A6E6AA" Ref="JP3"  Part="1" 
AR Path="/63AEBE91/61A6E6AA" Ref="JP?"  Part="1" 
F 0 "JP3" H 5950 900 50  0000 C CNN
F 1 "TEST" H 6200 900 50  0000 C CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Open_RoundedPad1.0x1.5mm" H 6050 750 50  0001 C CNN
F 3 "~" H 6050 750 50  0001 C CNN
	1    6050 750 
	1    0    0    -1  
$EndComp
$Comp
L Device:R R46
U 1 1 61A6E6B0
P 6650 750
AR Path="/61A16067/61A6E6B0" Ref="R46"  Part="1" 
AR Path="/63AEBE91/61A6E6B0" Ref="R?"  Part="1" 
F 0 "R46" V 6857 750 50  0000 C CNN
F 1 "10M" V 6766 750 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 6580 750 50  0001 C CNN
F 3 "~" H 6650 750 50  0001 C CNN
	1    6650 750 
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R47
U 1 1 61A6E6B6
P 7100 750
AR Path="/61A16067/61A6E6B6" Ref="R47"  Part="1" 
AR Path="/63AEBE91/61A6E6B6" Ref="R?"  Part="1" 
F 0 "R47" V 7307 750 50  0000 C CNN
F 1 "10M" V 7216 750 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 7030 750 50  0001 C CNN
F 3 "~" H 7100 750 50  0001 C CNN
	1    7100 750 
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R48
U 1 1 61A6E6BC
P 7550 750
AR Path="/61A16067/61A6E6BC" Ref="R48"  Part="1" 
AR Path="/63AEBE91/61A6E6BC" Ref="R?"  Part="1" 
F 0 "R48" V 7757 750 50  0000 C CNN
F 1 "10M" V 7666 750 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 7480 750 50  0001 C CNN
F 3 "~" H 7550 750 50  0001 C CNN
	1    7550 750 
	0    1    -1   0   
$EndComp
$Comp
L Device:R R49
U 1 1 61A6E6C2
P 8000 750
AR Path="/61A16067/61A6E6C2" Ref="R49"  Part="1" 
AR Path="/63AEBE91/61A6E6C2" Ref="R?"  Part="1" 
F 0 "R49" V 8207 750 50  0000 C CNN
F 1 "10M" V 8116 750 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 7930 750 50  0001 C CNN
F 3 "~" H 8000 750 50  0001 C CNN
	1    8000 750 
	0    1    -1   0   
$EndComp
$Comp
L Device:R R50
U 1 1 61A6E6C8
P 8450 750
AR Path="/61A16067/61A6E6C8" Ref="R50"  Part="1" 
AR Path="/63AEBE91/61A6E6C8" Ref="R?"  Part="1" 
F 0 "R50" V 8657 750 50  0000 C CNN
F 1 "10M" V 8566 750 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 8380 750 50  0001 C CNN
F 3 "~" H 8450 750 50  0001 C CNN
	1    8450 750 
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4400 600  4850 600 
Wire Wire Line
	5350 2100 5800 2100
Wire Wire Line
	6350 750  6500 750 
Wire Wire Line
	6800 750  6950 750 
Wire Wire Line
	7250 750  7400 750 
Wire Wire Line
	7700 750  7850 750 
Wire Wire Line
	8750 750  8600 750 
Wire Wire Line
	5800 2100 5800 2000
Connection ~ 5800 2100
Wire Wire Line
	5800 2100 5950 2100
$Comp
L Simulation_SPICE:DIODE D11
U 1 1 61A6E6DF
P 5800 1150
AR Path="/61A16067/61A6E6DF" Ref="D11"  Part="1" 
AR Path="/63AEBE91/61A6E6DF" Ref="D?"  Part="1" 
F 0 "D11" V 5754 1230 50  0000 L CNN
F 1 "1N4937" V 5845 1230 50  0000 L CNN
F 2 "Diode_SMD:D_2114_3652Metric_Castellated" H 5800 1150 50  0001 C CNN
F 3 "~" H 5800 1150 50  0001 C CNN
F 4 "Y" H 5800 1150 50  0001 L CNN "Spice_Netlist_Enabled"
F 5 "V" H 5800 1150 50  0001 L CNN "Spice_Primitive"
	1    5800 1150
	0    1    1    0   
$EndComp
$Comp
L Simulation_SPICE:DIODE D12
U 1 1 61A6E6E7
P 6300 1150
AR Path="/61A16067/61A6E6E7" Ref="D12"  Part="1" 
AR Path="/63AEBE91/61A6E6E7" Ref="D?"  Part="1" 
F 0 "D12" V 6346 1070 50  0000 R CNN
F 1 "1N4937" V 6255 1070 50  0000 R CNN
F 2 "Diode_SMD:D_2114_3652Metric_Castellated" H 6300 1150 50  0001 C CNN
F 3 "~" H 6300 1150 50  0001 C CNN
F 4 "Y" H 6300 1150 50  0001 L CNN "Spice_Netlist_Enabled"
F 5 "V" H 6300 1150 50  0001 L CNN "Spice_Primitive"
	1    6300 1150
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5800 1000 5800 850 
Wire Wire Line
	5800 850  6300 850 
Wire Wire Line
	6300 850  6300 1000
Wire Wire Line
	5900 1600 5800 1600
Wire Wire Line
	5800 1300 5800 1600
Wire Wire Line
	5800 1600 5800 1700
Connection ~ 5800 1600
Wire Wire Line
	6200 1600 6300 1600
Wire Wire Line
	6300 1600 6300 1300
$Comp
L Simulation_SPICE:DIODE D13
U 1 1 61A6E6F8
P 6550 1600
AR Path="/61A16067/61A6E6F8" Ref="D13"  Part="1" 
AR Path="/63AEBE91/61A6E6F8" Ref="D?"  Part="1" 
F 0 "D13" H 6550 1383 50  0000 C CNN
F 1 "1N4937" H 6550 1474 50  0000 C CNN
F 2 "Diode_SMD:D_2114_3652Metric_Castellated" H 6550 1600 50  0001 C CNN
F 3 "~" H 6550 1600 50  0001 C CNN
F 4 "Y" H 6550 1600 50  0001 L CNN "Spice_Netlist_Enabled"
F 5 "V" H 6550 1600 50  0001 L CNN "Spice_Primitive"
	1    6550 1600
	-1   0    0    1   
$EndComp
Wire Wire Line
	6400 1600 6300 1600
Connection ~ 6300 1600
Wire Wire Line
	6700 1600 6900 1600
Connection ~ 6900 1600
Wire Wire Line
	6900 1600 7100 1600
Wire Wire Line
	7400 1950 7400 1800
Wire Wire Line
	6900 1800 6900 1600
Wire Wire Line
	7400 1800 6900 1800
Wire Wire Line
	6900 1800 6900 2550
Connection ~ 6900 1800
$Comp
L Projeto-Relogio-Pulso-2Displays-rescue:NE555-Timer-Projeto-Relogio-Pulso-2Displays-rescue U16
U 1 1 61A6E70F
P 6900 4850
AR Path="/61A16067/61A6E70F" Ref="U16"  Part="1" 
AR Path="/63AEBE91/61A6E70F" Ref="U?"  Part="1" 
F 0 "U16" H 6700 5250 50  0000 C CNN
F 1 "NE555" H 7100 5250 50  0000 C CNN
F 2 "Package_SO:SOIC-8_5.275x5.275mm_P1.27mm" H 6900 4850 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/ne555.pdf" H 6900 4850 50  0001 C CNN
	1    6900 4850
	1    0    0    -1  
$EndComp
$Comp
L pspice:INDUCTOR L1
U 1 1 61A6E71B
P 6900 3000
AR Path="/61A16067/61A6E71B" Ref="L1"  Part="1" 
AR Path="/63AEBE91/61A6E71B" Ref="L?"  Part="1" 
F 0 "L1" V 6854 3078 50  0000 L CNN
F 1 "10mH" V 6945 3078 50  0000 L CNN
F 2 "Inductor_THT:L_Radial_D7.2mm_P3.00mm_MuRATA_1700" H 6900 3000 50  0001 C CNN
F 3 "~" H 6900 3000 50  0001 C CNN
	1    6900 3000
	0    1    1    0   
$EndComp
$Comp
L pspice:INDUCTOR L2
U 1 1 61A6E721
P 5600 4550
AR Path="/61A16067/61A6E721" Ref="L2"  Part="1" 
AR Path="/63AEBE91/61A6E721" Ref="L?"  Part="1" 
F 0 "L2" V 5554 4628 50  0000 L CNN
F 1 "100uH" H 5500 4450 50  0000 L CNN
F 2 "Inductor_THT:L_Radial_D7.2mm_P3.00mm_MuRATA_1700" H 5600 4550 50  0001 C CNN
F 3 "~" H 5600 4550 50  0001 C CNN
	1    5600 4550
	0    1    1    0   
$EndComp
Wire Wire Line
	5600 4150 6900 4150
Wire Wire Line
	6900 4150 6900 4450
$Comp
L Device:CP C27
U 1 1 61A6E729
P 5600 5150
AR Path="/61A16067/61A6E729" Ref="C27"  Part="1" 
AR Path="/63AEBE91/61A6E729" Ref="C?"  Part="1" 
F 0 "C27" H 5718 5196 50  0000 L CNN
F 1 "100uF" H 5718 5105 50  0000 L CNN
F 2 "Capacitor_SMD:CP_Elec_5x4.5" H 5638 5000 50  0001 C CNN
F 3 "~" H 5600 5150 50  0001 C CNN
	1    5600 5150
	1    0    0    -1  
$EndComp
Wire Wire Line
	5600 5000 5600 4900
$Comp
L Device:CP C26
U 1 1 61A6E730
P 5100 4550
AR Path="/61A16067/61A6E730" Ref="C26"  Part="1" 
AR Path="/63AEBE91/61A6E730" Ref="C?"  Part="1" 
F 0 "C26" H 5218 4596 50  0000 L CNN
F 1 "100uF" H 5150 4450 50  0000 L CNN
F 2 "Capacitor_SMD:CP_Elec_5x4.5" H 5138 4400 50  0001 C CNN
F 3 "~" H 5100 4550 50  0001 C CNN
	1    5100 4550
	1    0    0    -1  
$EndComp
Wire Wire Line
	5100 4400 5100 4150
Connection ~ 5600 4150
$Comp
L Device:C C25
U 1 1 61A6E738
P 4700 4550
AR Path="/61A16067/61A6E738" Ref="C25"  Part="1" 
AR Path="/63AEBE91/61A6E738" Ref="C?"  Part="1" 
F 0 "C25" H 4815 4596 50  0000 L CNN
F 1 "100nF" H 4750 4450 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 4738 4400 50  0001 C CNN
F 3 "~" H 4700 4550 50  0001 C CNN
	1    4700 4550
	1    0    0    -1  
$EndComp
Wire Wire Line
	4700 4400 4700 4150
Wire Wire Line
	4700 4150 5100 4150
Wire Wire Line
	4700 4700 4700 4850
Wire Wire Line
	5100 4700 5100 4850
Connection ~ 4700 4850
Wire Wire Line
	4700 4850 4700 5400
Wire Wire Line
	5600 5400 4700 5400
Wire Wire Line
	5600 5400 5600 5300
Wire Wire Line
	5600 4300 5600 4150
Wire Wire Line
	3000 2200 5800 2200
Wire Wire Line
	4950 1550 4950 2500
Wire Wire Line
	4950 2500 5400 2500
Wire Wire Line
	5400 4900 5600 4900
Wire Wire Line
	5400 2500 5400 4900
Connection ~ 5600 4900
Wire Wire Line
	5600 4900 5600 4800
Wire Wire Line
	6550 2850 6550 2550
Wire Wire Line
	6550 2550 6900 2550
Connection ~ 6900 2550
Wire Wire Line
	6900 2550 6900 2750
Wire Wire Line
	6550 3150 6550 3300
Connection ~ 6900 4150
Wire Wire Line
	6900 4150 7100 4150
Wire Wire Line
	6900 3250 6900 4150
$Comp
L Device:R R66
U 1 1 61A6E75D
P 7800 4650
AR Path="/61A16067/61A6E75D" Ref="R66"  Part="1" 
AR Path="/63AEBE91/61A6E75D" Ref="R?"  Part="1" 
F 0 "R66" V 8007 4650 50  0000 C CNN
F 1 "3K" V 7916 4650 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 7730 4650 50  0001 C CNN
F 3 "~" H 7800 4650 50  0001 C CNN
	1    7800 4650
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7950 4650 8050 4650
Wire Wire Line
	8050 4650 8050 2700
Wire Wire Line
	7000 2700 7000 2150
Wire Wire Line
	7000 2150 7100 2150
Wire Wire Line
	7000 2700 8050 2700
Wire Wire Line
	7400 4650 7650 4650
Wire Wire Line
	7400 4150 7550 4150
Wire Wire Line
	7550 4150 7550 4850
Wire Wire Line
	7550 4850 7400 4850
$Comp
L Device:R R69
U 1 1 61A6E76C
P 7250 5400
AR Path="/61A16067/61A6E76C" Ref="R69"  Part="1" 
AR Path="/63AEBE91/61A6E76C" Ref="R?"  Part="1" 
F 0 "R69" V 7457 5400 50  0000 C CNN
F 1 "33K" V 7366 5400 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 7180 5400 50  0001 C CNN
F 3 "~" H 7250 5400 50  0001 C CNN
	1    7250 5400
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7550 5400 7550 4850
Connection ~ 7550 4850
Wire Wire Line
	6400 4650 6150 4650
Wire Wire Line
	6150 4650 6150 5400
Wire Wire Line
	6150 5700 7700 5700
Wire Wire Line
	7700 5700 7700 5050
Wire Wire Line
	7700 5050 7400 5050
$Comp
L Device:C C29
U 1 1 61A6E779
P 7700 6000
AR Path="/61A16067/61A6E779" Ref="C29"  Part="1" 
AR Path="/63AEBE91/61A6E779" Ref="C?"  Part="1" 
F 0 "C29" H 7815 6046 50  0000 L CNN
F 1 "1nF" H 7815 5955 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 7738 5850 50  0001 C CNN
F 3 "~" H 7700 6000 50  0001 C CNN
	1    7700 6000
	1    0    0    -1  
$EndComp
Wire Wire Line
	7700 6150 7700 6300
Connection ~ 7700 5700
Wire Wire Line
	7700 5700 7700 5850
Wire Wire Line
	6900 5250 6900 6300
Connection ~ 6150 5400
Wire Wire Line
	6150 5400 6150 5700
$Comp
L Transistor_BJT:2N3904 Q14
U 1 1 61A6E78B
P 8550 2500
AR Path="/61A16067/61A6E78B" Ref="Q14"  Part="1" 
AR Path="/63AEBE91/61A6E78B" Ref="Q?"  Part="1" 
F 0 "Q14" H 8740 2546 50  0000 L CNN
F 1 "2N3904" H 8740 2455 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 8750 2425 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N3904.pdf" H 8550 2500 50  0001 L CNN
	1    8550 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	7400 2350 7400 2500
Wire Wire Line
	7400 2500 8250 2500
$Comp
L Device:R_POT_US RV2
U 1 1 61A6E793
P 8250 3050
AR Path="/61A16067/61A6E793" Ref="RV2"  Part="1" 
AR Path="/63AEBE91/61A6E793" Ref="RV?"  Part="1" 
F 0 "RV2" H 8450 3200 50  0000 R CNN
F 1 "100" H 8450 2950 50  0000 R CNN
F 2 "Potentiometer_THT:Potentiometer_Bourns_3339P_Vertical_HandSoldering" H 8250 3050 50  0001 C CNN
F 3 "~" H 8250 3050 50  0001 C CNN
	1    8250 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	8250 2900 8250 2500
Connection ~ 8250 2500
Wire Wire Line
	8250 2500 8350 2500
Wire Wire Line
	8400 3050 8650 3050
Wire Wire Line
	8650 3050 8650 2700
$Comp
L Device:R R54
U 1 1 61A6E79E
P 9350 2050
AR Path="/61A16067/61A6E79E" Ref="R54"  Part="1" 
AR Path="/63AEBE91/61A6E79E" Ref="R?"  Part="1" 
F 0 "R54" H 9280 2004 50  0000 R CNN
F 1 "1K" H 9280 2095 50  0000 R CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 9280 2050 50  0001 C CNN
F 3 "~" H 9350 2050 50  0001 C CNN
	1    9350 2050
	-1   0    0    1   
$EndComp
$Comp
L Device:C C24
U 1 1 61A6E7A4
P 8250 3650
AR Path="/61A16067/61A6E7A4" Ref="C24"  Part="1" 
AR Path="/63AEBE91/61A6E7A4" Ref="C?"  Part="1" 
F 0 "C24" H 8365 3696 50  0000 L CNN
F 1 "10nF 1KV" H 8365 3605 50  0000 L CNN
F 2 "Capacitor_SMD:C_1806_4516Metric" H 8288 3500 50  0001 C CNN
F 3 "~" H 8250 3650 50  0001 C CNN
	1    8250 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	8250 3500 8250 3200
Wire Wire Line
	8250 3800 8250 3950
$Comp
L Device:R R53
U 1 1 61A6E7B2
P 8650 1950
AR Path="/61A16067/61A6E7B2" Ref="R53"  Part="1" 
AR Path="/63AEBE91/61A6E7B2" Ref="R?"  Part="1" 
F 0 "R53" H 8580 1904 50  0000 R CNN
F 1 "100K" H 8580 1995 50  0000 R CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 8580 1950 50  0001 C CNN
F 3 "~" H 8650 1950 50  0001 C CNN
	1    8650 1950
	-1   0    0    1   
$EndComp
Wire Wire Line
	8650 1700 9350 1700
Wire Wire Line
	9350 1700 9350 1900
$Comp
L Device:LED D14
U 1 1 61A6E7BA
P 9350 2550
AR Path="/61A16067/61A6E7BA" Ref="D14"  Part="1" 
AR Path="/63AEBE91/61A6E7BA" Ref="D?"  Part="1" 
F 0 "D14" V 9389 2433 50  0000 R CNN
F 1 "LED" V 9298 2433 50  0000 R CNN
F 2 "LED_SMD:LED_1206_3216Metric" H 9350 2550 50  0001 C CNN
F 3 "~" H 9350 2550 50  0001 C CNN
	1    9350 2550
	0    -1   -1   0   
$EndComp
Wire Wire Line
	9350 2700 9350 2850
Wire Wire Line
	9350 2200 9350 2400
$Comp
L Device:C C22
U 1 1 61A6E7C8
P 9750 2550
AR Path="/61A16067/61A6E7C8" Ref="C22"  Part="1" 
AR Path="/63AEBE91/61A6E7C8" Ref="C?"  Part="1" 
F 0 "C22" H 9865 2596 50  0000 L CNN
F 1 "100nF" H 9865 2505 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 9788 2400 50  0001 C CNN
F 3 "~" H 9750 2550 50  0001 C CNN
	1    9750 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	9750 2700 9750 2850
Wire Wire Line
	9750 1700 9350 1700
Wire Wire Line
	9750 1700 9750 2400
Connection ~ 9350 1700
Wire Wire Line
	6400 5050 6300 5050
Wire Wire Line
	6300 5050 6300 3700
Wire Wire Line
	6300 3700 7800 3700
Wire Wire Line
	7800 3700 7800 2200
Wire Wire Line
	8650 1800 8650 1700
$Comp
L Device:C C16
U 1 1 61A6E7DE
P 1800 850
AR Path="/61A16067/61A6E7DE" Ref="C16"  Part="1" 
AR Path="/63AEBE91/61A6E7DE" Ref="C?"  Part="1" 
F 0 "C16" H 1915 896 50  0000 L CNN
F 1 "100nF" H 1915 805 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 1838 700 50  0001 C CNN
F 3 "~" H 1800 850 50  0001 C CNN
	1    1800 850 
	1    0    0    -1  
$EndComp
Wire Wire Line
	1600 1450 1600 600 
Wire Wire Line
	1600 600  1800 600 
Connection ~ 1600 1450
Connection ~ 2150 600 
Wire Wire Line
	1800 700  1800 600 
Connection ~ 1800 600 
Wire Wire Line
	1800 600  2150 600 
Wire Wire Line
	1800 1000 1800 1150
$Comp
L Device:C C20
U 1 1 61A6E7F2
P 2150 1650
AR Path="/61A16067/61A6E7F2" Ref="C20"  Part="1" 
AR Path="/63AEBE91/61A6E7F2" Ref="C?"  Part="1" 
F 0 "C20" H 2265 1696 50  0000 L CNN
F 1 "1nF" H 2265 1605 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 2188 1500 50  0001 C CNN
F 3 "~" H 2150 1650 50  0001 C CNN
	1    2150 1650
	1    0    0    -1  
$EndComp
$Comp
L Device:R R64
U 1 1 61A6E7F8
P 7250 4150
AR Path="/61A16067/61A6E7F8" Ref="R64"  Part="1" 
AR Path="/63AEBE91/61A6E7F8" Ref="R?"  Part="1" 
F 0 "R64" V 7457 4150 50  0000 C CNN
F 1 "33K" V 7366 4150 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 7180 4150 50  0001 C CNN
F 3 "~" H 7250 4150 50  0001 C CNN
	1    7250 4150
	0    -1   -1   0   
$EndComp
$Comp
L Device:C C17
U 1 1 61A6E7FE
P 6050 1600
AR Path="/61A16067/61A6E7FE" Ref="C17"  Part="1" 
AR Path="/63AEBE91/61A6E7FE" Ref="C?"  Part="1" 
F 0 "C17" V 5798 1600 50  0000 C CNN
F 1 "10nF 1KV" V 5889 1600 50  0000 C CNN
F 2 "Capacitor_SMD:C_1806_4516Metric" H 6088 1450 50  0001 C CNN
F 3 "~" H 6050 1600 50  0001 C CNN
	1    6050 1600
	0    1    1    0   
$EndComp
$Comp
L Device:C C18
U 1 1 61A6E804
P 7250 1600
AR Path="/61A16067/61A6E804" Ref="C18"  Part="1" 
AR Path="/63AEBE91/61A6E804" Ref="C?"  Part="1" 
F 0 "C18" V 6998 1600 50  0000 C CNN
F 1 "10nF 1KV" V 7089 1600 50  0000 C CNN
F 2 "Capacitor_SMD:C_1806_4516Metric" H 7288 1450 50  0001 C CNN
F 3 "~" H 7250 1600 50  0001 C CNN
	1    7250 1600
	0    1    1    0   
$EndComp
$Comp
L Transistor_BJT:MPSA42 Q13
U 1 1 61A6E80A
P 7300 2150
AR Path="/61A16067/61A6E80A" Ref="Q13"  Part="1" 
AR Path="/63AEBE91/61A6E80A" Ref="Q?"  Part="1" 
F 0 "Q13" H 7491 2196 50  0000 L CNN
F 1 "MPSA42" H 7491 2105 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 7500 2075 50  0001 L CIN
F 3 "http://www.onsemi.com/pub_link/Collateral/MPSA42-D.PDF" H 7300 2150 50  0001 L CNN
	1    7300 2150
	1    0    0    -1  
$EndComp
$Comp
L Device:C C23
U 1 1 61A6E810
P 6550 3000
AR Path="/61A16067/61A6E810" Ref="C23"  Part="1" 
AR Path="/63AEBE91/61A6E810" Ref="C?"  Part="1" 
F 0 "C23" H 6435 2954 50  0000 R CNN
F 1 "10nF 1KV" V 6700 3150 50  0000 R CNN
F 2 "Capacitor_SMD:C_1806_4516Metric" H 6588 2850 50  0001 C CNN
F 3 "~" H 6550 3000 50  0001 C CNN
	1    6550 3000
	-1   0    0    1   
$EndComp
Wire Wire Line
	2600 800  2700 800 
Wire Wire Line
	2300 800  2150 800 
Wire Wire Line
	2150 600  2150 800 
Wire Wire Line
	2150 950  2700 950 
Wire Wire Line
	2700 950  2700 800 
Connection ~ 2700 800 
Wire Wire Line
	2700 800  4100 800 
Wire Wire Line
	2150 950  2150 1500
Connection ~ 5100 4150
Wire Wire Line
	5100 4150 5600 4150
Wire Wire Line
	5100 4850 4700 4850
Wire Wire Line
	1050 1450 1600 1450
Text Notes 500  3350 0    50   ~ 0
AUDIO
$Comp
L Transistor_BJT:BC548 Q12
U 1 1 61A6E823
P 10450 1800
AR Path="/61A16067/61A6E823" Ref="Q12"  Part="1" 
AR Path="/63AEBE91/61A6E823" Ref="Q?"  Part="1" 
F 0 "Q12" V 10778 1800 50  0000 C CNN
F 1 "BC548" V 10687 1800 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 10650 1725 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/BC/BC547.pdf" H 10450 1800 50  0001 L CNN
	1    10450 1800
	0    1    -1   0   
$EndComp
Wire Wire Line
	10950 1700 10650 1700
Text GLabel 10600 2750 2    50   Input ~ 0
ON_GEIGER
Wire Wire Line
	10250 1700 9750 1700
Connection ~ 9750 1700
$Comp
L Connector:TestPoint TP7
U 1 1 61A6E82D
P 8750 750
AR Path="/61A16067/61A6E82D" Ref="TP7"  Part="1" 
AR Path="/63AEBE91/61A6E82D" Ref="TP?"  Part="1" 
F 0 "TP7" V 8704 938 50  0000 L CNN
F 1 "Calibration" V 8795 938 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_1.5x1.5mm" H 8950 750 50  0001 C CNN
F 3 "~" H 8950 750 50  0001 C CNN
	1    8750 750 
	0    1    1    0   
$EndComp
Wire Wire Line
	8650 2200 7800 2200
Connection ~ 8650 2200
Wire Wire Line
	8650 2200 8650 2300
Wire Wire Line
	8650 2100 8650 2200
Wire Wire Line
	7400 5400 7550 5400
Wire Wire Line
	6150 5400 7100 5400
$Comp
L Device:R R56
U 1 1 61A6E839
P 10450 2350
AR Path="/61A16067/61A6E839" Ref="R56"  Part="1" 
AR Path="/63AEBE91/61A6E839" Ref="R?"  Part="1" 
F 0 "R56" H 10380 2304 50  0000 R CNN
F 1 "10K" H 10380 2395 50  0000 R CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 10380 2350 50  0001 C CNN
F 3 "~" H 10450 2350 50  0001 C CNN
	1    10450 2350
	-1   0    0    1   
$EndComp
Wire Wire Line
	10450 2000 10450 2200
Wire Wire Line
	10450 2500 10450 2750
Wire Wire Line
	10450 2750 10600 2750
Text GLabel 1050 1450 0    50   Input ~ 0
GEIGER_SENSOR
Text GLabel 10950 1700 2    50   Input ~ 0
5VG
Wire Wire Line
	4050 4650 3650 4650
Wire Wire Line
	1600 2800 1400 2800
$Comp
L Switch:SW_DPDT_x2 SW1
U 1 1 61A6E847
P 4950 1350
AR Path="/61A16067/61A6E847" Ref="SW1"  Part="1" 
AR Path="/63AEBE91/61A6E847" Ref="SW?"  Part="1" 
F 0 "SW1" V 4996 1162 50  0000 R CNN
F 1 "SW_DPDT_x2" V 4905 1162 50  0000 R CNN
F 2 "Button_Switch_THT:SW_CuK_OS102011MA1QN1_SPDT_Angled" H 4950 1350 50  0001 C CNN
F 3 "~" H 4950 1350 50  0001 C CNN
	1    4950 1350
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4850 1150 4850 600 
Wire Wire Line
	1600 6350 1700 6350
$Comp
L Connector:Conn_01x02_Female J?
U 1 1 6334E37B
P 1400 6350
AR Path="/6334E37B" Ref="J?"  Part="1" 
AR Path="/67F05B40/6334E37B" Ref="J?"  Part="1" 
AR Path="/61A16067/6334E37B" Ref="J17"  Part="1" 
AR Path="/63AEBE91/6334E37B" Ref="J?"  Part="1" 
F 0 "J17" H 1428 6326 50  0000 L CNN
F 1 "BAT_IN" H 1450 6250 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x02_P2.00mm_Vertical" H 1400 6350 50  0001 C CNN
F 3 "~" H 1400 6350 50  0001 C CNN
	1    1400 6350
	-1   0    0    -1  
$EndComp
Text GLabel 1500 4800 0    50   Input ~ 0
5VA
Wire Wire Line
	2250 4800 2250 4900
Wire Wire Line
	3550 5850 3550 5800
$Comp
L Device:R R?
U 1 1 6334E384
P 2900 5300
AR Path="/6334E384" Ref="R?"  Part="1" 
AR Path="/67F05B40/6334E384" Ref="R?"  Part="1" 
AR Path="/61A16067/6334E384" Ref="R68"  Part="1" 
AR Path="/63AEBE91/6334E384" Ref="R?"  Part="1" 
F 0 "R68" V 3000 5200 50  0000 C CNN
F 1 "1K" V 3000 5350 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2830 5300 50  0001 C CNN
F 3 "~" H 2900 5300 50  0001 C CNN
	1    2900 5300
	0    1    -1   0   
$EndComp
$Comp
L Device:LED D?
U 1 1 6334E38A
P 3100 5100
AR Path="/6334E38A" Ref="D?"  Part="1" 
AR Path="/67F05B40/6334E38A" Ref="D?"  Part="1" 
AR Path="/61A16067/6334E38A" Ref="D16"  Part="1" 
AR Path="/63AEBE91/6334E38A" Ref="D?"  Part="1" 
F 0 "D16" V 3200 5050 50  0000 R CNN
F 1 "GREEN" H 3100 4950 50  0000 R CNN
F 2 "LED_SMD:LED_1206_3216Metric" H 3100 5100 50  0001 C CNN
F 3 "~" H 3100 5100 50  0001 C CNN
	1    3100 5100
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3050 5300 3100 5300
Wire Wire Line
	3100 5300 3100 5250
Wire Wire Line
	3100 4950 3100 4800
Wire Wire Line
	2750 5300 2650 5300
$Comp
L Device:R R?
U 1 1 6334E394
P 2900 5450
AR Path="/6334E394" Ref="R?"  Part="1" 
AR Path="/67F05B40/6334E394" Ref="R?"  Part="1" 
AR Path="/61A16067/6334E394" Ref="R70"  Part="1" 
AR Path="/63AEBE91/6334E394" Ref="R?"  Part="1" 
F 0 "R70" V 2800 5350 50  0000 C CNN
F 1 "1K" V 2800 5500 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2830 5450 50  0001 C CNN
F 3 "~" H 2900 5450 50  0001 C CNN
	1    2900 5450
	0    1    -1   0   
$EndComp
Wire Wire Line
	2750 5450 2650 5450
$Comp
L Device:LED D?
U 1 1 6334E39B
P 3350 5100
AR Path="/6334E39B" Ref="D?"  Part="1" 
AR Path="/67F05B40/6334E39B" Ref="D?"  Part="1" 
AR Path="/61A16067/6334E39B" Ref="D17"  Part="1" 
AR Path="/63AEBE91/6334E39B" Ref="D?"  Part="1" 
F 0 "D17" V 3450 5050 50  0000 R CNN
F 1 "RED" H 3250 4950 50  0000 R CNN
F 2 "LED_SMD:LED_1206_3216Metric" H 3350 5100 50  0001 C CNN
F 3 "~" H 3350 5100 50  0001 C CNN
	1    3350 5100
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3350 5450 3350 5250
Wire Wire Line
	3350 4950 3350 4800
$Comp
L Device:R R?
U 1 1 6334E3A3
P 1550 5300
AR Path="/6334E3A3" Ref="R?"  Part="1" 
AR Path="/67F05B40/6334E3A3" Ref="R?"  Part="1" 
AR Path="/61A16067/6334E3A3" Ref="R67"  Part="1" 
AR Path="/63AEBE91/6334E3A3" Ref="R?"  Part="1" 
F 0 "R67" V 1750 5300 50  0000 C CNN
F 1 "1.2K" V 1650 5300 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 1480 5300 50  0001 C CNN
F 3 "~" H 1550 5300 50  0001 C CNN
	1    1550 5300
	0    1    -1   0   
$EndComp
Wire Wire Line
	1700 5300 1850 5300
Text Notes 650  5900 0    50   ~ 0
10K - 130mA\n5K - 250mA\n4K - 300mA\n3K - 400mA\n2K - 580mA\n1.66K - 690mA\n1.5K - 780mA\n1.33K - 900mA\n1.2K - 1A\n\n
Wire Wire Line
	1850 5150 1750 5150
Wire Wire Line
	1750 5150 1750 5800
Wire Wire Line
	1750 5800 2250 5800
Connection ~ 2250 5800
Wire Wire Line
	2250 5800 2250 5700
Wire Wire Line
	1400 5300 1350 5300
Connection ~ 1750 5800
$Comp
L Device:CP C?
U 1 1 6334E3B2
P 3850 5250
AR Path="/6334E3B2" Ref="C?"  Part="1" 
AR Path="/67AE4A42/6334E3B2" Ref="C?"  Part="1" 
AR Path="/67E43E22/6334E3B2" Ref="C?"  Part="1" 
AR Path="/67F05B40/6334E3B2" Ref="C?"  Part="1" 
AR Path="/61A16067/6334E3B2" Ref="C28"  Part="1" 
AR Path="/63AEBE91/6334E3B2" Ref="C?"  Part="1" 
F 0 "C28" H 3900 5350 50  0000 L CNN
F 1 "10uF" H 3900 5150 50  0000 L CNN
F 2 "Capacitor_SMD:C_1806_4516Metric" H 3888 5100 50  0001 C CNN
F 3 "~" H 3850 5250 50  0001 C CNN
	1    3850 5250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3850 4800 3850 5100
Text GLabel 1650 5450 0    50   Input ~ 0
BAT
Wire Wire Line
	1650 5450 1850 5450
Text GLabel 3750 7450 0    50   Input ~ 0
BAT
$Comp
L Device:CP C?
U 1 1 6334E3BC
P 3850 7000
AR Path="/6334E3BC" Ref="C?"  Part="1" 
AR Path="/67AE4A42/6334E3BC" Ref="C?"  Part="1" 
AR Path="/67E43E22/6334E3BC" Ref="C?"  Part="1" 
AR Path="/67F05B40/6334E3BC" Ref="C?"  Part="1" 
AR Path="/61A16067/6334E3BC" Ref="C31"  Part="1" 
AR Path="/63AEBE91/6334E3BC" Ref="C?"  Part="1" 
F 0 "C31" H 3900 7100 50  0000 L CNN
F 1 "10uF" H 3900 6900 50  0000 L CNN
F 2 "Capacitor_SMD:C_1806_4516Metric" H 3888 6850 50  0001 C CNN
F 3 "~" H 3850 7000 50  0001 C CNN
	1    3850 7000
	1    0    0    1   
$EndComp
Wire Wire Line
	3850 7450 3850 7150
$Comp
L Battery_Management:DW01 U?
U 1 1 6334E3C3
P 3000 6400
AR Path="/6334E3C3" Ref="U?"  Part="1" 
AR Path="/67F05B40/6334E3C3" Ref="U?"  Part="1" 
AR Path="/61A16067/6334E3C3" Ref="U18"  Part="1" 
AR Path="/63AEBE91/6334E3C3" Ref="U?"  Part="1" 
F 0 "U18" H 2850 6750 50  0000 C CNN
F 1 "DW01" H 3150 6750 50  0000 C CNN
F 2 "Package_SO:TSSOP-8_4.4x3mm_P0.65mm" H 3050 6750 50  0001 C CNN
F 3 "" H 3050 6750 50  0001 C CNN
	1    3000 6400
	-1   0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 6334E3C9
P 3550 6450
AR Path="/6334E3C9" Ref="R?"  Part="1" 
AR Path="/67F05B40/6334E3C9" Ref="R?"  Part="1" 
AR Path="/61A16067/6334E3C9" Ref="R72"  Part="1" 
AR Path="/63AEBE91/6334E3C9" Ref="R?"  Part="1" 
F 0 "R72" V 3650 6350 50  0000 C CNN
F 1 "1K" V 3650 6500 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 3480 6450 50  0001 C CNN
F 3 "~" H 3550 6450 50  0001 C CNN
	1    3550 6450
	0    1    1    0   
$EndComp
$Comp
L Battery_Management:AM8205 U?
U 1 1 6334E3CF
P 3000 7500
AR Path="/6334E3CF" Ref="U?"  Part="1" 
AR Path="/67F05B40/6334E3CF" Ref="U?"  Part="1" 
AR Path="/61A16067/6334E3CF" Ref="U19"  Part="1" 
AR Path="/63AEBE91/6334E3CF" Ref="U?"  Part="1" 
F 0 "U19" H 3000 7915 50  0000 C CNN
F 1 "AM8205" H 3000 7824 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23-6" H 2850 7800 50  0001 C CNN
F 3 "" H 2850 7800 50  0001 C CNN
	1    3000 7500
	-1   0    0    -1  
$EndComp
Text GLabel 3400 6350 2    50   Input ~ 0
G1
Wire Wire Line
	3400 6350 3300 6350
Text GLabel 2450 7550 0    50   Input ~ 0
G1
$Comp
L Device:C C?
U 1 1 6334E3D8
P 2300 6400
AR Path="/6334E3D8" Ref="C?"  Part="1" 
AR Path="/67F05B40/6334E3D8" Ref="C?"  Part="1" 
AR Path="/61A16067/6334E3D8" Ref="C30"  Part="1" 
AR Path="/63AEBE91/6334E3D8" Ref="C?"  Part="1" 
F 0 "C30" H 2185 6354 50  0000 R CNN
F 1 "20pF" H 2185 6445 50  0000 R CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 2338 6250 50  0001 C CNN
F 3 "~" H 2300 6400 50  0001 C CNN
	1    2300 6400
	1    0    0    1   
$EndComp
Wire Wire Line
	3000 6000 3000 5900
Wire Wire Line
	3000 5900 2300 5900
Wire Wire Line
	2300 5900 2300 6250
$Comp
L Device:R R?
U 1 1 6334E3E1
P 2000 5900
AR Path="/6334E3E1" Ref="R?"  Part="1" 
AR Path="/67F05B40/6334E3E1" Ref="R?"  Part="1" 
AR Path="/61A16067/6334E3E1" Ref="R71"  Part="1" 
AR Path="/63AEBE91/6334E3E1" Ref="R?"  Part="1" 
F 0 "R71" V 2100 5900 50  0000 C CNN
F 1 "100" V 2200 5900 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 1930 5900 50  0001 C CNN
F 3 "~" H 2000 5900 50  0001 C CNN
	1    2000 5900
	0    1    1    0   
$EndComp
Wire Wire Line
	1600 5900 1700 5900
Text GLabel 1600 5900 0    50   Input ~ 0
BAT2+
Connection ~ 1700 5900
Wire Wire Line
	1700 5900 1850 5900
Text GLabel 2600 6350 0    50   Input ~ 0
G2
Wire Wire Line
	2600 6350 2700 6350
Text GLabel 2450 7350 0    50   Input ~ 0
G2
Wire Wire Line
	3300 7450 3350 7450
Wire Wire Line
	3350 7450 3350 7700
Wire Wire Line
	2650 7450 2700 7450
Wire Wire Line
	3300 7350 3350 7350
Wire Wire Line
	1700 6450 1600 6450
$Comp
L Battery_Management:TP4056 U?
U 1 1 6334E3F4
P 2250 5300
AR Path="/6334E3F4" Ref="U?"  Part="1" 
AR Path="/67F05B40/6334E3F4" Ref="U?"  Part="1" 
AR Path="/61A16067/6334E3F4" Ref="U17"  Part="1" 
AR Path="/63AEBE91/6334E3F4" Ref="U?"  Part="1" 
F 0 "U17" H 2050 5650 50  0000 C CNN
F 1 "TP4056" H 2450 5650 50  0000 C CNN
F 2 "Package_SO:SOIC-8_5.275x5.275mm_P1.27mm" H 2100 5650 50  0001 C CNN
F 3 "" H 2100 5650 50  0001 C CNN
	1    2250 5300
	1    0    0    -1  
$EndComp
Wire Wire Line
	3550 7550 3300 7550
Wire Wire Line
	2700 7350 2450 7350
Wire Wire Line
	2650 7450 2650 7700
Wire Wire Line
	2700 7550 2450 7550
Wire Wire Line
	2150 5900 2300 5900
Connection ~ 2300 5900
Wire Wire Line
	3750 7450 3850 7450
Wire Wire Line
	3350 7700 2650 7700
Wire Wire Line
	3100 4800 3350 4800
Connection ~ 3100 4800
Wire Wire Line
	3050 5450 3350 5450
Wire Wire Line
	2650 5150 2850 5150
Wire Wire Line
	2250 4800 2850 4800
Wire Wire Line
	2850 4800 2850 5150
Connection ~ 2850 4800
Wire Wire Line
	2850 4800 3100 4800
Wire Wire Line
	1500 4800 2250 4800
Connection ~ 2250 4800
Wire Wire Line
	1350 5300 1350 5800
Wire Wire Line
	1350 5800 1750 5800
Wire Wire Line
	1700 5900 1700 6350
Wire Wire Line
	3350 7350 3350 7000
Wire Wire Line
	3400 6450 3300 6450
Wire Wire Line
	3850 6450 3700 6450
Connection ~ 3850 5800
Wire Wire Line
	2250 5800 3550 5800
Wire Wire Line
	3350 4800 3850 4800
Connection ~ 3350 4800
Wire Wire Line
	1700 7000 3350 7000
Wire Wire Line
	2300 6550 2300 6900
Wire Wire Line
	2300 6900 3000 6900
Wire Wire Line
	3000 6900 3000 6800
Wire Notes Line
	1700 5400 1700 5050
Wire Notes Line
	1700 5050 600  5050
Wire Notes Line
	600  5050 600  5850
Wire Notes Line
	600  5850 1400 5850
Wire Notes Line
	1400 5850 1400 5400
Wire Notes Line
	1400 5400 1700 5400
Connection ~ 3850 6450
Wire Wire Line
	3850 6450 3850 5800
Wire Wire Line
	3850 6450 3850 6850
Wire Wire Line
	1700 6450 1700 7000
Connection ~ 3550 5800
Wire Wire Line
	3550 5800 3850 5800
Wire Wire Line
	3850 5400 3850 5800
Wire Notes Line
	4150 4700 4150 7750
Wire Notes Line
	4150 7750 550  7750
Wire Notes Line
	550  7750 550  4700
Wire Notes Line
	550  4700 4150 4700
Text Notes 700  7350 0    50   ~ 0
Modulo de recarga com \nProte????o de Sobrecorrente\n
Text Notes 650  7650 0    50   ~ 0
VERIFICAR CORRENTE RECOMENDADA!!
Wire Wire Line
	1050 6650 1050 6800
Text GLabel 1300 6650 2    50   Input ~ 0
BAT2-
Wire Wire Line
	1300 6650 1050 6650
Wire Wire Line
	8300 750  8150 750 
Wire Wire Line
	5750 750  5350 750 
Wire Wire Line
	5350 750  5350 2100
Wire Wire Line
	2300 4000 1400 4000
Connection ~ 3650 4550
Wire Wire Line
	3650 4550 3650 4350
Text Notes 4400 5400 1    50   ~ 0
PORTA FUSIVEL\nP PCI
$Comp
L Connector:Conn_01x02_Female J?
U 1 1 61C949BA
P 950 3250
AR Path="/61C949BA" Ref="J?"  Part="1" 
AR Path="/67F05B40/61C949BA" Ref="J?"  Part="1" 
AR Path="/61A16067/61C949BA" Ref="J15"  Part="1" 
AR Path="/63AEBE91/61C949BA" Ref="J?"  Part="1" 
F 0 "J15" H 978 3226 50  0000 L CNN
F 1 "AUDIO" H 1000 3150 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x02_P2.00mm_Vertical" H 950 3250 50  0001 C CNN
F 3 "~" H 950 3250 50  0001 C CNN
	1    950  3250
	-1   0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 61C81513
P 5550 3200
AR Path="/61C81513" Ref="R?"  Part="1" 
AR Path="/61A16067/61C81513" Ref="R61"  Part="1" 
AR Path="/63AEBE91/61C81513" Ref="R?"  Part="1" 
F 0 "R61" V 5757 3200 50  0000 C CNN
F 1 "220" V 5666 3200 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 5480 3200 50  0001 C CNN
F 3 "~" H 5550 3200 50  0001 C CNN
	1    5550 3200
	1    0    0    1   
$EndComp
Wire Wire Line
	5550 3050 5550 2400
Wire Wire Line
	5550 2400 4400 2400
Connection ~ 4400 2400
Wire Wire Line
	4400 2400 4400 2800
Wire Wire Line
	5550 3450 5550 3350
Text GLabel 5700 3450 2    50   Input ~ 0
BUZZER
Wire Wire Line
	5700 3450 5550 3450
Text GLabel 3550 7550 2    50   Input ~ 0
BAT2-
$Comp
L power:GNDD #PWR?
U 1 1 626FB548
P 7600 1650
AR Path="/626FB548" Ref="#PWR?"  Part="1" 
AR Path="/61A16067/626FB548" Ref="#PWR0126"  Part="1" 
F 0 "#PWR0126" H 7600 1400 50  0001 C CNN
F 1 "GNDD" H 7604 1495 50  0000 C CNN
F 2 "" H 7600 1650 50  0001 C CNN
F 3 "" H 7600 1650 50  0001 C CNN
	1    7600 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	7600 1650 7600 1600
Wire Wire Line
	7400 1600 7600 1600
$Comp
L power:GNDD #PWR?
U 1 1 627305E5
P 9350 2850
AR Path="/627305E5" Ref="#PWR?"  Part="1" 
AR Path="/61A16067/627305E5" Ref="#PWR0127"  Part="1" 
F 0 "#PWR0127" H 9350 2600 50  0001 C CNN
F 1 "GNDD" H 9354 2695 50  0000 C CNN
F 2 "" H 9350 2850 50  0001 C CNN
F 3 "" H 9350 2850 50  0001 C CNN
	1    9350 2850
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 62741D80
P 9750 2850
AR Path="/62741D80" Ref="#PWR?"  Part="1" 
AR Path="/61A16067/62741D80" Ref="#PWR0128"  Part="1" 
F 0 "#PWR0128" H 9750 2600 50  0001 C CNN
F 1 "GNDD" H 9754 2695 50  0000 C CNN
F 2 "" H 9750 2850 50  0001 C CNN
F 3 "" H 9750 2850 50  0001 C CNN
	1    9750 2850
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 6275365A
P 8250 3950
AR Path="/6275365A" Ref="#PWR?"  Part="1" 
AR Path="/61A16067/6275365A" Ref="#PWR0129"  Part="1" 
F 0 "#PWR0129" H 8250 3700 50  0001 C CNN
F 1 "GNDD" H 8254 3795 50  0000 C CNN
F 2 "" H 8250 3950 50  0001 C CNN
F 3 "" H 8250 3950 50  0001 C CNN
	1    8250 3950
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 62764FD1
P 6550 3300
AR Path="/62764FD1" Ref="#PWR?"  Part="1" 
AR Path="/61A16067/62764FD1" Ref="#PWR0130"  Part="1" 
F 0 "#PWR0130" H 6550 3050 50  0001 C CNN
F 1 "GNDD" H 6554 3145 50  0000 C CNN
F 2 "" H 6550 3300 50  0001 C CNN
F 3 "" H 6550 3300 50  0001 C CNN
	1    6550 3300
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 62776A71
P 5800 2700
AR Path="/62776A71" Ref="#PWR?"  Part="1" 
AR Path="/61A16067/62776A71" Ref="#PWR0131"  Part="1" 
F 0 "#PWR0131" H 5800 2450 50  0001 C CNN
F 1 "GNDD" H 5804 2545 50  0000 C CNN
F 2 "" H 5800 2700 50  0001 C CNN
F 3 "" H 5800 2700 50  0001 C CNN
	1    5800 2700
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 62799ED2
P 3500 1850
AR Path="/62799ED2" Ref="#PWR?"  Part="1" 
AR Path="/61A16067/62799ED2" Ref="#PWR0132"  Part="1" 
F 0 "#PWR0132" H 3500 1600 50  0001 C CNN
F 1 "GNDD" H 3504 1695 50  0000 C CNN
F 2 "" H 3500 1850 50  0001 C CNN
F 3 "" H 3500 1850 50  0001 C CNN
	1    3500 1850
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 627AB901
P 1800 1150
AR Path="/627AB901" Ref="#PWR?"  Part="1" 
AR Path="/61A16067/627AB901" Ref="#PWR0133"  Part="1" 
F 0 "#PWR0133" H 1800 900 50  0001 C CNN
F 1 "GNDD" H 1804 995 50  0000 C CNN
F 2 "" H 1800 1150 50  0001 C CNN
F 3 "" H 1800 1150 50  0001 C CNN
	1    1800 1150
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 627BD297
P 2150 1950
AR Path="/627BD297" Ref="#PWR?"  Part="1" 
AR Path="/61A16067/627BD297" Ref="#PWR0134"  Part="1" 
F 0 "#PWR0134" H 2150 1700 50  0001 C CNN
F 1 "GNDD" H 2154 1795 50  0000 C CNN
F 2 "" H 2150 1950 50  0001 C CNN
F 3 "" H 2150 1950 50  0001 C CNN
	1    2150 1950
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 627CEC2E
P 1600 1950
AR Path="/627CEC2E" Ref="#PWR?"  Part="1" 
AR Path="/61A16067/627CEC2E" Ref="#PWR0135"  Part="1" 
F 0 "#PWR0135" H 1600 1700 50  0001 C CNN
F 1 "GNDD" H 1604 1795 50  0000 C CNN
F 2 "" H 1600 1950 50  0001 C CNN
F 3 "" H 1600 1950 50  0001 C CNN
	1    1600 1950
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 627E05CC
P 2150 4400
AR Path="/627E05CC" Ref="#PWR?"  Part="1" 
AR Path="/61A16067/627E05CC" Ref="#PWR0136"  Part="1" 
F 0 "#PWR0136" H 2150 4150 50  0001 C CNN
F 1 "GNDD" H 2154 4245 50  0000 C CNN
F 2 "" H 2150 4400 50  0001 C CNN
F 3 "" H 2150 4400 50  0001 C CNN
	1    2150 4400
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 627F1FDA
P 2550 3600
AR Path="/627F1FDA" Ref="#PWR?"  Part="1" 
AR Path="/61A16067/627F1FDA" Ref="#PWR0137"  Part="1" 
F 0 "#PWR0137" H 2550 3350 50  0001 C CNN
F 1 "GNDD" H 2554 3445 50  0000 C CNN
F 2 "" H 2550 3600 50  0001 C CNN
F 3 "" H 2550 3600 50  0001 C CNN
	1    2550 3600
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 62803797
P 3300 3750
AR Path="/62803797" Ref="#PWR?"  Part="1" 
AR Path="/61A16067/62803797" Ref="#PWR0138"  Part="1" 
F 0 "#PWR0138" H 3300 3500 50  0001 C CNN
F 1 "GNDD" H 3304 3595 50  0000 C CNN
F 2 "" H 3300 3750 50  0001 C CNN
F 3 "" H 3300 3750 50  0001 C CNN
	1    3300 3750
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 628151AF
P 4400 4050
AR Path="/628151AF" Ref="#PWR?"  Part="1" 
AR Path="/61A16067/628151AF" Ref="#PWR0139"  Part="1" 
F 0 "#PWR0139" H 4400 3800 50  0001 C CNN
F 1 "GNDD" H 4404 3895 50  0000 C CNN
F 2 "" H 4400 4050 50  0001 C CNN
F 3 "" H 4400 4050 50  0001 C CNN
	1    4400 4050
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 628269CC
P 3550 5850
AR Path="/628269CC" Ref="#PWR?"  Part="1" 
AR Path="/61A16067/628269CC" Ref="#PWR0140"  Part="1" 
F 0 "#PWR0140" H 3550 5600 50  0001 C CNN
F 1 "GNDD" H 3554 5695 50  0000 C CNN
F 2 "" H 3550 5850 50  0001 C CNN
F 3 "" H 3550 5850 50  0001 C CNN
	1    3550 5850
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 62838218
P 1050 6800
AR Path="/62838218" Ref="#PWR?"  Part="1" 
AR Path="/61A16067/62838218" Ref="#PWR0141"  Part="1" 
F 0 "#PWR0141" H 1050 6550 50  0001 C CNN
F 1 "GNDD" H 1054 6645 50  0000 C CNN
F 2 "" H 1050 6800 50  0001 C CNN
F 3 "" H 1050 6800 50  0001 C CNN
	1    1050 6800
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 6285BB14
P 6900 6300
AR Path="/6285BB14" Ref="#PWR?"  Part="1" 
AR Path="/61A16067/6285BB14" Ref="#PWR0142"  Part="1" 
F 0 "#PWR0142" H 6900 6050 50  0001 C CNN
F 1 "GNDD" H 6904 6145 50  0000 C CNN
F 2 "" H 6900 6300 50  0001 C CNN
F 3 "" H 6900 6300 50  0001 C CNN
	1    6900 6300
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 6286D48B
P 7700 6300
AR Path="/6286D48B" Ref="#PWR?"  Part="1" 
AR Path="/61A16067/6286D48B" Ref="#PWR0143"  Part="1" 
F 0 "#PWR0143" H 7700 6050 50  0001 C CNN
F 1 "GNDD" H 7704 6145 50  0000 C CNN
F 2 "" H 7700 6300 50  0001 C CNN
F 3 "" H 7700 6300 50  0001 C CNN
	1    7700 6300
	1    0    0    -1  
$EndComp
$EndSCHEMATC
