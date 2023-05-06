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
calcDay1 C B A #
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
int fulltime;                   // Armazena Horario 4 Digitos Processado
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
int compareYear = 0;            // Armazena Data Menu de Ajuste Calendario

byte hourBias;                  // Byte para Long horas x fuso (12 ~ 24)
byte minuteBias;                // Byte para Long minutos x 60 
byte secsBias;                  // Byte para Long segundos x 60
int secs;                       // Armazena Horario Segundos sem conversão

// NIVEL DE BATERIA E WIFI   
byte compareUpdateBattery;      // Armazena atualização de updateBattery
byte compareUpdateWiFi;         // Armazena atualização de updateBattery


// DADOS TOUCHSCREEN
int xMax;
int xMin;
int yMax;
int yMin;

// DADOS TIMERS
unsigned long period = 0;

// VALORES AJUSTAVEIS PELO USUÁRIO
byte logoTime = 3;

byte backgroundSetup = 0;
// backgroundSetup = 0 Programa Fundo Preto e Colorido.
// backgroundSetup = 1 Programa Fundo Branco e Colorido.
// backgroundSetup = 2 Programa Fundo Preto.
// backgroundSetup = 3 Programa Fundo Branco.

byte batteryStyleMode = 2;
// batteryStyleMode = 0 Estilo 1 de Bateria.
// batteryStyleMode = 1 Estilo 2 de Bateria.
// batteryStyleMode = 2 Estilo 3 de Bateria.
// batteryStyleMode = 3 Estilo 4 de Bateria.

byte lockStyle = 1;
// lockStyle = 0 Estilo 1 de Trava.
// lockStyle = 1 Estilo 2 de Trava.

int day;                        // Armazena dados de dia calendario
int month;                      // Armazena dados de mes calendario
int year;                       // Armazena dados de ano calendario
int startDay = 0;               // Identifica o 1 dia da semana
byte Week = 0;                  // Armazena Semana do ano
int dayWeek = 0;                // Armazena Dia do ano
int monthLengh = 0;             // Armazena o tamanho do Mes
int newDayStart = 0;            // Armazena o Dia do inicio da semana
int newWeekStart = 0;           // Armazena a posicao da Semana 
byte weekYear = 1;              // Armazena semana do mes calendario
int udpateCalendar;             // Armazena o dia para atualizacao do calendario

byte fuso = 1;                  
//fuso = 0 12 Horas  
//fuso = 1 24 Horas

// GERACAO DE GRAFICOS
int secsCalcGeiger = 0;         // Armazena segundos marcação gráfico Geiger
int minsCalcGeiger = 0;         // Armazena minutos marcação gráfico Geiger
int minsCalcTemp = 0;           // Armazena Horario marcação gráfico Temperatura
int minsCalcHumi = 0;           // Armazena Horario marcação gráfico Umidade
int minsCalcPres = 0;           // Armazena Horario marcação gráfico Pressão Atmosferica

int calcGeiger = 0;             // Armazena dado de Contagem para geigerCalc
int calcTemp = 0;               // Armazena dado de Contagem para tempCalc
int calcHumi = 0;               // Armazena dado de Contagem para humiCalc
int calcPres = 0;               // Armazena dado de Contagem para presCalc

int bankGeiger = 0;             // Armazena dado da posição do Gráfico em uso
int bankTemp = 0;               // Armazena dado da posição do Gráfico em uso
int bankHumi = 0;               // Armazena dado da posição do Gráfico em uso
int bankPres = 0;               // Armazena dado da posição do Gráfico em uso

byte functGeiger = 0;


int writerGeiger = 0;           // Armazena dado da posição do Gráfico em não uso
int writerTemp = 0;             // Armazena dado da posição do Gráfico em não uso
int writerHumi = 0;             // Armazena dado da posição do Gráfico em não uso
int writerPres = 0;             // Armazena dado da posição do Gráfico em não uso

int arrayGeiger [400] = {0};     // Armazena dados de Geiger
int arrayTemp [400] = {0};       // Armazena dados de Temperatura 
int arrayHumi [400] = {0};       // Armazena dados de Umidade 
int arrayPres [400] = {0};       // Armazena dados de Pressão Atmosferica

byte encoderPos = 0;
byte lastPos;
byte readClock;
boolean bCW;

int pressingDuration = 500;     // Tempo do botão Pressionado em Millis

unsigned long timerMode = 0;    // Armazena tempo atual
unsigned long touchMode = 0;    // Armazena tempo Touch

byte displayMode = 0;
// displayMode = 0 Sistema aguardando comando
// displayMode = 1 Habilita entrada do Menu
// displayMode = 2 Habilita saida do Menu

byte displayTFT = 0;     
// displayTFT = 0 Sistema aguardando comando

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

byte dosimeterSelection = 1;
// dosimeterSelection = 1 
// dosimeterSelection = 2
// dosimeterSelection = 3 
// dosimeterSelection = 4 
// dosimeterSelection = 5 

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

byte touchSet = 0; // Indica se o touch esta calibrado
// touchSet = 0 Display nao calibrado
// touchSet = 1 Display calibrado
// touchSet = 2 Usando os valores do DESENVOLVEDOR no setup()
// touchSet = 3 Em finalizacao de calibracao

bool squareEnd = 0;
bool roundEnd = 1;

// ------------------------------ CONFIGURACAO DOS PINOS DE SENSORES E DISPLAY --------

int pinBatteryRead;
int pinBatteryCharger;         // Pino de Leitura da Bateria

// ------------------------------ CORES DISPLAY RGB 555 -------------------------------

uint16_t blue_battery = 0x16BB;         //0x15D9E1
uint16_t green_battery = 0x1F22;        //0x19E710
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

uint16_t blackScript = 0x2104;          //0x202124
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

#include <TFT_eSPI.h> 
#include <SPI.h>
#include "MapFloat.h"
#include <Wire.h>
#include "Adafruit_GFX.h"

#include <stdint.h>

#include <EasyColor.h>

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
    
    TFT_eSPI tft = TFT_eSPI();      // Could invoke custom library declaring width and height
    EasyColor rgb2rgb;                 //Conversão de e para RGB888/RGB565

void setup() {
  Serial.begin(115200);
  Serial.println("Sistema Inicializado");
  tft.init();
  tft.setRotation(1);

  if (touchSet == 2) {
    uint16_t calData[5] = { 223, 3675, 227, 3503, 7 };
    tft.setTouch(calData);
  }

  if (fuso == 1) {
    fuso = 23;
  } else {
    fuso = 11;
  }

  hours = 0;
  mins = 0;
  day = 1;
  month = 3;
  year = 2023;
}



unsigned long UtlTime;
unsigned long timeSystem;
unsigned long timePressed;

int dosimetervalue = 0;
byte geigerCurve = 0;
byte updateGeigerCurve = 0;
byte arrayDosi [480] = {0};  

byte i = 0;  // ATUALIZACAO VISUAL DATA E HORA 
byte language = 1; // TELA DE ABERTURA

  uint16_t x = 0, y = 0; // To store the touch coordinates



byte switchPressedRecalibrate = 0; 
// switchPressedRecalibrate = 0 Aguardando comando
// switchPressedRecalibrate = 1 Tela de Calibracao

byte switchPressedTest = 0;
// switchPressedTest = 0 Aguardando comando
// switchPressedTest = 1 Tela de Teste do Touch

byte switchPressedExit = 0;
// switchPressedExit = 0 Aguardando comando
// switchPressedExit = 1 Saida da calibracao para welcome()

byte touchScreenMode = 0;
// switchPressedExit = 0 Aguardando comando
// switchPressedExit = 1 Habilita o testCalibration()

byte switchLanguage = 0;
// switchLanguage = 0 Aguardando comando
// switchLanguage = 1 Altera valor de language

byte switchStartWelcome = 0;
// swtichStartWelcome = 0 Aguardando comando
// swtichStartWelcome = 1 Saida de welcome para knowname()

byte switchInputName = 0;
// swtichStartWelcome = 0 Aguardando comando
// swtichStartWelcome = 1 Habita o keyboard()

byte switchMenuStart = 0;
// swtichStartWelcome = 0 Aguardando comando
// swtichStartWelcome = 1 Habita o welcome()
// swtichStartWelcome = 2 Habita o knowname()
// swtichStartWelcome = 3 Habita o profileimage()
// swtichStartWelcome = 4 Habita o internetAcess()
// swtichStartWelcome = 5 Habita o startProgram()

byte switchKeyboard = 0;
// switchKeyboard = 0 Aguardando comando
// switchKeyboard = 1 Habita o knowname()

byte keyboardClose = 0;
// keyboardClose = 0 Aguardando comando
// keyboardClose = 1 Habita o knowname()

byte swithContinueKnowname = 0;
// swithContinueKnowname = 0 Aguardando comando
// swithContinueKnowname = 1 Habita o profileimage()


byte switchCaps = 0;
// switchCaps = 0 Aguardando comando
// switchCaps = 1 Habita o CAPSLOCK

byte languageScreen = 0;
// languageScreen = 0 Aguardando comando
// languageScreen = 1 Habilita alteracao da byte language


#define nameLenght 30
int lenghtText = 0;
char textKnowname [nameLenght] = {0};
char key;


