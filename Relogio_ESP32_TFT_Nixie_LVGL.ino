// Font file is stored in SPIFFS
#define FS_NO_GLOBALS
#include <FS.h>
#include <TFT_eSPI.h> 
#include <SPI.h>
#include <Wire.h>
//#include <PNGdec.h>
#include <WiFi.h>
#include <lvgl.h>

#include "Imagens.h"
#include "main.h"

#define pinOnOff 16
#define pinSet 17
#define pinBL 25

#define GFXFF 1
  // TL_DATUM = Top left (default)
  // TC_DATUM = Top center
  // TR_DATUM = Top right
  // ML_DATUM = Middle left
  // MC_DATUM = Middle center
  // MR_DATUM = Middle right
  // BL_DATUM = Bottom left
  // BC_DATUM = Bottom center
  // BR_DATUM = Bottom right
  // L_BASELINE = Left character baseline (Line the 'A' character would sit on)
  // C_BASELINE = Centre character baseline
  // R_BASELINE = Right character baseline

// -------------------- FONTES SALVAS SPIFFS --------------------
// Lato_Bold_48
// Lato_Bold_24
// Lato_Bold_14
// Lato_Bold_12
// Lato_Bold_10
// Lato_Regular_24
// Lato_Regular_14
// Lato_Regular_12
// Lato_Regular_10

// -------------------- CORES DISPLAY RGB 555 --------------------

uint16_t darkBackgroundColor = 0x2988;  //0x2F3243
uint16_t lightBackgroundColor = 0xEF9D; //0xF3F3F3
uint16_t backgroundColor;

uint16_t redTextColor = 0xF30D;         //0xFC6470
uint16_t lightRedTextColor = 0x924A;    //0x964B5A
uint16_t orangeTextColor = 0xDAA1;      //0xE65510
uint16_t greenTextColor = 0x4FEF;       //0x50FF7D
uint16_t lightTextColor = 0xEFBE;       //0xF3F8FE
uint16_t darkTextColor = 0x2988;        //0x2F3243
uint16_t textColor;

uint16_t blockColor = 0xEFBE;           //0XF3F8FE
uint16_t grayColor = 0x4228;            //0x454545
uint16_t gray2Color = 0x528A;           //0x545454
uint16_t blackColor = 0x10A2;           //0x161616
uint16_t snowColor = 0xEF9D;            //0xF3F3F3
uint16_t snow2Color = 0xE73C;           //0xEAEAEA
uint16_t whiteColor = 0xFFFF;           //0xFFFFFF

uint16_t bluetoothColor = 0x3BBD;       //0x3D79F2

// -------------------- FUNCOES E AJUSTES NAO CONFIGURAVEIS --------------------
const int pwmResolution = 8;          // Resolucao PWM (8 bits para o ESP32)
const int pwmFrequency = 5000;        // Frequencia do sinal PWM em Hz
const int fadeDuration = 3000;        // Duracao do carregamento da tela (em milissegundos)
const int holdDuration = 2000;        // Duracao da saida mantida em 100% (em milissegundos)

unsigned long startTime;              // Tempo de início da transição

unsigned long currentTime = millis(); // Tempo real para funcoes

byte firstInicialization = 0;         // Define a primeira inicializacao do aparelho
  // firstInicialization = 0 Nao executado primeira inicializacao
  // firstInicialization = 1 Executado barra de carregamento e analise dos modulos
  // firstInicialization = 2 Executado a animacao da logomarca
  // firstInicialization = 3 Executado os resultados da analise dos modulos
  // firstInicialization = 4 Executado time para inicializacao do byte firstSettings

byte firstSettings = 0;               // Define a primeira configuracao do aparelho
  // firstSettings








byte colorBackgroundValue = 0;        // Define qual a cor de background
  // byte colorBackgroundValue = 0 Definido como fundo Escuro
  // byte colorBackgroundValue = 1 Definido como fundo Claro

byte colorTextValue = 0;              // Define qual a cor de texto
  // byte colorTextValue = 0 Definido como texto Claro
  // byte colorTextValue = 1 Definido como texto Escuro
  // byte colorTextValue = 2 Definido como texto Colorido

byte error = 0;                     // Armazena e define erros encontrados
  

  uint16_t t_x = 0, t_y = 0;          // Armazena as posicoes do TouchScreen
  uint16_t xScreen = 0, yScreen = 0;  // Armazena valor convertido do TouchScreen
// -------------------- FUNCOES E AJUSTES CONFIGURAVEIS --------------------
byte touchSet = 2;
  // touchSet = 0 Iniciado a calibracao do Touchscreen
  // touchSet = 1 Validando calibracao do Touchscreen
  // touchSet = 2 Usando os valores do DESENVOLVEDOR no setup()
  // touchSet = 3 Finalizacao de calibracao do Touchscreen

byte systemLanguage = 0;
  // systemLanguage = 0 A ser definido nas configuracoes
  // systemLanguage = 1 Definido sistema em Ingles
  // systemLanguage = 2 Definido sistema em Portugues
  // systemLanguage = 3 Definido sistema em Espanhol
  // systemLanguage = 4 Definido sistema em Italiano



// -------------------- INSTANCIAS DAS BIBLIOTECAS --------------------
  TFT_eSPI tft = TFT_eSPI();      // Instancia da biblioteca TFT_eSPI para operacao do display
  TFT_eSprite logo = TFT_eSprite(&tft); // Instancia da biblioteca TFT_eSPI para imagem PNG

// -------------------- CARREGAMENTO DAS TELAS --------------------
static bool loaded[10] = {      // Variavel loaded para cada tela
/*
VERSAO FINAL loader[0] = false; e loader[1] = false;
Altere para TRUE para pular o carregamento de certas telas
*/
  true,        // loader[0] firstLoading();
  true,        // loader[1] firstLanguages();
  false,       // loader[2] firstAppTheme();
  true,        // loader[3] keyboard();
  true,        // loader[4] 
  true,        // loader[5] 
  true,        // loader[6] 
  true,        // loader[7] 
  true,        // loader[8] 
  true,        // loader[9] 
};

byte screenLoaded = 0;
// screenLoaded = 1 Habita Botoes de firstLanguages()
// screenLoaded = 2 Habita Botoes de firstAppTheme()
// screenLoaded = 3 Habita Botoes de keyboard()

// -------------------- ESTRUTURA DOS BOTOES --------------------
bool request[10] = {      // Variavel request para recarregamento completo da tela
  false,        // loader[0] firstLoading();
  false,        // loader[1] firstLanguages();
  false,        // loader[2] firstAppTheme();
  false,        // loader[3] keyboard();
  false,        // loader[4] 
  false,        // loader[5] 
  false,        // loader[6] 
  false,        // loader[7] 
  false,        // loader[8] 
  false,        // loader[9] 
};
// -------------------- BOOLEAN DE BOTOES E ACOES --------------------

bool touch = false; // Variavel para rastrear o estado anterior do toque
bool executeBtn = false;
bool selected_Languages = false;
bool openKeyboard = false; // Variavel para abrir e fechar teclado

