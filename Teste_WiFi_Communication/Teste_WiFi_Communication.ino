/*
PCF8574
Alimentação 2.6 a 3.6V

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


ESP8266 - Alimentação Ideal 3v3 possível 5V mas com aquecimento

R       Botao Hard Reset

RST     Alimentacao LDR
EN

ADC0    LDR Sensor

GPIO0   TRIGGER_PIN
GPIO1   NÃO UTILIZÁVEL
GPIO2   Anode Nixie A        
GPIO3   Anode Nixie B
GPIO4   SDA Micro STM32 (Slave)
GPIO5   SCL Micro STM32 (Slave)
GPIO6   Anode Nixie C
GPIO7   Anode Nixie D
GPIO8   NÃO UTILIZÁVEL
GPIO9   NÃO UTILIZÁVEL
GPIO10  Botão Hibernar
GPIO11  NÃO UTILIZÁVEL
GPIO12  Botão Menu
GPIO13  Pino Nixie A
GPIO14  Pino Nixie B  
GPIO15  Pino Nixie C
GPIO16  Pino Nixie D

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
	// DADOS NIXIE

unsigned long nixieEffect = millis();

byte effectModeNixie = 1;
//effectModeNixie = 0 Animação Nixie desativado
//effectModeNixie = 1 Animação Nixie estilo Metro
//effectModeNixie = 2 Animação Nixie Númerico 

int numberArray[4] = { 0, 0, 0, 0}; // Armazena os dados de cada flashNixie para cada Nixie
int flashNixie = 0;         // Armazena valor para inserção no Driver
int nixieCounts = 0;        // Identifica o Pino a ser acionado do Driver
int nixieAnode = 0;         // Identifica o Pino para o efeito refresh
int compareTimeMins;        // Armazena tempo Minutos (ADICIONAR MESMO DA FUNCAO PRINCIPAL)
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

const int timeZone = -3;     
const int NTP_PACKET_SIZE = 48; // NTP time is in the first 48 bytes of message
byte packetBuffer[NTP_PACKET_SIZE]; //buffer to hold incoming & outgoing packets

#define TRIGGER_PIN 0           // ESTADO WI-FI

#define pinAnode0 4             // Pino Nixie Anodo Hora 1 
#define pinAnode1 3             // Pino Nixie Anodo Hora 2
#define pinAnode2 10            // Pino Nixie Anodo Minuto 1
#define pinAnode3 12            // Pino Nixie Anodo Minuto 2

#define driverPinA 13           // Pino Driver Catodo A
#define driverPinB 14           // Pino Driver Catodo B
#define driverPinC 15           // Pino Driver Catodo C
#define driverPinD 16           // Pino Driver Catodo D

#include <TimeLib.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <WiFiManager.h> 

// ------------------------------- INSTANCIAS DAS BIBLIOTECAS --------------------------

WiFiUDP Udp;
WiFiManager wm; 
WiFiManagerParameter custom_field; 


time_t getNtpTime();
void digitalClockDisplay();
void printDigits(int digits);
void sendNTPpacket(IPAddress &address);

void setup() {
	Serial.begin(115200);

	Serial.setDebugOutput(true);  
	pinMode(TRIGGER_PIN, INPUT);
	delay(1000);

	pinMode(pinAnode0, OUTPUT);
	pinMode(pinAnode1, OUTPUT);
	pinMode(pinAnode2, OUTPUT);
	pinMode(pinAnode3, OUTPUT);
	
	pinMode(driverPinA, OUTPUT);
	pinMode(driverPinB, OUTPUT);
	pinMode(driverPinC, OUTPUT);
	pinMode(driverPinD, OUTPUT);

	WiFi.mode(WIFI_STA); // explicitly set mode, esp defaults to STA+AP  
	int customFieldLength = 40;
	//WiFi.disconnect();

	while (WiFi.status() != WL_CONNECTED) {
		delay(500);
		Serial.print(".");

		const char* custom_radio_str = "<br/><label for='customfieldid'>Custom Field Label</label><input type='radio' name='customfieldid' value='1' checked> One<br><input type='radio' name='customfieldid' value='2'> Two<br><input type='radio' name='customfieldid' value='3'> Three";
		new (&custom_field) WiFiManagerParameter(custom_radio_str); // custom html input
		
		wm.addParameter(&custom_field);
		wm.setSaveParamsCallback(saveParamCallback);

		// custom menu via array or vector
		// 
		// menu tokens, "wifi","wifinoscan","info","param","close","sep","erase","restart","exit" (sep is seperator) (if param is in menu, params will not show up in wifi page!)
		// const char* menu[] = {"wifi","info","param","sep","restart","exit"}; 
		// wm.setMenu(menu,6);
		std::vector<const char *> menu = {"wifi","info","param","sep","restart","exit"};
		wm.setMenu(menu);

		// set dark theme
		wm.setClass("invert");


		//set static ip
		//wm.setSTAStaticIPConfig(IPAddress(10,0,1,99), IPAddress(10,0,1,1), IPAddress(255,255,255,0)); // set static ip,gw,sn
		// wm.setShowStaticFields(true); // force show static ip fields
		// wm.setShowDnsFields(true);    // force show dns field always

		// wm.setConnectTimeout(20); // how long to try to connect for before continuing
		wm.setConfigPortalTimeout(180); // auto close configportal after n seconds
		// wm.setCaptivePortalEnable(false); // disable captive portal redirection
		// wm.setAPClientCheck(true); // avoid timeout if client connected to softap

		// wifi scan settings
		// wm.setRemoveDuplicateAPs(false); // do not remove duplicate ap names (true)
		// wm.setMinimumSignalQuality(20);  // set min RSSI (percentage) to show in scans, null = 8%
		// wm.setShowInfoErase(false);      // do not show erase button on info page
		// wm.setScanDispPerc(true);       // show RSSI as percentage not graph icons
		// wm.setBreakAfterConfig(true);   // always exit configportal even if wifi save fails

		bool res;
		// res = wm.autoConnect(); // auto generated AP name from chipid
		// res = wm.autoConnect("AutoConnectAP"); // anonymous ap
		res = wm.autoConnect(userNameWiFi, passWordWiFi); // password protected ap

		if(!res) {
			Serial.println("Failed to connect or hit timeout");
			ESP.restart();
		} else {
			Serial.println("Selected Wifi connected)");
		}
	}

	Serial.print("IP number assigned by DHCP is: ");
	Serial.println(WiFi.localIP());
	Serial.println("Starting UDP: ");
	Udp.begin(localPort);
	Serial.print("Local port: ");
	Serial.println(Udp.localPort());
	Serial.println("waiting for sync");
	setSyncProvider(getNtpTime);
	setSyncInterval(300);
}

time_t prevDisplay = 0; // when the digital clock was displayed

void loop() {
	unsigned long nixieEffect = millis();
	checkButton();
	nixie();
	if (timeStatus() != timeNotSet) {
		if (now() != prevDisplay) { //update the display only if time has changed
			prevDisplay = now();
			digitalClockDisplay();
		}
	}
}

void checkButton(){
	// check for button press
	if ( digitalRead(TRIGGER_PIN) == LOW ) {
		// poor mans debounce/press-hold, code not ideal for production
		delay(50);
		if( digitalRead(TRIGGER_PIN) == LOW ){
			Serial.println("Button Pressed");
			// still holding button for 3000 ms, reset settings, code not ideaa for production
			delay(3000); // reset delay hold
			if( digitalRead(TRIGGER_PIN) == LOW ){
				Serial.println("Button Held");
				Serial.println("Erasing Config, restarting");
				wm.resetSettings();
				ESP.restart();
			}
			
			// start portal w delay
			Serial.println("Starting config portal");
			wm.setConfigPortalTimeout(120);
			
			if (!wm.startConfigPortal("OnDemandAP","password")) {
				Serial.println("Failed to connect or hit timeout");
				delay(3000);
				// ESP.restart();
			} else {
				//if you get here you have connected to the WiFi
				Serial.println("Connected)");
			}
		}
	}
}

String getParam(String name){
	//read parameter from server, for customhmtl input
	String value;
	if(wm.server->hasArg(name)) {
		value = wm.server->arg(name);
	}
	return value;
}

void saveParamCallback(){
	Serial.println("[CALLBACK] saveParamCallback fired");
	Serial.println("PARAM customfieldid = " + getParam("customfieldid"));
}

void digitalClockDisplay() {
	// digital clock display of the time
	Serial.print(hour());
	printDigits(minute());
	printDigits(second());
	Serial.print(" ");
	Serial.print(day());
	Serial.print(".");
	Serial.print(month());
	Serial.print(".");
	Serial.println(year());
}

void printDigits(int digits) {
	// utility for digital clock display: prints preceding colon and leading 0
	Serial.print(":");
	if (digits < 10)
		Serial.print('0');
	Serial.print(digits);
}

	//------------------------------------ NTP code ---------------------------------//

time_t getNtpTime() {
	IPAddress ntpServerIP; // NTP server's ip address

	while (Udp.parsePacket() > 0) ; // discard any previously received packets
	Serial.println("Transmit NTP Request");
	// get a random server from the pool
	WiFi.hostByName(ntpServerName, ntpServerIP);
	Serial.print(ntpServerName);
	Serial.print(": ");
	Serial.println(ntpServerIP);
	sendNTPpacket(ntpServerIP);
	uint32_t beginWait = millis();
	while (millis() - beginWait < 1500) {
		int size = Udp.parsePacket();
		if (size >= NTP_PACKET_SIZE) {
			Serial.println("Receive NTP Response");
			Udp.read(packetBuffer, NTP_PACKET_SIZE);  // read packet into the buffer
			unsigned long secsSince1900;
			// convert four bytes starting at location 40 to a long integer
			secsSince1900 =  (unsigned long)packetBuffer[40] << 24;
			secsSince1900 |= (unsigned long)packetBuffer[41] << 16;
			secsSince1900 |= (unsigned long)packetBuffer[42] << 8;
			secsSince1900 |= (unsigned long)packetBuffer[43];
			return secsSince1900 - 2208988800UL + timeZone * SECS_PER_HOUR;
		}
	}
	Serial.println("No NTP Response Restarting");
	ESP.restart();
}

void sendNTPpacket(IPAddress &address) {
	// set all bytes in the buffer to 0
	memset(packetBuffer, 0, NTP_PACKET_SIZE);
	// Initialize values needed to form NTP request
	// (see URL above for details on the packets)
	packetBuffer[0] = 0b11100011;   // LI, Version, Mode
	packetBuffer[1] = 0;     // Stratum, or type of clock
	packetBuffer[2] = 6;     // Polling Interval
	packetBuffer[3] = 0xEC;  // Peer Clock Precision
	// 8 bytes of zero for Root Delay & Root Dispersion
	packetBuffer[12] = 49;
	packetBuffer[13] = 0x4E;
	packetBuffer[14] = 49;
	packetBuffer[15] = 52;
	// all NTP fields have been given values, now
	// you can send a packet requesting a timestamp:
	Udp.beginPacket(address, 123); //NTP requests are to port 123
	Udp.write(packetBuffer, NTP_PACKET_SIZE);
	Udp.endPacket();
}

void nixie() {
	// --------------------------------------- FUNCAO PARA GERAÇÃO DO FLASH  ------------------

	// SIMULAÇÃO VIA SERIAL OPERACIONAL VERIFICAR EM MODELO REAL ------------------------------ 
	//Serial.println(lowerHours);

  lowerHours = (hour() % 10);
  upperHours = (hour() / 10);
  lowerMins = ((minute() % 10));
	upperMins = (minute() / 10);

	lowerSeconds = (second() % 10);
	upperSeconds = (second() / 10);

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
	delay(updateNixie);
	digitalWrite(anodPin, LOW);
}

void effectNixieSelected () {
	
	if (effectModeNixie == 1) {
		if (compareTimeMins != lowerMins) {
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
					compareTimeMins = lowerMins;
				}
			}
		}
	}
	if (effectModeNixie == 2) {
		if (compareTimeMins != lowerMins) {
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
					compareTimeMins = lowerMins;
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

byte format_hour(byte hr){
	if(hr > 12){
		hr-= 12;
	}
	if(hr == 0){
		hr = 12;
	}
	return hr;
}