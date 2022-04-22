#pragma once
#include <Arduino.h>
#include <ESP8266WiFi.h>
class NarodMonSender {
  public:
    void setHead(String deviceId);
    void setHead(String deviceId, String name, String lat, String lon, String alt) ;
    void addSensor(String value, String sensorId) ;
    void addSensor(double value, String sensorId) ;
    void addSensor(int value, String sensorId) ;
	void addSensor(String value, String sensorId, String name) ;
    void addSensor(double value, String sensorId, String name) ;
    void addSensor(int value, String sensorId, String name) ;
    
    String sendData();
    void enableDebug();
    void disableDebug();
  private:
    const char* host = "narodmon.ru";
    const uint16_t port = 8283;
    boolean debug = false;
    String text = "";
    WiFiClient client;
    void connectServer();
};
