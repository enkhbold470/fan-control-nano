// SerialFunctions.h

// Include necessary libraries
#include <SoftwareSerial.h>

// Define SoftwareSerial object
SoftwareSerial mySerial(7, 8); // RX, TX pins for SoftwareSerial

// Function to initialize serial communication
void setupSerialFunctions() {
  mySerial.begin(9600); // Set the baud rate to match your requirements
  Serial.println("Serial communication initialized");
}

// Function to process serial input
void processSerialInput() {
  while (mySerial.available()) {
    char serialChar = mySerial.read();
    
    // Toggle LEDs based on received commands
    switch (serialChar) {
      case 'FS':
        toggleLED(1);
        break;
      case 'MS':
        toggleLED(2);
        break;
      case 'LS':
        toggleLED(3);
        break;
      case 'RF':
        toggleLED(4);
        break;
      case 'IO':
        toggleLED(5);
        break;
      default:
        // Handle unknown commands or characters here
        break;
    }
  }
}

// Function to send data over serial communication
void sendDataOverSerial(String data) {
  mySerial.println(data);
}
