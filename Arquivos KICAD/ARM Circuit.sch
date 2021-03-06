EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 5 5
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text GLabel 2400 2200 2    50   Input ~ 0
3.3VR
Wire Wire Line
	2250 2200 2250 2400
Wire Wire Line
	2100 5350 2100 5450
Wire Wire Line
	2400 2200 2250 2200
$Comp
L MCU_Module:STM32F401CCU6 U?
U 1 1 63B8F075
P 2050 4000
AR Path="/63B8F075" Ref="U?"  Part="1" 
AR Path="/61A16067/63B8F075" Ref="U?"  Part="1" 
AR Path="/63B72C77/63B8F075" Ref="U20"  Part="1" 
F 0 "U20" H 2250 2550 50  0000 C CNN
F 1 "STM32F401CCU6" H 2450 2650 50  0000 C CNN
F 2 "Package_DFN_QFN:QFN-48-1EP_7X7mm_P0.5mm_without_thermal" H 2750 4200 50  0001 C CNN
F 3 "" H 2750 4200 50  0001 C CNN
	1    2050 4000
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 63B8F07B
P 2100 5450
AR Path="/63B8F07B" Ref="#PWR?"  Part="1" 
AR Path="/61A16067/63B8F07B" Ref="#PWR?"  Part="1" 
AR Path="/63B72C77/63B8F07B" Ref="#PWR071"  Part="1" 
F 0 "#PWR071" H 2100 5200 50  0001 C CNN
F 1 "GNDD" H 2104 5295 50  0000 C CNN
F 2 "" H 2100 5450 50  0001 C CNN
F 3 "" H 2100 5450 50  0001 C CNN
	1    2100 5450
	1    0    0    -1  
$EndComp
Text GLabel 1850 2200 0    50   Input ~ 0
3.3VA
Wire Wire Line
	1850 2200 2000 2200
Wire Wire Line
	2000 2200 2000 2400
Text GLabel 2800 2700 2    50   Input ~ 0
HRST
Wire Wire Line
	2650 2700 2800 2700
$Comp
L Device:C C?
U 1 1 63B8F09E
P 1250 5200
AR Path="/63B8F09E" Ref="C?"  Part="1" 
AR Path="/61A16067/63B8F09E" Ref="C?"  Part="1" 
AR Path="/63B72C77/63B8F09E" Ref="C32"  Part="1" 
F 0 "C32" H 1135 5154 50  0000 R CNN
F 1 "20pF" H 1135 5245 50  0000 R CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 1288 5050 50  0001 C CNN
F 3 "~" H 1250 5200 50  0001 C CNN
	1    1250 5200
	-1   0    0    1   
$EndComp
Wire Wire Line
	1250 5050 1250 4900
Wire Wire Line
	1250 5350 1250 5450
$Comp
L power:GNDD #PWR?
U 1 1 63B8F0A6
P 1250 5450
AR Path="/63B8F0A6" Ref="#PWR?"  Part="1" 
AR Path="/61A16067/63B8F0A6" Ref="#PWR?"  Part="1" 
AR Path="/63B72C77/63B8F0A6" Ref="#PWR070"  Part="1" 
F 0 "#PWR070" H 1250 5200 50  0001 C CNN
F 1 "GNDD" H 1254 5295 50  0000 C CNN
F 2 "" H 1250 5450 50  0001 C CNN
F 3 "" H 1250 5450 50  0001 C CNN
	1    1250 5450
	1    0    0    -1  
$EndComp
Text GLabel 1800 5400 0    50   Input ~ 0
OSC1
Wire Wire Line
	1800 5400 1900 5400
Text GLabel 1800 5500 0    50   Input ~ 0
OSC2
Wire Wire Line
	1800 5500 2000 5500
Wire Wire Line
	2000 5500 2000 5350
Wire Wire Line
	1900 5350 1900 5400
Wire Wire Line
	1550 4900 1250 4900
Connection ~ 1250 4900
Wire Wire Line
	1250 4900 1250 4800
Wire Wire Line
	1250 4800 1550 4800
