#include "easyNarodMon.h";
void NarodMonSender::addHead(String deviceId) {
  text += "#" + deviceId + '\n';
}
void NarodMonSender::addSensor(String value, String sensorId) {
  text += "#" + sensorId + "#" + value + '\n';
}
String NarodMonSender::sendData() {
  if (!serverConnected) {
    connectServer();
  }
  if (!client.connected()) {
    serverConnected = false;
    if (debug) {
      Serial.println("connection error");
    }
    return "connection error";
  }
  client.println(text + "##");
  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 5000) {
      if (debug) {
        Serial.println(">>> Client Timeout !");
      }
      client.stop();
      return "client timeout";
    }
  }

  // Read all the lines of the reply from server and print them to Serial
  if (debug) {
    Serial.println("receiving from remote server");
  }
  // not testing 'client.connected()' since we do not need to send data here
  String answer;
  while (client.available()) {
    answer = client.readString();
  }
  if (debug) {
    Serial.print("server sent: ");
    Serial.println(answer);
  }

  if (debug) {
    Serial.println();
    Serial.println("closing connection");
  }
  client.stop();
  return answer;
}
void NarodMonSender::connectServer() {
  if (debug) {
    Serial.print("connecting to ");
    Serial.print(host);
    Serial.print(':');
    Serial.println(port);
  }
  // Use WiFiClient class to create TCP connections
  if (!client.connect(host, port)) {
    if (debug) {
      Serial.println("connection failed");
    }
    return;
  }
  serverConnected = true;
}
void NarodMonSender::enableDebug() {
  debug = true;
}
void NarodMonSender::disableDebug() {
  debug = false;
}
