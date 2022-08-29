/*
Lista Terminais Utilizados STM32F401CCU6

BRANCO -    COMANDOS (BOTOES)
VERDE -     GNDS   
AMARELO -   3V3
VERMELHO -  5V
PRETO -     PWM
LARANJA -   SPI
ROXO -      GEIGER     
AZUL -      NIXIE


Caracteristica

SN74141 : True Table
D C B A #
L,L,L,L 0
L,L,L,H 1
L,L,H,L 2
L,L,H,H 3
L,H,L,L 4
L,H,L,H 5
L,H,H,L 6
L,H,H,H 7
H,L,L,L 8
H,L,L,H 9
H,L,H,L N
H,L,H,H N
H,H,L,L N
H,H,L,H N
H,H,H,L N
H,H,H,H N

*/

// DADOS RELOGIO
int time;                       // Armazena Horario 4 Digitos Processado
int hours;                      // Armazena Horario Horas
int mins;                       // Armazena Horario Minutos
byte compareTimeHour;           // Armazena Horario do Display
byte compareTimeMins;           // Armazena Horario do Display
byte compareTimeSecs;           // Armazena Horario do Display

byte compareSecs = 0;           // Armazena Horario Menu de Ajuste Relogio
byte compareMins = 0;           // Armazena Horario Menu de Ajuste Relogio
byte compareHour = 0;           // Armazena Horario Menu de Ajuste Relogio

byte compareDay = 0;            // Armazena Data Menu de Ajuste Calendario
byte compareMonth = 0;          // Armazena Data Menu de Ajuste Calendario
byte compareYear = 0;           // Armazena Data Menu de Ajuste Calendario

byte hourBias = 0;              // Byte para Long horas x fuso (12 ~ 24)
byte minuteBias = 0;            // Byte para Long minutos x 60 
byte secsBias = 0;              // Byte para Long segundos x 60
unsigned long secs;             // Armazena Horario Segundos sem conversão

// NIVEL DE BATERIA E WIFI   
byte compareUpdateBattery;      // Armazena atualização de updateBattery
byte compareUpdateWiFi;      // Armazena atualização de updateBattery


// DADOS TIMERS
unsigned long period = 0;

// VALORES AJUSTAVEIS PELO USUÁRIO
byte logoTime = 3;

byte backgroundSetup = 0;
// backgroundSetup = 0 Programa Fundo Preto e Colorido.
// backgroundSetup = 1 Programa Fundo Branco e Colorido.
// backgroundSetup = 2 Programa Fundo Preto.
// backgroundSetup = 3 Programa Fundo Branco.

byte batteryStyleMode = 0;
// batteryStyleMode = 0 Estilo 1 de Bateria.
// batteryStyleMode = 1 Estilo 2 de Bateria.
// batteryStyleMode = 2 Estilo 3 de Bateria.
// batteryStyleMode = 3 Estilo 4 de Bateria.

byte lockStyle = 0;
// lockStyle = 0 Estilo 1 de Trava.
// lockStyle = 1 Estilo 2 de Trava.
// lockStyle = 2 Estilo 3 de Trava.

byte day = 1;                   // Armazena dados de dia calendario
byte month = 1;                 // Armazena dados de mes calendario
int year = 2022;                // Armazena dados de ano calendario

byte fuso = 1;                  
//fuso = 0 12 Horas  
//fuso = 1 24 Horas

// BANCO DE DADOS DE COMPARADORES
byte logoStarted = 0;
// logoStarted = 0 Tela de Abertura ativado.
// logoStarted = 1 Tela de Abertura desativado.

byte powerCharger = 0;          
// powerCharger = 0 Carregador Desconectado
// powerCharger = 1 Carregador Conectado

byte screenLoad = 0;
// screenLoad = 0 Tela inicia o carregamento.
// screenLoad = 1 Tela para o carregamento.

byte updateBattery = 0;
// updateBattery = 0 Apresentação Bateria Level 1
// updateBattery = 1 Apresentação Bateria Level 2
// updateBattery = 2 Apresentação Bateria Level 3
// updateBattery = 3 Apresentação Bateria Level 4
// updateBattery = 4 Apresentação Bateria Level 5
// updateBattery = 5 Apresentação Bateria Level 6
// updateBattery = 6 Apresentação Bateria Level 7