Text GLabel 1400 4300 0    50   Input ~ 0
SLEEP
Text GLabel 1400 4500 0    50   Input ~ 0
UP
Text GLabel 1400 4600 0    50   Input ~ 0
DOWN
Text GLabel 1400 4400 0    50   Input ~ 0
MODE
Wire Wire Line
	1400 4300 1550 4300
Wire Wire Line
	1400 4400 1550 4400
Wire Wire Line
	1400 4500 1550 4500
Wire Wire Line
	1400 4600 1550 4600
Text GLabel 1400 3000 0    50   Input ~ 0
TX0
Text GLabel 1400 3100 0    50   Input ~ 0
RX0
Wire Wire Line
	1400 3000 1550 3000
Wire Wire Line
	1400 3100 1550 3100
Text GLabel 2800 3850 2    50   Input ~ 0
BLK_ST7789
Text GLabel 2800 3750 2    50   Input ~ 0
RST_ST7789
Text GLabel 2800 3650 2    50   Input ~ 0
DC_ST7789
Text GLabel 2800 3550 2    50   Input ~ 0
LDR_POWER
Wire Wire Line
	2650 3550 2800 3550
Wire Wire Line
	2650 3650 2800 3650
Wire Wire Line
	2650 3750 2800 3750
Wire Wire Line
	2650 3850 2800 3850
Text Notes 3800 5500 0    50   ~ 0
Lista Terminais Utilizados STM32F401CCU6\n\nCaracteristica\n\nST7789 - Alimenta????o Ideal 3v3 \nposs??vel 5V mas com aquecimento\n\nR       Botao Hard Reset\n\nPA0     Alimentacao LDR\nPA1     Pino DC ST7789\nPA2     Pino RST ST7789\nPA3     Pino BLK ST7789\nPA4     LDR Sensor\nPA5     Pino SCL ST7789 \nPA6     Geiger Sensor\nPA7     Pino SDA ST7789\nPA8     Pino Nixie A\nPA9     Pino Nixie B\nPA10    Pino Nixie C\nPA11    Pino Nixie D\nPA12    anode Nixie C\nPA15    anode Nixie D\n\nPB0     Nivel Bateria\nPB1     anode Nixie A\nPB2     anode Nixie B\nPB3     Pino SCL BME280\nPB4     anode Nixie D\nPB5     Pino SDA BME280\nPB6     **USART TX1\nPB7     **USART RX1\nPB8     Buzzer\nPB9     \nPB10    \nPB12    Botao Hibernar\nPB13    Botao Menu\nPB14    Botao Up\nPB15    Botao Down\n\nPC13    \nPC14    \nPC15    
Text GLabel 1400 4100 0    50   Input ~ 0
ANODE_NIXIE_A
Wire Wire Line
	1550 4100 1400 4100
Text GLabel 1400 4000 0    50   Input ~ 0
ANODE_NIXIE_B
Wire Wire Line
	1550 4000 1400 4000
Text GLabel 2800 4700 2    50   Input ~ 0
ANODE_NIXIE_C
Wire Wire Line
	2650 4700 2800 4700
Text GLabel 2800 4450 2    50   Input ~ 0
ANODE_NIXIE_D
Wire Wire Line
	2650 4450 2800 4450
Text GLabel 2800 4050 2    50   Input ~ 0
SCL_ST7789
Text GLabel 2800 3950 2    50   Input ~ 0
LDR_SENSOR
Wire Wire Line
	2650 3950 2800 3950
Wire Wire Line
	2650 4050 2800 4050
Text GLabel 2800 4250 2    50   Input ~ 0
SDA_ST7789
Wire Wire Line
	2650 4250 2800 4250
Text GLabel 2800 4350 2    50   Input ~ 0
BATERRY_LEVEL
Wire Wire Line
	2650 4350 2800 4350
Text GLabel 2800 4150 2    50   Input ~ 0
GEIGER_SENSOR
Wire Wire Line
	2650 4150 2800 4150
Text GLabel 2800 2900 2    50   Input ~ 0
3V3
Wire Wire Line
	2650 2900 2800 2900
Text GLabel 2800 3000 2    50   Input ~ 0
SWCLK
Wire Wire Line
	2650 3000 2800 3000