// -------------------- INT DE BOTOES --------------------------------
int buttonPressed = 0;
// buttonPressed = 1 Habilita Botao touchedBtn_Lang_English
// buttonPressed = 2 Habilita Botao touchedBtn_Lang_Portuguese
// buttonPressed = 3 Habilita Botao touchedBtn_Lang_Spanish
// buttonPressed = 4 Habilita Botao touchedBtn_Lang_Italian
// buttonPressed = 5 Habilita Botao touchedBtn_firstLanguague
// buttonPressed = 6 Habilita Botao 
// buttonPressed = 7 Habilita Botao 

// -------------------- CONFIGURACOES E INICIALIZACAO DE MODULOS --------------------
void setup() {
  Serial.begin(115200);
  Serial.println("Sistema Inicializado");
  tft.init();
  tft.setRotation(1);      

  pinMode(pinOnOff, INPUT_PULLUP);
  pinMode(pinSet, INPUT_PULLUP);
  ledcSetup(0, pwmFrequency, pwmResolution); 
  ledcAttachPin(pinBL, 25); 
  
  startTime = millis();

  if (!SPIFFS.begin()) {
    Serial.println("SPIFFS initialisation failed!");
    while (1) yield(); 
  }
  listFiles(); // Lista todos os arquivos que estao armazenados no SPIFFS

  if (touchSet == 2) {
    uint16_t calData[5] = { 343, 3546, 211, 2344, 7 };
    tft.setTouch(calData);
  }
  tft.fillScreen(darkBackgroundColor);

  if (colorBackgroundValue == 0) {
    backgroundColor = darkBackgroundColor;
  } else {
    backgroundColor = lightBackgroundColor;
  }

  if (colorTextValue == 0) {
    textColor = lightTextColor;
  } else {
    textColor = darkTextColor;
  }

}

void loop() {
  unsigned long currentTime = millis();
  unsigned long elapsedTime = 0;

  bool pressed = tft.getTouch(&t_x, &t_y);
  if (pressed) {
    obtainTouch();
  } else {
    touch = false;
  }

  switch (screenLoaded) {
    case 1: btn_firstLanguages(); break;
    case 2: btn_firstAppTheme(); break;
    case 3: btn_keyboard(); break;
  }

  loadScreen(firstLoading, loaded[0], request[0]);
  loadScreen(firstLanguages, loaded[1], request[1]);
  loadScreen(firstAppTheme, loaded[2], request[2]);
  loadScreen(keyboard, loaded[3], request[3]);
  //loadScreen(firstWiFiConnection, loaded[3], request[3]);

}

// -------------------- OBTENCAO DA POSICAO DE TOUCH --------------------
void obtainTouch() {
  xScreen = map(t_x, 0, tft.width(), 0, 480);
  yScreen = map(t_y, 0, tft.height(), 0, 480);
  Serial.print("x, y, z = ");
  Serial.print(xScreen);
  Serial.print(" ,");
  Serial.print(yScreen);
  Serial.print(" ,");
  Serial.printf("%i \n", tft.getTouchRawZ()); 
  touch = true;
}

// -------------------- FUNCAO RECONHECER O BOTAO PRESSIONADO --------------------
bool touchRect(int startX, int startY, int sizeX, int sizeY) {
  bool touched = (t_x > startX && t_x < startX + sizeX && t_y > startY && t_y < startY + sizeY);
  return touched;
}

// -------------------- ANIMACOES E ACOES DOS BOTOES --------------------
void btn_firstLanguages() {
  // BOTOES MUDAR LINGUAGEM DO SISTEMA PARA INGLES
  bool touchedBtn_Lang_English = touchRect(140, 123, 96, 68);
  bool touchedBtn_Lang_Portuguese = touchRect(244, 123, 96, 68);
  bool touchedBtn_Lang_Spanish = touchRect(140, 205, 96, 68);
  bool touchedBtn_Lang_Italian = touchRect(244, 205, 96, 68);
  bool touchedBtn_firstLanguague = touchRect(400, 238, 80 , 40);

  if (!touch) {
    touchedBtn_Lang_English = false;
    touchedBtn_Lang_Portuguese = false;
    touchedBtn_Lang_Spanish = false;
    touchedBtn_Lang_Italian = false;
    touchedBtn_firstLanguague = false;
  }

  // ANIMACAO DO BOTAO MUDAR LINGUAGEM DO SISTEMA PARA INGLES
  if (touchedBtn_Lang_English) {
    tft.fillSmoothRoundRect(140, 123, 96, 68, 5, redTextColor, backgroundColor);
    tft.fillSmoothRoundRect(244, 123, 96, 68, 5, lightTextColor, backgroundColor);

    tft.setTextDatum(ML_DATUM);
    tft.setTextColor(lightTextColor, redTextColor);
    smoothText("Lato_Regular_14");
    tft.drawString("Hi!", 145, 142, GFXFF);
    tft.drawString("I am Mufox", 145, 157, GFXFF);

    tft.setTextColor(darkTextColor, lightBackgroundColor);
    tft.drawString("Olá!", 249, 142, GFXFF);
    tft.drawString("Eu sou Mufox", 249, 157, GFXFF);


    tft.setTextColor(darkTextColor, redTextColor);
    smoothText("Lato_Regular_10");
    tft.drawString("English", 147, 178, GFXFF);
    tft.setTextColor(redTextColor, lightBackgroundColor);
    tft.drawString("Português", 251, 178, GFXFF);
    executeBtn = true;
    buttonPressed = 1;
  }

  // ANIMACAO E ACAO DO BOTAO MUDAR LINGUAGEM DO SISTEMA PARA INGLES
  if (!touchedBtn_Lang_English && executeBtn && buttonPressed == 1) {
    touch = false;
    executeBtn = false;
    systemLanguage = 1;
    request[1] = true;
    selected_Languages = true;
  }

  // ANIMACAO DO BOTAO MUDAR LINGUAGEM DO SISTEMA PARA PORTUGUES
  if (touchedBtn_Lang_Portuguese) {
    tft.fillSmoothRoundRect(140, 123, 96, 68, 5, lightTextColor, backgroundColor);
    tft.fillSmoothRoundRect(244, 123, 96, 68, 5, redTextColor, backgroundColor);
      
    tft.setTextDatum(ML_DATUM);

    tft.setTextColor(darkTextColor, lightBackgroundColor);
    smoothText("Lato_Regular_14");
    tft.drawString("Hi!", 145, 142, GFXFF);
    tft.drawString("I am Mufox", 145, 157, GFXFF);

    tft.setTextColor(lightTextColor, redTextColor);
    smoothText("Lato_Regular_14");
    tft.drawString("Olá!", 249, 142, GFXFF);
    tft.drawString("Eu sou Mufox", 249, 157, GFXFF);

    tft.setTextColor(redTextColor, lightBackgroundColor);
    smoothText("Lato_Regular_10");
    tft.drawString("English", 147, 178, GFXFF);
    tft.setTextColor(darkTextColor, redTextColor);
    tft.drawString("Português", 251, 178, GFXFF);
    executeBtn = true;
    buttonPressed = 2;
  }

  // ANIMACAO E ACAO DO BOTAO MUDAR LINGUAGEM DO SISTEMA PARA PORTUGUES
  if (!touchedBtn_Lang_Portuguese && executeBtn && buttonPressed == 2) {
    touch = false;
    executeBtn = false;
    systemLanguage = 2;
    request[1] = true;
    selected_Languages = true;
  }

  // APRESENTACAO DO CAMPO PERMITE CONTINUAR A PROXIMA TELA
  if (touchedBtn_firstLanguague && selected_Languages) {
    executeBtn = true;
    buttonPressed = 5;
  }

  // LINGUAGEM SELECIONADA PERMITE CONTINUAR A PROXIMA JANELA
  if (!touchedBtn_firstLanguague && executeBtn && buttonPressed == 5) {
    touch = false;
    executeBtn = false;
    request[2] = true;
  } 
}

