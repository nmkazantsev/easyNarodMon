#pragma once
#include <Arduino.h>
#include <ESP8266WiFi.h>
class NarodMonSender {
  public:
    void setHead(String deviceId);
    void setHead(String device Id, String name, String lat, String lon, String alt) ;
    void addSensor(String value, String sensorId) ;
    void addSensor(float value, String sensorId) ;
    void addSensor(int value, String sensorId) ;
void addSensor(String value, String sensorId, String name) ;
    void addSensor(float value, String sensorId, String name) ;
    void addSensor(int value, String sensorId, String name) ;
    
    String sendData();
    void enableDebug();
    void disableDebug();
  private:
    const char* host = "narodmon.ru";
    const uint16_t port = 8283;
    boolean serverConnected = false;
    boolean debug = false;
    String text = "";
    WiFiClient client;
    void connectServer();
};
