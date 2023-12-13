#include <ArduinoJson.h>
#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_B300");  // Set Bluetooth name
}

void loop() {
  if (SerialBT.available()) {
    // Read the data from Bluetooth
    String receivedData = SerialBT.readStringUntil('\n');

    // Parse JSON data
    StaticJsonDocument<200> doc;  // Adjust the size based on your JSON data
    DeserializationError error = deserializeJson(doc, receivedData);

    if (error) {
      Serial.print(F("JSON parsing failed: "));
      Serial.println(error.c_str());
      return;
    }

    // Access JSON data
    const char* arah = doc["arah"];
    Serial.print(F("Received Arah: "));
    Serial.println(arah);

    // Your code to handle the received JSON data

    // Clear the Serial buffer
    while (SerialBT.available()) {
      SerialBT.read();
    }
  }
}
