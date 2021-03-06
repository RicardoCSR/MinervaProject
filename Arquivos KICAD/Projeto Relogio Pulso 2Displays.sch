EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 5
Title "Micro"
Date "2021-11-15"
Rev "V 1.0"
Comp "Mufox"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Device:R R3
U 1 1 63422CB8
P 9550 1200
F 0 "R3" V 9757 1200 50  0000 C CNN
F 1 "10K" V 9666 1200 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 9480 1200 50  0001 C CNN
F 3 "~" H 9550 1200 50  0001 C CNN
	1    9550 1200
	0    1    -1   0   
$EndComp
$Comp
L power:GNDD #PWR03
U 1 1 63422CBE
P 10900 1600
F 0 "#PWR03" H 10900 1350 50  0001 C CNN
F 1 "GNDD" H 10904 1445 50  0000 C CNN
F 2 "" H 10900 1600 50  0001 C CNN
F 3 "" H 10900 1600 50  0001 C CNN
	1    10900 1600
	1    0    0    -1  
$EndComp
Wire Wire Line
	10900 1500 10900 1600
Text GLabel 9300 1200 0    50   Input ~ 0
HRST
Wire Wire Line
	9300 1200 9400 1200
$Comp
L Device:C C2
U 1 1 643BBCD6
P 10500 1500
F 0 "C2" V 10350 1500 50  0000 C CNN
F 1 "20pF" V 10250 1500 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 10538 1350 50  0001 C CNN
F 3 "~" H 10500 1500 50  0001 C CNN
	1    10500 1500
	0    -1   -1   0   
$EndComp
Wire Wire Line
	9700 1200 9900 1200
Wire Wire Line
	10650 1500 10900 1500
Connection ~ 10900 1500
Wire Wire Line
	10050 1500 10050 1400
Wire Wire Line
	10050 1500 10350 1500
Wire Wire Line
	10050 1000 10050 900 
Wire Wire Line
	10900 900  10900 1500
Wire Notes Line
	550  5550 550  550 
Wire Notes Line
	3250 550  3250 5550
Wire Notes Line
	550  550  3250 550 
Wire Notes Line
	550  5550 3250 5550
Wire Notes Line
	11100 550  11100 2300
Wire Notes Line
	11100 2300 8900 2300
Wire Notes Line
	8900 2300 8900 550 
Text Notes 9000 2200 0    50   ~ 0
1 - 2 Habilita botao Reset da Placa\n2 - 3 Mantem Pino Forçado em Zero
$Sheet
S -1900 2050 1850 500 
U 67AE4A42
F0 "Inferior Board" 50
F1 "Nixie.sch" 50
$EndSheet
$Sheet
S -1900 2800 1850 500 
U 67F05B40
F0 "Superior Board" 50
F1 "Power.sch" 50
$EndSheet
$Comp
L Device:R R2
U 1 1 61CC0A69
P 7450 1150
F 0 "R2" V 7657 1150 50  0000 C CNN
F 1 "1M" V 7566 1150 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 7380 1150 50  0001 C CNN
F 3 "~" H 7450 1150 50  0001 C CNN
	1    7450 1150
	-1   0    0    -1  
$EndComp
Text GLabel 8300 900  2    50   Input ~ 0
SLEEP
Wire Notes Line
	6800 550  8850 550 
$Comp
L Piezo:DiscPiezo P1
U 1 1 630BE4D1
P 7100 1150
F 0 "P1" V 6875 1150 50  0000 C CNN
F 1 "DiscPiezo" V 6966 1150 50  0000 C CNN
F 2 "Connector_PinHeader_1.27mm:PinHeader_1x02_P1.27mm_Vertical" H 7200 1200 50  0001 C CNN
F 3 "" H 7200 1200 50  0001 C CNN
	1    7100 1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	7450 1000 7450 900 
Wire Wire Line
	7450 900  8300 900 
$Comp
L Device:R R5
U 1 1 63547CFC
P 7450 2000
F 0 "R5" V 7657 2000 50  0000 C CNN
F 1 "1M" V 7566 2000 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 7380 2000 50  0001 C CNN
F 3 "~" H 7450 2000 50  0001 C CNN
	1    7450 2000
	-1   0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR02
U 1 1 63547D02
P 7450 1500
F 0 "#PWR02" H 7450 1250 50  0001 C CNN
F 1 "GNDD" H 7454 1345 50  0000 C CNN
F 2 "" H 7450 1500 50  0001 C CNN
F 3 "" H 7450 1500 50  0001 C CNN
	1    7450 1500
	1    0    0    -1  
$EndComp
Text GLabel 8300 1750 2    50   Input ~ 0
UP
$Comp
L Piezo:DiscPiezo P2
U 1 1 63547D0A
P 7100 2000
F 0 "P2" V 6875 2000 50  0000 C CNN
F 1 "DiscPiezo" V 6966 2000 50  0000 C CNN
F 2 "Connector_PinHeader_1.27mm:PinHeader_1x02_P1.27mm_Vertical" H 7200 2050 50  0001 C CNN
F 3 "" H 7200 2050 50  0001 C CNN
	1    7100 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	7100 1750 7450 1750
Wire Wire Line
	7450 1850 7450 1750
Connection ~ 7450 1750
Wire Wire Line
	7450 1750 8300 1750
Wire Wire Line
	7100 2250 7450 2250
Wire Wire Line
	7450 2150 7450 2250
$Comp
L Device:R R6
U 1 1 635B4632
P 7450 2850
F 0 "R6" V 7657 2850 50  0000 C CNN
F 1 "1M" V 7566 2850 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 7380 2850 50  0001 C CNN
F 3 "~" H 7450 2850 50  0001 C CNN
	1    7450 2850
	-1   0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR04
U 1 1 635B4638
P 7450 2350
F 0 "#PWR04" H 7450 2100 50  0001 C CNN
F 1 "GNDD" H 7454 2195 50  0000 C CNN
F 2 "" H 7450 2350 50  0001 C CNN
F 3 "" H 7450 2350 50  0001 C CNN
	1    7450 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	7450 2250 7450 2350