byte wifiRead = 0;
// wifiRead = 0 WiFi em alta potência
// wifiRead = 1 WiFi em media potência
// wifiRead = 2 WiFi em baixa potência
// wifiRead = 3 WiFi sem Sinal

byte telaMenu = 0;
// telaMenu = 0 Menu Principal
// telaMenu = 1 Tela  
// telaMenu = 2 Tela  
// telaMenu = 3 Tela  
// telaMenu = 4 Tela  
// telaMenu = 5 Tela  
// telaMenu = 6 Tela  
// telaMenu = 7 Tela  
// telaMenu = 8 Tela  
// telaMenu = 9 Tela  
// telaMenu = 10 Tela 
// telaMenu = 11 Tela 
// telaMenu = 12 Tela 
// telaMenu = 13 Tela 
// telaMenu = 14 Tela 
// telaMenu = 15 Tela 

// ------------------------------ CONFIGURACAO DOS PINOS DE SENSORES E DISPLAY --------

int pinBatteryRead = PC13;
int pinBatteryCharger = PB7;         // Pino de Leitura da Bateria

// ------------------------------ CORES DISPLAY RGB 555 -------------------------------

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
uint16_t dosimeterColor = 0xF234;       //0xFE48AA

uint16_t wifi_level3 = 0x16BB;          //0x15D9E2
uint16_t wifi_level2 = 0x053D;          //0x04A7F2
uint16_t wifi_level1 = 0x0B35;          //0x0B69B1

uint16_t wifi_off3 = 0x9CF3;            //0x9F9F9F
uint16_t wifi_off2 = 0x7BEF;            //0x7E7E7E
uint16_t wifi_off1 = 0x52AA;            //0x555555

uint16_t geigerLevel1 = 0x362F;         //0x39C87E
uint16_t geigerLevel2 = 0xFF06;         //0xFFE437
uint16_t geigerLevel3 = 0xD8E4;         //0xE02028
uint16_t geigerLevel = 0xEB84;          //0xF67423

uint16_t geigerColor;
uint16_t geigerColor1 = 0xFDA0;         //0xFFB801
uint16_t geigerColor2 = 0xDCA6;         //0xE49837

uint16_t luxColor1 = 0xFF06;            //0xFFE437
uint16_t luxColor2 = 0xFDA0;            //0xFFB801

uint16_t temperatureColor;
uint16_t temperatureColor1 = 0xEBE8;    //0xF18148
uint16_t temperatureColor2 = 0xD12B;    //0xDE2662

uint16_t humidityColor;
uint16_t humidityColor1 = 0x25B9;       //0x25B7D0
uint16_t humidityColor2 = 0x929A;       //0x9A54D8

uint16_t pressureColor;
uint16_t pressureColor1 = 0x76A7;       //0x76DA41
uint16_t pressureColor2 = 0x1DF2;       //0x1EC099

uint16_t springMenu = 0x9669;           //0x9AD24D
uint16_t summerMenu = 0xFF06;           //0xFFE437
uint16_t autumnMenu = 0xFDA0;           //0xFFB801
uint16_t winterMenu = 0x8E3D;           //0x90CAEF
uint16_t seasonMenu;

uint16_t drizzleColor = 0xCF5E;         //0xD0EEFD
uint16_t rainColor = 0x8E3D;            //0x90CAEF
uint16_t sunColor = 0xFF06;             //0xFFE437


uint16_t blackScript = 0x18c3;          //0x000000
uint16_t greyScript = 0x94B2;           //0x969696
uint16_t greywhite = 0xDF1B;            //0xE6E6E6
uint16_t whiteScript = 0xFFFF;          //0xFFFFFF
uint16_t redScript = 0xEA69;            //0xEF4D4F
uint16_t yellowScript = 0xFDA0;         //0xFFB801
uint16_t greenScript = 0x1F01;          //0x1AE510
uint16_t blueScript = 0x0B35;           //0x0B69B1

uint16_t profile = 0xEC71;              //0xEF9090


uint16_t icon12 = 0xB8EC;               //0xBE1D69


#include "STM32LowPower.h"
#include <STM32RTC.h>

#include <TFT_eSPI.h> 
#include <SPI.h>
#include "MapFloat.h"
#include <Wire.h>
#include "Adafruit_GFX.h"
#include <EasyColor.h>
#include <forcedClimate.h>

