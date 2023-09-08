const int ledPins[] = {A0, A1, A2, A3, A4}; // Pins for the LEDs
const int buttonPins[] = {2, 3, 4, 5, 6};  // Pins for the buttons
const int numButtons = 5;                  // Number of buttons
int buttonState[numButtons] = {LOW};       // Stores the current state of the buttons
int lastButtonState[numButtons] = {LOW};   // Stores the previous state of the buttons
int buttonPushCounter[numButtons] = {0};   // Counter for the number of button presses

void setup() {
  Serial.begin(9600);
  Serial.println("ON UART");

  for (int i = 0; i < numButtons; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP); // Set buttons as input with pull-up resistors
    pinMode(ledPins[i], OUTPUT);          // Set LEDs as output
    digitalWrite(ledPins[i], HIGH);
  }

  Serial.println("Each LED is initially turned off.");
}

void loop() {
  for (int i = 0; i < numButtons; i++) {
    buttonState[i] = digitalRead(buttonPins[i]);
    checkButton(i);
    toggleLED(i);
  }
}

void checkButton(int buttonIndex) {
  if (buttonState[buttonIndex] != lastButtonState[buttonIndex]) {
    if (buttonState[buttonIndex] == LOW) {
      buttonPushCounter[buttonIndex]++;
      
      // Print custom labels based on the button pressed
      switch (buttonIndex + 1) {
        case 1:
          Serial.print("Button 1 (FS) pushed: ");
          Serial.println(buttonPushCounter[buttonIndex] % 2 == 0 ? "OFF" : "ON"); // Fast Speed
          // Toggle the LED state for Button 1
          toggleLED(buttonIndex);
          break;
        case 2:
          Serial.print("Button 2 (MS) pushed: ");
          Serial.println(buttonPushCounter[buttonIndex] % 2 == 0 ? "OFF" : "ON"); // Medium Speed
          break;
        case 3:
          Serial.print("Button 3 (LS) pushed: ");
          Serial.println(buttonPushCounter[buttonIndex] % 2 == 0 ? "OFF" : "ON"); // Low Speed
          break;
        case 4:
          Serial.print("Button 4 (RF) pushed: ");
          Serial.println(buttonPushCounter[buttonIndex] % 2 == 0 ? "OFF" : "ON"); // Rotate Fan
          break;
        case 5:
          Serial.print("Button 5 (IO) pushed: ");
          Serial.println(buttonPushCounter[buttonIndex] % 2 == 0 ? "OFF" : "ON"); // Ion
          break;
        default:
          Serial.println("Unknown Button");
          break;
      }
    }
    delay(50); // Debounce delay
  }
  lastButtonState[buttonIndex] = buttonState[buttonIndex];
}

void toggleLED(int ledIndex) {
  if (buttonPushCounter[ledIndex] % 2 == 0) {
    digitalWrite(ledPins[ledIndex], HIGH);
  } else {
    digitalWrite(ledPins[ledIndex], LOW);
  }
}
