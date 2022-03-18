// Arduinix 6 Bulb - Also supports Hour and Min. time set.
// 
// This code runs a six bulb setup and displays a prototype clock setup.
// NOTE: the delay is setup for IN-17 nixie bulbs.
//
// original code by Jeremy Howa
// www.robotpirate.com
// www.arduinix.com
// 2008 - 2009
// code modified by Andrea Biffi www.andreabiffi.com to work with only one SN74141
//
// Last Edit Nov 2013
//

// SN74141 : True Table
//D C B A #
//L,L,L,L 0
//L,L,L,H 1
//L,L,H,L 2
//L,L,H,H 3
//L,H,L,L 4
//L,H,L,H 5
//L,H,H,L 6
//L,H,H,H 7
//H,L,L,L 8
//H,L,L,H 9

#define DEBUG_ON   false

// SN74141
int ledPin_0_a = 2;                
int ledPin_0_b = 3;
int ledPin_0_c = 4;
int ledPin_0_d = 5;
             
// anod pins
int ledPin_a_5 = 8;
int ledPin_a_6 = 9;

int ledPin_a_1 = 10;   
int ledPin_a_2 = 11;  
int ledPin_a_3 = 12;   
int ledPin_a_4 = 13;    

void setup() 
{
  pinMode(ledPin_0_a, OUTPUT);      
  pinMode(ledPin_0_b, OUTPUT);      
  pinMode(ledPin_0_c, OUTPUT);      
  pinMode(ledPin_0_d, OUTPUT);    
  
  pinMode(ledPin_a_1, OUTPUT);      
  pinMode(ledPin_a_2, OUTPUT);      
  pinMode(ledPin_a_3, OUTPUT); 
  pinMode(ledPin_a_4, OUTPUT);    
  pinMode(ledPin_a_5, OUTPUT);      
  pinMode(ledPin_a_6, OUTPUT);  
 
  // NOTE:
  // Grounding on pins analog0 and analog input 1 will set the Hour and Mins.
  pinMode(A0, INPUT ); // set the virtual pin analog0 (pin 0 on the analog inputs ) 
  digitalWrite(A0, HIGH); // set pin analog input 0 as a pull up resistor.

  pinMode(A1, INPUT ); // set the virtual pin analog input 1 (pin 1 on the analog inputs ) 
  digitalWrite(A1, HIGH); // set pin analog input 1 as a pull up resistor.
  
  if( DEBUG_ON )
  {
    Serial.begin(9600);
  }
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
void DisplayNumberSet( int anod, int num1)
{
  int anodPin;
  int a,b,c,d;
  
  // set defaults.
  a=0;b=0;c=0;d=0; // will display a zero.
  anodPin =  ledPin_a_1;     // default on first anod.
  
  // Select what anod to fire.
  switch( anod )
  {
    case 0:    anodPin =  ledPin_a_1;    break;
    case 1:    anodPin =  ledPin_a_2;    break;
    case 2:    anodPin =  ledPin_a_3;    break;
    case 3:    anodPin =  ledPin_a_4;    break;
    case 4:    anodPin =  ledPin_a_5;    break;
    case 5:    anodPin =  ledPin_a_6;    break;
  }  
  
  // Load the a,b,c,d to send to the SN74141 IC (1)
  switch( num1 )
  {
    case 0: a=0;b=0;c=0;d=0;break;
    case 1: a=1;b=0;c=0;d=0;break;
    case 2: a=0;b=1;c=0;d=0;break;
    case 3: a=1;b=1;c=0;d=0;break;
    case 4: a=0;b=0;c=1;d=0;break;
    case 5: a=1;b=0;c=1;d=0;break;
    case 6: a=0;b=1;c=1;d=0;break;
    case 7: a=1;b=1;c=1;d=0;break;
    case 8: a=0;b=0;c=0;d=1;break;
    case 9: a=1;b=0;c=0;d=1;break;
  }  
  
  // Write to output pins.
  digitalWrite(ledPin_0_d, d);
  digitalWrite(ledPin_0_c, c);
  digitalWrite(ledPin_0_b, b);
  digitalWrite(ledPin_0_a, a);

  // Turn on this anod.
  digitalWrite(anodPin, HIGH);   

  // Delay
  // NOTE: With the difference in Nixie bulbs you may have to change
  //       this delay to set the update speed of the bulbs. If you 
  //       dont wait long enough the bulb will be dim or not light at all
  //       you want to set this delay just right so that you have 
  //       nice bright output yet quick enough so that you can multiplex with
  //       more bulbs (2ms is standard).
  delay(6);
  
  // Shut off this anod.
  digitalWrite(anodPin, LOW);
}

////////////////////////////////////////////////////////////////////////
//
// DisplayNumberString
// Use: passing an array that is 6 elements long will display numbers
//      on a 6 nixie bulb setup.
//
////////////////////////////////////////////////////////////////////////
void DisplayNumberString( int* array )
{
  // bank 1 (bulb 1)
  DisplayNumberSet(0,array[0]);   
  // bank 2 (bulb 2)
  DisplayNumberSet(1,array[1]);   
  // bank 3 (bulb 3)
  DisplayNumberSet(2,array[2]);   
  // bank 4 (bulb 4)
  DisplayNumberSet(3,array[3]);   
  // bank 5 (bulb 5)
  DisplayNumberSet(4,array[4]);   
  // bank 6 (bulb 6)
  DisplayNumberSet(5,array[5]);   
}

// Defines
long MINS = 60;         // 60 Seconds in a Min.
long HOURS = 60 * MINS; // 60 Mins in an hour.
long DAYS = 24 * HOURS; // 24 Hours in a day. > Note: change the 24 to a 12 for non millitary time.

long runTime = 0;       // Time from when we started.

// default time sets. clock will start at 12:59:00
// NOTE: We start seconds at 0 so we dont need a clock set
//       The values you see here would be what you change 
//       if you added a set clock inputs to the board.
long clockHourSet = 22;
long clockMinSet  = 02;

int HourButtonPressed = false;
int MinButtonPressed = false;

////////////////////////////////////////////////////////////////////////
//
//
////////////////////////////////////////////////////////////////////////
void loop()     
{
  // Get milliseconds.
  runTime = millis();

  // Get time in seconds.
  long time = (runTime) / 1000; ///change this value to speed up or slow down the clock, set to smaller number such as 10, 1, or 100 for debugging
  
  int hourInput = digitalRead(14);  
  int minInput  = digitalRead(15);
  
  if( DEBUG_ON )
    Serial.println( hourInput );       
  
  if( hourInput == 0 )
    HourButtonPressed = true;
  if( minInput == 0 )
    MinButtonPressed = true;
  
  if( HourButtonPressed == true && hourInput == 1 )
  {
    clockHourSet++;
    HourButtonPressed = false;
  }
  
  if( MinButtonPressed == true && minInput == 1 )
  {
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
  if( upperSeconds >= 10 )   upperSeconds = upperSeconds / 10;
  if( upperMins >= 10 )      upperMins = upperMins / 10;
  if( upperHours >= 10 )     upperHours = upperHours / 10;

  // Fill in the Number array used to display on the tubes.
  int NumberArray[6]= {0,0,0,0,0,0};
  NumberArray[0] = upperHours;
  NumberArray[1] = lowerHours;
  NumberArray[2] = upperMins;
  NumberArray[3] = lowerMins;
  NumberArray[4] = upperSeconds;
  NumberArray[5] = lowerSeconds;

  // Display.
  DisplayNumberString( NumberArray );
}






/*

// Arduinix 6 Bulb - Also supports Hour and Min. time set.
// 
// This code runs a six bulb setup and displays a prototype clock setup.
// NOTE: the delay is setup for IN-17 nixie bulbs.
//
// original code by Jeremy Howa
// www.robotpirate.com
// www.arduinix.com
// 2008 - 2009
// code modified by Andrea Biffi www.andreabiffi.com to work with only one SN74141
//
// Last Edit Nov 2013
//

// SN74141 : True Table
//D C B A #
//L,L,L,L 0
//L,L,L,H 1
//L,L,H,L 2
//L,L,H,H 3
//L,H,L,L 4
//L,H,L,H 5
//L,H,H,L 6
//L,H,H,H 7
//H,L,L,L 8
//H,L,L,H 9

// SN74141
int ledPin_0_a = 2;                
int ledPin_0_b = 3;
int ledPin_0_c = 4;
int ledPin_0_d = 5;
             
// anod pins
int ledPin_a_1 = 9;
int ledPin_a_2 = 10;
int ledPin_a_3 = 11;
int ledPin_a_4 = 12;

void setup() {
  Serial.begin(115200);
  Serial.println("TESTE");
  pinMode(ledPin_0_a, OUTPUT);      
  pinMode(ledPin_0_b, OUTPUT);      
  pinMode(ledPin_0_c, OUTPUT);      
  pinMode(ledPin_0_d, OUTPUT);    
  
  pinMode(ledPin_a_1, OUTPUT);      
  pinMode(ledPin_a_2, OUTPUT);      
  pinMode(ledPin_a_3, OUTPUT); 
  pinMode(ledPin_a_4, OUTPUT);    
 
  // NOTE:
  // Grounding on pins analog0 and analog input 1 will set the Hour and Mins.
  pinMode(A0, INPUT ); // set the virtual pin analog0 (pin 0 on the analog inputs ) 
  digitalWrite(A0, HIGH); // set pin analog input 0 as a pull up resistor.

  pinMode(A1, INPUT ); // set the virtual pin analog input 1 (pin 1 on the analog inputs ) 
  digitalWrite(A1, HIGH); // set pin analog input 1 as a pull up resistor.
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
void DisplayNumberSet( int anod, int num1)
{
  int anodPin;
  int a,b,c,d;
  
  // set defaults.
  a=0;b=0;c=0;d=0; // will display a zero.
  anodPin =  ledPin_a_1;     // default on first anod.
  
  // Select what anod to fire.
  switch( anod )
  {
    case 0:    anodPin =  ledPin_a_1;    break;
    case 1:    anodPin =  ledPin_a_2;    break;
    case 2:    anodPin =  ledPin_a_3;    break;
    case 3:    anodPin =  ledPin_a_4;    break;
  }  
  
  // Load the a,b,c,d to send to the SN74141 IC (1)
  switch( num1 ) {
    case 0: a=0;b=0;c=0;d=0;break;
    case 1: a=1;b=0;c=0;d=0;break;
    case 2: a=0;b=1;c=0;d=0;break;
    case 3: a=1;b=1;c=0;d=0;break;
    case 4: a=0;b=0;c=1;d=0;break;
    case 5: a=1;b=0;c=1;d=0;break;
    case 6: a=0;b=1;c=1;d=0;break;
    case 7: a=1;b=1;c=1;d=0;break;
    case 8: a=0;b=0;c=0;d=1;break;
    case 9: a=1;b=0;c=0;d=1;break;
  }  
  
  // Write to output pins.
  digitalWrite(ledPin_0_d, d);
  digitalWrite(ledPin_0_c, c);
  digitalWrite(ledPin_0_b, b);
  digitalWrite(ledPin_0_a, a);

  // Turn on this anod.
  digitalWrite(anodPin, HIGH);   

  // Delay
  // NOTE: With the difference in Nixie bulbs you may have to change
  //       this delay to set the update speed of the bulbs. If you 
  //       dont wait long enough the bulb will be dim or not light at all
  //       you want to set this delay just right so that you have 
  //       nice bright output yet quick enough so that you can multiplex with
  //       more bulbs (2ms is standard).
  delay(6.5);
  
  // Shut off this anod.
  digitalWrite(anodPin, LOW);
}

////////////////////////////////////////////////////////////////////////
//
// DisplayNumberString
// Use: passing an array that is 6 elements long will display numbers
//      on a 6 nixie bulb setup.
//
////////////////////////////////////////////////////////////////////////
void DisplayNumberString( int* array )
{
  // bank 1 (bulb 1)
  DisplayNumberSet(0,array[0]);   
  // bank 2 (bulb 2)
  DisplayNumberSet(1,array[1]);   
  // bank 3 (bulb 3)
  DisplayNumberSet(2,array[2]);   
  // bank 4 (bulb 4)
  DisplayNumberSet(3,array[3]);    
}

// Defines
long MINS = 60;         // 60 Seconds in a Min.
long HOURS = 60 * MINS; // 60 Mins in an hour.
long DAYS = 24 * HOURS; // 24 Hours in a day. > Note: change the 24 to a 12 for non millitary time.

long runTime = 0;       // Time from when we started.

// default time sets. clock will start at 12:59:00
// NOTE: We start seconds at 0 so we dont need a clock set
//       The values you see here would be what you change 
//       if you added a set clock inputs to the board.
long clockHourSet = 01;
long clockMinSet  = 01;

int HourButtonPressed = false;
int MinButtonPressed = false;

////////////////////////////////////////////////////////////////////////
//
//
////////////////////////////////////////////////////////////////////////
void loop() {
  // Get milliseconds.
  runTime = millis();

  // Get time in seconds.
  long time = (runTime) / 10; ///change this value to speed up or slow down the clock, set to smaller number such as 10, 1, or 100 for debugging
  
  int hourInput = digitalRead(14);  
  int minInput  = digitalRead(15);      
  
  if( hourInput == 0 )
    HourButtonPressed = true;
  if( minInput == 0 )
    MinButtonPressed = true;
  
  if( HourButtonPressed == true && hourInput == 1 )
  {
    clockHourSet++;
    HourButtonPressed = false;
  }
  
  if( MinButtonPressed == true && minInput == 1 )
  {
    clockMinSet++;
    MinButtonPressed = false;
  }
  
  // Set time based on offset..
  long hbump = 60*60*clockHourSet;
  long mbump = 60*clockMinSet;
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
  if( upperSeconds >= 10 )   upperSeconds = upperSeconds / 10;
  if( upperMins >= 10 )      upperMins = upperMins / 10;
  if( upperHours >= 10 )     upperHours = upperHours / 10;

  // Fill in the Number array used to display on the tubes.
  int NumberArray[4]={0,0,0,0};

  int saveSeconds;
  
  NumberArray[0] = upperHours;
  NumberArray[1] = lowerHours;
  NumberArray[2] = upperMins;
  NumberArray[3] = lowerMins;

  if (upperMins != saveSeconds) {
    Serial.print(NumberArray[0]);
    Serial.print(NumberArray[1]," : ");
    Serial.print(NumberArray[2]);
    Serial.println(NumberArray[3]);
    saveSeconds = upperMins;
  }
  // Display.
  DisplayNumberString( NumberArray );
}

*/
