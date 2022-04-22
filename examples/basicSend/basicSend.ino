#include <ESP8266WiFi.h>
#include "easyNarodMon.h";

<<<<<<< Updated upstream
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
=======
#define WiFiSSID "Mywifi"//define your wifi info here
#define WiFiPASS "12345678"
#define deviceId "mydeviceid" //id of device, sometimes mac adress is being used
#define sensor1Id "123456asdf"//ids of your sensors here. If you have a lot of them you may change this define to something else
#define sensor2Id "7890zxcvvb"
NarodMonSender mySender;//create an object of sender
void setup() {
  mySender.enableDebug();//allow debugging (it is blocked by default)
  Serial.begin(115200);
  mySender.connectWiFi(WiFiSSID,WiFiPASS);//the library has an option of connecting wifi. It does it in the same way as ESP connects in basic examples from arduino ide.
>>>>>>> Stashed changes
}
void loop() {
<<<<<<< Updated upstream
  //set head starts a new request and enters there device id
  mySender.setHead("device-id");
  //add sensor to your request, first param is value, second is id of sensor
  mySender.addSensor(30, "sensor1-id");
  mySender.addSensor(23.5, "sensor2-id");
=======
  //start a new request. Put device id into header
  mySender.setHead(deviceId);
  //add some sensors. Check readme to find out more about this code.
  mySender.addSensor(30, sensor1Id);
  mySender.addSensor(23.5, sensor2Id);
  //and only now your esp is connecting server and sends request. So you may be creating a request for a long time, but it will any way be sent without delays.
>>>>>>> Stashed changes
  mySender.sendData();
  delay(300000); // execute once every 5 minutes, don't flood remote service
}