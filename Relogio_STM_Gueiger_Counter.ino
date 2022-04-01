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

ST7789 - Alimentação Ideal 3v3 possível 5V mas com aquecimento

R       Botao Hard Reset

PA0     Alimentacao LDR
PA1     Pino DC ST7789
PA2     Pino RST ST7789
PA3     Pino BLK ST7789
PA4     Geiger Sensor
PA5     Pino SCL ST7789 
PA6     LDR Sensor
PA7     Pino SDA ST7789
PA8     Pino Nixie A
PA9     Pino Nixie B
PA10    Pino Nixie C
PA11    Pino Nixie D
PA12    anode Nixie B
PA15    anode Nixie A

PB0     Nivel Bateria
PB1     
PB2     
PB3     Pino SCL BME280 // TESTAR
PB4      
PB5     Pino SDA BME280 // TESTAR
PB6     **USART TX1
PB7     **USART RX1
PB8     Buzzer
PB9     
PB10    
PB12    Botao Hibernar
PB13    Botao Menu
PB14    Botao Up
PB15    Botao Down

PC13    Leitura Bat EN
PC14    anode Nixie C
PC15    anode Nixie D



*/

//------------------------------- VALORES AJUSTAVEIS PELO USUÁRIO --------------------

byte smoothBright = 100;        // 50 ~ 100 suavidade do brilho do tft
byte maxBrightness = 150;       // Define valor máximo de brilho
byte minBrightness = -80;       // Define valor minimo de brilho

byte logoTime = 3;              // Tempo de abertura Marca em Segundos

byte updateBMEData = 15000;     // Tempo de Leitura do BME280

int pressingDuration = 500;     // Tempo do botão Pressionado em Millis

byte day = 1;                   // Armazena dados de dia calendario
byte month = 1;                 // Armazena dados de mes calendario
int year = 2022;                // Armazena dados de ano calendario

byte fuso = 1;                  
//fuso = 0 12 Horas  
//fuso = 1 24 Horas

// DEFINIDO PELO TIPO DE TUBO UTILIZADO
float tubeGeiger = 151.0;       // Valor definido pelo tubo JS05

// RECOMENDADO NAO AJUSTAR
int integratingTime = 15000;    // Tempo de atualização das informações Geiger
int oneMinute = 60000;          // Tempo em Millis() para 1 minuto
int updateGeigeValue = 2000;    // Tempo de atualização dos dados do Modo Geiger


//------------------------------- ARMAZENAMENTO DE DADOS E COMPARADORES ---------------
    // DADOS CALENDARIO
int dayCount = 1;               // Armazena dado do nº dia do ano
int weekCount = 1;              // Armazena dado do nº semana do ano
byte dayWeek = 6;               // Armazena dado do dia da Semana
byte compareWeek;               // Armazena Calendario do Display
String attWeek[7] = {
"SUN",
"MON",
"TUE",
"WED",
"THU",
"FRI",
"SAT"};

String attWeekFull[7] = {
"SUNDAY",
"MONDAY",
"TUESDAY",
"WEDNESDAY",
"THURSDAY",
"FRIDAY",
"SATURDAY"};

String months[12] = {
"JANUARY",
"FEBRUERY",
"MARCH",
"APRIL",
"MAY",
"JUNE",
"JULY",
"AUGUST",
"SEPTEMBER",
"OCTOBER",
"NOVEMBER",
"DECEMBER"}; 


    // DADOS SENSOR GEIGER
unsigned long prevGraphGeiger;  // Armazena tempo de contagem do countsSecs
unsigned long prevGraphDosim;   // Armazena tempo de contagem do countsSecs
int countsSecs = 0;             // Armazena contagens do gueigerGraph no periodo de 1 Segundo
int counts;
unsigned long events = 0;       // Armazena Eventos Geiger
unsigned long cpm = 0;          // cpm = count * multiplier
unsigned int multiplier;        // multiplier = 60000 / 15000
int secCounts [20] = {0};       // Armazena Counts coletado pelo Geiger
int graphCounts;                // Armazena o valor de contagem para gráfico Personalizado.
double avgCounts = 0;           // Média de Contagens
double avgCPM = 0;              // Média de Contagens por Minuto
double avgUSV = 0;              // Média de µSv/h
double avgSvHour = 0;           // Média de mSv/h
double sumCPM = 0;              // Double para calculo Contagens
double sumUSV = 0;              // Double para calculo µSv/h 
double sumsvHour = 0;           // Double para calculo Media mSv/h
double uSv = 0;                 // Armazena dado de µSv/h
double compareuSv;              // Armazena uSv do Display 
int avgCPMz = avgCPM;

    // DADOS DESENHO MENU GEIGER
int xGeiger = 120;
int yGeiger = 120;
int radiusGeiger = 65;
int startAngleGeiger = 180;
int endAngleGeiger = 360;
int compareCounts;
double pxLate;
double pyLate;

    // DADOS DESENHO MENU DOSIMETER
int xDosimeter = 120;
int yDosimeter = 140;
int radiusDosimeter = 110;
int startAngleDosimeter = 210;
int endAngleGDosimeter = 330;
int compareCountsDosimeter;
double pxLateDosimeter;
double pyLateDosimeter;

    // DADOS DESENHO MENU GEIGER GF
long red = 42;
long green = 245;
long blue = 152;
unsigned int gradient = red << 11;
unsigned long targetTime = 0;

/*
  Canal de ajuste do ST7789 criar uma pagina para o ajuste da frequência de atualização
  indicar sendo de 5 ~ 10

  2.0 ~ 6.9  = taxa atualização não visivel
  7.0 ~ 7.9  = taxa atualização visivel leve
  8.0 ~ 10.0 = taxa atualização visivel forte

*/

    // DADOS SENSOR LDR
int brightness;                 // Armazena Brilho Processado
int brightMedia[100] = {0};     // Armazena brightSensor coletado pelo LDR
int brightSensor;               // Armazena Brilho coletado pelo LDR

    // DADOS SENSOR BME280
unsigned long lastMillis;
unsigned long int hum_raw,temp_raw,pres_raw;
signed long int t_fine;
uint16_t dig_T1;
 int16_t dig_T2;
 int16_t dig_T3;
uint16_t dig_P1;
 int16_t dig_P2;
 int16_t dig_P3;
 int16_t dig_P4;
 int16_t dig_P5;
 int16_t dig_P6;
 int16_t dig_P7;
 int16_t dig_P8;
 int16_t dig_P9;
 int8_t  dig_H1;
 int16_t dig_H2;
 int8_t  dig_H3;
 int16_t dig_H4;
 int16_t dig_H5;
 int8_t  dig_H6;

unsigned long timerBME;
int temperature = 0;
byte temperatureMin = 0;
byte temperatureMax = 0;
int humidity = 0;
byte humidityMin = 0;
byte humidityMax = 0;
int pressure = 0;
int pressureMin = 0;
int pressureMax = 0;
int fanrenheit = temperature * 1.8 + 32;
int fanrenheitMin = temperature * 1.8 + 32;
int fanrenheitMax = temperature * 1.8 + 32;
byte positionTempMax = 0;
byte positionTempMin = 0;
byte positionHumiMax = 0;
byte positionHumiMin = 0;
byte positionPresMax = 0;
byte positionPresMin = 0;

    // DADOS ZAMBRETTI
byte updateZambrettiHr = 0;
byte updateZambrettiMin = 0;


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

    // DADOS NIXIE

int numberArray[4] = {0};       // Armazena os Dados de flashNixie
int flashNixie = 0;             // Armazena valor para Inserção no Driver
int nixieCounts = 0;            // Armazena o Pino a ser acionado no Driver
int nixieAnode = 0;             // Armazena o Pino a ser acionado no Optotransistor
int speedEffect = 25;           // Taxa de atualização dos efeitos de 1 Nixie;

float refreshNixie = 7;         // Armazena taxa de atualização do Nixie

int lowerHours = hours % 10;
int upperHours = hours - lowerHours;
int lowerMins = mins % 10;
int upperMins = mins - lowerMins;
int lowerSeconds = secs % 10;
int upperSeconds = secs - lowerSeconds;

    // DADOS TIMERS 
unsigned long period = 0;       // Armazena periodo para comparador
unsigned long prevGeiger = 0;   // Armazena tempos para Geiger
unsigned long prevDosimeter = 0;// Armazena tempos para Dosimetro

    // BOTAO HIBERNAR
int startedPressingSleep = 0;   // Armazena o dado do Botão Sleep pressionado
int sleepBtnPressed = 0;        // Armazena valor = 1 se maior pressingDuration
unsigned long timerSleep = 0;   // Armazena tempo atual

    // BOTAO MENU
int startedPressingMode = 0;    // Armazena o dado do Botão Modo pressionado
int modeBtnPressed = 0;         // Armazena valor = 1 se maior pressingDuration 
unsigned long timerMode = 0;    // Armazena tempo atual

    // BOTAO UP
int startedPressingUp = 0;      // Armazena o dado do Botão Up pressionado
int upBtnPressed = 0;           // Armazena valor = 1 se maior pressingDuration
unsigned long timerUp = 0;      // Armazena tempo atual

    // BOTAO DOWN
int startedPressingDown = 0;    // Armazena o dado do Botão Down pressionado
int downBtnPressed = 0;         // Armazena valor = 1 se maior pressingDuration
unsigned long timerDown = 0;    // Armazena tempo atual

    // SETA DE SELECAO
int compareArrow = 0;           // Armazena o dado da Seta no Display

    // NIVEL DE BATERIA
int battery = 0;                // Armazena o dado de Leitura da Bateria
byte batteryPower;              // Armazena Leitura da Bateria
float voltageBattery;           // Armazena Tensão de Entrada

    // NIVEL DE BATERIA E WIFI          CORRIGIR red red red red red red red red red
byte statusMenu = 1;            // Armazena os dado de atualização
byte compareStatusMenu = 0;     // Armazena os dados de atualização

    // GERACAO DE GRAFICOS
byte minsCalcGeiger = 0;        // Armazena Horario marcação gráfico Geiger
byte minsCalcTemp = 0;          // Armazena Horario marcação gráfico Temperatura
byte minsCalcHumi = 0;          // Armazena Horario marcação gráfico Umidade
byte minsCalcPres = 0;          // Armazena Horario marcação gráfico Pressão Atmosferica

byte calcGeiger = 0;            // Armazena dado de Contagem para geigerCalc
byte calcTemp = 0;              // Armazena dado de Contagem para tempCalc
byte calcHumi = 0;              // Armazena dado de Contagem para humiCalc
byte calcPres = 0;              // Armazena dado de Contagem para presCalc

byte bankGeiger = 0;            // Armazena dado da posição do Gráfico em uso
byte bankTemp = 0;              // Armazena dado da posição do Gráfico em uso
byte bankHumi = 0;              // Armazena dado da posição do Gráfico em uso
byte bankPres = 0;              // Armazena dado da posição do Gráfico em uso

byte writerGeiger = 0;          // Armazena dado da posição do Gráfico em não uso
byte writerTemp = 0;            // Armazena dado da posição do Gráfico em não uso
byte writerHumi = 0;            // Armazena dado da posição do Gráfico em não uso
byte writerPres = 0;            // Armazena dado da posição do Gráfico em não uso

byte geigerCalc [220] = {0};    // Armazena dados de Geiger cada 16 minutos 
byte tempCalc [220] = {0};      // Armazena dados de Temperatura cada 16 minutos  
byte humiCalc [220] = {0};      // Armazena dados de Umidade cada 16 minutos
byte presCalc [220] = {0};      // Armazena dados de Pressão Atmosferica cada 16 minutos


// ------------------------------ BANCO DE DADOS DE COMPARADORES -----------------------

byte weatherSelector = 0;

byte sleepMode = 0;  
// sleepMode = 0 Sistema aguardando comando
// sleepMode = 1 Habilita entrada do Modo Hibernar
// sleepMode = 2 Habilita saida do Modo Hibernar

byte calendarFill = 0;
// calendarFill = 0 Iniciado Menu Calendar
// calendarFill = 1 Processo de preenchimento da tela

byte powerCharger = 1;          
// powerCharger = 0 Porta de saida ativada
// powerCharger = 1 Porta de saida desativada

byte flagArrow = 0;
// flagArrow = 0 Tela com Seta em Modo triangleclear
// flagArrow = 1 Tela com Seta em Modo triangletop
// flagArrow = 2 Tela com Seta em Modo triangledown
// flagArrow = 3 Tela com Seta em Modo triangleSelection

byte logostarted = 0;           
// logostarted = 0 Tela de Abertura ao ligar ou Hibernar ativado
// logostarted = 1 Tela de Abertura ao ligar ou Hibernar desativado

byte ldrPin = 0;
// ldrPin = 0 Porta de saida ativada
// ldrPin = 1 Porta de saida desativada

byte displayMode = 0;
// displayMode = 0 Sistema aguardando comando
// displayMode = 1 Habilita entrada do Menu
// displayMode = 2 Habilita saida do Menu

byte geigerMode = 0;
// geigerMode = 0 Sistema aguardando comando
// geigerMode = 1 Habilita entrada do Geiger
// geigerMode = 2 Habilita saida do Geiger 

byte displayTFT = 0;     
// displayTFT = 0 Sistema aguardando comando
// displayTFT = 1 Exibe display Geiger Simples
// displayTFT = 2 Exibe display Dosimetro
// displayTFT = 3 Exibe display Geiger Completo
// displayTFT = 4 Exibe display Clima Simples
// displayTFT = 5 Exibe display Clima Completo
// displayTFT = 6 Exibe display Calendario 
// displayTFT = 7 Exibe display Cronometro
// displayTFT = 8 Exibe display Ajuste Relogio
// displayTFT = 9 Exibe display Ajuste Data
// displayTFT = 10 Exibe display Ajuste Brilho
// displayTFT = 11 Exibe display Status Sensores

byte displayFlag = 0;     
// displayFlag = 0 Sistema aguardando comando
// displayFlag = 1 Exibe tft Geiger Simples
// displayFlag = 2 Exibe tft Dosimetro
// displayFlag = 3 Exibe tft Geiger Completo
// displayFlag = 4 Exibe tft Clima Simples
// displayFlag = 5 Exibe tft Clima Completo
// displayFlag = 6 Exibe tft Calendario 
// displayFlag = 7 Exibe display Cronometro
// displayFlag = 8 Exibe tft Ajuste Relogio
// displayFlag = 9 Exibe tft Ajuste Data
// displayFlag = 10 Exibe tft Ajuste Brilho
// displayFlag = 11 Exibe tft Status Sensores

byte triangleDisplay = 0;   
// triangleDisplay = 0 Nenhuma seta ativa
// triangleDisplay = 1 Nenhuma seta superior ativa
// triangleDisplay = 2 Nenhuma seta inferior ativa

byte bmeFunctional = 0;
// bmeFunctional = 0 BME280 não conectado
// bmeFunctional = 1 BME280 conectado
// bmeFunctional = 2 BME280 não operacional

byte geigerFunctional = 0;
// geigerFunctional = 0 Geiger não conectado
// geigerFunctional = 1 Geiger conectado

byte wifiFuncional = 0;
// wifiFuncional = 0 WiFi em alta potência
// wifiFuncional = 1 WiFi em media potência
// wifiFuncional = 2 WiFi em baixa potência
// wifiFuncional = 3 WiFi sem Sinal

byte effectModeNixie = 0;
// effectModeNixie = 0 Efeito desativado
// effectModeNixie = 1 Sequência Metro Nixie {6 7 5 8 4 3 9 2 0 1}
// effectModeNixie = 2 Sequência Numerica Nixie {9 8 7 6 5 4 3 2 1 0}

// ------------------------------ ARMAZENA DADOS DE STYLE ---------------------------

byte displayStyleMode = 0;      
// displayStyleMode = 0 Apresentação DEFAULT
// displayStyleMode = 1 Apresentação DALTONIC
// displayStyleMode = 2 Apresentação WHITE
// displayStyleMode = 3 Apresentação ACHROMATIC
// displayStyleMode = 4 Apresentação ACHROM W.

byte batteryStyleMode = 0;
// batteryStyleMode = 0 Apresentação Modo 1
// batteryStyleMode = 1 Apresentação Modo 2
// batteryStyleMode = 2 Apresentação Modo 3
// batteryStyleMode = 3 Apresentação Modo 4




byte weatherGraph = 0;



int* prt;           // CORRIGE LEITURA PARA ARQUITETURA ARM

// ------------------------------ CONFIGURACAO DOS PINOS DE SENSORES E DISPLAY --------

int ldrPinPower = PA0;          // Pino de alimentação do Sensor LDR
int ldrSensor = PA6;            // Pino do Sensor LDR
int geigerSensor = PA4;         // Pino do Sensor Geiger

int batteryLevel = PB0;         // Pino de Leitura da Bateria

int dspPinPower = PA3;          // Pino de BackLight do Display ST7789

int pinAnode0 = PA15;           // Pino Nixie Anodo Hora 1
int pinAnode1 = PA12;           // Pino Nixie Anodo Hora 2
int pinAnode2 = PB2;            // Pino Nixie Anodo Minuto 1
int pinAnode3 = PB1;            // Pino Nixie Anodo Minuto 2

int driverPinA = PA8;           // Pino Driver Catodo A
int driverPinB = PA9;           // Pino Driver Catodo B
int driverPinC = PA10;          // Pino Driver Catodo C
int driverPinD = PA11;          // Pino Driver Catodo D

// ------------------------------ CORES DISPLAY STY7789 -------------------------------

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

uint16_t geigerLevel3 = 0x362F;         //0x39C87E
uint16_t geigerLevel2 = 0xFF06;         //0xFFE437
uint16_t geigerLevel1 = 0xD8E4;         //0xE02028

uint16_t geigerColor1 = 0xFDA0;         //0xFFB801
uint16_t geigerColor2 = 0xDCA6;         //0xE49837

uint16_t luxColor1 = 0xFF06;            //0xFFE437
uint16_t luxColor2 = 0xFDA0;            //0xFFB801

uint16_t temperatureColor1 = 0xEBE8;    //0xF18148
uint16_t temperatureColor2 = 0xD12B;    //0xDE2662

uint16_t humidityColor1 = 0x25B9;       //0x25B7D0
uint16_t humidityColor2 = 0x929A;       //0x9A54D8

uint16_t pressureColor1 = 0x76A7;       //0x76DA41
uint16_t pressureColor2 = 0x1DF2;       //0x1EC099

uint16_t redAjust = 0xD8E4;             //0xE02028

uint16_t springMenu = 0x9669;           //0x9AD24D
uint16_t summerMenu = 0xFF06;           //0xFFE437
uint16_t autumnMenu = 0xFDA0;           //0xFFB801
uint16_t winterMenu = 0x8E3D;           //0x90CAEF
uint16_t seasonMenu;

uint16_t drizzleColor = 0xCF5E;         //0xD0EEFD
uint16_t rainColor = 0x8E3D;            //0x90CAEF
uint16_t sunColor = 0xFF06;             //0xFFE437


