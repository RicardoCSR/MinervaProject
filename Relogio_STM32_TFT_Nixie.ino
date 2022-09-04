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
int secs;                       // Armazena Horario Segundos sem conversão

// NIVEL DE BATERIA E WIFI   
byte compareUpdateBattery;      // Armazena atualização de updateBattery
byte compareUpdateWiFi;         // Armazena atualização de updateBattery


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

int day;                      // Armazena dados de dia calendario
int month;                    // Armazena dados de mes calendario
int year;                     // Armazena dados de ano calendario

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

uint16_t nixieColor = 0xD264;           //0xDE4E28
uint16_t dosimeterColor = 0xF234;       //0xFE48AA
uint16_t highValueColor = 0xD94B;       //0xE1295F

uint16_t middleTimeGraph = 0x7BEF;      //0x7E7E7E

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
uint16_t temperatureColor1 = 0xDCA6;    //0xE49837
uint16_t temperatureColor2 = 0xD12B;    //0xDE2662

uint16_t humidityColor;
uint16_t humidityColor1 = 0x25B9;       //0x25B7D0
uint16_t humidityColor2 = 0x929A;       //0x9A54D8

uint16_t menuSelection = 0x16BB;        //0x15D9E2
uint16_t profileColor = 0x5DD1;         //0x5FBC8C

uint16_t pressureColor;
uint16_t pressureColor1 = 0x76A7;       //0x77DA3F
uint16_t pressureColor2 = 0x1DF2;       //0x1BBF9A

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

uint16_t icon_1 = 0xEB84;               //0xF67423
uint16_t icon_2 = 0xED23;               //0xF1A71F
uint16_t icon_3 = 0xE2E9;               //0xEB6052
uint16_t icon_4 = 0x5DD1;               //0x5FBC8D
uint16_t icon_5 = 0xE0CB;               //0xE91B5B
uint16_t icon_6 = 0xE2E9;               //0xEB6052
uint16_t icon_7 = 0x566B;               //0x58D160
uint16_t icon_8 = 0x3559;               //0x33ACD1
uint16_t icon_9 = 0xDCA6;               //0xE49837
uint16_t icon_10 = 0x16BB;              //0x15D9E2
uint16_t icon_11 = 0x14D1;              //0x189B8D
uint16_t icon_12 = 0xB8EC;              //0xBE1D69
uint16_t icon_13 = 0x31C7;              //0x343A40
uint16_t icon_14 = 0x929A;              //0x9A54D8
uint16_t icon_15 = 0x634C;              //0x6A6A6A

uint16_t icon_black = 0x8450;           //0x8A8A8A
uint16_t icon_white = 0xD6BA;           //0xD9D9D9

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

byte i = 0;

#define GFXFF 1
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

  if (fuso == 1) {
    fuso = 23;
  } else {
    fuso = 11;
  }

  
  Serial.print("Insira Hora: ");
  while (hours == 0) {
    if (Serial.available() > 0) {
      hours = Serial.parseInt();
      Serial.println(hours);
    }
  }
  Serial.print("Insira Minuto: ");
  while (mins == 0) {
    if (Serial.available() > 0) {
      mins = Serial.parseInt();
      Serial.println(mins);
    }
  }
  Serial.print("Insira Dia: ");
  while (day == 0) {
    if (Serial.available() > 0) {
      day = Serial.parseInt();
      Serial.println(day);
    }
  }

  Serial.print("Insira Mês: ");
  while (month == 0) {
    if (Serial.available() > 0) {
      month = Serial.parseInt();
      Serial.println(month);
    }
  }

  Serial.print("Insira Ano: ");
  while (year == 0) {
    if (Serial.available() > 0) {
      year = Serial.parseInt();
      Serial.println(year);
    }
  }
  

}

void loop(void) {
  // ---------------------- CONFIGURAÇÃO E SETUPS -----------

    unsigned long actualTime = millis();
    unsigned long UtlTime;
  // ------------------------------- HORARIO VIA MILLIS() OPERACIONAL -----------------------
    /*
    secs = millis() / 1000 + (long)hourBias * 3600 + (long)minuteBias * 60;
    secsBias = secs % 60;
    mins = (secs / 60) % 60;
    hours = (secs / 3600) % fuso;
    time = hours * 100 + mins;
    */
    if (millis() - UtlTime < 0) {
      UtlTime = millis();
    } else {
      secs = int((millis()) - UtlTime)/1000;
    }
    if (secs > 59) {
      secs = 0;
      mins ++;
      UtlTime = millis();
      if (mins > 59) {
        mins = 0;
        hours ++;
        if (hours > fuso) {
          day ++;
          hours = 0;
          if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
            if (day > 31) {
              day = 1;
              month ++;
              if (month > 12) {
                year ++;
                month = 1;
              }
            }
          } else if ( month == 2) {
            if (year % 400 == 0) {
              if (day > 29) {
                day = 1;
                month ++;
              }
            } else {
              if (day > 28) {
                day = 1;
                month ++;
              }
            }
          } else {
            if (day > 30) {
              day = 1;
              month ++;
            }
          }
        }
      }
    }


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
    if (secs != compareSecs) {
      compareSecs = secs;
      Serial.print(day);
      Serial.print("/");
      Serial.print(month);
      Serial.print("/");
      Serial.print(year);
      Serial.print("     ");
      Serial.print(hours);
      Serial.print(":");
      Serial.print(mins);
      Serial.print(":");
      Serial.println(secs);  
    }

  // ---------------------- ACESSO A PAGINA white white white white white --------------
    if (UtlTime - period >= 5 * 1000) {
      period = UtlTime;
    }  
    telaMenu = 15;
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
    tft.fillRoundRect(43,67, 71, 71, 10, icon_1);
    tft.pushImage(43, 67, 71, 71, icon1);
    tft.fillRoundRect(124,67, 71, 71, 10, icon_2);
    tft.pushImage(124, 67, 71, 71, icon2);
    tft.fillRoundRect(205,67, 71, 71, 10, icon_3);
    tft.pushImage(205, 67, 71, 71, icon3);
    tft.fillRoundRect(286,67, 71, 71, 10, icon_4);
    tft.pushImage(286, 67, 71, 71, icon4);
    tft.fillRoundRect(367,67, 71, 71, 10, icon_5);
    tft.pushImage(367, 67, 71, 71, icon5);

    tft.fillRoundRect(43,147, 71, 71, 10, icon_6);
    tft.pushImage(43, 147, 71, 71, icon6);
    tft.fillRoundRect(124,147, 71, 71, 10, icon_7);
    tft.pushImage(124, 147, 71, 71, icon7);
    tft.fillRoundRect(205,147, 71, 71, 10, icon_8);
    tft.pushImage(205, 147, 71, 71, icon8);
    tft.fillRoundRect(286,147, 71, 71, 10, icon_9);
    tft.pushImage(286, 147, 71, 71, icon9);
    tft.fillRoundRect(367,147, 71, 71, 10, icon_10);
    tft.pushImage(367, 147, 71, 71, icon10);

    tft.fillRoundRect(43,227, 71, 71, 10, icon_11);
    tft.pushImage(43, 227, 71, 71, icon11);
    tft.fillRoundRect(204, 227, 71, 71, 10, icon_13);
    tft.pushImage(205, 227, 71, 71, icon13);
    tft.fillRoundRect(286,227, 71, 71, 10, icon_14);
    tft.pushImage(286, 227, 71, 71, icon14);
    tft.fillRoundRect(367,227, 71, 71, 10, icon_15);
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

  if ((day > 1) && (day < 10)) {
    tft.drawString("0", 77, 30, GFXFF);
    tft.drawString(stringDayMin, 92, 30, GFXFF);
  } else {
    tft.fillRect(77, 22, 28, 20, blackScript);
  }

  if ((month > 1) && (month < 10)) {
    tft.drawString("0", 110, 30, GFXFF);
    tft.drawString(stringMonthMin, 125, 30, GFXFF);
  } else {
    tft.fillRect(110, 22, 28, 20, blackScript);
  }

  tft.drawString(stringYearMin, 143, 30, GFXFF);

  if ((hours > 1) && (hours < 10)) {
    tft.drawString("0", 219, 30, GFXFF);
    tft.drawString(stringHourMin, 234, 30, GFXFF);
  } else {
    tft.fillRect(219, 22, 28, 20, blackScript);
  }

  if ((mins > 1) && (mins < 10)) {
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
  tft.drawRoundRect(361, 21, 50, 20, 5, whiteScript);
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

  tft.pushImage(294, 19, 19, 23, lock);
}

void home() {
  tft.fillTriangle(440, 297, 455, 282, 470, 297, whiteScript);
  tft.fillRect(446, 297, 19, 6, whiteScript);
  tft.fillRect(446, 303, 7, 6, whiteScript);
  tft.fillRect(458, 303, 7, 6, whiteScript);
}

