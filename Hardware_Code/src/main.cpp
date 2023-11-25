#include <Arduino.h>


// grey => ground
// black => ground
// red => 3.3 v
// yellow => tx
// blue => rx

// // put function declarations here:
// int myFunction(int, int);

char Incoming_value = 0; // Variable for storing Incoming_value from serial
int tazerPin = 8;

void setup() {
//   int result = myFunction(2, 3);

  Serial.begin(9600);  // Sets the data rate in bits per second (baud) for serial data transmission
  pinMode(tazerPin, OUTPUT); // Sets digital pin 13 as output pin
}

void loop() {

  if (Serial.available() > 0)
  {
    Incoming_value = Serial.read(); // Read the incoming data and store it into variable Incoming_value
    Serial.print(Incoming_value);   // Print Value of Incoming_value in Serial monitor
    Serial.print("\n");             // New line
    if (Incoming_value == 'E')
      digitalWrite(tazerPin, HIGH);
	  delay(70);
      digitalWrite(tazerPin, LOW);
  }
}

// put function definitions here:
// int myFunction(int x, int y) {
//   return x + y;
// }