uint16_t blackScript = 0x0000;          //0x000000
uint16_t greyScript = 0x94B2;           //0x969696
uint16_t greywhite = 0xDF1B;            //0xE6E6E6
uint16_t whiteScript = 0xFFFF;          //0xFFFFFF
uint16_t redScript = 0xEA69;            //0xEF4D4F
uint16_t yellowScript = 0xFDA0;         //0xFFB801
uint16_t greenScript = 0x1F01;          //0x1AE510
uint16_t blueScript = 0x0B35;           //0x0B69B1


volatile int repetitions = 2000;

#define BUTTON_SLEEP PB12       // Modo repouso * Apertar e Pressionar BUTTON_UP
#define BUTTON_MODE PB13        // Selecionar Modo Geiger, Clima ou Calendário
#define BUTTON_UP PB14          // Sobe no Menu 
#define BUTTON_DOWN PB15        // Desce no Menu 

#define pinAnode0 PA15          // Pino Nixie Anodo Hora 1 
#define pinAnode1 PA12          // Pino Nixie Anodo Hora 2
#define pinAnode2 PC14          // Pino Nixie Anodo Minuto 1
#define pinAnode3 PC15          // Pino Nixie Anodo Minuto 2

#define driverPinA PA8          // Pino Driver Catodo A
#define driverPinB PA9          // Pino Driver Catodo B
#define driverPinC PA10         // Pino Driver Catodo C
#define driverPinD PA11         // Pino Driver Catodo D

#define seaLevelPressure_HPA (1013.25)
#define BME280_ADDRESS 0x76
#define GFXFF 1

#include "STM32LowPower.h"
#include <STM32RTC.h>

#include <TFT_eSPI.h> 
#include <SPI.h>
#include "MapFloat.h"
#include <Wire.h>
#include "Adafruit_GFX.h"

#include "Imagens.h"

#include "Lato_bold_24.h"
#include "Lato_Bold_48.h"
#include "Lato_Regular_14.h"
#include "Lato_Regular_12.h"
#include "Lato_Regular_10.h"

#define latoBold24 &Lato_Bold_24
#define latoBold48 &Lato_Bold_48
#define latoRegular14 &Lato_Regular_14
#define latoRegular12 &Lato_Regular_12
#define latoRegular10 &Lato_Regular_10


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

byte teste = 0;

// ------------------------------- INSTANCIAS DAS BIBLIOTECAS --------------------------

    STM32RTC& rtc = STM32RTC::getInstance();
    TFT_eSPI tft = TFT_eSPI();       // Could invoke custom library declaring width and height

void setup() {

    uint8_t osrs_t = 1;             //Temperature oversampling x 1
    uint8_t osrs_p = 1;             //Pressure oversampling x 1
    uint8_t osrs_h = 1;             //Humidity oversampling x 1
    uint8_t mode = 3;               //Normal mode
    uint8_t t_sb = 5;               //Tstandby 1000ms
    uint8_t filter = 0;             //Filter off 
    uint8_t spi3w_en = 0;           //3-wire SPI Disable
    
    uint8_t ctrl_meas_reg = (osrs_t << 5) | (osrs_p << 2) | mode;
    uint8_t config_reg    = (t_sb << 5) | (filter << 2) | spi3w_en;
    uint8_t ctrl_hum_reg  = osrs_h;

    Serial.begin(500000);
    analogWrite (dspPinPower, 0);

    LowPower.begin();
    tft.init();

    Wire.begin();
    bmeFunctional = Wire.endTransmission();
    writeReg(0xF2,ctrl_hum_reg);
    writeReg(0xF4,ctrl_meas_reg);
    writeReg(0xF5,config_reg);
    readTrim(); 

    pinMode(BUTTON_UP, INPUT_PULLUP);
    pinMode(BUTTON_DOWN, INPUT_PULLUP);
    pinMode(BUTTON_MODE, INPUT_PULLUP);
    pinMode(BUTTON_SLEEP, INPUT_PULLUP);

    pinMode(pinAnode0, OUTPUT);
    pinMode(pinAnode1, OUTPUT);
    pinMode(pinAnode2, OUTPUT);
    pinMode(pinAnode3, OUTPUT);

    pinMode(driverPinA, OUTPUT);
    pinMode(driverPinB, OUTPUT);
    pinMode(driverPinC, OUTPUT);
    pinMode(driverPinD, OUTPUT);

    pinMode(geigerSensor, INPUT);

    attachInterrupt (digitalPinToInterrupt (geigerSensor), geigeImpulse, FALLING);
    LowPower.attachInterruptWakeup(BUTTON_SLEEP, repetitionsIncrease, RISING, SLEEP_MODE);

    if (fuso == 1) {
        fuso = 24;
    } else {
        fuso = 12;
    }

}

void loop(void) {

    int upBtnPressed = digitalRead(BUTTON_UP);
    int downBtnPressed = digitalRead(BUTTON_DOWN);
    int modeBtnPressed = digitalRead(BUTTON_MODE);
    int sleepBtnPressed = digitalRead(BUTTON_SLEEP);
    unsigned long actualTime = millis();
    unsigned long actualTimeBright = millis();

    if (actualTimeBright - period >= 50) {
        statusBright();
        actualTimeBright = period;
    }
    statusGeiger();
    readBMEData();

    battery = analogRead(batteryLevel);
    batteryPower = map(battery, 0, 1023, 1, 255);
    voltageBattery = analogRead(batteryLevel) * 3.301 / 1024;    // red red red red red red red red rd red red VERIFICAR CASAS APOS . 

    if (counts > 0) {
        geigerFunctional = 1;
    } else {
        geigerFunctional = 0;
    }
    

    // ------------------------- COMANDO BANCO DE DADOS GEIGER -----------

// ------------------------- COMANDO BANCO DE DADOS GEIGER -----------

    if (minsCalcGeiger != mins) {
        minsCalcGeiger = mins;
        if (fuso == 1) {
            switch(hours) {
                case 0: bankGeiger = 10; break; 
                case 1: bankGeiger = 20; break; 
                case 2: bankGeiger = 29; break; 
                case 3: bankGeiger = 38; break;
                case 4: bankGeiger = 47; break;
                case 5: bankGeiger = 56; break;
                case 6: bankGeiger = 65; break;
                case 7: bankGeiger = 74; break;
                case 8: bankGeiger = 83; break;
                case 9: bankGeiger = 92; break;
                case 10: bankGeiger = 101; break;
                case 11: bankGeiger = 110; break;
                case 12: bankGeiger = 119; break;
                case 13: bankGeiger = 128; break;
                case 14: bankGeiger = 137; break;
                case 15: bankGeiger = 146; break;
                case 16: bankGeiger = 155; break;
                case 17: bankGeiger = 164; break;
                case 18: bankGeiger = 173; break;
                case 19: bankGeiger = 182; break;
                case 20: bankGeiger = 191; break;
                case 21: bankGeiger = 200; break;
                case 22: bankGeiger = 210; break;
                case 23: bankGeiger = 220; break;
            }
        } else {
            switch(hours) {
                case 0: bankGeiger = 10; break; 
                case 1: bankGeiger = 20; break; 
                case 2: bankGeiger = 29; break; 
                case 3: bankGeiger = 38; break;
                case 4: bankGeiger = 47; break;
                case 5: bankGeiger = 56; break;
                case 6: bankGeiger = 65; break;
                case 7: bankGeiger = 74; break;
                case 8: bankGeiger = 83; break;
                case 9: bankGeiger = 92; break;
                case 10: bankGeiger = 101; break;
                case 11: bankGeiger = 110; break;
                case 12: bankGeiger = 119; break;
                case 13: bankGeiger = 128; break;
                case 14: bankGeiger = 137; break;
                case 15: bankGeiger = 146; break;
                case 16: bankGeiger = 155; break;
                case 17: bankGeiger = 164; break;
                case 18: bankGeiger = 173; break;
                case 19: bankGeiger = 182; break;
                case 20: bankGeiger = 191; break;
                case 21: bankGeiger = 200; break;
                case 22: bankGeiger = 210; break;
                case 23: bankGeiger = 220; break;
            }
        }
        switch(mins) {
            case 6: bankGeiger = bankGeiger + 1; break;
            case 13: bankGeiger = bankGeiger + 2; break;
            case 19: bankGeiger = bankGeiger + 3; break;
            case 25: bankGeiger = bankGeiger + 4; break;
            case 31: bankGeiger = bankGeiger + 5; break;
            case 37: bankGeiger = bankGeiger + 6; break;
            case 43: bankGeiger = bankGeiger + 7; break;
            case 49: bankGeiger = bankGeiger + 8; break;
            case 54: bankGeiger = bankGeiger + 9; break;
        }
    }

    byte functGeiger = 0;
    if (minsCalcGeiger != bankGeiger) {
        minsCalcGeiger = bankGeiger;
        geigerCalc[bankGeiger] = avgUSV;
    }
    if (bankGeiger == 240) {
        tft.drawLine(10, 100, 10, 175, blackScript);
        bankGeiger = 10;
        writerGeiger = 10;
    }
    if (displayFlag == 3) {
        if (bankGeiger != writerGeiger) {
            writerGeiger = bankGeiger;
            functGeiger = map(geigerCalc[writerGeiger], 1, 2000, 175, 100);
            tft.drawLine(bankGeiger + 1, 100, bankGeiger + 1, 175, blackScript);
            tft.drawLine(bankGeiger, functGeiger - 50, bankGeiger, 175, geigerColor1);
        }
    }








    if (logostarted == 0) {
        startLogo();
        analogWrite(dspPinPower, 255);
        if (actualTime - period >= logoTime * 1000) {
            period = actualTime;
            logostarted = 1;
            tft.fillScreen (blackScript);
            analogWrite(dspPinPower, 0);
        }        
    }
    
    nixie();

    if (logostarted == 1 && displayTFT > 0 && sleepMode == 0 && displayFlag > 0) {

        if (mins != compareTimeMins) {           
            tft.fillRect (182, 215, 50, 15, blackScript);
            compareTimeMins = mins;
        }
        if (day != compareWeek) {
            tft.fillRect (30, 215, 160, 15, blackScript);
            compareWeek = day;
        }
        if (secsBias != compareTimeSecs) {
            compareTimeSecs = secsBias;
            if (displayFlag == 7) {
                tft.fillRect (20, 35, 201, 80, blackScript);
                tft.fillRect (158, 135, 70, 20, blackScript);
                Serial.println("");
                Serial.println(hours);
                Serial.println(":");
                Serial.println(mins);
                Serial.println(":");
                Serial.println(secs);
            }
        }
        switch (displayFlag) {
            case 1:      
                if (displayStyleMode == 0) { geigerStyleMode0(); } break; // GEIGER

            case 2:
                if (displayStyleMode == 0) { dosimeterStyleMode0(); } break; // DOSIMETER

            case 3:
                if (displayStyleMode == 0) { geigerGraphStyleMode0(); } break; // GEIGER GF

            case 4:
                if (displayStyleMode == 0) { weatherStyleMode0(); } break; // WEATHER

            case 5:
                if (displayStyleMode == 0) { weatherGraphStyleMode0(); } break; // WEATHER GF TEMP

            case 6:
                if (displayStyleMode == 0) { calendarStyleMode0(); } break; // CALENDAR

            case 7:
                if (displayStyleMode == 0) { timerStyleMode0(); } break; // TIMER

            case 8:
                if (displayStyleMode == 0) { ajustTimeStyleMode0(); } break; // AJUST TIME

            case 9:
                if (displayStyleMode == 0) { ajustDataStyleMode0(); } break; // AJUST DATA

            case 10: 
                if (displayStyleMode == 0) { ajustBrightStyleMode0(); } break; // AJUST BRIGHT

            case 11:
            break; // SETTINGS 

            default: 
            tft.fillScreen(blackScript);
        }
    }

    // ------------------------------- FUNCAO MENU DISPLAY OPERACIONAL ------------------------

        if (logostarted == 1 && displayTFT > 0 && sleepMode == 0 && displayFlag == 0) {
            if (mins != compareTimeMins) {
                tft.fillRect (182, 215, 50, 15, blackScript);
                compareTimeMins = mins;
            }
            if (day != compareWeek) {
                tft.fillRect (30, 215, 160, 15, blackScript);
                compareWeek = day;
            }

            statusBattery();
            subMenu();

            if (flagArrow != compareArrow) {
                tft.fillRect (15, 98, 30, 30, blackScript);
                compareArrow = flagArrow;
            }

            if (downBtnPressed == HIGH && upBtnPressed == HIGH && modeBtnPressed == HIGH) {
                flagArrow = 0;
                triangleclear();
            }
            if (downBtnPressed == HIGH && upBtnPressed == LOW && modeBtnPressed == HIGH) {
                flagArrow = 1;
                triangletop();
            } 
            if (downBtnPressed == LOW && upBtnPressed == HIGH && modeBtnPressed == HIGH) {
                flagArrow = 2;
                triangledown();
            }
            if (downBtnPressed == HIGH && upBtnPressed == HIGH && modeBtnPressed == LOW) {
                flagArrow = 3;
                triangleselection();
            }

            analogWrite(dspPinPower, 255);
            if (displayMode == 1) {
                switch (displayTFT) {
                    case 1:
                        if (geigerFunctional == 0) {
                            tft.setTextDatum(ML_DATUM);
                            tft.setTextColor(redScript);
                            tft.setFreeFont(latoRegular14);
                            tft.drawString("No Operational", 125, 90, GFXFF);
                        }
                        
                        tft.setTextDatum(ML_DATUM);
                        tft.setTextColor(whiteScript);
                        tft.setFreeFont(latoRegular14);
                        tft.drawString("DOSIMETER", 60, 60, GFXFF);

                        tft.setTextDatum(ML_DATUM);
                        tft.setTextColor(whiteScript);
                        tft.setFreeFont(latoBold24);
                        tft.drawString("GEIGER", 60, 110, GFXFF);

                        tft.setTextDatum(ML_DATUM);
                        tft.setTextColor(whiteScript);
                        tft.setFreeFont(latoRegular14);
                        tft.drawString("SETTINGS", 60, 160, GFXFF);
                    break;
                    case 2:
                        if (geigerFunctional == 0) {
                            tft.setTextDatum(ML_DATUM);
                            tft.setTextColor(redScript);
                            tft.setFreeFont(latoRegular14);
                            tft.drawString("No Operational", 125, 90, GFXFF);
                        }

                        tft.setTextDatum(ML_DATUM);
                        tft.setTextColor(whiteScript);
                        tft.setFreeFont(latoRegular14);
                        tft.drawString("GEIGER GF", 60, 60, GFXFF);

                        tft.setTextDatum(ML_DATUM);
                        tft.setTextColor(whiteScript);
                        tft.setFreeFont(latoBold24);
                        tft.drawString("DOSIMETER", 60, 110, GFXFF);

                        tft.setTextDatum(ML_DATUM);
                        tft.setTextColor(whiteScript);
                        tft.setFreeFont(latoRegular14);
                        tft.drawString("GEIGER", 60, 160, GFXFF);
                    break;
                    case 3:
                        if (geigerFunctional == 0) {
                            tft.setTextDatum(ML_DATUM);
                            tft.setTextColor(redScript);
                            tft.setFreeFont(latoRegular14);
                            tft.drawString("No Operational", 125, 90, GFXFF);
                        }

                        tft.setTextDatum(ML_DATUM);
                        tft.setTextColor(whiteScript);
                        tft.setFreeFont(latoRegular14);
                        tft.drawString("WEATHER", 60, 60, GFXFF);

                        tft.setTextDatum(ML_DATUM);
                        tft.setTextColor(whiteScript);
                        tft.setFreeFont(latoBold24);
                        tft.drawString("GEIGER GF", 60, 110, GFXFF);

                        tft.setTextDatum(ML_DATUM);
                        tft.setTextColor(whiteScript);
                        tft.setFreeFont(latoRegular14);
                        tft.drawString("DOSIMETER", 60, 160, GFXFF);
                    break;
                    case 4:
                        if (bmeFunctional != 0) {
                            tft.setTextDatum(ML_DATUM);
                            tft.setTextColor(redScript);
                            tft.setFreeFont(latoRegular14);
                            tft.drawString("No Operational", 125, 90, GFXFF);
                        }

                        tft.setTextDatum(ML_DATUM);
                        tft.setTextColor(whiteScript);
                        tft.setFreeFont(latoRegular14);
                        tft.drawString("WEATHER GF", 60, 60, GFXFF);

                        tft.setTextDatum(ML_DATUM);
                        tft.setTextColor(whiteScript);
                        tft.setFreeFont(latoBold24);
                        tft.drawString("WEATHER", 60, 110, GFXFF);

                        tft.setTextDatum(ML_DATUM);
                        tft.setTextColor(whiteScript);
                        tft.setFreeFont(latoRegular14);
                        tft.drawString("GEIGER GF", 60, 160, GFXFF);
                    break;
                    case 5:
                        if (bmeFunctional != 0) {
                            tft.setTextDatum(ML_DATUM);
                            tft.setTextColor(redScript);
                            tft.setFreeFont(latoRegular14);
                            tft.drawString("No Operational", 125, 90, GFXFF);
                        }

                        tft.setTextDatum(ML_DATUM);
                        tft.setTextColor(whiteScript);
                        tft.setFreeFont(latoRegular14);
                        tft.drawString("CALENDAR", 60, 60, GFXFF);

                        tft.setTextDatum(ML_DATUM);
                        tft.setTextColor(whiteScript);
                        tft.setFreeFont(latoBold24);
                        tft.drawString("WEATHER GF", 60, 110, GFXFF);

                        tft.setTextDatum(ML_DATUM);
                        tft.setTextColor(whiteScript);
                        tft.setFreeFont(latoRegular14);
                        tft.drawString("WEATHER", 60, 160, GFXFF);
                    break;
                    case 6:
                        tft.setTextDatum(ML_DATUM);
                        tft.setTextColor(whiteScript);
                        tft.setFreeFont(latoRegular14);
                        tft.drawString("TIMER", 60, 60, GFXFF);

                        tft.setTextDatum(ML_DATUM);
                        tft.setTextColor(whiteScript);
                        tft.setFreeFont(latoBold24);
                        tft.drawString("CALENDAR", 60, 110, GFXFF);

                        tft.setTextDatum(ML_DATUM);
                        tft.setTextColor(whiteScript);
                        tft.setFreeFont(latoRegular14);
                        tft.drawString("WEATHER GF", 60, 160, GFXFF);
                    break;
                    case 7:
                        tft.setTextDatum(ML_DATUM);
                        tft.setTextColor(whiteScript);
                        tft.setFreeFont(latoRegular14);
                        tft.drawString("CLOCK AJUST", 60, 60, GFXFF);

                        tft.setTextDatum(ML_DATUM);
                        tft.setTextColor(whiteScript);
                        tft.setFreeFont(latoBold24);
                        tft.drawString("TIMER", 60, 110, GFXFF);

                        tft.setTextDatum(ML_DATUM);
                        tft.setTextColor(whiteScript);
                        tft.setFreeFont(latoRegular14);
                        tft.drawString("CALENDAR", 60, 160, GFXFF);
                    break;
                    case 8:
                        tft.setTextDatum(ML_DATUM);
                        tft.setTextColor(whiteScript);
                        tft.setFreeFont(latoRegular14);
                        tft.drawString("DATA AJUST", 60, 60, GFXFF);

                        tft.setTextDatum(ML_DATUM);
                        tft.setTextColor(whiteScript);
                        tft.setFreeFont(latoBold24);
                        tft.drawString("CLOCK AJUST", 60, 110, GFXFF);

                        tft.setTextDatum(ML_DATUM);
                        tft.setTextColor(whiteScript);
                        tft.setFreeFont(latoRegular14);
                        tft.drawString("TIMER", 60, 160, GFXFF);
                    break;
                    case 9:
                        tft.setTextDatum(ML_DATUM);
                        tft.setTextColor(whiteScript);
                        tft.setFreeFont(latoRegular14);
                        tft.drawString("BRIGHT", 60, 60, GFXFF);

                        tft.setTextDatum(ML_DATUM);
                        tft.setTextColor(whiteScript);
                        tft.setFreeFont(latoBold24);
                        tft.drawString("DATA AJUST", 60, 110, GFXFF);

                        tft.setTextDatum(ML_DATUM);
                        tft.setTextColor(whiteScript);
                        tft.setFreeFont(latoRegular14);
                        tft.drawString("CLOCK AJUST", 60, 160, GFXFF);
                    break;
                    case 10:
                        tft.setTextDatum(ML_DATUM);
                        tft.setTextColor(whiteScript);
                        tft.setFreeFont(latoRegular14);
                        tft.drawString("SETTING", 60, 60, GFXFF);

                        tft.setTextDatum(ML_DATUM);
                        tft.setTextColor(whiteScript);
                        tft.setFreeFont(latoBold24);
                        tft.drawString("BRIGHT", 60, 110, GFXFF);

                        tft.setTextDatum(ML_DATUM);
                        tft.setTextColor(whiteScript);
                        tft.setFreeFont(latoRegular14);
                        tft.drawString("DATA AJUST", 60, 160, GFXFF);
                    break;
                    case 11:
                        tft.setTextDatum(ML_DATUM);
                        tft.setTextColor(whiteScript);
                        tft.setFreeFont(latoRegular14);
                        tft.drawString("GEIGER", 60, 60, GFXFF);

                        tft.setTextDatum(ML_DATUM);
                        tft.setTextColor(whiteScript);
                        tft.setFreeFont(latoBold24);
                        tft.drawString("SETTING", 60, 110, GFXFF);

                        tft.setTextDatum(ML_DATUM);
                        tft.setTextColor(whiteScript);
                        tft.setFreeFont(latoRegular14);
                        tft.drawString("BRIGHT", 60, 160, GFXFF);
                    break;

                    default:
                        statusBattery();
                }
            }
        }

    // ------------------------------- COMANDO HIBERNAR OPERACIONAL ---------------------------

        if (sleepBtnPressed == LOW && startedPressingSleep == 0) {
            startedPressingSleep = 1;
            timerSleep = millis();
        } else if (sleepBtnPressed == HIGH) {
            startedPressingSleep = 0;
            timerSleep = millis();
        }    
        if (millis() - timerSleep >= pressingDuration && startedPressingSleep == 1) {
            HibernMode();
            startedPressingSleep = 0;
        }

    // ------------------------------- COMANDO MENU OPERACIONAL -------------------------------
    
        else if (modeBtnPressed == LOW && startedPressingMode == 0) {
            startedPressingMode = 1;
            timerMode = millis();
        } else if (modeBtnPressed == HIGH) {
            startedPressingMode = 0;
            timerMode = millis();
        }

        if (millis() - timerMode >= (pressingDuration / 2) && startedPressingMode == 1) {
            if ((displayMode == 1) && (displayTFT == 5)) {
                weatherGraph ++;
            }
            displayMenu();
            startedPressingMode = 0;
        }

    // ------------------------------- COMANDO UP MENU OPERACIONAL ----------------------------

        else if (upBtnPressed == LOW && startedPressingUp == 0) {
            startedPressingUp = 1;
            timerUp = millis();

        } else if (upBtnPressed == HIGH) {
            triangleDisplay = 1;
            startedPressingUp = 0;
            timerUp = millis(); 
            if (triangleDisplay == 2 && timerUp - millis() >= 10) {
                timerDown = millis();
                enterDisplayMenu();
            }
        }

        if (millis() - timerUp >= (pressingDuration / 2) && startedPressingUp == 1) {
            tft.fillScreen(blackScript); 
            upModeDisplay();  
            startedPressingUp = 0;
            displayFlag = 0;
            calendarFill = 0;
        } 

    // ------------------------------- COMANDO DOWN MENU OPERACIONAL --------------------------

        else if (downBtnPressed == LOW && startedPressingDown == 0) {
            startedPressingDown = 1;
            timerDown = millis();

        } else if (downBtnPressed == HIGH) {
            triangleDisplay = 2;
            startedPressingDown = 0;
            timerDown = millis(); 
            if (triangleDisplay == 1 && timerDown - millis() >= 10) {
                timerUp = millis();
                enterDisplayMenu();
            }
        }

        if (millis() - timerDown >= (pressingDuration / 2) && startedPressingDown == 1) {
            tft.fillScreen(blackScript); 
            downModeDisplay();  
            startedPressingDown = 0;
            displayFlag = 0;
            calendarFill = 0;
        } 

    // ------------------------------- HORARIO VIA MILLIS() OPERACIONAL -----------------------
        secs = millis() / 2 + (long)hourBias * 3600 + (long)minuteBias * 60;
        secsBias = secs % 60;
        mins = (secs / 60) % 60;
        hours = (secs / 3600) % fuso;
        time = hours * 100 + mins;

    //------------------------------- FUNCAO RELOGIO OPERACIONAL ------------------------------
        if (time < 0 || time > 9999) {
            errorTime();
        } 
}

