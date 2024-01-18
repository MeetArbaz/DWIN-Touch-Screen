void btn() {
  if (dwinSerial.available() > 0) {
    int b = 0;
    while (dwinSerial.available() > 0) {
      char incomingByte = dwinSerial.read();
      delay(2);
      incomingData[b] = incomingByte;
      b++;
    }

    // Check if the received data is from the specified VP address (1300)
    if (incomingData[4] == (byte)0x13) {
      int k = 7;
      while (incomingData[k] == 0x01) {
        Serial.write(incomingData[k]);
        k++;
      }
      Serial.println("it works"); // Print a new line for better readability
      memset(incomingData, 0, sizeof(incomingData));
    }
    Serial.println(""); // Print an extra new line for better readability
  }
}
