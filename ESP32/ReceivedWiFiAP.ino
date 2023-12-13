#include <WiFi.h>
#include <Arduino.h>

const char* ssid = "B300-Access-Point";
const char* password = "123456789";

WiFiServer server(80);

void setup(){
  Serial.begin(115200);
  Serial.print("Setting AP (Access Point)…");
  WiFi.softAP(ssid, password);
 
  IPAddress IP = WiFi.softAPIP();
  Serial.print("ESP32 AP IP Address : ");
  Serial.println(IP);

  server.begin();
}

void loop(){
  WiFiClient client = server.available();

  if (client) {
    while (client.connected()) {
      if (client.available()) {
        char receivedData = client.read();
        Serial.print("Arah : ");
        Serial.println(receivedData);
      }
    }
    client.stop();
  }
}