// ------------------------------ FUNCAO COMANDOS GEIGER OPERACIONAL ----------------------

void repetitionsIncrease() {

    repetitions ++;
}

void geigeImpulse() {
    counts ++;
    events ++;
    countsSecs ++;
}

// ------------------------------- FUNCAO HIBERNAR OPERACIONAL ----------------------------

void HibernMode() {
    startedPressingSleep = 0;
    sleepMode ++;
    if (sleepMode == 1) {
        enterHibernMode();
    } else if (sleepMode == 2) {
        exitHibernMode();
    } else {
        errorTime();
    }
}

void enterHibernMode() {
    analogWrite(dspPinPower, 0);













    ldrPin = 1;
    LowPower.sleep();
}

void exitHibernMode() {
    displayFlag = 0;
    logostarted = 0;
    sleepMode = 0;
    geigerMode = 0;
    ldrPin = 0;
    calendarFill = 0;
}

// ------------------------------ FUNCAO TELA ABERTURA RELOGIO OPERACIONAL ------------

void startLogo() {
    tft.setSwapBytes(true);
    //tft.pushImage(0, 0, 240, 240, abertura);
}

// ------------------------------ FUNCAO DISPLAY MENUS OPERACIONAL --------------------

void statusBattery() {
    String stringVoltageBattery = String(voltageBattery, 3);
    if (statusMenu != compareStatusMenu) {
        tft.fillRect(150, 7, 85, 25, blackScript);
        if (batteryStyleMode == 0) {
            tft.drawRoundRect (180, 10, 52, 22, 5, whiteScript);
            tft.drawRoundRect (181, 11, 50, 20, 4, whiteScript);

            if (powerCharger == 1) {
                if (batteryPower >= 213) {
                    tft.fillRoundRect (182, 12, 48, 18, 3, blue_battery);
                } else if ((batteryPower >= 171) && (batteryPower <= 212)) {
                    tft.fillRoundRect (190, 12, 40, 18, 3, green_battery);
                } else if ((batteryPower >= 129) && (batteryPower <= 170)) {
                    tft.fillRoundRect (200, 12, 30, 18, 3, yellow_battery);    
                } else if ((batteryPower >= 87) && (batteryPower <= 128)) {
                    tft.fillRoundRect (210, 12, 20, 18, 3, yellowed_battery);
                    
                } else if ((batteryPower >= 42) && (batteryPower <= 86)) {
                    tft.fillRoundRect (215, 12, 15, 18, 3, orange_battery);
                    
                } else if ((batteryPower >= 0) && (batteryPower <= 41)) {
                    tft.fillRoundRect (220, 12, 10, 18, 3, red_battery);
                }
            } else {
                tft.fillRoundRect (182, 12, 48, 18, 3, charge_battery);
                tft.fillTriangle(194, 21, 207, 16, 207, 21, blackScript);
                tft.fillTriangle(204, 21, 204, 26, 217, 21, blackScript);
            }
        }

        if (batteryStyleMode == 1) {
            tft.drawRoundRect (180, 10, 52, 22, 5, whiteScript);
            tft.drawRoundRect (181, 11, 50, 20, 4, whiteScript);

            if (powerCharger == 1) {
                if (batteryPower >= 213) {
                    tft.fillRoundRect (182, 12, 48, 18, 3, blue_battery);
                } else if ((batteryPower >= 171) && (batteryPower <= 212)) {
                    tft.fillRoundRect (190, 12, 40, 18, 3, green_battery);
                } else if ((batteryPower >= 129) && (batteryPower <= 170)) {
                    tft.fillRoundRect (200, 12, 30, 18, 3, yellow_battery);  
                } else if ((batteryPower >= 87) && (batteryPower <= 128)) {
                    tft.fillRoundRect (210, 12, 20, 18, 3, yellowed_battery);
                } else if ((batteryPower >= 42) && (batteryPower <= 86)) {
                    tft.fillRoundRect (215, 12, 15, 18, 3, orange_battery);
                } else if ((batteryPower >= 0) && (batteryPower <= 41)) {
                    tft.fillRoundRect (220, 12, 10, 18, 3, red_battery);
                }
                tft.drawLine(190, 12, 190, 30, blackScript);
                tft.drawLine(200, 12, 200, 30, blackScript);
                tft.drawLine(210, 12, 210, 30, blackScript);
                tft.drawLine(220, 12, 220, 30, blackScript);
            } else {
                tft.fillRoundRect (182, 12, 48, 18, 3, charge_battery);
                tft.fillTriangle(194, 21, 207, 16, 207, 21, blackScript);
                tft.fillTriangle(204, 21, 204, 26, 217, 21, blackScript);
            }
        }

        if (batteryStyleMode == 2) {
            if (powerCharger == 1) {
                tft.setTextDatum(TL_DATUM);
                tft.setFreeFont(latoRegular12);
                tft.setTextColor(whiteScript);
                if (batteryPower >= 213) {
                    tft.drawRoundRect (180, 10, 52, 22, 5, blue_battery);
                    tft.drawRoundRect (181, 11, 50, 20, 4, blue_battery);
                    tft.drawString(stringVoltageBattery, 184, 15, GFXFF);
                    tft.drawString("V", 221, 15, GFXFF);
                } else if ((batteryPower >= 171) && (batteryPower <= 212)) {
                    tft.drawRoundRect (180, 10, 52, 22, 5, green_battery);
                    tft.drawRoundRect (181, 11, 50, 20, 4, green_battery);
                    tft.drawString(stringVoltageBattery, 184, 15, GFXFF);
                    tft.drawString("V", 221, 15, GFXFF);
                } else if ((batteryPower >= 129) && (batteryPower <= 170)) {
                    tft.drawRoundRect (180, 10, 52, 22, 5, yellow_battery);
                    tft.drawRoundRect (181, 11, 50, 20, 4, yellow_battery);
                    tft.drawString(stringVoltageBattery, 184, 15, GFXFF);  
                    tft.drawString("V", 221, 15, GFXFF);
                } else if ((batteryPower >= 87) && (batteryPower <= 128)) {
                    tft.drawRoundRect (180, 10, 52, 22, 5, yellowed_battery);
                    tft.drawRoundRect (181, 11, 50, 20, 4, yellowed_battery);
                    tft.drawString(stringVoltageBattery, 184, 15, GFXFF);
                    tft.drawString("V", 221, 15, GFXFF);
                } else if ((batteryPower >= 42) && (batteryPower <= 86)) {
                    tft.drawRoundRect (180, 10, 52, 22, 5, orange_battery);
                    tft.drawRoundRect (181, 11, 50, 20, 4, orange_battery);
                    tft.drawString(stringVoltageBattery, 184, 15, GFXFF);
                    tft.drawString("V", 221, 15, GFXFF);
                } else if ((batteryPower >= 0) && (batteryPower <= 41)) {
                    tft.drawRoundRect (180, 10, 52, 22, 5, red_battery);
                    tft.drawRoundRect (181, 11, 50, 20, 4, red_battery);
                    tft.drawString(stringVoltageBattery, 184, 15, GFXFF);
                    tft.drawString("V", 221, 15, GFXFF);
                }
            } else {
                tft.drawRoundRect (180, 10, 52, 22, 5, charge_battery);
                tft.drawRoundRect (181, 11, 50, 20, 4, charge_battery);
                tft.fillRoundRect (182, 12, 48, 18, 3, charge_battery);
                tft.fillTriangle(194, 21, 207, 16, 207, 21, blackScript);
                tft.fillTriangle(204, 21, 204, 26, 217, 21, blackScript);
            }
        }

        if (batteryStyleMode == 3) {
            if (powerCharger == 1) {
                if (batteryPower >= 213) {
                    tft.drawRoundRect (180, 10, 52, 22, 5, blue_battery);
                    tft.drawRoundRect (181, 11, 50, 20, 4, blue_battery);
                    tft.fillRoundRect (182, 12, 48, 18, 3, blue_battery);
                } else if ((batteryPower >= 171) && (batteryPower <= 212)) {
                    tft.drawRoundRect (180, 10, 52, 22, 5, green_battery);
                    tft.drawRoundRect (181, 11, 50, 20, 4, green_battery);
                    tft.fillRoundRect (190, 12, 40, 18, 3, green_battery);
                } else if ((batteryPower >= 129) && (batteryPower <= 170)) {
                    tft.drawRoundRect (180, 10, 52, 22, 5, yellow_battery);
                    tft.drawRoundRect (181, 11, 50, 20, 4, yellow_battery);
                    tft.fillRoundRect (200, 12, 30, 18, 3, yellow_battery);    
                } else if ((batteryPower >= 87) && (batteryPower <= 128)) {
                    tft.drawRoundRect (180, 10, 52, 22, 5, yellowed_battery);
                    tft.drawRoundRect (181, 11, 50, 20, 4, yellowed_battery);
                    tft.fillRoundRect (210, 12, 20, 18, 3, yellowed_battery);
                    
                } else if ((batteryPower >= 42) && (batteryPower <= 86)) {
                    tft.drawRoundRect (180, 10, 52, 22, 5, orange_battery);
                    tft.drawRoundRect (181, 11, 50, 20, 4, orange_battery);
                    tft.fillRoundRect (215, 12, 15, 18, 3, orange_battery);
                    
                } else if ((batteryPower >= 0) && (batteryPower <= 41)) {
                    tft.drawRoundRect (180, 10, 52, 22, 5, red_battery);
                    tft.drawRoundRect (181, 11, 50, 20, 4, red_battery);
                    tft.fillRoundRect (220, 12, 10, 18, 3, red_battery);
                }
            } else {
                tft.drawRoundRect (180, 10, 52, 22, 5, charge_battery);
                tft.drawRoundRect (181, 11, 50, 20, 4, charge_battery);
                tft.fillRoundRect (182, 12, 48, 18, 3, charge_battery);
                tft.fillTriangle(194, 21, 207, 16, 207, 21, blackScript);
                tft.fillTriangle(204, 21, 204, 26, 217, 21, blackScript);
            }
        }



        if (wifiFuncional == 0) {
                for (byte radi = 21; radi > 15; radi --) {
                    for (int i = 230; i < 310; i++) {
                        double radians = i * PI / 180;
                        double px = 162 + radi * cos(radians);
                        double py = 31 + radi * sin(radians);
                        tft.drawPixel(px, py, wifi_level3);
                    }
                }
                for (byte radi = 15; radi > 8; radi --) {
                    for (int i = 230; i < 310; i++) {
                        double radians = i * PI / 180;
                        double px = 162 + radi * cos(radians);
                        double py = 31 + radi * sin(radians);
                        tft.drawPixel(px, py, wifi_level2);
                    }
                }
                for (byte radi = 8; radi > 0; radi --) {
                    for (int i = 230; i < 310; i++) {
                        double radians = i * PI / 180;
                        double px = 162 + radi * cos(radians);
                        double py = 31 + radi * sin(radians);
                        tft.drawPixel(px, py, wifi_level1);
                    }
                }
            } else if (wifiFuncional == 1) {
                for (byte radi = 15; radi > 8; radi --) {
                    for (int i = 230; i < 310; i++) {
                        double radians = i * PI / 180;
                        double px = 162 + radi * cos(radians);
                        double py = 31 + radi * sin(radians);
                        tft.drawPixel(px, py, wifi_level2);
                    }
                }
                for (byte radi = 8; radi > 0; radi --) {
                    for (int i = 230; i < 310; i++) {
                        double radians = i * PI / 180;
                        double px = 162 + radi * cos(radians);
                        double py = 31 + radi * sin(radians);
                        tft.drawPixel(px, py, wifi_level1);
                    }
                }
            } else if (wifiFuncional == 2) {
                for (byte radi = 8; radi > 0; radi --) {
                    for (int i = 230; i < 310; i++) {
                        double radians = i * PI / 180;
                        double px = 162 + radi * cos(radians);
                        double py = 31 + radi * sin(radians);
                        tft.drawPixel(px, py, wifi_level1);
                    }
                }
            } else if (wifiFuncional == 3) {
                for (byte radi = 15; radi > 8; radi --) {
                    for (int i = 230; i < 310; i++) {
                        double radians = i * PI / 180;
                        double px = 162 + radi * cos(radians);
                        double py = 31 + radi * sin(radians);
                        tft.drawPixel(px, py, wifi_level2);
                    }
                }
                for (byte radi = 21; radi > 15; radi --) {
                    for (int i = 230; i < 310; i++) {
                        double radians = i * PI / 180;
                        double px = 162 + radi * cos(radians);
                        double py = 31 + radi * sin(radians);
                        tft.drawPixel(px, py, wifi_off3);
                    }
                }
                for (byte radi = 15; radi > 8; radi --) {
                    for (int i = 230; i < 310; i++) {
                        double radians = i * PI / 180;
                        double px = 162 + radi * cos(radians);
                        double py = 31 + radi * sin(radians);
                        tft.drawPixel(px, py, wifi_off2);
                    }
                }
                for (byte radi = 8; radi > 0; radi --) {
                    for (int i = 230; i < 310; i++) {
                        double radians = i * PI / 180;
                        double px = 162 + radi * cos(radians);
                        double py = 31 + radi * sin(radians);
                        tft.drawPixel(px, py, wifi_off1);
                    }
                }
            }
        compareStatusMenu = statusMenu;
    }
}