void loop(void) {
  // ------------------------------- touchScreen OPERACIONAL ----------------------
    bool pressed = tft.getTouch(&x, &y);

    if (pressed) {
      if (timeSystem - timePressed >= 250) {
        Serial.print("x, y, z = ");
        Serial.print(x);
        Serial.print(",");
        Serial.print(y);
        Serial.print(",");
        Serial.printf("%i \n", tft.getTouchRawZ()); 
        timePressed = timeSystem;
      
  // ------------------------------ TOUCHSCREEN DISPLAY TFT 16 E 17 ---------------------
        if (displayTFT == 16 || displayTFT == 17) {
          touchRectRound(70, 250, 100, 30, 5, nixieColor, blackScript, switchPressedRecalibrate);
          tft.drawString("Recalibrar", 120, 264, GFXFF);
          if (switchPressedRecalibrate == 1) {
            switchPressedRecalibrate = 0;
            touchScreenMode = 0;
            touch_calibrate();
          }

          touchRectRound(190, 250, 100, 30, 5, autumnMenu, blackScript, switchPressedTest);
          Serial.print("switchPressedTest: ");
          Serial.println(switchPressedTest);
          if (touchScreenMode == 0) {
            tft.drawString("Testar", 240, 264, GFXFF);
          }
          if (switchPressedTest == 1) {
            testCalibration();
          } 

          touchRectRound(310, 250, 100, 30, 5, winterMenu, blackScript, switchPressedExit);
          tft.drawString("Sair", 360, 264, GFXFF);
          if (switchPressedExit == 1) {
            switchPressedExit = 0;
            touchScreenMode = 0;
            displayTFT = 18;
            tft.fillScreen(blackScript);
            welcome();
          }
        }

  // ------------------------------ WELCOME DISPLAY TFT 18 ---------------------
        if (displayTFT == 18) {
          touchRect(390, 280, 90, 40, blackScript, blackScript, languageScreen);
          if (languageScreen == 1) {
            tft.fillScreen(blackScript);
            if (language == 1) {
              language = 0;
              languageScreen = 0;
              welcome();
            } else {
              language = 1;
              languageScreen = 0;
              welcome();
            }
          }
          
          touchRect(190, 232, 100, 30, blackScript, blackScript, switchStartWelcome);
          if (switchStartWelcome == 1) {
            switchStartWelcome = 0;
            displayTFT = 19;
            tft.fillScreen(blackScript);
            knowname();
          }
        }

  // ------------------------------ KNOWNAME DISPLAY TFT 19 ---------------------
        if (displayTFT == 19) {
          touchRect(390, 280, 90, 40, blackScript, blackScript, languageScreen);
          if (languageScreen == 1) {
            tft.fillScreen(blackScript);
            if (language == 1) {
              language = 0;
              languageScreen = 0;
              knowname();
            } else {
              language = 1;
              languageScreen = 0;
              knowname();
            }
          }

          touchRectRound(115, 150, 250, 30, 5, whiteScript, blackScript, switchInputName);
          if (switchInputName == 1) {
            displayTFT = 20;
            tft.fillScreen(blackScript);
            switchInputName = 0;
            keyboard();
          }

          /*
          touchRectRound(190, 232, 100, 30, 5, whiteScript, blackScript, swithContinueKnowname);
          if (swithContinueKnowname == 1) {
            displayTFT = 21;
            tft.fillScreen(blackScript);
            swithContinueKnowname = 0;
            profileimage();
          }
          */

          touchCircle(454, 88, 10, whiteScript, wifi_off2, switchMenuStart);
          if (switchMenuStart == 1) {
            displayTFT = 18;
            tft.fillScreen(blackScript);
            switchMenuStart = 0;
            welcome();
          }
        }

  // ------------------------------ KEYBOARD DISPLAY TFT 20 ---------------------
        if (displayTFT == 20) {
          touchRect(2, 240, 35, 35, wifi_off2, blackScript, switchCaps);
          touchRect(442, 240, 35, 35, wifi_off2, blackScript, switchCaps);
          if (x > 2 && x < 2 + 35 && y > 240 && y < 240 + 35) {
            tft.fillRect(0, 160, 480, 160, blackScript);
            keyboard();
          } 
          if (x > 2 && x < 2 + 35 && y > 240 && y < 240 + 35) {
            tft.fillRect(0, 160, 480, 160, blackScript);
            keyboard();
          }

          touchCircle(441, 93, 20, blackScript, blackScript, keyboardClose);
          if (keyboardClose == 1) {
            displayTFT = 19;
            keyboardClose = 0;
            tft.fillScreen(blackScript);
            knowname();
          }



    // COLUNA 1 TECLADO
          if (x > 2 && x < 2 + 35 && y > 160 && y < 160 + 35) {
            if (switchCaps == 0) {
              textBoxName(113);
              Serial.println("q");
            } else {
              textBoxName(81);
              Serial.println("Q");
            }
          }
          if (x > 42 && x < 42 + 35 && y > 160 && y < 160 + 35) {
            if (switchCaps == 0) {
              textBoxName(119);
              Serial.println("w");
            } else {
              textBoxName(87);
              Serial.println("W");
            }
          }
          if (x > 82 && x < 82 + 35 && y > 160 && y < 160 + 35) {
            if (switchCaps == 0) {
              textBoxName(101);
              Serial.println("e");
            } else {
              textBoxName(69);
              Serial.println("E");
            }
          }
          if (x > 122 && x < 122 + 35 && y > 160 && y < 160 + 35) {
            if (switchCaps == 0) {
              textBoxName(114);
              Serial.println("r");
            } else {
              textBoxName(82);
              Serial.println("R");
            }
          }
          if (x > 162 && x < 162 + 35 && y > 160 && y < 160 + 35) {
            if (switchCaps == 0) {
              textBoxName(116);
              Serial.println("t");
            } else {
              textBoxName(84);
              Serial.println("T");
            }
          }
          if (x > 202 && x < 202 + 35 && y > 160 && y < 160 + 35) {
            if (switchCaps == 0) {
              textBoxName(121);
              Serial.println("y");
            } else {
              textBoxName(89);
              Serial.println("Y");
            }
          }
          if (x > 242 && x < 242 + 35 && y > 160 && y < 160 + 35) {
            if (switchCaps == 0) {
              textBoxName(117);
              Serial.println("u");
            } else {
              textBoxName(85);
              Serial.println("U");
            }
          }
          if (x > 282 && x < 282 + 35 && y > 160 && y < 160 + 35) {
            if (switchCaps == 0) {
              textBoxName(105);
              Serial.println("i");
            } else {
              textBoxName(73);
              Serial.println("I");
            }
          }
          if (x > 322 && x < 322 + 35 && y > 160 && y < 160 + 35) {
            if (switchCaps == 0) {
              textBoxName(111);
              Serial.println("o");
            } else {
              textBoxName(79);
              Serial.println("O");
            }
          }
          if (x > 362 && x < 362 + 35 && y > 160 && y < 160 + 35) {
            if (switchCaps == 0) {
              textBoxName(112);
              Serial.println("p");
            } else {
              textBoxName(80);
              Serial.println("P");
            }
          }
          if (x > 402 && x < 402 + 75 && y > 160 && y < 160 + 35) {
            textBoxName(8);
            Serial.println("Backspace");
          }

    // COLUNA 2 TECLADO
          if (x > 24 && x < 24 + 35 && y > 200 && y < 200 + 35) {
            if (switchCaps == 0) {
              textBoxName(97);
              Serial.println("a");
            } else {
              textBoxName(65);
              Serial.println("A");
            }
          }
          if (x > 64 && x < 64 + 35 && y > 200 && y < 200 + 35) {
            if (switchCaps == 0) {
              textBoxName(115);
              Serial.println("s");
            } else {
              textBoxName(83);
              Serial.println("S");
            }
          }
          if (x > 104 && x < 104 + 35 && y > 200 && y < 200 + 35) {
            if (switchCaps == 0) {
              textBoxName(100);
              Serial.println("d");
            } else {
              textBoxName(68);
              Serial.println("D");
            }
          }
          if (x > 144 && x < 144 + 35 && y > 200 && y < 200 + 35) {
            if (switchCaps == 0) {
              textBoxName(102);
              Serial.println("f");
            } else {
              textBoxName(70);
              Serial.println("F");
            }
          }
          if (x > 184 && x < 184 + 35 && y > 200 && y < 200 + 35) {
            if (switchCaps == 0) {
              textBoxName(103);
              Serial.println("g");
            } else {
              textBoxName(71);
              Serial.println("G");
            }
          }
          if (x > 224 && x < 224 + 35 && y > 200 && y < 200 + 35) {
            if (switchCaps == 0) {
              textBoxName(104);
              Serial.println("h");
            } else {
              textBoxName(72);
              Serial.println("H");
            }
          }
          if (x > 264 && x < 264 + 35 && y > 200 && y < 200 + 35) {
            if (switchCaps == 0) {
              textBoxName(106);
              Serial.println("j");
            } else {
              textBoxName(74);
              Serial.println("J");
            }
          }
          if (x > 304 && x < 304 + 35 && y > 200 && y < 200 + 35) {
            if (switchCaps == 0) {
              textBoxName(107);
              Serial.println("k");
            } else {
              textBoxName(75);
              Serial.println("K");
            }
          }
          if (x > 344 && x < 344 + 35 && y > 200 && y < 200 + 35) {
            if (switchCaps == 0) {
              textBoxName(108);
              Serial.println("l");
            } else {
              textBoxName(76);
              Serial.println("L");
            }
          }
          if (x > 384 && x < 384 + 35 && y > 200 && y < 200 + 35) {
            textBoxName(39);
            Serial.println("'");
          }
          if (x > 424 && x < 424 + 53 && y > 200 && y < 200 + 35) {
            textBoxName(10);
            Serial.println("Enter");
          }

    // COLUNA 3 TECLADO
          if (x > 42 && x < 42 + 35 && y > 240 && y < 240 + 35) {
            if (switchCaps == 0) {
              textBoxName(122);
              Serial.println("z");
            } else {
              textBoxName(90);
              Serial.println("Z");
            }
          }
          if (x > 82 && x < 82 + 35 && y > 240 && y < 240 + 35) {
            if (switchCaps == 0) {
              textBoxName(120);
              Serial.println("x");
            } else {
              textBoxName(88);
              Serial.println("X");
            }
          }
          if (x > 122 && x < 122 + 35 && y > 240 && y < 240 + 35) {
            if (switchCaps == 0) {
              textBoxName(99);
              Serial.println("c");
            } else {
              textBoxName(67);
              Serial.println("C");
            }
          }
          if (x > 162 && x < 162 + 35 && y > 240 && y < 240 + 35) {
            if (switchCaps == 0) {
              textBoxName(118);
              Serial.println("v");
            } else {
              textBoxName(86);
              Serial.println("V");
            }
          }
          if (x > 202 && x < 202 + 35 && y > 240 && y < 240 + 35) {
            if (switchCaps == 0) {
              textBoxName(98);
              Serial.println("b");
            } else {
              textBoxName(66);
              Serial.println("B");
            }
          }
          if (x > 242 && x < 242 + 35 && y > 240 && y < 240 + 35) {
            if (switchCaps == 0) {
              textBoxName(110);
              Serial.println("n");
            } else {
              textBoxName(78);
              Serial.println("N");
            }
          }
          if (x > 282 && x < 282 + 35 && y > 240 && y < 240 + 35) {
            if (switchCaps == 0) {
              textBoxName(109);
              Serial.println("m");
            } else {
              textBoxName(77);
              Serial.println("M");
            }
          }
          if (x > 322 && x < 322 + 35 && y > 240 && y < 240 + 35) {
            textBoxName(44);
            Serial.println(",");
          }
          if (x > 362 && x < 362 + 35 && y > 240 && y < 240 + 35) {
            textBoxName(46);
            Serial.println(".");
          }
          if (x > 402 && x < 402 + 35 && y > 240 && y < 240 + 35) {
            textBoxName(63);
            Serial.println("?");
          }
          if (x > 442 && x < 442 + 35 && y > 240 && y < 240 + 35) {
            textBoxName(127);
            Serial.println("Del");
          }

    // COLUNA 4 TECLADO
          if (x > 122 && x < 122 + 235 && y > 280 && y < 280 + 35) {
            textBoxName(32);
            Serial.println("Space");
          }
        }

  // ------------------------------ PROFILEIMAGE DISPLAY TFT 21 ---------------------
        if (displayTFT == 21) {
          touchRect(390, 280, 90, 40, blackScript, blackScript, languageScreen);
          if (languageScreen == 1) {
            tft.fillScreen(blackScript);
            if (language == 1) {
              language = 0;
              languageScreen = 0;
              profileimage();
            } else {
              language = 1;
              languageScreen = 0;
              profileimage();
            }
          } 



        }




      }
    }




  // ------------------------ HORARIO VIA MILLIS() OPERACIONAL -----------------------
    timeSystem = millis();

    if(timeSystem - UtlTime >= 1000) {
      UtlTime = timeSystem;
      secs ++;
    }
    if(secs > 59) {
      secs = 0;
      mins = mins + 1;
      if(mins > 59) {
        hours = hours + 1;
        mins = 0;
        if(hours > 23) {
          day = day + 1;
          hours = 0;
          if( month ==1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
            if(day > 31) {
              day = 1;
              month = month + 1;
              if(month > 12) {
                year = year + 1;
                month = 1;
              }
            }
          }
          else if(month == 2) {
            if(year%400 == 0) {
              if(day > 29) {
                day = 1;
                month = month + 1;
              }
            }
            else if((year%4==0) && (year%100!=0)) {
              if(day > 29) {
                day = 1;
                month = month + 1;
              }
            } else {
              if(day > 28) {
                day = 1;
                month = month + 1;
              }
            }
          } else {
            if(day > 30) {
              day = 1;
              month = month + 1;
            }
          }
        }
      }
    }

  // ------------------------ COMANDO DE LOGO ----------

    if (logoStarted == 0) {
      logoStarted = 1;
      startLogo();
      if (UtlTime - period >= logoTime * 1000) {
        period = UtlTime;
        if ((backgroundSetup == 1) || (backgroundSetup == 3)) {
          tft.fillRect(0, 0, 480, 320, whiteScript);
        } else {
          tft.fillRect(0, 0, 480, 320, blackScript);
        }
      }
    } 

  // ------------------------ PERFIL SETUP -----------
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
        if (touchSet == 1) {
          defaultSetup();
        } else if (touchSet == 0){
          touch_calibrate();
        }
    } 

  // ------------------------ ATUALIZA RELOGIO SERIAL OPERACIONAL -----------
    /*if (secs != compareSecs) {
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
    */

  // ------------------------ ATUALIZACAO VISUAL DATA E HORA OPERACIONAL --------
    if (displayTFT < 16) {
      if (i == 1) {
        compareHour = 0;
        compareMins = 0;
        compareDay = 0;
        compareMonth = 0;
        compareYear = 0;
        i = 2;
      }
    
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
    
      if (hours != compareHour) {
        compareHour = hours;
        tft.setTextDatum(ML_DATUM);
        tft.setTextColor(blackScript);
        tft.setFreeFont(latoRegular24);
        if ((hours > 1) && (hours < 10)) {
          tft.drawString("0", 219, 30, GFXFF);
          tft.drawString(stringHourMin, 234, 30, GFXFF);
        } else {
          tft.fillRect(219, 22, 28, 20, blackScript);
        }
        tft.setTextColor(whiteScript);  
        if (hours < 10) {
          tft.drawString("0", 219, 30, GFXFF);
          tft.drawString(stringHour, 234, 30, GFXFF);
        } else {
          tft.drawString(stringHour, 219, 30, GFXFF);
        }
      }
      if (mins != compareMins) {
        compareMins = mins;
        tft.setTextDatum(ML_DATUM);
        tft.setTextColor(blackScript);
        tft.setFreeFont(latoRegular24);
        if ((mins > 1) && (mins < 10)) {
          tft.drawString("0", 252, 30, GFXFF);
          tft.drawString(stringMinMin, 267, 30, GFXFF);
        } else {
          tft.fillRect(252, 22, 28, 20, blackScript);
        }
        tft.setTextColor(whiteScript);  
        if (mins < 10) {
          tft.drawString("0", 252, 30, GFXFF);
          tft.drawString(":", 246, 30, GFXFF);
          tft.drawString(stringMin, 267, 30, GFXFF);
        } else {
          tft.drawString(":", 246, 30, GFXFF);
          tft.drawString(stringMin, 252, 30, GFXFF);
        }
      }

      if (day != compareDay) {
        compareDay = day;
        tft.setTextDatum(ML_DATUM);
        tft.setTextColor(blackScript);
        tft.setFreeFont(latoRegular24);
        if ((day > 1) && (day < 10)) {
          tft.drawString("0", 77, 30, GFXFF);
          tft.drawString(stringDayMin, 92, 30, GFXFF);
        } else {
          tft.fillRect(77, 22, 28, 20, blackScript);
        }

        tft.setTextColor(whiteScript);  
        if (day < 10) {
          tft.drawString("0", 77, 30, GFXFF);
          tft.drawString(stringDay, 92, 30, GFXFF);
        } else {
          tft.drawString(stringDay, 77, 30, GFXFF);
        }
      }

      if (month != compareMonth) {
        compareMonth = month;
        tft.setTextDatum(ML_DATUM);
        tft.setTextColor(blackScript);
        tft.setFreeFont(latoRegular24);
        if ((month > 1) && (month < 10)) {
          tft.drawString("0", 110, 30, GFXFF);
          tft.drawString(stringMonthMin, 125, 30, GFXFF);
        } else {
          tft.fillRect(110, 22, 28, 20, blackScript);
        }

        tft.setTextColor(whiteScript);  

        if (month < 10) {
          tft.drawString("0", 110, 30, GFXFF);
          tft.drawString(stringMonth, 125, 30, GFXFF);
        } else {
          tft.drawString(stringMonth, 110, 30, GFXFF);
        }
      }

      if (year != compareYear) {
        compareYear = year;
        tft.setTextDatum(ML_DATUM);
        tft.setTextColor(blackScript);
        tft.setFreeFont(latoRegular24);
        tft.drawString(stringYearMin, 143, 30, GFXFF);

        tft.setTextColor(whiteScript);  

        tft.drawString(stringYear, 143, 30, GFXFF);
      }
    }

  // ------------------------ ATUALIZA GRAFICO DOSIMETRO GEIGER -------------------
    if (telaMenu == 3) {
      //33 - 433 X
      //78 - 196 Y
      if (dosimeterSelection == 1) {
        if (secsCalcGeiger != secs) {
          secsCalcGeiger = secs;
          switch(secs) {
            case 0: bankGeiger = 32; break;
            case 1: bankGeiger = 39; break;
            case 2: bankGeiger = 45; break;
            case 3: bankGeiger = 52; break;
            case 4: bankGeiger = 59; break;
            case 5: bankGeiger = 65; break;
            case 6: bankGeiger = 72; break;
            case 7: bankGeiger = 77; break;
            case 8: bankGeiger = 85; break;
            case 9: bankGeiger = 92; break;
            case 10: bankGeiger = 99; break;
            case 11: bankGeiger = 105; break;
            case 12: bankGeiger = 112; break;
            case 13: bankGeiger = 119; break;
            case 14: bankGeiger = 125; break;
            case 15: bankGeiger = 132; break;
            case 16: bankGeiger = 139; break;
            case 17: bankGeiger = 145; break;
            case 18: bankGeiger = 152; break;
            case 19: bankGeiger = 159; break;
            case 20: bankGeiger = 165; break;
            case 21: bankGeiger = 172; break;
            case 22: bankGeiger = 179; break;
            case 23: bankGeiger = 185; break;
            case 24: bankGeiger = 192; break;
            case 25: bankGeiger = 199; break;
            case 26: bankGeiger = 205; break;
            case 27: bankGeiger = 212; break;
            case 28: bankGeiger = 219; break;
            case 29: bankGeiger = 225; break;
            case 30: bankGeiger = 232; break;
            case 31: bankGeiger = 239; break;
            case 32: bankGeiger = 245; break;
            case 33: bankGeiger = 252; break;
            case 34: bankGeiger = 259; break;
            case 35: bankGeiger = 265; break;
            case 36: bankGeiger = 272; break;
            case 37: bankGeiger = 279; break;
            case 38: bankGeiger = 285; break;
            case 39: bankGeiger = 292; break;
            case 40: bankGeiger = 299; break;
            case 41: bankGeiger = 305; break;
            case 42: bankGeiger = 312; break;
            case 43: bankGeiger = 319; break;
            case 44: bankGeiger = 325; break;
            case 45: bankGeiger = 332; break;
            case 46: bankGeiger = 339; break;
            case 47: bankGeiger = 345; break;
            case 48: bankGeiger = 352; break;
            case 49: bankGeiger = 359; break;
            case 50: bankGeiger = 365; break;
            case 51: bankGeiger = 372; break;
            case 52: bankGeiger = 379; break;
            case 53: bankGeiger = 385; break;
            case 54: bankGeiger = 392; break;
            case 55: bankGeiger = 399; break;
            case 56: bankGeiger = 405; break;
            case 57: bankGeiger = 412; break;
            case 58: bankGeiger = 418; break;
            case 59: bankGeiger = 425; break;
          }
        }
      }
      if (dosimeterSelection == 2) {
        if (minsCalcGeiger != mins) {
          minsCalcGeiger = mins;
          switch(hours) {
            case 0: bankGeiger = 32; break; 
            case 1: bankGeiger = 48; break; 
            case 2: bankGeiger = 64; break; 
            case 3: bankGeiger = 82; break;
            case 4: bankGeiger = 98; break;
            case 5: bankGeiger = 114; break;
            case 6: bankGeiger = 132; break;
            case 7: bankGeiger = 148; break;
            case 8: bankGeiger = 164; break;
            case 9: bankGeiger = 182; break;
            case 10: bankGeiger = 198; break;
            case 11: bankGeiger = 214; break;
            case 12: bankGeiger = 232; break;
            case 13: bankGeiger = 248; break;
            case 14: bankGeiger = 264; break;
            case 15: bankGeiger = 282; break;
            case 16: bankGeiger = 298; break;
            case 17: bankGeiger = 314; break;
            case 18: bankGeiger = 332; break;
            case 19: bankGeiger = 348; break;
            case 20: bankGeiger = 364; break;
            case 21: bankGeiger = 382; break;
            case 22: bankGeiger = 398; break;
            case 23: bankGeiger = 414; break;
          }
          switch(mins) {
            case 3: bankGeiger = bankGeiger + 0; break;
            case 6: bankGeiger = bankGeiger + 1; break;
            case 10: bankGeiger = bankGeiger + 2; break;
            case 13: bankGeiger = bankGeiger + 3; break;
            case 16: bankGeiger = bankGeiger + 4; break;
            case 19: bankGeiger = bankGeiger + 5; break;
            case 22: bankGeiger = bankGeiger + 6; break;
            case 25: bankGeiger = bankGeiger + 7; break;
            case 28: bankGeiger = bankGeiger + 8; break;
            case 31: bankGeiger = bankGeiger + 9; break;
            case 36: bankGeiger = bankGeiger + 10; break;
            case 37: bankGeiger = bankGeiger + 11; break;
            case 40: bankGeiger = bankGeiger + 12; break;
            case 43: bankGeiger = bankGeiger + 13; break;
            case 46: bankGeiger = bankGeiger + 14; break;
            case 49: bankGeiger = bankGeiger + 15; break;
            case 53: bankGeiger = bankGeiger + 16; break;
            case 56: bankGeiger = bankGeiger + 17; break;
          }
        }
      }
      byte undoWriterGeiger;
      if (bankGeiger != writerGeiger) {
        functGeiger = map(random(0, 200), 0, 200, 196, 78); 
        undoWriterGeiger = writerGeiger - 1;
        writerGeiger = bankGeiger;
      }
      rgbColorGeiger();
      arrayDosi[writerGeiger] = functGeiger;
      //tft.drawPixel(bankGeiger, arrayDosi[writerGeiger], geigerColor);
      tft.drawLine(bankGeiger, arrayDosi[writerGeiger], bankGeiger - 6, arrayDosi[undoWriterGeiger], geigerColor);
    }

  // ------------------------ ATUALIZACAO CALENDARIO OPERACIONAL -----------
    if (day != udpateCalendar) {
      udpateCalendar = day;
      if (telaMenu == 4) {
        tft.fillRect(0, 65, 480, 255, blackScript);
        calendar();
      }
    }

}


void textBoxName(int keys) {
  Serial.print(keys);
  Serial.print(":  ");
  switch (keys) {
    case 1 : key = ' '; break;
    case 2 : key = ' '; break;
    case 3 : key = ' '; break;
    case 4 : key = ' '; break;
    case 5 : key = ' '; break;
    case 6 : key = ' '; break;
    case 7 : key = ' '; break;
    case 8 : keyBackspace(); break;
    case 9 : key = ' '; break;
    case 10: key = ' '; break;
    case 11: key = ' '; break;
    case 12: key = ' '; break;
    case 13: key = ' '; break;
    case 14: key = ' '; break;
    case 15: key = ' '; break;
    case 16: key = ' '; break;
    case 17: key = ' '; break;
    case 18: key = ' '; break;
    case 19: key = ' '; break;
    case 20: key = ' '; break;
    case 21: key = ' '; break;
    case 22: key = ' '; break;
    case 23: key = ' '; break;
    case 24: key = ' '; break;
    case 25: key = ' '; break;
    case 26: key = ' '; break;
    case 27: key = ' '; break;
    case 28: key = ' '; break;
    case 29: key = ' '; break;
    case 30: key = ' '; break;
    case 31: key = ' '; break;
    case 32: key = ' '; break;
    case 33: key = '!'; break;
    case 34: key = '"'; break;
    case 35: key = '#'; break;
    case 36: key = '$'; break;
    case 37: key = '%'; break;
    case 38: key = '&'; break;
    case 39: key = ' '; break;
    case 40: key = '('; break;
    case 41: key = ')'; break;
    case 42: key = '*'; break;
    case 43: key = '+'; break;
    case 44: key = ','; break;
    case 45: key = '-'; break;
    case 46: key = '.'; break;
    case 47: key = '/'; break;
    case 48: key = '0'; break;
    case 49: key = '1'; break;
    case 50: key = '2'; break;
    case 51: key = '3'; break;
    case 52: key = '4'; break;
    case 53: key = '5'; break;
    case 54: key = '6'; break;
    case 55: key = '7'; break;
    case 56: key = '8'; break;
    case 57: key = '9'; break;
    case 58: key = ':'; break;
    case 59: key = ';'; break;
    case 60: key = '<'; break;
    case 61: key = '='; break;
    case 62: key = '>'; break;
    case 63: key = '?'; break;
    case 64: key = '@'; break;
    case 65: key = 'A'; break;
    case 66: key = 'B'; break;
    case 67: key = 'C'; break;
    case 68: key = 'D'; break;
    case 69: key = 'E'; break;
    case 70: key = 'F'; break;
    case 71: key = 'G'; break;
    case 72: key = 'H'; break;
    case 73: key = 'I'; break;
    case 74: key = 'J'; break;
    case 75: key = 'K'; break;
    case 76: key = 'L'; break;
    case 77: key = 'M'; break;
    case 78: key = 'N'; break;
    case 79: key = 'O'; break;
    case 80: key = 'P'; break;
    case 81: key = 'Q'; break;
    case 82: key = 'R'; break;
    case 83: key = 'S'; break;
    case 84: key = 'T'; break;
    case 85: key = 'U'; break;
    case 86: key = 'V'; break;
    case 87: key = 'W'; break;
    case 88: key = 'X'; break;
    case 89: key = 'Y'; break;
    case 90: key = 'Z'; break;
    case 91: key = '['; break;
    case 92: key = '\ '; break;
    case 93: key = ']'; break;
    case 94: key = '^'; break;
    case 95: key = '_'; break;
    case 96: key = '`'; break;
    case 97: key = 'a'; break;
    case 98: key = 'b'; break;
    case 99: key = 'c'; break;
    case 100: key = 'd'; break;
    case 101: key = 'e'; break;
    case 102: key = 'f'; break;
    case 103: key = 'g'; break;
    case 104: key = 'h'; break;
    case 105: key = 'i'; break;
    case 106: key = 'j'; break;
    case 107: key = 'k'; break;
    case 108: key = 'l'; break;
    case 109: key = 'm'; break;
    case 110: key = 'n'; break;
    case 111: key = 'o'; break;
    case 112: key = 'p'; break;
    case 113: key = 'q'; break;
    case 114: key = 'r'; break;
    case 115: key = 's'; break;
    case 116: key = 't'; break;
    case 117: key = 'u'; break;
    case 118: key = 'v'; break;
    case 119: key = 'w'; break;
    case 120: key = 'x'; break;
    case 121: key = 'y'; break;
    case 122: key = 'z'; break;
    case 123: key = '{'; break;
    case 124: key = '|'; break;
    case 125: key = '}'; break;
    case 126: key = '~'; break;
    case 127: key = ' '; break;
  }

  if (lenghtText < nameLenght) {
    textKnowname[lenghtText] = key;
    lenghtText ++;
    tft.fillRect(69, 83, 342, 34, blackScript);
    Serial.println(textKnowname);
    Serial.println(lenghtText);
    tft.setTextDatum(ML_DATUM);
    tft.setTextColor(whiteScript);
    tft.setFreeFont(latoRegular24);
    tft.drawString(textKnowname, 69, 98, GFXFF);
  }
}