void geigerLoad() { 
  tft.drawLine(142, 105, 143, 105, whiteScript);
  tft.drawLine(147, 105, 149, 105, whiteScript);
  tft.drawLine(153, 105, 155, 105, whiteScript);
  tft.drawLine(159, 105, 161, 105, whiteScript);
  tft.drawLine(165, 105, 167, 105, whiteScript);
  tft.drawLine(171, 105, 173, 105, whiteScript);
  tft.drawLine(177, 105, 179, 105, whiteScript);
  tft.drawLine(183, 105, 185, 105, whiteScript);
  tft.drawLine(189, 105, 191, 105, whiteScript);
  tft.drawLine(195, 105, 197, 105, whiteScript);
  tft.drawLine(201, 105, 203, 105, whiteScript);
  tft.drawLine(207, 105, 209, 105, whiteScript);
  tft.drawLine(213, 105, 215, 105, whiteScript);
  tft.drawLine(219, 105, 221, 105, whiteScript);
  tft.drawLine(225, 105, 227, 105, whiteScript);
  tft.drawLine(231, 105, 233, 105, whiteScript);
  tft.drawLine(237, 105, 239, 105, whiteScript);
  tft.drawLine(243, 105, 245, 105, whiteScript);
  tft.drawLine(249, 105, 251, 105, whiteScript);
  tft.drawLine(255, 105, 257, 105, whiteScript);
  tft.drawLine(261, 105, 263, 105, whiteScript);
  tft.drawLine(267, 105, 269, 105, whiteScript);
  tft.drawLine(273, 105, 275, 105, whiteScript);
  tft.drawLine(279, 105, 281, 105, whiteScript);
  tft.drawLine(285, 105, 287, 105, whiteScript);
  tft.drawLine(291, 105, 293, 105, whiteScript);
  tft.drawLine(297, 105, 299, 105, whiteScript);
  tft.drawLine(303, 105, 305, 105, whiteScript);
  tft.drawLine(309, 105, 311, 105, whiteScript);
  tft.drawLine(315, 105, 317, 105, whiteScript);
  tft.drawLine(321, 105, 323, 105, whiteScript);
  tft.drawLine(327, 105, 329, 105, whiteScript);
  tft.drawLine(333, 105, 335, 105, whiteScript);
  tft.drawLine(339, 105, 341, 105, whiteScript);
  tft.drawLine(345, 105, 347, 105, whiteScript);
  tft.drawLine(351, 105, 353, 105, whiteScript);
  tft.drawLine(357, 105, 359, 105, whiteScript);
  tft.drawLine(363, 105, 365, 105, whiteScript);
  tft.drawLine(369, 105, 371, 105, whiteScript);
  tft.drawLine(375, 105, 377, 105, whiteScript);
  tft.drawLine(381, 105, 383, 105, whiteScript);
  tft.drawLine(387, 105, 389, 105, whiteScript);
  tft.drawLine(393, 105, 395, 105, whiteScript);
  tft.drawLine(399, 105, 401, 105, whiteScript);
  tft.drawLine(405, 105, 407, 105, whiteScript);
  tft.drawLine(411, 105, 413, 105, whiteScript);
  tft.drawLine(417, 105, 419, 105, whiteScript);
  tft.drawLine(423, 105, 425, 105, whiteScript);
  tft.drawLine(429, 105, 431, 105, whiteScript);
  tft.drawLine(435, 105, 437, 105, whiteScript);
  tft.drawLine(441, 105, 442, 105, whiteScript);

  tft.drawLine(142, 125, 143, 125, whiteScript);
  tft.drawLine(147, 125, 149, 125, whiteScript);
  tft.drawLine(153, 125, 155, 125, whiteScript);
  tft.drawLine(159, 125, 161, 125, whiteScript);
  tft.drawLine(165, 125, 167, 125, whiteScript);
  tft.drawLine(171, 125, 173, 125, whiteScript);
  tft.drawLine(177, 125, 179, 125, whiteScript);
  tft.drawLine(183, 125, 185, 125, whiteScript);
  tft.drawLine(189, 125, 191, 125, whiteScript);
  tft.drawLine(195, 125, 197, 125, whiteScript);
  tft.drawLine(201, 125, 203, 125, whiteScript);
  tft.drawLine(207, 125, 209, 125, whiteScript);
  tft.drawLine(213, 125, 215, 125, whiteScript);
  tft.drawLine(219, 125, 221, 125, whiteScript);
  tft.drawLine(225, 125, 227, 125, whiteScript);
  tft.drawLine(231, 125, 233, 125, whiteScript);
  tft.drawLine(237, 125, 239, 125, whiteScript);
  tft.drawLine(243, 125, 245, 125, whiteScript);
  tft.drawLine(249, 125, 251, 125, whiteScript);
  tft.drawLine(255, 125, 257, 125, whiteScript);
  tft.drawLine(261, 125, 263, 125, whiteScript);
  tft.drawLine(267, 125, 269, 125, whiteScript);
  tft.drawLine(273, 125, 275, 125, whiteScript);
  tft.drawLine(279, 125, 281, 125, whiteScript);
  tft.drawLine(285, 125, 287, 125, whiteScript);
  tft.drawLine(291, 125, 293, 125, whiteScript);
  tft.drawLine(297, 125, 299, 125, whiteScript);
  tft.drawLine(303, 125, 305, 125, whiteScript);
  tft.drawLine(309, 125, 311, 125, whiteScript);
  tft.drawLine(315, 125, 317, 125, whiteScript);
  tft.drawLine(321, 125, 323, 125, whiteScript);
  tft.drawLine(327, 125, 329, 125, whiteScript);
  tft.drawLine(333, 125, 335, 125, whiteScript);
  tft.drawLine(339, 125, 341, 125, whiteScript);
  tft.drawLine(345, 125, 347, 125, whiteScript);
  tft.drawLine(351, 125, 353, 125, whiteScript);
  tft.drawLine(357, 125, 359, 125, whiteScript);
  tft.drawLine(363, 125, 365, 125, whiteScript);
  tft.drawLine(369, 125, 371, 125, whiteScript);
  tft.drawLine(375, 125, 377, 125, whiteScript);
  tft.drawLine(381, 125, 383, 125, whiteScript);
  tft.drawLine(387, 125, 389, 125, whiteScript);
  tft.drawLine(393, 125, 395, 125, whiteScript);
  tft.drawLine(399, 125, 401, 125, whiteScript);
  tft.drawLine(405, 125, 407, 125, whiteScript);
  tft.drawLine(411, 125, 413, 125, whiteScript);
  tft.drawLine(417, 125, 419, 125, whiteScript);
  tft.drawLine(423, 125, 425, 125, whiteScript);
  tft.drawLine(429, 125, 431, 125, whiteScript);
  tft.drawLine(435, 125, 437, 125, whiteScript);
  tft.drawLine(441, 125, 442, 125, whiteScript);

  tft.drawLine(142, 145, 143, 145, whiteScript);
  tft.drawLine(147, 145, 149, 145, whiteScript);
  tft.drawLine(153, 145, 155, 145, whiteScript);
  tft.drawLine(159, 145, 161, 145, whiteScript);
  tft.drawLine(165, 145, 167, 145, whiteScript);
  tft.drawLine(171, 145, 173, 145, whiteScript);
  tft.drawLine(177, 145, 179, 145, whiteScript);
  tft.drawLine(183, 145, 185, 145, whiteScript);
  tft.drawLine(189, 145, 191, 145, whiteScript);
  tft.drawLine(195, 145, 197, 145, whiteScript);
  tft.drawLine(201, 145, 203, 145, whiteScript);
  tft.drawLine(207, 145, 209, 145, whiteScript);
  tft.drawLine(213, 145, 215, 145, whiteScript);
  tft.drawLine(219, 145, 221, 145, whiteScript);
  tft.drawLine(225, 145, 227, 145, whiteScript);
  tft.drawLine(231, 145, 233, 145, whiteScript);
  tft.drawLine(237, 145, 239, 145, whiteScript);
  tft.drawLine(243, 145, 245, 145, whiteScript);
  tft.drawLine(249, 145, 251, 145, whiteScript);
  tft.drawLine(255, 145, 257, 145, whiteScript);
  tft.drawLine(261, 145, 263, 145, whiteScript);
  tft.drawLine(267, 145, 269, 145, whiteScript);
  tft.drawLine(273, 145, 275, 145, whiteScript);
  tft.drawLine(279, 145, 281, 145, whiteScript);
  tft.drawLine(285, 145, 287, 145, whiteScript);
  tft.drawLine(291, 145, 293, 145, whiteScript);
  tft.drawLine(297, 145, 299, 145, whiteScript);
  tft.drawLine(303, 145, 305, 145, whiteScript);
  tft.drawLine(309, 145, 311, 145, whiteScript);
  tft.drawLine(315, 145, 317, 145, whiteScript);
  tft.drawLine(321, 145, 323, 145, whiteScript);
  tft.drawLine(327, 145, 329, 145, whiteScript);
  tft.drawLine(333, 145, 335, 145, whiteScript);
  tft.drawLine(339, 145, 341, 145, whiteScript);
  tft.drawLine(345, 145, 347, 145, whiteScript);
  tft.drawLine(351, 145, 353, 145, whiteScript);
  tft.drawLine(357, 145, 359, 145, whiteScript);
  tft.drawLine(363, 145, 365, 145, whiteScript);
  tft.drawLine(369, 145, 371, 145, whiteScript);
  tft.drawLine(375, 145, 377, 145, whiteScript);
  tft.drawLine(381, 145, 383, 145, whiteScript);
  tft.drawLine(387, 145, 389, 145, whiteScript);
  tft.drawLine(393, 145, 395, 145, whiteScript);
  tft.drawLine(399, 145, 401, 145, whiteScript);
  tft.drawLine(405, 145, 407, 145, whiteScript);
  tft.drawLine(411, 145, 413, 145, whiteScript);
  tft.drawLine(417, 145, 419, 145, whiteScript);
  tft.drawLine(423, 145, 425, 145, whiteScript);
  tft.drawLine(429, 145, 431, 145, whiteScript);
  tft.drawLine(435, 145, 437, 145, whiteScript);
  tft.drawLine(441, 145, 442, 145, whiteScript);

  tft.drawLine(142, 165, 143, 165, whiteScript);
  tft.drawLine(147, 165, 149, 165, whiteScript);
  tft.drawLine(153, 165, 155, 165, whiteScript);
  tft.drawLine(159, 165, 161, 165, whiteScript);
  tft.drawLine(165, 165, 167, 165, whiteScript);
  tft.drawLine(171, 165, 173, 165, whiteScript);
  tft.drawLine(177, 165, 179, 165, whiteScript);
  tft.drawLine(183, 165, 185, 165, whiteScript);
  tft.drawLine(189, 165, 191, 165, whiteScript);
  tft.drawLine(195, 165, 197, 165, whiteScript);
  tft.drawLine(201, 165, 203, 165, whiteScript);
  tft.drawLine(207, 165, 209, 165, whiteScript);
  tft.drawLine(213, 165, 215, 165, whiteScript);
  tft.drawLine(219, 165, 221, 165, whiteScript);
  tft.drawLine(225, 165, 227, 165, whiteScript);
  tft.drawLine(231, 165, 233, 165, whiteScript);
  tft.drawLine(237, 165, 239, 165, whiteScript);
  tft.drawLine(243, 165, 245, 165, whiteScript);
  tft.drawLine(249, 165, 251, 165, whiteScript);
  tft.drawLine(255, 165, 257, 165, whiteScript);
  tft.drawLine(261, 165, 263, 165, whiteScript);
  tft.drawLine(267, 165, 269, 165, whiteScript);
  tft.drawLine(273, 165, 275, 165, whiteScript);
  tft.drawLine(279, 165, 281, 165, whiteScript);
  tft.drawLine(285, 165, 287, 165, whiteScript);
  tft.drawLine(291, 165, 293, 165, whiteScript);
  tft.drawLine(297, 165, 299, 165, whiteScript);
  tft.drawLine(303, 165, 305, 165, whiteScript);
  tft.drawLine(309, 165, 311, 165, whiteScript);
  tft.drawLine(315, 165, 317, 165, whiteScript);
  tft.drawLine(321, 165, 323, 165, whiteScript);
  tft.drawLine(327, 165, 329, 165, whiteScript);
  tft.drawLine(333, 165, 335, 165, whiteScript);
  tft.drawLine(339, 165, 341, 165, whiteScript);
  tft.drawLine(345, 165, 347, 165, whiteScript);
  tft.drawLine(351, 165, 353, 165, whiteScript);
  tft.drawLine(357, 165, 359, 165, whiteScript);
  tft.drawLine(363, 165, 365, 165, whiteScript);
  tft.drawLine(369, 165, 371, 165, whiteScript);
  tft.drawLine(375, 165, 377, 165, whiteScript);
  tft.drawLine(381, 165, 383, 165, whiteScript);
  tft.drawLine(387, 165, 389, 165, whiteScript);
  tft.drawLine(393, 165, 395, 165, whiteScript);
  tft.drawLine(399, 165, 401, 165, whiteScript);
  tft.drawLine(405, 165, 407, 165, whiteScript);
  tft.drawLine(411, 165, 413, 165, whiteScript);
  tft.drawLine(417, 165, 419, 165, whiteScript);
  tft.drawLine(423, 165, 425, 165, whiteScript);
  tft.drawLine(429, 165, 431, 165, whiteScript);
  tft.drawLine(435, 165, 437, 165, whiteScript);
  tft.drawLine(441, 165, 442, 165, whiteScript);

  tft.drawLine(172, 85, 172, 86, whiteScript);
  tft.drawLine(172, 90, 172, 92, whiteScript);
  tft.drawLine(172, 96, 172, 98, whiteScript);
  tft.drawLine(172, 102, 172, 104, whiteScript);
  tft.drawLine(172, 108, 172, 110, whiteScript);
  tft.drawLine(172, 114, 172, 116, whiteScript);
  tft.drawLine(172, 120, 172, 122, whiteScript);
  tft.drawLine(172, 126, 172, 128, whiteScript);
  tft.drawLine(172, 132, 172, 134, whiteScript);
  tft.drawLine(172, 138, 172, 140, whiteScript);
  tft.drawLine(172, 144, 172, 146, whiteScript);
  tft.drawLine(172, 150, 172, 152, whiteScript);
  tft.drawLine(172, 156, 172, 158, whiteScript);
  tft.drawLine(172, 162, 172, 164, whiteScript);
  tft.drawLine(172, 168, 172, 170, whiteScript);
  tft.drawLine(172, 174, 172, 176, whiteScript);
  tft.drawLine(172, 180, 172, 182, whiteScript);
  tft.drawLine(172, 186, 172, 187, whiteScript);

  tft.drawLine(202, 85, 202, 86, whiteScript);
  tft.drawLine(202, 90, 202, 92, whiteScript);
  tft.drawLine(202, 96, 202, 98, whiteScript);
  tft.drawLine(202, 102, 202, 104, whiteScript);
  tft.drawLine(202, 108, 202, 110, whiteScript);
  tft.drawLine(202, 114, 202, 116, whiteScript);
  tft.drawLine(202, 120, 202, 122, whiteScript);
  tft.drawLine(202, 126, 202, 128, whiteScript);
  tft.drawLine(202, 132, 202, 134, whiteScript);
  tft.drawLine(202, 138, 202, 140, whiteScript);
  tft.drawLine(202, 144, 202, 146, whiteScript);
  tft.drawLine(202, 150, 202, 152, whiteScript);
  tft.drawLine(202, 156, 202, 158, whiteScript);
  tft.drawLine(202, 162, 202, 164, whiteScript);
  tft.drawLine(202, 168, 202, 170, whiteScript);
  tft.drawLine(202, 174, 202, 176, whiteScript);
  tft.drawLine(202, 180, 202, 182, whiteScript);
  tft.drawLine(202, 186, 202, 187, whiteScript);

  tft.drawLine(232, 85, 232, 86, whiteScript);
  tft.drawLine(232, 90, 232, 92, whiteScript);
  tft.drawLine(232, 96, 232, 98, whiteScript);
  tft.drawLine(232, 102, 232, 104, whiteScript);
  tft.drawLine(232, 108, 232, 110, whiteScript);
  tft.drawLine(232, 114, 232, 116, whiteScript);
  tft.drawLine(232, 120, 232, 122, whiteScript);
  tft.drawLine(232, 126, 232, 128, whiteScript);
  tft.drawLine(232, 132, 232, 134, whiteScript);
  tft.drawLine(232, 138, 232, 140, whiteScript);
  tft.drawLine(232, 144, 232, 146, whiteScript);
  tft.drawLine(232, 150, 232, 152, whiteScript);
  tft.drawLine(232, 156, 232, 158, whiteScript);
  tft.drawLine(232, 162, 232, 164, whiteScript);
  tft.drawLine(232, 168, 232, 170, whiteScript);
  tft.drawLine(232, 174, 232, 176, whiteScript);
  tft.drawLine(232, 180, 232, 182, whiteScript);
  tft.drawLine(232, 186, 232, 187, whiteScript);

  tft.drawLine(262, 85, 262, 86, whiteScript);
  tft.drawLine(262, 90, 262, 92, whiteScript);
  tft.drawLine(262, 96, 262, 98, whiteScript);
  tft.drawLine(262, 102, 262, 104, whiteScript);
  tft.drawLine(262, 108, 262, 110, whiteScript);
  tft.drawLine(262, 114, 262, 116, whiteScript);
  tft.drawLine(262, 120, 262, 122, whiteScript);
  tft.drawLine(262, 126, 262, 128, whiteScript);
  tft.drawLine(262, 132, 262, 134, whiteScript);
  tft.drawLine(262, 138, 262, 140, whiteScript);
  tft.drawLine(262, 144, 262, 146, whiteScript);
  tft.drawLine(262, 150, 262, 152, whiteScript);
  tft.drawLine(262, 156, 262, 158, whiteScript);
  tft.drawLine(262, 162, 262, 164, whiteScript);
  tft.drawLine(262, 168, 262, 170, whiteScript);
  tft.drawLine(262, 174, 262, 176, whiteScript);
  tft.drawLine(262, 180, 262, 182, whiteScript);
  tft.drawLine(262, 186, 262, 187, whiteScript);

  tft.drawLine(292, 85, 292, 86, whiteScript);
  tft.drawLine(292, 90, 292, 92, whiteScript);
  tft.drawLine(292, 96, 292, 98, whiteScript);
  tft.drawLine(292, 102, 292, 104, whiteScript);
  tft.drawLine(292, 108, 292, 110, whiteScript);
  tft.drawLine(292, 114, 292, 116, whiteScript);
  tft.drawLine(292, 120, 292, 122, whiteScript);
  tft.drawLine(292, 126, 292, 128, whiteScript);
  tft.drawLine(292, 132, 292, 134, whiteScript);
  tft.drawLine(292, 138, 292, 140, whiteScript);
  tft.drawLine(292, 144, 292, 146, whiteScript);
  tft.drawLine(292, 150, 292, 152, whiteScript);
  tft.drawLine(292, 156, 292, 158, whiteScript);
  tft.drawLine(292, 162, 292, 164, whiteScript);
  tft.drawLine(292, 168, 292, 170, whiteScript);
  tft.drawLine(292, 174, 292, 176, whiteScript);
  tft.drawLine(292, 180, 292, 182, whiteScript);
  tft.drawLine(292, 186, 292, 187, whiteScript);

  tft.drawLine(322, 85, 322, 86, whiteScript);
  tft.drawLine(322, 90, 322, 92, whiteScript);
  tft.drawLine(322, 96, 322, 98, whiteScript);
  tft.drawLine(322, 102, 322, 104, whiteScript);
  tft.drawLine(322, 108, 322, 110, whiteScript);
  tft.drawLine(322, 114, 322, 116, whiteScript);
  tft.drawLine(322, 120, 322, 122, whiteScript);
  tft.drawLine(322, 126, 322, 128, whiteScript);
  tft.drawLine(322, 132, 322, 134, whiteScript);
  tft.drawLine(322, 138, 322, 140, whiteScript);
  tft.drawLine(322, 144, 322, 146, whiteScript);
  tft.drawLine(322, 150, 322, 152, whiteScript);
  tft.drawLine(322, 156, 322, 158, whiteScript);
  tft.drawLine(322, 162, 322, 164, whiteScript);
  tft.drawLine(322, 168, 322, 170, whiteScript);
  tft.drawLine(322, 174, 322, 176, whiteScript);
  tft.drawLine(322, 180, 322, 182, whiteScript);
  tft.drawLine(322, 186, 322, 187, whiteScript);

  tft.drawLine(352, 85, 352, 86, whiteScript);
  tft.drawLine(352, 90, 352, 92, whiteScript);
  tft.drawLine(352, 96, 352, 98, whiteScript);
  tft.drawLine(352, 102, 352, 104, whiteScript);
  tft.drawLine(352, 108, 352, 110, whiteScript);
  tft.drawLine(352, 114, 352, 116, whiteScript);
  tft.drawLine(352, 120, 352, 122, whiteScript);
  tft.drawLine(352, 126, 352, 128, whiteScript);
  tft.drawLine(352, 132, 352, 134, whiteScript);
  tft.drawLine(352, 138, 352, 140, whiteScript);
  tft.drawLine(352, 144, 352, 146, whiteScript);
  tft.drawLine(352, 150, 352, 152, whiteScript);
  tft.drawLine(352, 156, 352, 158, whiteScript);
  tft.drawLine(352, 162, 352, 164, whiteScript);
  tft.drawLine(352, 168, 352, 170, whiteScript);
  tft.drawLine(352, 174, 352, 176, whiteScript);
  tft.drawLine(352, 180, 352, 182, whiteScript);
  tft.drawLine(352, 186, 352, 187, whiteScript);

  tft.drawLine(382, 85, 382, 86, whiteScript);
  tft.drawLine(382, 90, 382, 92, whiteScript);
  tft.drawLine(382, 96, 382, 98, whiteScript);
  tft.drawLine(382, 102, 382, 104, whiteScript);
  tft.drawLine(382, 108, 382, 110, whiteScript);
  tft.drawLine(382, 114, 382, 116, whiteScript);
  tft.drawLine(382, 120, 382, 122, whiteScript);
  tft.drawLine(382, 126, 382, 128, whiteScript);
  tft.drawLine(382, 132, 382, 134, whiteScript);
  tft.drawLine(382, 138, 382, 140, whiteScript);
  tft.drawLine(382, 144, 382, 146, whiteScript);
  tft.drawLine(382, 150, 382, 152, whiteScript);
  tft.drawLine(382, 156, 382, 158, whiteScript);
  tft.drawLine(382, 162, 382, 164, whiteScript);
  tft.drawLine(382, 168, 382, 170, whiteScript);
  tft.drawLine(382, 174, 382, 176, whiteScript);
  tft.drawLine(382, 180, 382, 182, whiteScript);
  tft.drawLine(382, 186, 382, 187, whiteScript);

  tft.drawLine(412, 85, 412, 86, whiteScript);
  tft.drawLine(412, 90, 412, 92, whiteScript);
  tft.drawLine(412, 96, 412, 98, whiteScript);
  tft.drawLine(412, 102, 412, 104, whiteScript);
  tft.drawLine(412, 108, 412, 110, whiteScript);
  tft.drawLine(412, 114, 412, 116, whiteScript);
  tft.drawLine(412, 120, 412, 122, whiteScript);
  tft.drawLine(412, 126, 412, 128, whiteScript);
  tft.drawLine(412, 132, 412, 134, whiteScript);
  tft.drawLine(412, 138, 412, 140, whiteScript);
  tft.drawLine(412, 144, 412, 146, whiteScript);
  tft.drawLine(412, 150, 412, 152, whiteScript);
  tft.drawLine(412, 156, 412, 158, whiteScript);
  tft.drawLine(412, 162, 412, 164, whiteScript);
  tft.drawLine(412, 168, 412, 170, whiteScript);
  tft.drawLine(412, 174, 412, 176, whiteScript);
  tft.drawLine(412, 180, 412, 182, whiteScript);
  tft.drawLine(412, 186, 412, 187, whiteScript);
}