Text GLabel 2800 3100 2    50   Input ~ 0
SWDIO
Wire Wire Line
	2650 3100 2800 3100
Text GLabel 2800 3200 2    50   Input ~ 0
SWGND
Wire Wire Line
	2650 3200 2800 3200
Text GLabel 1400 2700 0    50   Input ~ 0
SCL_BME280
Text GLabel 1400 2900 0    50   Input ~ 0
SDA_BME280
Wire Wire Line
	1400 2700 1550 2700
Wire Wire Line
	1400 2900 1550 2900
Text GLabel 1400 3900 0    50   Input ~ 0
LEVEL_D
Text GLabel 1400 3800 0    50   Input ~ 0
LEVEL_C
Text GLabel 1400 3700 0    50   Input ~ 0
LEVEL_B
Text GLabel 1400 3600 0    50   Input ~ 0
LEVEL_A
Wire Wire Line
	1400 3600 1550 3600
Wire Wire Line
	1400 3700 1550 3700
Wire Wire Line
	1400 3800 1550 3800
Wire Wire Line
	1400 3900 1550 3900
Text GLabel 1400 3200 0    50   Input ~ 0
BUZZER
Wire Wire Line
	1550 3200 1400 3200
Text GLabel 2050 7050 0    50   Input ~ 0
3V3
Wire Wire Line
	2200 7050 2050 7050
Text GLabel 2050 6750 0    50   Input ~ 0
SWCLK
Wire Wire Line
	2200 6750 2050 6750
Text GLabel 2050 6850 0    50   Input ~ 0
SWDIO
Wire Wire Line
	2200 6850 2050 6850
$Comp
L Connector:Conn_01x04_Male J?
U 1 1 63B8F108
P 2400 6850
AR Path="/63B8F108" Ref="J?"  Part="1" 
AR Path="/61A16067/63B8F108" Ref="J?"  Part="1" 
AR Path="/63B72C77/63B8F108" Ref="J21"  Part="1" 
F 0 "J21" H 2508 7131 50  0000 C CNN
F 1 "SERIAL" H 2508 7040 50  0000 C CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_2x02_P2.00mm_Vertical" H 2400 6850 50  0001 C CNN
F 3 "~" H 2400 6850 50  0001 C CNN
	1    2400 6850
	-1   0    0    -1  
$EndComp
Wire Notes Line
	1650 6500 3700 6500
Text Notes 2550 6900 0    50   ~ 0
Conector de Grava????o STM32
Text GLabel 2050 6950 0    50   Input ~ 0
SWGND
Wire Wire Line
	2200 6950 2050 6950
Text GLabel 2800 4900 2    50   Input ~ 0
EN
Wire Wire Line
	2650 4900 2800 4900
Wire Notes Line
	3700 7150 1650 7150
Wire Notes Line
	3700 6500 3700 7150
Wire Notes Line
	1650 6500 1650 7150
Text GLabel 8950 2700 2    50   Input ~ 0
3.3VR
$Comp
L power:GNDD #PWR?
U 1 1 63BE2874
P 8950 2600
AR Path="/63BE2874" Ref="#PWR?"  Part="1" 
AR Path="/61A16067/63BE2874" Ref="#PWR?"  Part="1" 
AR Path="/63AEBE91/63BE2874" Ref="#PWR?"  Part="1" 
AR Path="/63B72C77/63BE2874" Ref="#PWR068"  Part="1" 
F 0 "#PWR068" H 8950 2350 50  0001 C CNN
F 1 "GNDD" V 8950 2400 50  0000 C CNN
F 2 "" H 8950 2600 50  0001 C CNN
F 3 "" H 8950 2600 50  0001 C CNN
	1    8950 2600
	0    -1   1    0   
$EndComp
Wire Notes Line
	8050 2200 8050 3750
Wire Notes Line
	7700 3800 9850 3800
Wire Notes Line
	8050 2200 9850 2200
Wire Notes Line
	7700 5200 9850 5200
Wire Notes Line
	7700 3800 7700 5200
