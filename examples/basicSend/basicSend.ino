
#include <ESP8266WiFi.h>
#include "easyNarodMon.h";

#ifndef STASSID
#define STASSID "your-ssid"
#define STAPSK  "your-passs"
#endif

const char* ssid     = STASSID;
const char* password = STAPSK;
NarodMonSender mySender;
void setup() {
  mySender.enableDebug();
  Serial.begin(115200);
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  mySender.setHead("device-id");
  mySender.addSensor(30, "sensor1-id");
  mySender.addSensor(23.5, "sensor2-id");
  mySender.sendData();
  delay(300000); // execute once every 5 minutes, don't flood remote service
}