/*
Sequencia Flash Nixie 
6 7 5 8 4 3 9 2 0 1 
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
ESP32 - Alimentação Ideal 3v3 possível 5V mas com aquecimento
EN
GPIO1   UART TX CP2102 
GPIO2
GPIO3   UART RX CP2102
GPIO4
GPIO5   Pino Nixie A
GPIO6
GPIO7
GPIO8
GPIO9
GPIO10
GPIO11
GPIO12  Anode Nixie C
GPIO13  Anode Nixie D
GPIO14  Anode Nixie B
GPIO15  
GPIO16  UART TX STM32 (Slave)
GPIO17  UART RX STM32 (Slave)
GPIO18  Pino Nixie B
GPIO19  Pino Nixie C
GPIO21  Pino Nixie D
GPIO22  Botão Hibernar
GPIO23  Botão Menu
GPIO25  Botão Cima
GPIO26  Botão Baixo
GPIO27  Anode Nixie A 
GPIO32
GPIO33
GPIO34
GPIO35
GPIO36  LDR Sensor
GPIO39  HardReset (Button for Fail)
connect a 10 uF electrolytic capacitor between the EN pin and GND
Acessa o canal via GPIO16 
#define 16 XXXX
*/

//------------------------------- VALORES AJUSTAVEIS PELO USUÁRIO --------------------
const char *userNameWiFi = "MinervaProject";
const char *passWordWiFi = "MinervaProject";

int compareTimesMins = 0;

float updateNixie = 7;    // Variavel armazena taxa de atualização
int speedEffect = 25;       // Taxa de atualização do Efeito

/*
    Canal de ajuste do ST7789 criar uma pagina para o ajuste da frequência de atualização
    indicar sendo de 5 ~ 10
    2.0 ~ 6.9  = taxa atualização não visivel
    7.0 ~ 7.9  = taxa atualização visivel leve
    8.0 ~ 10.0 = taxa atualização visivel forte
*/
 
//------------------------------- ARMAZENAMENTO DE DADOS E COMPARADORES ---------------

unsigned long nixieEffect = millis();

byte effectModeNixie = 1;
//effectModeNixie = 0 Animação Nixie desativado
//effectModeNixie = 1 Animação Nixie estilo Metro
//effectModeNixie = 2 Animação Nixie Númerico 


byte displayNow;

int numberArray[4] = { 0, 0, 0, 0}; // Armazena os dados de cada flashNixie para cada Nixie
int flashNixie = 0;         // Armazena valor para inserção no Driver
int nixieCounts = 0;        // Identifica o Pino a ser acionado do Driver
int nixieAnode = 0;         // Identifica o Pino para o efeito refresh
int compareTimeMins;        // Armazena tempo Minutos
int* prt;                   // Corrige falha de Processadores ARM

// DADOS NTC
unsigned int localPort = 8888;  

int lowerHours;             // Armazena dados de Hora 2
int upperHours;             // Armazena dados de Hora 1
int lowerMins;              // Armazena dados de Minuto 2
int upperMins;              // Armazena dados de Minuto 1
int lowerSeconds;           // Armazena dados de Segundos 2
int upperSeconds;           // Armazena dados de Segundo 1

// NTP Servers:
static const char ntpServerName[] = "us.pool.ntp.org";
//static const char ntpServerName[] = "time.nist.gov";
//static const char ntpServerName[] = "time-a.timefreq.bldrdoc.gov";
//static const char ntpServerName[] = "time-b.timefreq.bldrdoc.gov";
//static const char ntpServerName[] = "time-c.timefreq.bldrdoc.gov";
//static const char ntpServerName[] = "server 0.br.pool.ntp.or";
//static const char ntpServerName[] = "server 1.br.pool.ntp.or";
//static const char ntpServerName[] = "server 2.br.pool.ntp.or";
//static const char ntpServerName[] = "server 3.br.pool.ntp.or";
//static const char ntpServerName[] = "a.st1.ntp.br";
//static const char ntpServerName[] = "b.st1.ntp.br";
//static const char ntpServerName[] = "c.st1.ntp.br";
//static const char ntpServerName[] = "d.st1.ntp.br";
//static const char ntpServerName[] = "gps.ntp.br";