Text GLabel 8300 2600 2    50   Input ~ 0
DOWN
$Comp
L Piezo:DiscPiezo P3
U 1 1 635B4640
P 7100 2850
F 0 "P3" V 6875 2850 50  0000 C CNN
F 1 "DiscPiezo" V 6966 2850 50  0000 C CNN
F 2 "Connector_PinHeader_1.27mm:PinHeader_1x02_P1.27mm_Vertical" H 7200 2900 50  0001 C CNN
F 3 "" H 7200 2900 50  0001 C CNN
	1    7100 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	7100 2600 7450 2600
Wire Wire Line
	7450 2700 7450 2600
Connection ~ 7450 2600
Wire Wire Line
	7450 2600 8300 2600
Wire Wire Line
	7100 3100 7450 3100
Wire Wire Line
	7450 3000 7450 3100
Connection ~ 7450 2250
$Comp
L power:GNDD #PWR06
U 1 1 638A7B89
P 7450 3200
F 0 "#PWR06" H 7450 2950 50  0001 C CNN
F 1 "GNDD" H 7454 3045 50  0000 C CNN
F 2 "" H 7450 3200 50  0001 C CNN
F 3 "" H 7450 3200 50  0001 C CNN
	1    7450 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	7450 3200 7450 3100
Connection ~ 7450 3100
$Comp
L Device:R R7
U 1 1 639EE436
P 7450 3700
F 0 "R7" V 7657 3700 50  0000 C CNN
F 1 "1M" V 7566 3700 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 7380 3700 50  0001 C CNN
F 3 "~" H 7450 3700 50  0001 C CNN
	1    7450 3700
	-1   0    0    -1  
$EndComp
Text GLabel 8300 3450 2    50   Input ~ 0
MODE
$Comp
L Piezo:DiscPiezo P5
U 1 1 639EE43D
P 7100 3700
F 0 "P5" V 6875 3700 50  0000 C CNN
F 1 "DiscPiezo" V 6966 3700 50  0000 C CNN
F 2 "Connector_PinHeader_1.27mm:PinHeader_1x02_P1.27mm_Vertical" H 7200 3750 50  0001 C CNN
F 3 "" H 7200 3750 50  0001 C CNN
	1    7100 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	7100 3450 7450 3450
Wire Wire Line
	7450 3550 7450 3450
Connection ~ 7450 3450
Wire Wire Line
	7450 3450 8300 3450
Wire Wire Line
	7100 3950 7450 3950
Wire Wire Line
	7450 3850 7450 3950
$Comp
L power:GNDD #PWR08
U 1 1 639EE449
P 7450 4050
F 0 "#PWR08" H 7450 3800 50  0001 C CNN
F 1 "GNDD" H 7454 3895 50  0000 C CNN
F 2 "" H 7450 4050 50  0001 C CNN
F 3 "" H 7450 4050 50  0001 C CNN
	1    7450 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	7450 4050 7450 3950
Connection ~ 7450 3950
Text Notes 6850 750  0    50   ~ 0
*DEIXA A BARRA PARA SOLDAGEM DO PIEZO
Wire Notes Line
	11100 550  8900 550 
Wire Notes Line
	8850 550  8850 4400
Wire Notes Line
	8850 4400 6800 4400
Wire Notes Line
	6800 4400 6800 550 
$Sheet
S -1900 1300 1850 500 
U 61A16067
F0 "External Board" 50
F1 "Geiger Circuit.sch" 50
$EndSheet
Wire Notes Line
	8900 2350 11100 2350
Wire Notes Line
	11100 2350 11100 5650
Wire Notes Line
	11100 5650 8900 5650
Wire Notes Line
	8900 5650 8900 2350
$Comp
L Connector:Conn_01x02_Female J7
U 1 1 621E30EA
P 10700 5950
AR Path="/621E30EA" Ref="J7"  Part="1" 
AR Path="/67F05B40/621E30EA" Ref="J?"  Part="1" 
F 0 "J7" H 10800 5850 50  0000 C CNN
F 1 "CRYSTAL" H 10900 5950 50  0000 C CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x02_P2.00mm_Vertical" H 10700 5950 50  0001 C CNN
F 3 "~" H 10700 5950 50  0001 C CNN
	1    10700 5950
	1    0    0    1   
$EndComp
Wire Wire Line
	7450 1300 7450 1400
Wire Wire Line
	7100 900  7450 900 
Connection ~ 7450 900 
Wire Wire Line
	7100 1400 7450 1400
Connection ~ 7450 1400
Wire Wire Line
	7450 1400 7450 1500
$Comp
L Connector:Conn_01x02_Male J1
U 1 1 61C0BE7E
P 10550 650
F 0 "J1" V 10612 694 50  0000 L CNN
F 1 "RST" V 10703 694 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x02_P2.00mm_Vertical" H 10550 650 50  0001 C CNN
F 3 "~" H 10550 650 50  0001 C CNN
	1    10550 650 
	0    1    1    0   
$EndComp
Wire Wire Line
	10450 900  10450 850 
Wire Wire Line
	10050 900  10450 900 
Wire Wire Line
	10550 850  10550 900 
Wire Wire Line
	10550 900  10900 900 
Text GLabel 10350 5850 0    50   Input ~ 0
OSC1
Wire Wire Line
	10350 5850 10500 5850
Text GLabel 10350 5950 0    50   Input ~ 0
OSC2
Wire Wire Line
	10500 5950 10350 5950
$Comp
L Jumper:SolderJumper_3_Open JP1
U 1 1 61DE4752
P 10050 1200
F 0 "JP1" V 10004 1268 50  0000 L CNN
F 1 "RST" V 10095 1268 50  0000 L CNN
F 2 "Jumper:SolderJumper-3_P1.3mm_Open_RoundedPad1.0x1.5mm_NumberLabels" H 10050 1200 50  0001 C CNN
F 3 "~" H 10050 1200 50  0001 C CNN
	1    10050 1200
	0    1    1    0   
$EndComp
Text GLabel 3150 5900 2    50   Input ~ 0
DCDC
Text GLabel 800  6300 0    50   Input ~ 0
5VA
Wire Wire Line
	1000 6300 800  6300
Text GLabel 1150 5900 0    50   Input ~ 0
BAT2+
Wire Wire Line
	3150 5900 3000 5900
Connection ~ 1000 7000
Wire Wire Line
	1000 7000 1000 6750
Wire Wire Line
	1000 6300 1000 6450