void subMenu() {

    String stringDay = String(day);
    String stringMonth = String(month);
    String stringYear = String(year);
    String stringMin = String(mins);
    String stringHour = String(hours);


    if (day >= 24 && month >= 9) {
        if (day <= 21 && month <= 12) {
        seasonMenu = springMenu;
        }
    } 
    if (day >= 22 && month == 12) {
        if (day <= 21 && month <= 3) {
        seasonMenu = summerMenu;
        }
    } 
    if (day >= 22 && month >= 3) {
        if (day <= 21 && month <= 6) {
        seasonMenu = autumnMenu;
        }
    } 
    if (day >= 22 && month >= 6) {
        if (day <= 23 && month <= 9) {
        seasonMenu = winterMenu;
        }
    }
    tft.setTextDatum(ML_DATUM);
    tft.setTextColor(springMenu);
    tft.setFreeFont(latoRegular14);

    if (day < 10) {
        tft.drawString("0", 30, 220, GFXFF);

        tft.drawString(stringDay, 39, 220, GFXFF);
    } else if (day >= 10){
       tft.drawString(stringDay, 30, 220, GFXFF); 
    }

    if (month < 10) {
        tft.drawString("0", 10, 220, GFXFF);
        tft.drawString(stringMonth, 19, 220, GFXFF);
    } else if (month >= 10){
       tft.drawString(stringMonth, 10, 220, GFXFF); 
    }
    tft.drawString(stringYear, 50, 220, GFXFF);

    tft.drawString(attWeek[dayWeek - 1], 120, 220, GFXFF);

    if (hours < 10) {
        tft.drawString("0", 182, 220, GFXFF);
        tft.drawString(stringHour, 190, 220, GFXFF); 
    } else {
        tft.drawString(stringHour, 182, 220, GFXFF); 
    }
 
    tft.drawString(":", 200, 220, GFXFF);

    if (mins < 10) {
        tft.drawString("0", 206, 220, GFXFF);
        tft.drawString(stringMin, 214, 220, GFXFF);
    } else {
        tft.drawString(stringMin, 206, 220, GFXFF);
    }
}

// ------------------------------- FUNCAO DISPLAY GEIGER 

void geigerStyleMode0() {
    if (uSv != compareuSv) {
        tft.fillRect (140, 172, 90, 25, blackScript);
        compareuSv = uSv;
    }

    tft.drawRect(25, 96, 190, 25, whiteScript);
    tft.fillRect(115, 91, 26, 5, geigerLevel3);

    tft.setTextDatum(ML_DATUM);
    tft.setTextColor(whiteScript);
    tft.setFreeFont(latoRegular14);
    tft.drawString("Counts per second", 53, 149, GFXFF);
    tft.setFreeFont(latoBold24);
    tft.drawString("sieverts", 41, 180, GFXFF);
    
    processDataGeigerStyle0();
    graphGeigerGeneratorStyle0();

    tft.setFreeFont(latoRegular10);
    tft.drawString("2", 28, 80, GFXFF);
    tft.drawString("5", 38, 80, GFXFF);
    tft.drawString("20", 68, 80, GFXFF);
    tft.drawString("50", 85, 80, GFXFF);
    tft.drawString("200", 133, 80, GFXFF);
    tft.drawString("500", 155, 80, GFXFF);
    tft.drawString("2K", 199, 80, GFXFF);

    tft.setFreeFont(latoRegular14);
    tft.drawString("10", 48, 77, GFXFF);
    tft.drawString("100", 103, 77, GFXFF);
    tft.drawString("1K", 177, 77, GFXFF);

    /*
    if (uSv <= 9) {
        tft.drawString("u", 170, 169, GFXFF);
        tft.drawLine(170, 174, 170, 179, whiteScript);
    } else if (uSv <= 99) {
        tft.drawString("u", 180, 169, GFXFF);
        tft.drawLine(180, 174, 180, 179, whiteScript);
    } else {
        tft.drawString("u", 190, 169, GFXFF);
        tft.drawLine(190, 174, 190, 179, whiteScript);
    }
    */
    statusBattery();
    subMenu();   
}

void processDataGeigerStyle0() {
    String stringuSv = String(uSv, 1);

    if (uSv < 10) {
        tft.setTextDatum(ML_DATUM);
        tft.setTextColor(whiteScript);
        tft.setFreeFont(latoBold24);
        tft.drawString("u", 185, 180, GFXFF);
        tft.fillRect(186, 185, 3, 10, whiteScript);
    } else if (uSv < 100) {
        tft.setTextDatum(ML_DATUM);
        tft.setTextColor(whiteScript);
        tft.setFreeFont(latoBold24);
        tft.drawString("u", 200, 180, GFXFF);
        tft.fillRect(201, 185, 3, 10, whiteScript);
    } else if (uSv > 99) {
        tft.setTextDatum(ML_DATUM);
        tft.setTextColor(whiteScript);
        tft.setFreeFont(latoBold24);
        tft.drawString("u", 215, 180, GFXFF);
        tft.fillRect(216, 185, 3, 10, whiteScript);
    }
    tft.drawString(stringuSv, 147, 180, GFXFF);
}

void graphGeigerGeneratorStyle0() {   // incluir média para leitura.
    unsigned long geigerGraphMillis = millis();
    int pixelGraphGeiger;

    if (geigerGraphMillis - prevGraphGeiger >= 1000) {
        prevGraphGeiger = geigerGraphMillis;
        tft.fillRect(26, 97, 187, 23, blackScript);
        countsSecs = 0;
    }

    if (countsSecs < 2) {
        pixelGraphGeiger = map(countsSecs, 1, 2, 1, 5);
    } else if (countsSecs < 5) {
        pixelGraphGeiger = map(countsSecs, 3, 5, 6, 15);
    } else if (countsSecs < 10) {
        pixelGraphGeiger = map(countsSecs, 6, 10, 16, 25);
    } else if (countsSecs < 20) {
        pixelGraphGeiger = map(countsSecs, 11, 20, 26, 45);
    } else if (countsSecs < 50) {
        pixelGraphGeiger = map(countsSecs, 21, 50, 46, 52);
    } else if (countsSecs < 100) {
        pixelGraphGeiger = map(countsSecs, 51, 100, 53, 80);
    } else if (countsSecs < 200) {
        pixelGraphGeiger = map(countsSecs, 101, 200, 81, 110);
    } else if (countsSecs < 500) {
        pixelGraphGeiger = map(countsSecs, 201, 500, 111, 138);
    } else if (countsSecs < 1000) {
        pixelGraphGeiger = map(countsSecs, 501, 1000, 139, 155);
    } else if (countsSecs < 2000) {
        pixelGraphGeiger = map(countsSecs, 1001, 2000, 156, 175);
    } else if (countsSecs < 2200) {
        pixelGraphGeiger = map(countsSecs, 2001, 2200, 176, 189);
    } else {
        pixelGraphGeiger = 188;
    }

    //tft.fillRect(pixelGraphGeiger, 97, 2, 40, geigerColor2);
    tft.fillRectHGradient(26, 97, pixelGraphGeiger, 23, geigerColor1, geigerColor2);
}

void dosimeterStyleMode0() {
    float svHour = avgUSV * 60;
    svHour = svHour / 100;
    String stringcpm = String(cpm);
    String stringuSv = String(uSv);
    if (svHour > 9.9) {
        svHour = 9.9;
    }
    String stringsvHour = String(svHour, 1);
    String stringavgSvHour = String (avgSvHour, 2);

    tft.drawRect(25, 76, 190, 25, whiteScript);

    graphDosimeterStyle0();

    tft.setTextDatum(ML_DATUM);
    tft.setTextColor(greywhite);
    tft.setFreeFont(latoRegular14);

    tft.drawString(stringcpm, 60, 163, GFXFF);
    tft.drawString(stringavgSvHour, 84, 180, GFXFF);

    tft.drawString("CPM:", 21, 163, GFXFF);
    tft.drawString("Average:", 21, 180, GFXFF);
    tft.drawString("0", 26, 60, GFXFF);
    tft.drawString("2", 60, 60, GFXFF);
    tft.drawString("4", 95, 60, GFXFF);
    tft.drawString("6", 129, 60, GFXFF);
    tft.drawString("8", 164, 60, GFXFF);
    tft.drawString("10", 198, 60, GFXFF);

    tft.setFreeFont(latoBold24);

    tft.drawString("Sieverts", 21, 120, GFXFF);
    tft.drawString("mSv/h", 160, 120, GFXFF);
    tft.drawString(stringsvHour, 118, 120);

    if (uSv != compareuSv) {
        tft.fillRect (110, 110, 54, 24, blackScript);
        tft.fillRect (60, 156, 50, 16, blackScript);
        tft.fillRect (80, 175, 40, 16, blackScript);
        compareuSv = uSv;
        sumsvHour = (double)svHour + sumsvHour;
        avgSvHour = (sumsvHour / (avgCounts / multiplier) / 4);
    }

    subMenu();
    statusBattery();
}

void graphDosimeterStyle0() {
    float svHour = avgUSV * 60;
    svHour = svHour / 100;
    unsigned long dosimeterGraphMillis = millis();
    int pixelGraphDosimeter;

    if (dosimeterGraphMillis - prevGraphDosim >= 15000) {
        prevGraphDosim = dosimeterGraphMillis;
        
        tft.fillRect(26, 77, 73, 23, geigerLevel3);
        tft.fillRect(99, 77, 86, 23, geigerLevel2);
        tft.fillRect(185, 77, 29, 23, geigerLevel1);

        if (svHour < 9.9) {
            pixelGraphDosimeter = mapFloat(svHour, 0.00, 10.00, 26, 209);
        } else {
            pixelGraphDosimeter = 184;
        }
        tft.fillRect(pixelGraphDosimeter, 77, 5, 23, dosimeterColor);


        if ((svHour > 4.00) && (svHour < 8.99)) {
            tft.fillTriangle(167, 144, 189, 144, 179, 171, yellow_battery);
            tft.fillTriangle(147, 185, 175, 177, 161, 202, yellow_battery);
            tft.fillTriangle(210, 185, 183, 177, 196, 202, yellow_battery);
            tft.fillTriangle(179, 163, 168, 182, 190, 182, blackScript);
            tft.fillCircle(179, 175, 5, yellow_battery);
        } else if (svHour > 9 ) {
            tft.fillTriangle(167, 144, 189, 144, 179, 171, temperatureColor2);
            tft.fillTriangle(147, 185, 175, 177, 161, 202, temperatureColor2);
            tft.fillTriangle(210, 185, 183, 177, 196, 202, temperatureColor2);
            tft.fillTriangle(179, 163, 168, 182, 190, 182, blackScript);
            tft.fillCircle(179, 175, 5, temperatureColor2);
        } else {
            tft.fillRect(147, 144, 60, 60, blackScript);
        }
    }
}

void geigerGraphStyleMode0() {
    if (uSv != compareuSv) {
        tft.fillRect (82, 61, 148, 32, blackScript);
        compareuSv = uSv;
    }

    tft.setTextDatum(ML_DATUM);
    tft.setTextColor(greywhite);
    tft.setFreeFont(latoRegular14);

    tft.drawString("Sieverts", 13, 51, GFXFF);
    tft.drawString("uSh", 195, 51, GFXFF);
    tft.drawLine(196, 54, 196, 62, whiteScript);
    tft.drawString("CPM", 13, 70, GFXFF);
    tft.drawString("mCPM", 136, 70, GFXFF);
    tft.drawString("0", 7, 199, GFXFF);
    tft.drawString("6", 65, 199, GFXFF);
    tft.drawString("12", 115, 199, GFXFF);
    tft.drawString("18", 170, 199, GFXFF);
    tft.drawString("24", 223, 199, GFXFF);

    tft.setFreeFont(latoRegular10);

    tft.drawString("3", 36, 199, GFXFF);
    tft.drawString("9", 91, 199, GFXFF);
    tft.drawString("15", 143, 199, GFXFF);
    tft.drawString("21", 198, 199, GFXFF);

    tft.fillRect(10, 183, 2, 6, redAjust);
    tft.fillRect(38, 183, 1, 5, wifi_off2);
    tft.fillRect(68, 183, 2, 6, redAjust);
    tft.fillRect(93, 183, 1, 5, wifi_off2);
    tft.fillRect(123, 183, 2, 6, redAjust);
    tft.fillRect(147, 183, 1, 5, wifi_off2);
    tft.fillRect(178, 183, 2, 6, redAjust);
    tft.fillRect(203, 183, 1, 5, wifi_off2);
    tft.fillRect(230, 183, 2, 6, redAjust);

    

    //tft.fillRect(10, 85, 220, 85, sunColor);

    statusBattery();
    subMenu();
}

// ------------------------------- CONTADOR GEIGER MILLIS() OPERACIONAL -------------------

void statusGeiger() {   
    unsigned long geigerMillis = millis();

    if (geigerMillis - prevGeiger >= integratingTime) {
        avgCounts ++;

        multiplier = oneMinute / integratingTime;
        
        cpm = counts * multiplier; // CPM * 60/15 = CPM * 4
        uSv = (cpm / tubeGeiger);

        sumCPM = (double)cpm + sumCPM;
        sumUSV = uSv + sumUSV;

        avgCPM = sumCPM / avgCounts;
        avgUSV = sumUSV / avgCounts;


        prevGeiger = geigerMillis;
        counts = 0;
    }
}

// ------------------------------- FUNCAO DISPLAY WEATHER 

void weatherStyleMode0() {
    String stringTemp = String(temperature);
    String stringHumi = String(humidity);
    String stringPres = String(pressure);
    String stringUpdZambMin = String(updateZambrettiMin);
    String stringUpdZambHr = String(updateZambrettiHr);    
    String stringTempMin = String(temperatureMin);
    String stringTempMax = String(temperatureMax);
    String stringHumiMin = String(humidityMin);
    String stringHumiMax = String(humidityMax);
    String stringPresMin = String(pressureMin);
    String stringPresMax = String(pressureMax);

    tft.setTextDatum(ML_DATUM);
    tft.setTextColor(whiteScript);
    tft.setFreeFont(latoRegular14);
    tft.drawString(stringTempMin, 27, 135, GFXFF);
    tft.drawString(stringTempMax, 185, 135, GFXFF);
    tft.drawString(stringHumiMin, 27, 160, GFXFF);
    tft.drawString(stringHumiMax, 185, 160, GFXFF);
    tft.drawString(stringPresMin, 18, 185, GFXFF);
    tft.drawString(stringPresMax, 185, 185, GFXFF);
    tft.drawString("Update", 25, 80, GFXFF);
    tft.drawString(stringUpdZambMin, 80, 80, GFXFF);
    tft.drawString(stringUpdZambHr, 110, 80, GFXFF);

    tft.drawRect(49, 127, 130, 20, whiteScript);
    tft.drawRect(49, 152, 130, 20, whiteScript);
    tft.drawRect(49, 177, 130, 20, whiteScript);

    tft.fillRectHGradient(87, 128, 36, 18, temperatureColor1, temperatureColor2);
    tft.fillRectHGradient(76, 153, 67, 18, humidityColor1, humidityColor2);
    tft.fillRectHGradient(105, 178, 18, 18, pressureColor1, pressureColor2);

    climateStyleMode0();
    statusBattery();
    subMenu();
}

void climateStyleMode0() {
    switch (weatherSelector) {
        case 1: cleanWeather(); tft.setTextDatum(ML_DATUM); tft.setFreeFont(latoRegular14); tft.drawString("Clean", 25, 60, GFXFF); break;
        case 2: cloudWeather(); tft.setTextDatum(ML_DATUM); tft.setFreeFont(latoRegular14); tft.drawString("Cloud", 25, 60, GFXFF); break;
        case 3: sereneWeather(); tft.setTextDatum(ML_DATUM); tft.setFreeFont(latoRegular14); tft.drawString("Serene", 25, 60, GFXFF); break;
        case 4: drizzleWeather(); tft.setTextDatum(ML_DATUM); tft.setFreeFont(latoRegular14); tft.drawString("Drizzle", 25, 60, GFXFF); break;
        case 5: thunderWeather(); tft.setTextDatum(ML_DATUM); tft.setFreeFont(latoRegular14); tft.drawString("Thunderstorm", 25, 60, GFXFF); break;
        case 6: stormWeather(); tft.setTextDatum(ML_DATUM); tft.setFreeFont(latoRegular14); tft.drawString("Storm", 25, 60, GFXFF); break;
        case 7: tempestWeather(); tft.setTextDatum(ML_DATUM); tft.setFreeFont(latoRegular14); tft.drawString("Tempest", 25, 60, GFXFF); break;
        case 8: seTempestWeather(); tft.setTextDatum(ML_DATUM); tft.setFreeFont(latoRegular14); tft.drawString("??Tempest", 25, 60, GFXFF); break;
        case 9: hailWeather(); tft.setTextDatum(ML_DATUM); tft.setFreeFont(latoRegular14); tft.drawString("Hail", 25, 60, GFXFF); break;
        case 10: seRainWeather(); tft.setTextDatum(ML_DATUM); tft.setFreeFont(latoRegular14); tft.drawString("??Rain", 25, 60, GFXFF); break;
        case 11: hvSereneWeather(); tft.setTextDatum(ML_DATUM); tft.setFreeFont(latoRegular14); tft.drawString("Heavy Serene", 25, 60, GFXFF); break;
        case 12: snowWeather(); tft.setTextDatum(ML_DATUM); tft.setFreeFont(latoRegular14); tft.drawString("Snow", 25, 60, GFXFF); break;
        default:
            unknownWeather(); tft.setTextDatum(ML_DATUM); tft.setFreeFont(latoRegular14); tft.drawString("Unknown", 25, 60, GFXFF); break;
    }
}

void weatherGraphStyleMode0() {
    String stringweather = String(weatherGraph);
    tft.drawString(stringweather, 50, 10, GFXFF);
    if (weatherGraph == 1) {
        tempGraphStyleMode0();
    } else if (weatherGraph == 2) {
        humiGraphStyleMode0();
    } else if (weatherGraph == 3) {
        presGraphStyleMode0();
    } else {
        weatherGraph = 0;
        displayMode = 0;
    }
}

void tempGraphStyleMode0() {
    String stringTemp = String(temperature);
    String stringTempMin = String(temperatureMin);
    String stringTempMax = String(temperatureMax);

    tft.setTextDatum(ML_DATUM);
    tft.setTextColor(greywhite);

    tft.setFreeFont(latoBold24);

    tft.drawString(stringTemp, 150, 165, GFXFF);
    tft.drawString("C", 190, 165, GFXFF);
    tft.drawCircle(215, 160, 3, whiteScript);
    tft.drawCircle(215, 160, 4, whiteScript);

    tft.setFreeFont(latoRegular14);

    tft.drawString("0", 7, 125, GFXFF);
    tft.drawString("6", 65, 125, GFXFF);
    tft.drawString("12", 115, 125, GFXFF);
    tft.drawString("18", 170, 125, GFXFF);
    tft.drawString("24", 223, 125, GFXFF);

    tft.drawString("Min:", 24, 155, GFXFF);
    tft.drawString("Max:", 24, 175, GFXFF);

    tft.drawString(stringTempMin, 60, 155, GFXFF);
    tft.drawString(stringTempMax, 60, 175, GFXFF);

    tft.drawString("C", 85, 155, GFXFF);
    tft.drawString("C", 85, 175, GFXFF);
    tft.drawCircle(100, 150, 2, whiteScript);
    tft.drawCircle(100, 170, 2, whiteScript);

    tft.setFreeFont(latoRegular10);

    tft.drawString("3", 36, 125, GFXFF);
    tft.drawString("9", 91, 125, GFXFF);
    tft.drawString("15", 143, 125, GFXFF);
    tft.drawString("21", 198, 125, GFXFF);

    tft.fillRect(10, 110, 2, 6, temperatureColor1);
    tft.fillRect(38, 110, 1, 5, wifi_off2);
    tft.fillRect(68, 110, 2, 6, temperatureColor1);
    tft.fillRect(93, 110, 1, 5, wifi_off2);
    tft.fillRect(123, 110, 2, 6, temperatureColor1);
    tft.fillRect(147, 110, 1, 5, wifi_off2);
    tft.fillRect(178, 110, 2, 6, temperatureColor1);
    tft.fillRect(203, 110, 1, 5, wifi_off2);
    tft.fillRect(230, 110, 2, 6, temperatureColor1);

    tft.fillRectHGradient(10, 50, 220, 55, temperatureColor1, temperatureColor2);

    statusBattery();
    subMenu();
}