Text Notes 9200 3700 0    50   ~ 0
Display ST7789
Text Notes 8300 5150 0    50   ~ 0
Alimenta????o e Envio de dados externos
$Comp
L Connector:Conn_01x07_Male J?
U 1 1 63BE2881
P 8600 2900
AR Path="/61A16067/63BE2881" Ref="J?"  Part="1" 
AR Path="/63AEBE91/63BE2881" Ref="J?"  Part="1" 
AR Path="/63B72C77/63BE2881" Ref="J18"  Part="1" 
F 0 "J18" H 8400 3000 50  0000 C CNN
F 1 "ST7789" H 8400 2900 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x07_P2.54mm_Vertical" H 8600 2900 50  0001 C CNN
F 3 "~" H 8600 2900 50  0001 C CNN
	1    8600 2900
	1    0    0    -1  
$EndComp
Text GLabel 8950 3200 2    50   Input ~ 0
BLK_ST7789
Text GLabel 8950 3000 2    50   Input ~ 0
RST_ST7789
Text GLabel 8950 3100 2    50   Input ~ 0
DC_ST7789
Wire Wire Line
	8800 3100 8950 3100
Wire Wire Line
	8800 3000 8950 3000
Wire Wire Line
	8800 3200 8950 3200
Text GLabel 8950 2800 2    50   Input ~ 0
SCL_ST7789
Wire Wire Line
	8800 2800 8950 2800
Text GLabel 8950 2900 2    50   Input ~ 0
SDA_ST7789
Wire Wire Line
	8800 2900 8950 2900
Wire Wire Line
	8800 2700 8950 2700
Wire Wire Line
	8950 2600 8800 2600
Text GLabel 8450 4400 0    50   Input ~ 0
5VG
Wire Wire Line
	8450 4400 8600 4400
Text GLabel 9250 4400 2    50   Input ~ 0
3.3VR
Wire Wire Line
	9250 4400 9100 4400
Text GLabel 8450 4500 0    50   Input ~ 0
3.3VA
Wire Wire Line
	8450 4500 8600 4500
Wire Wire Line
	8600 4700 8450 4700
Text GLabel 9250 4600 2    50   Input ~ 0
BAT2+
Wire Wire Line
	9250 4600 9100 4600
Text GLabel 9250 4500 2    50   Input ~ 0
TX0
Text GLabel 9250 4700 2    50   Input ~ 0
RX0
Wire Wire Line
	9250 4500 9100 4500
Wire Wire Line
	9250 4700 9100 4700
$Comp
L Connector_Generic:Conn_02x04_Odd_Even J?
U 1 1 63BE28A6
P 8800 4500
AR Path="/63BE28A6" Ref="J?"  Part="1" 
AR Path="/61A16067/63BE28A6" Ref="J?"  Part="1" 
AR Path="/63AEBE91/63BE28A6" Ref="J?"  Part="1" 
AR Path="/63B72C77/63BE28A6" Ref="J20"  Part="1" 
F 0 "J20" H 8850 4817 50  0000 C CNN
F 1 "Modulo Externo" H 8850 4726 50  0000 C CNN
F 2 "Connector_Molex:Molex_Nano-Fit_105310-xx08_2x04_P2.50mm_Vertical" H 8800 4500 50  0001 C CNN
F 3 "~" H 8800 4500 50  0001 C CNN
	1    8800 4500
	1    0    0    -1  
$EndComp
Wire Notes Line
	8050 3750 9850 3750
Wire Notes Line
	9850 3750 9850 2200
Wire Notes Line
	9850 3800 9850 5200
$Comp
L Device:R R?
U 1 1 63BF2BCE
P 6000 5050
AR Path="/63BF2BCE" Ref="R?"  Part="1" 
AR Path="/63B72C77/63BF2BCE" Ref="R73"  Part="1" 
F 0 "R73" V 6207 5050 50  0000 C CNN
F 1 "10K" V 6116 5050 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 5930 5050 50  0001 C CNN
F 3 "~" H 6000 5050 50  0001 C CNN
	1    6000 5050
	0    1    -1   0   
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 63BF2BD4
P 7350 5450
AR Path="/63BF2BD4" Ref="#PWR?"  Part="1" 
AR Path="/63B72C77/63BF2BD4" Ref="#PWR072"  Part="1" 
F 0 "#PWR072" H 7350 5200 50  0001 C CNN
F 1 "GNDD" H 7354 5295 50  0000 C CNN
F 2 "" H 7350 5450 50  0001 C CNN
F 3 "" H 7350 5450 50  0001 C CNN
	1    7350 5450
	1    0    0    -1  
