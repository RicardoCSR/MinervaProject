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

uint16_t darkBackgroundColor = 0x2988;  //0x2F3243
uint16_t lightBackgroundColor = 0xEF9D; //0xF3F3F3
uint16_t backgroundColor;

uint16_t redTextColor = 0xF30D;         //0xFC6470
uint16_t orangeTextColor = 0xDAA1;      //0xE65510
uint16_t greenTextColor = 0x4FEF;       //0x50FF7D
uint16_t lightTextColor = 0xEFBE;       //0xF3F8FE
uint16_t darkTextColor = 0x2988;        //0x2F3243
uint16_t textColor;

uint16_t blockColor = 0xEFBE;           //0XF3F8FE



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

byte colorBackgroundValue = 0;      // Define qual a cor de background
  // byte colorBackgroundValue = 0 Definido como fundo Escuro
  // byte colorBackgroundValue = 1 Definido como fundo Claro

byte colorTextValue = 0;            // Define qual a cor de texto
  // byte colorTextValue = 0 Definido como texto Claro
  // byte colorTextValue = 1 Definido como texto Escuro
  // byte colorTextValue = 2 Definido como texto Colorido

  byte error = 0;                   // Armazena e define erros encontrados
  

// -------------------- FUNCOES E AJUSTES CONFIGURAVEIS --------------------
  byte touchSet = 2;
  // touchSet = 0 Display nao calibrado
  // touchSet = 1 Display calibrado
  // touchSet = 2 Usando os valores do DESENVOLVEDOR no setup()
  // touchSet = 3 Em finalizacao de calibracao


// -------------------- INSTANCIAS DAS BIBLIOTECAS --------------------
  TFT_eSPI tft = TFT_eSPI();      // Instancia da biblioteca TFT_eSPI para operacao do display
  TFT_eSprite logo = TFT_eSprite(&tft); // Instancia da biblioteca TFT_eSPI para imagem PNG
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
  tft.fillScreen(darkBackgroundColor);
}

void loop() {
  unsigned long currentTime = millis();
  unsigned long elapsedTime = 0;

  firstSettings();



  // -------------------- AJUSTE DE BRILHO DA TELA -------------------- 


  if (displayTFT == 0) {

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
void firstSettings() {
  unsigned long timerCheckingModule = 0;
  unsigned long interval = 20;  
  unsigned long bargraphTime = 5000; 
  unsigned long logoTime = 2500;

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
}



// Função de desaceleração cúbica (Ease Out Cubic)
float easeOutCubic(float t) {
  t--;
  return t * t * t + 1.0;
}
// Função de aceleração cúbica (Ease In Cubic)
float easeInCubic(float t) {
  return t * t * t;
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