void geigerAlarm() {

  tft.pushImage(146, 205, 71, 71, icon1);
}

void dosimeter() {
  tft.drawRect(34, 112, 400, 25, whiteScript);
  tft.fillRect(184, 107, 35, 5, geigerLevel1);

  tft.setFreeFont(latoRegular10);

  tft.drawString("2", 37, 98, GFXFF);
  tft.drawString("5", 47, 98, GFXFF);
  tft.drawString("20", 87, 98, GFXFF);
  tft.drawString("50", 124, 98, GFXFF);
  tft.drawString("500", 235, 98, GFXFF);
  tft.drawString("2K", 388, 98, GFXFF);

  tft.setFreeFont(latoRegular14);

  tft.drawString("10", 57, 95, GFXFF);
  tft.drawString("100", 172, 95, GFXFF);
  tft.drawString("1K", 286, 95, GFXFF);
}

void dosimeterAlarm() {

  tft.pushImage(46, 205, 71, 71, icon1);
}

void dosimeterLoad() { 
  tft.drawPixel(33, 78, whiteScript);
  tft.drawLine(33, 86, 33, 88, whiteScript);
  tft.drawLine(33, 96, 33, 98, whiteScript);
  tft.drawLine(33, 106, 33, 108, whiteScript);
  tft.drawLine(33, 116, 33, 118, whiteScript);
  tft.drawLine(33, 126, 33, 128, whiteScript);
  tft.drawLine(33, 136, 33, 138, whiteScript);
  tft.drawLine(33, 146, 33, 148, whiteScript);
  tft.drawLine(33, 156, 33, 158, whiteScript);
  tft.drawLine(33, 166, 33, 168, whiteScript);
  tft.drawLine(33, 176, 33, 178, whiteScript);
  tft.drawLine(33, 186, 33, 188, whiteScript);
  tft.drawPixel(33, 196, whiteScript);

  tft.drawPixel(66, 78, whiteScript);
  tft.drawLine(66, 86, 66, 88, whiteScript);
  tft.drawLine(66, 96, 66, 98, whiteScript);
  tft.drawLine(66, 106, 66, 108, whiteScript);
  tft.drawLine(66, 116, 66, 118, whiteScript);
  tft.drawLine(66, 126, 66, 128, whiteScript);
  tft.drawLine(66, 136, 66, 138, whiteScript);
  tft.drawLine(66, 146, 66, 148, whiteScript);
  tft.drawLine(66, 156, 66, 158, whiteScript);
  tft.drawLine(66, 166, 66, 168, whiteScript);
  tft.drawLine(66, 176, 66, 178, whiteScript);
  tft.drawLine(66, 186, 66, 188, whiteScript);
  tft.drawPixel(66, 196, whiteScript);

  tft.drawPixel(99, 78, whiteScript);
  tft.drawLine(99, 86, 99, 88, whiteScript);
  tft.drawLine(99, 96, 99, 98, whiteScript);
  tft.drawLine(99, 106, 99, 108, whiteScript);
  tft.drawLine(99, 116, 99, 118, whiteScript);
  tft.drawLine(99, 126, 99, 128, whiteScript);
  tft.drawLine(99, 136, 99, 138, whiteScript);
  tft.drawLine(99, 146, 99, 148, whiteScript);
  tft.drawLine(99, 156, 99, 158, whiteScript);
  tft.drawLine(99, 166, 99, 168, whiteScript);
  tft.drawLine(99, 176, 99, 178, whiteScript);
  tft.drawLine(99, 186, 99, 188, whiteScript);
  tft.drawPixel(99, 196, whiteScript);

  tft.drawPixel(133, 78, whiteScript);
  tft.drawLine(133, 86, 133, 88, whiteScript);
  tft.drawLine(133, 96, 133, 98, whiteScript);
  tft.drawLine(133, 106, 133, 108, whiteScript);
  tft.drawLine(133, 116, 133, 118, whiteScript);
  tft.drawLine(133, 126, 133, 128, whiteScript);
  tft.drawLine(133, 136, 133, 138, whiteScript);
  tft.drawLine(133, 146, 133, 148, whiteScript);
  tft.drawLine(133, 156, 133, 158, whiteScript);
  tft.drawLine(133, 166, 133, 168, whiteScript);
  tft.drawLine(133, 176, 133, 178, whiteScript);
  tft.drawLine(133, 186, 133, 188, whiteScript);
  tft.drawPixel(133, 196, whiteScript);

  tft.drawPixel(166, 78, whiteScript);
  tft.drawLine(166, 86, 166, 88, whiteScript);
  tft.drawLine(166, 96, 166, 98, whiteScript);
  tft.drawLine(166, 106, 166, 108, whiteScript);
  tft.drawLine(166, 116, 166, 118, whiteScript);
  tft.drawLine(166, 126, 166, 128, whiteScript);
  tft.drawLine(166, 136, 166, 138, whiteScript);
  tft.drawLine(166, 146, 166, 148, whiteScript);
  tft.drawLine(166, 156, 166, 158, whiteScript);
  tft.drawLine(166, 166, 166, 168, whiteScript);
  tft.drawLine(166, 176, 166, 178, whiteScript);
  tft.drawLine(166, 186, 166, 188, whiteScript);
  tft.drawPixel(166, 196, whiteScript);

  tft.drawPixel(199, 78, whiteScript);
  tft.drawLine(199, 86, 199, 88, whiteScript);
  tft.drawLine(199, 96, 199, 98, whiteScript);
  tft.drawLine(199, 106, 199, 108, whiteScript);
  tft.drawLine(199, 116, 199, 118, whiteScript);
  tft.drawLine(199, 126, 199, 128, whiteScript);
  tft.drawLine(199, 136, 199, 138, whiteScript);
  tft.drawLine(199, 146, 199, 148, whiteScript);
  tft.drawLine(199, 156, 199, 158, whiteScript);
  tft.drawLine(199, 166, 199, 168, whiteScript);
  tft.drawLine(199, 176, 199, 178, whiteScript);
  tft.drawLine(199, 186, 199, 188, whiteScript);
  tft.drawPixel(199, 196, whiteScript);

  tft.drawPixel(233, 78, whiteScript);
  tft.drawLine(233, 86, 233, 88, whiteScript);
  tft.drawLine(233, 96, 233, 98, whiteScript);
  tft.drawLine(233, 106, 233, 108, whiteScript);
  tft.drawLine(233, 116, 233, 118, whiteScript);
  tft.drawLine(233, 126, 233, 128, whiteScript);
  tft.drawLine(233, 136, 233, 138, whiteScript);
  tft.drawLine(233, 146, 233, 148, whiteScript);
  tft.drawLine(233, 156, 233, 158, whiteScript);
  tft.drawLine(233, 166, 233, 168, whiteScript);
  tft.drawLine(233, 176, 233, 178, whiteScript);
  tft.drawLine(233, 186, 233, 188, whiteScript);
  tft.drawPixel(233, 196, whiteScript);

  tft.drawPixel(266, 78, whiteScript);
  tft.drawLine(266, 86, 266, 88, whiteScript);
  tft.drawLine(266, 96, 266, 98, whiteScript);
  tft.drawLine(266, 106, 266, 108, whiteScript);
  tft.drawLine(266, 116, 266, 118, whiteScript);
  tft.drawLine(266, 126, 266, 128, whiteScript);
  tft.drawLine(266, 136, 266, 138, whiteScript);
  tft.drawLine(266, 146, 266, 148, whiteScript);
  tft.drawLine(266, 156, 266, 158, whiteScript);
  tft.drawLine(266, 166, 266, 168, whiteScript);
  tft.drawLine(266, 176, 266, 178, whiteScript);
  tft.drawLine(266, 186, 266, 188, whiteScript);
  tft.drawPixel(266, 196, whiteScript);

  tft.drawPixel(299, 78, whiteScript);
  tft.drawLine(299, 86, 299, 88, whiteScript);
  tft.drawLine(299, 96, 299, 98, whiteScript);
  tft.drawLine(299, 106, 299, 108, whiteScript);
  tft.drawLine(299, 116, 299, 118, whiteScript);
  tft.drawLine(299, 126, 299, 128, whiteScript);
  tft.drawLine(299, 136, 299, 138, whiteScript);
  tft.drawLine(299, 146, 299, 148, whiteScript);
  tft.drawLine(299, 156, 299, 158, whiteScript);
  tft.drawLine(299, 166, 299, 168, whiteScript);
  tft.drawLine(299, 176, 299, 178, whiteScript);
  tft.drawLine(299, 186, 299, 188, whiteScript);
  tft.drawPixel(299, 196, whiteScript);

  tft.drawPixel(333, 78, whiteScript);
  tft.drawLine(333, 86, 333, 88, whiteScript);
  tft.drawLine(333, 96, 333, 98, whiteScript);
  tft.drawLine(333, 106, 333, 108, whiteScript);
  tft.drawLine(333, 116, 333, 118, whiteScript);
  tft.drawLine(333, 126, 333, 128, whiteScript);
  tft.drawLine(333, 136, 333, 138, whiteScript);
  tft.drawLine(333, 146, 333, 148, whiteScript);
  tft.drawLine(333, 156, 333, 158, whiteScript);
  tft.drawLine(333, 166, 333, 168, whiteScript);
  tft.drawLine(333, 176, 333, 178, whiteScript);
  tft.drawLine(333, 186, 333, 188, whiteScript);
  tft.drawPixel(333, 196, whiteScript);

  tft.drawPixel(367, 78, whiteScript);
  tft.drawLine(367, 86, 367, 88, whiteScript);
  tft.drawLine(367, 96, 367, 98, whiteScript);
  tft.drawLine(367, 106, 367, 108, whiteScript);
  tft.drawLine(367, 116, 367, 118, whiteScript);
  tft.drawLine(367, 126, 367, 128, whiteScript);
  tft.drawLine(367, 136, 367, 138, whiteScript);
  tft.drawLine(367, 146, 367, 148, whiteScript);
  tft.drawLine(367, 156, 367, 158, whiteScript);
  tft.drawLine(367, 166, 367, 168, whiteScript);
  tft.drawLine(367, 176, 367, 178, whiteScript);
  tft.drawLine(367, 186, 367, 188, whiteScript);
  tft.drawPixel(367, 196, whiteScript);

  tft.drawPixel(399, 78, whiteScript);
  tft.drawLine(399, 86, 399, 88, whiteScript);
  tft.drawLine(399, 96, 399, 98, whiteScript);
  tft.drawLine(399, 106, 399, 108, whiteScript);
  tft.drawLine(399, 116, 399, 118, whiteScript);
  tft.drawLine(399, 126, 399, 128, whiteScript);
  tft.drawLine(399, 136, 399, 138, whiteScript);
  tft.drawLine(399, 146, 399, 148, whiteScript);
  tft.drawLine(399, 156, 399, 158, whiteScript);
  tft.drawLine(399, 166, 399, 168, whiteScript);
  tft.drawLine(399, 176, 399, 178, whiteScript);
  tft.drawLine(399, 186, 399, 188, whiteScript);
  tft.drawPixel(399, 196, whiteScript);

  tft.drawPixel(433, 78, whiteScript);
  tft.drawLine(433, 86, 433, 88, whiteScript);
  tft.drawLine(433, 96, 433, 98, whiteScript);
  tft.drawLine(433, 106, 433, 108, whiteScript);
  tft.drawLine(433, 116, 433, 118, whiteScript);
  tft.drawLine(433, 126, 433, 128, whiteScript);
  tft.drawLine(433, 136, 433, 138, whiteScript);
  tft.drawLine(433, 146, 433, 148, whiteScript);
  tft.drawLine(433, 156, 433, 158, whiteScript);
  tft.drawLine(433, 166, 433, 168, whiteScript);
  tft.drawLine(433, 176, 433, 178, whiteScript);
  tft.drawLine(433, 186, 433, 188, whiteScript);
  tft.drawPixel(433, 196, whiteScript);

  tft.drawLine(32, 208, 32, 213, highValueColor);
  tft.drawLine(33, 208, 33, 213, highValueColor);

  tft.drawLine(132, 208, 132, 213, highValueColor);
  tft.drawLine(133, 208, 133, 213, highValueColor);

  tft.drawLine(232, 208, 232, 213, highValueColor);
  tft.drawLine(233, 208, 233, 213, highValueColor);

  tft.drawLine(332, 208, 332, 213, highValueColor);
  tft.drawLine(333, 208, 333, 213, highValueColor);

  tft.drawLine(432, 208, 432, 213, highValueColor);
  tft.drawLine(433, 208, 433, 213, highValueColor);

  tft.drawLine(80, 208, 80, 212, middleTimeGraph);
  tft.drawLine(181, 208, 181, 212, middleTimeGraph);
  tft.drawLine(282, 208, 282, 212, middleTimeGraph);
  tft.drawLine(382, 208, 382, 212, middleTimeGraph);

  tft.setTextDatum(ML_DATUM);
  tft.setTextColor(whiteScript);
  tft.setFreeFont(latoRegular24);

  tft.drawString("0", 26, 228, GFXFF);
  tft.drawString("6", 125, 228, GFXFF);
  tft.drawString("12", 220, 228, GFXFF);
  tft.drawString("18", 318, 228, GFXFF);
  tft.drawString("24", 418, 228, GFXFF);

  tft.setFreeFont(latoRegular14);

  tft.drawString("3", 76, 225, GFXFF);
  tft.drawString("9", 178, 225, GFXFF);
  tft.drawString("15", 274, 225, GFXFF);
  tft.drawString("21", 374, 225, GFXFF);
} 