void keyBackspace() {
  Serial.println(lenghtText);
  if (lenghtText > 0) {
    lenghtText ++;
    textKnowname[lenghtText] = ' ';
    lenghtText  = lenghtText - 2;
  } else if (lenghtText < 0) {
    textKnowname[lenghtText] = ' ';
    lenghtText ++;
  }
  tft.fillRect(69, 83, 342, 34, blackScript);
  Serial.println(lenghtText);
}

void touch_calibrate() {
  displayTFT = 16;
  uint16_t calData[5]; // REMOVER WHITE WHITE WHITE WHITE

  // Calibrate
  tft.fillScreen(blackScript);
  tft.setCursor(20, 0);
  
  tft.setTextDatum(MC_DATUM);
  tft.setTextColor(whiteScript);
  tft.setFreeFont(latoRegular24);
  tft.drawString("Toque nas setas indicados", 240, 124, GFXFF);
  tft.drawString("Touch in the indicated corners", 240, 154, GFXFF);

  tft.println();

  tft.calibrateTouch(calData, greenScript, blackScript, 15);

  touchSet = 3;

  tft.fillScreen(blackScript);

  tft.setTextDatum(MC_DATUM);
  tft.setTextColor(whiteScript);
  tft.setFreeFont(latoRegular24);
  tft.drawString("Calibracao Concluida!", 240, 124, GFXFF);
  tft.drawString("Calibration Completed!", 240, 154, GFXFF);

  tft.drawRoundRect(70, 250, 100, 30, 5, temperatureColor2);
  tft.drawRoundRect(190, 250, 100, 30, 5, icon_9);
  tft.drawRoundRect(310, 250, 100, 30, 5, humidityColor1);
  tft.setFreeFont(latoRegular14);
  tft.drawString("Recalibrar", 120, 264, GFXFF);
  tft.drawString("Testar", 240, 264, GFXFF);
  tft.drawString("Sair", 360, 264, GFXFF);
}

void testCalibration() {
  if (touchScreenMode == 0) {
    tft.fillScreen(blackScript);
    touchScreenMode ++;
    tft.drawRoundRect(70, 250, 100, 30, 5, nixieColor);
    tft.fillRoundRect(190, 250, 100, 30, 5, autumnMenu);
    tft.drawRoundRect(310, 250, 100, 30, 5, winterMenu);
 
    tft.drawString("Recalibrar", 120, 264, GFXFF);
    tft.drawString("Limpar", 240, 264, GFXFF);
    tft.drawString("Sair", 360, 264, GFXFF);
  }
  displayTFT = 17;
  uint16_t x, y;

  if (tft.getTouch(&x, &y)) {
    tft.fillRect(10, 0, 40, 35, blackScript);
    tft.setCursor(5, 15, 2);
    tft.printf("x: %i     ", x);
    tft.setCursor(5, 30, 2);
    tft.printf("y: %i    ", y);

    tft.fillCircle(x, y, 2, green_battery);

    if (switchPressedTest == 0 && touchScreenMode == 1) {
      touchScreenMode == 0;
      testCalibration();
    }
  }
}

void rgbColorGeiger() {
    byte rValue = map (writerGeiger, 33, 433, 255, 228);
    byte gValue = map (writerGeiger, 33, 433, 184, 152);
    byte bValue = map (writerGeiger, 33, 433, 1, 55);

    geigerColor = rgb2rgb.RGB24toRGB16(rValue,gValue,bValue);
}

// -------------------------
void displayMenu() {
  displayMode ++;
  if (displayMode == 1) {
    selectFunctionDisplay();
  } else if (displayMode == 2) {
    displayMode = 0;
  }
}

void selectFunctionDisplay() {
  // telaMenu = 0 Sistema aguardando comando
  // telaMenu = 1 Exibe display Geiger 
  static unsigned long UtlTime = 0;

  if (UtlTime - period >= 5 * 1000) {
    period = UtlTime;
  }  
  if (displayTFT == 0) {
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
      case 16:
        touch_calibrate();
      break;
      case 17:
        testCalibration();
      break;
      case 18:
        welcome();
      break;
      default:
        defaultSetup();
    }
  }
}

// ------------------------ TELA DE ABERTURA -------------

void startLogo() {
  bool wait = 1;
  tft.fillScreen(blackScript);
  tft.setSwapBytes(true);
  //tft.pushImage(0, 0, 480, 320, abertura); //white white white white white white ATIVAR PARA USAR

  if (language == 1) {
    tft.setTextDatum(ML_DATUM);
    tft.setTextColor(whiteScript);
    tft.setFreeFont(latoBold48);
    tft.drawString("MAKING THE", 36, 125, GFXFF);
    tft.drawString("OLD NEW", 36, 185, GFXFF);

    tft.setFreeFont(latoRegular24);
    tft.drawString("EN-US", 394, 299, GFXFF);
  } else {
    tft.setTextDatum(ML_DATUM);
    tft.setTextColor(whiteScript);
    tft.setFreeFont(latoBold48);
    tft.drawString("FAZENDO O", 36, 125, GFXFF);
    tft.drawString("ANTIGO NOVO", 36, 185, GFXFF);

    tft.setFreeFont(latoRegular24);
    tft.drawString("PT-BR", 394, 299, GFXFF);
  }
  wifiLevel();
  batteryLevel();
  lockLevel();

  while (wait) {
    bool pressed = tft.getTouch(&x, &y);
    if (pressed) {
      if (touchSet == 0) {
        touch_calibrate();
        wait = 0;
        break;
      }
    }
  }
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
    tft.pushImage(124, 227, 71, 71, icon12);
    tft.pushImage(205, 227, 71, 71, icon13);
    tft.pushImage(286, 227, 71, 71, icon14);
    tft.pushImage(367, 227, 71, 71, icon15);

    wifiLevel();
    batteryLevel();
    lockLevel();
    
    screenLoad = 1;
  }
}

void wifiLevel() {
  switch (wifiRead) {
    case 1:
      wifiStyle2();
    break;
    case 2:
      wifiStyle3();
    break;
    case 3:
      wifiStyle4();
    break;
    default:
      wifiStyle1();
  }
}

void wifiStyle1() {
  tft.fillCircle(333, 36, 2, septemberColor);
  tft.drawSmoothArc(333, 36, 5, 7, 134, 226, septemberColor, blackScript, roundEnd);
  tft.drawSmoothArc(333, 36, 10, 12, 134, 226, septemberColor, blackScript, roundEnd);
  tft.drawSmoothArc(333, 36, 15, 17, 134, 226, septemberColor, blackScript, roundEnd);
}
void wifiStyle2() {
  tft.fillRoundRect(322, 15, 30, 30, 5, februeryColor);
  tft.fillCircle(337, 36, 2, whiteScript);
  tft.drawSmoothArc(337, 36, 6, 7, 134, 226, whiteScript, februeryColor, roundEnd);
  tft.drawSmoothArc(337, 36, 11, 12, 134, 226, whiteScript, februeryColor, roundEnd);
  tft.drawSmoothArc(337, 36, 16, 17, 134, 226, whiteScript, februeryColor, roundEnd);
}
void wifiStyle3() {
  tft.drawSmoothArc(330, 38, 0, 2, 179, 269, whiteScript, blackScript, squareEnd);
  tft.drawSmoothArc(330, 38, 6, 7, 179, 269, whiteScript, blackScript, squareEnd);
  tft.drawSmoothArc(330, 38, 11, 12, 179, 269, whiteScript, blackScript, squareEnd);
  tft.drawSmoothArc(330, 38, 16, 17, 179, 269, whiteScript, blackScript, squareEnd);
}
void wifiStyle4() {
  tft.drawSmoothArc(337, 36, 0, 4, 134, 226, whiteScript, februeryColor, roundEnd);
  tft.drawSmoothArc(337, 36, 8, 10, 134, 226, whiteScript, februeryColor, roundEnd);
  tft.drawSmoothArc(337, 36, 14, 16, 134, 226, whiteScript, februeryColor, roundEnd);
}

