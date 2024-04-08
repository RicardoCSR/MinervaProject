// Font file is stored in SPIFFS
#define FS_NO_GLOBALS
#include <FS.h>
#include <TFT_eSPI.h> 
#include <SPI.h>
#include <Wire.h>
#include <WiFi.h>

#include "bigPowerImage.h"
#include "MufoxLogo.h"
#include "shift.h"
#include "shiftPressed.h"
#include "backspace.h"
#include "backspacePressed.h"

#define pinOnOff 16
#define pinSet 17
#define pinBL 22
#define pinPowered 5

// #define TFT_MISO 19  // (leave TFT SDO disconnected if other SPI devices share MISO)
// #define TFT_MOSI 23
// #define TFT_SCLK 18
// #define TFT_CS   15  // Chip select control pin
// #define TFT_DC    2  // Data Command control pin
// #define TFT_RST   4  // Reset pin (could connect to RST pin)
// #define TOUCH_CS 21

// #define SD_CS 5      // Pino Chip Select (CS) do cartão SD

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
unsigned long startTime;              // Tempo de início da transição

unsigned long currentTime = millis(); // Tempo real para funcoes

byte firstSettings = 0;               // Define a primeira configuracao do aparelho
  // firstSettings

bool powerOn = false;                     // Indica se foi ligado o equipamento
  // powerOn = false Equipamento desligado
  // powerOn = true Equipamento ligado

bool firstInicialization = false;         // Define a primeira inicializacao do aparelho
  // firstInicialization = false Nao executado primeira inicializacao
  // firstInicialization = true Executado barra de carregamento e analise dos modulos

bool shiftActivated = false;
  // shiftActivated = false Nao executado
  // shiftActivated = true Ativo

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

byte loadingBar = 0;
  // loadingBar = 0 Nao executado barra de carregamento
  // loadingBar = 1 Executado barra de firstLanguages
  // loadingBar = 2 Executado barra de firstAppTheme

byte keyboardShow = 0;
  // keyboardShow = 0 Nao executado abertura do teclado
  // keyboardShow = 1 Executado abertura do teclado
  // keyboardShow = 2 Executado abertura do Shift key
  // keyboardShow = 3 Executado fechamento do teclado


// -------------------- INSTANCIAS DAS BIBLIOTECAS --------------------
  TFT_eSPI tft = TFT_eSPI();      // Instancia da biblioteca TFT_eSPI para operacao do display
  TFT_eSprite logo = TFT_eSprite(&tft); // Instancia da biblioteca TFT_eSPI para imagem PNG