void temperatureLoad() { 
  tft.drawPixel(33, 78, whiteScript);
  tft.drawLine(33, 86, 33, 88, whiteScript);
  tft.drawLine(33, 96, 33, 98, whiteScript);
  tft.drawLine(33, 106, 33, 108, whiteScript);
  tft.drawLine(33, 116, 33, 118, whiteScript);
  tft.drawLine(33, 126, 33, 128, whiteScript);
  tft.drawLine(33, 136, 33, 138, whiteScript);
  tft.drawLine(33, 146, 33, 148, whiteScript);
  tft.drawLine(33, 156, 33, 158, whiteScript);
  tft.drawLine(33, 166, 33, 168, whiteScript);
  tft.drawLine(33, 176, 33, 178, whiteScript);
  tft.drawLine(33, 186, 33, 188, whiteScript);
  tft.drawPixel(33, 196, whiteScript);

  tft.drawPixel(66, 78, whiteScript);
  tft.drawLine(66, 86, 66, 88, whiteScript);
  tft.drawLine(66, 96, 66, 98, whiteScript);
  tft.drawLine(66, 106, 66, 108, whiteScript);
  tft.drawLine(66, 116, 66, 118, whiteScript);
  tft.drawLine(66, 126, 66, 128, whiteScript);
  tft.drawLine(66, 136, 66, 138, whiteScript);
  tft.drawLine(66, 146, 66, 148, whiteScript);
  tft.drawLine(66, 156, 66, 158, whiteScript);
  tft.drawLine(66, 166, 66, 168, whiteScript);
  tft.drawLine(66, 176, 66, 178, whiteScript);
  tft.drawLine(66, 186, 66, 188, whiteScript);
  tft.drawPixel(66, 196, whiteScript);

  tft.drawPixel(99, 78, whiteScript);
  tft.drawLine(99, 86, 99, 88, whiteScript);
  tft.drawLine(99, 96, 99, 98, whiteScript);
  tft.drawLine(99, 106, 99, 108, whiteScript);
  tft.drawLine(99, 116, 99, 118, whiteScript);
  tft.drawLine(99, 126, 99, 128, whiteScript);
  tft.drawLine(99, 136, 99, 138, whiteScript);
  tft.drawLine(99, 146, 99, 148, whiteScript);
  tft.drawLine(99, 156, 99, 158, whiteScript);
  tft.drawLine(99, 166, 99, 168, whiteScript);
  tft.drawLine(99, 176, 99, 178, whiteScript);
  tft.drawLine(99, 186, 99, 188, whiteScript);
  tft.drawPixel(99, 196, whiteScript);

  tft.drawPixel(133, 78, whiteScript);
  tft.drawLine(133, 86, 133, 88, whiteScript);
  tft.drawLine(133, 96, 133, 98, whiteScript);
  tft.drawLine(133, 106, 133, 108, whiteScript);
  tft.drawLine(133, 116, 133, 118, whiteScript);
  tft.drawLine(133, 126, 133, 128, whiteScript);
  tft.drawLine(133, 136, 133, 138, whiteScript);
  tft.drawLine(133, 146, 133, 148, whiteScript);
  tft.drawLine(133, 156, 133, 158, whiteScript);
  tft.drawLine(133, 166, 133, 168, whiteScript);
  tft.drawLine(133, 176, 133, 178, whiteScript);
  tft.drawLine(133, 186, 133, 188, whiteScript);
  tft.drawPixel(133, 196, whiteScript);

  tft.drawPixel(166, 78, whiteScript);
  tft.drawLine(166, 86, 166, 88, whiteScript);
  tft.drawLine(166, 96, 166, 98, whiteScript);
  tft.drawLine(166, 106, 166, 108, whiteScript);
  tft.drawLine(166, 116, 166, 118, whiteScript);
  tft.drawLine(166, 126, 166, 128, whiteScript);
  tft.drawLine(166, 136, 166, 138, whiteScript);
  tft.drawLine(166, 146, 166, 148, whiteScript);
  tft.drawLine(166, 156, 166, 158, whiteScript);
  tft.drawLine(166, 166, 166, 168, whiteScript);
  tft.drawLine(166, 176, 166, 178, whiteScript);
  tft.drawLine(166, 186, 166, 188, whiteScript);
  tft.drawPixel(166, 196, whiteScript);

  tft.drawPixel(199, 78, whiteScript);
  tft.drawLine(199, 86, 199, 88, whiteScript);
  tft.drawLine(199, 96, 199, 98, whiteScript);
  tft.drawLine(199, 106, 199, 108, whiteScript);
  tft.drawLine(199, 116, 199, 118, whiteScript);
  tft.drawLine(199, 126, 199, 128, whiteScript);
  tft.drawLine(199, 136, 199, 138, whiteScript);
  tft.drawLine(199, 146, 199, 148, whiteScript);
  tft.drawLine(199, 156, 199, 158, whiteScript);
  tft.drawLine(199, 166, 199, 168, whiteScript);
  tft.drawLine(199, 176, 199, 178, whiteScript);
  tft.drawLine(199, 186, 199, 188, whiteScript);
  tft.drawPixel(199, 196, whiteScript);

  tft.drawPixel(233, 78, whiteScript);
  tft.drawLine(233, 86, 233, 88, whiteScript);
  tft.drawLine(233, 96, 233, 98, whiteScript);
  tft.drawLine(233, 106, 233, 108, whiteScript);
  tft.drawLine(233, 116, 233, 118, whiteScript);
  tft.drawLine(233, 126, 233, 128, whiteScript);
  tft.drawLine(233, 136, 233, 138, whiteScript);
  tft.drawLine(233, 146, 233, 148, whiteScript);
  tft.drawLine(233, 156, 233, 158, whiteScript);
  tft.drawLine(233, 166, 233, 168, whiteScript);
  tft.drawLine(233, 176, 233, 178, whiteScript);
  tft.drawLine(233, 186, 233, 188, whiteScript);
  tft.drawPixel(233, 196, whiteScript);

  tft.drawPixel(266, 78, whiteScript);
  tft.drawLine(266, 86, 266, 88, whiteScript);
  tft.drawLine(266, 96, 266, 98, whiteScript);
  tft.drawLine(266, 106, 266, 108, whiteScript);
  tft.drawLine(266, 116, 266, 118, whiteScript);
  tft.drawLine(266, 126, 266, 128, whiteScript);
  tft.drawLine(266, 136, 266, 138, whiteScript);
  tft.drawLine(266, 146, 266, 148, whiteScript);
  tft.drawLine(266, 156, 266, 158, whiteScript);
  tft.drawLine(266, 166, 266, 168, whiteScript);
  tft.drawLine(266, 176, 266, 178, whiteScript);
  tft.drawLine(266, 186, 266, 188, whiteScript);
  tft.drawPixel(266, 196, whiteScript);

  tft.drawPixel(299, 78, whiteScript);
  tft.drawLine(299, 86, 299, 88, whiteScript);
  tft.drawLine(299, 96, 299, 98, whiteScript);
  tft.drawLine(299, 106, 299, 108, whiteScript);
  tft.drawLine(299, 116, 299, 118, whiteScript);
  tft.drawLine(299, 126, 299, 128, whiteScript);
  tft.drawLine(299, 136, 299, 138, whiteScript);
  tft.drawLine(299, 146, 299, 148, whiteScript);
  tft.drawLine(299, 156, 299, 158, whiteScript);
  tft.drawLine(299, 166, 299, 168, whiteScript);
  tft.drawLine(299, 176, 299, 178, whiteScript);
  tft.drawLine(299, 186, 299, 188, whiteScript);
  tft.drawPixel(299, 196, whiteScript);

  tft.drawPixel(333, 78, whiteScript);
  tft.drawLine(333, 86, 333, 88, whiteScript);
  tft.drawLine(333, 96, 333, 98, whiteScript);
  tft.drawLine(333, 106, 333, 108, whiteScript);
  tft.drawLine(333, 116, 333, 118, whiteScript);
  tft.drawLine(333, 126, 333, 128, whiteScript);
  tft.drawLine(333, 136, 333, 138, whiteScript);
  tft.drawLine(333, 146, 333, 148, whiteScript);
  tft.drawLine(333, 156, 333, 158, whiteScript);
  tft.drawLine(333, 166, 333, 168, whiteScript);
  tft.drawLine(333, 176, 333, 178, whiteScript);
  tft.drawLine(333, 186, 333, 188, whiteScript);
  tft.drawPixel(333, 196, whiteScript);

  tft.drawPixel(367, 78, whiteScript);
  tft.drawLine(367, 86, 367, 88, whiteScript);
  tft.drawLine(367, 96, 367, 98, whiteScript);
  tft.drawLine(367, 106, 367, 108, whiteScript);
  tft.drawLine(367, 116, 367, 118, whiteScript);
  tft.drawLine(367, 126, 367, 128, whiteScript);
  tft.drawLine(367, 136, 367, 138, whiteScript);
  tft.drawLine(367, 146, 367, 148, whiteScript);
  tft.drawLine(367, 156, 367, 158, whiteScript);
  tft.drawLine(367, 166, 367, 168, whiteScript);
  tft.drawLine(367, 176, 367, 178, whiteScript);
  tft.drawLine(367, 186, 367, 188, whiteScript);
  tft.drawPixel(367, 196, whiteScript);

  tft.drawPixel(399, 78, whiteScript);
  tft.drawLine(399, 86, 399, 88, whiteScript);
  tft.drawLine(399, 96, 399, 98, whiteScript);
  tft.drawLine(399, 106, 399, 108, whiteScript);
  tft.drawLine(399, 116, 399, 118, whiteScript);
  tft.drawLine(399, 126, 399, 128, whiteScript);
  tft.drawLine(399, 136, 399, 138, whiteScript);
  tft.drawLine(399, 146, 399, 148, whiteScript);
  tft.drawLine(399, 156, 399, 158, whiteScript);
  tft.drawLine(399, 166, 399, 168, whiteScript);
  tft.drawLine(399, 176, 399, 178, whiteScript);
  tft.drawLine(399, 186, 399, 188, whiteScript);
  tft.drawPixel(399, 196, whiteScript);

  tft.drawPixel(433, 78, whiteScript);
  tft.drawLine(433, 86, 433, 88, whiteScript);
  tft.drawLine(433, 96, 433, 98, whiteScript);
  tft.drawLine(433, 106, 433, 108, whiteScript);
  tft.drawLine(433, 116, 433, 118, whiteScript);
  tft.drawLine(433, 126, 433, 128, whiteScript);
  tft.drawLine(433, 136, 433, 138, whiteScript);
  tft.drawLine(433, 146, 433, 148, whiteScript);
  tft.drawLine(433, 156, 433, 158, whiteScript);
  tft.drawLine(433, 166, 433, 168, whiteScript);
  tft.drawLine(433, 176, 433, 178, whiteScript);
  tft.drawLine(433, 186, 433, 188, whiteScript);
  tft.drawPixel(433, 196, whiteScript);

  tft.drawLine(32, 208, 32, 213, temperatureColor1);
  tft.drawLine(33, 208, 33, 213, temperatureColor1);

  tft.drawLine(132, 208, 132, 213, temperatureColor1);
  tft.drawLine(133, 208, 133, 213, temperatureColor1);

  tft.drawLine(232, 208, 232, 213, temperatureColor1);
  tft.drawLine(233, 208, 233, 213, temperatureColor1);

  tft.drawLine(332, 208, 332, 213, temperatureColor1);
  tft.drawLine(333, 208, 333, 213, temperatureColor1);

  tft.drawLine(432, 208, 432, 213, temperatureColor1);
  tft.drawLine(433, 208, 433, 213, temperatureColor1);

  tft.drawLine(80, 208, 80, 212, middleTimeGraph);
  tft.drawLine(181, 208, 181, 212, middleTimeGraph);
  tft.drawLine(282, 208, 282, 212, middleTimeGraph);
  tft.drawLine(382, 208, 382, 212, middleTimeGraph);

  tft.setTextDatum(ML_DATUM);
  tft.setTextColor(whiteScript);
  tft.setFreeFont(latoRegular24);

  tft.drawString("0", 26, 228, GFXFF);
  tft.drawString("6", 125, 228, GFXFF);
  tft.drawString("12", 220, 228, GFXFF);
  tft.drawString("18", 318, 228, GFXFF);
  tft.drawString("24", 418, 228, GFXFF);

  tft.setFreeFont(latoRegular14);

  tft.drawString("3", 76, 225, GFXFF);
  tft.drawString("9", 178, 225, GFXFF);
  tft.drawString("15", 274, 225, GFXFF);
  tft.drawString("21", 374, 225, GFXFF);
} 

