#pragma once
#include <Arduino.h>
#include <ESP8266WiFi.h>
class NarodMonSender {
  public:
    void addHead(String deviceId);
    void addSensor(String value, String sensorId) ;
    String sendData();
    void connectServer();
    void enableDebug();
    void disableDebug();
  private:
    const char* host = "narodmon.ru";
    const uint16_t port = 8283;
    boolean serverConnected = false;
    boolean debug = false;
    String text = "";
    WiFiClient client;
};