$Comp
L Diode:BZD27Cxx D4
U 1 1 63028635
P 1000 6600
AR Path="/63028635" Ref="D4"  Part="1" 
AR Path="/67F05B40/63028635" Ref="D?"  Part="1" 
F 0 "D4" V 954 6679 50  0000 L CNN
F 1 "BZD27Cxx" V 1045 6679 50  0000 L CNN
F 2 "Diode_SMD:D_2114_3652Metric_Castellated" H 1000 6425 50  0001 C CNN
F 3 "https://www.vishay.com/docs/85153/bzd27series.pdf" H 1000 6600 50  0001 C CNN
	1    1000 6600
	0    1    1    0   
$EndComp
Wire Wire Line
	1000 7000 1150 7000
Wire Wire Line
	1000 7150 1000 7000
$Comp
L Device:R R17
U 1 1 63028645
P 1000 7300
AR Path="/63028645" Ref="R17"  Part="1" 
AR Path="/67F05B40/63028645" Ref="R?"  Part="1" 
F 0 "R17" H 931 7254 50  0000 R CNN
F 1 "100R" H 931 7345 50  0000 R CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 930 7300 50  0001 C CNN
F 3 "~" H 1000 7300 50  0001 C CNN
	1    1000 7300
	1    0    0    1   
$EndComp
Wire Wire Line
	1450 7000 1600 7000
$Comp
L Device:R R16
U 1 1 6302864C
P 1300 7000
AR Path="/6302864C" Ref="R16"  Part="1" 
AR Path="/67F05B40/6302864C" Ref="R?"  Part="1" 
F 0 "R16" V 1507 7000 50  0000 C CNN
F 1 "1K" V 1416 7000 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 1230 7000 50  0001 C CNN
F 3 "~" H 1300 7000 50  0001 C CNN
	1    1300 7000
	0    1    -1   0   
$EndComp
Connection ~ 1900 6700
Wire Wire Line
	1900 6800 1900 6700
$Comp
L Transistor_BJT:BC548 Q7
U 1 1 63028654
P 1800 7000
AR Path="/63028654" Ref="Q7"  Part="1" 
AR Path="/67F05B40/63028654" Ref="Q?"  Part="1" 
F 0 "Q7" H 1991 7046 50  0000 L CNN
F 1 "BC548" H 1991 6955 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 2000 6925 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/BC/BC547.pdf" H 1800 7000 50  0001 L CNN
	1    1800 7000
	1    0    0    -1  
$EndComp
Wire Wire Line
	1900 5900 2500 5900
Wire Wire Line
	2350 6700 2500 6700
Wire Wire Line
	1900 6700 1900 6300
Wire Wire Line
	2050 6700 1900 6700
$Comp
L Device:R R15
U 1 1 63028660
P 2200 6700
AR Path="/63028660" Ref="R15"  Part="1" 
AR Path="/67F05B40/63028660" Ref="R?"  Part="1" 
F 0 "R15" V 2407 6700 50  0000 C CNN
F 1 "1K" V 2316 6700 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2130 6700 50  0001 C CNN
F 3 "~" H 2200 6700 50  0001 C CNN
	1    2200 6700
	0    1    -1   0   
$EndComp
Connection ~ 2800 6400
Wire Wire Line
	2800 6500 2800 6400
$Comp
L Transistor_BJT:BC548 Q6
U 1 1 63028668
P 2700 6700
AR Path="/63028668" Ref="Q6"  Part="1" 
AR Path="/67F05B40/63028668" Ref="Q?"  Part="1" 
F 0 "Q6" H 2891 6746 50  0000 L CNN
F 1 "BC548" H 2891 6655 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 2900 6625 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/BC/BC547.pdf" H 2700 6700 50  0001 L CNN
	1    2700 6700
	1    0    0    -1  
$EndComp
Wire Wire Line
	1900 6000 1900 5900
$Comp
L Device:R R12
U 1 1 6302866F
P 1900 6150
AR Path="/6302866F" Ref="R12"  Part="1" 
AR Path="/67F05B40/6302866F" Ref="R?"  Part="1" 
F 0 "R12" H 1830 6196 50  0000 R CNN
F 1 "200K" H 1830 6105 50  0000 R CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 1830 6150 50  0001 C CNN
F 3 "~" H 1900 6150 50  0001 C CNN
	1    1900 6150
	-1   0    0    -1  
$EndComp
Connection ~ 2500 5900
Wire Wire Line
	1150 5900 1400 5900
Wire Wire Line
	2800 6400 2800 6200
Wire Wire Line
	2500 6400 2800 6400
Wire Wire Line
	2500 6300 2500 6400
Wire Wire Line
	2500 5900 2600 5900
Wire Wire Line
	2500 6000 2500 5900
$Comp
L Device:R R13
U 1 1 6302867C
P 2500 6150
AR Path="/6302867C" Ref="R13"  Part="1" 
AR Path="/67F05B40/6302867C" Ref="R?"  Part="1" 
F 0 "R13" H 2430 6196 50  0000 R CNN
F 1 "1M" H 2430 6105 50  0000 R CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2430 6150 50  0001 C CNN
F 3 "~" H 2500 6150 50  0001 C CNN
	1    2500 6150
	-1   0    0    -1  
$EndComp
$Comp
L Transistor_BJT:BC548 Q5
U 1 1 63028682
P 2800 6000
AR Path="/63028682" Ref="Q5"  Part="1" 
AR Path="/67F05B40/63028682" Ref="Q?"  Part="1" 
F 0 "Q5" V 3100 6000 50  0000 C CNN
F 1 "BC548" V 3000 6000 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 3000 5925 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/BC/BC547.pdf" H 2800 6000 50  0001 L CNN
	1    2800 6000
	0    -1   -1   0   
$EndComp
$Comp
L power:GNDD #PWR018
U 1 1 6302863C
P 1000 7600
AR Path="/6302863C" Ref="#PWR018"  Part="1" 
AR Path="/67F05B40/6302863C" Ref="#PWR?"  Part="1" 
F 0 "#PWR018" H 1000 7350 50  0001 C CNN
F 1 "GNDD" H 1004 7445 50  0000 C CNN
F 2 "" H 1000 7600 50  0001 C CNN
F 3 "" H 1000 7600 50  0001 C CNN
	1    1000 7600
	1    0    0    -1  
$EndComp
Wire Wire Line
	2800 7050 2800 6900
Wire Wire Line
	1900 7350 1900 7200
