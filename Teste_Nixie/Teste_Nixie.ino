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

// ------------------------------------------------------ COMANDO NIXIE DRIVER ------------------------- (EM ANALISE)
// Pinos ligado ao Nixie Driver:

int ledPin_0_a = 2;    
int ledPin_0_b = 3;
int ledPin_0_c = 4;
int ledPin_0_d = 5;
             
// Pinos Anodo (Incluir caso houver)
int ledPin_a_1 = 9;
int ledPin_a_2 = 10;
int ledPin_a_3 = 11;
int ledPin_a_4 = 12;

void setup() {
  Serial.begin(115200);
  Serial.println("TESTE");    // VERIFICACAO DE COMUNICAR
  pinMode(ledPin_0_a, OUTPUT);      
  pinMode(ledPin_0_b, OUTPUT);      
  pinMode(ledPin_0_c, OUTPUT);      
  pinMode(ledPin_0_d, OUTPUT);    
  
  pinMode(ledPin_a_1, OUTPUT);      
  pinMode(ledPin_a_2, OUTPUT);      
  pinMode(ledPin_a_3, OUTPUT); 
  pinMode(ledPin_a_4, OUTPUT);    
 
  // NOTE:
  // Aterrano o pino Analog0 (A0) e Analog1 (A1) serão para ajustar Hora e Minutos (REMOVER, POSSIVEL UTILIZAR)
  pinMode(A0, INPUT ); 
  digitalWrite(A0, HIGH);

  pinMode(A1, INPUT );  
  digitalWrite(A1, HIGH);
}


// REMOVER UTILIZAR O DEFINIDO NO PROGRAMA ORIGINAL
// Defines
long MINS = 60;         // 60 Seconds in a Min.
long HOURS = 60 * MINS; // 60 Mins in an hour.
long DAYS = 24 * HOURS; // 24 Hours in a day. > Note: change the 24 to a 12 for non millitary time.

long runTime = 0;       // Time from when we started.

// default time sets. clock will start at 12:59:00
// NOTE: We start seconds at 0 so we dont need a clock set
//       The values you see here would be what you change 
//       if you added a set clock inputs to the board.
long clockHourSet = 00;
long clockMinSet  = 00;

int HourButtonPressed = false;
int MinButtonPressed = false;

////////////////////////////////////////////////////////////////////////
//
//
////////////////////////////////////////////////////////////////////////

void loop() {

  nixie();
}