void humiGraphStyleMode0() {
    String stringHumi = String(humidity);
    String stringHumiMin = String(humidityMin);
    String stringHumiMax = String(humidityMax);

    tft.setTextDatum(ML_DATUM);
    tft.setTextColor(greywhite);

    tft.setFreeFont(latoBold24);

    tft.drawString(stringHumi, 150, 165, GFXFF);
    tft.drawString("%", 190, 165, GFXFF);

    tft.setFreeFont(latoRegular14);

    tft.drawString("0", 7, 125, GFXFF);
    tft.drawString("6", 65, 125, GFXFF);
    tft.drawString("12", 115, 125, GFXFF);
    tft.drawString("18", 170, 125, GFXFF);
    tft.drawString("24", 223, 125, GFXFF);

    tft.drawString("Min:", 24, 155, GFXFF);
    tft.drawString("Max:", 24, 175, GFXFF);

    tft.drawString(stringHumiMin, 60, 155, GFXFF);
    tft.drawString(stringHumiMax, 60, 175, GFXFF);

    tft.drawString("%", 85, 155, GFXFF);
    tft.drawString("%", 85, 175, GFXFF);

    tft.setFreeFont(latoRegular10);

    tft.drawString("3", 36, 125, GFXFF);
    tft.drawString("9", 91, 125, GFXFF);
    tft.drawString("15", 143, 125, GFXFF);
    tft.drawString("21", 198, 125, GFXFF);

    tft.fillRect(10, 110, 2, 6, humidityColor1);
    tft.fillRect(38, 110, 1, 5, wifi_off2);
    tft.fillRect(68, 110, 2, 6, humidityColor1);
    tft.fillRect(93, 110, 1, 5, wifi_off2);
    tft.fillRect(123, 110, 2, 6, humidityColor1);
    tft.fillRect(147, 110, 1, 5, wifi_off2);
    tft.fillRect(178, 110, 2, 6, humidityColor1);
    tft.fillRect(203, 110, 1, 5, wifi_off2);
    tft.fillRect(230, 110, 2, 6, humidityColor1);

    tft.fillRectHGradient(10, 50, 220, 55, humidityColor1, humidityColor2);

    statusBattery();
    subMenu();
}

void presGraphStyleMode0() {
    String stringPres = String(pressure);
    String stringPresMin = String(pressureMin);
    String stringPresMax = String(pressureMax);

    tft.setTextDatum(ML_DATUM);
    tft.setTextColor(greywhite);

    tft.setFreeFont(latoBold24);

    tft.drawString(stringPres, 150, 165, GFXFF);
    tft.drawString("Hg", 190, 165, GFXFF);
    tft.drawCircle(215, 160, 3, whiteScript);
    tft.drawCircle(215, 160, 4, whiteScript);

    tft.setFreeFont(latoRegular14);

    tft.drawString("0", 7, 125, GFXFF);
    tft.drawString("6", 65, 125, GFXFF);
    tft.drawString("12", 115, 125, GFXFF);
    tft.drawString("18", 170, 125, GFXFF);
    tft.drawString("24", 223, 125, GFXFF);

    tft.drawString("Min:", 24, 155, GFXFF);
    tft.drawString("Max:", 24, 175, GFXFF);

    tft.drawString(stringPresMin, 60, 155, GFXFF);
    tft.drawString(stringPresMax, 60, 175, GFXFF);

    tft.drawString("Hg", 85, 155, GFXFF);
    tft.drawString("Hg", 85, 175, GFXFF);
    tft.drawCircle(100, 150, 2, whiteScript);
    tft.drawCircle(100, 170, 2, whiteScript);

    tft.setFreeFont(latoRegular10);

    tft.drawString("3", 36, 125, GFXFF);
    tft.drawString("9", 91, 125, GFXFF);
    tft.drawString("15", 143, 125, GFXFF);
    tft.drawString("21", 198, 125, GFXFF);

    tft.fillRect(10, 110, 2, 6, pressureColor1);
    tft.fillRect(38, 110, 1, 5, wifi_off2);
    tft.fillRect(68, 110, 2, 6, pressureColor1);
    tft.fillRect(93, 110, 1, 5, wifi_off2);
    tft.fillRect(123, 110, 2, 6, pressureColor1);
    tft.fillRect(147, 110, 1, 5, wifi_off2);
    tft.fillRect(178, 110, 2, 6, pressureColor1);
    tft.fillRect(203, 110, 1, 5, wifi_off2);
    tft.fillRect(230, 110, 2, 6, pressureColor1);

    tft.fillRectHGradient(10, 50, 220, 55, pressureColor1, pressureColor2);

    statusBattery();
    subMenu();
}

// ------------------------------- FUNCAO CALENDARIO 

void calendarStyleMode0() {
    String stringDay = String(day);
    String stringMonth = String(month);
    String stringYear = String(year);
    String stringDayCount = String(dayCount);
    String stringWeekCount = String(weekCount);

    if (calendarFill == 0) {
        switch (month) {
            case 1: tft.fillRect(0, 109, 240, 131, januaryColor); calendarFill = 1; break;
            case 2: tft.fillRect(0, 109, 240, 131, februeryColor); calendarFill = 1; break;
            case 3: tft.fillRect(0, 109, 240, 131, marchColor); calendarFill = 1; break;
            case 4: tft.fillRect(0, 109, 240, 131, aprilColor); calendarFill = 1; break;
            case 5: tft.fillRect(0, 109, 240, 131, mayColor); calendarFill = 1; break;
            case 6: tft.fillRect(0, 109, 240, 131, juneColor); calendarFill = 1; break;
            case 7: tft.fillRect(0, 109, 240, 131, julyColor); calendarFill = 1; break;
            case 8: tft.fillRect(0, 109, 240, 131, augustColor); calendarFill = 1; break;
            case 9: tft.fillRect(0, 109, 240, 131, septemberColor); calendarFill = 1; break;
            case 10: tft.fillRect(0, 109, 240, 131, octoberColor); calendarFill = 1; break;
            case 11: tft.fillRect(0, 109, 240, 131, novemberColor); calendarFill = 1; break;
            case 12: tft.fillRect(0, 109, 240, 131, decemberColor); calendarFill = 1; break;
        }
    }
    switch (month) {
        case 1: tft.fillRect(30, 215, 205, 15, januaryColor); break;
        case 2: tft.fillRect(30, 215, 205, 15, februeryColor); break;
        case 3: tft.fillRect(30, 215, 205, 15, marchColor); break;
        case 4: tft.fillRect(30, 215, 205, 15, aprilColor); break;
        case 5: tft.fillRect(30, 215, 205, 15, mayColor); break;
        case 6: tft.fillRect(30, 215, 205, 15, juneColor); break;
        case 7: tft.fillRect(30, 215, 205, 15, julyColor); break;
        case 8: tft.fillRect(30, 215, 205, 15, augustColor); break;
        case 9: tft.fillRect(30, 215, 205, 15, septemberColor); break;
        case 10: tft.fillRect(30, 215, 205, 15, octoberColor); break;
        case 11: tft.fillRect(30, 215, 205, 15, novemberColor); break;
        case 12: tft.fillRect(30, 215, 205, 15, decemberColor); break;
    }

    tft.setTextDatum(ML_DATUM);
    tft.setTextColor(whiteScript);
    tft.setFreeFont(latoBold48);
    if (day < 10) {
        tft.drawString("0", 10, 60, GFXFF); 
        tft.drawString(stringDay, 42, 60, GFXFF);
    } else {
        tft.drawString(stringDay, 10, 60, GFXFF);
    }
    if (month < 10) {
        tft.drawString("0", 10, 135, GFXFF);
        tft.drawString(stringMonth, 42, 135, GFXFF);
    } else {
        tft.drawString(stringMonth, 10, 135, GFXFF);
    }
    tft.setFreeFont(latoRegular14);

    tft.drawString("WEEK", 150, 50, GFXFF);
    tft.drawString("DAY", 150, 65, GFXFF);

    tft.drawString(stringWeekCount, 210, 50, GFXFF);
    tft.drawString(stringDayCount, 210, 65, GFXFF);  

    switch (dayWeek) {
        case 1: tft.drawString(attWeekFull[dayWeek - 1], 8, 95, GFXFF); break; //CALIBRATED
        case 2: tft.drawString(attWeekFull[dayWeek - 1], 6, 95, GFXFF); break; //CALIBRATED
        case 3: tft.drawString(attWeekFull[dayWeek - 1], 5, 95, GFXFF); break; //CALIBRATED
        case 4: tft.drawString(attWeekFull[dayWeek - 1], 5, 95, GFXFF); break; //CALIBRATED
        case 5: tft.drawString(attWeekFull[dayWeek - 1], 5, 95, GFXFF); break; //CALIBRATED
        case 6: tft.drawString(attWeekFull[dayWeek - 1], 11, 95, GFXFF); break; //CALIBRATED
        case 7: tft.drawString(attWeekFull[dayWeek - 1], 5, 95, GFXFF); break; //CALIBRATED
    }

    switch (month) {
        case 1: tft.drawString(months[month - 1], 5, 170, GFXFF); break; //CALIBRATED
        case 2: tft.drawString(months[month - 1], 5, 170, GFXFF); break; //CALIBRATED
        case 3: tft.drawString(months[month - 1], 12, 170, GFXFF); break; //CALIBRATED
        case 4: tft.drawString(months[month - 1], 16, 170, GFXFF); break; //CALIBRATED
        case 5: tft.drawString(months[month - 1], 21, 170, GFXFF); break; //CALIBRATED
        case 6: tft.drawString(months[month - 1], 21, 170, GFXFF); break; //CALIBRATED
        case 7: tft.drawString(months[month - 1], 21, 170, GFXFF); break; //CALIBRATED
        case 8: tft.drawString(months[month - 1], 12, 170, GFXFF); break; //CALIBRATED
        case 9: tft.drawString(months[month - 1], 5, 170, GFXFF); break; //CALIBRATED
        case 10: tft.drawString(months[month - 1], 5, 170, GFXFF); break; //CALIBRATED
        case 11: tft.drawString(months[month - 1], 5, 170, GFXFF); break; //CALIBRATED
        case 12: tft.drawString(months[month - 1], 5, 170, GFXFF); break; //CALIBRATED
    }
    tft.setTextColor(blackScript);
    tft.drawString("S", 100, 125, GFXFF);
    tft.drawString("M", 120, 125, GFXFF);
    tft.drawString("T", 140, 125, GFXFF);
    tft.drawString("W", 160, 125, GFXFF);
    tft.drawString("T", 180, 125, GFXFF);
    tft.drawString("F", 200, 125, GFXFF);
    tft.drawString("S", 220, 125, GFXFF);          
                
    tft.setTextColor(whiteScript);
    tft.setFreeFont(latoBold24);
    tft.drawString(stringYear, 10, 200, GFXFF);

    statusBattery();
}

// ------------------------------- FUNCAO RELOGIO OPERACIONAL 

void timerStyleMode0() {
    String stringSec = String(secsBias);
    String stringMin = String(mins);

    byte timerSelectionMode = 0;
    byte fineSelectionMode = 0;
    
    tft.setTextDatum(ML_DATUM);
    tft.setTextColor(whiteScript);
    tft.setFreeFont(latoRegular14);
    tft.drawString("Mode", 32, 41, GFXFF);

    switch (timerSelectionMode) {
        case 0: tft.setTextColor(redScript); tft.setFreeFont(latoRegular14); tft.drawString("Timer", 80, 41, GFXFF); break;
        case 1: tft.setTextColor(redScript); tft.setFreeFont(latoRegular14); tft.drawString("Count", 80, 41, GFXFF); break;
        case 2: tft.setTextColor(redScript); tft.setFreeFont(latoRegular14); tft.drawString("Lap", 80, 41, GFXFF); break;
        case 3: tft.setTextColor(redScript); tft.setFreeFont(latoRegular14); tft.drawString("Alarm", 80, 41, GFXFF); break;
    }

    if (fineSelectionMode == 0) {
        tft.drawCircle (32, 81, 5, whiteScript);
    } else {
        tft.fillCircle (32, 81, 5, whiteScript);
    }
    tft.setTextColor(whiteScript);

    tft.drawString("Fine", 48, 80, GFXFF);
    tft.drawString("Alert", 143, 156, GFXFF);

    tft.setTextColor(yellowScript);
    tft.drawString("Increase", 32, 101, GFXFF);
    tft.drawString("Decrease", 32, 121, GFXFF);

    tft.setTextColor(greenScript);
    tft.drawString("Start", 32, 151, GFXFF);

    tft.setTextColor(redScript);
    tft.drawString("Reset", 32, 171, GFXFF);

    tft.drawCircle(178, 94, 50, whiteScript);
    tft.drawCircle(179, 95, 50, whiteScript);

    tft.setTextColor(whiteScript);
    tft.setFreeFont(latoBold24);

    tft.drawString(stringMin, 144, 90, GFXFF);
    tft.drawString(":", 174, 87, GFXFF);
    tft.drawString(stringSec, 184, 90, GFXFF);

     for (byte radi = 47; radi > 40; radi --) {
        for (int i = 270; i < 360; i++) {
            double radians = i * PI / 180;
            double px = 178 + radi * cos(radians);
            double py = 94 + radi * sin(radians);
            tft.drawPixel(px, py, redScript);
        }
    }

    statusBattery();
    subMenu();
}

// ------------------------------- FUNCAO AJUSTE RELOGIO E DATA

void ajustTimeStyleMode0() {

    if (secsBias != compareSecs) {
        tft.fillRect (163, 35, 60, 90, blackScript);
        tft.fillRect (158, 137, 62, 18, blackScript);
        compareSecs = secsBias;
    }
    if (mins != compareMins) {
        tft.fillRect (91, 35, 60, 90, blackScript);
        compareMins = mins;
    }
    if (hours != compareHour) {
        tft.fillRect (20, 35, 60, 90, blackScript);
        compareHour = hours;
    }


    String stringSec = String(secsBias);
    String stringSecMin = String(secsBias - 1);
    String stringSecMax = String(secsBias + 1);
    String stringMin = String(mins);
    String stringMinMin = String(mins - 1);
    String stringMinMax = String(mins + 1);        
    String stringHour = String(hours);
    String stringHourMin = String(hours - 1);
    String stringHourMax = String(hours + 1);

    tft.setTextDatum(ML_DATUM);
    tft.setTextColor(greyScript);
    tft.setFreeFont(latoBold24);

    if (hours == 23) {
        tft.drawString("00", 34, 42, GFXFF);
        tft.drawString(stringHourMin, 34, 104, GFXFF);
    } if (hours == 0) {
        tft.drawString("23", 34, 104, GFXFF);
        tft.drawString("0", 34, 42, GFXFF);
        tft.drawString(stringHourMax, 48, 42, GFXFF);
    } else if (hours < 11) {
        tft.drawString("0", 34, 104, GFXFF);
        tft.drawString(stringHourMin, 48, 104, GFXFF);
    } if (hours < 9) {
        tft.drawString("0", 34, 42, GFXFF);
        tft.drawString(stringHourMax, 48, 42, GFXFF); 
    } if ((hours == 9) || (hours == 10)) {
        tft.drawString(stringHourMax, 34, 42, GFXFF);
    } if ((hours > 10) && (hours < 23)) {
        tft.drawString(stringHourMin, 34, 104, GFXFF);
        tft.drawString(stringHourMax, 34, 42, GFXFF);
    }

    if (mins == 59) {
        tft.drawString("00", 106, 42, GFXFF);
        tft.drawString(stringMinMin, 106, 104, GFXFF);
    } if (mins == 0) {
        tft.drawString("59", 106, 104, GFXFF);
        tft.drawString("0", 106, 42, GFXFF);
        tft.drawString(stringMinMax, 120, 42, GFXFF);
    } else if (mins < 11) {
        tft.drawString("0", 106, 104, GFXFF);
        tft.drawString(stringMinMin, 120, 104, GFXFF);
    } if (mins < 9) {
        tft.drawString("0", 106, 42, GFXFF);
        tft.drawString(stringMinMax, 120, 42, GFXFF);
    } if ((mins == 9) || (mins == 10)) {
        tft.drawString(stringMinMax, 106, 42, GFXFF);
    } if ((mins > 10) && (mins < 59)) {
        tft.drawString(stringMinMin, 106, 104, GFXFF);
        tft.drawString(stringMinMax, 106, 42, GFXFF);
    }

    if (secsBias == 59) {
        tft.drawString("00", 178, 42, GFXFF);
        tft.drawString(stringSecMin, 178, 104, GFXFF);
    } if (secsBias == 0) {
        tft.drawString("59", 178, 104, GFXFF);
        tft.drawString("0", 178, 42, GFXFF);
        tft.drawString(stringSecMax, 192, 42, GFXFF);
    } else if (secsBias < 11) {
        tft.drawString("0", 178, 104, GFXFF);
        tft.drawString(stringSecMin, 192, 104, GFXFF);
    } if (secsBias < 9) {
        tft.drawString("0", 178, 42, GFXFF);
        tft.drawString(stringSecMax, 192, 42, GFXFF);
    } if ((secsBias == 9) || (secsBias == 10)) {
        tft.drawString(stringSecMax, 178, 42, GFXFF);
    } if ((secsBias > 10) && (secsBias < 59)) {
        tft.drawString(stringSecMin, 178, 104, GFXFF);
        tft.drawString(stringSecMax, 178, 42, GFXFF);
    }

    tft.setTextDatum(ML_DATUM);
    tft.setTextColor(redScript);
    tft.setFreeFont(latoBold48);
    if (hours < 10) {
        tft.drawString("0", 20, 73, GFXFF);
        tft.drawString(stringHour, 50, 73, GFXFF);                    
    } else {
        tft.drawString(stringHour, 20, 73, GFXFF);   
    }
    if (mins < 10) {
        tft.drawString("0", 92, 73, GFXFF);
        tft.drawString(stringMin, 122, 73, GFXFF);
    } else {
        tft.drawString(stringMin, 92, 73, GFXFF);
    }
    if (secsBias < 10) {
        tft.drawString("0", 164, 73, GFXFF);
        tft.drawString(stringSec, 194, 73, GFXFF);
    } else {
        tft.drawString(stringSec, 164, 73, GFXFF);
    }

    tft.setTextDatum(ML_DATUM);
    tft.setTextColor(whiteScript);
    tft.setFreeFont(latoRegular14);
    tft.drawString("Current", 102, 141, GFXFF);

    if (hours < 10) {
        tft.drawString("0", 158, 141, GFXFF);
        tft.drawString(stringHour, 167, 141, GFXFF); 
    } else {
        tft.drawString(stringHour, 159, 141, GFXFF); 
    }
             
    tft.drawString(":", 177, 141, GFXFF);

    if (mins < 10) {
        tft.drawString("0", 181, 141, GFXFF);
        tft.drawString(stringMin, 189, 141, GFXFF);
    } else {
        tft.drawString(stringMin, 181, 141, GFXFF);
    }

    tft.drawString(":", 199, 141, GFXFF);

    if (secsBias < 10) {
        tft.drawString("0", 203, 141, GFXFF);
        tft.drawString(stringSec, 211, 141, GFXFF);
    } else {
        tft.drawString(stringSec, 203, 141, GFXFF);
    }

    tft.setTextColor(greenScript);
    tft.drawString("Save", 25, 141, GFXFF);
    tft.setTextColor(redScript);
    tft.drawString("Settings", 25, 161, GFXFF);

    statusBattery();
    subMenu();
}

