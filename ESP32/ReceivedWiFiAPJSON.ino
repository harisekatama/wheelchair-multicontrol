#include <WiFi.h>
#include <Arduino.h>
#include <ArduinoJson.h>

const char* ssid = "B300-Access-Point";
const char* password = "123456789";

WiFiServer server(80);

void setup(){
  Serial.begin(115200);


  // Connect to Wi-Fi network with SSID and password
  Serial.print("Setting AP (Access Point)…");
  // Remove the password parameter, if you want the AP (Access Point) to be open
  WiFi.softAP(ssid, password);
 
  IPAddress IP = WiFi.softAPIP();
  Serial.print("ESP32 AP IP Address : ");
  Serial.println(IP);

  // Start the server
  server.begin();
}

void loop(){
    // Check if a client has connected
  WiFiClient client = server.available();

  if (client) {
    //Serial.println("New client connected");
    
    // Read the data from the client
    while (client.connected()) {
      if (client.available()) {
    
        String receivedData = client.readStringUntil('\n');

        StaticJsonDocument<200> doc;
        DeserializationError error = deserializeJson(doc, receivedData);

        if(error){
          Serial.println("Failed to parse JSON");
        }
        else{
          const char* arah = doc["arah"];

          Serial.print("Received Arah : ");
          Serial.println(arah);
        }
      }
    }
    client.stop();
  }
}
