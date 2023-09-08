// LEDFunctions.h

// Define LED pins
const int ledPins[] = {A0, A1, A2, A3, A4};
const int numLEDs = 5;

// Function to initialize LED setup
void setupLEDFunctions() {
  for (int i = 0; i < numLEDs; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], HIGH); // Turn off LEDs initially
  }
}

// Function to toggle the state of an LED
void toggleLEDState(int ledIndex) {
  digitalWrite(ledPins[ledIndex], !digitalRead(ledPins[ledIndex]));
}

// Function to turn on an LED
void turnOnLED(int ledIndex) {
  digitalWrite(ledPins[ledIndex], LOW);
}

// Function to turn off an LED
void turnOffLED(int ledIndex) {
  digitalWrite(ledPins[ledIndex], HIGH);
}
