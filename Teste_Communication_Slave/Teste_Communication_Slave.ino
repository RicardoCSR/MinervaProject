// Include the required Wire library for I2C<br>#include <Wire.h>
#include <Wire.h>
#include <SPI.h>   

int LED = PC13;
String x;
void setup() {
  Serial.begin(115200);
  // Define the LED pin as Output

  Serial.println("STM32 Inicializado");
  pinMode (LED, OUTPUT);
  // Start the I2C Bus as Slave on address 9
  Wire.begin(9); 
  // Attach a function to trigger when something is received.
}

void receiveEvent(int howMany) {
  x = Wire.read();
  Serial.println("Dado Enviado");
}

void loop() {

  Serial.println("STM32 Inicializado");
}
