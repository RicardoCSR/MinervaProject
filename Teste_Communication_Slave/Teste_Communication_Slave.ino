// ------------------------------ CORES DISPLAY ST7789 RGB 565 E 888 -------------------------------

uint16_t blue_battery = 0x16BB;         //0x15D9E2
uint16_t green_battery = 0x9669;        //0x9AD24D
uint16_t yellow_battery = 0xEF02;       //0xF4E317
uint16_t yellowed_battery = 0xF523;     //0xF7A619
uint16_t orange_battery = 0xEB84;       //0xF67423
uint16_t red_battery = 0xEA69;          //0xEF4D4F
uint16_t charge_battery = 0x1F01;       //0x1AE510

uint16_t januaryColor = 0x21D1;         //0x27398F
uint16_t februeryColor = 0x0B35;        //0x0B69B1       
uint16_t marchColor = 0x14D1;           //0x189B8D
uint16_t aprilColor = 0x5DD1;           //0x5FBC8C
uint16_t mayColor = 0xF5AA;             //0xF8B958
uint16_t juneColor = 0xF4A6;            //0xE49837
uint16_t julyColor = 0xD264;            //0xDE5028
uint16_t augustColor = 0xD8E4;          //0xE02028
uint16_t septemberColor = 0xE0CB;       //0xE91B5B
uint16_t octoberColor = 0xB8EC;         //0xBE1D69
uint16_t novemberColor = 0x3232;        //0x344698
uint16_t decemberColor = 0x296F;        //0x31307E

uint16_t nixieColor = 0xEAEA;           //0xF16057

uint16_t wifi_level3 = 0x16BB;          //0x15D9E2
uint16_t wifi_level2 = 0x053D;          //0x04A7F2
uint16_t wifi_level1 = 0x0B35;          //0x0B69B1

uint16_t wifi_off3 = 0x9CF3;            //0x9F9F9F
uint16_t wifi_off2 = 0x7BEF;            //0x7E7E7E
uint16_t wifi_off1 = 0x52AA;            //0x555555

uint16_t springMenu = 0x9669;           //0x9AD24D
uint16_t summerMenu = 0xFF06;           //0xFFE437
uint16_t autumnMenu = 0xFDA0;           //0xFFB801
uint16_t winterMenu = 0x8E3D;           //0x90CAEF
uint16_t seasonMenu;

uint16_t drizzleColor = 0xCF5E;         //0xD0EEFD
uint16_t rainColor = 0x8E3D;            //0x90CAEF
uint16_t sunColor = 0xFF06;             //0xFFE437

uint16_t whiteScript = 0xFFFF;          //0xFFFFFF
uint16_t redScript = 0xEA69;            //0xEF4D4F
uint16_t yellowScript = 0xFDA0;         //0xFFB801
uint16_t greenScript = 0x1F01;          //0x1AE510
uint16_t blueScript = 0x0B35;           //0x0B69B1
uint16_t blackScript = 0x0000;          //0x000000

uint16_t redAjust = 0xD8E4;             //0xE02028

uint16_t background1 = 0x31A6;          //0x373737
uint16_t background2 = 0xFFFF;          //0xFFFFFF

uint16_t temperatureColor1 = 0xEBE8;    //0xF18148
uint16_t temperatureColor2 = 0xD12B;    //0xDE2662

uint16_t humidityColor1 = 0x25B9;       //0x25B7D0
uint16_t humidityColor2 = 0x929A;       //0x9A54D8

uint16_t pressureColor1 = 0x76A7;       //0x76DA41
uint16_t pressureColor2 = 0x1DF2;       //0x1EC099

uint16_t luxColor1 = 0xFF06;            //0xFFE437
uint16_t luxColor2 = 0xFDA0;            //0xFFB801

// Include the required Wire library for I2C<br>#include <Wire.h> 

//int* prt;

#define led PC13

#include <SoftwareSerial.h>

SoftwareSerial mySerial (PB6, PB7);

void setup() {
  Serial.begin(115200);
  Serial.println("oi");
  mySerial.begin(38400);
  pinMode(led, OUTPUT);
}

void loop() {
  if (mySerial.available()) {
    Serial.write(mySerial.read());
  }  
  if (mySerial.available()) {
    mySerial.write(Serial.read());
  }
  if (mySerial == 1) {
    digitalWrite(led, HIGH);
  } 
  if (mySerial == 2) {
    digitalWrite(led, LOW);
  }
}