Wire Wire Line
	1000 7600 1000 7450
Wire Notes Line
	550  5600 550  7850
Text Notes 8050 4350 0    50   ~ 0
Botões de comando
Text Notes 2200 7750 0    50   ~ 0
Seletor de alimentação para 5V
Text GLabel 1150 5750 0    50   Input ~ 0
BAT1+
Wire Wire Line
	1150 5750 1400 5750
$Comp
L Diode:1N5819 D2
U 1 1 633BC07A
P 1550 5750
AR Path="/633BC07A" Ref="D2"  Part="1" 
AR Path="/67F05B40/633BC07A" Ref="D?"  Part="1" 
F 0 "D2" H 1650 5650 50  0000 C CNN
F 1 "1N5819" H 1400 5650 50  0000 C CNN
F 2 "Diode_SMD:D_0805_2012Metric" H 1550 5575 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88525/1n5817.pdf" H 1550 5750 50  0001 C CNN
	1    1550 5750
	-1   0    0    1   
$EndComp
$Comp
L Diode:1N5819 D3
U 1 1 633BCE6E
P 1550 5900
AR Path="/633BCE6E" Ref="D3"  Part="1" 
AR Path="/67F05B40/633BCE6E" Ref="D?"  Part="1" 
F 0 "D3" H 1650 5800 50  0000 C CNN
F 1 "1N5819" H 1400 5800 50  0000 C CNN
F 2 "Diode_SMD:D_0805_2012Metric" H 1550 5725 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88525/1n5817.pdf" H 1550 5900 50  0001 C CNN
	1    1550 5900
	-1   0    0    -1  
$EndComp
Wire Wire Line
	1700 5900 1900 5900
Connection ~ 1900 5900
Wire Wire Line
	1700 5750 1900 5750
Wire Wire Line
	1900 5750 1900 5900
Wire Notes Line
	3500 5600 3500 7850
Wire Notes Line
	3500 5600 550  5600
Wire Notes Line
	550  7850 3500 7850
$Comp
L Connector:Conn_01x02_Female J6
U 1 1 61C15310
P 9250 5850
AR Path="/61C15310" Ref="J6"  Part="1" 
AR Path="/67F05B40/61C15310" Ref="J?"  Part="1" 
F 0 "J6" H 9350 5850 50  0000 L CNN
F 1 "BAT_IN" H 9300 5750 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x02_P2.00mm_Vertical" H 9250 5850 50  0001 C CNN
F 3 "~" H 9250 5850 50  0001 C CNN
	1    9250 5850
	-1   0    0    -1  
$EndComp
Text GLabel 9550 5850 2    50   Input ~ 0
IN_BAT+
Text GLabel 9550 5950 2    50   Input ~ 0
IN_BAT-
Wire Wire Line
	9550 5850 9450 5850
Wire Wire Line
	9550 5950 9450 5950
Wire Notes Line
	11100 5700 11100 6450
$Comp
L RF_Module:ESP32-WROOM-32 U1
U 1 1 62597C8A
P 1700 2050
F 0 "U1" H 1250 3400 50  0000 C CNN
F 1 "ESP32-WROOM-32" H 2100 3400 50  0000 C CNN
F 2 "RF_Module:ESP32-WROOM-32" H 1700 550 50  0001 C CNN
F 3 "https://www.espressif.com/sites/default/files/documentation/esp32-wroom-32_datasheet_en.pdf" H 1400 2100 50  0001 C CNN
	1    1700 2050
	1    0    0    -1  
$EndComp
Text GLabel 2450 950  2    50   Input ~ 0
TX0
Text GLabel 2450 1150 2    50   Input ~ 0
RX0
Wire Wire Line
	2450 950  2300 950 
Wire Wire Line
	2450 1150 2300 1150
Wire Wire Line
	1700 3450 1700 3550
$Comp
L power:GNDD #PWR07
U 1 1 625BEAB4
P 1700 3550
F 0 "#PWR07" H 1700 3300 50  0001 C CNN
F 1 "GNDD" H 1704 3395 50  0000 C CNN
F 2 "" H 1700 3550 50  0001 C CNN
F 3 "" H 1700 3550 50  0001 C CNN
	1    1700 3550
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x03_Male J4
U 1 1 625DD7AB
P 1650 5000
F 0 "J4" H 1550 4950 50  0000 C CNN
F 1 "UART" H 1500 5050 50  0000 C CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x03_P2.00mm_Vertical" H 1650 5000 50  0001 C CNN
F 3 "~" H 1650 5000 50  0001 C CNN
	1    1650 5000
	-1   0    0    -1  
$EndComp
Text GLabel 1300 4900 0    50   Input ~ 0
TX0
Text GLabel 1300 5000 0    50   Input ~ 0
RX0
Wire Wire Line
	1300 4900 1450 4900
Wire Wire Line
	1300 5000 1450 5000
$Comp
L power:GNDD #PWR011
U 1 1 62603F0F
P 1300 5100
F 0 "#PWR011" H 1300 4850 50  0001 C CNN
F 1 "GNDD" V 1300 4900 50  0000 C CNN
F 2 "" H 1300 5100 50  0001 C CNN
F 3 "" H 1300 5100 50  0001 C CNN
	1    1300 5100
	0    1    -1   0   
$EndComp
Wire Wire Line
	1300 5100 1450 5100
Text GLabel 2450 2950 2    50   Input ~ 0
ANODE_NIXIE_A
Wire Wire Line
	2300 2950 2450 2950
Text GLabel 2450 2850 2    50   Input ~ 0
ANODE_NIXIE_B
Wire Wire Line
	2300 2850 2450 2850
Text GLabel 2450 2750 2    50   Input ~ 0
LEVEL_D
Text GLabel 2450 2650 2    50   Input ~ 0
LEVEL_C
Wire Wire Line
	2450 2650 2300 2650
Wire Wire Line
	2450 2750 2300 2750
Text GLabel 2450 1450 2    50   Input ~ 0
SLEEP
Text GLabel 2450 1650 2    50   Input ~ 0
UP
Text GLabel 2450 1550 2    50   Input ~ 0
MODE
Wire Wire Line
	2450 1450 2300 1450
Wire Wire Line
	2450 1550 2300 1550
Wire Wire Line
	2450 1650 2300 1650
Wire Wire Line
	2450 1750 2300 1750