#include "Imagens.h"

#include "Lato_Bold_48.h"
#include "Lato_Regular_24.h"
#include "Lato_Regular_14.h"
#include "Lato_Regular_12.h"
#include "Lato_Regular_10.h"

#define latoBold48 &Lato_Bold_48
#define latoRegular24 &Lato_Regular_24
#define latoRegular14 &Lato_Regular_14
#define latoRegular12 &Lato_Regular_12
#define latoRegular10 &Lato_Regular_10

#define GFXFF 1
byte i = 0;
  // TL_DATUM = Top left (default)
  // TC_DATUM = Top centre
  // TR_DATUM = Top right
  // ML_DATUM = Middle left
  // MC_DATUM = Middle centre
  // MR_DATUM = Middle right
  // BL_DATUM = Bottom left
  // BC_DATUM = Bottom centre
  // BR_DATUM = Bottom right
  // L_BASELINE = Left character baseline (Line the 'A' character would sit on)
  // C_BASELINE = Centre character baseline
  // R_BASELINE = Right character baseline

// ------------------------------- INSTANCIAS DAS BIBLIOTECAS --------------------------

    STM32RTC& rtc = STM32RTC::getInstance();
    TFT_eSPI tft = TFT_eSPI();      // Could invoke custom library declaring width and height
    EasyColor rgb2rgb;                 //Conversão de e para RGB888/RGB565
    ForcedClimate climateSensor = ForcedClimate(Wire, 0x77);

void setup() {
  Serial.begin(115200);
  Serial.println("Sistema Inicializado");
  tft.init();
  Wire.begin(0x77);
  climateSensor.begin();
  tft.setRotation(3);
}

void loop(void) {
  // ---------------------- CONFIGURAÇÃO E SETUPS -----------

    unsigned long actualTime = millis();

  // ------------------------------- HORARIO VIA MILLIS() OPERACIONAL -----------------------
    secs = millis() / 20 + (long)hourBias * 3600 + (long)minuteBias * 60;
    secsBias = secs % 60;
    mins = (secs / 60) % 60;
    hours = (secs / 3600) % fuso;
    time = hours * 100 + mins;

  // ---------------------- COMANDO DE LOGO ----------

    if (logoStarted == 0) {
      logoStarted = 1;
      startLogo();
      if (actualTime - period >= logoTime * 1000) {
        period = actualTime;
        if ((backgroundSetup == 1) || (backgroundSetup == 3)) {
          tft.fillRect(0, 0, 480, 320, whiteScript);
        } else {
          tft.fillRect(0, 0, 480, 320, blackScript);
        }
      }
    } 

  // ---------------------- PERFIL SETUP -----------
    switch (backgroundSetup) {
      case 1:
        // do something
      break;
      case 2:
        // do something
      break;
      case 3:
        // do something
      break; 
      default:
        defaultSetup();
    } 

  // ---------------------- ATUALIZA RELOGIO -----------
    if (mins != compareMins) {
      Serial.print(hours);
      Serial.print(":");
      Serial.println(mins);
      superiorMenu();
    }

  // ---------------------- ACESSO A PAGINA --------------
    if (actualTime - period >= 10 * 1000) {
      period = actualTime;
      telaMenu = 1;
    }  

    if (i == 0) {
    switch (telaMenu) {
      case 1:
        telaMenu1();
      break;
      case 2:
        telaMenu2();
      break;
      case 3:
        telaMenu3();
      break;
      case 4:
        telaMenu4();
      break;
      case 5:
        telaMenu5();
      break;
      case 6:
        telaMenu6();
      break;
      case 7:
        telaMenu7();
      break;
      case 8:
        telaMenu8();
      break;
      case 9:
        telaMenu9();
      break;
      case 10:
        telaMenu10();
      break;
      case 11:
        telaMenu11();
      break;
      case 12:
        telaMenu12();
      break;
      case 13:
        telaMenu13();
      break;
      case 14:
        telaMenu14();
      break;
      case 15:
        telaMenu15();
      break;
      default:
        defaultSetup();
    }
    }






}


// ------------------------ TELA DE ABERTURA -------------
void startLogo() {
  tft.fillScreen(blackScript);
  tft.setSwapBytes(true);
  //tft.pushImage(0, 0, 480, 320, abertura);
}