// ---------------------- CORRIGIR

void ajustDataStyleMode0() {
    String stringDay = String(day);
    String stringDayMin = String(day - 1);
    String stringDayMax = String(day + 1);
    String stringMonth = String(month);
    String stringMonthMin = String(month - 1);
    String stringMonthMax = String(month + 1);
    String stringYear = String(year);
    String stringYearMin = String(year - 1);
    String stringYearMax = String(year + 1);

    if (day != compareDay) {
        tft.fillRect (163, 35, 60, 90, blackScript);
        tft.fillRect (158, 137, 62, 18, blackScript);
        compareDay = day;
    }
    if (month != compareMonth) {
        tft.fillRect (91, 35, 60, 90, blackScript);
        compareMonth = month;
    }
    if (year != compareYear) {
        tft.fillRect (20, 35, 60, 90, blackScript);
        compareYear = year;
    }

    tft.setTextDatum(ML_DATUM);
    tft.setTextColor(greyScript);
    tft.setFreeFont(latoBold24);

    // VERIFICAR AS VARIAVEIS DE MES PARA A APLICAÇÃO
    if (day == 23) {
        tft.drawString("00", 34, 42, GFXFF);
        tft.drawString(stringDayMin, 34, 104, GFXFF);
    } if (day == 0) {
        tft.drawString("23", 34, 104, GFXFF);
        tft.drawString("0", 34, 42, GFXFF);
        tft.drawString(stringDayMax, 48, 42, GFXFF);
    } else if (day < 11) {
        tft.drawString("0", 34, 104, GFXFF);
        tft.drawString(stringDayMin, 48, 104, GFXFF);
    } if (day < 9) {
        tft.drawString("0", 34, 42, GFXFF);
        tft.drawString(stringDayMax, 48, 42, GFXFF); 
    } if ((day == 9) || (day == 10)) {
        tft.drawString(stringDayMax, 34, 42, GFXFF);
    } if ((day > 10) && (day < 23)) {
        tft.drawString(stringDayMin, 34, 104, GFXFF);
        tft.drawString(stringDayMax, 34, 42, GFXFF);
    }

    if (month == 12) {
        tft.drawString("00", 106, 42, GFXFF);
        tft.drawString(stringMonthMin, 106, 104, GFXFF);
    } if (month == 0) {
        tft.drawString("12", 106, 104, GFXFF);
        tft.drawString("0", 106, 42, GFXFF);
        tft.drawString(stringMonthMax, 120, 42, GFXFF);
    } else if (month < 11) {
        tft.drawString("0", 106, 104, GFXFF);
        tft.drawString(stringMonthMin, 120, 104, GFXFF);
    } if (month < 9) {
        tft.drawString("0", 106, 42, GFXFF);
        tft.drawString(stringMonthMax, 120, 42, GFXFF);
    } if ((month == 9) || (month == 10)) {
        tft.drawString(stringMonthMax, 106, 42, GFXFF);
    } if ((month > 10) && (month < 12)) {
        tft.drawString(stringMonthMin, 106, 104, GFXFF);
        tft.drawString(stringMonthMax, 106, 42, GFXFF);
    }
    if (year == 99) {
        tft.drawString("00", 178, 42, GFXFF);
        tft.drawString(stringYearMin, 178, 104, GFXFF);
    } if (year == 0) {
        tft.drawString("99", 178, 104, GFXFF);
        tft.drawString("0", 178, 42, GFXFF);
        tft.drawString(stringYearMax, 192, 42, GFXFF);
    } else if (year < 11) {
        tft.drawString("0", 178, 104, GFXFF);
        tft.drawString(stringYearMin, 192, 104, GFXFF);
    } if (year < 9) {
        tft.drawString("0", 178, 42, GFXFF);
        tft.drawString(stringYearMax, 192, 42, GFXFF);
    } if ((year == 9) || (year == 10)) {
        tft.drawString(stringYearMax, 178, 42, GFXFF);
    } if ((year > 10) && (year < 99)) {
        tft.drawString(stringYearMin, 178, 104, GFXFF);
        tft.drawString(stringYearMax, 178, 42, GFXFF);
    }

    tft.setTextDatum(ML_DATUM);
    tft.setTextColor(redScript);
    tft.setFreeFont(latoBold48);
    if (hours < 10) {
        tft.drawString("0", 20, 73, GFXFF);
        tft.drawString(stringDay, 50, 73, GFXFF);                    
    } else {
        tft.drawString(stringDay, 20, 73, GFXFF);   
    }
    if (mins < 10) {
        tft.drawString("0", 92, 73, GFXFF);
        tft.drawString(stringMonth, 122, 73, GFXFF);
    } else {
        tft.drawString(stringMonth, 92, 73, GFXFF);
    }
    if (secsBias < 10) {
        tft.drawString("0", 164, 73, GFXFF);
        tft.drawString(stringYear, 194, 73, GFXFF);
    } else {
        tft.drawString(stringYear, 164, 73, GFXFF);
    }
    tft.setTextDatum(ML_DATUM);
    tft.setTextColor(whiteScript);
    tft.setFreeFont(latoRegular14);
    tft.drawString("Current", 102, 141, GFXFF);

    if (hours < 10) {
        tft.drawString("0", 158, 141, GFXFF);
        tft.drawString(stringDay, 167, 141, GFXFF); 
    } else {
        tft.drawString(stringDay, 159, 141, GFXFF); 
    }
             
    tft.drawString(":", 177, 141, GFXFF);

    if (mins < 10) {
        tft.drawString("0", 181, 141, GFXFF);
        tft.drawString(stringMonth, 189, 141, GFXFF);
    } else {
        tft.drawString(stringMonth, 181, 141, GFXFF);
    }

    tft.drawString(":", 199, 141, GFXFF);
    if (secsBias < 10) {
        tft.drawString("0", 203, 141, GFXFF);
        tft.drawString(stringYear, 211, 141, GFXFF);
    } else {
        tft.drawString(stringYear, 203, 141, GFXFF);
    }

    tft.setTextColor(greenScript);
    tft.drawString("Save", 25, 141, GFXFF);
    tft.setTextColor(redScript);
    tft.drawString("Settings", 25, 161, GFXFF);
    statusBattery();
    subMenu();
}

// --------------------------------- FUNCAO AJUSTE DE BRILHO

void ajustBrightStyleMode0() {
    String stringBrightness = String(brightness);

    tft.drawRect(15, 158, 154, 20, whiteScript);
    tft.fillRectHGradient(16, 159, 74, 18, luxColor1, luxColor2);

    tft.fillRect(193, 66, 4, 120, whiteScript);

    tft.setTextDatum(ML_DATUM);
    tft.setTextColor(whiteScript);
    tft.setFreeFont(latoRegular14);

    tft.drawString("Mode", 31, 43, GFXFF);
    tft.drawString("Screen", 170, 43, GFXFF);
    tft.drawString("NBR 5413", 15, 185, GFXFF);
    tft.drawString("CLASSE", 105, 185, GFXFF);
    tft.drawString(stringBrightness, 60, 145, GFXFF);

    tft.setTextColor(greenScript);
    tft.drawString("Save", 31, 63, GFXFF);

    tft.setTextColor(blueScript);
    tft.drawString("Auto", 77, 43, GFXFF);

    tft.setTextColor(redScript);
    tft.drawString("A", 165, 185, GFXFF);

    tft.setFreeFont(latoBold24);
    tft.setTextColor(whiteScript);
    tft.drawString("Lux", 15, 140, GFXFF);

    subMenu();
    statusBattery();
}








// ------------------------------- FUNCAO CONTROLE ENTRADA MENUS ----------------------

void enterDisplayMenu(void) {

    if (displayTFT == 0) {
        upModeDisplay();
    }
}

void displayMenu() {
    startedPressingMode = 0;

    displayMode ++;
    if (displayMode == 1) {
        selectFunctionDisplay();
    } else if (displayMode == 2) {
        displayMode = 0;
    }
}

void selectFunctionDisplay() {
    // displayTFT = 0 Sistema aguardando comando
    // displayTFT = 1 Exibe display Geiger Simples
    // displayTFT = 2 Exibe display Dosimetro
    // displayTFT = 3 Exibe display Geiger Completo
    // displayTFT = 4 Exibe display Clima Simples
    // displayTFT = 5 Exibe display Clima Completo
    // displayTFT = 6 Exibe display Calendario 
    // displayTFT = 7 Exibe display Cronometro
    // displayTFT = 8 Exibe display Ajuste Relogio
    // displayTFT = 9 Exibe display Ajuste Data
    // displayTFT = 10 Exibe display Ajuste Brilho
    // displayTFT = 11 Exibe display Status Sensores

    if (sleepMode == 0) {
        if (displayTFT == 1 && displayMode == 1) {
            tft.fillScreen(blackScript);
            displayFlag = 1;
        } else if (displayTFT == 2 && displayMode == 1) {
            tft.fillScreen(blackScript);
            displayFlag = 2; 
        } else if (displayTFT == 3 && displayMode == 1) {
            tft.fillScreen(blackScript);
            displayFlag = 3;
        } else if (displayTFT == 4 && displayMode == 1) {
            tft.fillScreen(blackScript);
            displayFlag = 4;
        } else if (displayTFT == 5 && displayMode == 1) {
            tft.fillScreen(blackScript);
            displayFlag = 5;;
        } else if (displayTFT == 6 && displayMode == 1) {
            tft.fillScreen(blackScript);
            displayFlag = 6;
        } else if (displayTFT == 7 && displayMode == 1) {
            tft.fillScreen(blackScript);
            displayFlag = 7;
        } else if (displayTFT == 8 && displayMode == 1) {
            tft.fillScreen(blackScript);
            displayFlag = 8;
        } else if (displayTFT == 9 && displayMode == 1) {
            tft.fillScreen(blackScript);
            displayFlag = 9;
        } else if (displayTFT == 10 && displayMode == 1) { 
            tft.fillScreen(blackScript);
            displayFlag = 10;
        } else if (displayTFT == 11 && displayMode == 1) { 
            tft.fillScreen(blackScript);
            displayFlag = 11;
        } 
    }
}

void brightDisplayOff() {





    //APAGAR    
}

// ------------------------------- FUNCAO CONTROLE DO MENU ---------------------------

void upModeDisplay() {
    startedPressingUp = 0;
    displayMode = 1;

    if (sleepMode == 0) {
        displayTFT ++;
    } if (displayTFT > 11) {
        displayTFT = 1;
    }
}

void downModeDisplay() {
    startedPressingUp = 0;
    displayMode = 1;

    if (sleepMode == 0) {
    } if (displayTFT <= 1) {
        displayTFT = 11;
    } else if (displayTFT > 1) {
        displayTFT --;
    }
}

// ------------------------------- SETAS DO MENU DE SELECAO --------------------------

void triangletop() {

    tft.pushImage(15, 98, 26, 30, arrowUp);
}

void triangledown() {

    tft.pushImage(15, 98, 26, 30, arrowDown);
}

void triangleclear() {

    tft.pushImage(15, 100, 30, 26, arrowClean);
}

void triangleselection() {

    tft.pushImage(15, 100, 30, 26, arrowSelection);
}

// ------------------------------- CONTROLE LDR OPERACIONAL ---------------------------

void statusBright() {
    if (ldrPin == 0) {
        analogWrite(ldrPinPower, 255); // 255 3.301V
    } else if (timerMode == 1){
        analogWrite(ldrPinPower, 0);
    }

    brightSensor = analogRead(ldrSensor);
    brightness = map(brightSensor, 0, 1023, -200, 200);

    unsigned long brightTime = millis();
    int brightFunc;
    byte brightCalc;

    if (millis() - brightTime >= 50) {
        brightMedia[brightCalc] = brightness;
        brightCalc = brightCalc + 1;
    }   
    if (brightCalc == smoothBright) {
        for (brightCalc = smoothBright; brightCalc > 0; brightCalc --) {
            brightness = brightMedia[brightCalc];
            brightFunc = brightFunc + brightness;
        }
        brightness = brightFunc / smoothBright;
        if (brightness > maxBrightness) {
            brightness = maxBrightness;
        } else if (brightness < minBrightness) {
            brightness = minBrightness;
        }
    }
}

// ------------------------------- FUNCAO LEITURA BME280 --------------------------------------

void readBMEData() {
    double temp_act = 0.0, press_act = 0.0,hum_act=0.0;
    signed long int temp_cal;
    unsigned long int press_cal,hum_cal;
    if (millis() - timerBME >= updateBMEData) {
        readData();
        temp_cal = calibration_T(temp_raw);
        press_cal = calibration_P(pres_raw);
        hum_cal = calibration_H(hum_raw);
        temperature = (double)temp_cal / 100.0;
        pressure = (double)press_cal / 100.0;
        humidity = (double)hum_cal / 1024.0;    
        timerBME = millis();
    }
}

void readTrim() {
    uint8_t data[32],i=0;
    Wire.beginTransmission(BME280_ADDRESS);
    Wire.write(0x88);
    Wire.endTransmission();
    Wire.requestFrom(BME280_ADDRESS,24);
    while(Wire.available()){
        data[i] = Wire.read();
        i++;
    }
    
    Wire.beginTransmission(BME280_ADDRESS);
    Wire.write(0xA1);
    Wire.endTransmission();
    Wire.requestFrom(BME280_ADDRESS,1);
    data[i] = Wire.read();
    i++;
    
    Wire.beginTransmission(BME280_ADDRESS);
    Wire.write(0xE1);
    Wire.endTransmission();
    Wire.requestFrom(BME280_ADDRESS,7);
    while(Wire.available()){
        data[i] = Wire.read();
        i++;    
    }
    dig_T1 = (data[1] << 8) | data[0];
    dig_T2 = (data[3] << 8) | data[2];
    dig_T3 = (data[5] << 8) | data[4];
    dig_P1 = (data[7] << 8) | data[6];
    dig_P2 = (data[9] << 8) | data[8];
    dig_P3 = (data[11]<< 8) | data[10];
    dig_P4 = (data[13]<< 8) | data[12];
    dig_P5 = (data[15]<< 8) | data[14];
    dig_P6 = (data[17]<< 8) | data[16];
    dig_P7 = (data[19]<< 8) | data[18];
    dig_P8 = (data[21]<< 8) | data[20];
    dig_P9 = (data[23]<< 8) | data[22];
    dig_H1 = data[24];
    dig_H2 = (data[26]<< 8) | data[25];
    dig_H3 = data[27];
    dig_H4 = (data[28]<< 4) | (0x0F & data[29]);
    dig_H5 = (data[30] << 4) | ((data[29] >> 4) & 0x0F);
    dig_H6 = data[31];   
}

void writeReg(uint8_t reg_address, uint8_t data) {
    Wire.beginTransmission(BME280_ADDRESS);
    Wire.write(reg_address);
    Wire.write(data);
    Wire.endTransmission();    
}

void readData() {
    int i = 0;
    uint32_t data[8];
    Wire.beginTransmission(BME280_ADDRESS);
    Wire.write(0xF7);
    Wire.endTransmission();
    Wire.requestFrom(BME280_ADDRESS,8);
    while(Wire.available()) {
        data[i] = Wire.read();
        i++;
    }
    pres_raw = (data[0] << 12) | (data[1] << 4) | (data[2] >> 4);
    temp_raw = (data[3] << 12) | (data[4] << 4) | (data[5] >> 4);
    hum_raw  = (data[6] << 8) | data[7];
}


signed long int calibration_T(signed long int adc_T) {
    
    signed long int var1, var2, T;
    var1 = ((((adc_T >> 3) - ((signed long int)dig_T1<<1))) * ((signed long int)dig_T2)) >> 11;
    var2 = (((((adc_T >> 4) - ((signed long int)dig_T1)) * ((adc_T>>4) - ((signed long int)dig_T1))) >> 12) * ((signed long int)dig_T3)) >> 14;
    
    t_fine = var1 + var2;
    T = (t_fine * 5 + 128) >> 8;
    return T; 
}

unsigned long int calibration_P(signed long int adc_P) {
    signed long int var1, var2;
    unsigned long int P;
    var1 = (((signed long int)t_fine)>>1) - (signed long int)64000;
    var2 = (((var1>>2) * (var1>>2)) >> 11) * ((signed long int)dig_P6);
    var2 = var2 + ((var1*((signed long int)dig_P5))<<1);
    var2 = (var2>>2)+(((signed long int)dig_P4)<<16);
    var1 = (((dig_P3 * (((var1>>2)*(var1>>2)) >> 13)) >>3) + ((((signed long int)dig_P2) * var1)>>1))>>18;
    var1 = ((((32768+var1))*((signed long int)dig_P1))>>15);
    if (var1 == 0) {
        return 0;
    }    
    P = (((unsigned long int)(((signed long int)1048576)-adc_P)-(var2>>12)))*3125;
    if(P<0x80000000) {
       P = (P << 1) / ((unsigned long int) var1);   
    } else {
        P = (P / (unsigned long int)var1) * 2;    
    }
    var1 = (((signed long int)dig_P9) * ((signed long int)(((P>>3) * (P>>3))>>13)))>>12;
    var2 = (((signed long int)(P>>2)) * ((signed long int)dig_P8))>>13;
    P = (unsigned long int)((signed long int)P + ((var1 + var2 + dig_P7) >> 4));
    return P;
}

unsigned long int calibration_H(signed long int adc_H) {
    signed long int v_x1;
    
    v_x1 = (t_fine - ((signed long int)76800));
    v_x1 = (((((adc_H << 14) -(((signed long int)dig_H4) << 20) - (((signed long int)dig_H5) * v_x1)) + 
              ((signed long int)16384)) >> 15) * (((((((v_x1 * ((signed long int)dig_H6)) >> 10) * 
              (((v_x1 * ((signed long int)dig_H3)) >> 11) + ((signed long int) 32768))) >> 10) + (( signed long int)2097152)) * 
              ((signed long int) dig_H2) + 8192) >> 14));
   v_x1 = (v_x1 - (((((v_x1 >> 15) * (v_x1 >> 15)) >> 7) * ((signed long int)dig_H1)) >> 4));
   v_x1 = (v_x1 < 0 ? 0 : v_x1);
   v_x1 = (v_x1 > 419430400 ? 419430400 : v_x1);
   return (unsigned long int)(v_x1 >> 12);   
}