void batteryLevel() {
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

void batteryStyle1() {
  tft.drawRoundRect(362, 18, 47, 21, 3, whiteScript);
  tft.drawRoundRect(363, 19, 45, 20, 2, whiteScript);
  tft.drawSmoothArc(408, 28, 1, 4, 180, 359, whiteScript, whiteScript, squareEnd);

  tft.fillRoundRect(366, 21, 7, 16, 1, green_battery);
  tft.fillRoundRect(374, 21, 7, 16, 1, green_battery);
  tft.fillRoundRect(382, 21, 7, 16, 1, green_battery);
  tft.fillRoundRect(390, 21, 7, 16, 1, green_battery);
  tft.fillRoundRect(398, 21, 7, 16, 1, green_battery);
}
void batteryStyle2() {
  tft.drawRoundRect(362, 18, 47, 21, 3, whiteScript);
  tft.drawRoundRect(363, 19, 45, 20, 2, whiteScript);
  tft.drawSmoothArc(408, 28, 1, 4, 180, 359, whiteScript, whiteScript, squareEnd);

  tft.fillRoundRect(366, 21, 39, 16, 1, green_battery);
}
void batteryStyle3() {
  tft.drawRoundRect(362, 18, 47, 21, 3, whiteScript);
  tft.drawRoundRect(363, 20, 45, 20, 2, whiteScript);
  tft.drawSmoothArc(408, 28, 1, 4, 180, 359, whiteScript, whiteScript, squareEnd);

  tft.fillRectHGradient(366, 21, 39, 16, pressureColor1, pressureColor2);
  tft.drawLine(365, 22, 365, 36, pressureColor1);
  tft.drawLine(405, 22, 405, 36, pressureColor2);
} 
void batteryStyle4() {
  tft.drawRoundRect(362, 21, 50, 19, 3, blue_battery);
}

void lockLevel() {
  switch (lockStyle) {
      case 1:
        lockStyle2();
        break;
      default:
        lockStyle1();
  }
}

void lockStyle1() {
  tft.drawSmoothArc(300, 23, 3, 4, 89, 270, whiteScript, blackScript, squareEnd);
  tft.drawLine(296, 24, 296, 28, whiteScript);
  tft.drawLine(297, 24, 297, 28, whiteScript);
  tft.drawLine(303, 24, 303, 28, whiteScript);
  tft.drawLine(304, 24, 304, 28, whiteScript);
  tft.fillRoundRect(295, 28, 11, 12, 2, whiteScript);
}
void lockStyle2() {
  tft.drawSmoothArc(300, 23, 3, 4, 89, 270, whiteScript, blackScript, squareEnd);
  tft.drawLine(296, 24, 296, 26, whiteScript);
  tft.drawLine(297, 24, 297, 26, whiteScript);
  tft.drawLine(303, 24, 303, 26, whiteScript);
  tft.drawLine(304, 24, 304, 26, whiteScript);
  tft.drawLine(294, 27, 306, 27, whiteScript);
  tft.drawLine(294, 28, 306, 28, whiteScript);
  tft.drawLine(294, 29, 294, 32, whiteScript);
  tft.drawLine(295, 29, 295, 32, whiteScript);
  tft.drawLine(294, 38, 306, 38, whiteScript);
  tft.drawLine(294, 39, 306, 39, whiteScript); 
  tft.drawLine(305, 37, 305, 34, whiteScript); 
  tft.drawLine(306, 37, 306, 34, whiteScript); 
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

void dosimeterAnalogic() {
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

void dosimeterDigital() { 
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
} 

void dosimeterMin() { 
  tft.drawLine(32, 208, 32, 213, highValueColor);
  tft.drawLine(33, 208, 33, 213, highValueColor);

  tft.drawLine(432, 208, 432, 213, highValueColor);
  tft.drawLine(433, 208, 433, 213, highValueColor);

  tft.drawLine(65, 208, 65, 212, middleTimeGraph);
  tft.drawLine(98, 208, 98, 212, middleTimeGraph);
  tft.drawLine(132, 208, 132, 212, middleTimeGraph);
  tft.drawLine(165, 208, 165, 212, middleTimeGraph);
  tft.drawLine(198, 208, 198, 212, middleTimeGraph);
  tft.drawLine(232, 208, 232, 212, middleTimeGraph);
  tft.drawLine(265, 208, 265, 212, middleTimeGraph);
  tft.drawLine(298, 208, 298, 212, middleTimeGraph);
  tft.drawLine(332, 208, 332, 212, middleTimeGraph);
  tft.drawLine(365, 208, 365, 212, middleTimeGraph);
  tft.drawLine(398, 208, 398, 212, middleTimeGraph);

  tft.drawPixel(443, 78, redScript);
  tft.drawLine(443, 86, 443, 88, redScript);
  tft.drawLine(443, 96, 443, 98, redScript);
  tft.drawLine(443, 106, 443, 108, redScript);
  tft.drawLine(443, 116, 443, 118, redScript);
  tft.drawLine(443, 126, 443, 128, redScript);
  tft.drawLine(443, 136, 443, 138, redScript);
  tft.drawLine(443, 146, 443, 148, redScript);
  tft.drawLine(443, 156, 443, 158, redScript);
  tft.drawLine(443, 166, 443, 168, redScript);
  tft.drawLine(443, 176, 443, 178, redScript);
  tft.drawLine(443, 186, 443, 188, redScript);
  tft.drawPixel(443, 196, redScript);

  tft.setFreeFont(latoRegular10);
  tft.drawString("10", 450, 185, GFXFF);
  tft.drawString("50", 450, 159, GFXFF);
  tft.drawString("100", 450, 128, GFXFF);
  tft.drawString("500", 450, 82, GFXFF);

  tft.setTextDatum(ML_DATUM);
  tft.setTextColor(whiteScript);
  tft.setFreeFont(latoRegular24);

  tft.drawString("0", 26, 228, GFXFF);
  tft.drawString("59", 418, 228, GFXFF);

  tft.setFreeFont(latoRegular14);

  tft.drawString("5", 61, 225, GFXFF);
  tft.drawString("10", 90, 225, GFXFF);
  tft.drawString("15", 124, 225, GFXFF);
  tft.drawString("20", 157, 225, GFXFF);
  tft.drawString("25", 190, 225, GFXFF);
  tft.drawString("30", 223, 225, GFXFF);
  tft.drawString("35", 257, 225, GFXFF);
  tft.drawString("40", 290, 225, GFXFF);
  tft.drawString("45", 324, 225, GFXFF);
  tft.drawString("50", 357, 225, GFXFF);
  tft.drawString("55", 390, 225, GFXFF);
} 

void dosimeterDay() {
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

  tft.drawPixel(443, 78, redScript);
  tft.drawLine(443, 86, 443, 88, redScript);
  tft.drawLine(443, 96, 443, 98, redScript);
  tft.drawLine(443, 106, 443, 108, redScript);
  tft.drawLine(443, 116, 443, 118, redScript);
  tft.drawLine(443, 126, 443, 128, redScript);
  tft.drawLine(443, 136, 443, 138, redScript);
  tft.drawLine(443, 146, 443, 148, redScript);
  tft.drawLine(443, 156, 443, 158, redScript);
  tft.drawLine(443, 166, 443, 168, redScript);
  tft.drawLine(443, 176, 443, 178, redScript);
  tft.drawLine(443, 186, 443, 188, redScript);
  tft.drawPixel(443, 196, redScript);

  tft.setFreeFont(latoRegular10);
  tft.drawString("100", 450, 185, GFXFF);
  tft.drawString("500", 450, 159, GFXFF);
  tft.drawString("1K", 450, 128, GFXFF);
  tft.drawString("2K", 450, 82, GFXFF);

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

void dosimeterWeek() {
  tft.fillRoundRect(32, 104, 41, 94, 5, icon_11);
  tft.fillRoundRect(92, 104, 41, 94, 5, icon_11);
  tft.fillRoundRect(152, 104, 41, 94, 5, icon_11);
  tft.fillRoundRect(212, 104, 41, 94, 5, icon_11);
  tft.fillRoundRect(272, 104, 41, 94, 5, icon_11);
  tft.fillRoundRect(332, 104, 41, 94, 5, icon_11);
  tft.fillRoundRect(392, 104, 41, 94, 5, icon_11);


  tft.setTextDatum(ML_DATUM);
  tft.setTextColor(whiteScript);
  tft.setFreeFont(latoRegular14);

  tft.drawString("Sun", 41, 225, GFXFF);
  tft.drawString("Mon", 99, 225, GFXFF);
  tft.drawString("Tue", 162, 225, GFXFF);
  tft.drawString("Wed", 218, 225, GFXFF);
  tft.drawString("Thu", 281, 225, GFXFF);
  tft.drawString("Fri", 345, 225, GFXFF);
  tft.drawString("Sat", 403, 225, GFXFF);

  tft.drawPixel(443, 78, redScript);
  tft.drawLine(443, 86, 443, 88, redScript);
  tft.drawLine(443, 96, 443, 98, redScript);
  tft.drawLine(443, 106, 443, 108, redScript);
  tft.drawLine(443, 116, 443, 118, redScript);
  tft.drawLine(443, 126, 443, 128, redScript);
  tft.drawLine(443, 136, 443, 138, redScript);
  tft.drawLine(443, 146, 443, 148, redScript);
  tft.drawLine(443, 156, 443, 158, redScript);
  tft.drawLine(443, 166, 443, 168, redScript);
  tft.drawLine(443, 176, 443, 178, redScript);
  tft.drawLine(443, 186, 443, 188, redScript);
  tft.drawPixel(443, 196, redScript);

  tft.setFreeFont(latoRegular10);
  tft.drawString("100", 450, 185, GFXFF);
  tft.drawString("500", 450, 159, GFXFF);
  tft.drawString("1K", 450, 128, GFXFF);
  tft.drawString("2K", 450, 82, GFXFF);
}

void dosimeterMonth() {
  if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
    monthLengh = 31;
  } else {
    monthLengh = 30;
  }
  if (month == 2) {
    if (year%400 == 0) {
      monthLengh = 29;
    } else if((year%4==0) && (year%100!=0)) {
      monthLengh = 29;
    }else {
      monthLengh = 28;
    }
  }

  tft.drawPixel(443, 78, redScript);
  tft.drawLine(443, 86, 443, 88, redScript);
  tft.drawLine(443, 96, 443, 98, redScript);
  tft.drawLine(443, 106, 443, 108, redScript);
  tft.drawLine(443, 116, 443, 118, redScript);
  tft.drawLine(443, 126, 443, 128, redScript);
  tft.drawLine(443, 136, 443, 138, redScript);
  tft.drawLine(443, 146, 443, 148, redScript);
  tft.drawLine(443, 156, 443, 158, redScript);
  tft.drawLine(443, 166, 443, 168, redScript);
  tft.drawLine(443, 176, 443, 178, redScript);
  tft.drawLine(443, 186, 443, 188, redScript);
  tft.drawPixel(443, 196, redScript);

  tft.setFreeFont(latoRegular10);
  tft.drawString("100", 450, 185, GFXFF);
  tft.drawString("500", 450, 159, GFXFF);
  tft.drawString("1K", 450, 128, GFXFF);
  tft.drawString("2K", 450, 82, GFXFF);  

  switch (monthLengh) {
      case 28: dosimeterday28(); break;
      case 29: dosimeterday29(); break;
      case 30: dosimeterday30(); break;
      case 31: dosimeterday31(); break;
  }








/* 
28DD
  tft.fillRoundRect(32, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(47, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(62, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(77, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(92, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(107, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(122, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(137, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(152, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(167, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(182, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(197, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(212, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(227, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(242, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(257, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(272, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(287, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(302, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(317, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(332, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(347, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(362, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(377, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(392, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(407, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(422, 127, 10, 71, 2, icon_11);

29DD
  tft.fillRoundRect(32, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(46, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(60, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(74, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(88, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(102, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(116, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(130, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(144, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(158, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(172, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(186, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(200, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(214, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(228, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(242, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(256, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(270, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(284, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(298, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(312, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(326, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(340, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(354, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(368, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(382, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(396, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(410, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(424, 127, 10, 71, 2, icon_11);

30DD
  tft.fillRoundRect(32, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(46, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(60, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(74, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(88, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(102, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(116, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(130, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(144, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(158, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(172, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(186, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(200, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(214, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(228, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(242, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(256, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(270, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(284, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(298, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(312, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(326, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(340, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(354, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(368, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(382, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(396, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(410, 127, 10, 71, 2, icon_11);
  tft.fillRoundRect(424, 127, 10, 71, 2, icon_11);




*/
}

void dosimeterday28() {
  tft.drawLine(32, 208, 32, 213, highValueColor);
  tft.drawLine(33, 208, 33, 213, highValueColor);

  tft.drawLine(432, 208, 432, 213, highValueColor);
  tft.drawLine(433, 208, 433, 213, highValueColor);

  tft.drawLine(162, 208, 162, 212, middleTimeGraph);
  tft.drawLine(303, 208, 303, 212, middleTimeGraph);

  tft.setTextDatum(ML_DATUM);
  tft.setTextColor(whiteScript);
  tft.setFreeFont(latoRegular24);

  tft.drawString("0", 26, 228, GFXFF);
  tft.drawString("28", 418, 228, GFXFF);

  tft.setFreeFont(latoRegular14);

  tft.drawString("10", 154, 225, GFXFF);
  tft.drawString("20", 295, 225, GFXFF);

  tft.setFreeFont(latoRegular10);
  tft.drawString("100", 445, 185, GFXFF);
  tft.drawString("500", 445, 159, GFXFF);
  tft.drawString("1K", 445, 128, GFXFF);
  tft.drawString("2K", 445, 82, GFXFF);
}

void dosimeterday29() {
  tft.drawLine(32, 208, 32, 213, highValueColor);
  tft.drawLine(33, 208, 33, 213, highValueColor);

  tft.drawLine(432, 208, 432, 213, highValueColor);
  tft.drawLine(433, 208, 433, 213, highValueColor);

  tft.drawLine(162, 208, 162, 212, middleTimeGraph);
  tft.drawLine(303, 208, 303, 212, middleTimeGraph);

  tft.setTextDatum(ML_DATUM);
  tft.setTextColor(whiteScript);
  tft.setFreeFont(latoRegular24);
  tft.drawString("0", 26, 228, GFXFF);
  tft.drawString("29", 418, 228, GFXFF);

  tft.setFreeFont(latoRegular14);
  tft.drawString("10", 154, 225, GFXFF);
  tft.drawString("20", 295, 225, GFXFF);

  tft.setFreeFont(latoRegular10);
  tft.drawString("100", 445, 185, GFXFF);
  tft.drawString("500", 445, 159, GFXFF);
  tft.drawString("1K", 445, 128, GFXFF);
  tft.drawString("2K", 445, 82, GFXFF);
}

void dosimeterday30() {
  tft.drawLine(32, 208, 32, 213, highValueColor);
  tft.drawLine(33, 208, 33, 213, highValueColor);

  tft.drawLine(432, 208, 432, 213, highValueColor);
  tft.drawLine(433, 208, 433, 213, highValueColor);

  tft.drawLine(162, 208, 162, 212, middleTimeGraph);
  tft.drawLine(303, 208, 303, 212, middleTimeGraph);

  tft.setTextDatum(ML_DATUM);
  tft.setTextColor(whiteScript);
  tft.setFreeFont(latoRegular24);
  tft.drawString("0", 26, 228, GFXFF);
  tft.drawString("30", 418, 228, GFXFF);

  tft.setFreeFont(latoRegular14);
  tft.drawString("10", 154, 225, GFXFF);
  tft.drawString("20", 295, 225, GFXFF);

  tft.setFreeFont(latoRegular10);
  tft.drawString("100", 445, 185, GFXFF);
  tft.drawString("500", 445, 159, GFXFF);
  tft.drawString("1K", 445, 128, GFXFF);
  tft.drawString("2K", 445, 82, GFXFF);
}

void dosimeterday31() {
  tft.drawLine(32, 208, 32, 213, highValueColor);
  tft.drawLine(33, 208, 33, 213, highValueColor);

  tft.drawLine(432, 208, 432, 213, highValueColor);
  tft.drawLine(433, 208, 433, 213, highValueColor);

  tft.drawLine(162, 208, 162, 212, middleTimeGraph);
  tft.drawLine(303, 208, 303, 212, middleTimeGraph);

  tft.setTextDatum(ML_DATUM);
  tft.setTextColor(whiteScript);
  tft.setFreeFont(latoRegular24);
  tft.drawString("0", 26, 228, GFXFF);
  tft.drawString("31", 418, 228, GFXFF);

  tft.setFreeFont(latoRegular14);
  tft.drawString("10", 154, 225, GFXFF);
  tft.drawString("20", 295, 225, GFXFF);

  tft.setFreeFont(latoRegular10);
  tft.drawString("100", 445, 185, GFXFF);
  tft.drawString("500", 445, 159, GFXFF);
  tft.drawString("1K", 445, 128, GFXFF);
  tft.drawString("2K", 445, 82, GFXFF);
}

void dosimeterYear() { 
  tft.fillRoundRect(32, 104, 15, 94, 5, januaryColor);
  tft.fillRoundRect(67, 104, 15, 94, 5, februeryColor);
  tft.fillRoundRect(102, 104, 15, 94, 5, marchColor);
  tft.fillRoundRect(137, 104, 15, 94, 5, aprilColor);
  tft.fillRoundRect(172, 104, 15, 94, 5, mayColor);
  tft.fillRoundRect(207, 104, 15, 94, 5, juneColor);
  tft.fillRoundRect(242, 104, 15, 94, 5, julyColor);
  tft.fillRoundRect(277, 104, 15, 94, 5, augustColor);
  tft.fillRoundRect(312, 104, 15, 94, 5, septemberColor);
  tft.fillRoundRect(347, 104, 15, 94, 5, octoberColor);
  tft.fillRoundRect(382, 104, 15, 94, 5, novemberColor);
  tft.fillRoundRect(417, 104, 15, 94, 5, decemberColor);

  tft.drawLine(38, 208, 38, 212, middleTimeGraph);
  tft.drawLine(74, 208, 74, 212, middleTimeGraph);
  tft.drawLine(108, 208, 108, 212, middleTimeGraph);
  tft.drawLine(144, 208, 144, 212, middleTimeGraph);
  tft.drawLine(178, 208, 178, 212, middleTimeGraph);
  tft.drawLine(214, 208, 214, 212, middleTimeGraph);
  tft.drawLine(248, 208, 248, 212, middleTimeGraph);
  tft.drawLine(284, 208, 284, 212, middleTimeGraph);
  tft.drawLine(319, 208, 319, 212, middleTimeGraph);
  tft.drawLine(354, 208, 354, 212, middleTimeGraph);
  tft.drawLine(389, 208, 389, 212, middleTimeGraph);
  tft.drawLine(424, 208, 424, 212, middleTimeGraph);

  tft.drawPixel(443, 78, redScript);
  tft.drawLine(443, 86, 443, 88, redScript);
  tft.drawLine(443, 96, 443, 98, redScript);
  tft.drawLine(443, 106, 443, 108, redScript);
  tft.drawLine(443, 116, 443, 118, redScript);
  tft.drawLine(443, 126, 443, 128, redScript);
  tft.drawLine(443, 136, 443, 138, redScript);
  tft.drawLine(443, 146, 443, 148, redScript);
  tft.drawLine(443, 156, 443, 158, redScript);
  tft.drawLine(443, 166, 443, 168, redScript);
  tft.drawLine(443, 176, 443, 178, redScript);
  tft.drawLine(443, 186, 443, 188, redScript);
  tft.drawPixel(443, 196, redScript);

  tft.setFreeFont(latoRegular10);
  tft.drawString("100", 450, 185, GFXFF);
  tft.drawString("500", 450, 159, GFXFF);
  tft.drawString("1K", 450, 128, GFXFF);
  tft.drawString("2K", 450, 82, GFXFF);

  tft.setTextDatum(ML_DATUM);
  tft.setTextColor(whiteScript);
  tft.setFreeFont(latoRegular14);
  tft.drawString("1", 34, 225, GFXFF);
  tft.drawString("2", 70, 225, GFXFF);
  tft.drawString("3", 104, 225, GFXFF);
  tft.drawString("4", 140, 225, GFXFF);
  tft.drawString("5", 174, 225, GFXFF);
  tft.drawString("6", 210, 225, GFXFF);
  tft.drawString("7", 244, 225, GFXFF);
  tft.drawString("8", 280, 225, GFXFF);
  tft.drawString("9", 315, 225, GFXFF);
  tft.drawString("10", 346, 225, GFXFF);
  tft.drawString("11", 381, 225, GFXFF);
  tft.drawString("12", 417, 225, GFXFF);
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
  calendarLoader();
  seasons();
  date();
}

void calendarLoader() {
  if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
    monthLengh = 31;
  } else {
    monthLengh = 30;
  }
  if (month == 2) {
    if (year%400 == 0) {
      monthLengh = 29;
    } else if((year%4==0) && (year%100!=0)) {
      monthLengh = 29;
    }else {
      monthLengh = 28;
    }
  }

  if (day == 1) {
    startDay = startDayOfWeek(year, month, day);
  }
  tft.setTextDatum(MC_DATUM);

  switch (startDay) {
    case 0:
      newWeekStart = 1;
      tft.setTextColor(blackScript);
      tft.drawString("1", 154, 113, GFXFF);
      tft.drawString("7", 332, 113, GFXFF);
      tft.setTextColor(whiteScript);
      tft.drawString("2", 184, 113, GFXFF);
      tft.drawString("3", 215, 113, GFXFF);
      tft.drawString("4", 244, 113, GFXFF);
      tft.drawString("5", 275, 113, GFXFF);
      tft.drawString("6", 304, 113, GFXFF);
    break;
    case 1:
      newWeekStart = 1;
      tft.setTextColor(whiteScript);
      tft.drawString("1", 184, 113, GFXFF);
      tft.drawString("2", 215, 113, GFXFF);
      tft.drawString("3", 244, 113, GFXFF);
      tft.drawString("4", 275, 113, GFXFF);
      tft.drawString("5", 304, 113, GFXFF);
      tft.setTextColor(blackScript);
      tft.drawString("6", 332, 113, GFXFF);
    break;
    case 2:
      newWeekStart = 1;
      tft.setTextColor(whiteScript);
      tft.drawString("1", 215, 113, GFXFF);
      tft.drawString("2", 244, 113, GFXFF);
      tft.drawString("3", 275, 113, GFXFF);
      tft.drawString("4", 304, 113, GFXFF);
      tft.setTextColor(blackScript);
      tft.drawString("5", 332, 113, GFXFF);
    break;
    case 3:
      newWeekStart = 1;
      tft.setTextColor(whiteScript);
      tft.drawString("1", 244, 113, GFXFF);
      tft.drawString("2", 275, 113, GFXFF);
      tft.drawString("3", 304, 113, GFXFF);
      tft.setTextColor(blackScript);
      tft.drawString("4", 332, 113, GFXFF);
    break;
    case 4:
      newWeekStart = 1;
      tft.setTextColor(whiteScript);
      tft.drawString("1", 275, 113, GFXFF);
      tft.drawString("2", 304, 113, GFXFF);
      tft.setTextColor(blackScript);
      tft.drawString("3", 332, 113, GFXFF);
    break;
    case 5:
      newWeekStart = 1;
      if (monthLengh == 28 || monthLengh == 30) {
        tft.setTextColor(whiteScript);
        tft.drawString("1", 304, 113, GFXFF);
        tft.setTextColor(blackScript);
        tft.drawString("2", 332, 113, GFXFF);
      }
      if (monthLengh == 31) {
        tft.setTextColor(whiteScript);
        tft.drawString("1", 304, 113, GFXFF);
        tft.setTextColor(blackScript);
        tft.drawString("2", 332, 113, GFXFF);
      }
    break;
    case 6:
      newWeekStart = 1;
      if (monthLengh == 28) {
        tft.setTextColor(blackScript);
        tft.drawString("1", 332, 113, GFXFF);
      };
      if (monthLengh == 30) {
        tft.setTextColor(blackScript);
        tft.drawString("1", 332, 113, GFXFF);
      };
      if (monthLengh == 31) {
        tft.setTextColor(blackScript);
        tft.drawString("1", 332, 113, GFXFF);
      };
    break;
  }

  // 1 - Sunday OPERACIONAL
  if ((startDay == 0) && (newWeekStart == 1)) {
    newDayStart = 6 - startDay;
    for (int weekTwo = 0; weekTwo < 8; weekTwo++) {
      newDayStart = newDayStart + 1;
      String StringDayWeek = String(newDayStart);
      if (monthLengh >= newDayStart) {
        switch (weekTwo) {
          case 1:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 154, 138, GFXFF);
            weekYear = weekYear + 1;
            newWeekStart = (newWeekStart + 1);
          break;
          case 2:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 184, 138, GFXFF);
          break;
          case 3:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 215, 138, GFXFF);
          break;
          case 4:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 244, 138, GFXFF);
          break;
          case 5:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 275, 138, GFXFF);
          break;
          case 6:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 304, 138, GFXFF);
          break;
          case 7:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 332, 138, GFXFF);
          break;
        }
      }
    }
  }
  if ((startDay == 0) && (newWeekStart == 2)) {
    newDayStart = 13 - startDay;
    newWeekStart = newWeekStart + 1;
    for (int weekThree = 0; weekThree < 8; weekThree++) {
      newDayStart = newDayStart + 1;
      String StringDayWeek = String(newDayStart);
      if (monthLengh >= newDayStart) {
        switch (weekThree) {
          case 1:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 154, 163, GFXFF);
            weekYear = weekYear + 1;
          break;
          case 2:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 184, 163, GFXFF);
          break;
          case 3:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 215, 163, GFXFF);
          break;
          case 4:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 244, 163, GFXFF);
          break;
          case 5:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 275, 163, GFXFF);
          break;
          case 6:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 304, 163, GFXFF);
          break;
          case 7:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 332, 163, GFXFF);
          break;
        }
      }
    }
  }
  if ((startDay == 0) && (newWeekStart == 3)) {
    newDayStart = 20 - startDay;
    newWeekStart = newWeekStart + 1;
    for (int weekFour = 0; weekFour < 8; weekFour++) {
      newDayStart = newDayStart + 1;
      String StringDayWeek = String(newDayStart);
      if (monthLengh >= newDayStart) {
        switch (weekFour) {
          case 1:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 154, 188, GFXFF);
            weekYear = weekYear + 1;
          break;
          case 2:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 184, 188, GFXFF);
          break;
          case 3:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 215, 188, GFXFF);
          break;
          case 4:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 244, 188, GFXFF);
          break;
          case 5:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 275, 188, GFXFF);
          break;
          case 6:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 304, 188, GFXFF);
          break;
          case 7:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 332, 188, GFXFF);
          break;
        }
      }
    }
  }
  if ((startDay == 0) && (newWeekStart == 4)) {
    newDayStart = 27 - startDay;
    newWeekStart = newWeekStart + 1;
    for (int weekFive = 0; weekFive < 8; weekFive++) {
      newDayStart = newDayStart + 1;
      String StringDayWeek = String(newDayStart);
      if (monthLengh >= newDayStart) {
        switch (weekFive) {
          case 1:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 154, 213, GFXFF);
            weekYear = weekYear + 1;
          break;
          case 2:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 184, 213, GFXFF);
          break;
          case 3:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 215, 213, GFXFF);
          break;
          case 4:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 244, 213, GFXFF);
          break;
          case 5:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 275, 213, GFXFF);
          break;
          case 6:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 304, 213, GFXFF);
          break;
          case 7:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 332, 213, GFXFF);
          break;
        }
      }
    }
  }
  if ((startDay == 0) && (newWeekStart == 5)) {
    newDayStart = 30 - startDay;
    newWeekStart = newWeekStart + 1;
    for (int weekSix = 0; weekSix < 3; weekSix++) {
      newDayStart = newDayStart + 1;
      String StringDayWeek = String(newDayStart);
      if (monthLengh >= newDayStart) {
        switch (weekSix) {
          case 1:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 154, 233, GFXFF);
            weekYear = weekYear + 1;
          break;
          case 2:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 184, 233, GFXFF);
          break;
        }
      }
    }
  }