void btn_firstAppTheme() {
  // BOTAO MUDAR LINGUAGEM DO SISTEMA PARA INGLES
  bool touchedBtn_Keyboard = touchRect(102, 155, 275, 30);

  if (!touch) {
    touchedBtn_Keyboard = false;
  }

  if (touchedBtn_Keyboard) {
    executeBtn = true;
    buttonPressed = 6;
  }

  // ANIMACAO E ACAO DO BOTAO MUDAR PARA TECLADO
  if (!touchedBtn_Keyboard && executeBtn && buttonPressed == 6) {
    executeBtn = false;
    request[3] = true;
    openKeyboard = true;
  }
}

void btn_keyboard() {
  bool touchedBtn_A_Keyboard = touchRect(54, 204, 29, 22);

  if (!touch) {
    touchedBtn_A_Keyboard = false;
  }

  if (touchedBtn_A_Keyboard) {
    executeBtn = true;
    buttonPressed = 7;
  }

  if (!touchedBtn_A_Keyboard && executeBtn && buttonPressed == 7) {
    executeBtn = false;
  }

  Serial.print("touchedBtn_A_Keyboard: ");
  Serial.println(touchedBtn_A_Keyboard);

}



// -------------------- PRIMEIRA CONFIGURACOES DE INTERNET --------------------
void firstWiFiConnection() {
  tft.fillRect(41, 29, 390, 3, lightRedTextColor);
  tft.fillRect(41, 29, 260, 3, redTextColor);

  tft.fillSmoothCircle(36, 30, 5, redTextColor, backgroundColor);
  tft.fillSmoothCircle(166, 30, 5, redTextColor, backgroundColor);
  tft.fillSmoothCircle(296, 30, 5, redTextColor, backgroundColor);
 
  tft.drawSmoothCircle(426, 30, 5, redTextColor, backgroundColor);
  tft.fillSmoothCircle(426, 30, 3, backgroundColor, redTextColor);

  tft.setTextDatum(ML_DATUM);
  tft.setTextColor(textColor, backgroundColor);
  smoothText("Lato_Bold_24");
  tft.drawString("Connect", 67, 65, GFXFF);
  smoothText("Lato_Regular_24");
  tft.drawString("in your network", 67, 94, GFXFF);

  tft.fillSmoothCircle(236, 182, 40, bluetoothColor);
  tft.fillSmoothCircle(235, 197, 3, blockColor);
  tft.drawArc(235, 197, 10, 13, 135, 225, blockColor, bluetoothColor, true);
  tft.drawArc(235, 197, 20, 23, 135, 225, blockColor, bluetoothColor, true);
  tft.drawArc(235, 197, 30, 33, 135, 225, blockColor, bluetoothColor, true);
}