// -------------------- CARREGAMENTO DAS TELAS --------------------
static bool loaded[10] = {      // Variavel loaded para cada tela
// false Tela nao e carregada
// true Tela e carregada

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

// -------------------- CARREGAMENTO DAS ZONAS BOTOES TELAS -------------------
byte btn_screenLoaded = 0;
// btn_screenLoaded = 1 Habita Botoes de firstLanguages()
// btn_screenLoaded = 2 Habita Botoes de firstAppTheme()
// btn_screenLoaded = 3 Habita Botoes de keyboard()

// -------------------- ESTRUTURA DOS BOTOES --------------------
bool request[10] = {      // Variavel request para recarregamento completo da tela
// false Tela nao e carregada
// true Tela e carregada

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
bool shiftKeyboard = false; // Variavel para abrir e fechar Shift


// -------------------- INT DE BOTOES --------------------------------
int buttonPressed = 0;
// buttonPressed = 1 Habilita Botao touchedBtn_Lang_English
// buttonPressed = 2 Habilita Botao touchedBtn_Lang_Portuguese
// buttonPressed = 3 Habilita Botao touchedBtn_Lang_Spanish
// buttonPressed = 4 Habilita Botao touchedBtn_Lang_Italian
// buttonPressed = 5 Habilita Botao touchedBtn_firstLanguague
// buttonPressed = 6 Habilita Botao touchedBtn_Keyboard
// buttonPressed = 7 Habilita Botao touchedBtn_A_Keyboard
// buttonPressed = 8 Habilita Botao touchedBtn_B_Keyboard
// buttonPressed = 9 Habilita Botao touchedBtn_C_Keyboard
// buttonPressed = 10 Habilita Botao touchedBtn_D_Keyboard
// buttonPressed = 11 Habilita Botao touchedBtn_E_Keyboard
// buttonPressed = 12 Habilita Botao touchedBtn_F_Keyboard
// buttonPressed = 13 Habilita Botao touchedBtn_G_Keyboard
// buttonPressed = 14 Habilita Botao touchedBtn_H_Keyboard
// buttonPressed = 15 Habilita Botao touchedBtn_I_Keyboard
// buttonPressed = 16 Habilita Botao touchedBtn_J_Keyboard
// buttonPressed = 17 Habilita Botao touchedBtn_K_Keyboard
// buttonPressed = 18 Habilita Botao touchedBtn_L_Keyboard
// buttonPressed = 19 Habilita Botao touchedBtn_M_Keyboard
// buttonPressed = 20 Habilita Botao touchedBtn_N_Keyboard
// buttonPressed = 21 Habilita Botao touchedBtn_O_Keyboard
// buttonPressed = 22 Habilita Botao touchedBtn_P_Keyboard
// buttonPressed = 23 Habilita Botao touchedBtn_Q_Keyboard
// buttonPressed = 24 Habilita Botao touchedBtn_R_Keyboard
// buttonPressed = 25 Habilita Botao touchedBtn_S_Keyboard
// buttonPressed = 26 Habilita Botao touchedBtn_T_Keyboard
// buttonPressed = 27 Habilita Botao touchedBtn_U_Keyboard
// buttonPressed = 28 Habilita Botao touchedBtn_V_Keyboard
// buttonPressed = 29 Habilita Botao touchedBtn_W_Keyboard
// buttonPressed = 30 Habilita Botao touchedBtn_X_Keyboard
// buttonPressed = 31 Habilita Botao touchedBtn_Y_Keyboard
// buttonPressed = 32 Habilita Botao touchedBtn_Z_Keyboard

// -------------------- CONFIGURACOES E INICIALIZACAO DE MODULOS --------------------
void setup() {
  Serial.begin(115200);
  Serial.println("Sistema Inicializado");
  delay(1000);
  tft.init();
  tft.setRotation(1);      

  pinMode(pinOnOff, INPUT_PULLUP);
  pinMode(pinSet, INPUT_PULLUP);
  pinMode(pinPowered, INPUT);
  pinMode(pinBL, OUTPUT);  
  
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

  powerOn = digitalRead(pinOnOff);
  if (powerOn) {
    Serial.println("Device on");
    loaded[0] = true;
    firstLoading();
  }


  switch (btn_screenLoaded) {
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
  bool touchedBtn_firstLanguague = touchRect(400, 218, 80 , 80);

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
    keyboardShow = 1;
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
    Serial.print("Lingua selecionada: ");
    Serial.println(systemLanguage);
    touch = false;
    executeBtn = false;
    request[2] = true;
  } 
}

void btn_firstAppTheme() {
  // BOTAO MUDAR LINGUAGEM DO SISTEMA PARA INGLES
  bool touchedBtn_Keyboard = touchRect(97, 152, 284, 36);

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
  bool touchedBtn_Q_Keyboard = touchRect(4, 132, 42, 40);
  bool touchedBtn_W_Keyboard = touchRect(52, 132, 42, 40);
  bool touchedBtn_E_Keyboard = touchRect(99, 132, 42, 40);
  bool touchedBtn_R_Keyboard = touchRect(147, 132, 42, 40);
  bool touchedBtn_T_Keyboard = touchRect(194, 132, 42, 40);
  bool touchedBtn_Y_Keyboard = touchRect(242, 132, 42, 40);
  bool touchedBtn_U_Keyboard = touchRect(291, 132, 42, 40);
  bool touchedBtn_I_Keyboard = touchRect(338, 132, 42, 40);
  bool touchedBtn_O_Keyboard = touchRect(386, 132, 42, 40);
  bool touchedBtn_P_Keyboard = touchRect(434, 132, 42, 40);

  bool touchedBtn_A_Keyboard = touchRect(4, 176, 65, 40);
  bool touchedBtn_S_Keyboard = touchRect(74, 176, 42, 40);
  bool touchedBtn_D_Keyboard = touchRect(121, 176, 42, 40);
  bool touchedBtn_F_Keyboard = touchRect(169, 176, 42, 40);
  bool touchedBtn_G_Keyboard = touchRect(216, 176, 42, 40);
  bool touchedBtn_H_Keyboard = touchRect(266, 176, 42, 40);
  bool touchedBtn_J_Keyboard = touchRect(314, 176, 42, 40);
  bool touchedBtn_K_Keyboard = touchRect(361, 176, 42, 40);
  bool touchedBtn_L_Keyboard = touchRect(409, 176, 67, 40);

  bool touchedBtn_Z_Keyboard = touchRect(74, 220, 42, 40);
  bool touchedBtn_X_Keyboard = touchRect(121, 220, 42, 40);
  bool touchedBtn_C_Keyboard = touchRect(169, 220, 42, 40);
  bool touchedBtn_V_Keyboard = touchRect(216, 220, 42, 40);
  bool touchedBtn_B_Keyboard = touchRect(266, 220, 42, 40);
  bool touchedBtn_N_Keyboard = touchRect(314, 220, 42, 40);
  bool touchedBtn_M_Keyboard = touchRect(361, 220, 42, 40);

  if (!touch) {
    touchedBtn_A_Keyboard = false;
    touchedBtn_B_Keyboard = false;
    touchedBtn_C_Keyboard = false;
    touchedBtn_D_Keyboard = false;
    touchedBtn_E_Keyboard = false;
    touchedBtn_F_Keyboard = false;
    touchedBtn_G_Keyboard = false;
    touchedBtn_H_Keyboard = false;
    touchedBtn_I_Keyboard = false;
    touchedBtn_J_Keyboard = false;
    touchedBtn_K_Keyboard = false;
    touchedBtn_L_Keyboard = false;
    touchedBtn_M_Keyboard = false;
    touchedBtn_N_Keyboard = false;
    touchedBtn_O_Keyboard = false;
    touchedBtn_P_Keyboard = false;
    touchedBtn_Q_Keyboard = false;
    touchedBtn_R_Keyboard = false;
    touchedBtn_S_Keyboard = false;
    touchedBtn_T_Keyboard = false;
    touchedBtn_U_Keyboard = false;
    touchedBtn_V_Keyboard = false;
    touchedBtn_W_Keyboard = false;
    touchedBtn_X_Keyboard = false;
    touchedBtn_Y_Keyboard = false;
    touchedBtn_Z_Keyboard = false;
  }

  if (touchedBtn_A_Keyboard) {
    executeBtn = true;
    buttonPressed = 7;
    
    if (shiftActivated) {
      tft.drawString("A", 37, 196, GFXFF);
    } else if (!shiftActivated) {
      tft.drawString("a", 37, 196, GFXFF);
    }
  }

  if (!touchedBtn_A_Keyboard && executeBtn && buttonPressed == 7) {
    executeBtn = false;

    if (shiftActivated) {
      tft.drawString("A", 37, 196, GFXFF);
    } else if (!shiftActivated) {
      tft.drawString("a", 37, 196, GFXFF);
    }
  }

  if (touchedBtn_B_Keyboard) {
    executeBtn = true;
    buttonPressed = 8;

    if (shiftActivated) {
      tft.drawString("B", 284, 238, GFXFF);
    } else if (!shiftActivated) {
      tft.drawString("b", 284, 238, GFXFF);
    }
  }

  if (!touchedBtn_B_Keyboard && executeBtn && buttonPressed == 8) {
    executeBtn = false;

    if (shiftActivated) {
      tft.drawString("B", 284, 238, GFXFF);
    } else if (!shiftActivated) {
      tft.drawString("b", 284, 238, GFXFF);
    }
  }

  if (touchedBtn_C_Keyboard) {
    executeBtn = true;
    buttonPressed = 9;

    if (shiftActivated) {
      tft.drawString("C", 188, 238, GFXFF);
    } else if (!shiftActivated) {
      tft.drawString("c", 188, 238, GFXFF);
    }
  }

  if (!touchedBtn_C_Keyboard && executeBtn && buttonPressed == 9) {
    executeBtn = false;

    if (shiftActivated) {
      tft.drawString("C", 188, 238, GFXFF);
    } else if (!shiftActivated) {
      tft.drawString("c", 188, 238, GFXFF);
    }
  }

  if (touchedBtn_D_Keyboard) {
    executeBtn = true;
    buttonPressed = 10;

    if (shiftActivated) {
      tft.drawString("D", 140, 196, GFXFF);
    } else if (!shiftActivated) {
      tft.drawString("d", 140, 196, GFXFF);
    }
  }

  if (touchedBtn_D_Keyboard && executeBtn && buttonPressed == 10) {
    executeBtn = false;

    if (shiftActivated) {
      tft.drawString("D", 140, 196, GFXFF);
    } else if (!shiftActivated) {
      tft.drawString("d", 140, 196, GFXFF);
    }
  }

  if (touchedBtn_E_Keyboard) {
    executeBtn = true;
    buttonPressed = 11;

    if (shiftActivated) {
      tft.drawString("E", 118, 150, GFXFF);
    } else if (!shiftActivated) {
      tft.drawString("e", 118, 150, GFXFF);
    }
  }

  if (touchedBtn_E_Keyboard && executeBtn && buttonPressed == 11) {
    executeBtn = false;

    if (shiftActivated) {
      tft.drawString("E", 118, 150, GFXFF);
    } else if (!shiftActivated) {
      tft.drawString("e", 118, 150, GFXFF);
    }
  }

  if (touchedBtn_F_Keyboard) {
    executeBtn = true;
    buttonPressed = 12;

    if (shiftActivated) {
      tft.drawString("F", 188, 196, GFXFF);
    } else if (!shiftActivated) {
      tft.drawString("f", 188, 196, GFXFF);
    }
  }

  if (touchedBtn_F_Keyboard && executeBtn && buttonPressed == 12) {
    executeBtn = false;

    if (shiftActivated) {
      tft.drawString("F", 188, 196, GFXFF);
    } else if (!shiftActivated) {
      tft.drawString("f", 188, 196, GFXFF);
    }
  }
  
  if (touchedBtn_G_Keyboard) {
    executeBtn = true;
    buttonPressed = 13;

    if (shiftActivated) {
      tft.drawString("G", 236, 196, GFXFF);
    } else if (!shiftActivated) {
      tft.drawString("g", 236, 196, GFXFF);
    }
  }

  if (touchedBtn_G_Keyboard && executeBtn && buttonPressed == 13) {
    executeBtn = false;

    if (shiftActivated) {
      tft.drawString("G", 236, 196, GFXFF);
    } else if (!shiftActivated) {
      tft.drawString("g", 236, 196, GFXFF);
    }
  }

  if (touchedBtn_H_Keyboard) {
    executeBtn = true;
    buttonPressed = 14;

    if (shiftActivated) {
      tft.drawString("H", 284, 196, GFXFF);
    } else if (!shiftActivated) {
      tft.drawString("h", 284, 196, GFXFF);
    }
  }

  if (touchedBtn_H_Keyboard && executeBtn && buttonPressed == 14) {
    executeBtn = false;

    if (shiftActivated) {
      tft.drawString("H", 284, 196, GFXFF);
    } else if (!shiftActivated) {
      tft.drawString("h", 284, 196, GFXFF);
    }
  }

  if (touchedBtn_I_Keyboard) {
    executeBtn = true;
    buttonPressed = 15;

    if (shiftActivated) {
      tft.drawString("I", 359, 150, GFXFF);
    } else if (!shiftActivated) {
      tft.drawString("i", 359, 150, GFXFF);
    }
  }

  if (touchedBtn_I_Keyboard && executeBtn && buttonPressed == 15) {
    executeBtn = false;

    if (shiftActivated) {
      tft.drawString("I", 359, 150, GFXFF);
    } else if (!shiftActivated) {
      tft.drawString("i", 359, 150, GFXFF);
    }
  }

  if (touchedBtn_J_Keyboard) {
    executeBtn = true;
    buttonPressed = 16;

    if (shiftActivated) {
      tft.drawString("J", 332, 196, GFXFF);
    } else if (!shiftActivated) {
      tft.drawString("j", 332, 196, GFXFF);
    }
  }

  if (touchedBtn_J_Keyboard && executeBtn && buttonPressed == 16) {
    executeBtn = false;

    if (shiftActivated) {
      tft.drawString("J", 332, 196, GFXFF);
    } else if (!shiftActivated) {
      tft.drawString("j", 332, 196, GFXFF);
    }
  }

  if (touchedBtn_K_Keyboard) {
    executeBtn = true;
    buttonPressed = 17;

    if (shiftActivated) {
      tft.drawString("K", 379, 196, GFXFF);
    } else if (!shiftActivated) {
      tft.drawString("k", 379, 196, GFXFF);
    }
  }

  if (touchedBtn_K_Keyboard && executeBtn && buttonPressed == 17) {
    executeBtn = false;

    if (shiftActivated) {
      tft.drawString("K", 379, 196, GFXFF);
    } else if (!shiftActivated) {
      tft.drawString("k", 379, 196, GFXFF);
    }
  }

  if (touchedBtn_L_Keyboard) {
    executeBtn = true;
    buttonPressed = 18;

    if (shiftActivated) {
      tft.drawString("L", 427, 196, GFXFF);
    } else if (!shiftActivated) {
      tft.drawString("l", 427, 196, GFXFF);
    }
  }

  if (touchedBtn_L_Keyboard && executeBtn && buttonPressed == 18) {
    executeBtn = false;

    if (shiftActivated) {
      tft.drawString("L", 427, 196, GFXFF);
    } else if (!shiftActivated) {
      tft.drawString("l", 427, 196, GFXFF);
    }
  }

  if (touchedBtn_M_Keyboard) {
    executeBtn = true;
    buttonPressed = 19;

    if (shiftActivated) {
      tft.drawString("M", 379, 238, GFXFF);
    } else if (!shiftActivated) {
      tft.drawString("m", 379, 238, GFXFF);
    }
  }

  if (touchedBtn_M_Keyboard && executeBtn && buttonPressed == 19) {
    executeBtn = false;

    if (shiftActivated) {
      tft.drawString("M", 379, 238, GFXFF);
    } else if (!shiftActivated) {
      tft.drawString("m", 379, 238, GFXFF);
    }
  }

  if (touchedBtn_N_Keyboard) {
    executeBtn = true;
    buttonPressed = 20;

    if (shiftActivated) {
      tft.drawString("N", 332, 238, GFXFF);
    } else if (!shiftActivated) {
      tft.drawString("n", 332, 238, GFXFF);
    }
  }

  if (touchedBtn_N_Keyboard && executeBtn && buttonPressed == 20) {
    executeBtn = false;

    if (shiftActivated) {
      tft.drawString("N", 332, 238, GFXFF);
    } else if (!shiftActivated) {
      tft.drawString("n", 332, 238, GFXFF);
    }
  }

  if (touchedBtn_O_Keyboard) {
    executeBtn = true;
    buttonPressed = 21;

    if (shiftActivated) {
      tft.drawString("O", 405, 150, GFXFF);
    } else if (!shiftActivated) {
      tft.drawString("o", 405, 150, GFXFF);
    }
  }

  if (touchedBtn_O_Keyboard && executeBtn && buttonPressed == 21) {
    executeBtn = false;

    if (shiftActivated) {
      tft.drawString("O", 405, 150, GFXFF);
    } else if (!shiftActivated) {
      tft.drawString("o", 405, 150, GFXFF);
    }
  }

  if (touchedBtn_P_Keyboard) {
    executeBtn = true;
    buttonPressed = 22;

    if (shiftActivated) {
      tft.drawString("P", 453, 150, GFXFF);
    } else if (!shiftActivated) {
      tft.drawString("p", 453, 150, GFXFF);
    }
  }

  if (touchedBtn_P_Keyboard && executeBtn && buttonPressed == 22) {
    executeBtn = false;

    if (shiftActivated) {
      tft.drawString("P", 453, 150, GFXFF);
    } else if (!shiftActivated) {
      tft.drawString("p", 453, 150, GFXFF);
    }
  }

  if (touchedBtn_Q_Keyboard) {
    executeBtn = true;
    buttonPressed = 23;

    if (shiftActivated) {
      tft.drawString("Q", 23, 150, GFXFF);
    } else if (!shiftActivated) {
      tft.drawString("q", 23, 150, GFXFF);
    }
  }

  if (touchedBtn_Q_Keyboard && executeBtn && buttonPressed == 23) {
    executeBtn = false;

    if (shiftActivated) {
      tft.drawString("Q", 23, 150, GFXFF);
    } else if (!shiftActivated) {
      tft.drawString("q", 23, 150, GFXFF);
    }
  }

  if (touchedBtn_R_Keyboard) {
    executeBtn = true;
    buttonPressed = 24;

    if (shiftActivated) {
      tft.drawString("R", 166, 150, GFXFF);
    } else if (!shiftActivated) {
      tft.drawString("r", 166, 150, GFXFF);
    }
  }

  if (touchedBtn_R_Keyboard && executeBtn && buttonPressed == 24) {
    executeBtn = false;

    if (shiftActivated) {
      tft.drawString("R", 166, 150, GFXFF);
    } else if (!shiftActivated) {
      tft.drawString("r", 166, 150, GFXFF);
    }
  }

  if (touchedBtn_S_Keyboard) {
    executeBtn = true;
    buttonPressed = 25;

    if (shiftActivated) {
      tft.drawString("S", 93, 196, GFXFF);
    } else if (!shiftActivated) {
      tft.drawString("s", 93, 196, GFXFF);
    }
  }

  if (touchedBtn_S_Keyboard && executeBtn && buttonPressed == 25) {
    executeBtn = false;

    if (shiftActivated) {
      tft.drawString("S", 93, 196, GFXFF);
    } else if (!shiftActivated) {
      tft.drawString("s", 93, 196, GFXFF);
    }
  }

  if (touchedBtn_T_Keyboard) {
    executeBtn = true;
    buttonPressed = 26;

    if (shiftActivated) {
      tft.drawString("T", 203, 150, GFXFF);
    } else if (!shiftActivated) {
      tft.drawString("t", 203, 150, GFXFF);
    }
  }

  if (touchedBtn_T_Keyboard && executeBtn && buttonPressed == 26) {
    executeBtn = false;

    if (shiftActivated) {
      tft.drawString("T", 203, 150, GFXFF);
    } else if (!shiftActivated) {
      tft.drawString("t", 203, 150, GFXFF);
    }
  }

  if (touchedBtn_U_Keyboard) {
    executeBtn = true;
    buttonPressed = 27;

    if (shiftActivated) {
      tft.drawString("U", 310, 150, GFXFF);
    } else if (!shiftActivated) {
      tft.drawString("u", 310, 150, GFXFF);
    }
  }

  if (touchedBtn_U_Keyboard && executeBtn && buttonPressed == 27) {
    executeBtn = false;

    if (shiftActivated) {
      tft.drawString("U", 310, 150, GFXFF);
    } else if (!shiftActivated) {
      tft.drawString("u", 310, 150, GFXFF);
    }
  }

  if (touchedBtn_V_Keyboard) {
    executeBtn = true;
    buttonPressed = 28;

    if (shiftActivated) {
      tft.drawString("v", 236, 238, GFXFF);
    } else if (!shiftActivated) {
      tft.drawString("v", 236, 238, GFXFF);
    }
  }

  if (touchedBtn_V_Keyboard && executeBtn && buttonPressed == 28) {
    executeBtn = false;

    if (shiftActivated) {
      tft.drawString("v", 236, 238, GFXFF);
    } else if (!shiftActivated) {
      tft.drawString("v", 236, 238, GFXFF);
    }
  }

  if (touchedBtn_W_Keyboard) {
    executeBtn = true;
    buttonPressed = 29;

    if (shiftActivated) {
      tft.drawString("W", 71, 150, GFXFF);
    } else if (!shiftActivated) {
      tft.drawString("w", 71, 150, GFXFF);
    }
  }

  if (touchedBtn_W_Keyboard && executeBtn && buttonPressed == 29) {
    executeBtn = false;

    if (shiftActivated) {
      tft.drawString("W", 71, 150, GFXFF);
    } else if (!shiftActivated) {
      tft.drawString("w", 71, 150, GFXFF);
    }
  }

  if (touchedBtn_X_Keyboard) {
    executeBtn = true;
    buttonPressed = 30;

    if (shiftActivated) {
      tft.drawString("X", 140, 238, GFXFF);
    } else if (!shiftActivated) {
      tft.drawString("x", 140, 238, GFXFF);
    }
  }

  if (touchedBtn_X_Keyboard && executeBtn && buttonPressed == 30) {
    executeBtn = false;

    if (shiftActivated) {
      tft.drawString("X", 140, 238, GFXFF);
    } else if (!shiftActivated) {
      tft.drawString("x", 140, 238, GFXFF);
    }
  }

  if (touchedBtn_Y_Keyboard) {
    executeBtn = true;
    buttonPressed = 31;

    if (shiftActivated) {
      tft.drawString("Y", 261, 150, GFXFF);
    } else if (!shiftActivated) {
      tft.drawString("y", 261, 150, GFXFF);
    }
  }

  if (touchedBtn_Y_Keyboard && executeBtn && buttonPressed == 31) {
    executeBtn = false;

    if (shiftActivated) {
      tft.drawString("Y", 261, 150, GFXFF);
    } else if (!shiftActivated) {
      tft.drawString("y", 261, 150, GFXFF);
    }
  }

  if (touchedBtn_Z_Keyboard) {
    executeBtn = true;
    buttonPressed = 32;

    if (shiftActivated) {
      tft.drawString("Z", 93, 238, GFXFF);
    } else if (!shiftActivated) {
      tft.drawString("z", 93, 238, GFXFF);
    }
  }

  if (touchedBtn_Z_Keyboard && executeBtn && buttonPressed == 32) {
    executeBtn = false;

    if (shiftActivated) {
      tft.drawString("Z", 93, 238, GFXFF);
    } else if (!shiftActivated) {
      tft.drawString("z", 93, 238, GFXFF);
    }
  }

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
  btn_screenLoaded = 3;
  request[3] = false;

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
    tft.drawRoundRect(102, 65, 275, 30, 5, redTextColor); 

    logo.createSprite(24, 22);
    logo.setSwapBytes(true);
    logo.pushImage(0, 0, 24, 22, shift); // sizeX e sizeY do PNG carregado
    logo.pushSprite(25, 228, backgroundColor); // x e y do PNG carregado
    logo.deleteSprite();

    logo.createSprite(30, 24);
    logo.setSwapBytes(true);
    logo.pushImage(0, 0, 30, 24, backspace); // sizeX e sizeY do PNG carregado
    logo.pushSprite(426, 227, backgroundColor); // x e y do PNG carregado
    logo.deleteSprite();

    tft.drawRoundRect(121, 264, 235, 40, 2, textColor); 
    tft.fillRoundRect(409, 264, 67, 40, 10, bluetoothColor);
    tft.drawRect(427, 285, 29,2, textColor);
    tft.drawRect(454, 275, 2, 10, textColor);
    tft.drawLine(427, 285, 433, 279, textColor);
    tft.drawLine(428, 285, 434, 279, textColor);
    tft.drawLine(427, 286, 433, 292, textColor);
    tft.drawLine(428, 286, 434, 292, textColor);
  }

  if (openKeyboard) {
    tft.setTextDatum(MC_DATUM);
    tft.setTextColor(lightTextColor, backgroundColor);
    smoothText("Lato_Regular_24");

    if (shiftKeyboard == false) {
      tft.drawString("q", 23, 150, GFXFF);
      tft.drawString("w", 71, 150, GFXFF);
      tft.drawString("e", 118, 150, GFXFF);
      tft.drawString("r", 166, 150, GFXFF);
      tft.drawString("t", 203, 150, GFXFF);
      tft.drawString("y", 261, 150, GFXFF);
      tft.drawString("u", 310, 150, GFXFF);
      tft.drawString("i", 359, 150, GFXFF);
      tft.drawString("o", 405, 150, GFXFF);
      tft.drawString("p", 453, 150, GFXFF);

      tft.drawString("a", 37, 196, GFXFF);
      tft.drawString("s", 93, 196, GFXFF);
      tft.drawString("d", 140, 196, GFXFF);
      tft.drawString("f", 188, 196, GFXFF);
      tft.drawString("g", 236, 196, GFXFF);
      tft.drawString("h", 284, 196, GFXFF);
      tft.drawString("j", 332, 196, GFXFF);
      tft.drawString("k", 379, 196, GFXFF);
      tft.drawString("l", 427, 196, GFXFF);

      tft.drawString("z", 93, 238, GFXFF);
      tft.drawString("x", 140, 238, GFXFF);
      tft.drawString("c", 188, 238, GFXFF);
      tft.drawString("v", 236, 238, GFXFF);
      tft.drawString("b", 284, 238, GFXFF);
      tft.drawString("n", 332, 238, GFXFF);
      tft.drawString("m", 379, 238, GFXFF);

    } else if (shiftKeyboard == true) {
      tft.drawString("Q", 23, 150, GFXFF);
      tft.drawString("W", 71, 150, GFXFF);
      tft.drawString("E", 118, 150, GFXFF);
      tft.drawString("R", 166, 150, GFXFF);
      tft.drawString("T", 203, 150, GFXFF);
      tft.drawString("Y", 261, 150, GFXFF);
      tft.drawString("U", 310, 150, GFXFF);
      tft.drawString("I", 359, 150, GFXFF);
      tft.drawString("O", 405, 150, GFXFF);
      tft.drawString("P", 453, 150, GFXFF);

      tft.drawString("A", 37, 196, GFXFF);
      tft.drawString("S", 93, 196, GFXFF);
      tft.drawString("D", 140, 196, GFXFF);
      tft.drawString("F", 188, 196, GFXFF);
      tft.drawString("G", 236, 196, GFXFF);
      tft.drawString("H", 284, 196, GFXFF);
      tft.drawString("J", 332, 196, GFXFF);
      tft.drawString("K", 379, 196, GFXFF);
      tft.drawString("L", 427, 196, GFXFF);

      tft.drawString("Z", 93, 238, GFXFF);
      tft.drawString("X", 140, 238, GFXFF);
      tft.drawString("C", 188, 238, GFXFF);
      tft.drawString("V", 236, 238, GFXFF);
      tft.drawString("B", 284, 238, GFXFF);
      tft.drawString("N", 332, 238, GFXFF);
      tft.drawString("M", 379, 238, GFXFF);
    }
    
    tft.drawString("?123", 35, 284, GFXFF);
    tft.drawString(",", 93, 284, GFXFF);
    tft.drawString(".", 379, 284, GFXFF);
  }

  unsigned long startTime = millis();
  unsigned long timerCheckingModule = 0;
  unsigned long interval = 20;  
  unsigned long loading = 2000; 

  if (loadingBar == 2) {
    tft.fillRect(41, 29, 390, 3, lightRedTextColor);
    tft.fillRect(41, 29, 130, 3, redTextColor);

    tft.fillSmoothCircle(36, 30, 5, redTextColor, backgroundColor);
    tft.fillSmoothCircle(166, 30, 5, redTextColor, backgroundColor);

    tft.drawSmoothCircle(296, 30, 5, redTextColor, backgroundColor);
    tft.fillSmoothCircle(296, 30, 3, backgroundColor, redTextColor);
  
    tft.drawSmoothCircle(426, 30, 5, redTextColor, backgroundColor);
    tft.fillSmoothCircle(426, 30, 3, backgroundColor, redTextColor);  
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
}

// -------------------- PRIMEIRA CONFIGURACOES DE TEMA --------------------
void firstAppTheme() {
  btn_screenLoaded = 2;
  request[2] = false;

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

  if (systemLanguage == 1) {
    tft.setTextDatum(ML_DATUM);
    tft.setTextColor(textColor, backgroundColor);
    smoothText("Lato_Bold_24");
    tft.drawString("What", 67, 65, GFXFF);
    smoothText("Lato_Regular_24");
    tft.drawString("is your name?", 67, 94, GFXFF);
    if (!openKeyboard) {
      tft.drawRoundRect(102, 155, 275, 30, 5, redTextColor);
    } 

  } else if (systemLanguage == 2) {
    tft.setTextDatum(ML_DATUM);
    tft.setTextColor(textColor, backgroundColor);
    smoothText("Lato_Bold_24");
    tft.drawString("Qual", 67, 65, GFXFF);
    smoothText("Lato_Regular_24");
    tft.drawString("é seu nome?", 67, 94, GFXFF);
    if (!openKeyboard) {
      tft.drawRoundRect(102, 155, 275, 30, 5, redTextColor);
    } 
  }


  unsigned long startTime = millis();
  unsigned long timerCheckingModule = 0;
  unsigned long interval = 20;  
  unsigned long loading = 2000; 

  if (loadingBar == 1) {
    tft.fillRect(41, 29, 390, 3, lightRedTextColor);
    tft.fillRect(41, 29, 130, 3, redTextColor);

    tft.fillSmoothCircle(36, 30, 5, redTextColor, backgroundColor);
    tft.fillSmoothCircle(166, 30, 5, redTextColor, backgroundColor);

    tft.drawSmoothCircle(296, 30, 5, redTextColor, backgroundColor);
    tft.fillSmoothCircle(296, 30, 3, backgroundColor, redTextColor);
  
    tft.drawSmoothCircle(426, 30, 5, redTextColor, backgroundColor);
    tft.fillSmoothCircle(426, 30, 3, backgroundColor, redTextColor);
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
    loadingBar = 2;
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
  btn_screenLoaded = 1;
  request[1] = false;

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

  if (loadingBar == 0) {
    tft.fillRect(41, 29, 390, 3, lightRedTextColor);

    tft.fillSmoothCircle(36, 30, 5, redTextColor, backgroundColor);
    tft.drawSmoothCircle(166, 30, 5, redTextColor, backgroundColor);
    tft.fillSmoothCircle(166, 30, 3, backgroundColor, redTextColor);

    tft.drawSmoothCircle(296, 30, 5, redTextColor, backgroundColor);
    tft.fillSmoothCircle(296, 30, 3, backgroundColor, redTextColor);
  
    tft.drawSmoothCircle(426, 30, 5, redTextColor, backgroundColor);
    tft.fillSmoothCircle(426, 30, 3, backgroundColor, redTextColor);  
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
    loadingBar = 1;
  }
}

// -------------------- INICIALIZACAO DO APARELHO --------------------
void firstLoading() {
  unsigned long timerCheckingModule = 0;
  unsigned long timerNotPoweredConnected = 0;
  unsigned long interval = 20;  
  unsigned long bargraphTime = 5000; 
  unsigned long logoTime = 5000;
  unsigned long notPoweredTime = 5000;
  byte powerConnect = 0;

  powerConnect = digitalRead(pinPowered);

  if (powerConnect > 0) {
    Serial.println("Device connected to a power source");
    digitalWrite(pinBL, HIGH);
    if (firstInicialization == false) {
      logo.createSprite(165, 165);
      logo.setSwapBytes(true);
      logo.pushImage(0, 0, 165, 165, MufoxLogo); // sizeX e sizeY do PNG carregado
      logo.pushSprite(158, 37, TFT_BLACK); // x e y do PNG carregado
      logo.deleteSprite();
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

          // CARREGAMENTO COM PERCA DE VELOCIDADE
          //float progress = (millis() - startTime) / (float)bargraphTime;
          //float easedProgress = easeOutCubic(progress);  // Função de desaceleração aplicada ao progresso
          //float width = easedProgress * 220;
          //tft.drawLine(width + 130, 245, width + 130, 260, blockColor); 
        }
        firstSettings = 1;
        loaded[0] = false;
        loaded[1] = true;
      }
    } 
    return;
  }
  if ((firstInicialization == true) && (powerConnect == 0)) {
    Serial.println("Device not connect to a power source");

    digitalWrite(pinBL, HIGH);
    unsigned long startTime = millis();

    while (millis() - startTime <= notPoweredTime) {
      if (millis() - timerNotPoweredConnected >= 10) {
        timerNotPoweredConnected = millis();

        tft.setTextDatum(MC_DATUM);
        tft.setTextColor(textColor, backgroundColor);
        smoothText("Lato_Bold_24");
        tft.drawString("Connect to", 240, 104, GFXFF);
        tft.drawString("Power suppy", 240, 125, GFXFF);
        tft.setSwapBytes(true);
        tft.pushImage(216, 175, 48, 64, bigPowerImage);
      }
    }
    digitalWrite(pinBL, LOW);
    loaded[0] = false;
    tft.fillScreen(darkBackgroundColor);
  } 
  else if (firstInicialization == false) {
    tft.fillScreen(darkBackgroundColor);
    Serial.println("Device turned on");

    digitalWrite(pinBL, HIGH);
    unsigned long startTime = millis();

    while (millis() - startTime <= notPoweredTime) {
      if (millis() - timerNotPoweredConnected >= 10) {
        timerNotPoweredConnected = millis();

        tft.setTextDatum(MC_DATUM);
        tft.setTextColor(textColor, backgroundColor);
        smoothText("Lato_Bold_24");
        tft.drawString("Welcome back!", 240, 64, GFXFF);
        tft.drawString("We miss you..", 240, 105, GFXFF);
        //tft.setSwapBytes(true);
        //tft.pushImage(216, 175, 48, 64, bigPowerImage);
        tft.fillRect(190, 134, 100, 100, whiteColor);
      }
    }
    tft.fillScreen(darkBackgroundColor);
  }
}

// -------------------- FUNCAO DE CARREGAMENTO DAS TELAS --------------------
void loadScreen(void (*drawFunction)(), bool& loaded, bool& request) {
  if (loaded) {
    if((loadingBar == 1) || (loadingBar == 2)) {
      tft.fillRect(62, 53, 157, 60, backgroundColor);
      tft.fillRect(140, 123, 200, 150, backgroundColor);
      tft.fillRect(405, 243, 70, 30, backgroundColor);      
      tft.fillRect(31, 9, 55, 15, backgroundColor);      
      tft.fillRect(143, 9, 55, 15, backgroundColor);      
      tft.fillRect(273, 9, 55, 15, backgroundColor);      
      tft.fillRect(383, 9, 55, 15, backgroundColor);            
    }  
    if (keyboardShow == 1) {
      tft.fillRect(97, 152, 284, 36, whiteColor);
      tft.fillRect(62, 53, 157, 60, backgroundColor);
      tft.fillRect(140, 123, 200, 150, backgroundColor);
      tft.fillRect(405, 243, 70, 30, backgroundColor); 
      tft.fillRect(31, 9, 55, 15, backgroundColor);      
      tft.fillRect(143, 9, 55, 15, backgroundColor);      
      tft.fillRect(273, 9, 55, 15, backgroundColor);      
      tft.fillRect(383, 9, 55, 15, backgroundColor); 
    } else {
      tft.fillScreen(backgroundColor);
    }
    drawFunction();
    loaded = false;
    return;
  } else if (request) {
    if((loadingBar == 1) || (loadingBar == 2)) {
      tft.fillRect(62, 53, 157, 60, backgroundColor);
      tft.fillRect(140, 123, 200, 150, backgroundColor);
      tft.fillRect(405, 243, 70, 30, backgroundColor); 
      tft.fillRect(31, 9, 55, 15, backgroundColor);      
      tft.fillRect(143, 9, 55, 15, backgroundColor);      
      tft.fillRect(273, 9, 55, 15, backgroundColor);      
      tft.fillRect(383, 9, 55, 15, backgroundColor);  
    }  
    if (keyboardShow == 1) {
      tft.fillRect(97, 152, 284, 36, backgroundColor);
      tft.fillRect(62, 53, 157, 60, backgroundColor);
      tft.fillRect(140, 123, 200, 150, backgroundColor);
      tft.fillRect(405, 243, 70, 30, backgroundColor); 
      tft.fillRect(31, 9, 55, 15, backgroundColor);      
      tft.fillRect(143, 9, 55, 15, backgroundColor);      
      tft.fillRect(273, 9, 55, 15, backgroundColor);      
      tft.fillRect(383, 9, 55, 15, backgroundColor); 
    } else {
      tft.fillScreen(backgroundColor);
    }
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