// 1- Monday OPERACIONAL
  if ((startDay == 1) && (newWeekStart == 1)) {
    newDayStart = 6 - startDay;
    for (int weekTwo = 0; weekTwo < 8; weekTwo++) {
      newDayStart = newDayStart + 1;
      String StringDayWeek = String(newDayStart);
      if (monthLengh >= newDayStart) {
        switch (weekTwo) {
          case 1:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 154, 138, GFXFF);
            weekYear = weekYear + 1;
            newWeekStart = (newWeekStart + 1);
          break;
          case 2:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 184, 138, GFXFF);
          break;
          case 3:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 215, 138, GFXFF);
          break;
          case 4:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 244, 138, GFXFF);
          break;
          case 5:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 275, 138, GFXFF);
          break;
          case 6:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 304, 138, GFXFF);
          break;
          case 7:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 332, 138, GFXFF);
          break;
        }
      }
    }
  }
  if ((startDay == 1) && (newWeekStart == 2)) {
    newDayStart = 13 - startDay;
    newWeekStart = newWeekStart + 1;
    for (int weekThree = 0; weekThree < 8; weekThree++) {
      newDayStart = newDayStart + 1;
      String StringDayWeek = String(newDayStart);
      if (monthLengh >= newDayStart) {
        switch (weekThree) {
          case 1:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 154, 163, GFXFF);
            weekYear = weekYear + 1;
          break;
          case 2:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 184, 163, GFXFF);
          break;
          case 3:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 215, 163, GFXFF);
          break;
          case 4:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 244, 163, GFXFF);
          break;
          case 5:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 275, 163, GFXFF);
          break;
          case 6:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 304, 163, GFXFF);
          break;
          case 7:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 332, 163, GFXFF);
          break;
        }
      }
    }
  }
  if ((startDay == 1) && (newWeekStart == 3)) {
    newDayStart = 20 - startDay;
    newWeekStart = newWeekStart + 1;
    for (int weekFour = 0; weekFour < 8; weekFour++) {
      newDayStart = newDayStart + 1;
      String StringDayWeek = String(newDayStart);
      if (monthLengh >= newDayStart) {
        switch (weekFour) {
          case 1:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 154, 188, GFXFF);
            weekYear = weekYear + 1;
          break;
          case 2:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 184, 188, GFXFF);
          break;
          case 3:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 215, 188, GFXFF);
          break;
          case 4:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 244, 188, GFXFF);
          break;
          case 5:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 275, 188, GFXFF);
          break;
          case 6:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 304, 188, GFXFF);
          break;
          case 7:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 332, 188, GFXFF);
          break;
        }
      }
    }
  }
  if ((startDay == 1) && (newWeekStart == 4)) {
    newDayStart = 27 - startDay;
    newWeekStart = newWeekStart + 1;
    for (int weekFive = 0; weekFive < 8; weekFive++) {
      newDayStart = newDayStart + 1;
      String StringDayWeek = String(newDayStart);
      if (monthLengh >= newDayStart) {
        switch (weekFive) {
          case 1:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 154, 213, GFXFF);
            weekYear = weekYear + 1;
          break;
          case 2:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 184, 213, GFXFF);
          break;
          case 3:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 215, 213, GFXFF);
          break;
          case 4:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 244, 213, GFXFF);
          break;
          case 5:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 275, 213, GFXFF);
          break;
          case 6:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 304, 213, GFXFF);
          break;
          case 7:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 332, 213, GFXFF);
          break;
        }
      }
    }
  }
  if ((startDay == 1) && (newWeekStart == 5)) {
    newDayStart = 34 - startDay;
    newWeekStart = newWeekStart + 1;
    for (int weekSix = 0; weekSix < 3; weekSix++) {
      newDayStart = newDayStart + 1;
      String StringDayWeek = String(newDayStart);
      if (monthLengh >= newDayStart) {
        switch (weekSix) {
          case 1:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 154, 238, GFXFF);
            weekYear = weekYear + 1;
          break;
          case 2:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 184, 238, GFXFF);
          break;
        }
      }
    }
  }

// 1 - Tuesday OPERACIONAL
  if ((startDay == 2) && (newWeekStart == 1)) {
    newDayStart = 6 - startDay;
    for (int weekTwo = 0; weekTwo < 8; weekTwo++) {
      newDayStart = newDayStart + 1;
      String StringDayWeek = String(newDayStart);
      if (monthLengh >= newDayStart) {
        switch (weekTwo) {
          case 1:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 154, 138, GFXFF);
            weekYear = weekYear + 1;
            newWeekStart = (newWeekStart + 1);
          break;
          case 2:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 184, 138, GFXFF);
          break;
          case 3:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 215, 138, GFXFF);
          break;
          case 4:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 244, 138, GFXFF);
          break;
          case 5:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 275, 138, GFXFF);
          break;
          case 6:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 304, 138, GFXFF);
          break;
          case 7:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 332, 138, GFXFF);
          break;
        }
      }
    }
  }
  if ((startDay == 2) && (newWeekStart == 2)) {
    newDayStart = 13 - startDay;
    newWeekStart = newWeekStart + 1;
    for (int weekThree = 0; weekThree < 8; weekThree++) {
      newDayStart = newDayStart + 1;
      String StringDayWeek = String(newDayStart);
      if (monthLengh >= newDayStart) {
        switch (weekThree) {
          case 1:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 154, 163, GFXFF);
            weekYear = weekYear + 1;
          break;
          case 2:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 184, 163, GFXFF);
          break;
          case 3:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 215, 163, GFXFF);
          break;
          case 4:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 244, 163, GFXFF);
          break;
          case 5:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 275, 163, GFXFF);
          break;
          case 6:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 304, 163, GFXFF);
          break;
          case 7:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 332, 163, GFXFF);
          break;
        }
      }
    }
  }
  if ((startDay == 2) && (newWeekStart == 3)) {
    newDayStart = 20 - startDay;
    newWeekStart = newWeekStart + 1;
    for (int weekFour = 0; weekFour < 8; weekFour++) {
      newDayStart = newDayStart + 1;
      String StringDayWeek = String(newDayStart);
      if (monthLengh >= newDayStart) {
        switch (weekFour) {
          case 1:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 154, 188, GFXFF);
            weekYear = weekYear + 1;
          break;
          case 2:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 184, 188, GFXFF);
          break;
          case 3:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 215, 188, GFXFF);
          break;
          case 4:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 244, 188, GFXFF);
          break;
          case 5:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 275, 188, GFXFF);
          break;
          case 6:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 304, 188, GFXFF);
          break;
          case 7:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 332, 188, GFXFF);
          break;
        }
      }
    }
  }
  if ((startDay == 2) && (newWeekStart == 4)) {
    newDayStart = 27 - startDay;
    newWeekStart = newWeekStart + 1;
    for (int weekFive = 0; weekFive < 8; weekFive++) {
      newDayStart = newDayStart + 1;
      String StringDayWeek = String(newDayStart);
      if (monthLengh >= newDayStart) {
        switch (weekFive) {
          case 1:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 154, 213, GFXFF);
            weekYear = weekYear + 1;
          break;
          case 2:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 184, 213, GFXFF);
          break;
          case 3:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 215, 213, GFXFF);
          break;
          case 4:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 244, 213, GFXFF);
          break;
          case 5:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 275, 213, GFXFF);
          break;
          case 6:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 304, 213, GFXFF);
          break;
          case 7:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 332, 213, GFXFF);
          break;
        }
      }
    }
  }
  if ((startDay == 2) && (newWeekStart == 5)) {
    newDayStart = 34 - startDay;
    newWeekStart = newWeekStart + 1;
    for (int weekSix = 0; weekSix < 3; weekSix++) {
      newDayStart = newDayStart + 1;
      String StringDayWeek = String(newDayStart);
      if (monthLengh >= newDayStart) {
        switch (weekSix) {
          case 1:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 154, 238, GFXFF);
            weekYear = weekYear + 1;
          break;
          case 2:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 184, 238, GFXFF);
          break;
        }
      }
    }
  }

// 1 - Wednesday OPERACIONAL
  if ((startDay == 3) && (newWeekStart == 1)) {
    newDayStart = 6 - startDay;
    for (int weekTwo = 0; weekTwo < 8; weekTwo++) {
      newDayStart = newDayStart + 1;
      String StringDayWeek = String(newDayStart);
      if (monthLengh >= newDayStart) {
        switch (weekTwo) {
          case 1:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 154, 138, GFXFF);
            weekYear = weekYear + 1;
            newWeekStart = (newWeekStart + 1);
          break;
          case 2:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 184, 138, GFXFF);
          break;
          case 3:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 215, 138, GFXFF);
          break;
          case 4:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 244, 138, GFXFF);
          break;
          case 5:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 275, 138, GFXFF);
          break;
          case 6:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 304, 138, GFXFF);
          break;
          case 7:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 332, 138, GFXFF);
          break;
        }
      }
    }
  }
  if ((startDay == 3) && (newWeekStart == 2)) {
    newDayStart = 13 - startDay;
    newWeekStart = newWeekStart + 1;
    for (int weekThree = 0; weekThree < 8; weekThree++) {
      newDayStart = newDayStart + 1;
      String StringDayWeek = String(newDayStart);
      if (monthLengh >= newDayStart) {
        switch (weekThree) {
          case 1:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 154, 163, GFXFF);
            weekYear = weekYear + 1;
          break;
          case 2:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 184, 163, GFXFF);
          break;
          case 3:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 215, 163, GFXFF);
          break;
          case 4:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 244, 163, GFXFF);
          break;
          case 5:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 275, 163, GFXFF);
          break;
          case 6:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 304, 163, GFXFF);
          break;
          case 7:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 332, 163, GFXFF);
          break;
        }
      }
    }
  }
  if ((startDay == 3) && (newWeekStart == 3)) {
    newDayStart = 20 - startDay;
    newWeekStart = newWeekStart + 1;
    for (int weekFour = 0; weekFour < 8; weekFour++) {
      newDayStart = newDayStart + 1;
      String StringDayWeek = String(newDayStart);
      if (monthLengh >= newDayStart) {
        switch (weekFour) {
          case 1:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 154, 188, GFXFF);
            weekYear = weekYear + 1;
          break;
          case 2:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 184, 188, GFXFF);
          break;
          case 3:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 215, 188, GFXFF);
          break;
          case 4:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 244, 188, GFXFF);
          break;
          case 5:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 275, 188, GFXFF);
          break;
          case 6:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 304, 188, GFXFF);
          break;
          case 7:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 332, 188, GFXFF);
          break;
        }
      }
    }
  }
  if ((startDay == 3) && (newWeekStart == 4)) {
    newDayStart = 27 - startDay;
    newWeekStart = newWeekStart + 1;
    for (int weekFive = 0; weekFive < 8; weekFive++) {
      newDayStart = newDayStart + 1;
      String StringDayWeek = String(newDayStart);
      if (monthLengh >= newDayStart) {
        switch (weekFive) {
          case 1:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 154, 213, GFXFF);
            weekYear = weekYear + 1;
          break;
          case 2:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 184, 213, GFXFF);
          break;
          case 3:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 215, 213, GFXFF);
          break;
          case 4:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 244, 213, GFXFF);
          break;
          case 5:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 275, 213, GFXFF);
          break;
          case 6:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 304, 213, GFXFF);
          break;
          case 7:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 332, 213, GFXFF);
          break;
        }
      }
    }
  }
  if ((startDay == 3) && (newWeekStart == 5)) {
    newDayStart = 34 - startDay;
    newWeekStart = newWeekStart + 1;
    for (int weekSix = 0; weekSix < 3; weekSix++) {
      newDayStart = newDayStart + 1;
      String StringDayWeek = String(newDayStart);
      if (monthLengh >= newDayStart) {
        switch (weekSix) {
          case 1:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 154, 238, GFXFF);
            weekYear = weekYear + 1;
          break;
          case 2:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 184, 238, GFXFF);
          break;
        }
      }
    }
  }

// 1 -Thuesday OPERACIONAL
  if ((startDay == 4) && (newWeekStart == 1)) {
    newDayStart = 6 - startDay;
    for (int weekTwo = 0; weekTwo < 8; weekTwo++) {
      newDayStart = newDayStart + 1;
      String StringDayWeek = String(newDayStart);
      if (monthLengh >= newDayStart) {
        switch (weekTwo) {
          case 1:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 154, 138, GFXFF);
            weekYear = weekYear + 1;
            newWeekStart = (newWeekStart + 1);
          break;
          case 2:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 184, 138, GFXFF);
          break;
          case 3:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 215, 138, GFXFF);
          break;
          case 4:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 244, 138, GFXFF);
          break;
          case 5:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 275, 138, GFXFF);
          break;
          case 6:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 304, 138, GFXFF);
          break;
          case 7:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 332, 138, GFXFF);
          break;
        }
      }
    }
  }
  if ((startDay == 4) && (newWeekStart == 2)) {
    newDayStart = 13 - startDay;
    newWeekStart = newWeekStart + 1;
    for (int weekThree = 0; weekThree < 8; weekThree++) {
      newDayStart = newDayStart + 1;
      String StringDayWeek = String(newDayStart);
      if (monthLengh >= newDayStart) {
        switch (weekThree) {
          case 1:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 154, 163, GFXFF);
            weekYear = weekYear + 1;
          break;
          case 2:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 184, 163, GFXFF);
          break;
          case 3:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 215, 163, GFXFF);
          break;
          case 4:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 244, 163, GFXFF);
          break;
          case 5:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 275, 163, GFXFF);
          break;
          case 6:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 304, 163, GFXFF);
          break;
          case 7:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 332, 163, GFXFF);
          break;
        }
      }
    }
  }
  if ((startDay == 4) && (newWeekStart == 3)) {
    newDayStart = 20 - startDay;
    newWeekStart = newWeekStart + 1;
    for (int weekFour = 0; weekFour < 8; weekFour++) {
      newDayStart = newDayStart + 1;
      String StringDayWeek = String(newDayStart);
      if (monthLengh >= newDayStart) {
        switch (weekFour) {
          case 1:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 154, 188, GFXFF);
            weekYear = weekYear + 1;
          break;
          case 2:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 184, 188, GFXFF);
          break;
          case 3:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 215, 188, GFXFF);
          break;
          case 4:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 244, 188, GFXFF);
          break;
          case 5:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 275, 188, GFXFF);
          break;
          case 6:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 304, 188, GFXFF);
          break;
          case 7:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 332, 188, GFXFF);
          break;
        }
      }
    }
  }
  if ((startDay == 4) && (newWeekStart == 4)) {
    newDayStart = 27 - startDay;
    newWeekStart = newWeekStart + 1;
    for (int weekFive = 0; weekFive < 8; weekFive++) {
      newDayStart = newDayStart + 1;
      String StringDayWeek = String(newDayStart);
      if (monthLengh >= newDayStart) {
        switch (weekFive) {
          case 1:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 154, 213, GFXFF);
            weekYear = weekYear + 1;
          break;
          case 2:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 184, 213, GFXFF);
          break;
          case 3:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 215, 213, GFXFF);
          break;
          case 4:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 244, 213, GFXFF);
          break;
          case 5:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 275, 213, GFXFF);
          break;
          case 6:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 304, 213, GFXFF);
          break;
          case 7:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 332, 213, GFXFF);
          break;
        }
      }
    }
  }
  if ((startDay == 4) && (newWeekStart == 5)) {
    newDayStart = 34 - startDay;
    newWeekStart = newWeekStart + 1;
    for (int weekSix = 0; weekSix < 3; weekSix++) {
      newDayStart = newDayStart + 1;
      String StringDayWeek = String(newDayStart);
      if (monthLengh >= newDayStart) {
        switch (weekSix) {
          case 1:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 154, 238, GFXFF);
            weekYear = weekYear + 1;
          break;
          case 2:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 184, 238, GFXFF);
          break;
        }
      }
    }
  }

// 1 - friday OPERACIONAL
  if ((startDay == 5) && (newWeekStart == 1)) {
    newDayStart = 6 - startDay;
    for (int weekTwo = 0; weekTwo < 8; weekTwo++) {
      newDayStart = newDayStart + 1;
      String StringDayWeek = String(newDayStart);
      if (monthLengh >= newDayStart) {
        switch (weekTwo) {
          case 1:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 154, 138, GFXFF);
            weekYear = weekYear + 1;
            newWeekStart = (newWeekStart + 1);
          break;
          case 2:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 184, 138, GFXFF);
          break;
          case 3:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 215, 138, GFXFF);
          break;
          case 4:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 244, 138, GFXFF);
          break;
          case 5:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 275, 138, GFXFF);
          break;
          case 6:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 304, 138, GFXFF);
          break;
          case 7:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 332, 138, GFXFF);
          break;
        }
      }
    }
  }
  if ((startDay == 5) && (newWeekStart == 2)) {
    newDayStart = 13 - startDay;
    newWeekStart = newWeekStart + 1;
    for (int weekThree = 0; weekThree < 8; weekThree++) {
      newDayStart = newDayStart + 1;
      String StringDayWeek = String(newDayStart);
      if (monthLengh >= newDayStart) {
        switch (weekThree) {
          case 1:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 154, 163, GFXFF);
            weekYear = weekYear + 1;
          break;
          case 2:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 184, 163, GFXFF);
          break;
          case 3:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 215, 163, GFXFF);
          break;
          case 4:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 244, 163, GFXFF);
          break;
          case 5:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 275, 163, GFXFF);
          break;
          case 6:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 304, 163, GFXFF);
          break;
          case 7:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 332, 163, GFXFF);
          break;
        }
      }
    }
  }
  if ((startDay == 5) && (newWeekStart == 3)) {
    newDayStart = 20 - startDay;
    newWeekStart = newWeekStart + 1;
    for (int weekFour = 0; weekFour < 8; weekFour++) {
      newDayStart = newDayStart + 1;
      String StringDayWeek = String(newDayStart);
      if (monthLengh >= newDayStart) {
        switch (weekFour) {
          case 1:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 154, 188, GFXFF);
            weekYear = weekYear + 1;
          break;
          case 2:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 184, 188, GFXFF);
          break;
          case 3:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 215, 188, GFXFF);
          break;
          case 4:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 244, 188, GFXFF);
          break;
          case 5:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 275, 188, GFXFF);
          break;
          case 6:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 304, 188, GFXFF);
          break;
          case 7:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 332, 188, GFXFF);
          break;
        }
      }
    }
  }
  if ((startDay == 5) && (newWeekStart == 4)) {
    newDayStart = 27 - startDay;
    newWeekStart = newWeekStart + 1;
    for (int weekFive = 0; weekFive < 8; weekFive++) {
      newDayStart = newDayStart + 1;
      String StringDayWeek = String(newDayStart);
      if (monthLengh >= newDayStart) {
        switch (weekFive) {
          case 1:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 154, 213, GFXFF);
            weekYear = weekYear + 1;
          break;
          case 2:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 184, 213, GFXFF);
          break;
          case 3:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 215, 213, GFXFF);
          break;
          case 4:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 244, 213, GFXFF);
          break;
          case 5:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 275, 213, GFXFF);
          break;
          case 6:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 304, 213, GFXFF);
          break;
          case 7:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 332, 213, GFXFF);
          break;
        }
      }
    }
  }
  if ((startDay == 5) && (newWeekStart == 5)) {
    newDayStart = 34 - startDay;
    newWeekStart = newWeekStart + 1;
    for (int weekSix = 0; weekSix < 3; weekSix++) {
      newDayStart = newDayStart + 1;
      String StringDayWeek = String(newDayStart);
      if (monthLengh >= newDayStart) {
        switch (weekSix) {
          case 1:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 154, 238, GFXFF);
            weekYear = weekYear + 1;
          break;
          case 2:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 184, 238, GFXFF);
          break;
        }
      }
    }
  }