// -------------------- TECLADO --------------------
void keyboard() {
  screenLoaded = 3;
  tft.fillRect(41, 29, 390, 3, lightRedTextColor);
  tft.fillRect(41, 29, 130, 3, redTextColor);

  tft.fillSmoothCircle(36, 30, 5, redTextColor, backgroundColor);
  tft.fillSmoothCircle(166, 30, 5, redTextColor, backgroundColor);

  tft.drawSmoothCircle(296, 30, 5, redTextColor, backgroundColor);
  tft.fillSmoothCircle(296, 30, 3, backgroundColor, redTextColor);
 
  tft.drawSmoothCircle(426, 30, 5, redTextColor, backgroundColor);
  tft.fillSmoothCircle(426, 30, 3, backgroundColor, redTextColor);
  
  if (systemLanguage == 1) {
    tft.setTextDatum(ML_DATUM);
    smoothText("Lato_Regular_10");
    tft.setTextColor(redTextColor, backgroundColor);
    tft.drawString("Language", 36, 15, GFXFF);
    tft.setTextDatum(MC_DATUM);
    tft.drawString("Profile", 169, 15, GFXFF);
    tft.drawString("Network", 299, 15, GFXFF);
    tft.setTextDatum(MR_DATUM);
    tft.drawString("Done", 423, 15, GFXFF);

  } else if (systemLanguage == 2) {
    tft.setTextDatum(ML_DATUM);
    smoothText("Lato_Regular_10");
    tft.setTextColor(redTextColor, backgroundColor);
    tft.drawString("língua", 36, 15, GFXFF);
    tft.setTextDatum(MC_DATUM);
    tft.drawString("Perfil", 169, 15, GFXFF);
    tft.drawString("Rede", 299, 15, GFXFF);
    tft.setTextDatum(MR_DATUM);
    tft.drawString("Pronto", 423, 15, GFXFF);

  } else if (systemLanguage == 3) {
    tft.setTextDatum(ML_DATUM);
    smoothText("Lato_Regular_10");
    tft.setTextColor(redTextColor, backgroundColor);
    tft.drawString("Idioma", 36, 15, GFXFF);
    tft.setTextDatum(MC_DATUM);
    tft.drawString("Perfil", 169, 15, GFXFF);
    tft.drawString("Red", 299, 15, GFXFF);
    tft.setTextDatum(MR_DATUM);
    tft.drawString("Hecho", 423, 15, GFXFF);

  } else if (systemLanguage == 4) {
    tft.setTextDatum(ML_DATUM);
    smoothText("Lato_Regular_10");
    tft.setTextColor(redTextColor, backgroundColor);
    tft.drawString("Lingua", 36, 15, GFXFF);
    tft.setTextDatum(MC_DATUM);
    tft.drawString("Profilo", 169, 15, GFXFF);
    tft.drawString("Rete", 299, 15, GFXFF);
    tft.setTextDatum(MR_DATUM);
    tft.drawString("Fatto", 423, 15, GFXFF);
  }

  if (openKeyboard) {
  tft.drawRoundRect(102, 125, 275, 30, 5, redTextColor);

    tft.drawRoundRect(11, 180, 22, 22, 2, redTextColor);
    tft.drawRoundRect(36, 180, 28, 22, 2, redTextColor);
    tft.drawRoundRect(67, 180, 28, 22, 2, redTextColor);
    tft.drawRoundRect(98, 180, 28, 22, 2, redTextColor);
    tft.drawRoundRect(129, 180, 28, 22, 2, redTextColor);
    tft.drawRoundRect(160, 180, 28, 22, 2, redTextColor);
    tft.drawRoundRect(191, 180, 28, 22, 2, redTextColor);
    tft.drawRoundRect(222, 180, 28, 22, 2, redTextColor);
    tft.drawRoundRect(253, 180, 28, 22, 2, redTextColor);
    tft.drawRoundRect(284, 180, 28, 22, 2, redTextColor);
    tft.drawRoundRect(315, 180, 28, 22, 2, redTextColor);
    tft.drawRoundRect(346, 180, 28, 22, 2, redTextColor);
    tft.drawRoundRect(377, 180, 28, 22, 2, redTextColor);
    tft.drawRoundRect(408, 180, 59, 22, 2, redTextColor);

    tft.drawRoundRect(11, 204, 40, 22, 2, redTextColor);
    tft.drawRoundRect(54, 204, 29, 22, 2, redTextColor);
    tft.drawRoundRect(86, 204, 29, 22, 2, redTextColor);
    tft.drawRoundRect(118, 204, 29, 22, 2, redTextColor);
    tft.drawRoundRect(150, 204, 29, 22, 2, redTextColor);
    tft.drawRoundRect(182, 204, 29, 22, 2, redTextColor);
    tft.drawRoundRect(214, 204, 29, 22, 2, redTextColor);
    tft.drawRoundRect(246, 204, 29, 22, 2, redTextColor);
    tft.drawRoundRect(278, 204, 29, 22, 2, redTextColor);
    tft.drawRoundRect(310, 204, 29, 22, 2, redTextColor);
    tft.drawRoundRect(342, 204, 29, 22, 2, redTextColor);
    tft.drawRoundRect(374, 204, 29, 22, 2, redTextColor);
    tft.drawRoundRect(406, 204, 29, 22, 2, redTextColor);
    tft.drawRoundRect(438, 204, 29, 22, 2, redTextColor);

    tft.drawRoundRect(11, 228, 45, 22, 2, redTextColor);
    tft.drawRoundRect(59, 228, 29, 22, 2, redTextColor);
    tft.drawRoundRect(91, 228, 29, 22, 2, redTextColor);
    tft.drawRoundRect(123, 228, 29, 22, 2, redTextColor);
    tft.drawRoundRect(155, 228, 29, 22, 2, redTextColor);
    tft.drawRoundRect(187, 228, 29, 22, 2, redTextColor);
    tft.drawRoundRect(219, 228, 29, 22, 2, redTextColor);
    tft.drawRoundRect(251, 228, 29, 22, 2, redTextColor);
    tft.drawRoundRect(283, 228, 29, 22, 2, redTextColor);
    tft.drawRoundRect(315, 228, 29, 22, 2, redTextColor);
    tft.drawRoundRect(347, 228, 29, 22, 2, redTextColor);
    tft.drawRoundRect(379, 228, 29, 22, 2, redTextColor);
    tft.drawRoundRect(411, 228, 56, 22, 2, redTextColor);

    tft.drawRoundRect(11, 252, 45, 22, 2, redTextColor);
    tft.drawRoundRect(59, 252, 33, 22, 2, redTextColor);
    tft.drawRoundRect(95, 252, 33, 22, 2, redTextColor);
    tft.drawRoundRect(131, 252, 33, 22, 2, redTextColor);
    tft.drawRoundRect(167, 252, 33, 22, 2, redTextColor);
    tft.drawRoundRect(203, 252, 33, 22, 2, redTextColor);
    tft.drawRoundRect(239, 252, 33, 22, 2, redTextColor);
    tft.drawRoundRect(275, 252, 33, 22, 2, redTextColor);
    tft.drawRoundRect(311, 252, 33, 22, 2, redTextColor);
    tft.drawRoundRect(347, 252, 33, 22, 2, redTextColor);
    tft.drawRoundRect(383, 252, 33, 22, 2, redTextColor);
    tft.drawRoundRect(419, 252, 48, 22, 2, redTextColor);

    tft.drawRoundRect(11, 276, 45, 22, 2, redTextColor);
    tft.drawRoundRect(59, 276, 29, 22, 2, redTextColor);
    tft.drawRoundRect(91, 276, 325, 22, 2, redTextColor);
    tft.drawRoundRect(419, 276, 48, 22, 2, redTextColor);
  }

  if (openKeyboard) {
    tft.setTextDatum(MC_DATUM);
    tft.setTextColor(lightTextColor, backgroundColor);
    smoothText("Lato_Regular_14");
    tft.drawString("`", 22, 191, GFXFF);
    tft.drawString("1", 50, 191, GFXFF);
    tft.drawString("2", 81, 191, GFXFF);
    tft.drawString("3", 112, 191, GFXFF);
    tft.drawString("4", 143, 191, GFXFF);
    tft.drawString("5", 174, 191, GFXFF);
    tft.drawString("6", 205, 191, GFXFF);
    tft.drawString("7", 236, 191, GFXFF);
    tft.drawString("8", 267, 191, GFXFF);
    tft.drawString("9", 298, 191, GFXFF);
    tft.drawString("0", 329, 191, GFXFF);
    tft.drawString("-", 360, 191, GFXFF);
    tft.drawString("=", 391, 191, GFXFF);

    tft.drawString("q", 68, 215, GFXFF);
    tft.drawString("w", 100, 215, GFXFF);
    tft.drawString("e", 132, 215, GFXFF);
    tft.drawString("r", 164, 215, GFXFF);
    tft.drawString("t", 196, 215, GFXFF);
    tft.drawString("y", 228, 215, GFXFF);
    tft.drawString("u", 260, 215, GFXFF);
    tft.drawString("i", 292, 215, GFXFF);
    tft.drawString("o", 324, 215, GFXFF);
    tft.drawString("p", 356, 215, GFXFF);
    tft.drawString("[", 388, 215, GFXFF);
    tft.drawString("]", 420, 215, GFXFF);
    tft.drawString("\\", 452, 215, GFXFF);

    tft.drawString("a", 73, 239, GFXFF);
    tft.drawString("s",105, 239, GFXFF);
    tft.drawString("d", 136, 239, GFXFF);
    tft.drawString("f", 168, 239, GFXFF);
    tft.drawString("g", 200, 239, GFXFF);
    tft.drawString("h", 232, 239, GFXFF);
    tft.drawString("j", 264, 239, GFXFF);
    tft.drawString("k", 296, 239, GFXFF);
    tft.drawString("l", 328, 239, GFXFF);
    tft.drawString(";", 360, 239, GFXFF);
    tft.drawString("'", 394, 239, GFXFF);

    tft.drawString("z", 74, 263, GFXFF);
    tft.drawString("x", 110, 263, GFXFF);
    tft.drawString("c", 147, 263, GFXFF);
    tft.drawString("v", 184, 263, GFXFF);
    tft.drawString("b", 219, 263, GFXFF);
    tft.drawString("n", 258, 263, GFXFF);
    tft.drawString("m", 295, 263, GFXFF);
    tft.drawString(",", 333, 263, GFXFF);
    tft.drawString(".", 370, 263, GFXFF);
    tft.drawString("/", 407, 263, GFXFF);

    tft.drawString("@", 72, 287, GFXFF);


    smoothText("Lato_Regular_10");
    tft.drawString("backscape", 438, 191, GFXFF);
  }

  unsigned long startTime = millis();
  unsigned long timerCheckingModule = 0;
  unsigned long interval = 20;  
  unsigned long loading = 2000; 

  while (millis() - startTime <= loading) {
    if (millis() - timerCheckingModule >= interval) {
      if (systemLanguage == 0) {
        timerCheckingModule = millis();
        float progress = (millis() - startTime) / (float)loading;
        float easedProgress = easeOutCubic(progress);  // Função de desaceleração aplicada ao progresso
        float width = easedProgress * 41;
        tft.fillRect(141, 29, width, 3, redTextColor);
      } else {
        timerCheckingModule = millis();
        float progress = (millis() - startTime) / (float)loading;
        float easedProgress = easeOutCubic(progress);  // Função de desaceleração aplicada ao progresso
        float width = easedProgress * 50;
        tft.fillRect(141, 29, width, 3, redTextColor);
      }
    }
  }
}