time_t prevDisplay = 0;
time_t getNtpTime();

const bool hour_12 = false;
const int timeZone = -3;
const int NTP_PACKET_SIZE = 48; // NTP time is in the first 48 bytes of message
byte packetBuffer[NTP_PACKET_SIZE]; //buffer to hold incoming & outgoing packets

#define pinAnode0 27            // Pino Nixie Anodo Hora 1 
#define pinAnode1 14            // Pino Nixie Anodo Hora 2
#define pinAnode2 12            // Pino Nixie Anodo Minuto 1
#define pinAnode3 13            // Pino Nixie Anodo Minuto 2

#define driverPinA 5            // Pino Driver Catodo A
#define driverPinB 18           // Pino Driver Catodo B
#define driverPinC 19           // Pino Driver Catodo C
#define driverPinD 21           // Pino Driver Catodo D

#define button_Sleep 22         // Modo repouso * Apertar e Pressionar BUTTON_UP
#define button_Mode 23          // Selecionar Modo Geiger, Clima ou Calendário
#define button_Up 25            // Sobe no Menu 
#define button_Down 26          // Desce no Menu 

#define ldrSensor 36            // Pino Sensor LDR 

#define hardReset 39            // HardReset (Button for Fail)

#define batteryLevel 34         // Leitura do Nivel da Bateria
#define chargeBattery 35        // Leitura do Carregador Bateria
#define fullCharger 32          // Leitura da Bateria Cheia
#define buzzerCharger 25        // Sinal de Bateria Carregada

#include <WiFiManager.h>
#include <TimeLib.h>
#include <WiFiUdp.h>
#include <DNSServer.h>

#include "WiFi.h"
#include "ESPAsyncWebServer.h"

#include "SoftwareSerial.h"

#include <Wire.h>
#include <SPI.h>

// ------------------------------- INSTANCIAS DAS BIBLIOTECAS --------------------------

WiFiManager wifiManager;
WiFiUDP Udp;

AsyncWebServer server1(80);
AsyncWebServer server2(81);
AsyncWebServer server3(82);

SoftwareSerial blackBoardSlave(3, 1); //RX TX

void digitalClockDisplay();
void printDigits(int digits);
void sendNTPpacket(IPAddress &address);

void setup(){
	blackBoardSlave.begin(250000);
    Serial.begin(500000);

    //Serial.println("Apagando Configurações e reiniciando");
    //wifiManager.resetSettings();

    wifiManager.autoConnect(userNameWiFi, passWordWiFi);
	wifiManager.setAPCallback(configModeCallback);
	delay(1000);
	wifiManager.setSaveConfigCallback(saveConfigCallback);   
	Serial.print("Número de IP identificado pelo DHCP é: ");
	Serial.println(WiFi.localIP());
	Serial.println("Iniciando UDP");
	Udp.begin(localPort);
	Serial.print("Porta Local: ");
 
  	setSyncProvider(getNtpTime);

  	Serial.print(" ");    
  	Serial.print(hour());
  	printDigits(minute());
  	printDigits(second());
  	Serial.print(" ");
  	Serial.print(day());
  	Serial.print(".");
  	Serial.print(month());
  	Serial.print(".");
  	Serial.print(year());
  	Serial.println(" ");
  	delay(1000);

    bool res;
    // res = wifiManager.autoConnect(); // auto generated AP name from chipid
    // res = wifiManager.autoConnect("AutoConnectAP"); // anonymous ap
    res = wifiManager.autoConnect(userNameWiFi, passWordWiFi); // password protected ap

    if(!res) {
        Serial.println("Failed to connect or hit timeout");
        ESP.restart();
    } else {
        Serial.println("Selected Wifi connected)");
    }

    wifiManager.setAPCallback(configModeCallback);
    delay(1000);
    wifiManager.setSaveConfigCallback(saveConfigCallback);   
    Serial.print("Número de IP identificado pelo DHCP é: ");
    Serial.println(WiFi.localIP());
    Serial.println("Iniciando UDP");
    Udp.begin(localPort);
    Serial.print("Porta Local: ");
    setSyncProvider(getNtpTime);
    setSyncInterval(300);
    delay(1000);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
  	if (!wifiManager.startConfigPortal(userNameWiFi, passWordWiFi))  {
      	Serial.println(" Falha ao conectar"); 
      	delay(10000);
      	ESP.restart();   
    }

    server1.on("/hello", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/plain", "Hello from server 1");
  });
 
  server2.on("/hello", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/plain", "Hello from server 2");
  });
 
  server3.on("/test", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/plain", "Hello from server 3");
  });
 
  server1.begin();
  server2.begin();
  server3.begin();
}
 
