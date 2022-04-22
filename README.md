# easyNarodMon
A library for esp8266 boards for easy communicating with https://narodmon.ru/

Please, write me about any features you would like to see in this library! 

Use standart procedure for installation: download zip-package and add .zip library in you Arduino IDE. Please, do not forget to check out an example.

Short description:
void addHead(String deviceId);
Starts a Stirng with request to server. Adds there headers and inserts there device id (usually mac address of device is being used)

void addSensor(String value, String sensorId) ;
add a sensor to the request string. Please, call it only after addHead

String sendData();
Sends the generated requests, returns the answers from server or "connection error" if it happened

void enableDebug();
allows library to print debug info to Serial

void disableDebug();
forbids the library to print debug info. By default debug is disables