// -------------------- PRIMEIRA CONFIGURACOES DE TEMA --------------------
void firstAppTheme() {
  screenLoaded = 2;
  request[2] = false;
  tft.fillRect(41, 29, 390, 3, lightRedTextColor);
  tft.fillRect(41, 29, 130, 3, redTextColor);

  tft.fillSmoothCircle(36, 30, 5, redTextColor, backgroundColor);
  tft.fillSmoothCircle(166, 30, 5, redTextColor, backgroundColor);

  tft.drawSmoothCircle(296, 30, 5, redTextColor, backgroundColor);
  tft.fillSmoothCircle(296, 30, 3, backgroundColor, redTextColor);
 
  tft.drawSmoothCircle(426, 30, 5, redTextColor, backgroundColor);
  tft.fillSmoothCircle(426, 30, 3, backgroundColor, redTextColor);

  if (systemLanguage == 1) {
    tft.setTextDatum(ML_DATUM);
    smoothText("Lato_Regular_10");
    tft.setTextColor(redTextColor, backgroundColor);
    tft.drawString("Language", 36, 15, GFXFF);
    tft.setTextDatum(MC_DATUM);
    tft.drawString("Profile", 169, 15, GFXFF);
    tft.drawString("Network", 299, 15, GFXFF);
    tft.setTextDatum(MR_DATUM);
    tft.drawString("Done", 423, 15, GFXFF);

  } else if (systemLanguage == 2) {
    tft.setTextDatum(ML_DATUM);
    smoothText("Lato_Regular_10");
    tft.setTextColor(redTextColor, backgroundColor);
    tft.drawString("língua", 36, 15, GFXFF);
    tft.setTextDatum(MC_DATUM);
    tft.drawString("Perfil", 169, 15, GFXFF);
    tft.drawString("Rede", 299, 15, GFXFF);
    tft.setTextDatum(MR_DATUM);
    tft.drawString("Pronto", 423, 15, GFXFF);

  } else if (systemLanguage == 3) {
    tft.setTextDatum(ML_DATUM);
    smoothText("Lato_Regular_10");
    tft.setTextColor(redTextColor, backgroundColor);
    tft.drawString("Idioma", 36, 15, GFXFF);
    tft.setTextDatum(MC_DATUM);
    tft.drawString("Perfil", 169, 15, GFXFF);
    tft.drawString("Red", 299, 15, GFXFF);
    tft.setTextDatum(MR_DATUM);
    tft.drawString("Hecho", 423, 15, GFXFF);

  } else if (systemLanguage == 4) {
    tft.setTextDatum(ML_DATUM);
    smoothText("Lato_Regular_10");
    tft.setTextColor(redTextColor, backgroundColor);
    tft.drawString("Lingua", 36, 15, GFXFF);
    tft.setTextDatum(MC_DATUM);
    tft.drawString("Profilo", 169, 15, GFXFF);
    tft.drawString("Rete", 299, 15, GFXFF);
    tft.setTextDatum(MR_DATUM);
    tft.drawString("Fatto", 423, 15, GFXFF);
  }

  tft.setTextDatum(ML_DATUM);
  tft.setTextColor(textColor, backgroundColor);
  smoothText("Lato_Bold_24");
  tft.drawString("What", 67, 65, GFXFF);
  smoothText("Lato_Regular_24");
  tft.drawString("is your name?", 67, 94, GFXFF);
  if (!openKeyboard) {
    tft.drawRoundRect(102, 155, 275, 30, 5, redTextColor);
  }

  unsigned long startTime = millis();
  unsigned long timerCheckingModule = 0;
  unsigned long interval = 20;  
  unsigned long loading = 2000; 

  while (millis() - startTime <= loading) {
    if (millis() - timerCheckingModule >= interval) {
      if (systemLanguage == 0) {
        timerCheckingModule = millis();
        float progress = (millis() - startTime) / (float)loading;
        float easedProgress = easeOutCubic(progress);  // Função de desaceleração aplicada ao progresso
        float width = easedProgress * 41;
        tft.fillRect(141, 29, width, 3, redTextColor);
      } else {
        timerCheckingModule = millis();
        float progress = (millis() - startTime) / (float)loading;
        float easedProgress = easeOutCubic(progress);  // Função de desaceleração aplicada ao progresso
        float width = easedProgress * 50;
        tft.fillRect(141, 29, width, 3, redTextColor);
      }
    }
  }
}
  // ---------------------------------------
  /*
    tft.setTextDatum(ML_DATUM);
    tft.setTextColor(textColor, backgroundColor);
    smoothText("Lato_Bold_24");
    tft.drawString("Choose", 67, 65, GFXFF);
    smoothText("Lato_Regular_24");
    tft.drawString("the app theme", 67, 94, GFXFF);

    smoothText("Lato_Regular_14");
    tft.setTextColor(redTextColor, blackColor);
    tft.fillSmoothRoundRect(57, 142, 80, 70, 10, grayColor, backgroundColor);
    tft.fillSmoothRoundRect(73, 161, 64, 51, 10, blackColor, gray2Color);
    tft.drawString("Aa", 81, 172, GFXFF);

    tft.setTextColor(redTextColor, whiteColor);
    tft.fillSmoothRoundRect(152, 142, 80, 70, 10, snowColor, backgroundColor);
    tft.fillSmoothRoundRect(168, 161, 64, 51, 10, whiteColor, snow2Color);
    tft.drawString("Aa", 173, 172, GFXFF);

    tft.setTextColor(whiteColor, blackColor);
    tft.fillSmoothRoundRect(247, 142, 80, 70, 10, grayColor, backgroundColor);
    tft.fillSmoothRoundRect(263, 161, 64, 51, 10, blackColor, gray2Color);
    tft.drawString("Aa", 271, 172, GFXFF);

    tft.setTextColor(blackColor, whiteColor);
    tft.fillSmoothRoundRect(342, 142, 80, 70, 10, snowColor, backgroundColor);
    tft.fillSmoothRoundRect(358, 161, 64, 51, 10, whiteColor, snow2Color);
    tft.drawString("Aa", 363, 172, GFXFF);

    tft.setTextColor(whiteColor, backgroundColor);
    smoothText("Lato_Regular_10");
    tft.drawString("Dark & Color", 57, 223, GFXFF);
    tft.drawString("Light & Color", 152, 223, GFXFF);
    tft.drawString("Dark", 247, 223, GFXFF);
    tft.drawString("Light", 342, 223, GFXFF);
    // ---------------------------------------

    




    tft.setTextDatum(ML_DATUM);
    tft.setTextColor(textColor, backgroundColor);
    smoothText("Lato_Bold_24");
    tft.drawString("Select", 67, 65, GFXFF);
    smoothText("Lato_Regular_24");
    tft.drawString("a profile image", 67, 94, GFXFF);

    tft.fillRect(67, 144, 50, 50, blockColor);
    tft.fillSmoothRoundRect(128, 144, 50, 50, 7, blockColor);
    tft.fillSmoothCircle(92, 230, 25, blockColor);
    tft.fillRect(128, 205, 50, 50, blockColor);
    tft.fillTriangle(125, 202, 125, 221, 144, 202, backgroundColor);
    tft.fillTriangle(162, 202, 181, 221, 181, 202, backgroundColor);
    tft.fillTriangle(125, 239, 125, 258, 144, 258, backgroundColor);
    tft.fillTriangle(162, 258, 181, 258, 181, 239, backgroundColor);

    tft.drawRect(282, 120, 100, 100, backgroundColor);

    tft.fillSmoothCircle(365, 90, 18, bluetoothColor);

    tft.drawRect(282, 120, 100, 100, blockColor);

    unsigned long startTime = millis();
    unsigned long timerCheckingModule = 0;
    unsigned long interval = 20;  
    unsigned long loading = 2000; 

    while (millis() - startTime <= loading) {
      if (millis() - timerCheckingModule >= interval) {
        timerCheckingModule = millis();
        float progress = (millis() - startTime) / (float)loading;
        float easedProgress = easeOutCubic(progress);  // Função de desaceleração aplicada ao progresso
        float width = easedProgress * 41;
        tft.fillRect(171, 29, width, 3, redTextColor);
      }
    }
  }
  */