// 1 - saturday OPERACIONAL
  if ((startDay == 6) && (newWeekStart == 1)) {
    newDayStart = 6 - startDay;
    for (int weekTwo = 0; weekTwo < 8; weekTwo++) {
      newDayStart = newDayStart + 1;
      String StringDayWeek = String(newDayStart);
      if (monthLengh >= newDayStart) {
        switch (weekTwo) {
          case 1:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 154, 138, GFXFF);
            weekYear = weekYear + 1;
            newWeekStart = (newWeekStart + 1);
          break;
          case 2:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 184, 138, GFXFF);
          break;
          case 3:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 215, 138, GFXFF);
          break;
          case 4:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 244, 138, GFXFF);
          break;
          case 5:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 275, 138, GFXFF);
          break;
          case 6:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 304, 138, GFXFF);
          break;
          case 7:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 332, 138, GFXFF);
          break;
        }
      }
    }
  }
  if ((startDay == 6) && (newWeekStart == 2)) {
    newDayStart = 13 - startDay;
    newWeekStart = newWeekStart + 1;
    for (int weekThree = 0; weekThree < 8; weekThree++) {
      newDayStart = newDayStart + 1;
      String StringDayWeek = String(newDayStart);
      if (monthLengh >= newDayStart) {
        switch (weekThree) {
          case 1:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 154, 163, GFXFF);
            weekYear = weekYear + 1;
          break;
          case 2:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 184, 163, GFXFF);
          break;
          case 3:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 215, 163, GFXFF);
          break;
          case 4:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 244, 163, GFXFF);
          break;
          case 5:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 275, 163, GFXFF);
          break;
          case 6:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 304, 163, GFXFF);
          break;
          case 7:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 332, 163, GFXFF);
          break;
        }
      }
    }
  }
  if ((startDay == 6) && (newWeekStart == 3)) {
    newDayStart = 20 - startDay;
    newWeekStart = newWeekStart + 1;
    for (int weekFour = 0; weekFour < 8; weekFour++) {
      newDayStart = newDayStart + 1;
      String StringDayWeek = String(newDayStart);
      if (monthLengh >= newDayStart) {
        switch (weekFour) {
          case 1:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 154, 188, GFXFF);
            weekYear = weekYear + 1;
          break;
          case 2:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 184, 188, GFXFF);
          break;
          case 3:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 215, 188, GFXFF);
          break;
          case 4:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 244, 188, GFXFF);
          break;
          case 5:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 275, 188, GFXFF);
          break;
          case 6:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 304, 188, GFXFF);
          break;
          case 7:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 332, 188, GFXFF);
          break;
        }
      }
    }
  }
  if ((startDay == 6) && (newWeekStart == 4)) {
    newDayStart = 27 - startDay;
    newWeekStart = newWeekStart + 1;
    for (int weekFive = 0; weekFive < 8; weekFive++) {
      newDayStart = newDayStart + 1;
      String StringDayWeek = String(newDayStart);
      if (monthLengh >= newDayStart) {
        switch (weekFive) {
          case 1:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 154, 213, GFXFF);
            weekYear = weekYear + 1;
          break;
          case 2:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 184, 213, GFXFF);
          break;
          case 3:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 215, 213, GFXFF);
          break;
          case 4:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 244, 213, GFXFF);
          break;
          case 5:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 275, 213, GFXFF);
          break;
          case 6:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 304, 213, GFXFF);
          break;
          case 7:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 332, 213, GFXFF);
          break;
        }
      }
    }
  }
  if ((startDay == 6) && (newWeekStart == 5)) {
    newDayStart = 34 - startDay;
    newWeekStart = newWeekStart + 1;
    for (int weekSix = 0; weekSix < 3; weekSix++) {
      newDayStart = newDayStart + 1;
      String StringDayWeek = String(newDayStart);
      if (monthLengh >= newDayStart) {
        switch (weekSix) {
          case 1:
            tft.setTextColor(blackScript);
            tft.drawString(StringDayWeek, 154, 238, GFXFF);
            weekYear = weekYear + 1;
          break;
          case 2:
            tft.setTextColor(whiteScript);
            tft.drawString(StringDayWeek, 184, 238, GFXFF);
          break;
        }
      }
    }
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
    tft.drawString(stringDay, 55, 105, GFXFF);
  }

  if (month < 10) {
    tft.drawString("0", 40, 175, GFXFF);
    tft.drawString(stringMonth, 70, 175, GFXFF);
  } else {
    tft.drawString(stringMonth, 55, 175, GFXFF);
  }

  tft.setTextDatum(TL_DATUM);
  tft.setTextColor(whiteScript);
  tft.setFreeFont(latoRegular14);
  tft.drawString("SEMANA", 365, 86, GFXFF);
  tft.drawString("DIA", 402, 105, GFXFF);
}

void seasons() {
  if (month >= 9) {
    if (day >= 23) {
      tft.pushImage(377, 154, 75, 92, spring);
    }
    return;
  }
  if (month >= 9 && month <= 12) {
    if (day <= 20) {
      tft.pushImage(377, 154, 75, 92, spring);
    }
    return;
  }
  if (month == 12) {
    if (day >= 21) {
      tft.pushImage(377, 154, 75, 92, summer);
    }
    return;
  }
  if (month == 12 || month <= 3) {
    if (day <= 20) {
      tft.pushImage(377, 154, 75, 92, summer);
    }
    return;
  }
  if (month >= 3) {
    if (day >= 21) {
      tft.pushImage(377, 154, 75, 92, autumn); 
    }
    return;
  }
  if (month >= 3 && month <= 6) {
    if (day <= 20) {
      tft.pushImage(377, 154, 75, 92, autumn); 
    }
    return;
  }
  if (month >= 6) {
    if (day >= 21) {
      tft.pushImage(377, 154, 75, 92, winter);
    }
    return;
  }
  if (month >= 6 && month <= 9) {
    if (day <= 22) {
      tft.pushImage(377, 154, 75, 92, winter);
    }
  }
}

void nixie() {
  tft.fillRect(30, 118, 10, 10, whiteScript);
  tft.fillRect(30, 146, 10, 10, whiteScript);
  tft.pushImage(272, 84, 36, 90, nixieBulb);
  tft.pushImage(309, 84, 36, 90, nixieBulb);
  tft.pushImage(348, 84, 36, 90, nixieBulb);
  tft.pushImage(385, 84, 36, 90, nixieBulb);
  tft.fillCircle(338, 158, 4, nixieColor);
}

void compass() {
  tft.drawSmoothArc(201, 173, 60, 59, 0, 359, icon_15, blackScript, squareEnd);

  tft.drawSmoothArc(201, 173, 79, 80, 0, 359, icon_15, blackScript, squareEnd);

  tft.drawSmoothArc(201, 173, 88, 88, 0, 359, icon_15, blackScript, squareEnd);
  tft.drawSmoothArc(201, 173, 93, 93, 0, 359, icon_15, blackScript, squareEnd);
  tft.drawSmoothArc(201, 173, 98, 98, 0, 359, icon_15, blackScript, squareEnd);

  tft.drawSmoothArc(201, 173, 89, 92, 0, 5, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 6, 10, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 11, 15, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 16, 20, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 21, 25, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 26, 30, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 31, 35, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 36, 40, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 41, 45, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 46, 50, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 51, 55, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 56, 60, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 61, 65, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 66, 70, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 71, 75, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 76, 80, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 81, 85, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 86, 90, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 91, 95, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 96, 100, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 101, 105, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 106, 110, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 111, 115, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 116, 120, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 121, 125, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 126, 130, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 131, 135, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 136, 140, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 141, 145, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 146, 150, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 151, 155, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 156, 160, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 161, 165, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 166, 170, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 171, 175, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 176, 180, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 181, 185, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 186, 190, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 191, 195, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 196, 200, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 201, 205, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 206, 210, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 211, 215, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 216, 220, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 221, 225, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 226, 230, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 231, 235, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 236, 240, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 241, 245, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 246, 250, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 251, 255, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 256, 260, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 261, 265, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 266, 270, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 271, 275, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 276, 280, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 281, 285, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 286, 290, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 291, 295, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 296, 300, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 301, 305, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 306, 310, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 311, 315, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 316, 320, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 321, 325, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 326, 330, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 331, 335, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 336, 340, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 341, 345, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 346, 350, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 351, 355, blackScript, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 92, 356, 360, blackScript, icon_15, squareEnd);

  tft.drawSmoothArc(201, 173, 89, 97, 179, 181, geigerLevel3, geigerLevel3, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 97, 89, 91, icon_15, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 97, 269, 271, icon_15, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 97, 359, 1, icon_15, icon_15, squareEnd);

  tft.drawSmoothArc(201, 173, 89, 97, 29, 31, icon_15, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 97, 59, 61, icon_15, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 97, 119, 121, icon_15, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 97, 149, 151, icon_15, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 97, 209, 211, icon_15, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 97, 239, 241, icon_15, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 97, 299, 301, icon_15, icon_15, squareEnd);
  tft.drawSmoothArc(201, 173, 89, 97, 329, 331, icon_15, icon_15, squareEnd);

  tft.fillCircle(201, 172, 5, greenScript);

  tft.fillRect(200, 162, 2, 2, whiteScript);
  tft.fillRect(200, 152, 2, 2, whiteScript);
  tft.fillRect(200, 142, 2, 2, whiteScript);
  tft.fillRect(200, 132, 2, 2, whiteScript);
  tft.fillRect(200, 122, 2, 2, whiteScript);

  tft.fillRect(150, 172, 2, 2, whiteScript);
  tft.fillRect(160, 172, 2, 2, whiteScript);
  tft.fillRect(170, 172, 2, 2, whiteScript);
  tft.fillRect(180, 172, 2, 2, whiteScript);
  tft.fillRect(190, 172, 2, 2, whiteScript);

  tft.fillRect(210, 172, 2, 2, whiteScript);
  tft.fillRect(220, 172, 2, 2, whiteScript);
  tft.fillRect(230, 172, 2, 2, whiteScript);
  tft.fillRect(240, 172, 2, 2, whiteScript);
  tft.fillRect(250, 172, 2, 2, whiteScript);

  tft.fillRect(200, 182, 2, 2, whiteScript);
  tft.fillRect(200, 192, 2, 2, whiteScript);
  tft.fillRect(200, 202, 2, 2, whiteScript);
  tft.fillRect(200, 212, 2, 2, whiteScript);
  tft.fillRect(200, 222, 2, 2, whiteScript);

  tft.setTextDatum(MC_DATUM);
  tft.setTextColor(geigerLevel3);
  tft.setFreeFont(latoRegular24);
  tft.drawString("N", 200, 61, GFXFF);

  tft.setTextColor(wifi_level2);  
  tft.drawString("S", 200, 285, GFXFF); 

  tft.setTextColor(whiteScript);  
  tft.drawString("W", 83, 170, GFXFF); 

  tft.setTextColor(whiteScript);  
  tft.drawString("E", 313, 170, GFXFF); 

  tft.setTextDatum(MC_DATUM);
  tft.setTextColor(augustColor);
  tft.setFreeFont(latoBold48);
  tft.drawString("174", 370, 97, GFXFF);

  tft.setTextDatum(MC_DATUM);
  tft.setTextColor(greenScript);
  tft.setFreeFont(latoBold48);
  tft.drawString("0.0", 370, 146, GFXFF);

  tft.setTextDatum(MC_DATUM);
  tft.setTextColor(whiteScript);
  tft.setFreeFont(latoRegular14);
  tft.drawString("X", 340, 216, GFXFF);
  tft.drawString("59", 360, 216, GFXFF);
  tft.drawString("Y", 400, 216, GFXFF);
  tft.drawString("46", 420, 216, GFXFF);


  tft.fillRectHGradient(15, 267, 100, 30, geigerColor1, geigerColor2);
  tft.drawString("CALIBRAR", 65, 281, GFXFF);
}