void pressureLoad() {
  tft.drawPixel(33, 78, whiteScript);
  tft.drawLine(33, 86, 33, 88, whiteScript);
  tft.drawLine(33, 96, 33, 98, whiteScript);
  tft.drawLine(33, 106, 33, 108, whiteScript);
  tft.drawLine(33, 116, 33, 118, whiteScript);
  tft.drawLine(33, 126, 33, 128, whiteScript);
  tft.drawLine(33, 136, 33, 138, whiteScript);
  tft.drawLine(33, 146, 33, 148, whiteScript);
  tft.drawLine(33, 156, 33, 158, whiteScript);
  tft.drawLine(33, 166, 33, 168, whiteScript);
  tft.drawLine(33, 176, 33, 178, whiteScript);
  tft.drawLine(33, 186, 33, 188, whiteScript);
  tft.drawPixel(33, 196, whiteScript);

  tft.drawPixel(66, 78, whiteScript);
  tft.drawLine(66, 86, 66, 88, whiteScript);
  tft.drawLine(66, 96, 66, 98, whiteScript);
  tft.drawLine(66, 106, 66, 108, whiteScript);
  tft.drawLine(66, 116, 66, 118, whiteScript);
  tft.drawLine(66, 126, 66, 128, whiteScript);
  tft.drawLine(66, 136, 66, 138, whiteScript);
  tft.drawLine(66, 146, 66, 148, whiteScript);
  tft.drawLine(66, 156, 66, 158, whiteScript);
  tft.drawLine(66, 166, 66, 168, whiteScript);
  tft.drawLine(66, 176, 66, 178, whiteScript);
  tft.drawLine(66, 186, 66, 188, whiteScript);
  tft.drawPixel(66, 196, whiteScript);

  tft.drawPixel(99, 78, whiteScript);
  tft.drawLine(99, 86, 99, 88, whiteScript);
  tft.drawLine(99, 96, 99, 98, whiteScript);
  tft.drawLine(99, 106, 99, 108, whiteScript);
  tft.drawLine(99, 116, 99, 118, whiteScript);
  tft.drawLine(99, 126, 99, 128, whiteScript);
  tft.drawLine(99, 136, 99, 138, whiteScript);
  tft.drawLine(99, 146, 99, 148, whiteScript);
  tft.drawLine(99, 156, 99, 158, whiteScript);
  tft.drawLine(99, 166, 99, 168, whiteScript);
  tft.drawLine(99, 176, 99, 178, whiteScript);
  tft.drawLine(99, 186, 99, 188, whiteScript);
  tft.drawPixel(99, 196, whiteScript);

  tft.drawPixel(133, 78, whiteScript);
  tft.drawLine(133, 86, 133, 88, whiteScript);
  tft.drawLine(133, 96, 133, 98, whiteScript);
  tft.drawLine(133, 106, 133, 108, whiteScript);
  tft.drawLine(133, 116, 133, 118, whiteScript);
  tft.drawLine(133, 126, 133, 128, whiteScript);
  tft.drawLine(133, 136, 133, 138, whiteScript);
  tft.drawLine(133, 146, 133, 148, whiteScript);
  tft.drawLine(133, 156, 133, 158, whiteScript);
  tft.drawLine(133, 166, 133, 168, whiteScript);
  tft.drawLine(133, 176, 133, 178, whiteScript);
  tft.drawLine(133, 186, 133, 188, whiteScript);
  tft.drawPixel(133, 196, whiteScript);

  tft.drawPixel(166, 78, whiteScript);
  tft.drawLine(166, 86, 166, 88, whiteScript);
  tft.drawLine(166, 96, 166, 98, whiteScript);
  tft.drawLine(166, 106, 166, 108, whiteScript);
  tft.drawLine(166, 116, 166, 118, whiteScript);
  tft.drawLine(166, 126, 166, 128, whiteScript);
  tft.drawLine(166, 136, 166, 138, whiteScript);
  tft.drawLine(166, 146, 166, 148, whiteScript);
  tft.drawLine(166, 156, 166, 158, whiteScript);
  tft.drawLine(166, 166, 166, 168, whiteScript);
  tft.drawLine(166, 176, 166, 178, whiteScript);
  tft.drawLine(166, 186, 166, 188, whiteScript);
  tft.drawPixel(166, 196, whiteScript);

  tft.drawPixel(199, 78, whiteScript);
  tft.drawLine(199, 86, 199, 88, whiteScript);
  tft.drawLine(199, 96, 199, 98, whiteScript);
  tft.drawLine(199, 106, 199, 108, whiteScript);
  tft.drawLine(199, 116, 199, 118, whiteScript);
  tft.drawLine(199, 126, 199, 128, whiteScript);
  tft.drawLine(199, 136, 199, 138, whiteScript);
  tft.drawLine(199, 146, 199, 148, whiteScript);
  tft.drawLine(199, 156, 199, 158, whiteScript);
  tft.drawLine(199, 166, 199, 168, whiteScript);
  tft.drawLine(199, 176, 199, 178, whiteScript);
  tft.drawLine(199, 186, 199, 188, whiteScript);
  tft.drawPixel(199, 196, whiteScript);

  tft.drawPixel(233, 78, whiteScript);
  tft.drawLine(233, 86, 233, 88, whiteScript);
  tft.drawLine(233, 96, 233, 98, whiteScript);
  tft.drawLine(233, 106, 233, 108, whiteScript);
  tft.drawLine(233, 116, 233, 118, whiteScript);
  tft.drawLine(233, 126, 233, 128, whiteScript);
  tft.drawLine(233, 136, 233, 138, whiteScript);
  tft.drawLine(233, 146, 233, 148, whiteScript);
  tft.drawLine(233, 156, 233, 158, whiteScript);
  tft.drawLine(233, 166, 233, 168, whiteScript);
  tft.drawLine(233, 176, 233, 178, whiteScript);
  tft.drawLine(233, 186, 233, 188, whiteScript);
  tft.drawPixel(233, 196, whiteScript);

  tft.drawPixel(266, 78, whiteScript);
  tft.drawLine(266, 86, 266, 88, whiteScript);
  tft.drawLine(266, 96, 266, 98, whiteScript);
  tft.drawLine(266, 106, 266, 108, whiteScript);
  tft.drawLine(266, 116, 266, 118, whiteScript);
  tft.drawLine(266, 126, 266, 128, whiteScript);
  tft.drawLine(266, 136, 266, 138, whiteScript);
  tft.drawLine(266, 146, 266, 148, whiteScript);
  tft.drawLine(266, 156, 266, 158, whiteScript);
  tft.drawLine(266, 166, 266, 168, whiteScript);
  tft.drawLine(266, 176, 266, 178, whiteScript);
  tft.drawLine(266, 186, 266, 188, whiteScript);
  tft.drawPixel(266, 196, whiteScript);

  tft.drawPixel(299, 78, whiteScript);
  tft.drawLine(299, 86, 299, 88, whiteScript);
  tft.drawLine(299, 96, 299, 98, whiteScript);
  tft.drawLine(299, 106, 299, 108, whiteScript);
  tft.drawLine(299, 116, 299, 118, whiteScript);
  tft.drawLine(299, 126, 299, 128, whiteScript);
  tft.drawLine(299, 136, 299, 138, whiteScript);
  tft.drawLine(299, 146, 299, 148, whiteScript);
  tft.drawLine(299, 156, 299, 158, whiteScript);
  tft.drawLine(299, 166, 299, 168, whiteScript);
  tft.drawLine(299, 176, 299, 178, whiteScript);
  tft.drawLine(299, 186, 299, 188, whiteScript);
  tft.drawPixel(299, 196, whiteScript);

  tft.drawPixel(333, 78, whiteScript);
  tft.drawLine(333, 86, 333, 88, whiteScript);
  tft.drawLine(333, 96, 333, 98, whiteScript);
  tft.drawLine(333, 106, 333, 108, whiteScript);
  tft.drawLine(333, 116, 333, 118, whiteScript);
  tft.drawLine(333, 126, 333, 128, whiteScript);
  tft.drawLine(333, 136, 333, 138, whiteScript);
  tft.drawLine(333, 146, 333, 148, whiteScript);
  tft.drawLine(333, 156, 333, 158, whiteScript);
  tft.drawLine(333, 166, 333, 168, whiteScript);
  tft.drawLine(333, 176, 333, 178, whiteScript);
  tft.drawLine(333, 186, 333, 188, whiteScript);
  tft.drawPixel(333, 196, whiteScript);

  tft.drawPixel(367, 78, whiteScript);
  tft.drawLine(367, 86, 367, 88, whiteScript);
  tft.drawLine(367, 96, 367, 98, whiteScript);
  tft.drawLine(367, 106, 367, 108, whiteScript);
  tft.drawLine(367, 116, 367, 118, whiteScript);
  tft.drawLine(367, 126, 367, 128, whiteScript);
  tft.drawLine(367, 136, 367, 138, whiteScript);
  tft.drawLine(367, 146, 367, 148, whiteScript);
  tft.drawLine(367, 156, 367, 158, whiteScript);
  tft.drawLine(367, 166, 367, 168, whiteScript);
  tft.drawLine(367, 176, 367, 178, whiteScript);
  tft.drawLine(367, 186, 367, 188, whiteScript);
  tft.drawPixel(367, 196, whiteScript);

  tft.drawPixel(399, 78, whiteScript);
  tft.drawLine(399, 86, 399, 88, whiteScript);
  tft.drawLine(399, 96, 399, 98, whiteScript);
  tft.drawLine(399, 106, 399, 108, whiteScript);
  tft.drawLine(399, 116, 399, 118, whiteScript);
  tft.drawLine(399, 126, 399, 128, whiteScript);
  tft.drawLine(399, 136, 399, 138, whiteScript);
  tft.drawLine(399, 146, 399, 148, whiteScript);
  tft.drawLine(399, 156, 399, 158, whiteScript);
  tft.drawLine(399, 166, 399, 168, whiteScript);
  tft.drawLine(399, 176, 399, 178, whiteScript);
  tft.drawLine(399, 186, 399, 188, whiteScript);
  tft.drawPixel(399, 196, whiteScript);

  tft.drawPixel(433, 78, whiteScript);
  tft.drawLine(433, 86, 433, 88, whiteScript);
  tft.drawLine(433, 96, 433, 98, whiteScript);
  tft.drawLine(433, 106, 433, 108, whiteScript);
  tft.drawLine(433, 116, 433, 118, whiteScript);
  tft.drawLine(433, 126, 433, 128, whiteScript);
  tft.drawLine(433, 136, 433, 138, whiteScript);
  tft.drawLine(433, 146, 433, 148, whiteScript);
  tft.drawLine(433, 156, 433, 158, whiteScript);
  tft.drawLine(433, 166, 433, 168, whiteScript);
  tft.drawLine(433, 176, 433, 178, whiteScript);
  tft.drawLine(433, 186, 433, 188, whiteScript);
  tft.drawPixel(433, 196, whiteScript);

  tft.drawLine(32, 208, 32, 213, pressureColor1);
  tft.drawLine(33, 208, 33, 213, pressureColor1);

  tft.drawLine(132, 208, 132, 213, pressureColor1);
  tft.drawLine(133, 208, 133, 213, pressureColor1);

  tft.drawLine(232, 208, 232, 213, pressureColor1);
  tft.drawLine(233, 208, 233, 213, pressureColor1);

  tft.drawLine(332, 208, 332, 213, pressureColor1);
  tft.drawLine(333, 208, 333, 213, pressureColor1);

  tft.drawLine(432, 208, 432, 213, pressureColor1);
  tft.drawLine(433, 208, 433, 213, pressureColor1);

  tft.drawLine(80, 208, 80, 212, middleTimeGraph);
  tft.drawLine(181, 208, 181, 212, middleTimeGraph);
  tft.drawLine(282, 208, 282, 212, middleTimeGraph);
  tft.drawLine(382, 208, 382, 212, middleTimeGraph);

  tft.setTextDatum(ML_DATUM);
  tft.setTextColor(whiteScript);
  tft.setFreeFont(latoRegular24);

  tft.drawString("0", 26, 228, GFXFF);
  tft.drawString("6", 125, 228, GFXFF);
  tft.drawString("12", 220, 228, GFXFF);
  tft.drawString("18", 318, 228, GFXFF);
  tft.drawString("24", 418, 228, GFXFF);

  tft.setFreeFont(latoRegular14);

  tft.drawString("3", 76, 225, GFXFF);
  tft.drawString("9", 178, 225, GFXFF);
  tft.drawString("15", 274, 225, GFXFF);
  tft.drawString("21", 374, 225, GFXFF);
}