// -------------------- PRIMEIRA CONFIGURACOES DO APARELHO --------------------
void firstLanguages() {
  screenLoaded = 1;
  request[1] = false;

  tft.fillRect(41, 29, 390, 3, lightRedTextColor);

  tft.fillSmoothCircle(36, 30, 5, redTextColor, backgroundColor);
  tft.drawSmoothCircle(166, 30, 5, redTextColor, backgroundColor);
  tft.fillSmoothCircle(166, 30, 3, backgroundColor, redTextColor);

  tft.drawSmoothCircle(296, 30, 5, redTextColor, backgroundColor);
  tft.fillSmoothCircle(296, 30, 3, backgroundColor, redTextColor);
 
  tft.drawSmoothCircle(426, 30, 5, redTextColor, backgroundColor);
  tft.fillSmoothCircle(426, 30, 3, backgroundColor, redTextColor);

  if (systemLanguage > 0) {
    tft.setTextDatum(ML_DATUM);
    tft.setTextColor(redTextColor, backgroundColor);
    smoothText("Lato_Regular_14");
    switch (systemLanguage) {
      case 1: tft.drawString("Next", 413, 249, GFXFF); break;
      case 2: tft.drawString("Próximo", 413, 249, GFXFF); break;
      case 3: tft.drawString("Próximo", 413, 249, GFXFF); break;
      case 4: tft.drawString("Prossimo", 413, 249, GFXFF); break;
    }
  }

  if (systemLanguage == 1) {
    tft.fillSmoothRoundRect(140, 123, 96, 68, 5, redTextColor, backgroundColor);
    tft.fillSmoothRoundRect(244, 123, 96, 68, 5, lightTextColor, backgroundColor);
    tft.fillSmoothRoundRect(140, 205, 96, 68, 5, grayColor, backgroundColor);
    tft.fillSmoothRoundRect(244, 205, 96, 68, 5, grayColor, backgroundColor);

    tft.setTextDatum(ML_DATUM);
    tft.setTextColor(textColor, backgroundColor);
    smoothText("Lato_Bold_24");
    tft.drawString("Choose", 67, 65, GFXFF);
    smoothText("Lato_Regular_24");
    tft.drawString("your Language", 67, 94, GFXFF);

    tft.setTextColor(lightTextColor, redTextColor);
    smoothText("Lato_Regular_14");
    tft.drawString("Hi!", 145, 142, GFXFF);
    tft.drawString("I am Mufox", 145, 157, GFXFF);

    tft.setTextColor(darkTextColor, lightBackgroundColor);
    tft.drawString("Olá!", 249, 142, GFXFF);
    tft.drawString("Eu sou Mufox", 249, 157, GFXFF);

    //tft.drawString("Hi!", 147, 132, GFXFF);
    //tft.drawString("I am Mufox", 147, 152, GFXFF);


    //tft.drawString("Hi!", 147, 132, GFXFF);
    //tft.drawString("I am Mufox", 147, 152, GFXFF);

    smoothText("Lato_Regular_10");
    tft.setTextColor(darkTextColor, redTextColor);
    tft.drawString("English", 147, 178, GFXFF);

    tft.setTextColor(redTextColor, lightBackgroundColor);
    tft.drawString("Português", 251, 178, GFXFF);

    tft.setTextColor(lightTextColor, grayColor);
    // tft.drawString("Español", 147, 260, GFXFF);
    tft.drawString("En progreso", 147, 260, GFXFF);
    // tft.drawString("Italiano", 251, 260, GFXFF);
    tft.drawString("In corso", 251, 260, GFXFF);

    tft.setTextColor(redTextColor, backgroundColor);
    tft.drawString("Language", 36, 15, GFXFF);
    tft.setTextDatum(MC_DATUM);
    tft.drawString("Profile", 169, 15, GFXFF);
    tft.drawString("Network", 299, 15, GFXFF);
    tft.setTextDatum(MR_DATUM);
    tft.drawString("Done", 423, 15, GFXFF);
  } 
  
  if (systemLanguage == 2) {
    tft.fillSmoothRoundRect(140, 123, 96, 68, 5, lightTextColor, backgroundColor);
    tft.fillSmoothRoundRect(244, 123, 96, 68, 5, redTextColor, backgroundColor);
    tft.fillSmoothRoundRect(140, 205, 96, 68, 5, grayColor, backgroundColor);
    tft.fillSmoothRoundRect(244, 205, 96, 68, 5, grayColor, backgroundColor);

    tft.setTextDatum(ML_DATUM);
    tft.setTextColor(textColor, backgroundColor);
    smoothText("Lato_Bold_24");
    tft.drawString("Escolha", 67, 65, GFXFF);
    smoothText("Lato_Regular_24");
    tft.drawString("sua língua", 67, 94, GFXFF);

    tft.setTextColor(darkTextColor, lightBackgroundColor);
    smoothText("Lato_Regular_14");
    tft.drawString("Hi!", 145, 142, GFXFF);
    tft.drawString("I am Mufox", 145, 157, GFXFF);

    tft.setTextColor(lightTextColor, redTextColor);
    tft.drawString("Olá!", 249, 142, GFXFF);
    tft.drawString("Eu sou Mufox", 249, 157, GFXFF);

    //tft.drawString("Hi!", 147, 132, GFXFF);
    //tft.drawString("I am Mufox", 147, 152, GFXFF);


    //tft.drawString("Hi!", 147, 132, GFXFF);
    //tft.drawString("I am Mufox", 147, 152, GFXFF);

    tft.setTextColor(redTextColor, lightBackgroundColor);
    smoothText("Lato_Regular_10");
    tft.drawString("English", 147, 178, GFXFF);

    tft.setTextColor(darkTextColor, redTextColor);
    tft.drawString("Português", 251, 178, GFXFF);

    tft.setTextColor(lightTextColor, grayColor);
    // tft.drawString("Español", 147, 260, GFXFF);
    tft.drawString("En progreso", 147, 260, GFXFF);
    // tft.drawString("Italiano", 251, 260, GFXFF);
    tft.drawString("In corso", 251, 260, GFXFF);

    tft.setTextColor(redTextColor, backgroundColor);
    tft.drawString("língua", 36, 15, GFXFF);
    tft.setTextDatum(MC_DATUM);
    tft.drawString("Perfil", 169, 15, GFXFF);
    tft.drawString("Rede", 299, 15, GFXFF);
    tft.setTextDatum(MR_DATUM);
    tft.drawString("Pronto", 423, 15, GFXFF);
  } else if (systemLanguage == 0) {
    tft.fillSmoothRoundRect(140, 123, 96, 68, 5, lightTextColor, backgroundColor);
    tft.fillSmoothRoundRect(244, 123, 96, 68, 5, lightTextColor, backgroundColor);
    tft.fillSmoothRoundRect(140, 205, 96, 68, 5, grayColor, backgroundColor);
    tft.fillSmoothRoundRect(244, 205, 96, 68, 5, grayColor, backgroundColor);

    tft.setTextDatum(ML_DATUM);
    tft.setTextColor(textColor, backgroundColor);
    smoothText("Lato_Bold_24");
    tft.drawString("Choose", 67, 65, GFXFF);
    smoothText("Lato_Regular_24");
    tft.drawString("your Language", 67, 94, GFXFF);

    tft.setTextColor(darkTextColor, lightBackgroundColor);
    smoothText("Lato_Regular_14");
    tft.drawString("Hi!", 145, 142, GFXFF);
    tft.drawString("I am Mufox", 145, 157, GFXFF);

    tft.setTextColor(darkTextColor, lightBackgroundColor);
    tft.drawString("Olá!", 249, 142, GFXFF);
    tft.drawString("Eu sou Mufox", 249, 157, GFXFF);

    //tft.drawString("Hi!", 147, 132, GFXFF);
    //tft.drawString("I am Mufox", 147, 152, GFXFF);


    //tft.drawString("Hi!", 147, 132, GFXFF);
    //tft.drawString("I am Mufox", 147, 152, GFXFF);

    smoothText("Lato_Regular_10");
    tft.setTextColor(redTextColor, lightBackgroundColor);
    tft.drawString("English", 147, 178, GFXFF);

    tft.setTextColor(redTextColor, lightBackgroundColor);
    tft.drawString("Português", 251, 178, GFXFF);

    tft.setTextColor(lightTextColor, grayColor);
    // tft.drawString("Español", 147, 260, GFXFF);
    tft.drawString("En progreso", 147, 260, GFXFF);
    // tft.drawString("Italiano", 251, 260, GFXFF);
    tft.drawString("In corso", 251, 260, GFXFF);

    tft.setTextColor(redTextColor, backgroundColor);
    tft.drawString("Language", 36, 15, GFXFF);
    tft.setTextDatum(MC_DATUM);
    tft.drawString("Profile", 169, 15, GFXFF);
    tft.drawString("Network", 299, 15, GFXFF);
    tft.setTextDatum(MR_DATUM);
    tft.drawString("Done", 423, 15, GFXFF);
  }

  unsigned long startTime = millis();
  unsigned long timerCheckingModule = 0;
  unsigned long interval = 20;  
  unsigned long loading = 2000; 

  while (millis() - startTime <= loading) {
    if (millis() - timerCheckingModule >= interval) {
      if (systemLanguage == 0) {
        timerCheckingModule = millis();
        float progress = (millis() - startTime) / (float)loading;
        float easedProgress = easeOutCubic(progress);  // Função de desaceleração aplicada ao progresso
        float width = easedProgress * 41;
        tft.fillRect(41, 29, width, 3, redTextColor);
      } else {
        timerCheckingModule = millis();
        float progress = (millis() - startTime) / (float)loading;
        float easedProgress = easeOutCubic(progress);  // Função de desaceleração aplicada ao progresso
        float width = easedProgress * 75;
        tft.fillRect(41, 29, width, 3, redTextColor);
      }
    }
  }
}