void keyboard() {
  tft.fillCircle(30, 100, 20, whiteScript);
  tft.drawRoundRect(65, 81, 350, 40, 5, icon_black);

  tft.drawLine(438, 90, 459, 111, icon_white);
  tft.drawLine(439, 90, 460, 111, icon_white);
  tft.drawLine(440, 90, 461, 111, icon_white);
  tft.drawLine(438, 111, 459, 90, icon_white);
  tft.drawLine(439, 111, 460, 90, icon_white);
  tft.drawLine(440, 111, 461, 90, icon_white);
  tft.drawLine(18, 93, 30, 105, blackScript);
  tft.drawLine(18, 94, 30, 106, blackScript);
  tft.drawLine(18, 95, 30, 107, blackScript);
  tft.drawLine(18, 96, 30, 108, blackScript);
  tft.drawLine(18, 97, 30, 109, blackScript);
  tft.drawLine(18, 98, 30, 110, blackScript);
  tft.drawLine(30, 105, 42, 93, blackScript);
  tft.drawLine(30, 106, 42, 94, blackScript);
  tft.drawLine(30, 107, 42, 95, blackScript);
  tft.drawLine(30, 108, 42, 96, blackScript);
  tft.drawLine(30, 109, 42, 97, blackScript);
  tft.drawLine(30, 110, 42, 98, blackScript);

  tft.fillRect(2, 160, 35, 35, wifi_off1);
  tft.fillRect(42, 160, 35, 35, wifi_off1);
  tft.fillRect(82, 160, 35, 35, wifi_off1);
  tft.fillRect(122, 160, 35, 35, wifi_off1);
  tft.fillRect(162, 160, 35, 35, wifi_off1);
  tft.fillRect(202, 160, 35, 35, wifi_off1);
  tft.fillRect(242, 160, 35, 35, wifi_off1);
  tft.fillRect(282, 160, 35, 35, wifi_off1);
  tft.fillRect(322, 160, 35, 35, wifi_off1);
  tft.fillRect(362, 160, 35, 35, wifi_off1);
  tft.fillRect(402, 160, 75, 35, wifi_off1);

  tft.fillRect(24, 200, 35, 35, wifi_off1);
  tft.fillRect(64, 200, 35, 35, wifi_off1);
  tft.fillRect(104, 200, 35, 35, wifi_off1);
  tft.fillRect(144, 200, 35, 35, wifi_off1);
  tft.fillRect(184, 200, 35, 35, wifi_off1);
  tft.fillRect(224, 200, 35, 35, wifi_off1);
  tft.fillRect(264, 200, 35, 35, wifi_off1);
  tft.fillRect(304, 200, 35, 35, wifi_off1);
  tft.fillRect(344, 200, 35, 35, wifi_off1);
  tft.fillRect(384, 200, 35, 35, wifi_off1);
  tft.fillRect(424, 200, 53, 35, wifi_off1);

  tft.fillRect(2, 240, 35, 35, wifi_off2);
  tft.fillRect(42, 240, 35, 35, wifi_off1);
  tft.fillRect(82, 240, 35, 35, wifi_off1);
  tft.fillRect(122, 240, 35, 35, wifi_off1);
  tft.fillRect(162, 240, 35, 35, wifi_off1);
  tft.fillRect(202, 240, 35, 35, wifi_off1);
  tft.fillRect(242, 240, 35, 35, wifi_off1);
  tft.fillRect(282, 240, 35, 35, wifi_off1);
  tft.fillRect(322, 240, 35, 35, wifi_off1);
  tft.fillRect(362, 240, 35, 35, wifi_off1);
  tft.fillRect(402, 240, 35, 35, wifi_off1);
  tft.fillRect(442, 240, 35, 35, wifi_off2);

  tft.fillRect(2, 280, 35, 35, wifi_off2);
  tft.fillRect(42, 280, 35, 35, wifi_off2);
  tft.fillRect(82, 280, 35, 35, wifi_off2);
  tft.fillRect(122, 280, 235, 35, wifi_off1);
  tft.fillRect(362, 280, 35, 35, wifi_off2);
  tft.fillRect(402, 280, 35, 35, wifi_off2);
  tft.fillRect(442, 280, 35, 35, wifi_off2);

  // Seta Esquerda
  tft.drawLine(372, 298, 383, 287, whiteScript);
  tft.drawLine(373, 298, 384, 287, whiteScript);
  tft.drawLine(374, 298, 385, 287, whiteScript);
  tft.drawLine(375, 298, 386, 287, whiteScript);
  tft.drawLine(375, 298, 386, 309, whiteScript);
  tft.drawLine(374, 298, 385, 309, whiteScript);
  tft.drawLine(373, 298, 384, 309, whiteScript);
  tft.drawLine(372, 298, 383, 309, whiteScript);

  // Seta Direita
  tft.drawLine(427, 298, 416, 287, whiteScript);
  tft.drawLine(426, 298, 415, 287, whiteScript);
  tft.drawLine(425, 298, 414, 287, whiteScript);
  tft.drawLine(424, 298, 413, 287, whiteScript);
  tft.drawLine(424, 298, 413, 309, whiteScript);
  tft.drawLine(425, 298, 414, 309, whiteScript);
  tft.drawLine(426, 298, 415, 309, whiteScript);
  tft.drawLine(427, 298, 416, 309, whiteScript);

  // Enter
  tft.drawLine(440, 217, 447, 210, whiteScript);
  tft.drawLine(441, 217, 448, 210, whiteScript);
  tft.drawLine(442, 217, 449, 210, whiteScript);
  tft.drawLine(443, 217, 450, 210, whiteScript);
  tft.drawLine(443, 217, 450, 224, whiteScript);
  tft.drawLine(442, 217, 449, 224, whiteScript);
  tft.drawLine(441, 217, 448, 224, whiteScript);
  tft.drawLine(440, 217, 447, 224, whiteScript);
  tft.drawLine(443, 216, 459, 216, whiteScript);
  tft.drawLine(443, 217, 459, 217, whiteScript);
  tft.drawLine(443, 218, 459, 218, whiteScript);
  tft.drawLine(459, 210, 459, 218, whiteScript);
  tft.drawLine(460, 210, 460, 218, whiteScript);
  tft.drawLine(461, 210, 461, 218, whiteScript);

  // Apagar
  tft.drawLine(426, 177, 433, 170, whiteScript);
  tft.drawLine(427, 177, 434, 170, whiteScript);
  tft.drawLine(428, 177, 435, 170, whiteScript);
  tft.drawLine(429, 177, 436, 170, whiteScript);
  tft.drawLine(429, 177, 436, 184, whiteScript);
  tft.drawLine(428, 177, 435, 184, whiteScript);
  tft.drawLine(427, 177, 434, 184, whiteScript);
  tft.drawLine(426, 177, 433, 184, whiteScript); 
  tft.drawLine(427, 176, 460, 176, whiteScript); 
  tft.drawLine(427, 177, 460, 177, whiteScript); 
  tft.drawLine(427, 178, 460, 178, whiteScript); 

  if (switchCaps == 1) {
  
    tft.setTextDatum(MC_DATUM);
    tft.setTextColor(wifi_off2);
    tft.setFreeFont(latoRegular12);

    tft.drawString("1", 7, 166, GFXFF);
    tft.drawString("2", 47 , 166, GFXFF);
    tft.drawString("3", 87, 166, GFXFF);
    tft.drawString("4", 127, 166, GFXFF);
    tft.drawString("5", 167, 166, GFXFF);
    tft.drawString("6", 207, 166, GFXFF);
    tft.drawString("7", 247, 166, GFXFF);
    tft.drawString("8", 287, 166, GFXFF);
    tft.drawString("9", 327, 166, GFXFF);
    tft.drawString("0", 367, 166, GFXFF);

    tft.setTextColor(whiteScript);
    tft.setFreeFont(latoRegular24);

    tft.drawString("Q", 20, 178, GFXFF);
    tft.drawString("W", 60, 178, GFXFF);
    tft.drawString("E", 100, 178, GFXFF);
    tft.drawString("R", 140, 178, GFXFF);
    tft.drawString("T", 180, 178, GFXFF);
    tft.drawString("Y", 220, 178, GFXFF);
    tft.drawString("U", 260, 178, GFXFF);
    tft.drawString("I", 300, 178, GFXFF);
    tft.drawString("O", 340, 178, GFXFF);
    tft.drawString("P", 380, 178, GFXFF);


    tft.drawString("A", 40, 218, GFXFF);
    tft.drawString("S", 80, 218, GFXFF);
    tft.drawString("D", 120, 218, GFXFF);
    tft.drawString("F", 160, 218, GFXFF);
    tft.drawString("G", 200, 218, GFXFF);
    tft.drawString("H", 240, 218, GFXFF);
    tft.drawString("J", 280, 218, GFXFF);
    tft.drawString("K", 320, 218, GFXFF);
    tft.drawString("L", 360, 218, GFXFF);
    tft.drawString("'", 400, 218, GFXFF);

    
    tft.drawString("Z", 60, 258, GFXFF);
    tft.drawString("X", 100, 258, GFXFF);
    tft.drawString("C", 140, 258, GFXFF);
    tft.drawString("V", 180, 258, GFXFF);
    tft.drawString("B", 220, 258, GFXFF);
    tft.drawString("N", 260, 258, GFXFF);
    tft.drawString("M", 300, 258, GFXFF);
    tft.drawString(",", 340, 258, GFXFF);
    tft.drawString(".", 380, 258, GFXFF);
    tft.drawString("?", 420, 258, GFXFF);

    tft.setFreeFont(latoRegular12);

    tft.drawString("&123", 19, 297, GFXFF);

    tft.setFreeFont(latoRegular14);

    tft.drawString("Caps", 20, 258, GFXFF);
    tft.drawString("Del", 460, 258, GFXFF);

    tft.drawString("ctrl", 58, 295, GFXFF);
    tft.drawString("fn", 99, 295, GFXFF);

    tft.drawString("ENG", 460, 297, GFXFF);

  } else {
    
    tft.setTextDatum(MC_DATUM);
    tft.setTextColor(wifi_off2);
    tft.setFreeFont(latoRegular12);

    tft.drawString("1", 7, 166, GFXFF);
    tft.drawString("2", 47 , 166, GFXFF);
    tft.drawString("3", 87, 166, GFXFF);
    tft.drawString("4", 127, 166, GFXFF);
    tft.drawString("5", 167, 166, GFXFF);
    tft.drawString("6", 207, 166, GFXFF);
    tft.drawString("7", 247, 166, GFXFF);
    tft.drawString("8", 287, 166, GFXFF);
    tft.drawString("9", 327, 166, GFXFF);
    tft.drawString("0", 367, 166, GFXFF);

    tft.setTextColor(whiteScript);
    tft.setFreeFont(latoRegular24);

    tft.drawString("q", 20, 178, GFXFF);
    tft.drawString("w", 60, 178, GFXFF);
    tft.drawString("e", 100, 178, GFXFF);
    tft.drawString("r", 140, 178, GFXFF);
    tft.drawString("t", 180, 178, GFXFF);
    tft.drawString("y", 220, 178, GFXFF);
    tft.drawString("u", 260, 178, GFXFF);
    tft.drawString("i", 300, 178, GFXFF);
    tft.drawString("o", 340, 178, GFXFF);
    tft.drawString("p", 380, 178, GFXFF);


    tft.drawString("a", 40, 218, GFXFF);
    tft.drawString("s", 80, 218, GFXFF);
    tft.drawString("d", 120, 218, GFXFF);
    tft.drawString("f", 160, 218, GFXFF);
    tft.drawString("g", 200, 218, GFXFF);
    tft.drawString("h", 240, 218, GFXFF);
    tft.drawString("j", 280, 218, GFXFF);
    tft.drawString("k", 320, 218, GFXFF);
    tft.drawString("l", 360, 218, GFXFF);
    tft.drawString("'", 400, 218, GFXFF);

    
    tft.drawString("z", 60, 258, GFXFF);
    tft.drawString("x", 100, 258, GFXFF);
    tft.drawString("c", 140, 258, GFXFF);
    tft.drawString("v", 180, 258, GFXFF);
    tft.drawString("b", 220, 258, GFXFF);
    tft.drawString("n", 260, 258, GFXFF);
    tft.drawString("m", 300, 258, GFXFF);
    tft.drawString(",", 340, 258, GFXFF);
    tft.drawString(".", 380, 258, GFXFF);
    tft.drawString("?", 420, 258, GFXFF);

    tft.setFreeFont(latoRegular12);

    tft.drawString("&123", 19, 297, GFXFF);

    tft.setFreeFont(latoRegular14);

    tft.drawString("Caps", 20, 258, GFXFF);
    tft.drawString("Del", 460, 258, GFXFF);

    tft.drawString("Ctrl", 58, 295, GFXFF);
    tft.drawString("Fn", 99, 295, GFXFF);

    tft.drawString("Eng", 460, 295, GFXFF);

  }
}

void welcome() {
  displayTFT = 18;
  if (language == 1) {
    tft.setTextDatum(MC_DATUM);
    tft.setTextColor(whiteScript);
    tft.setFreeFont(latoRegular14);
    tft.drawString("Minerva Project came by the passion of the classic Nixie tubes", 240, 129, GFXFF);
    tft.drawString("developed in 50`s decade to the moderns LCD display by", 240, 149, GFXFF);
    tft.drawString("the inspiration came the challenger of joining the old to the new.", 240, 169, GFXFF);
    tft.setFreeFont(latoBold48);
    tft.drawString("WELCOME", 240, 79, GFXFF);
    tft.setTextDatum(ML_DATUM);
    tft.setFreeFont(latoRegular24);
    tft.drawString("EN-US", 394, 299, GFXFF);
    tft.setTextDatum(MC_DATUM);
    tft.setFreeFont(latoRegular14);
    tft.fillRectHGradient(190, 232, 100, 30, temperatureColor1, temperatureColor2);
    tft.drawString("START", 240, 245, GFXFF);
  } else {
    tft.setTextDatum(MC_DATUM);
    tft.setTextColor(whiteScript);
    tft.setFreeFont(latoRegular14);
    tft.drawString("Projeto Minerva veio da paixao dos classicos tubos Nixie", 240, 129, GFXFF);
    tft.drawString("desenvolvidos na decada de 50 aos modernos display LCD", 240, 149, GFXFF);
    tft.drawString("da inspiracao veio junto o desafio de unir o antigo ao novo.", 240, 169, GFXFF);
    tft.setFreeFont(latoBold48);
    tft.drawString("BEM-VINDO", 240, 79, GFXFF);
    tft.setTextDatum(ML_DATUM);
    tft.setFreeFont(latoRegular24);
    tft.drawString("PT-BR", 394, 299, GFXFF);
    tft.setTextDatum(MC_DATUM);
    tft.setFreeFont(latoRegular14);
    tft.fillRectHGradient(190, 232, 100, 30, temperatureColor1, temperatureColor2);
    tft.drawString("INICIAR", 240, 245, GFXFF);
  }
}

void knowname() {
  keyboardClose = 0;

  tft.fillCircle(454, 88, 10, greyScript);
  tft.fillCircle(454, 123, 10, whiteScript);
  tft.fillCircle(454, 158, 10, greyScript);
  tft.fillCircle(454, 193, 10, greyScript);
  tft.fillCircle(454, 228, 10, greyScript);
  
  if (language == 1) {
    tft.setTextDatum(MC_DATUM);
    tft.setFreeFont(latoRegular24);
    tft.drawString("We need to know", 240, 90, GFXFF);
    tft.drawString("what is your name?", 240, 120, GFXFF);
    tft.setTextDatum(ML_DATUM);
    tft.drawString("EN-US", 394, 299, GFXFF);
    tft.setTextDatum(MC_DATUM);
    tft.setFreeFont(latoRegular14);
    tft.fillRectHGradient(190, 232, 100, 30, humidityColor1, humidityColor2);
    tft.drawString("CONTINUE", 240, 245, GFXFF);

    tft.drawRoundRect(115, 150, 250, 30, 5, whiteScript);
  } else {
    tft.setTextDatum(MC_DATUM);
    tft.setFreeFont(latoRegular24);
    tft.drawString("Precisamos saber", 240, 90, GFXFF);
    tft.drawString("Qual o seu nome?", 240, 120, GFXFF);
    tft.setTextDatum(ML_DATUM);
    tft.drawString("PT-BR", 394, 299, GFXFF);
    tft.setTextDatum(MC_DATUM);
    tft.setFreeFont(latoRegular14);
    tft.fillRectHGradient(190, 232, 100, 30, humidityColor1, humidityColor2);
    tft.drawString("CONTINUAR", 240, 245, GFXFF);

    tft.drawRoundRect(115, 150, 250, 30, 5, whiteScript);
  }
}

void profileimage() {
  tft.fillCircle(454, 88, 10, greyScript);
  tft.fillCircle(454, 123, 10, greyScript);
  tft.fillCircle(454, 158, 10, whiteScript);
  tft.fillCircle(454, 193, 10, greyScript);
  tft.fillCircle(454, 228, 10, greyScript);

  if (language == 1) {
    tft.setTextDatum(MC_DATUM);
    tft.setFreeFont(latoRegular24);
    tft.drawString("Choose a image for your Profile?", 240, 90, GFXFF);
    tft.setTextDatum(ML_DATUM);
    tft.drawString("EN-US", 394, 299, GFXFF);
    tft.setTextDatum(MC_DATUM);
    tft.setFreeFont(latoRegular14);
    tft.fillRectHGradient(190, 232, 100, 30, pressureColor1, pressureColor2);
    tft.drawString("CONTINUE", 240, 245, GFXFF);

    tft.drawRoundRect(77, 123, 50, 50, 10, whiteScript);
    tft.drawRoundRect(132, 123, 50, 50, 10, whiteScript);
    tft.drawRoundRect(187, 123, 50, 50, 10, whiteScript);
    tft.drawRoundRect(242, 123, 50, 50, 10, whiteScript);
    tft.drawRoundRect(297, 123, 50, 50, 10, whiteScript);
    tft.drawRoundRect(352, 123, 50, 50, 10, whiteScript);
    tft.drawRoundRect(77, 176, 50, 50, 10, whiteScript);
    tft.drawRoundRect(132, 176, 50, 50, 10, whiteScript);
    tft.drawRoundRect(187, 176, 50, 50, 10, whiteScript);
    tft.drawRoundRect(242, 176, 50, 50, 10, whiteScript);
    tft.drawRoundRect(297, 176, 50, 50, 10, whiteScript);
    tft.drawRoundRect(352, 176, 50, 50, 10, whiteScript);
  } else {
    tft.setTextDatum(MC_DATUM);
    tft.setFreeFont(latoRegular24);
    tft.drawString("Qual image gostaria de Perfil?", 240, 90, GFXFF);
    tft.setTextDatum(ML_DATUM);
    tft.drawString("PT-BR", 394, 299, GFXFF);
    tft.setTextDatum(MC_DATUM);
    tft.setFreeFont(latoRegular14);
    tft.fillRectHGradient(190, 232, 100, 30, pressureColor1, pressureColor2);
    tft.drawString("CONTINUAR", 240, 245, GFXFF);

    tft.drawRoundRect(77, 123, 50, 50, 10, whiteScript);
    tft.drawRoundRect(132, 123, 50, 50, 10, whiteScript);
    tft.drawRoundRect(187, 123, 50, 50, 10, whiteScript);
    tft.drawRoundRect(242, 123, 50, 50, 10, whiteScript);
    tft.drawRoundRect(297, 123, 50, 50, 10, whiteScript);
    tft.drawRoundRect(352, 123, 50, 50, 10, whiteScript);
    tft.drawRoundRect(77, 176, 50, 50, 10, whiteScript);
    tft.drawRoundRect(132, 176, 50, 50, 10, whiteScript);
    tft.drawRoundRect(187, 176, 50, 50, 10, whiteScript);
    tft.drawRoundRect(242, 176, 50, 50, 10, whiteScript);
    tft.drawRoundRect(297, 176, 50, 50, 10, whiteScript);
    tft.drawRoundRect(352, 176, 50, 50, 10, whiteScript);
  }
}

void internetAcess() {
  tft.fillCircle(454, 88, 10, greyScript);
  tft.fillCircle(454, 123, 10, greyScript);
  tft.fillCircle(454, 158, 10, greyScript);
  tft.fillCircle(454, 193, 10, whiteScript);
  tft.fillCircle(454, 228, 10, greyScript);

  if (language == 1) {
    tft.setTextDatum(MC_DATUM);
    tft.setFreeFont(latoRegular24);
    tft.drawString("Insert your Wi-Fi data", 240, 90, GFXFF);
    tft.setTextDatum(ML_DATUM);
    tft.drawString("EN-US", 394, 299, GFXFF);

    tft.drawRoundRect(115, 112, 250, 30, 5, whiteScript);
    tft.fillTriangle(346, 123, 356, 123, 351, 132, whiteScript);
    tft.drawRoundRect(115, 161, 215, 30, 5, greyScript);
    tft.drawCircle(350, 176, 15, greyScript);

    tft.setTextDatum(MC_DATUM);
    tft.setFreeFont(latoRegular14);

    tft.fillRectHGradient(123, 216, 100, 30, humidityColor1, humidityColor2);
    tft.drawString("SEARCH", 173, 230, GFXFF);
    tft.fillRectHGradient(210, 267, 60, 30, temperatureColor1, temperatureColor2);
    tft.drawString("SKIP", 240, 280, GFXFF);
    tft.fillRectHGradient(258, 216, 100, 30, pressureColor1, pressureColor2);
    tft.setTextColor(greyScript);
    tft.drawString("ACESS", 308, 230, GFXFF);
  } else  {
    tft.setTextDatum(MC_DATUM);
    tft.setFreeFont(latoRegular24);
    tft.drawString("Insira os dados Wi-Fi", 240, 90, GFXFF);
    tft.setTextDatum(ML_DATUM);
    tft.drawString("PT-BR", 394, 299, GFXFF);

    tft.drawRoundRect(115, 112, 250, 30, 5, whiteScript);
    tft.fillTriangle(346, 123, 356, 123, 351, 132, whiteScript);
    tft.drawRoundRect(115, 161, 215, 30, 5, greyScript);
    tft.drawCircle(350, 176, 15, greyScript);

    tft.setTextDatum(MC_DATUM);
    tft.setFreeFont(latoRegular14);

    tft.fillRectHGradient(123, 216, 100, 30, humidityColor1, humidityColor2);
    tft.drawString("BUSCAR", 173, 230, GFXFF);
    tft.fillRectHGradient(210, 267, 60, 30, temperatureColor1, temperatureColor2);
    tft.drawString("PULAR", 240, 280, GFXFF);
    tft.fillRectHGradient(258, 216, 100, 30, pressureColor1, pressureColor2);
    tft.setTextColor(greyScript);
    tft.drawString("ACESSAR", 308, 230, GFXFF);
  }
}

