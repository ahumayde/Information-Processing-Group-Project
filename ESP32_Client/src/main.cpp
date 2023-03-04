#include <Arduino.h>
#include "passwords.h"
#include "WiFi.h"
#include <string>

WiFiClient client;

const char *ssid = WIFI_SSID;
const char *password = WIFI_PASSWORD;
const char *host = "172.20.10.7";
const int port = 10000;

void connectToNetwork() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("Establishing connection to WiFi..");
    delay(1000);
  }
  Serial.println("Connected to network");
}

void sendMessageToTCPServer(String input) {

  // std::string x = std::to_string(random(-255,255));
  // std::string y = std::to_string(random(-255,255));
  // std::string z = std::to_string(random(-255,255));

  // String x = String(random(-255,255));
  // String y = String(random(-255,255));
  // String b = String(random(0,4));
  // String msg = ","+x+","+y+","+b;

  String msg;
  if (input == "right") {
    msg = ",0,0,1";
  } else if (input == "left") {
    msg = ",0,0,2";
  } else if (input == "drop") {
    msg = ",0,255,0";
  } else if (input == "store") {
    msg = ",0,-255,0";
  } else {
    msg = ",0,0,0";
  }
  Serial.print("msg: ");
  Serial.println(msg);
  client.print(msg);
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
  String input = "drop";
  sendMessageToTCPServer(input);
  delay(1000);
}