$EndComp
Wire Wire Line
	7350 5350 7350 5450
Text GLabel 5750 5050 0    50   Input ~ 0
HRST
Wire Wire Line
	5750 5050 5850 5050
$Comp
L Device:C C?
U 1 1 63BF2BDD
P 6950 5350
AR Path="/63BF2BDD" Ref="C?"  Part="1" 
AR Path="/63B72C77/63BF2BDD" Ref="C33"  Part="1" 
F 0 "C33" V 6800 5350 50  0000 C CNN
F 1 "20pF" V 6700 5350 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 6988 5200 50  0001 C CNN
F 3 "~" H 6950 5350 50  0001 C CNN
	1    6950 5350
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6150 5050 6350 5050
Wire Wire Line
	7100 5350 7350 5350
Connection ~ 7350 5350
Wire Wire Line
	6500 5350 6500 5250
Wire Wire Line
	6500 5350 6800 5350
Wire Wire Line
	6500 4850 6500 4750
Wire Wire Line
	7350 4750 7350 5350
Wire Notes Line
	7550 4400 7550 6150
Wire Notes Line
	7550 6150 5350 6150
Wire Notes Line
	5350 6150 5350 4400
Text Notes 5450 6050 0    50   ~ 0
1 - 2 Habilita botao Reset da Placa\n2 - 3 Mantem Pino For??ado em Zero
Wire Notes Line
	7550 4400 5350 4400
$Comp
L Connector:Conn_01x02_Male J?
U 1 1 63BF2BEF
P 7000 4500
AR Path="/63BF2BEF" Ref="J?"  Part="1" 
AR Path="/63B72C77/63BF2BEF" Ref="J19"  Part="1" 
F 0 "J19" V 7062 4544 50  0000 L CNN
F 1 "RST" V 7153 4544 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x02_P2.00mm_Vertical" H 7000 4500 50  0001 C CNN
F 3 "~" H 7000 4500 50  0001 C CNN
	1    7000 4500
	0    1    1    0   
$EndComp
Wire Wire Line
	6900 4750 6900 4700
Wire Wire Line
	6500 4750 6900 4750
Wire Wire Line
	7000 4700 7000 4750
Wire Wire Line
	7000 4750 7350 4750
$Comp
L Jumper:SolderJumper_3_Open JP?
U 1 1 63BF2BF9
P 6500 5050
AR Path="/63BF2BF9" Ref="JP?"  Part="1" 
AR Path="/63B72C77/63BF2BF9" Ref="JP4"  Part="1" 
F 0 "JP4" V 6454 5118 50  0000 L CNN
F 1 "RST" V 6545 5118 50  0000 L CNN
F 2 "Jumper:SolderJumper-3_P1.3mm_Open_RoundedPad1.0x1.5mm_NumberLabels" H 6500 5050 50  0001 C CNN
F 3 "~" H 6500 5050 50  0001 C CNN
	1    6500 5050
	0    1    1    0   
$EndComp
Text GLabel 8450 4600 0    50   Input ~ 0
5VA
Wire Wire Line
	8450 4600 8600 4600
$Comp
L power:GNDD #PWR?
U 1 1 62884722
P 8450 4700
AR Path="/62884722" Ref="#PWR?"  Part="1" 
AR Path="/63B72C77/62884722" Ref="#PWR0144"  Part="1" 
F 0 "#PWR0144" H 8450 4450 50  0001 C CNN
F 1 "GNDD" V 8450 4500 50  0000 C CNN
F 2 "" H 8450 4700 50  0001 C CNN
F 3 "" H 8450 4700 50  0001 C CNN
	1    8450 4700
	0    1    1    0   
$EndComp
$EndSCHEMATC