// -------------------- PRIMEIRA INICIALIZACAO DO APARELHO --------------------
void firstLoading() {
  unsigned long timerCheckingModule = 0;
  unsigned long interval = 20;  
  unsigned long bargraphTime = 5000; 
  unsigned long logoTime = 5000;

  if (firstInicialization == 0) {
    logo.createSprite(165, 165);
    logo.setSwapBytes(true);
    logo.pushImage(0, 0, 165, 165, mufoxStart); // sizeX e sizeY do PNG carregado
    logo.pushSprite(158, 37, TFT_BLACK); // x e y do PNG carregado

    tft.setTextDatum(ML_DATUM);
    tft.setTextColor(textColor, backgroundColor);
    smoothText("Lato_Bold_14");
    tft.drawString("Checking Modules", 182, 228, GFXFF);

    unsigned long startTime = millis();

    while (millis() - startTime <= bargraphTime) {
      if (millis() - timerCheckingModule >= interval) {
        timerCheckingModule = millis();

        // CARREGAMENTO LINEAR
        float width = map(millis() - startTime, 0, bargraphTime, 130, 350);
        tft.drawLine(width, 245, width, 260, blockColor);

        /* CARREGAMENTO COM PERCA DE VELOCIDADE
        float progress = (millis() - startTime) / (float)bargraphTime;
        float easedProgress = easeOutCubic(progress);  // Função de desaceleração aplicada ao progresso
        float width = easedProgress * 220;
        tft.drawLine(width + 130, 245, width + 130, 260, blockColor); */
      }
    }
    firstInicialization = 1;
  }

  if (firstInicialization == 1) {
    unsigned long startTime = millis();

    while (millis() - startTime <= logoTime) {
      if (millis() - timerCheckingModule >= 10) {
        timerCheckingModule = millis();

        float progress = (millis() - startTime) / (float)logoTime;
        float easedProgress = easeOutCubic(progress);  // Função de aceleração aplicada ao progresso
        float logoXPosition = easedProgress * 111;
        int logoXEnd = 158 - logoXPosition;
        //int logoXEnd = tft.width() - logoXPosition;

        logo.pushSprite(logoXEnd, 37);

        Serial.println(logoXPosition);
      }
    }
    firstInicialization = 2;
    error = 0;
  }

  if (firstInicialization == 2) {
    if (error == 0) {
      tft.fillRect(130, 245, 220, 15, greenTextColor);
      tft.fillRect(174, 219, 130, 20, backgroundColor);
      tft.setTextColor(greenTextColor, backgroundColor);
      tft.setTextDatum(ML_DATUM);
      tft.drawString("Successful loaded", 182, 228, GFXFF);
      tft.setTextDatum(MR_DATUM);
      tft.drawString("Weather", 310, 80, GFXFF);
      tft.drawString("Geiger", 310, 95, GFXFF);
      tft.drawString("LDR", 310, 110, GFXFF);
      tft.drawString("Wi-Fi", 310, 125, GFXFF);
      tft.drawString("Battery", 310, 140, GFXFF);
      tft.drawString("Nixie", 310, 155, GFXFF);

      tft.drawString("OK", 345, 80, GFXFF);
      tft.drawString("OK", 345, 95, GFXFF);
      tft.drawString("OK", 345, 110, GFXFF);
      tft.drawString("OK", 345, 125, GFXFF);
      tft.drawString("OK", 345, 140, GFXFF);
      tft.drawString("OK", 345, 155, GFXFF);
    } else {
      tft.fillRect(130, 245, 220, 15, redTextColor);
      tft.fillRect(174, 219, 130, 20, backgroundColor);
      tft.setTextColor(redTextColor, backgroundColor);
      tft.setTextDatum(ML_DATUM);
      tft.drawString("Few Errors found", 182, 228, GFXFF);
      tft.setTextDatum(MR_DATUM);
      if (error == 1) {
        tft.setTextDatum(MR_DATUM);
        tft.drawString("Weather", 310, 80, GFXFF);
        tft.setTextDatum(ML_DATUM);
        tft.drawString("FAIL", 326, 80, GFXFF);
      } else if (error == 2) {
        tft.setTextDatum(MR_DATUM);
        tft.drawString("Geiger", 310, 95, GFXFF);
        tft.setTextDatum(ML_DATUM);
        tft.drawString("FAIL", 326, 95, GFXFF);
      } else if (error == 3) {
        tft.setTextDatum(MR_DATUM);
        tft.drawString("LDR", 310, 110, GFXFF);
        tft.setTextDatum(ML_DATUM);
        tft.drawString("FAIL", 326, 110, GFXFF);
      } else if (error == 4) {
        tft.setTextDatum(MR_DATUM);
        tft.drawString("Wi-Fi", 310, 125, GFXFF);
        tft.setTextDatum(ML_DATUM);
        tft.drawString("FAIL", 326, 125, GFXFF);
      } else if (error == 5) {
        tft.setTextDatum(MR_DATUM);
        tft.drawString("Battery", 310, 140, GFXFF);
        tft.setTextDatum(ML_DATUM);
        tft.drawString("FAIL", 326, 140, GFXFF);
      } else if (error == 6) {
        tft.setTextDatum(MR_DATUM);
        tft.drawString("Nixie", 310, 155, GFXFF);
        tft.setTextDatum(ML_DATUM);
        tft.drawString("FAIL", 326, 155, GFXFF);
      }
    }
    firstInicialization = 3;
  }

  if (firstInicialization == 3) {
    unsigned long startTime = millis();

    while (millis() - startTime <= 2000) {
      if (millis() - timerCheckingModule >= 100) {
        timerCheckingModule = millis();
        firstInicialization = 4;
        firstSettings = 1;
      }
    }
  }
}