Text GLabel 2450 3050 2    50   Input ~ 0
ANODE_NIXIE_C
Wire Wire Line
	2300 3050 2450 3050
Text GLabel 2450 3150 2    50   Input ~ 0
ANODE_NIXIE_D
Wire Wire Line
	2300 3150 2450 3150
Text GLabel 2450 2350 2    50   Input ~ 0
SCL_BME280
Text GLabel 2450 2250 2    50   Input ~ 0
SDA_BME280
Wire Wire Line
	2450 2350 2300 2350
Wire Wire Line
	2450 2250 2300 2250
Text GLabel 2450 1750 2    50   Input ~ 0
DOWN
Text GLabel 2450 1850 2    50   Input ~ 0
RX2
Text GLabel 2450 1950 2    50   Input ~ 0
TX2
Wire Wire Line
	2450 1850 2300 1850
Wire Wire Line
	2450 1950 2300 1950
Wire Wire Line
	2450 2550 2300 2550
Wire Wire Line
	2450 2450 2300 2450
Text GLabel 2450 2450 2    50   Input ~ 0
LEVEL_A
Text GLabel 2450 2550 2    50   Input ~ 0
LEVEL_B
Text GLabel 2450 2150 2    50   Input ~ 0
WIFI_LED
Wire Wire Line
	2450 2150 2300 2150
$Comp
L Transistor_BJT:BC817 Q1
U 1 1 627E9C31
P 6250 950
F 0 "Q1" H 6441 996 50  0000 L CNN
F 1 "BC817" H 6441 905 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 6450 875 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/BC818-D.pdf" H 6250 950 50  0001 L CNN
	1    6250 950 
	1    0    0    -1  
$EndComp
Text GLabel 950  850  0    50   Input ~ 0
EN
Wire Wire Line
	950  850  1050 850 
$Comp
L Transistor_BJT:BC817 Q2
U 1 1 6281FCF9
P 6250 1550
F 0 "Q2" H 6441 1596 50  0000 L CNN
F 1 "BC817" H 6441 1505 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 6450 1475 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/BC818-D.pdf" H 6250 1550 50  0001 L CNN
	1    6250 1550
	1    0    0    -1  
$EndComp
Text GLabel 2450 850  2    50   Input ~ 0
IO0
Wire Wire Line
	2450 850  2300 850 
Text GLabel 6250 1850 0    50   Input ~ 0
IO0
$Comp
L Device:R R1
U 1 1 6285297B
P 5800 950
AR Path="/6285297B" Ref="R1"  Part="1" 
AR Path="/67F05B40/6285297B" Ref="R?"  Part="1" 
F 0 "R1" V 6007 950 50  0000 C CNN
F 1 "10K" V 5916 950 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 5730 950 50  0001 C CNN
F 3 "~" H 5800 950 50  0001 C CNN
	1    5800 950 
	0    1    -1   0   
$EndComp
$Comp
L Device:R R4
U 1 1 62853C6D
P 5800 1550
AR Path="/62853C6D" Ref="R4"  Part="1" 
AR Path="/67F05B40/62853C6D" Ref="R?"  Part="1" 
F 0 "R4" V 6007 1550 50  0000 C CNN
F 1 "10K" V 5916 1550 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 5730 1550 50  0001 C CNN
F 3 "~" H 5800 1550 50  0001 C CNN
	1    5800 1550
	0    1    -1   0   
$EndComp
Wire Wire Line
	5950 1550 6050 1550
Wire Wire Line
	5950 950  6050 950 
Text GLabel 6250 650  0    50   Input ~ 0
EN
Wire Wire Line
	6250 650  6350 650 
Wire Wire Line
	6350 650  6350 750 
Text GLabel 5500 1200 0    50   Input ~ 0
RST
Text GLabel 5500 1300 0    50   Input ~ 0
DTR
Wire Wire Line
	6350 1300 6350 1350
Wire Wire Line
	5500 1300 5600 1300
Wire Wire Line
	6350 1150 6350 1200
Wire Wire Line
	5500 1200 5550 1200
Wire Wire Line
	5650 950  5600 950 
Wire Wire Line
	5600 950  5600 1300
Connection ~ 5600 1300
Wire Wire Line
	5600 1300 6350 1300
Wire Wire Line
	5550 1200 5550 1550
Wire Wire Line
	5550 1550 5650 1550
Connection ~ 5550 1200
Wire Wire Line
	5550 1200 6350 1200
Wire Wire Line
	6250 1850 6350 1850
Wire Wire Line
	6350 1850 6350 1750
$Comp
L Interface_USB:CP2102N-A01-GQFN24 U2
U 1 1 629814B3
P 4450 2050
F 0 "U2" H 4050 2850 50  0000 C CNN
F 1 "CP2102N-A01-GQFN24" H 5050 1250 50  0000 C CNN
F 2 "Package_DFN_QFN:QFN-24-1EP_4x4mm_P0.5mm_EP2.6x2.6mm" H 4900 1250 50  0001 L CNN
F 3 "https://www.silabs.com/documents/public/data-sheets/cp2102n-datasheet.pdf" H 4500 1000 50  0001 C CNN
	1    4450 2050
	1    0    0    -1  
$EndComp
$Comp
L Connector:USB_C_Plug P4
U 1 1 629E4A45
P 10200 3550
AR Path="/629E4A45" Ref="P4"  Part="1" 
AR Path="/67F05B40/629E4A45" Ref="P?"  Part="1" 
F 0 "P4" H 9650 4550 50  0000 C CNN
F 1 "USB_C_Plug" H 9550 4450 50  0000 C CNN
F 2 "Connector_USB:USB_C_Receptacle_Palconn_UTC16-G" H 10350 3550 50  0001 C CNN
F 3 "https://www.usb.org/sites/default/files/documents/usb_type-c.zip" H 10350 3550 50  0001 C CNN
	1    10200 3550
	-1   0    0    -1  
$EndComp
Wire Wire Line
	9350 2550 9500 2550
Text GLabel 9350 2550 0    50   Input ~ 0
VIN
Wire Wire Line
	10500 5250 10500 5350
Wire Wire Line
	10500 5250 10200 5250
Wire Wire Line
	10200 5250 10200 5150
Wire Wire Line
	10500 5150 10500 5250
Connection ~ 10500 5250
Wire Wire Line
	9600 2750 9400 2750
