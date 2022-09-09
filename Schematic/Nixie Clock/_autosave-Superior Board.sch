EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 3
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
L Device:LED_ABGR D?
U 1 1 637C7BDF
P 10650 1150
F 0 "D?" V 10800 1050 50  0000 R CNN
F 1 "LED_ABGR" V 10800 1550 50  0000 R CNN
F 2 "" H 10650 1100 50  0001 C CNN
F 3 "~" H 10650 1100 50  0001 C CNN
	1    10650 1150
	0    -1   -1   0   
$EndComp
Text GLabel 10500 800  0    50   Input ~ 0
5VA
Wire Wire Line
	10500 800  10650 800 
Wire Wire Line
	10650 800  10650 950 
Wire Wire Line
	10450 1450 10350 1450
Text GLabel 10350 1450 0    50   Input ~ 0
CHRG
Text GLabel 10350 1550 0    50   Input ~ 0
STDBY
Wire Wire Line
	10450 1450 10450 1350
Wire Wire Line
	10650 1550 10650 1350
Wire Wire Line
	10350 1550 10650 1550
Text GLabel 10350 1650 0    50   Input ~ 0
WIFI
Wire Wire Line
	10350 1650 10850 1650
Wire Wire Line
	10850 1650 10850 1350
$EndSCHEMATC
