#include <SoftwareSerial.h>

// Define custom TX and RX pins for software serial communication with the DWIN display
#define DWIN_RX_PIN 8
#define DWIN_TX_PIN 9

SoftwareSerial dwinSerial(DWIN_RX_PIN, DWIN_TX_PIN);

void setup() {
  Serial.begin(9600);
  dwinSerial.begin(9600);

  Serial.println("Arduino program for switching DWIN display pages");
  switchDWINPage(0x1A); // Change the page address as needed
}

void loop() {

}

void switchDWINPage(byte pageAddress) {
  // Format the command to switch the DWIN display page
  byte command[] = {0x5A, 0xA5, 0x07, 0x82, 0x00, 0x84, 0x5A, 0x01, 0x00, pageAddress};

  // Send the command to DWIN display
  for (int i = 0; i < sizeof(command); i++) {
    dwinSerial.write(command[i]);
  }
  Serial.print("switch to page : ");
  Serial.println(pageAddress);

  // Optionally, you can add a delay to ensure the DWIN display processes the command
  delay(100);
}
