/**
 * Código para o dispositivo escravo receber dados do mestre.
 * 
 * SLAVE: ARDUINO NANO ATMEGA328P
 * 
 * Autor: Nicholas Zambetti
 * Adaptações: Ana Paula Messina - tecdicas
 * 
 * 30/01/2019
 * 
 */

#include <SoftwareSerial.h>

SoftwareSerial mySerial(3, 1); // RX, TX

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  delay(2000);  
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Native USB only
  }


  Serial.println("Goodnight moon!");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(38400);
  mySerial.println("Hello, world?");
}

void loop() // run over and over
{
  if (mySerial.available())
    Serial.write(mySerial.read());
  if (Serial.available())
    mySerial.write(Serial.read());
}