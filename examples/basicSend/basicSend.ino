
#include <ESP8266WiFi.h>
#include "easyNarodMon.h";

#ifndef STASSID
#define STASSID "your-ssid" //enret wifi said and pass here
#define STAPSK  "your-passs"
#endif

const char* ssid     = STASSID;
const char* password = STAPSK;
NarodMonSender mySender; //create a class of sender
void setup() {
  mySender.enableDebug(); //enable serial debugging (default is disabled) 
  Serial.begin(115200);
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
//usual connection
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
//add head starts a new request and enters there device id
  mySender.addHead("device-id");
//add sensor to your request, first param is value, second is id of sensor
  mySender.addSensor("30", "sensor1-id");
  mySender.addSensor("23", "sensor2-id");
  mySender.sendData();//send request 
  delay(300000); // execute once every 5 minutes, don't flood remote service
}