// ------------------------------- FUNCAO NIXIE WRITER ------------------------------------
void nixie() {
    if( upperSeconds >= 10)   upperSeconds = upperSeconds / 10;
    if( upperMins >= 10)      upperMins = upperMins / 10;
    if( upperHours >= 10)     upperHours = upperHours / 10;

    effectNixieSelected();

    // ------------ AJUSTAR AS VARIAVEIS AO PROGRAMA PADRÃO -----------------------

    numberArray[0] = upperHours;
    numberArray[1] = lowerHours;
    numberArray[2] = upperMins;
    numberArray[3] = lowerMins;

    DisplayNumberString(numberArray);
}

// void DisplayNumberString (int* array)
void DisplayNumberString (int* array) {
    DisplayNumberSet(0,array[0]);   
    DisplayNumberSet(1,array[1]);   
    DisplayNumberSet(2,array[2]);   
    DisplayNumberSet(3,array[3]);    
}

void DisplayNumberSet(int anod, int num1) {
    int anodPin;
    int a, b, c, d;

    anodPin =  pinAnode0;   

    switch(anod) {
        case 0:    anodPin =  pinAnode0;    break;
        case 1:    anodPin =  pinAnode1;    break;
        case 2:    anodPin =  pinAnode2;    break;
        case 3:    anodPin =  pinAnode3;    break;
    }  

    switch(num1) {
        case 0: a = 0; b = 0; c = 0; d = 0; break;
        case 1: a = 1; b = 0; c = 0; d = 0; break;
        case 2: a = 0; b = 1; c = 0; d = 0; break;
        case 3: a = 1; b = 1; c = 0; d = 0; break;
        case 4: a = 0; b = 0; c = 1; d = 0; break;
        case 5: a = 1; b = 0; c = 1; d = 0; break;
        case 6: a = 0; b = 1; c = 1; d = 0; break;
        case 7: a = 1; b = 1; c = 1; d = 0; break;
        case 8: a = 0; b = 0; c = 0; d = 1; break;
        case 9: a = 1; b = 0; c = 0; d = 1; break;
    }  
    
    // ---------------------------------- CORRIGIR ---------------------------------

    // ---------------------------------------------------------------------------

    digitalWrite(anodPin, HIGH);   
    //delay(refreshNixie);
    digitalWrite(anodPin, LOW);
}

void effectNixieSelected () {
    unsigned long nixieEffect = millis();

    if (effectModeNixie == 1) {
        if (compareTimeMins != mins) {
            if (millis() - nixieEffect >= speedEffect) {
                nixieEffect = millis();
                nixieCounts ++; 
                if (nixieAnode < 4) {
                    if (nixieCounts <= 10) {
                        switch (nixieCounts) {
                            case 1: flashNixie = 6; break;
                            case 2: flashNixie = 7; break;
                            case 3: flashNixie = 5; break;
                            case 4: flashNixie = 8; break;
                            case 5: flashNixie = 4; break;
                            case 6: flashNixie = 3; break;
                            case 7: flashNixie = 9; break;
                            case 8: flashNixie = 2; break;
                            case 9: flashNixie = 0; break;
                            case 10: flashNixie = 1; break;
                        }
                    }  
                    numberArray[nixieAnode] = flashNixie;
                    prt = &nixieAnode;
                    DisplayNumberString(prt);
                }
                if (nixieCounts > 9) {
                    nixieCounts = 0;
                    numberArray[0] = upperHours; 
                    numberArray[1] = lowerHours;
                    numberArray[2] = upperMins;
                    numberArray[3] = lowerMins;
                    DisplayNumberString(prt);
                    nixieAnode ++;
                } 
                if (nixieAnode == 4) {
                    nixieAnode = 0;
                    compareTimeMins = mins;
                }
            }
        }
    }
    if (effectModeNixie == 2) {
        if (compareTimeMins != mins) {
            if (millis() - nixieEffect >= speedEffect) {
                nixieEffect = millis();
                nixieCounts ++; 
                if (nixieAnode < 4) {
                    if (nixieCounts <= 10) {
                        switch (nixieCounts) {
                            case 1: flashNixie = 9; break;
                            case 2: flashNixie = 8; break;
                            case 3: flashNixie = 7; break;
                            case 4: flashNixie = 6; break;
                            case 5: flashNixie = 5; break;
                            case 6: flashNixie = 4; break;
                            case 7: flashNixie = 3; break;
                            case 8: flashNixie = 2; break;
                            case 9: flashNixie = 1; break;
                            case 10: flashNixie = 0; break;
                        }
                    }  
                    numberArray[nixieAnode] = flashNixie;
                    DisplayNumberString(prt);
                }
                if (nixieCounts > 9) {
                    nixieCounts = 0;
                    numberArray[0] = upperHours; 
                    numberArray[1] = lowerHours;
                    numberArray[2] = upperMins;
                    numberArray[3] = lowerMins;
                    DisplayNumberString(prt);
                    nixieAnode ++;
                } 
                if (nixieAnode == 4) {
                    nixieAnode = 0;
                    compareTimeMins = mins;
                }
            }
        }
    } else {
        numberArray[0] = upperHours;
        numberArray[1] = lowerHours;
        numberArray[2] = upperMins;
        numberArray[3] = lowerMins;
    }
}







void errorTime() {
    /*
    writerSecs = secs;

    tft.setCursor(10, 20);
    tft.setTextSize(1);
    tft.setTextColor(whiteScript);
    tft.setTextFont(2);
    tft.println("Fail Value");
    
    tft.setTextFont(3);
    tft.setTextColor(yellow_battery);
    tft.setCursor(10, 40);
    tft.println("Tempr.");
    tft.setCursor(10, 55);
    tft.println("Humid.");
    tft.setCursor(10, 70);
    tft.println("Press.");
    tft.setCursor(10, 85);
    tft.println("Geigr.");
    tft.setCursor(10, 100);
    tft.println("Brigh.");
    tft.setCursor(10, 115);
    tft.println("  Day.");
    tft.setCursor(10, 130);
    tft.println("Month.");
    tft.setCursor(10, 145);
    tft.println(" Year.");
    tft.setCursor(10, 160);
    tft.println("DTemp.");
    tft.setCursor(10, 175);
    tft.println("DHumi.");
    tft.setCursor(10, 190);
    tft.println("DPres.");
    tft.setCursor(10, 205);
    tft.println("DGeig.");
    tft.setCursor(10, 220);
    tft.println("Zambr.");
    tft.setCursor(10, 235);
    tft.println(" Time.");

    tft.setTextColor(green_battery);
    tft.setCursor(80, 40);
    tft.println(temperature);
    tft.setCursor(80, 55);
    tft.println(humidity);
    tft.setCursor(80, 70);
    tft.println(pressure);
    tft.setCursor(80, 85);
    tft.println(geigerSensor);
    tft.setCursor(80, 100);
    tft.println(brightness);
    tft.setCursor(80, 115);
    tft.println(day);
    tft.setCursor(80, 130);
    tft.println(month);
    tft.setCursor(80, 145);
    tft.println(year);
    tft.setCursor(80, 160);
    tft.println(writerTemp);
    tft.setCursor(80, 175);
    tft.println(writerHumi);
    tft.setCursor(80, 190);
    tft.println(writerPres);
    tft.setCursor(80, 205);
    tft.println(writerGeiger);
    tft.setCursor(80, 220);
    tft.println(zambretti);
    tft.setCursor(80, 235);
    tft.println(time);
    */
}

// ------------------------------- SIMBOLO CLIMATICOS -----------

void cleanWeather() {
    tft.drawCircle(163, 73, 14, whiteScript);
    tft.drawCircle(163, 73, 13, whiteScript);
    tft.drawCircle(163, 73, 12, whiteScript);

    tft.drawCircle(174, 61, 14, whiteScript);
    tft.drawCircle(174, 61, 13, whiteScript);
    tft.drawCircle(174, 61, 12, whiteScript);

    tft.drawCircle(197, 54, 19, whiteScript);
    tft.drawCircle(197, 54, 18, whiteScript);
    tft.drawCircle(197, 54, 17, whiteScript);

    tft.drawCircle(215, 73, 14, whiteScript);
    tft.drawCircle(215, 73, 13, whiteScript);
    tft.drawCircle(215, 73, 12, whiteScript);

    tft.drawLine(163, 85, 173, 85, whiteScript);
    tft.drawLine(163, 86, 173, 86, whiteScript);
    tft.drawLine(163, 87, 173, 87, whiteScript);

    tft.drawLine(215, 85, 208, 85, whiteScript);
    tft.drawLine(215, 86, 208, 86, whiteScript);
    tft.drawLine(215, 87, 208, 87, whiteScript);

    tft.fillRect(163, 59, 52, 27,  blackScript);   
    tft.fillRect(158, 62, 5, 10, blackScript);
    tft.fillRect(175, 50, 15, 15, blackScript);
}

void cloudWeather() {
    tft.drawCircle(163, 73, 14, whiteScript);
    tft.drawCircle(163, 73, 13, whiteScript);
    tft.drawCircle(163, 73, 12, whiteScript);

    tft.drawCircle(174, 61, 14, whiteScript);
    tft.drawCircle(174, 61, 13, whiteScript);
    tft.drawCircle(174, 61, 12, whiteScript);

    tft.drawCircle(197, 54, 19, whiteScript);
    tft.drawCircle(197, 54, 18, whiteScript);
    tft.drawCircle(197, 54, 17, whiteScript);

    tft.drawCircle(215, 73, 14, whiteScript);
    tft.drawCircle(215, 73, 13, whiteScript);
    tft.drawCircle(215, 73, 12, whiteScript);

    tft.drawLine(163, 85, 173, 85, whiteScript);
    tft.drawLine(163, 86, 173, 86, whiteScript);
    tft.drawLine(163, 87, 173, 87, whiteScript);

    tft.drawLine(163, 85, 215, 85, whiteScript);
    tft.drawLine(163, 86, 215, 86, whiteScript);
    tft.drawLine(163, 87, 215, 87, whiteScript);

    tft.fillRect(163, 59, 52, 27,  blackScript);   
    tft.fillRect(158, 62, 5, 10, blackScript);
    tft.fillRect(175, 50, 15, 15, blackScript);
}

void sereneWeather() {
    tft.drawCircle(163, 73, 14, whiteScript);
    tft.drawCircle(163, 73, 13, whiteScript);
    tft.drawCircle(163, 73, 12, whiteScript);

    tft.drawCircle(174, 61, 14, whiteScript);
    tft.drawCircle(174, 61, 13, whiteScript);
    tft.drawCircle(174, 61, 12, whiteScript);

    tft.drawCircle(197, 54, 19, whiteScript);
    tft.drawCircle(197, 54, 18, whiteScript);
    tft.drawCircle(197, 54, 17, whiteScript);

    tft.drawCircle(215, 73, 14, whiteScript);
    tft.drawCircle(215, 73, 13, whiteScript);
    tft.drawCircle(215, 73, 12, whiteScript);

    tft.drawLine(163, 85, 173, 85, whiteScript);
    tft.drawLine(163, 86, 173, 86, whiteScript);
    tft.drawLine(163, 87, 173, 87, whiteScript);

    tft.drawLine(215, 85, 208, 85, whiteScript);
    tft.drawLine(215, 86, 208, 86, whiteScript);
    tft.drawLine(215, 87, 208, 87, whiteScript);

    tft.fillRect(163, 59, 52, 27,  blackScript);   
    tft.fillRect(158, 62, 5, 10, blackScript);
    tft.fillRect(175, 50, 15, 15, blackScript);

    tft.fillCircle(188, 86, 3, drizzleColor);
    tft.fillCircle(188, 108, 3, drizzleColor);
    tft.fillCircle(178, 97, 3, drizzleColor);
    tft.fillCircle(198, 97, 3, drizzleColor);
}

void drizzleWeather() {
    tft.drawCircle(163, 73, 14, whiteScript);
    tft.drawCircle(163, 73, 13, whiteScript);
    tft.drawCircle(163, 73, 12, whiteScript);

    tft.drawCircle(174, 61, 14, whiteScript);
    tft.drawCircle(174, 61, 13, whiteScript);
    tft.drawCircle(174, 61, 12, whiteScript);

    tft.drawCircle(197, 54, 19, whiteScript);
    tft.drawCircle(197, 54, 18, whiteScript);
    tft.drawCircle(197, 54, 17, whiteScript);

    tft.drawCircle(215, 73, 14, whiteScript);
    tft.drawCircle(215, 73, 13, whiteScript);
    tft.drawCircle(215, 73, 12, whiteScript);

    tft.drawLine(163, 85, 173, 85, whiteScript);
    tft.drawLine(163, 86, 173, 86, whiteScript);
    tft.drawLine(163, 87, 173, 87, whiteScript);

    tft.drawLine(215, 85, 208, 85, whiteScript);
    tft.drawLine(215, 86, 208, 86, whiteScript);
    tft.drawLine(215, 87, 208, 87, whiteScript);

    tft.drawRect(150, 35, 80, 80,  greenScript);   

    tft.fillRect(163, 59, 52, 27,  blackScript);   
    tft.fillRect(158, 62, 5, 10, blackScript);
    tft.fillRect(175, 50, 15, 15, blackScript);

    tft.fillCircle(180, 86, 2.5, rainColor);
    tft.fillCircle(190, 86, 2.5, rainColor);
    tft.fillCircle(200, 86, 2.5, rainColor);

    tft.drawLine(177, 86, 173, 94, rainColor);
    tft.drawLine(178, 86, 174, 94, rainColor);
    tft.drawLine(179, 86, 175, 94, rainColor);
    tft.drawLine(180, 86, 176, 94, rainColor);
    tft.drawLine(181, 86, 177, 94, rainColor);
    tft.drawLine(182, 86, 178, 94, rainColor);

    tft.drawLine(187, 86, 183, 94, rainColor);
    tft.drawLine(188, 86, 184, 94, rainColor);
    tft.drawLine(189, 86, 185, 94, rainColor);
    tft.drawLine(190, 86, 186, 94, rainColor);
    tft.drawLine(191, 86, 187, 94, rainColor);
    tft.drawLine(192, 86, 188, 94, rainColor);

    tft.drawLine(197, 86, 193, 94, rainColor);
    tft.drawLine(198, 86, 194, 94, rainColor);
    tft.drawLine(199, 86, 195, 94, rainColor);
    tft.drawLine(200, 86, 196, 94, rainColor);
    tft.drawLine(201, 86, 197, 94, rainColor);
    tft.drawLine(202, 86, 198, 94, rainColor);

    tft.fillCircle(176, 94, 2.5, rainColor);
    tft.fillCircle(186, 94, 2.5, rainColor);
    tft.fillCircle(196, 94, 2.5, rainColor);

    tft.fillCircle(172, 102, 2.5, rainColor);
    tft.fillCircle(182, 102, 2.5, rainColor);
    tft.fillCircle(192, 102, 2.5, rainColor);

    tft.drawLine(169, 102, 165, 110, rainColor);
    tft.drawLine(170, 102, 166, 110, rainColor);
    tft.drawLine(171, 102, 167, 110, rainColor);
    tft.drawLine(172, 102, 168, 110, rainColor);
    tft.drawLine(173, 102, 169, 110, rainColor);
    tft.drawLine(174, 102, 170, 110, rainColor);

    tft.drawLine(179, 102, 175, 110, rainColor);
    tft.drawLine(180, 102, 176, 110, rainColor);
    tft.drawLine(181, 102, 177, 110, rainColor);
    tft.drawLine(182, 102, 178, 110, rainColor);
    tft.drawLine(183, 102, 179, 110, rainColor);
    tft.drawLine(184, 102, 180, 110, rainColor);

    tft.drawLine(189, 102, 185, 110, rainColor);
    tft.drawLine(190, 102, 186, 110, rainColor);
    tft.drawLine(191, 102, 187, 110, rainColor);
    tft.drawLine(192, 102, 188, 110, rainColor);
    tft.drawLine(193, 102, 189, 110, rainColor);
    tft.drawLine(194, 102, 190, 110, rainColor);

    tft.fillCircle(168, 110, 2.5, rainColor);
    tft.fillCircle(178, 110, 2.5, rainColor);
    tft.fillCircle(188, 110, 2.5, rainColor);
}

void thunderWeather() {
    tft.drawCircle(163, 73, 14, whiteScript);
    tft.drawCircle(163, 73, 13, whiteScript);
    tft.drawCircle(163, 73, 12, whiteScript);

    tft.drawCircle(174, 61, 14, whiteScript);
    tft.drawCircle(174, 61, 13, whiteScript);
    tft.drawCircle(174, 61, 12, whiteScript);

    tft.drawCircle(197, 54, 19, whiteScript);
    tft.drawCircle(197, 54, 18, whiteScript);
    tft.drawCircle(197, 54, 17, whiteScript);

    tft.drawCircle(215, 73, 14, whiteScript);
    tft.drawCircle(215, 73, 13, whiteScript);
    tft.drawCircle(215, 73, 12, whiteScript);

    tft.drawLine(163, 85, 173, 85, whiteScript);
    tft.drawLine(163, 86, 173, 86, whiteScript);
    tft.drawLine(163, 87, 173, 87, whiteScript);

    tft.drawLine(215, 85, 208, 85, whiteScript);
    tft.drawLine(215, 86, 208, 86, whiteScript);
    tft.drawLine(215, 87, 208, 87, whiteScript);

    tft.drawRect(150, 35, 80, 80,  greenScript);   

    tft.fillRect(163, 59, 52, 27,  blackScript);   
    tft.fillRect(158, 62, 5, 10, blackScript);
    tft.fillRect(175, 50, 15, 15, blackScript);

    tft.fillCircle(195, 70, 2.5, sunColor);

    tft.drawLine(178, 92, 193, 70, sunColor);
    tft.drawLine(179, 92, 194, 70, sunColor);
    tft.drawLine(180, 92, 195, 70, sunColor);
    tft.drawLine(181, 92, 196, 70, sunColor);
    tft.drawLine(182, 92, 197, 70, sunColor);

    tft.drawLine(182, 92, 195, 92, sunColor);
    tft.drawLine(183, 91, 196, 91, sunColor);
    tft.drawLine(184, 90, 197, 90, sunColor);
    tft.drawLine(185, 89, 198, 89, sunColor);
    tft.drawLine(186, 88, 199, 88, sunColor);

    tft.drawLine(180, 110, 195, 88, sunColor);
    tft.drawLine(181, 110, 196, 88, sunColor);
    tft.drawLine(182, 110, 197, 88, sunColor);
    tft.drawLine(183, 110, 198, 88, sunColor);
    tft.drawLine(184, 110, 199, 88, sunColor);

    tft.fillCircle(182, 110, 2.5, sunColor);
}