Wire Wire Line
	9400 2750 9400 2850
Wire Wire Line
	9400 5250 10200 5250
Connection ~ 10200 5250
Wire Wire Line
	9600 2850 9400 2850
Connection ~ 9400 2850
Wire Wire Line
	9400 2850 9400 5250
Text GLabel 9250 3550 0    50   Input ~ 0
RX1-
Text GLabel 9250 3850 0    50   Input ~ 0
TX1-
Text GLabel 9250 3650 0    50   Input ~ 0
RX1+
Text GLabel 9250 3950 0    50   Input ~ 0
TX1+
Text GLabel 9250 4150 0    50   Input ~ 0
RX2-
Text GLabel 9250 4450 0    50   Input ~ 0
TX2-
Text GLabel 9250 4250 0    50   Input ~ 0
RX2+
Text GLabel 9250 4550 0    50   Input ~ 0
TX2+
Wire Wire Line
	9600 3550 9250 3550
Wire Wire Line
	9250 3650 9600 3650
Wire Wire Line
	9600 3850 9250 3850
Wire Wire Line
	9250 3950 9600 3950
Wire Wire Line
	9600 4150 9250 4150
Wire Wire Line
	9250 4250 9600 4250
Wire Wire Line
	9600 4450 9250 4450
Wire Wire Line
	9250 4550 9600 4550
Text GLabel 9250 3050 0    50   Input ~ 0
RX0
Text GLabel 9250 3250 0    50   Input ~ 0
TX0
Wire Wire Line
	9600 3050 9250 3050
Wire Wire Line
	9250 3250 9600 3250
Text GLabel 5200 2050 2    50   Input ~ 0
DTR
Wire Wire Line
	5050 2050 5200 2050
Text GLabel 9350 2450 0    50   Input ~ 0
REGIN
Wire Wire Line
	9350 2450 9500 2450
Wire Wire Line
	9500 2450 9500 2550
Connection ~ 9500 2550
Wire Wire Line
	9500 2550 9600 2550
Text GLabel 3700 2050 0    50   Input ~ 0
REGIN
Wire Wire Line
	3700 2050 3850 2050
Text GLabel 3700 2450 0    50   Input ~ 0
RX0
Text GLabel 3700 2550 0    50   Input ~ 0
TX0
Wire Wire Line
	3700 2350 3850 2350
Text GLabel 3700 2350 0    50   Input ~ 0
VIN
Wire Wire Line
	3700 2450 3850 2450
Wire Wire Line
	3700 2550 3850 2550
Text GLabel 5200 2150 2    50   Input ~ 0
RST
Wire Wire Line
	5050 2150 5200 2150
Wire Wire Line
	4550 2950 4550 3050
Wire Wire Line
	4550 3050 4500 3050
Wire Wire Line
	4450 3050 4450 2950
Wire Wire Line
	4500 3150 4500 3050
Connection ~ 4500 3050
Wire Wire Line
	4500 3050 4450 3050
$Comp
L Device:C C1
U 1 1 62BFB787
P 4100 900
F 0 "C1" V 3848 900 50  0000 C CNN
F 1 "20pF" V 3939 900 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 4138 750 50  0001 C CNN
F 3 "~" H 4100 900 50  0001 C CNN
	1    4100 900 
	0    1    1    0   
$EndComp
Wire Wire Line
	4250 900  4350 900 
Wire Wire Line
	4350 900  4350 1150
Wire Wire Line
	4450 1150 4450 900 
Wire Wire Line
	4450 900  4350 900 
Connection ~ 4350 900 
Wire Wire Line
	3800 1000 3800 900 
Wire Wire Line
	3800 900  3950 900 
Wire Wire Line
	1300 4600 1400 4600
Wire Wire Line
	1300 4500 1450 4500
Text GLabel 1300 4600 0    50   Input ~ 0
LDR_SENSOR
Text GLabel 1300 4500 0    50   Input ~ 0
LDR_POWER
$Comp
L Device:R R?
U 1 1 62CCC743
P 1150 4700
AR Path="/67AE4A42/62CCC743" Ref="R?"  Part="1" 
AR Path="/62CCC743" Ref="R8"  Part="1" 
AR Path="/67F05B40/62CCC743" Ref="R?"  Part="1" 
F 0 "R8" V 1050 4650 50  0000 C CNN
F 1 "10K" V 1050 4800 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 1080 4700 50  0001 C CNN
F 3 "~" H 1150 4700 50  0001 C CNN
	1    1150 4700
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1300 4700 1400 4700
Wire Wire Line
	1400 4700 1400 4600
Connection ~ 1400 4600
Wire Wire Line
	1400 4600 1450 4600
$Comp
L power:GNDD #PWR010
U 1 1 62CCC74D
P 850 4700
AR Path="/62CCC74D" Ref="#PWR010"  Part="1" 
AR Path="/67F05B40/62CCC74D" Ref="#PWR?"  Part="1" 
F 0 "#PWR010" H 850 4450 50  0001 C CNN
F 1 "GNDD" V 850 4500 50  0000 C CNN
F 2 "" H 850 4700 50  0001 C CNN
F 3 "" H 850 4700 50  0001 C CNN
	1    850  4700
	0    1    -1   0   
$EndComp
Wire Wire Line
	850  4700 1000 4700
Text GLabel 1300 4300 0    50   Input ~ 0
3V3
Wire Wire Line
	1450 4300 1300 4300
$Comp
L Connector:Conn_01x04_Male J2
U 1 1 62CE9FF0
P 1650 4100
F 0 "J2" H 1550 4000 50  0000 C CNN
F 1 "BME280" H 1450 4100 50  0000 C CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_2x02_P2.00mm_Vertical" H 1650 4100 50  0001 C CNN
F 3 "~" H 1650 4100 50  0001 C CNN
	1    1650 4100
	-1   0    0    -1  
$EndComp
Text GLabel 1300 4100 0    50   Input ~ 0
SCL_BME280
Text GLabel 1300 4000 0    50   Input ~ 0
SDA_BME280
Wire Wire Line
	1300 4100 1450 4100
Wire Wire Line
	1300 4000 1450 4000
Wire Wire Line
	1450 4200 1350 4200
