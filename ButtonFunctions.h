

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