void stormWeather() {
    tft.drawCircle(163, 73, 14, whiteScript);
    tft.drawCircle(163, 73, 13, whiteScript);
    tft.drawCircle(163, 73, 12, whiteScript);

    tft.drawCircle(174, 61, 14, whiteScript);
    tft.drawCircle(174, 61, 13, whiteScript);
    tft.drawCircle(174, 61, 12, whiteScript);

    tft.drawCircle(197, 54, 19, whiteScript);
    tft.drawCircle(197, 54, 18, whiteScript);
    tft.drawCircle(197, 54, 17, whiteScript);

    tft.drawCircle(215, 73, 14, whiteScript);
    tft.drawCircle(215, 73, 13, whiteScript);
    tft.drawCircle(215, 73, 12, whiteScript);

    tft.drawLine(163, 85, 173, 85, whiteScript);
    tft.drawLine(163, 86, 173, 86, whiteScript);
    tft.drawLine(163, 87, 173, 87, whiteScript);

    tft.drawLine(215, 85, 208, 85, whiteScript);
    tft.drawLine(215, 86, 208, 86, whiteScript);
    tft.drawLine(215, 87, 208, 87, whiteScript);

    tft.fillRect(163, 59, 52, 27,  blackScript);   
    tft.fillRect(158, 62, 5, 10, blackScript);
    tft.fillRect(175, 50, 15, 15, blackScript);

    tft.fillCircle(195, 70, 2.5, sunColor);
    tft.drawLine(178, 92, 193, 70, sunColor);
    tft.drawLine(179, 92, 194, 70, sunColor);
    tft.drawLine(180, 92, 195, 70, sunColor);
    tft.drawLine(181, 92, 196, 70, sunColor);
    tft.drawLine(182, 92, 197, 70, sunColor);
    tft.drawLine(182, 92, 195, 92, sunColor);
    tft.drawLine(183, 91, 196, 91, sunColor);
    tft.drawLine(184, 90, 197, 90, sunColor);
    tft.drawLine(185, 89, 198, 89, sunColor);
    tft.drawLine(186, 88, 199, 88, sunColor);
    tft.drawLine(180, 110, 195, 88, sunColor);
    tft.drawLine(181, 110, 196, 88, sunColor);
    tft.drawLine(182, 110, 197, 88, sunColor);
    tft.drawLine(183, 110, 198, 88, sunColor);
    tft.drawLine(184, 110, 199, 88, sunColor);
    tft.fillCircle(182, 110, 2.5, sunColor);

    tft.fillCircle(160, 96, 2.5, rainColor);
    tft.drawLine(158, 96, 153, 105, rainColor);
    tft.drawLine(159, 96, 154, 105, rainColor);
    tft.drawLine(160, 96, 155, 105, rainColor);
    tft.drawLine(161, 96, 156, 105, rainColor);
    tft.drawLine(162, 96, 157, 105, rainColor);
    tft.fillCircle(155, 105, 2.5, rainColor);

    tft.fillCircle(170, 96, 2.5, rainColor);
    tft.drawLine(168, 96, 163, 105, rainColor);
    tft.drawLine(169, 96, 164, 105, rainColor);
    tft.drawLine(170, 96, 165, 105, rainColor);
    tft.drawLine(171, 96, 166, 105, rainColor);
    tft.drawLine(172, 96, 167, 105, rainColor);
    tft.fillCircle(165, 105, 2.5, rainColor);

    tft.fillCircle(205, 96, 2.5, rainColor);
    tft.drawLine(203, 96, 198, 105, rainColor);
    tft.drawLine(204, 96, 199, 105, rainColor);
    tft.drawLine(205, 96, 200, 105, rainColor);
    tft.drawLine(206, 96, 201, 105, rainColor);
    tft.drawLine(207, 96, 202, 105, rainColor);
    tft.fillCircle(200, 105, 2.5, rainColor);

    tft.fillCircle(215, 96, 2.5, rainColor);
    tft.drawLine(213, 96, 208, 105, rainColor);
    tft.drawLine(214, 96, 209, 105, rainColor);
    tft.drawLine(215, 96, 210, 105, rainColor);
    tft.drawLine(216, 96, 211, 105, rainColor);
    tft.drawLine(217, 96, 212, 105, rainColor);
    tft.fillCircle(210, 105, 2.5, rainColor);
}

void tempestWeather() {
    tft.drawCircle(163, 73, 14, whiteScript);
    tft.drawCircle(163, 73, 13, whiteScript);
    tft.drawCircle(163, 73, 12, whiteScript);

    tft.drawCircle(174, 61, 14, whiteScript);
    tft.drawCircle(174, 61, 13, whiteScript);
    tft.drawCircle(174, 61, 12, whiteScript);

    tft.drawCircle(197, 54, 19, whiteScript);
    tft.drawCircle(197, 54, 18, whiteScript);
    tft.drawCircle(197, 54, 17, whiteScript);

    tft.drawCircle(215, 73, 14, whiteScript);
    tft.drawCircle(215, 73, 13, whiteScript);
    tft.drawCircle(215, 73, 12, whiteScript);

    tft.drawLine(163, 85, 173, 85, whiteScript);
    tft.drawLine(163, 86, 173, 86, whiteScript);
    tft.drawLine(163, 87, 173, 87, whiteScript);

    tft.drawLine(215, 85, 208, 85, whiteScript);
    tft.drawLine(215, 86, 208, 86, whiteScript);
    tft.drawLine(215, 87, 208, 87, whiteScript);

    tft.fillRect(163, 59, 52, 27,  blackScript);   
    tft.fillRect(158, 62, 5, 10, blackScript);
    tft.fillRect(175, 50, 15, 15, blackScript);

    tft.drawRect(150, 35, 80, 80,  greenScript);

    tft.fillCircle(183, 78, 2.5, rainColor);
    tft.fillCircle(193, 78, 2.5, rainColor);
    tft.fillCircle(203, 78, 2.5, rainColor);

    tft.drawLine(181, 78, 171, 100, rainColor);
    tft.drawLine(182, 78, 172, 100, rainColor);
    tft.drawLine(183, 78, 173, 100, rainColor);
    tft.drawLine(184, 78, 174, 100, rainColor);
    tft.drawLine(185, 78, 175, 100, rainColor);

    tft.drawLine(191, 78, 177, 110, rainColor);
    tft.drawLine(192, 78, 178, 110, rainColor);
    tft.drawLine(193, 78, 179, 110, rainColor);
    tft.drawLine(194, 78, 180, 110, rainColor);
    tft.drawLine(195, 78, 181, 110, rainColor);

    tft.drawLine(201, 78, 191, 100, rainColor);
    tft.drawLine(202, 78, 192, 100, rainColor);
    tft.drawLine(203, 78, 193, 100, rainColor);
    tft.drawLine(204, 78, 194, 100, rainColor);
    tft.drawLine(205, 78, 195, 100, rainColor);

    tft.fillCircle(173, 100, 2.5, rainColor);
    tft.fillCircle(179, 110, 2.5, rainColor);
    tft.fillCircle(193, 100, 2.5, rainColor);
}

void seTempestWeather() {
    tft.drawCircle(163, 73, 14, whiteScript);
    tft.drawCircle(163, 73, 13, whiteScript);
    tft.drawCircle(163, 73, 12, whiteScript);

    tft.drawCircle(174, 61, 14, whiteScript);
    tft.drawCircle(174, 61, 13, whiteScript);
    tft.drawCircle(174, 61, 12, whiteScript);

    tft.drawCircle(197, 54, 19, whiteScript);
    tft.drawCircle(197, 54, 18, whiteScript);
    tft.drawCircle(197, 54, 17, whiteScript);

    tft.drawCircle(215, 73, 14, whiteScript);
    tft.drawCircle(215, 73, 13, whiteScript);
    tft.drawCircle(215, 73, 12, whiteScript);

    tft.drawLine(163, 85, 173, 85, whiteScript);
    tft.drawLine(163, 86, 173, 86, whiteScript);
    tft.drawLine(163, 87, 173, 87, whiteScript);

    tft.drawLine(215, 85, 208, 85, whiteScript);
    tft.drawLine(215, 86, 208, 86, whiteScript);
    tft.drawLine(215, 87, 208, 87, whiteScript);

    tft.fillRect(163, 59, 52, 27,  blackScript);   
    tft.fillRect(158, 62, 5, 10, blackScript);
    tft.fillRect(175, 50, 15, 15, blackScript);

    tft.drawRect(150, 35, 80, 80,  greenScript);

    tft.fillCircle(183, 78, 2.5, rainColor);
    tft.fillCircle(193, 78, 2.5, rainColor);
    tft.fillCircle(203, 78, 2.5, rainColor);

    tft.drawLine(181, 78, 171, 100, rainColor);
    tft.drawLine(182, 78, 172, 100, rainColor);
    tft.drawLine(183, 78, 173, 100, rainColor);
    tft.drawLine(184, 78, 174, 100, rainColor);
    tft.drawLine(185, 78, 175, 100, rainColor);

    tft.drawLine(191, 78, 181, 100, rainColor);
    tft.drawLine(192, 78, 182, 100, rainColor);
    tft.drawLine(193, 78, 183, 100, rainColor);
    tft.drawLine(194, 78, 184, 100, rainColor);
    tft.drawLine(195, 78, 185, 100, rainColor);

    tft.drawLine(201, 78, 191, 100, rainColor);
    tft.drawLine(202, 78, 192, 100, rainColor);
    tft.drawLine(203, 78, 193, 100, rainColor);
    tft.drawLine(204, 78, 194, 100, rainColor);
    tft.drawLine(205, 78, 195, 100, rainColor);

    tft.fillCircle(173, 100, 2.5, rainColor);
    tft.fillCircle(183, 100, 2.5, rainColor);
    tft.fillCircle(193, 100, 2.5, rainColor);

    tft.fillCircle(170, 110, 3, drizzleColor);
    tft.fillCircle(180, 110, 3, drizzleColor);
    tft.fillCircle(190, 110, 3, drizzleColor);
}

void hailWeather() {
    tft.drawCircle(163, 73, 14, whiteScript);
    tft.drawCircle(163, 73, 13, whiteScript);
    tft.drawCircle(163, 73, 12, whiteScript);

    tft.drawCircle(174, 61, 14, whiteScript);
    tft.drawCircle(174, 61, 13, whiteScript);
    tft.drawCircle(174, 61, 12, whiteScript);

    tft.drawCircle(197, 54, 19, whiteScript);
    tft.drawCircle(197, 54, 18, whiteScript);
    tft.drawCircle(197, 54, 17, whiteScript);

    tft.drawCircle(215, 73, 14, whiteScript);
    tft.drawCircle(215, 73, 13, whiteScript);
    tft.drawCircle(215, 73, 12, whiteScript);

    tft.drawLine(163, 85, 173, 85, whiteScript);
    tft.drawLine(163, 86, 173, 86, whiteScript);
    tft.drawLine(163, 87, 173, 87, whiteScript);

    tft.drawLine(215, 85, 208, 85, whiteScript);
    tft.drawLine(215, 86, 208, 86, whiteScript);
    tft.drawLine(215, 87, 208, 87, whiteScript);

    tft.fillRect(163, 59, 52, 27,  blackScript);   
    tft.fillRect(158, 62, 5, 10, blackScript);
    tft.fillRect(175, 50, 15, 15, blackScript);

    tft.drawRect(150, 35, 80, 80,  greenScript);

    tft.fillCircle(190, 80, 2.5, drizzleColor);
    tft.fillRect(188, 80, 5, 12, drizzleColor);

    tft.fillCircle(182, 87, 2.5, drizzleColor);

    tft.drawLine(180, 87, 196, 103, drizzleColor);    
    tft.drawLine(181, 87, 197, 103, drizzleColor);
    tft.drawLine(182, 87, 198, 103, drizzleColor);
    tft.drawLine(183, 87, 199, 103, drizzleColor);
    tft.drawLine(184, 87, 200, 103, drizzleColor);

    tft.fillCircle(198, 87, 2.5, drizzleColor);  


    tft.fillCircle(175, 95, 2.5, drizzleColor);
    tft.fillRect(177, 93, 12, 5, drizzleColor);

    tft.fillCircle(190, 95, 5, drizzleColor);

    tft.fillRect(194, 93, 12, 5, drizzleColor);
    tft.fillCircle(205, 95, 2.5, drizzleColor);

    tft.fillCircle(182, 103, 2.5, drizzleColor);

    tft.drawLine(180, 103, 196, 87, drizzleColor);
    tft.drawLine(181, 103, 197, 87, drizzleColor);
    tft.drawLine(182, 103, 198, 87, drizzleColor);
    tft.drawLine(183, 103, 199, 87, drizzleColor);
    tft.drawLine(184, 103, 200, 87, drizzleColor);

    tft.fillCircle(198, 103, 2.5, drizzleColor);


    tft.fillRect(188, 98, 5, 12, drizzleColor);
    tft.fillCircle(190, 110, 2.5, drizzleColor);  

    tft.fillCircle(190, 95, 2, blackScript);
}

void seRainWeather() {
    tft.drawCircle(163, 73, 14, whiteScript);
    tft.drawCircle(163, 73, 13, whiteScript);
    tft.drawCircle(163, 73, 12, whiteScript);

    tft.drawCircle(174, 61, 14, whiteScript);
    tft.drawCircle(174, 61, 13, whiteScript);
    tft.drawCircle(174, 61, 12, whiteScript);

    tft.drawCircle(197, 54, 19, whiteScript);
    tft.drawCircle(197, 54, 18, whiteScript);
    tft.drawCircle(197, 54, 17, whiteScript);

    tft.drawCircle(215, 73, 14, whiteScript);
    tft.drawCircle(215, 73, 13, whiteScript);
    tft.drawCircle(215, 73, 12, whiteScript);

    tft.drawLine(163, 85, 173, 85, whiteScript);
    tft.drawLine(163, 86, 173, 86, whiteScript);
    tft.drawLine(163, 87, 173, 87, whiteScript);

    tft.drawLine(215, 85, 208, 85, whiteScript);
    tft.drawLine(215, 86, 208, 86, whiteScript);
    tft.drawLine(215, 87, 208, 87, whiteScript);

    tft.fillRect(163, 59, 52, 27,  blackScript);   
    tft.fillRect(158, 62, 5, 10, blackScript);
    tft.fillRect(175, 50, 15, 15, blackScript);

    tft.drawRect(150, 35, 80, 80,  greenScript);

    tft.fillCircle(187, 78, 2.5, rainColor);
    tft.fillCircle(200, 78, 2.5, rainColor);

    tft.drawLine(185, 78, 180, 90, rainColor);
    tft.drawLine(186, 78, 181, 90, rainColor);
    tft.drawLine(187, 78, 182, 90, rainColor);
    tft.drawLine(188, 78, 183, 90, rainColor);
    tft.drawLine(189, 78, 184, 90, rainColor);

    tft.drawLine(198, 78, 188, 100, rainColor);
    tft.drawLine(199, 78, 189, 100, rainColor);
    tft.drawLine(200, 78, 190, 100, rainColor);
    tft.drawLine(201, 78, 191, 100, rainColor);
    tft.drawLine(202, 78, 192, 100, rainColor);

    tft.fillCircle(182, 90, 2.5, rainColor);
    tft.fillCircle(190, 100, 2.5, rainColor);

    tft.fillCircle(178, 100, 2.5, drizzleColor);
    tft.fillCircle(187, 110, 2.5, drizzleColor);
}

void hvSereneWeather() {
    tft.drawCircle(163, 73, 14, whiteScript);
    tft.drawCircle(163, 73, 13, whiteScript);
    tft.drawCircle(163, 73, 12, whiteScript);

    tft.drawCircle(174, 61, 14, whiteScript);
    tft.drawCircle(174, 61, 13, whiteScript);
    tft.drawCircle(174, 61, 12, whiteScript);

    tft.drawCircle(197, 54, 19, whiteScript);
    tft.drawCircle(197, 54, 18, whiteScript);
    tft.drawCircle(197, 54, 17, whiteScript);

    tft.drawCircle(215, 73, 14, whiteScript);
    tft.drawCircle(215, 73, 13, whiteScript);
    tft.drawCircle(215, 73, 12, whiteScript);

    tft.drawLine(163, 85, 173, 85, whiteScript);
    tft.drawLine(163, 86, 173, 86, whiteScript);
    tft.drawLine(163, 87, 173, 87, whiteScript);

    tft.drawLine(215, 85, 208, 85, whiteScript);
    tft.drawLine(215, 86, 208, 86, whiteScript);
    tft.drawLine(215, 87, 208, 87, whiteScript);

    tft.fillRect(163, 59, 52, 27,  blackScript);   
    tft.fillRect(158, 62, 5, 10, blackScript);
    tft.fillRect(175, 50, 15, 15, blackScript);

    tft.fillCircle(183, 86, 3, drizzleColor); 
    tft.fillCircle(194, 86, 3, drizzleColor);

    tft.fillCircle(175, 97, 3, drizzleColor);
    tft.fillCircle(188, 97, 3, drizzleColor);
    tft.fillCircle(201, 97, 3, drizzleColor);

    tft.fillCircle(183, 108, 3, drizzleColor);
    tft.fillCircle(194, 108, 3, drizzleColor);
}

void unknownWeather() {
    tft.drawCircle(163, 78, 14, whiteScript);
    tft.drawCircle(163, 78, 13, whiteScript);
    tft.drawCircle(163, 78, 12, whiteScript);

    tft.drawCircle(174, 66, 14, whiteScript);
    tft.drawCircle(174, 66, 13, whiteScript);
    tft.drawCircle(174, 66, 12, whiteScript);

    tft.drawCircle(197, 59, 19, whiteScript);
    tft.drawCircle(197, 59, 18, whiteScript);
    tft.drawCircle(197, 59, 17, whiteScript);

    tft.drawCircle(215, 78, 14, whiteScript);
    tft.drawCircle(215, 78, 13, whiteScript);
    tft.drawCircle(215, 78, 12, whiteScript);

    tft.drawLine(163, 90, 173, 90, whiteScript);
    tft.drawLine(163, 91, 173, 91, whiteScript);
    tft.drawLine(163, 92, 173, 92, whiteScript);

    tft.drawLine(163, 90, 215, 90, whiteScript);
    tft.drawLine(163, 91, 215, 91, whiteScript);
    tft.drawLine(163, 92, 215, 92, whiteScript);

    tft.fillRect(163, 64, 52, 32,  blackScript);   
    tft.fillRect(158, 67, 5, 15, blackScript);
    tft.fillRect(175, 55, 15, 20, blackScript);

    tft.setTextDatum(TC_DATUM);
    tft.setTextColor(whiteScript);
    tft.setFreeFont(latoBold24);
    tft.drawString("?", 188, 62, GFXFF);
}

void snowWeather() {
    tft.drawRect(150, 35, 80, 80,  greenScript);

    tft.fillCircle(190, 50, 2, drizzleColor);
    tft.fillCircle(190, 100, 2, drizzleColor);
    tft.fillCircle(165, 75, 2, drizzleColor);
    tft.fillCircle(215, 75, 2, drizzleColor);






    tft.fillCircle(173, 89, 2, drizzleColor);
    tft.fillCircle(206, 89, 2, drizzleColor);

    tft.fillCircle(173, 60, 2, drizzleColor);
    tft.fillCircle(206, 60, 2, drizzleColor);



    tft.fillRect(188, 50, 5, 50, drizzleColor);
    tft.fillRect(165, 73, 50, 5, drizzleColor);
}