void humidityLoad() {
  tft.drawPixel(33, 78, whiteScript);
  tft.drawLine(33, 86, 33, 88, whiteScript);
  tft.drawLine(33, 96, 33, 98, whiteScript);
  tft.drawLine(33, 106, 33, 108, whiteScript);
  tft.drawLine(33, 116, 33, 118, whiteScript);
  tft.drawLine(33, 126, 33, 128, whiteScript);
  tft.drawLine(33, 136, 33, 138, whiteScript);
  tft.drawLine(33, 146, 33, 148, whiteScript);
  tft.drawLine(33, 156, 33, 158, whiteScript);
  tft.drawLine(33, 166, 33, 168, whiteScript);
  tft.drawLine(33, 176, 33, 178, whiteScript);
  tft.drawLine(33, 186, 33, 188, whiteScript);
  tft.drawPixel(33, 196, whiteScript);

  tft.drawPixel(66, 78, whiteScript);
  tft.drawLine(66, 86, 66, 88, whiteScript);
  tft.drawLine(66, 96, 66, 98, whiteScript);
  tft.drawLine(66, 106, 66, 108, whiteScript);
  tft.drawLine(66, 116, 66, 118, whiteScript);
  tft.drawLine(66, 126, 66, 128, whiteScript);
  tft.drawLine(66, 136, 66, 138, whiteScript);
  tft.drawLine(66, 146, 66, 148, whiteScript);
  tft.drawLine(66, 156, 66, 158, whiteScript);
  tft.drawLine(66, 166, 66, 168, whiteScript);
  tft.drawLine(66, 176, 66, 178, whiteScript);
  tft.drawLine(66, 186, 66, 188, whiteScript);
  tft.drawPixel(66, 196, whiteScript);

  tft.drawPixel(99, 78, whiteScript);
  tft.drawLine(99, 86, 99, 88, whiteScript);
  tft.drawLine(99, 96, 99, 98, whiteScript);
  tft.drawLine(99, 106, 99, 108, whiteScript);
  tft.drawLine(99, 116, 99, 118, whiteScript);
  tft.drawLine(99, 126, 99, 128, whiteScript);
  tft.drawLine(99, 136, 99, 138, whiteScript);
  tft.drawLine(99, 146, 99, 148, whiteScript);
  tft.drawLine(99, 156, 99, 158, whiteScript);
  tft.drawLine(99, 166, 99, 168, whiteScript);
  tft.drawLine(99, 176, 99, 178, whiteScript);
  tft.drawLine(99, 186, 99, 188, whiteScript);
  tft.drawPixel(99, 196, whiteScript);

  tft.drawPixel(133, 78, whiteScript);
  tft.drawLine(133, 86, 133, 88, whiteScript);
  tft.drawLine(133, 96, 133, 98, whiteScript);
  tft.drawLine(133, 106, 133, 108, whiteScript);
  tft.drawLine(133, 116, 133, 118, whiteScript);
  tft.drawLine(133, 126, 133, 128, whiteScript);
  tft.drawLine(133, 136, 133, 138, whiteScript);
  tft.drawLine(133, 146, 133, 148, whiteScript);
  tft.drawLine(133, 156, 133, 158, whiteScript);
  tft.drawLine(133, 166, 133, 168, whiteScript);
  tft.drawLine(133, 176, 133, 178, whiteScript);
  tft.drawLine(133, 186, 133, 188, whiteScript);
  tft.drawPixel(133, 196, whiteScript);

  tft.drawPixel(166, 78, whiteScript);
  tft.drawLine(166, 86, 166, 88, whiteScript);
  tft.drawLine(166, 96, 166, 98, whiteScript);
  tft.drawLine(166, 106, 166, 108, whiteScript);
  tft.drawLine(166, 116, 166, 118, whiteScript);
  tft.drawLine(166, 126, 166, 128, whiteScript);
  tft.drawLine(166, 136, 166, 138, whiteScript);
  tft.drawLine(166, 146, 166, 148, whiteScript);
  tft.drawLine(166, 156, 166, 158, whiteScript);
  tft.drawLine(166, 166, 166, 168, whiteScript);
  tft.drawLine(166, 176, 166, 178, whiteScript);
  tft.drawLine(166, 186, 166, 188, whiteScript);
  tft.drawPixel(166, 196, whiteScript);

  tft.drawPixel(199, 78, whiteScript);
  tft.drawLine(199, 86, 199, 88, whiteScript);
  tft.drawLine(199, 96, 199, 98, whiteScript);
  tft.drawLine(199, 106, 199, 108, whiteScript);
  tft.drawLine(199, 116, 199, 118, whiteScript);
  tft.drawLine(199, 126, 199, 128, whiteScript);
  tft.drawLine(199, 136, 199, 138, whiteScript);
  tft.drawLine(199, 146, 199, 148, whiteScript);
  tft.drawLine(199, 156, 199, 158, whiteScript);
  tft.drawLine(199, 166, 199, 168, whiteScript);
  tft.drawLine(199, 176, 199, 178, whiteScript);
  tft.drawLine(199, 186, 199, 188, whiteScript);
  tft.drawPixel(199, 196, whiteScript);

  tft.drawPixel(233, 78, whiteScript);
  tft.drawLine(233, 86, 233, 88, whiteScript);
  tft.drawLine(233, 96, 233, 98, whiteScript);
  tft.drawLine(233, 106, 233, 108, whiteScript);
  tft.drawLine(233, 116, 233, 118, whiteScript);
  tft.drawLine(233, 126, 233, 128, whiteScript);
  tft.drawLine(233, 136, 233, 138, whiteScript);
  tft.drawLine(233, 146, 233, 148, whiteScript);
  tft.drawLine(233, 156, 233, 158, whiteScript);
  tft.drawLine(233, 166, 233, 168, whiteScript);
  tft.drawLine(233, 176, 233, 178, whiteScript);
  tft.drawLine(233, 186, 233, 188, whiteScript);
  tft.drawPixel(233, 196, whiteScript);

  tft.drawPixel(266, 78, whiteScript);
  tft.drawLine(266, 86, 266, 88, whiteScript);
  tft.drawLine(266, 96, 266, 98, whiteScript);
  tft.drawLine(266, 106, 266, 108, whiteScript);
  tft.drawLine(266, 116, 266, 118, whiteScript);
  tft.drawLine(266, 126, 266, 128, whiteScript);
  tft.drawLine(266, 136, 266, 138, whiteScript);
  tft.drawLine(266, 146, 266, 148, whiteScript);
  tft.drawLine(266, 156, 266, 158, whiteScript);
  tft.drawLine(266, 166, 266, 168, whiteScript);
  tft.drawLine(266, 176, 266, 178, whiteScript);
  tft.drawLine(266, 186, 266, 188, whiteScript);
  tft.drawPixel(266, 196, whiteScript);

  tft.drawPixel(299, 78, whiteScript);
  tft.drawLine(299, 86, 299, 88, whiteScript);
  tft.drawLine(299, 96, 299, 98, whiteScript);
  tft.drawLine(299, 106, 299, 108, whiteScript);
  tft.drawLine(299, 116, 299, 118, whiteScript);
  tft.drawLine(299, 126, 299, 128, whiteScript);
  tft.drawLine(299, 136, 299, 138, whiteScript);
  tft.drawLine(299, 146, 299, 148, whiteScript);
  tft.drawLine(299, 156, 299, 158, whiteScript);
  tft.drawLine(299, 166, 299, 168, whiteScript);
  tft.drawLine(299, 176, 299, 178, whiteScript);
  tft.drawLine(299, 186, 299, 188, whiteScript);
  tft.drawPixel(299, 196, whiteScript);

  tft.drawPixel(333, 78, whiteScript);
  tft.drawLine(333, 86, 333, 88, whiteScript);
  tft.drawLine(333, 96, 333, 98, whiteScript);
  tft.drawLine(333, 106, 333, 108, whiteScript);
  tft.drawLine(333, 116, 333, 118, whiteScript);
  tft.drawLine(333, 126, 333, 128, whiteScript);
  tft.drawLine(333, 136, 333, 138, whiteScript);
  tft.drawLine(333, 146, 333, 148, whiteScript);
  tft.drawLine(333, 156, 333, 158, whiteScript);
  tft.drawLine(333, 166, 333, 168, whiteScript);
  tft.drawLine(333, 176, 333, 178, whiteScript);
  tft.drawLine(333, 186, 333, 188, whiteScript);
  tft.drawPixel(333, 196, whiteScript);

  tft.drawPixel(367, 78, whiteScript);
  tft.drawLine(367, 86, 367, 88, whiteScript);
  tft.drawLine(367, 96, 367, 98, whiteScript);
  tft.drawLine(367, 106, 367, 108, whiteScript);
  tft.drawLine(367, 116, 367, 118, whiteScript);
  tft.drawLine(367, 126, 367, 128, whiteScript);
  tft.drawLine(367, 136, 367, 138, whiteScript);
  tft.drawLine(367, 146, 367, 148, whiteScript);
  tft.drawLine(367, 156, 367, 158, whiteScript);
  tft.drawLine(367, 166, 367, 168, whiteScript);
  tft.drawLine(367, 176, 367, 178, whiteScript);
  tft.drawLine(367, 186, 367, 188, whiteScript);
  tft.drawPixel(367, 196, whiteScript);

  tft.drawPixel(399, 78, whiteScript);
  tft.drawLine(399, 86, 399, 88, whiteScript);
  tft.drawLine(399, 96, 399, 98, whiteScript);
  tft.drawLine(399, 106, 399, 108, whiteScript);
  tft.drawLine(399, 116, 399, 118, whiteScript);
  tft.drawLine(399, 126, 399, 128, whiteScript);
  tft.drawLine(399, 136, 399, 138, whiteScript);
  tft.drawLine(399, 146, 399, 148, whiteScript);
  tft.drawLine(399, 156, 399, 158, whiteScript);
  tft.drawLine(399, 166, 399, 168, whiteScript);
  tft.drawLine(399, 176, 399, 178, whiteScript);
  tft.drawLine(399, 186, 399, 188, whiteScript);
  tft.drawPixel(399, 196, whiteScript);

  tft.drawPixel(433, 78, whiteScript);
  tft.drawLine(433, 86, 433, 88, whiteScript);
  tft.drawLine(433, 96, 433, 98, whiteScript);
  tft.drawLine(433, 106, 433, 108, whiteScript);
  tft.drawLine(433, 116, 433, 118, whiteScript);
  tft.drawLine(433, 126, 433, 128, whiteScript);
  tft.drawLine(433, 136, 433, 138, whiteScript);
  tft.drawLine(433, 146, 433, 148, whiteScript);
  tft.drawLine(433, 156, 433, 158, whiteScript);
  tft.drawLine(433, 166, 433, 168, whiteScript);
  tft.drawLine(433, 176, 433, 178, whiteScript);
  tft.drawLine(433, 186, 433, 188, whiteScript);
  tft.drawPixel(433, 196, whiteScript);

  tft.drawLine(32, 208, 32, 213, humidityColor1);
  tft.drawLine(33, 208, 33, 213, humidityColor1);

  tft.drawLine(132, 208, 132, 213, humidityColor1);
  tft.drawLine(133, 208, 133, 213, humidityColor1);

  tft.drawLine(232, 208, 232, 213, humidityColor1);
  tft.drawLine(233, 208, 233, 213, humidityColor1);

  tft.drawLine(332, 208, 332, 213, humidityColor1);
  tft.drawLine(333, 208, 333, 213, humidityColor1);

  tft.drawLine(432, 208, 432, 213, humidityColor1);
  tft.drawLine(433, 208, 433, 213, humidityColor1);

  tft.drawLine(80, 208, 80, 212, middleTimeGraph);
  tft.drawLine(181, 208, 181, 212, middleTimeGraph);
  tft.drawLine(282, 208, 282, 212, middleTimeGraph);
  tft.drawLine(382, 208, 382, 212, middleTimeGraph);

  tft.setTextDatum(ML_DATUM);
  tft.setTextColor(whiteScript);
  tft.setFreeFont(latoRegular24);

  tft.drawString("0", 26, 228, GFXFF);
  tft.drawString("6", 125, 228, GFXFF);
  tft.drawString("12", 220, 228, GFXFF);
  tft.drawString("18", 318, 228, GFXFF);
  tft.drawString("24", 418, 228, GFXFF);

  tft.setFreeFont(latoRegular14);

  tft.drawString("3", 76, 225, GFXFF);
  tft.drawString("9", 178, 225, GFXFF);
  tft.drawString("15", 274, 225, GFXFF);
  tft.drawString("21", 374, 225, GFXFF);
}