// -------------------- FUNCAO DE CARREGAMENTO DAS TELAS --------------------
void loadScreen(void (*drawFunction)(), bool& loaded, bool& request) {
  if (!loaded) {
    tft.fillScreen(backgroundColor);
    drawFunction();
    loaded = true;
  } else if (request) {
    tft.fillScreen(backgroundColor);
    drawFunction();
    request = false;
  }
}

// -------------------- SPIFFS --------------------
void listFiles(void) {
  Serial.println();
  Serial.println("SPIFFS files found:");

#ifdef ESP32
  listDir(SPIFFS, "/", true);
#else
  fs::Dir dir = SPIFFS.openDir("/"); // Root directory
  String  line = "=====================================";

  Serial.println(line);
  Serial.println("  File name               Size");
  Serial.println(line);

  while (dir.next()) {
    String fileName = dir.fileName();
    Serial.print(fileName);
    int spaces = 25 - fileName.length(); // Tabulate nicely
    if (spaces < 0) spaces = 1;
    while (spaces--) Serial.print(" ");
    fs::File f = dir.openFile("r");
    Serial.print(f.size()); Serial.println(" bytes");
    yield();
  }

  Serial.println(line);
#endif
  Serial.println();
  delay(1000);
}

void listDir(fs::FS &fs, const char * dirname, uint8_t levels) {
  Serial.printf("Listing directory: %s\n", dirname);

  fs::File root = fs.open(dirname);
  if (!root) {
    Serial.println("Failed to open directory");
    return;
  }
  if (!root.isDirectory()) {
    Serial.println("Not a directory");
    return;
  }

  fs::File file = root.openNextFile();
  while (file) {

    if (file.isDirectory()) {
      Serial.print("DIR : ");
      String fileName = file.name();
      Serial.print(fileName);
      if (levels) {
        listDir(fs, file.name(), levels - 1);
      }
    } else {
      String fileName = file.name();
      Serial.print("  " + fileName);
      int spaces = 32 - fileName.length(); // Tabulate nicely
      if (spaces < 1) spaces = 1;
      while (spaces--) Serial.print(" ");
      String fileSize = (String) file.size();
      spaces = 8 - fileSize.length(); // Tabulate nicely
      if (spaces < 1) spaces = 1;
      while (spaces--) Serial.print(" ");
      Serial.println(fileSize + " bytes");
    }
    file = root.openNextFile();
  }
}

void smoothText(String textStyle) {
  String fileName = textStyle;
  /*void smoothText(int startX, int startY, int color, int background, String textStyle, String text, String positionText) {

  if (fileName == "lato_Regular_10") {
    startY = startY - 5;
  } else if (fileName == "Lato_Regular_12") {
    startY = startY - 6;
  } else if (fileName == "lato_Regular_14") {
    startY = startY - 7;
  } else if (fileName == "lato_Regular_24") {
    startY = startY - 12;
  } else if (fileName == "Lato_Bold_48") {
    startY = startY - 24;
  } 
  */
  //tft.setTextColor(color, background);
  tft.loadFont(fileName);
  /*int textWidth = tft.textWidth(text);
  int x, y;
  
  if (positionText == "TL_DATUM" || positionText == "ML_DATUM" || positionText == "BL_DATUM") {
    x = startX; // Alinhamento esquerdo
  } else if (positionText == "TC_DATUM" || positionText == "MC_DATUM" || positionText == "BC_DATUM") {
    x = startX - textWidth / 2; // Alinhamento central
  } else {
    x = startX - textWidth; // Alinhamento direito
  }

  if (positionText == "TL_DATUM" || positionText == "TC_DATUM" || positionText == "TR_DATUM") {
    y = startY + tft.fontHeight(); // Alinhamento superior
  } else if (positionText == "ML_DATUM" || positionText == "MC_DATUM" || positionText == "MR_DATUM") {
    y = startY + tft.fontHeight() / 2; // Alinhamento central
  } else {
    y = startY; // Alinhamento inferior
  }

  tft.setCursor(x, y);
  tft.println(text);
  */
}

// -------------------- FUNCOES DE ANIMACAO --------------------
// Função de desaceleração cúbica (Ease Out Cubic)
  float easeOutCubic(float t) {
    t--;
    return t * t * t + 1.0;
  }

  float easeInCubic(float t) {
    return t * t * t;
  }

/*
  uint16_t convertToRGB555(uint32_t rgb888) {
    uint8_t r = (rgb888 >> 16) & 0xFF;
    uint8_t g = (rgb888 >> 8) & 0xFF;
    uint8_t b = rgb888 & 0xFF;

    uint16_t r555 = (r >> 3) & 0x1F;
    uint16_t g555 = (g >> 3) & 0x1F;
    uint16_t b555 = (b >> 3) & 0x1F;

    uint16_t rgb555 = (r555 << 10) | (g555 << 5) | b555;

    return rgb555;
  }
*/