void defaultSetup() {
  if (screenLoad == 0) {
    tft.fillScreen(blackScript);
    tft.setSwapBytes(true);
    tft.pushImage(43, 67, 71, 71, icon1);
    tft.pushImage(124, 67, 71, 71, icon2);
    tft.pushImage(205, 67, 71, 71, icon3);
    tft.pushImage(286, 67, 71, 71, icon4);
    tft.pushImage(367, 67, 71, 71, icon5);

    tft.pushImage(43, 147, 71, 71, icon6);
    tft.pushImage(124, 147, 71, 71, icon7);
    tft.pushImage(205, 147, 71, 71, icon8);
    tft.pushImage(286, 147, 71, 71, icon9);
    tft.pushImage(367, 147, 71, 71, icon10);

    tft.pushImage(43, 227, 71, 71, icon11);
    tft.fillRoundRect(124, 227, 71, 71, 10, icon12);
    tft.pushImage(205, 227, 71, 71, icon13);
    tft.pushImage(286, 227, 71, 71, icon14);
    tft.pushImage(367, 227, 71, 71, icon15);

    superiorMenu();
    wifiLevel();
    batteryLevel();
    lockLevel();
    screenLoad = 1;
  }
}

void wifiLevel() {
  switch (wifiRead) {
    case 1:
      tft.pushImage(330, 37, 32, 32, wifi1);
    break;
    case 2:
      tft.pushImage(330, 37, 32, 32, wifi2);
    break;
    case 3:
      tft.pushImage(330, 37, 32, 32, wifi3);
    break;
    default:
      tft.setSwapBytes(true);
      tft.pushImage(320, 15, 32, 32, wifi4);
      tft.pushImage(425, 5, 45, 45, climate16);
      tft.pushImage (5, 7, 48, 48, profile1);
  }
}

void batteryLevel() {
  int batteryRead = 1000;

  switch (batteryStyleMode) {
      case 1:
        batteryStyle2();
        break;
      case 2:
        batteryStyle3();
        break;
      case 3:
        batteryStyle4();
      break;
      default:
        batteryStyle1();
  }
}

void lockLevel() {
  switch (lockStyle) {
      case 1:
        // do something
        break;
      case 2:
        // do something
        break;
      default:
        lockStyle1();
  }
}

void superiorMenu() {
  String stringHour = String(hours);
  String stringMin = String(mins);
  String stringDay = String(day);
  String stringMonth = String(month);
  String stringYear = String(year);

  String stringHourMin = String(hours - 1);
  String stringMinMin = String(mins - 1);
  String stringDayMin = String(day - 1);
  String stringMonthMin = String(month - 1);
  String stringYearMin = String(year - 1);

  tft.setTextDatum(ML_DATUM);
  tft.setTextColor(blackScript);
  tft.setFreeFont(latoRegular24);

  compareMins = mins;

  if (day < 10) {
    tft.drawString("0", 77, 30, GFXFF);
    tft.drawString(stringDayMin, 92, 30, GFXFF);
  } else {
    tft.fillRect(77, 22, 28, 20, blackScript);
  }

  if (month < 10) {
    tft.drawString("0", 110, 30, GFXFF);
    tft.drawString(stringMonthMin, 125, 30, GFXFF);
  } else {
    tft.fillRect(110, 22, 28, 20, blackScript);
  }

  tft.drawString(stringYearMin, 143, 30, GFXFF);

  if (hours < 10) {
    tft.drawString("0", 219, 30, GFXFF);
    tft.drawString(stringHourMin, 234, 30, GFXFF);
  } else {
    tft.fillRect(219, 22, 28, 20, blackScript);
  }

  if (mins < 10) {
    tft.drawString("0", 252, 30, GFXFF);
    tft.drawString(stringMinMin, 267, 30, GFXFF);
  } else {
    tft.fillRect(252, 22, 28, 20, blackScript);
  }







  tft.setTextColor(whiteScript);  

  if (day < 10) {
    tft.drawString("0", 77, 30, GFXFF);
    tft.drawString(stringDay, 92, 30, GFXFF);
  } else {
    tft.drawString(stringDay, 77, 30, GFXFF);
  }

  if (month < 10) {
    tft.drawString("0", 110, 30, GFXFF);
    tft.drawString(stringMonth, 125, 30, GFXFF);
  } else {
    tft.drawString(stringMonth, 110, 30, GFXFF);
  }

  tft.drawString(stringYear, 143, 30, GFXFF);


  if (hours < 10) {
    tft.drawString("0", 219, 30, GFXFF);
    tft.drawString(stringHour, 234, 30, GFXFF);
  } else {
    tft.drawString(stringHour, 219, 30, GFXFF);
  }

  if (mins < 10) {
    tft.drawString("0", 252, 30, GFXFF);
    tft.drawString(":", 246, 30, GFXFF);
    tft.drawString(stringMin, 267, 30, GFXFF);
  } else {
    tft.drawString(":", 246, 30, GFXFF);
    tft.drawString(stringMin, 252, 30, GFXFF);


  }
}