void calendar() {
  switch (month) {
    case 1:
      tft.setTextDatum(MC_DATUM);
      tft.setTextColor(whiteScript);
      tft.setFreeFont(latoRegular14);

      tft.fillRect(10, 75, 350, 185, januaryColor);
      tft.fillRoundRect(10, 267, 100, 30, 5, decemberColor);
      tft.fillRoundRect(115, 267, 140, 30, 5, januaryColor);
      tft.fillRoundRect(260, 267, 100, 30, 5, februeryColor);
      tft.drawString("DECEMBER", 60, 280, GFXFF);
      tft.drawString("JANUARY", 187, 280, GFXFF);
      tft.drawString("FEBRUERY", 310, 280, GFXFF);
    break;
    case 2:
      tft.setTextDatum(MC_DATUM);
      tft.setTextColor(whiteScript);
      tft.setFreeFont(latoRegular14);

      tft.fillRect(10, 75, 350, 185, februeryColor);
      tft.fillRoundRect(10, 267, 100, 30, 5, januaryColor);
      tft.fillRoundRect(115, 267, 140, 30, 5, februeryColor);
      tft.fillRoundRect(260, 267, 100, 30, 5, marchColor);
      tft.drawString("JANUARY", 60, 280, GFXFF);
      tft.drawString("FEBRUERY", 187, 280, GFXFF);
      tft.drawString("MARCH", 310, 280, GFXFF);
    break;
    case 3:
      tft.setTextDatum(MC_DATUM);
      tft.setTextColor(whiteScript);
      tft.setFreeFont(latoRegular14);

      tft.fillRect(10, 75, 350, 185, marchColor);
      tft.fillRoundRect(10, 267, 100, 30, 5, februeryColor);
      tft.fillRoundRect(115, 267, 140, 30, 5, marchColor);
      tft.fillRoundRect(260, 267, 100, 30, 5, aprilColor);
      tft.drawString("FEBRUERY", 60, 280, GFXFF);
      tft.drawString("MARCH", 187, 280, GFXFF);
      tft.drawString("APRIL", 310, 280, GFXFF);
    break;
    case 4:
      tft.setTextDatum(MC_DATUM);
      tft.setTextColor(whiteScript);
      tft.setFreeFont(latoRegular14);

      tft.fillRect(10, 75, 350, 185, aprilColor);
      tft.fillRoundRect(10, 267, 100, 30, 5, marchColor);
      tft.fillRoundRect(115, 267, 140, 30, 5, aprilColor);
      tft.fillRoundRect(260, 267, 100, 30, 5, mayColor);
      tft.drawString("MARCH", 60, 280, GFXFF);
      tft.drawString("APRIL", 187, 280, GFXFF);
      tft.drawString("MAY", 310, 280, GFXFF);
    break;
    case 5:
      tft.setTextDatum(MC_DATUM);
      tft.setTextColor(whiteScript);
      tft.setFreeFont(latoRegular14);

      tft.fillRect(10, 75, 350, 185, mayColor);
      tft.fillRoundRect(10, 267, 100, 30, 5, aprilColor);
      tft.fillRoundRect(115, 267, 140, 30, 5, mayColor);
      tft.fillRoundRect(260, 267, 100, 30, 5, juneColor);
      tft.drawString("APRIL", 60, 280, GFXFF);
      tft.drawString("MAY", 187, 280, GFXFF);
      tft.drawString("JUNE", 310, 280, GFXFF);
    break;
    case 6:
      tft.setTextDatum(MC_DATUM);
      tft.setTextColor(whiteScript);
      tft.setFreeFont(latoRegular14);

      tft.fillRect(10, 75, 350, 185, juneColor);
      tft.fillRoundRect(10, 267, 100, 30, 5, mayColor);
      tft.fillRoundRect(115, 267, 140, 30, 5, juneColor);
      tft.fillRoundRect(260, 267, 100, 30, 5, julyColor);
      tft.drawString("MAY", 60, 280, GFXFF);
      tft.drawString("JUNE", 187, 280, GFXFF);
      tft.drawString("JULY", 310, 280, GFXFF);
    break;
    case 7:
      tft.setTextDatum(MC_DATUM);
      tft.setTextColor(whiteScript);
      tft.setFreeFont(latoRegular14);

      tft.fillRect(10, 75, 350, 185, julyColor);
      tft.fillRoundRect(10, 267, 100, 30, 5, juneColor);
      tft.fillRoundRect(115, 267, 140, 30, 5, julyColor);
      tft.fillRoundRect(260, 267, 100, 30, 5, augustColor);
      tft.drawString("JUNE", 60, 280, GFXFF);
      tft.drawString("JULY", 187, 280, GFXFF);
      tft.drawString("AUGUST", 310, 280, GFXFF);
    break;
    case 8:
      tft.setTextDatum(MC_DATUM);
      tft.setTextColor(whiteScript);
      tft.setFreeFont(latoRegular14);

      tft.fillRect(10, 75, 350, 185, augustColor);
      tft.fillRoundRect(10, 267, 100, 30, 5, julyColor);
      tft.fillRoundRect(115, 267, 140, 30, 5, augustColor);
      tft.fillRoundRect(260, 267, 100, 30, 5, septemberColor);
      tft.drawString("JULY", 60, 280, GFXFF);
      tft.drawString("AUGUST", 187, 280, GFXFF);
      tft.drawString("SEPTEMBER", 310, 280, GFXFF);
    break;
    case 9:
      tft.setTextDatum(MC_DATUM);
      tft.setTextColor(whiteScript);
      tft.setFreeFont(latoRegular14);

      tft.fillRect(10, 75, 350, 185, septemberColor);
      tft.fillRoundRect(10, 267, 100, 30, 5, augustColor);
      tft.fillRoundRect(115, 267, 140, 30, 5, septemberColor);
      tft.fillRoundRect(260, 267, 100, 30, 5, octoberColor);
      tft.drawString("AUGUST", 60, 280, GFXFF);
      tft.drawString("SEPTEMBER", 187, 280, GFXFF);
      tft.drawString("OCTOBER", 310, 280, GFXFF);
    break;
    case 10:
      tft.setTextDatum(MC_DATUM);
      tft.setTextColor(whiteScript);
      tft.setFreeFont(latoRegular14);

      tft.fillRect(10, 75, 350, 185, octoberColor);
      tft.fillRoundRect(10, 267, 100, 30, 5, septemberColor);
      tft.fillRoundRect(115, 267, 140, 30, 5, octoberColor);
      tft.fillRoundRect(260, 267, 100, 30, 5, novemberColor);
      tft.drawString("SEPTEMBER", 60, 280, GFXFF);
      tft.drawString("OCTOBER", 187, 280, GFXFF);
      tft.drawString("NOVEMBER", 310, 280, GFXFF);
    break;
    case 11:
      tft.setTextDatum(MC_DATUM);
      tft.setTextColor(whiteScript);
      tft.setFreeFont(latoRegular14);

      tft.fillRect(10, 75, 350, 185, novemberColor);
      tft.fillRoundRect(10, 267, 100, 30, 5, octoberColor);
      tft.fillRoundRect(115, 267, 140, 30, 5, novemberColor);
      tft.fillRoundRect(260, 267, 100, 30, 5, decemberColor);
      tft.drawString("OCTOBER", 60, 280, GFXFF);
      tft.drawString("NOVEMBER", 187, 280, GFXFF);
      tft.drawString("DECEMBER", 310, 280, GFXFF);
    break;
    case 12:
      tft.setTextDatum(MC_DATUM);
      tft.setTextColor(whiteScript);
      tft.setFreeFont(latoRegular14);

      tft.fillRect(10, 75, 350, 185, decemberColor);
      tft.fillRoundRect(10, 267, 100, 30, 5, novemberColor);
      tft.fillRoundRect(115, 267, 140, 30, 5, decemberColor);
      tft.fillRoundRect(260, 267, 100, 30, 5, januaryColor);
      tft.drawString("NOVEMBER", 60, 280, GFXFF);
      tft.drawString("DECEMBER", 187, 280, GFXFF);
      tft.drawString("JANUARY", 310, 280, GFXFF);
    break;
    default:
      tft.setTextDatum(MC_DATUM);
      tft.setTextColor(whiteScript);
      tft.setFreeFont(latoRegular14);

      tft.drawRoundRect(10, 75, 350, 185, 5, whiteScript);
      tft.fillRoundRect(10, 267, 100, 30, 5, whiteScript);
      tft.fillRoundRect(115, 267, 140, 30, 5, whiteScript);
      tft.fillRoundRect(260, 267, 100, 30, 5, whiteScript);
      tft.drawString("UNKNOWN", 60, 280, GFXFF);
      tft.drawString("UNKNOWN", 187, 280, GFXFF);
      tft.drawString("UNKNOWN", 310, 280, GFXFF);
  }
}

void date() {
  String stringDay = String(day);
  String stringMonth = String(month);
  String stringYear = String(year);

  tft.setTextDatum(MC_DATUM);
  tft.setTextColor(blackScript);
  tft.setFreeFont(latoRegular14);

  tft.drawString("S", 154, 92, GFXFF);
  tft.drawString("M", 182, 92, GFXFF);
  tft.drawString("T", 215, 92, GFXFF);
  tft.drawString("W", 241, 92, GFXFF);
  tft.drawString("T", 275, 92, GFXFF);
  tft.drawString("F", 304, 92, GFXFF);
  tft.drawString("S", 332, 92, GFXFF);

  tft.setTextColor(whiteScript);
  tft.setFreeFont(latoRegular24);

  tft.drawString(stringYear, 55, 236, GFXFF);

  tft.setFreeFont(latoBold48);

  if (day < 10) {
    tft.drawString("0", 40, 105, GFXFF);
    tft.drawString(stringDay, 70, 105, GFXFF);
  } else {
    tft.drawString(stringDay, 40, 105, GFXFF);
  }

  if (month < 10) {
    tft.drawString("0", 40, 175, GFXFF);
    tft.drawString(stringMonth, 70, 175, GFXFF);
  } else {
    tft.drawString(stringMonth, 40, 175, GFXFF);
  }

  tft.setTextDatum(TL_DATUM);
  tft.setTextColor(whiteScript);
  tft.setFreeFont(latoRegular14);
  tft.drawString("SEMANA", 365, 86, GFXFF);
  tft.drawString("DIA", 402, 105, GFXFF);
}

