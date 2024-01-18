void fetchData() {
  if (dwinSerial.available() > 0) {
    int a = 0;
    while (dwinSerial.available() > 0) {
      char incomingByte = dwinSerial.read();
      delay(2);
      incomingData[a] = incomingByte;
      a++;
    }

    // Check if the received data is from the specified VP address (1200)
    if (incomingData[3] == (byte)0x83 && incomingData[4] == (byte)0x12) {
      int k = 7;
      while (incomingData[k] != 0xFF) {
        Serial.write(incomingData[k]);
        k++;
      }
      Serial.println(); // Print a new line for better readability
      memset(incomingData, 0, sizeof(incomingData));
    }
    Serial.println(""); // Print an extra new line for better readability
  }
}
