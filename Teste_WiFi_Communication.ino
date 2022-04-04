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
*/

// ------------------------------------------------------ VARIAVEIS DE CONFIGURACAO -------------------- (AJUSTAR AO PROGRAMA BASE)

unsigned long nixieEffect = millis();

int compareTimesMins = 0;

byte effectModeNixie = 0;
//effectModeNixie = 0 Animação Nixie desativado
//effectModeNixie = 1 Animação Nixie estilo Metro
//effectModeNixie = 2 Animação Nixie Númerico 

int numberArray[4] = { 0, 0, 0, 0}; // Armazena os dados de cada flashNixie para cada Nixie
int flashNixie = 0;         // Armazena valor para inserção no Driver
int nixieCounts = 0;        // Identifica o Pino a ser acionado do Driver
int nixieAnode = 0;         // Identifica o Pino para o efeito refresh
int compareTimeMins;        // Armazena tempo Minutos (ADICIONAR MESMO DA FUNCAO PRINCIPAL)
float updateNixie = 7;    // Variavel armazena taxa de atualização
int speedEffect = 25;       // Taxa de atualização do Efeito
int speedEffectSet = speedEffect * 4;

/*
  Canal de ajuste do ST7789 criar uma pagina para o ajuste da frequência de atualização
  indicar sendo de 5 ~ 10

  2.0 ~ 6.9  = taxa atualização não visivel
  7.0 ~ 7.9  = taxa atualização visivel leve
  8.0 ~ 10.0 = taxa atualização visivel forte

*/

int reset = 27;


#include <WiFiManager.h>
#include <TimeLib.h>
#include <WiFiUdp.h>
#include <DNSServer.h>

#include <Wire.h>
#include <SPI.h>

byte delayTime = 0;

time_t prevDisplay = 0;
time_t getNtpTime();

const bool hOUR_12 = false;
const int tIME_OFFSET = -3;
const int tIME_ZONE = 1;

//static const char ntpServerName[] = "a.st1.ntp.br";
//static const char ntpServerName[] = "b.st1.ntp.br";
//static const char ntpServerName[] = "c.st1.ntp.br";
//static const char ntpServerName[] = "d.st1.ntp.br";
//static const char ntpServerName[] = "a.ntp.br";
//static const char ntpServerName[] = "b.ntp.br";
//static const char ntpServerName[] = "c.ntp.br";
static const char ntpServerName[] = "gps.ntp.br";

// ------------------------------- INSTANCIAS DAS BIBLIOTECAS --------------------------

WiFiManager wifiManager;
WiFiUDP Udp;

unsigned int localPort = 5355;

void digitalClockDisplay();
void printDigits(int digits);
void sendNTPpacket(IPAddress &address);
void setup() {
  	Serial.begin(500000);
  	pinMode(reset, INPUT_PULLUP);
  
  	WiFiManager wifiManager;
  	wifiManager.autoConnect("JanelaSmart","123456789");
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

}

void loop() {
  	hour2 = hour();
  	minute2 = minute(); 
  	second2 = second(); 
  	delay(delayTime);
  	digitalClockDisplay();

  	if (digitalRead(reset) == HIGH ) {
    	WiFiManager wifiManager;
    	if (!wifiManager.startConfigPortal("JanelaSmart", "123456789") )  {
      	Serial.println(" Falha ao conectar"); 
      	delay(10000);

      	ESP.restart();   
    	}
  	}
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

const int NTP_PACKET_SIZE = 48; // NTP time is in the first 48 bytes of message
byte packetBuffer[NTP_PACKET_SIZE]; //buffer to hold incoming & outgoing packets
time_t getNtpTime() {
  	IPAddress ntpServerIP; // NTP server's ip address
  	while (Udp.parsePacket() > 0); // discard any previously received packets
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
		      	return secsSince1900 - 2208988800UL + tIME_OFFSET * SECS_PER_HOUR;
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
  	Serial.println(" Entrou no modo de configuração");
  	Serial.println(WiFi.softAPIP()); //imprime o IP do AP
  	Serial.println(myWiFiManager->getConfigPortalSSID()); //imprime o SSID criado da rede
}

void saveConfigCallback () {
  	Serial.println(" Configuração salva");
}