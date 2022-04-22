#include "easyNarodMon.h";
void NarodMonSender::setHead(String deviceId) {
  text = "#" + deviceId + '\n';
}
void NarodMonSender::setHead(String deviceId, String name, String lat, String lon, String alt) {
  text = "#" + deviceId +"#" +lat+"#" +lon+"#" +alt+'\n';
}
void NarodMonSender::addSensor(String value, String sensorId) {
  text += "#" + sensorId + "#" + value + '\n';
}
void NarodMonSender::addSensor(double value, String sensorId) {
  text += "#" + sensorId + "#" + String(value) + '\n';
}
void NarodMonSender::addSensor(int value, String sensorId) {
  text += "#" + sensorId + "#" + String(value) + '\n';
}

void NarodMonSender::addSensor(String value, String sensorId, String name) {
  text += "#" + sensorId + "#" + value +"#" +name+ '\n';
}
void NarodMonSender::addSensor(double value, String sensorId, String name) {
  text += "#" + sensorId + "#" + String(value) +"#" +name+ '\n';
}
void NarodMonSender::addSensor(int value, String sensorId, String name) {
  text += "#" + sensorId + "#" + String(value) +"#" +name+'\n';
}

String NarodMonSender::sendData() {
  if (!client.connected()) {
    connectServer();
  }
  if (!client.connected()) {
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
 
}
void NarodMonSender::enableDebug() {
  debug = true;
}
void NarodMonSender::disableDebug() {
  debug = false;
}


void NarodMonSender::connectWiFi(const char* ssid, const char* password) {
  if (debug) {
    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);
  }
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    if (debug) {
      Serial.print(".");
    }
  }
  if (debug) {
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
  }
}