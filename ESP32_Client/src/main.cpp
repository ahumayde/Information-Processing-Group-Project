#include <Arduino.h>
#include "passwords.h"
#include "WiFi.h"
#include <string>

WiFiClient client;

const char *ssid = WIFI_SSID;
const char *password = WIFI_PASSWORD;
const char *host = "192.168.67.152";
const int port = 10000;

void connectToNetwork() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("Establishing connection to WiFi..");
    delay(1000);
  }
  Serial.println("Connected to network");
}

void sendMessageToTCPServer() {
  client.print("5");
  Serial.println("Sent TCP message to server");
}

void setup() {
  Serial.begin(115200);

  connectToNetwork();
  Serial.println(WiFi.macAddress());
  Serial.println(WiFi.localIP());

  while (!client.connect(host, port)) {
    Serial.println("connection failed");
  }
}

void loop() {
  sendMessageToTCPServer();
  delay(1000);
}