// Font file is stored in SPIFFS
#define FS_NO_GLOBALS
#include <FS.h>
#include <TFT_eSPI.h> 
#include <SPI.h>
#include <Wire.h>
//#include <PNGdec.h>
#include <WiFi.h>

#include "Imagens.h"
#include "main.h"

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

// -------------------- CORES DISPLAY RGB 555 --------------------

uint16_t DarkBackgroundColor = 0x2988;  //0x2F3243

// -------------------- FUNCOES E AJUSTES NAO CONFIGURAVEIS --------------------
const int pwmResolution = 8;   // Resolucao PWM (8 bits para o ESP32)
const int pwmFrequency = 5000;  // Frequencia do sinal PWM em Hz
const int fadeDuration = 3000;  // Duracao do carregamento da tela (em milissegundos)
const int holdDuration = 2000;  // Duracao da saida mantida em 100% (em milissegundos)

unsigned long startTime;   // Tempo de início da transição

unsigned long currentTime = millis(); // Tempo real para funcoes

byte firstInicialization = 0; // Define a primeira inicializacao do aparelho
  // firstInicialization = 0 Nao executado primeira inicializacao
  // firstInicialization = 1 Executado primeira inicializacao

byte displayTFT = 0;


// -------------------- FUNCOES E AJUSTES CONFIGURAVEIS --------------------
  byte touchSet = 2;
  // touchSet = 0 Display nao calibrado
  // touchSet = 1 Display calibrado
  // touchSet = 2 Usando os valores do DESENVOLVEDOR no setup()
  // touchSet = 3 Em finalizacao de calibracao


// -------------------- INSTANCIAS DAS BIBLIOTECAS --------------------
  TFT_eSPI tft = TFT_eSPI();      // Instancia da biblioteca TFT_eSPI
  //PNG png;                        // Instancia decodificador PNG

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
    uint16_t calData[5] = { 223, 3675, 227, 3503, 7 };
    tft.setTouch(calData);
  }
}

void loop() {
  unsigned long currentTime = millis();





  // -------------------- AJUSTE DE BRILHO DA TELA -------------------- 
  if (firstInicialization == 0) {
    unsigned long elapsedTime = currentTime - startTime;

    int dutyCycle = map(elapsedTime, 0, fadeDuration, 0, (1 << pwmResolution) - 1);
    dacWrite(pinBL, dutyCycle);
    Serial.println(dutyCycle);

    if (elapsedTime >= fadeDuration) {
      startTime = currentTime;   // Atualiza o tempo de início
      firstInicialization = 1;
    }
  }

  if (displayTFT == 0) {
    tft.fillScreen(DarkBackgroundColor);
    tft.setSwapBytes(true);
    tft.pushImage(0, 0, 165, 165, mufoxStart); //white white white white white white ATIVAR PARA USAR
    displayTFT = 1;
    
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
}

void logoImageStart() {

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



