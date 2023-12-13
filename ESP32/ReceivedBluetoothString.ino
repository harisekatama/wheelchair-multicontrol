#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_B300"); // Bluetooth device name
}

void loop() {
  if (SerialBT.available()) {
    char receivedData = SerialBT.read();
    Serial.print("Arah : ");
    Serial.println(receivedData);
  }
}
