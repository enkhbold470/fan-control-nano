#include <SoftwareSerial.h>
const int rxPin = 2;  // RX pin for software serial
const int txPin = 3;  // TX pin for software serial
SoftwareSerial mySerial(rxPin, txPin);

const int buttonPins[] = {A1, A2, A3, A4, A5}; // Pins for the buttons
const int ledPins[] = {7, 8, 9, 10, 11};  // Pins for the LEDs
const int numButtons = 5;                 // Number of buttons

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  Serial.println("ON UART");
  
  for (int i = 0; i < numButtons; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP); // Set buttons as input with pull-up resistors
    pinMode(ledPins[i], OUTPUT);          // Set LEDs as output
    digitalWrite(ledPins[i], LOW);
  };
  Serial.println("Each leds are low");
  

}

void loop() {
receiveData();


}
int ledConBut(){
    for (int i = 0; i < numButtons; i++) {
    if (digitalRead(buttonPins[i]) == LOW) {
      // Button is pressed, turn on the corresponding LED
      digitalWrite(ledPins[i], HIGH);
      Serial.println(i, "ON");
    } else {
      // Button is not pressed, turn off the corresponding LED
      digitalWrite(ledPins[i], LOW);
    }
  }
  delay(1000);
}

int receiveData(){
    if (mySerial.available()) {
    char character = mySerial.read();
    Serial.println(character);
  }
}
