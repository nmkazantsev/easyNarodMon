/*
 * An example how to get data from sht20 sensor and send to to server.
 * Do not forget to install DFRobot_SHT20.h library!
 */

#include <ESP8266WiFi.h>
#include "easyNarodMon.h";

//include librares for sht 20
//(how to use sht20 was copied from it's library's example)
#include <Wire.h>
#include "DFRobot_SHT20.h"
DFRobot_SHT20    sht20; //create sht 20

#define WiFiSSID "ssid"//define your wifi info here
#define WiFiPASS "pass"
#define deviceId "id0000" //id of device, sometimes mac adress is being used
#define sensor1Id "id1111"//ids of your sensors here. If you have a lot of them you may change this define to something else
#define sensor2Id "id2222"
NarodMonSender mySender;//create an object of sender
void setup() {
  mySender.enableDebug();//allow debugging (it is blocked by default)
  Serial.begin(115200);
  sht20.initSHT20();                                  // Init SHT20 Sensor
  delay(100);
  sht20.checkSHT20();
  mySender.connectWiFi(WiFiSSID, WiFiPASS); //the library has an option of connecting wifi. It does it in the same way as ESP connects in basic examples from arduino ide.
}
void loop() {
  //start a new request. Put device id into header
  mySender.setHead(deviceId);
  //add some sensors. Check readme to find out more about this code.
  mySender.addSensor(sht20.readHumidity(), sensor1Id);
  mySender.addSensor(sht20.readTemperature(), sensor2Id);
  //and only now your esp is connecting server and sends request. So you may be creating a request for a long time, but it will any way be sent without delays.
  mySender.sendData();
  delay(300000); // execute once every 5 minutes, don't flood remote service
}