void seasons() {
  if (day >= 20 && month > 2) {
    if (day <21 && month < 7) {
      tft.pushImage(377, 154, 75, 92, spring);
    } 
  } else if (day >= 21 && month > 5) {
    if (day <23 && month < 9) {
      tft.pushImage(377, 154, 75, 92, summer);
    }
  } else if (day >= 23 && month > 8) {
    if (day <22 && month < 11) {
      tft.pushImage(377, 154, 75, 92, autumn);
    }
  } else if (day >= 22 && month > 11) {
    if (day < 20 && month < 4) {
      tft.pushImage(377, 154, 75, 92, winter);
    }
  }
}

void nixie() {
  tft.drawRect(30, 118, 10, 10, whiteScript);
  tft.drawRect(30, 146, 10, 10, whiteScript);
  tft.pushImage(272, 84, 36, 90, nixieBulb);
  tft.pushImage(309, 84, 36, 90, nixieBulb);
  tft.pushImage(348, 84, 36, 90, nixieBulb);
  tft.pushImage(385, 84, 36, 90, nixieBulb);
  tft.fillCircle(338, 158, 4, nixieColor);
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

  tft.drawString("2000", 100, 104, GFXFF);
  tft.drawString("1000", 100, 124, GFXFF);
  tft.drawString("500", 110, 144, GFXFF);
  tft.drawString("100", 110, 164, GFXFF);

  tft.drawString("aCPM/h", 105, 195, GFXFF); 

  tft.drawString("CPM:", 242, 234, GFXFF);
  tft.drawString("Average:", 242, 251, GFXFF);
  tft.drawString("uSh", 242, 268, GFXFF);
  tft.drawString("mCPM", 242, 286, GFXFF);

  tft.setFreeFont(latoRegular24);
  tft.drawString("Sieverts", 242, 205, GFXFF);

  tft.fillRect(40, 85, 23, 29, geigerLevel3);
  tft.fillRect(40, 114, 23, 86, geigerLevel2);
  tft.fillRect(40, 200, 23, 73, geigerLevel1);

  tft.fillTriangle(68, 272, 85, 262, 85, 282, geigerLevel);

  geigerLoad();
  geigerAlarm();
  home();
  superiorMenu();
  wifiLevel();
  batteryLevel();
  lockLevel();
}

void telaMenu2() {
  tft.fillScreen(blackScript);
  i = 1;

  tft.setTextDatum(ML_DATUM);
  tft.setTextColor(whiteScript);
  tft.setFreeFont(latoRegular14);

  tft.fillRectHGradient(35, 113, 323, 23, geigerColor1, geigerColor2);
  tft.fillTriangle(34, 140, 24, 157, 44, 157, geigerLevel);

  tft.drawString("Counts per second", 176, 166, GFXFF);

  tft.drawString("CPM:", 132, 234, GFXFF);
  tft.drawString("Average:", 132, 251, GFXFF);
  tft.drawString("uSh", 132, 268, GFXFF);
  tft.drawString("mCPM", 132, 286, GFXFF);

  tft.setFreeFont(latoRegular24);
  tft.drawString("Sieverts", 132, 205, GFXFF);

  dosimeter();
  dosimeterAlarm();
  home();
  superiorMenu();
  wifiLevel();
  batteryLevel();
  lockLevel();
}

void telaMenu3() {
  tft.fillScreen(blackScript);
  i = 1;

  tft.setTextDatum(ML_DATUM);
  tft.setTextColor(geigerColor1);
  tft.setFreeFont(latoRegular14);
  tft.drawString("Now:", 187, 250, GFXFF);

  tft.fillRectHGradient(15, 267, 100, 30, geigerColor1, geigerColor2);

  dosimeterLoad();
  home();
  superiorMenu();
  wifiLevel();
  batteryLevel();
  lockLevel();
}

void telaMenu4() {
  tft.fillScreen(blackScript);
  i = 1;
  
  tft.pushImage(377, 154, 80, 92, spring);
  seasons();
  calendar();
  date();
  home();
  superiorMenu();
  wifiLevel();
  batteryLevel();
  lockLevel();
}

void telaMenu5() {
  tft.fillScreen(blackScript);
}

void telaMenu6() {
  tft.fillScreen(blackScript);
  i = 1;

  tft.fillRectHGradient(15, 267, 100, 30, temperatureColor1, temperatureColor2);
  tft.setTextDatum(ML_DATUM);
  tft.setTextColor(whiteScript);
  tft.setFreeFont(latoRegular14);
  tft.drawString("Min:", 165, 265, GFXFF);
  tft.drawString("Max:", 165, 285, GFXFF);


  temperatureLoad();
  home();
  superiorMenu();
  wifiLevel();
  batteryLevel();
  lockLevel();
}

void telaMenu7() {
  tft.fillScreen(blackScript);
  i = 1;

  tft.fillRectHGradient(15, 267, 100, 30, pressureColor1, pressureColor2);
  tft.setTextDatum(ML_DATUM);
  tft.setTextColor(whiteScript);
  tft.setFreeFont(latoRegular14);
  tft.drawString("Min:", 165, 265, GFXFF);
  tft.drawString("Max:", 165, 285, GFXFF);


  pressureLoad();
  home();
  superiorMenu();
  wifiLevel();
  batteryLevel();
  lockLevel();
}

void telaMenu8() {
  tft.fillScreen(blackScript);
  i = 1;

  tft.fillRectHGradient(15, 267, 100, 30, humidityColor1, humidityColor2);
  tft.setTextDatum(ML_DATUM);
  tft.setTextColor(whiteScript);
  tft.setFreeFont(latoRegular14);
  tft.drawString("Min:", 165, 265, GFXFF);
  tft.drawString("Max:", 165, 285, GFXFF);


  humidityLoad();
  home();
  superiorMenu();
  wifiLevel();
  batteryLevel();
  lockLevel();
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
  i = 1;

  tft.fillRectHGradient(15, 267, 100, 30, pressureColor1, pressureColor2);
  tft.fillRectHGradient(125, 267, 100, 30, temperatureColor1, temperatureColor2);
  tft.fillRectHGradient(235, 267, 100, 30, humidityColor1, humidityColor2);
  tft.setTextDatum(ML_DATUM);
  tft.setTextColor(whiteScript);
  tft.setFreeFont(latoRegular14);
  tft.drawString("METRO", 48, 121, GFXFF); 
  tft.drawString("CASCADE", 48, 149, GFXFF);
  tft.drawString("CONTADOR", 30, 221, GFXFF);
  tft.drawString("OSCILACAO", 250, 221, GFXFF);

  tft.setFreeFont(latoRegular24);
  tft.drawString("ANIMACAO NIXIE", 31, 90, GFXFF);
  tft.drawString("ATUALIZAO", 31, 180, GFXFF);

  nixie();

  tft.setTextDatum(ML_DATUM);
  tft.setTextColor(nixieColor);
  tft.setFreeFont(latoBold48);
  tft.drawString("0", 276, 130, GFXFF);
  tft.drawString("9", 314, 130, GFXFF);
  tft.drawString("5", 352, 130, GFXFF);
  tft.drawString("2", 389, 130, GFXFF);

  home();
  superiorMenu();
  wifiLevel();
  batteryLevel();
  lockLevel();
}

void telaMenu14() {
  tft.fillScreen(blackScript);
  i = 1;

  tft.fillRectHGradient(25, 105, 100, 30, pressureColor1, pressureColor2);
  tft.fillRectHGradient(25, 154, 120, 30, temperatureColor1, temperatureColor2);
  tft.fillRectHGradient(25, 202, 100, 30, humidityColor1, humidityColor2);

  tft.setTextDatum(ML_DATUM);
  tft.setTextColor(whiteScript);
  tft.setFreeFont(latoRegular14);
  tft.drawString("CONECTADO EM", 31, 75, GFXFF); 
  tft.drawString("NTP", 31, 253, GFXFF); 
  tft.drawString("CLIMA", 31, 273, GFXFF);
  tft.setTextDatum(MR_DATUM);
  tft.drawString("WEB", 390, 253, GFXFF); 
  tft.drawString("LOCAL", 390, 273, GFXFF); 

  tft.drawRoundRect(186, 104, 250, 30, 15, whiteScript);
  tft.drawRoundRect(187, 105, 248, 28, 14, whiteScript);
  tft.drawRoundRect(186, 152, 215, 30, 15, whiteScript);
  tft.drawRoundRect(187, 153, 213, 28, 14, whiteScript);
  tft.drawCircle(421, 167, 15, whiteScript);
  tft.drawCircle(421, 167, 14, whiteScript);

  home();
  superiorMenu();
  wifiLevel();
  batteryLevel();
  lockLevel();
}
void telaMenu15() {
  tft.fillScreen(blackScript);
  i = 1;

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
  tft.setTextColor(whiteScript);
  tft.setFreeFont(latoRegular10);

  compareMins = mins;

  tft.fillRect(33, 107, 22, 22, profileColor);

  if ((day > 1) && (day < 10)) {
    tft.drawString("0", 61, 116, GFXFF);
    tft.drawString(stringDay, 67, 116, GFXFF);
  } else {
    tft.drawString(stringDay, 61, 116, GFXFF);
  }

  if ((month > 1) && (month < 10)) {
    tft.drawString("0", 77, 116, GFXFF);
    tft.drawString(stringMonth, 83, 116, GFXFF);
  } else {
    tft.drawString(stringMonth, 61, 116, GFXFF);
  }

  tft.drawString(stringYear, 91, 116, GFXFF);

  if ((hours > 1) && (hours < 10)) {
    tft.drawString("0", 120, 116, GFXFF);
    tft.drawString(stringHour, 126, 116, GFXFF);
  } else {
    tft.drawString(stringHour, 120, 116, GFXFF);
  }

  if ((mins > 1) && (mins < 10)) {
    tft.drawString("0", 135, 116, GFXFF);
    tft.drawString(stringMin, 143, 116, GFXFF);
  } else {
    tft.drawString(stringMin, 135, 116, GFXFF);
  }

  tft.setFreeFont(latoRegular24);
  tft.drawString("TEMA", 31, 90, GFXFF);

  tft.pushImage(155, 110, 9, 11, minilock);
  tft.pushImage(168, 111, 11, 10, miniwifi);
  tft.drawRoundRect(184, 112, 22, 8, 2, whiteScript);
  tft.fillRoundRect(185, 113, 20, 6, 2, blue_battery);
  tft.pushImage(214, 108, 17, 17, miniclimate);

  tft.fillRectHGradient(30, 249, 100, 30, pressureColor1, pressureColor2);
  tft.fillRectHGradient(135, 249, 100, 30, temperatureColor1, temperatureColor2);

  tft.drawRect(30, 104, 205, 137, menuSelection);


  tft.fillRoundRect(45, 132, 32, 32, 5, icon_1);
  tft.fillRoundRect(81, 132, 32, 32, 5, icon_2);
  tft.fillRoundRect(117, 132, 32, 32, 5, icon_3);
  tft.fillRoundRect(152, 132, 32, 32, 5, icon_4);
  tft.fillRoundRect(187, 132, 32, 32, 5, icon_5);

  tft.fillRoundRect(45, 168, 32, 32, 5, icon_6);
  tft.fillRoundRect(81, 168, 32, 32, 5, icon_7);
  tft.fillRoundRect(117, 168, 32, 32, 5, icon_8);
  tft.fillRoundRect(152, 168, 32, 32, 5, icon_9);
  tft.fillRoundRect(187, 168, 32, 32, 5, icon_10);

  tft.fillRoundRect(45, 204, 32, 32, 5, icon_11);
  tft.fillRoundRect(81, 204, 32, 32, 5, icon_12);
  tft.fillRoundRect(117, 204, 32, 32, 5, icon_13);
  tft.fillRoundRect(152, 204, 32, 32, 5, icon_14);
  tft.fillRoundRect(187, 204, 32, 32, 5, icon_15);

  tft.fillRoundRect(399, 108, 22, 22, 5, icon_5);
  tft.fillRect(399, 144, 22, 22, icon_5);

  tft.pushImage(440, 106, 19, 23, lock);
  tft.pushImage(442, 143, 16, 24, touch1);
  tft.pushImage(440, 184, 21, 17, touch2);

  tft.drawRoundRect(290, 109, 50, 20, 5, whiteScript);
  tft.drawRoundRect(291, 110, 48, 18, 4, whiteScript);
  tft.fillRoundRect(292, 111, 46, 16, 4, blue_battery);

  tft.drawRoundRect(290, 144, 50, 20, 5, blue_battery);
  tft.drawRoundRect(291, 145, 48, 18, 4, blue_battery);

  tft.fillRoundRect(290, 180, 50, 20, 5, blue_battery);

  tft.pushImage(361, 110, 17, 17, miniclimate);

  tft.drawRect(244, 104, 31, 31, icon_5);
  tft.fillTriangle(273, 105, 273, 133, 245, 133, icon_5);

  tft.fillRect(244, 140, 31, 31, whiteScript);
  tft.fillTriangle(273, 141, 273, 169, 245, 169, icon_5);

  tft.fillRect(244, 176, 31, 31, icon_black);
  tft.fillTriangle(273, 177, 273, 205, 245, 205, blackScript);

  tft.fillRect(244, 211, 31, 31, icon_white);
  tft.fillTriangle(273, 212, 245, 212, 245, 240, blackScript);

  home();
  superiorMenu();
  wifiLevel();
  batteryLevel();
  lockLevel();
}