void loop(){
	//digitalClockDisplay();
}


void digitalClockDisplay() {
  Serial.print(" ");  
  Serial.print(hour());
  printDigits(minute());
  printDigits(second());
  Serial.print(" ");
  Serial.print(day());
  Serial.print(".");
  Serial.print(month());
  Serial.print(".");
  Serial.print(year());
  Serial.println(" ");
}

void printDigits(int digits) {
  Serial.print(":");
  if (digits < 10)
    Serial.print('0');
  Serial.print(digits);
}


time_t getNtpTime() {
  IPAddress ntpServerIP; // NTP server's ip address
  while (Udp.parsePacket() > 0) ; // discard any previously received packets
  Serial.println(" Transmitindo solicitação de NTP");
  WiFi.hostByName(ntpServerName, ntpServerIP);
  Serial.print(ntpServerName);
  Serial.print(": ");
  Serial.println(ntpServerIP);
  sendNTPpacket(ntpServerIP);
  uint32_t beginWait = millis();
  while (millis() - beginWait < 1500) {
    int siZe = Udp.parsePacket();
    if (siZe >= NTP_PACKET_SIZE) {
      Serial.println(" Resposta de NTP recebida");
      Udp.read(packetBuffer, NTP_PACKET_SIZE);  // read packet into the buffer
      unsigned long secsSince1900;
      secsSince1900 =  (unsigned long)packetBuffer[40] << 24;
      secsSince1900 |= (unsigned long)packetBuffer[41] << 16;
      secsSince1900 |= (unsigned long)packetBuffer[42] << 8;
      secsSince1900 |= (unsigned long)packetBuffer[43];
      return secsSince1900 - 2208988800UL + timeZone * SECS_PER_HOUR;
    }
  }
  Serial.println(" Sem respota de NTP");
  return 0; // return 0 if unable to get the time
}

void sendNTPpacket(IPAddress &address) {
  memset(packetBuffer, 0, NTP_PACKET_SIZE);
  packetBuffer[0] = 0b11100011;   // LI, Version, Mode
  packetBuffer[1] = 0;     // Stratum, or type of clock
  packetBuffer[2] = 6;     // Polling Interval
  packetBuffer[3] = 0xEC;  // Peer Clock Precision
  packetBuffer[12] = 49;
  packetBuffer[13] = 0x4E;
  packetBuffer[14] = 49;
  packetBuffer[15] = 52;
  Udp.beginPacket(address, 123); //NTP requests are to port 123
  Udp.write(packetBuffer, NTP_PACKET_SIZE);
  Udp.endPacket();
}

byte format_hour(byte hr) {
    if (hr > 24){
      hr-=24;
    }
    if (hr == 0){
      hr = 24;
    }
    return hr;
}

void configModeCallback (WiFiManager *myWiFiManager) {  
  Serial.println("Entered config mode");
  Serial.println(" Entrou no modo de configuração");
  Serial.println(WiFi.softAPIP()); //imprime o IP do AP
  Serial.println(myWiFiManager->getConfigPortalSSID()); //imprime o SSID criado da rede
}

void saveConfigCallback () {
  Serial.println(" Configuração salva");
}