void batteryStyle1() {
  tft.drawRoundRect(361, 21, 50, 20, 4, whiteScript);
  tft.drawRoundRect(362, 22, 48, 18, 4, whiteScript);  
  tft.fillRoundRect(363, 23, 46, 16, 4, blue_battery);
}
void batteryStyle2() {
  tft.drawRoundRect(361, 21, 50, 20, 4, whiteScript);
  tft.fillRoundRect(362, 22, 48, 18, 4, blue_battery);
}
void batteryStyle3() {
  tft.drawRoundRect(361, 21, 50, 20, 4, whiteScript);
  tft.fillRoundRect(362, 22, 48, 18, 4, blue_battery);
}
void batteryStyle4() {
  tft.drawRoundRect(361, 21, 50, 20, 4, blue_battery);
  tft.fillRoundRect(362, 22, 48, 18, 4, blue_battery);
}

void lockStyle1() {
  tft.drawRoundRect(297, 20, 13, 13, 4, greenScript);
  tft.drawRoundRect(298, 21, 11, 11, 4, greenScript);
  tft.fillRect(302, 25, 10, 4, blackScript);
  tft.fillRoundRect(294, 29, 19, 13, 3, greenScript);
}

void home() {
  tft.fillTriangle(440, 297, 455, 282, 470, 297, whiteScript);
  tft.fillRect(446, 297, 19, 6, whiteScript);
  tft.fillRect(446, 303, 7, 6, whiteScript);
  tft.fillRect(458, 303, 7, 6, whiteScript);
}

void telaMenu1() {
  tft.fillScreen(blackScript);
  i = 1;

  tft.setTextDatum(ML_DATUM);
  tft.setTextColor(whiteScript);
  tft.setFreeFont(latoRegular14);
  tft.drawString("10", 19, 90, GFXFF);
  tft.drawString("8", 23, 125, GFXFF);
  tft.drawString("6", 23, 160, GFXFF);
  tft.drawString("4", 23, 195, GFXFF);
  tft.drawString("2", 23, 230, GFXFF);
  tft.drawString("0", 23, 265, GFXFF);

  tft.fillRect(40, 85, 23, 29, geigerLevel3);
  tft.fillRect(40, 114, 23, 86, geigerLevel2);
  tft.fillRect(40, 200, 23, 73, geigerLevel1);

  tft.fillTriangle(68, 272, 85, 262, 85, 282, geigerLevel);

  home();
  superiorMenu();
  wifiLevel();
  batteryLevel();
  lockLevel();
}
void telaMenu2() {
  tft.fillScreen(blackScript);
}
void telaMenu3() {
  tft.fillScreen(blackScript);
}
void telaMenu4() {
  tft.fillScreen(blackScript);
}
void telaMenu5() {
  tft.fillScreen(blackScript);
}
void telaMenu6() {
  tft.fillScreen(blackScript);
}
void telaMenu7() {
  tft.fillScreen(blackScript);
}
void telaMenu8() {
  tft.fillScreen(blackScript);
}
void telaMenu9() {
  tft.fillScreen(blackScript);
}
void telaMenu10() {
  tft.fillScreen(blackScript);
}
void telaMenu11() {
  tft.fillScreen(blackScript);
}
void telaMenu12() {
  tft.fillScreen(blackScript);
}
void telaMenu13() {
  tft.fillScreen(blackScript);
}
void telaMenu14() {
  tft.fillScreen(blackScript);
}
void telaMenu15() {
  tft.fillScreen(blackScript);
}