$Comp
L power:GNDD #PWR09
U 1 1 62D4346F
P 1350 4200
F 0 "#PWR09" H 1350 3950 50  0001 C CNN
F 1 "GNDD" V 1350 4000 50  0000 C CNN
F 2 "" H 1350 4200 50  0001 C CNN
F 3 "" H 1350 4200 50  0001 C CNN
	1    1350 4200
	0    1    1    0   
$EndComp
Text GLabel 950  750  0    50   Input ~ 0
HRST
Wire Wire Line
	950  750  1050 750 
Wire Wire Line
	1050 750  1050 850 
Connection ~ 1050 850 
Wire Wire Line
	1050 850  1100 850 
$Comp
L Connector:Conn_01x02_Male J5
U 1 1 63152053
P 1650 5400
F 0 "J5" H 1500 5400 50  0000 L CNN
F 1 "WIFI_BAT" H 1300 5300 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x02_P2.00mm_Vertical" H 1650 5400 50  0001 C CNN
F 3 "~" H 1650 5400 50  0001 C CNN
	1    1650 5400
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x02_Male J3
U 1 1 631DA2A5
P 1650 4600
F 0 "J3" H 1500 4600 50  0000 L CNN
F 1 "LDR" H 1450 4500 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x02_P2.00mm_Vertical" H 1650 4600 50  0001 C CNN
F 3 "~" H 1650 4600 50  0001 C CNN
	1    1650 4600
	-1   0    0    1   
$EndComp
Text Notes 2100 5500 0    50   ~ 0
Pino de Configuração ESP32
Text GLabel 1300 5300 0    50   Input ~ 0
WIFI_LED
Wire Wire Line
	1300 5300 1450 5300
Wire Notes Line
	3300 550  6750 550 
Wire Notes Line
	6750 550  6750 3450
Wire Notes Line
	6750 3450 3300 3450
Wire Notes Line
	3300 3450 3300 550 
Text Notes 6000 3400 0    50   ~ 0
CP2102 UART USB
Wire Notes Line
	8900 6450 8900 5700
Wire Notes Line
	8900 5700 11100 5700
Wire Notes Line
	8900 6450 11100 6450
Text Notes 10100 6400 0    50   ~ 0
Bateria Interna e Cristal
Text GLabel 2450 2050 2    50   Input ~ 0
BATERRY_LEVEL
Wire Wire Line
	2300 2050 2450 2050
Text GLabel 1300 5400 0    50   Input ~ 0
BATERRY_LEVEL
Wire Wire Line
	1300 5400 1450 5400
Text GLabel 6050 4950 0    50   Input ~ 0
VIN
$Comp
L Device:R R9
U 1 1 635720C4
P 6200 5200
AR Path="/635720C4" Ref="R9"  Part="1" 
AR Path="/67F05B40/635720C4" Ref="R?"  Part="1" 
F 0 "R9" H 6270 5246 50  0000 L CNN
F 1 "2K2" H 6270 5155 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 6130 5200 50  0001 C CNN
F 3 "~" H 6200 5200 50  0001 C CNN
	1    6200 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	6200 5050 6200 4950
$Comp
L Device:R R10
U 1 1 635720CB
P 6500 5500
AR Path="/635720CB" Ref="R10"  Part="1" 
AR Path="/67F05B40/635720CB" Ref="R?"  Part="1" 
F 0 "R10" V 6293 5500 50  0000 C CNN
F 1 "4K7" V 6384 5500 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 6430 5500 50  0001 C CNN
F 3 "~" H 6500 5500 50  0001 C CNN
	1    6500 5500
	0    -1   1    0   
$EndComp
Wire Wire Line
	6350 5500 6200 5500
Wire Wire Line
	6200 5500 6200 5350
$Comp
L Device:R R11
U 1 1 635720D3
P 7100 6050
AR Path="/635720D3" Ref="R11"  Part="1" 
AR Path="/67F05B40/635720D3" Ref="R?"  Part="1" 
F 0 "R11" H 7030 6096 50  0000 R CNN
F 1 "4K7" H 7030 6005 50  0000 R CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 7030 6050 50  0001 C CNN
F 3 "~" H 7100 6050 50  0001 C CNN
	1    7100 6050
	-1   0    0    -1  
$EndComp
$Comp
L Transistor_BJT:BC548 Q4
U 1 1 635720D9
P 7000 5500
AR Path="/635720D9" Ref="Q4"  Part="1" 
AR Path="/67F05B40/635720D9" Ref="Q?"  Part="1" 
F 0 "Q4" H 7191 5546 50  0000 L CNN
F 1 "BC548" H 7191 5455 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 7200 5425 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/BC/BC547.pdf" H 7000 5500 50  0001 L CNN
	1    7000 5500
	1    0    0    -1  
$EndComp
Wire Wire Line
	6800 5500 6650 5500
Wire Wire Line
	7100 5300 7100 4950
Wire Wire Line
	7100 4950 6200 4950
Wire Wire Line
	7100 5700 7100 5800
Wire Wire Line
	7100 6200 7100 6250
$Comp
L Transistor_FET:2N7000 Q3
U 1 1 635720EA
P 7600 5050
AR Path="/635720EA" Ref="Q3"  Part="1" 
AR Path="/67F05B40/635720EA" Ref="Q?"  Part="1" 
F 0 "Q3" V 7942 5050 50  0000 C CNN
F 1 "2N7000" V 7851 5050 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 7800 4975 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N7000.pdf" H 7600 5050 50  0001 L CNN
	1    7600 5050
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7400 4950 7100 4950
Connection ~ 7100 4950
Wire Wire Line
	7100 5800 7600 5800
Wire Wire Line
	7600 5800 7600 5250
Connection ~ 7100 5800
Wire Wire Line
	7100 5800 7100 5900
$Comp
L Diode:DZ2S056X0L D1
U 1 1 635720F6
P 7950 5300
AR Path="/635720F6" Ref="D1"  Part="1" 
AR Path="/67F05B40/635720F6" Ref="D?"  Part="1" 
F 0 "D1" V 7904 5379 50  0000 L CNN
F 1 "DZ2S056X0L" H 7750 5200 50  0000 L CNN
F 2 "Diode_SMD:D_2114_3652Metric_Castellated" H 7950 5125 50  0001 C CNN
F 3 "https://industrial.panasonic.com/content/data/SC/ds/ds4/DZ2S05600L_E.pdf" H 7950 5300 50  0001 C CNN
	1    7950 5300
	0    1    1    0   
