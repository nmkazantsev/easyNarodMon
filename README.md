# easyNarodMon
A library for esp8266 boards for easy communicating with https://narodmon.ru/

The author is always glad to see contributors here, offer your ideas and pull requests! 

Please, write me about any features you would like to see in this library! 

Use standart procedure for installation: download zip-package and add .zip library in you Arduino IDE. Please, do not forget to check out an example.

Short description:

void connectWifi(const char* ssid, const char* pass);
connect wifi like a usual esp example, just to clean up yuor code

void setHead(String deviceId);
Starts a Stirng with request to server. Adds there headers and inserts there device id (usually mac address of device is being used)

void setHead(String device Id, String name, String lat, String lon, String alt) ;
Allows to also add Device name and coordinates of it from GPS

void addSensor(String value, String sensorId) ;
void addSensor(float value, String sensorId) ;
void addSensor(int value, String sensorId) ;
add a sensor to the request string. Please, call it only after addHead
Also these functions are declared with additional String param: sensor name. 

String sendData();
Sends the generated requests, returns the answers from server or "connection error" if it happened

void enableDebug();
allows library to print debug info to Serial

void disableDebug();
forbids the library to print debug info. By default debug is disables