void startProgram() {
  tft.fillCircle(454, 88, 10, greyScript);
  tft.fillCircle(454, 123, 10, greyScript);
  tft.fillCircle(454, 158, 10, greyScript);
  tft.fillCircle(454, 193, 10, greyScript);
  tft.fillCircle(454, 228, 10, whiteScript);

  if (language == 1) {
    tft.setTextDatum(MC_DATUM);
    tft.setFreeFont(latoRegular24);
    tft.drawString("Everthing is already", 240, 90, GFXFF);
    tft.drawString("Xxxxxxx", 240, 120, GFXFF);
    tft.setTextDatum(ML_DATUM);
    tft.drawString("EN-US", 394, 299, GFXFF);
    tft.setTextDatum(MC_DATUM);
    tft.setFreeFont(latoRegular14);
    tft.fillRectHGradient(190, 232, 100, 30, humidityColor1, humidityColor2);
    tft.drawString("START", 240, 245, GFXFF);
    tft.drawString("You would be able to change the settings of", 240, 160, GFXFF);
    tft.drawString("your Device, all the settings can be changed", 240, 180, GFXFF);
    tft.drawString("by the Configuration menu.", 240, 200, GFXFF);


    tft.fillRectHGradient(190, 232, 100, 30, temperatureColor1, temperatureColor2);
    tft.drawString("START", 240, 245, GFXFF);
  } else {
    tft.setTextDatum(MC_DATUM);
    tft.setFreeFont(latoRegular24);
    tft.drawString("Tudo pronto", 240, 90, GFXFF);
    tft.drawString("Xxxxxxx", 240, 120, GFXFF);
    tft.setTextDatum(ML_DATUM);
    tft.drawString("PT-BR", 394, 299, GFXFF);
    tft.setTextDatum(MC_DATUM);
    tft.setFreeFont(latoRegular14);
    tft.fillRectHGradient(190, 232, 100, 30, humidityColor1, humidityColor2);
    tft.drawString("INICIAR", 240, 245, GFXFF);
    tft.drawString("Voce pode visualizar e configurar opcoes para", 240, 160, GFXFF);
    tft.drawString("seu dispositivo, todas as configuracoes podem ser", 240, 180, GFXFF);
    tft.drawString("alteradas pelo menu de configuracoes.", 240, 200, GFXFF);


    tft.fillRectHGradient(190, 232, 100, 30, temperatureColor1, temperatureColor2);
    tft.drawString("INICIAR", 240, 245, GFXFF);
  }
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

  tft.drawString("aCPM/h", 105, 190, GFXFF); 

  tft.drawString("CPM:", 332, 234, GFXFF);
  tft.drawString("Average:", 332, 251, GFXFF);
  tft.drawString("uSh", 332, 268, GFXFF);
  tft.drawString("mCPM", 332, 286, GFXFF);

  tft.setFreeFont(latoRegular24);
  tft.drawString("Sieverts", 242, 205, GFXFF);

  tft.fillRect(40, 85, 23, 29, geigerLevel3);
  tft.fillRect(40, 114, 23, 86, geigerLevel2);
  tft.fillRect(40, 200, 23, 73, geigerLevel1);

  tft.fillTriangle(68, 272, 85, 262, 85, 282, geigerLevel);

  tft.drawRoundRect(125, 267, 40, 30, 5, icon_9);
  tft.drawRoundRect(175, 267, 40, 30, 5, icon_9);
  tft.drawRoundRect(225, 267, 40, 30, 5, icon_9);

  tft.setFreeFont(latoRegular14);
  tft.drawString("W", 137, 280, GFXFF);
  tft.drawString("M", 188, 280, GFXFF);
  tft.drawString("Y", 240, 280, GFXFF);

  geigerLoad();
  home();
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

  dosimeterAnalogic();
  dosimeterAlarm();
  home();
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
  tft.drawString("Now:", 245, 279, GFXFF);

  tft.drawRoundRect(25, 267, 40, 30, 5, highValueColor);
  tft.drawRoundRect(75, 267, 40, 30, 5, icon_9);
  tft.drawRoundRect(125, 267, 40, 30, 5, icon_9);
  tft.drawRoundRect(175, 267, 40, 30, 5, icon_9);

  tft.setTextDatum(ML_DATUM);
  tft.setTextColor(geigerColor1);
  tft.setFreeFont(latoRegular14);
  tft.setTextColor(whiteScript);
  tft.drawString("W", 88, 280, GFXFF);
  tft.drawString("M", 138, 280, GFXFF);
  tft.drawString("Y", 190, 280, GFXFF);

  switch (dosimeterSelection) {
    case 1: dosimeterDigital(); dosimeterMin(); tft.drawString("m", 40, 280, GFXFF); break;
    case 2: dosimeterDay(); tft.drawString("D", 40, 280, GFXFF); break;
    case 3: dosimeterWeek(); tft.drawString("W", 88, 280, GFXFF); break;
    case 4: dosimeterMonth(); tft.drawString("M", 138, 280, GFXFF); break;
    case 5: dosimeterYear(); tft.drawString("Y", 190, 280, GFXFF); break;
  }

  home();
  wifiLevel();
  batteryLevel();
  lockLevel();
}

void telaMenu4() {
  tft.fillScreen(blackScript);
  i = 1;
  
  calendar();
  home();
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

  tft.drawRoundRect(15, 247, 40, 30, 5, temperatureColor1);
  tft.drawRoundRect(65, 247, 40, 30, 5, temperatureColor1);
  tft.drawRoundRect(115, 247, 40, 30, 5, temperatureColor1);
  tft.setTextDatum(ML_DATUM);
  tft.setTextColor(whiteScript);
  tft.setFreeFont(latoRegular14);
  tft.drawString("Min:", 165, 265, GFXFF);
  tft.drawString("Max:", 165, 285, GFXFF);
  tft.drawString("W", 27, 260, GFXFF);
  tft.drawString("M", 78, 260, GFXFF);
  tft.drawString("Y", 131, 260, GFXFF);


  temperatureLoad();
  home();
  wifiLevel();
  batteryLevel();
  lockLevel();
}

void telaMenu7() {
  tft.fillScreen(blackScript);
  i = 1;

  tft.drawRoundRect(15, 247, 40, 30, 5, pressureColor1);
  tft.drawRoundRect(65, 247, 40, 30, 5, pressureColor1);
  tft.drawRoundRect(115, 247, 40, 30, 5, pressureColor1);
  tft.setTextDatum(ML_DATUM);
  tft.setTextColor(whiteScript);
  tft.setFreeFont(latoRegular14);
  tft.drawString("Min:", 165, 265, GFXFF);
  tft.drawString("Max:", 165, 285, GFXFF);
  tft.drawString("W", 27, 260, GFXFF);
  tft.drawString("M", 78, 260, GFXFF);
  tft.drawString("Y", 131, 260, GFXFF);


  pressureLoad();
  home();
  wifiLevel();
  batteryLevel();
  lockLevel();
}

void telaMenu8() {
  tft.fillScreen(blackScript);
  i = 1;

  tft.drawRoundRect(15, 247, 40, 30, 5, humidityColor1);
  tft.drawRoundRect(65, 247, 40, 30, 5, humidityColor1);
  tft.drawRoundRect(115, 247, 40, 30, 5, humidityColor1);
  tft.setTextDatum(ML_DATUM);
  tft.setTextColor(whiteScript);
  tft.setFreeFont(latoRegular14);
  tft.drawString("Min:", 165, 265, GFXFF);
  tft.drawString("Max:", 165, 285, GFXFF);
  tft.drawString("W", 27, 260, GFXFF);
  tft.drawString("M", 78, 260, GFXFF);
  tft.drawString("Y", 131, 260, GFXFF);

  humidityLoad();
  home();
  wifiLevel();
  batteryLevel();
  lockLevel();
}

void telaMenu9() {
  tft.fillScreen(blackScript);
  i = 1;
  tft.drawSmoothArc(60, 100, 35, 25, 30, 145, temperatureColor2, blackScript, squareEnd);
  tft.pushImage(52, 86, 20, 35, temperatureImage);
  tft.drawCircle(60, 100, 35, temperatureColor2);
  tft.drawSmoothArc(60, 185, 35, 25, 10, 190, pressureColor2, blackScript, squareEnd);
  tft.pushImage(45, 169, 29, 29, pressureImage);
  tft.drawCircle(60, 185, 35, pressureColor2);
  tft.drawSmoothArc(60, 265, 35, 25, 25, 180, humidityColor2, blackScript, squareEnd);
  tft.pushImage(50, 248, 19, 30, humidityImage);
  tft.drawCircle(60, 265, 35, humidityColor2);
}

void telaMenu10() {
  tft.fillScreen(blackScript);
  i = 1;
  tft.pushImage(15, 50, 48, 48, profile1);
  tft.pushImage(65, 50, 48, 48, profile2);
  tft.pushImage(115, 50, 48, 48, profile3);
  tft.pushImage(165, 50, 48, 48, profile4);
  tft.pushImage(215, 50, 48, 48, profile5);
  tft.pushImage(265, 50, 48, 48, profile6);
  tft.pushImage(315, 50, 48, 48, profile7);
  tft.pushImage(365, 50, 48, 48, profile8);
  tft.pushImage(405, 50, 48, 48, profile9);

  tft.pushImage(15, 100, 48, 48, profile10);
  tft.pushImage(65, 100, 48, 48, profile11);
  tft.pushImage(115, 100, 48, 48, profile12);
  tft.pushImage(165, 100, 48, 48, profile13);
  tft.pushImage(215, 100, 48, 48, profile14);
  tft.pushImage(265, 100, 48, 48, profile15);
  tft.pushImage(315, 100, 48, 48, profile16);
  tft.pushImage(365, 100, 48, 48, profile17);
  tft.pushImage(405, 100, 48, 48, profile18);

  tft.pushImage(15, 150, 48, 48, profile19);
  tft.pushImage(65, 150, 48, 48, profile20);
  tft.pushImage(115, 150, 48, 48, profile21);
  tft.pushImage(165, 150, 48, 48, profile22);
  tft.pushImage(215, 150, 48, 48, profile23);
  tft.pushImage(265, 150, 48, 48, profile24);
  tft.pushImage(315, 150, 48, 48, profile25);
  tft.pushImage(365, 150, 48, 48, profile26);
  tft.pushImage(405, 150, 48, 48, profile27);

  tft.pushImage(15, 200, 48, 48, profile28);
  tft.pushImage(65, 200, 48, 48, profile29);




  tft.fillRectHGradient(15, 267, 100, 30, pressureColor1, pressureColor2);
  tft.fillRectHGradient(125, 267, 100, 30, temperatureColor1, temperatureColor2);
  tft.fillRectHGradient(235, 267, 100, 30, humidityColor1, humidityColor2);
}

void telaMenu11() {
  tft.fillScreen(blackScript);
  i = 1;

  tft.fillRect(13, 68, 450, 40, icon_15);

  tft.setTextDatum(MC_DATUM);
  tft.setTextColor(whiteScript);
  tft.setFreeFont(latoRegular24);

  tft.drawString("7", 23, 171, GFXFF); 
  tft.drawString("8", 64, 171, GFXFF); 
  tft.drawString("9", 105, 171, GFXFF); 

  tft.drawString("4", 23, 211, GFXFF); 
  tft.drawString("5", 64, 211, GFXFF); 
  tft.drawString("6", 105, 211, GFXFF); 

  tft.drawString("1", 23, 251, GFXFF); 
  tft.drawString("2", 64, 251, GFXFF); 
  tft.drawString("3", 105, 251, GFXFF); 

  tft.drawString("e", 23, 291, GFXFF); 
  tft.drawString("0", 64, 291, GFXFF); 
  tft.drawString(".", 105, 291, GFXFF); 

  tft.drawString("x", 175, 129, GFXFF); 
  tft.drawString("x", 175, 171, GFXFF); 
  tft.drawString("x", 175, 211, GFXFF); 
  tft.drawString("(", 178, 251, GFXFF); 

  tft.drawString("sin", 225, 129, GFXFF); 
  tft.drawString("cos", 225, 171, GFXFF); 
  tft.drawString("tan", 225, 211, GFXFF); 
  tft.drawString(")", 225, 251, GFXFF); 

  tft.drawString("dec", 273, 129, GFXFF); 
  tft.drawString("bin", 273, 171, GFXFF); 
  tft.drawString("hex", 273, 211, GFXFF); 
  tft.drawString(",", 273, 251, GFXFF); 

  tft.setTextColor(icon_1);

  tft.drawString("AC", 23, 131, GFXFF); 
  tft.drawString("x", 64, 131, GFXFF); 
  tft.drawString("%", 105, 131, GFXFF); 

  tft.drawString("-", 146, 131, GFXFF);  
  tft.drawString("x", 146, 171, GFXFF); 
  tft.drawString("-", 146, 211, GFXFF); 
  tft.drawString("+", 146, 251, GFXFF); 

  tft.setTextColor(blackScript);

  tft.drawString("=", 146, 291, GFXFF); 

  tft.drawCircle(277, 292, 15, icon_1);
  tft.drawCircle(277, 292, 14, icon_1);
  tft.drawCircle(327, 292, 15, icon_1);
  tft.drawCircle(327, 292, 14, icon_1);
  tft.drawCircle(377, 292, 15, icon_1);
  tft.drawCircle(377, 292, 14, icon_1);

  tft.drawCircle(327, 252, 15, icon_1);
  tft.drawCircle(327, 252, 14, icon_1);
  tft.drawCircle(377, 252, 15, icon_1);
  tft.drawCircle(377, 252, 14, icon_1);

  tft.drawCircle(327, 212, 15, icon_1);
  tft.drawCircle(327, 212, 14, icon_1);
  tft.drawCircle(377, 212, 15, icon_1);
  tft.drawCircle(377, 212, 14, icon_1);

  tft.drawCircle(327, 172, 15, icon_7);
  tft.drawCircle(327, 172, 14, icon_7);
  tft.drawCircle(377, 172, 15, icon_7);
  tft.drawCircle(377, 172, 14, icon_7);

  tft.drawCircle(327, 132, 15, icon_7);
  tft.drawCircle(327, 132, 14, icon_7);
  tft.drawCircle(377, 132, 15, icon_7);
  tft.drawCircle(377, 132, 14, icon_7);

  home();
  wifiLevel();
  batteryLevel();
  lockLevel();
}

void telaMenu12() {
  tft.fillScreen(blackScript);
  i = 1;

  compass();

  home();
  wifiLevel();
  batteryLevel();
  lockLevel();
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

  tft.setTextDatum(MC_DATUM);
  tft.setTextColor(whiteScript);
  tft.setFreeFont(latoRegular14);
  tft.drawString("BUSCAR", 74, 119, GFXFF); 
  tft.drawString("DESCONECTAR", 85, 168, GFXFF); 
  tft.drawString("ALTERAR", 74, 217, GFXFF); 

  tft.setTextDatum(ML_DATUM);
  tft.drawString("CONECTADO EM", 31, 75, GFXFF); 
  tft.drawString("NTP", 31, 253, GFXFF); 
  tft.drawString("CLIMA", 31, 273, GFXFF);
  tft.setTextDatum(MR_DATUM);
  tft.drawString("WEB", 390, 253, GFXFF); 
  tft.drawString("LOCAL", 390, 273, GFXFF); 

  tft.drawRoundRect(175, 112, 250, 30, 5, whiteScript);
  tft.fillTriangle(406, 123, 416, 123, 411, 132, whiteScript);
  tft.drawRoundRect(175, 161, 215, 30, 5, greyScript);
  tft.drawCircle(410, 176, 15, greyScript);

  home();
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

  tft.fillRect(33, 107, 20, 20, profileColor);

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


  tft.drawRoundRect(184, 112, 22, 8, 2, whiteScript);
  tft.fillRoundRect(185, 113, 20, 6, 2, blue_battery);

  tft.fillRectHGradient(30, 249, 100, 30, pressureColor1, pressureColor2);
  tft.fillRectHGradient(135, 249, 100, 30, temperatureColor1, temperatureColor2);

  tft.fillRect(30, 104, 205, 137, menuSelection);


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

  tft.drawRoundRect(290, 109, 50, 20, 5, whiteScript);
  tft.drawRoundRect(291, 110, 48, 18, 4, whiteScript);
  tft.fillRoundRect(292, 111, 46, 16, 4, blue_battery);

  tft.drawRoundRect(290, 144, 50, 20, 5, blue_battery);
  tft.drawRoundRect(291, 145, 48, 18, 4, blue_battery);

  tft.fillRoundRect(290, 180, 50, 20, 5, blue_battery);

  tft.fillRect(244, 104, 31, 31, icon_5);
  tft.fillTriangle(273, 105, 273, 133, 245, 133, icon_5);

  tft.fillRect(244, 140, 31, 31, whiteScript);
  tft.fillTriangle(273, 141, 273, 169, 245, 169, icon_5);

  tft.fillRect(244, 176, 31, 31, icon_black);
  tft.fillTriangle(273, 177, 273, 205, 245, 205, blackScript);

  tft.fillRect(244, 211, 31, 31, icon_white);
  tft.fillTriangle(273, 212, 245, 212, 245, 240, blackScript);

  home();
  wifiLevel();
  batteryLevel();
  lockLevel();
}

void drawArc(int x, int y, int arcStart, int artEnd, int radius, int color) {
  /*
      270
    /    \
  180     360-0
    \    /
      90
  */
  for (int i = arcStart; i < artEnd; i++) { 
    double radians = i * PI / 180;
    double px = x + radius * cos(radians);
    double py = y + radius * sin(radians);
    tft.drawPixel(px, py, color);
  }
}

int startDayOfWeek(int y, int m, int d) {
  static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
  y -= m < 3;
  return (y +y/4 -y/100 + y/400 + t[m-1] + d)% 7; 
}

void touchRectRound(int startX, int startY, int sizeX, int sizeY, int round, int color, int erase, byte& status) {
  bool pressed = tft.getTouch(&x, &y);

  if (x > startX && x < startX + sizeX && y > startY && y < startY + sizeY) {
    if (status == 0) {
      tft.fillRoundRect(startX, startY, sizeX, sizeY, round, color);
      status = 1;
    } else {
      tft.fillRoundRect(startX, startY, sizeX, sizeY, round, erase);
      tft.drawRoundRect(startX, startY, sizeX, sizeY, round, color);
      status = 0;
    }
  }
}

void touchRect(int startX, int startY, int sizeX, int sizeY, int color, int erase, byte& status) {
  bool pressed = tft.getTouch(&x, &y);

  if (x > startX && x < startX + sizeX && y > startY && y < startY + sizeY) {
    if (status == 0) {
      tft.fillRect(startX, startY, sizeX, sizeY, color);
      status = 1;
    } else {
      tft.fillRect(startX, startY, sizeX, sizeY, erase);
      tft.drawRect(startX, startY, sizeX, sizeY, color);
      status = 0;
    }
  }
}

void touchCircle(int startX, int startY, int size, int color, int erase, byte& status) {
  bool pressed = tft.getTouch(&x, &y);

  if (x > startX && x < startX + size && y > startY && y < startY + size) {
    if (status == 0) {
      tft.fillCircle(startX, startY, size, color);
      status = 1;
    } else {
      tft.fillCircle(startX, startY, size, erase);
      tft.fillCircle(startX, startY, size, color);
      status = 0;
    }
  }
}