$EndComp
$Comp
L Device:C C3
U 1 1 635720FC
P 8300 5300
AR Path="/635720FC" Ref="C3"  Part="1" 
AR Path="/67F05B40/635720FC" Ref="C?"  Part="1" 
F 0 "C3" H 8415 5346 50  0000 L CNN
F 1 "47uF" H 8415 5255 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 8338 5150 50  0001 C CNN
F 3 "~" H 8300 5300 50  0001 C CNN
	1    8300 5300
	1    0    0    -1  
$EndComp
Wire Wire Line
	7800 4950 7950 4950
Wire Wire Line
	7950 5150 7950 4950
Wire Wire Line
	7950 5450 7950 5600
Wire Wire Line
	8300 5150 8300 4950
Text GLabel 8500 4950 2    50   Input ~ 0
5VA
Wire Wire Line
	8300 4950 8500 4950
Wire Wire Line
	6050 4950 6200 4950
Connection ~ 6200 4950
Wire Wire Line
	8300 4950 7950 4950
Connection ~ 8300 4950
Connection ~ 7950 4950
$Comp
L Connector:TestPoint TP2
U 1 1 6357210D
P 7950 4800
AR Path="/6357210D" Ref="TP2"  Part="1" 
AR Path="/67F05B40/6357210D" Ref="TP?"  Part="1" 
F 0 "TP2" H 8008 4918 50  0000 L CNN
F 1 "5VA" H 8008 4827 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_1.5x1.5mm" H 8150 4800 50  0001 C CNN
F 3 "~" H 8150 4800 50  0001 C CNN
	1    7950 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	7950 4800 7950 4950
Wire Notes Line
	5750 4450 8850 4450
Wire Notes Line
	8850 4450 8850 6650
Wire Notes Line
	8850 6650 5750 6650
Wire Notes Line
	5750 6650 5750 4450
Text Notes 5900 6050 0    50   ~ 0
Circuito de Entrada com \nProteção de Sobretensão\n5.6Vmax\n
$Comp
L power:GNDD #PWR015
U 1 1 63572120
P 8300 6300
AR Path="/63572120" Ref="#PWR015"  Part="1" 
AR Path="/67F05B40/63572120" Ref="#PWR?"  Part="1" 
F 0 "#PWR015" H 8300 6050 50  0001 C CNN
F 1 "GNDD" H 8304 6145 50  0000 C CNN
F 2 "" H 8300 6300 50  0001 C CNN
F 3 "" H 8300 6300 50  0001 C CNN
	1    8300 6300
	1    0    0    -1  
$EndComp
Wire Wire Line
	8300 5450 8300 6250
$Comp
L Device:R R14
U 1 1 63572127
P 7750 6250
AR Path="/63572127" Ref="R14"  Part="1" 
AR Path="/67F05B40/63572127" Ref="R?"  Part="1" 
F 0 "R14" V 7543 6250 50  0000 C CNN
F 1 "1M" V 7634 6250 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 7680 6250 50  0001 C CNN
F 3 "~" H 7750 6250 50  0001 C CNN
	1    7750 6250
	0    -1   1    0   
$EndComp
Wire Wire Line
	7900 6250 8300 6250
Connection ~ 8300 6250
Wire Wire Line
	8300 6250 8300 6300
Wire Wire Line
	7600 6250 7100 6250
Connection ~ 7100 6250
Wire Wire Line
	7100 6250 7100 6300
$Comp
L power:GNDD #PWR013
U 1 1 63572133
P 7950 5600
AR Path="/63572133" Ref="#PWR013"  Part="1" 
AR Path="/67F05B40/63572133" Ref="#PWR?"  Part="1" 
F 0 "#PWR013" H 7950 5350 50  0001 C CNN
F 1 "GNDD" H 7954 5445 50  0000 C CNN
F 2 "" H 7950 5600 50  0001 C CNN
F 3 "" H 7950 5600 50  0001 C CNN
	1    7950 5600
	1    0    0    -1  
$EndComp
$Sheet
S -3900 1300 1850 500 
U 63B72C77
F0 "External Board 2" 50
F1 "ARM Circuit.sch" 50
$EndSheet
$Comp
L power:GNDD #PWR0101
U 1 1 625E6D0E
P 1900 7350
F 0 "#PWR0101" H 1900 7100 50  0001 C CNN
F 1 "GNDD" H 1904 7195 50  0000 C CNN
F 2 "" H 1900 7350 50  0001 C CNN
F 3 "" H 1900 7350 50  0001 C CNN
	1    1900 7350
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR0102
U 1 1 625F1D36
P 2800 7050
F 0 "#PWR0102" H 2800 6800 50  0001 C CNN
F 1 "GNDD" H 2804 6895 50  0000 C CNN
F 2 "" H 2800 7050 50  0001 C CNN
F 3 "" H 2800 7050 50  0001 C CNN
	1    2800 7050
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR0103
U 1 1 625FD09D
P 7100 6300
F 0 "#PWR0103" H 7100 6050 50  0001 C CNN
F 1 "GNDD" H 7104 6145 50  0000 C CNN
F 2 "" H 7100 6300 50  0001 C CNN
F 3 "" H 7100 6300 50  0001 C CNN
	1    7100 6300
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR0104
U 1 1 6260879D
P 10500 5350
F 0 "#PWR0104" H 10500 5100 50  0001 C CNN
F 1 "GNDD" H 10504 5195 50  0000 C CNN
F 2 "" H 10500 5350 50  0001 C CNN
F 3 "" H 10500 5350 50  0001 C CNN
	1    10500 5350
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR0105
U 1 1 6261379F
P 4500 3150
F 0 "#PWR0105" H 4500 2900 50  0001 C CNN
F 1 "GNDD" H 4504 2995 50  0000 C CNN
F 2 "" H 4500 3150 50  0001 C CNN
F 3 "" H 4500 3150 50  0001 C CNN
	1    4500 3150
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR0106
U 1 1 6261E834
P 3800 1000
F 0 "#PWR0106" H 3800 750 50  0001 C CNN
F 1 "GNDD" H 3804 845 50  0000 C CNN
F 2 "" H 3800 1000 50  0001 C CNN
F 3 "" H 3800 1000 50  0001 C CNN
	1    3800 1000
	1    0    0    -1  
$EndComp
$EndSCHEMATC