void nixie() {
  // REMOVER UTILIZAR O DEFINIDO NO PROGRAMA ORIGINAL
  // Get milliseconds.
  runTime = millis();
  // Get time in seconds.
  long time = (runTime) / 100; ///change this value to speed up or slow down the clock, set to smaller number such as 10, 1, or 100 for debugging
  


  int hourInput = digitalRead(14);  
  int minInput  = digitalRead(15);      
  
  if( hourInput == 0 )
    HourButtonPressed = true;
  if( minInput == 0 )
    MinButtonPressed = true;
  
  if( HourButtonPressed == true && hourInput == 1 ) {
    clockHourSet++;
    HourButtonPressed = false;
  }
  
  if( MinButtonPressed == true && minInput == 1 ) {
    clockMinSet++;
    MinButtonPressed = false;
  }
  
  // Set time based on offset..
  long hbump = 60 * 60 * clockHourSet;
  long mbump = 60 * clockMinSet;
  time += mbump + hbump;

  // Convert time to days,hours,mins,seconds
  long days  = time / DAYS;    time -= days  * DAYS; 
  long hours = time / HOURS;   time -= hours * HOURS; 
  long minutes  = time / MINS;    time -= minutes  * MINS; 
  long seconds  = time; 

  // Get the high and low order values for hours,min,seconds. 
  int lowerHours = hours % 10;
  int upperHours = hours - lowerHours;
  int lowerMins = minutes % 10;
  int upperMins = minutes - lowerMins;
  int lowerSeconds = seconds % 10;
  int upperSeconds = seconds - lowerSeconds;
  if( upperSeconds >= 10)   upperSeconds = upperSeconds / 10;
  if( upperMins >= 10)      upperMins = upperMins / 10;
  if( upperHours >= 10)     upperHours = upperHours / 10;


  // --------------------------------------- FUNCAO PARA GERAÇÃO DO FLASH  ------------------

  // SIMULAÇÃO VIA SERIAL OPERACIONAL VERIFICAR EM MODELO REAL ------------------------------  


  if (effectModeNixie == 1) {
    if (compareTimeMins != minutes) {
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
          DisplayNumberString(numberArray[nixieAnode]);
        }
        if (nixieCounts > 9) {
          nixieCounts = 0;
          numberArray[0] = upperHours; 
          numberArray[1] = lowerHours;
          numberArray[2] = upperMins;
          numberArray[3] = lowerMins;
          DisplayNumberString(numberArray[nixieAnode]);
          nixieAnode ++;
        } 
        if (nixieAnode == 4) {
          nixieAnode = 0;
          compareTimeMins = minutes;
        }
      }
    }
  }
  if (effectModeNixie == 2) {
    if (compareTimeMins != minutes) {
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
          DisplayNumberString(numberArray[nixieAnode]);
        }
        if (nixieCounts > 9) {
          nixieCounts = 0;
          numberArray[0] = upperHours; 
          numberArray[1] = lowerHours;
          numberArray[2] = upperMins;
          numberArray[3] = lowerMins;
          DisplayNumberString(numberArray[nixieAnode]);
          nixieAnode ++;
        } 
        if (nixieAnode == 4) {
          nixieAnode = 0;
          compareTimeMins = minutes;
        }
      }
    }
  } else {
    numberArray[0] = upperHours;
    numberArray[1] = lowerHours;
    numberArray[2] = upperMins;
    numberArray[3] = lowerMins;
  }

  // ---------------------------------------------------------------------------------------------------

  // ------------ AJUSTAR AS VARIAVEIS AO PROGRAMA PADRÃO -----------------------

  numberArray[0] = upperHours;
  numberArray[1] = lowerHours;
  numberArray[2] = upperMins;
  numberArray[3] = lowerMins;

  DisplayNumberString(numberArray);
}

void DisplayNumberString(int* array) {
  DisplayNumberSet(0,array[0]);   
  DisplayNumberSet(1,array[1]);   
  DisplayNumberSet(2,array[2]);   
  DisplayNumberSet(3,array[3]);    
}

////////////////////////////////////////////////////////////////////////
//
// DisplayNumberSet
// Use: Passing anod number, and number for bulb, this function
//      looks up the truth table and opens the correct outs from the arduino
//      to light the numbers given to this funciton.
//      On a 6 nixie bulb setup.
//
////////////////////////////////////////////////////////////////////////
void DisplayNumberSet(int anod, int num1) {
  
  int anodPin;
  int a, b, c, d;

    anodPin =  ledPin_a_1;   

    switch(anod) {
      case 0:    anodPin =  ledPin_a_1;    break;
      case 1:    anodPin =  ledPin_a_2;    break;
      case 2:    anodPin =  ledPin_a_3;    break;
      case 3:    anodPin =  ledPin_a_4;    break;
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

/*
  // ATUALIZA VISUALIZAÇÃO DOS NIXIES ????

  //unsigned long nixieAttTime = millis();

  if (millis() - nixieAttTime <= updateNixie * 1000) {
    nixieAttTime = millis();
    digitalWrite(anodPin, LOW);
    digitalWrite(ledPinTeste, LOW);
  } else {
    digitalWrite(anodPin, HIGH);
    digitalWrite(ledPinTeste, HIGH);
  }
*/

// ---------------------------------------------------------------------------



  // Turn on this anod.
  digitalWrite(anodPin, HIGH);   

  delay(updateNixie);
  
  // Shut off this anod.
  digitalWrite(anodPin, LOW);



}

