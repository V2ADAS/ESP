#include <WiFi.h>
#include <ArduinoJson.h>
#include <HardwareSerial.h>

#define TIMEOUT         50 // in ms

#define SSID            "ESP32"
#define PASSWORD        "9@ssW0rd"
#define PORT            4000


// Configure IP addresses of the local access point
IPAddress local_IP(192,168,1,22);
IPAddress gateway(192,168,1,22);
IPAddress subnet(255,255,255,0);

WiFiServer server(PORT);
WiFiClient client;

bool transmitting = true;

// Serial for Connecting with STM
HardwareSerial SerialPort(2);

void setup() {
  Serial.begin(115200);
  SerialPort.begin(115200, SERIAL_8N1, 16, 17);

  WiFi.softAPConfig(local_IP, gateway, subnet);
  WiFi.softAP(SSID, PASSWORD);
  
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.softAPIP());
  Serial.println(PORT);

  server.begin(PORT);
}

void handleRequest(String request) {
  Serial.print(request.length());
  Serial.print(": ");
  Serial.println(request);

  if (request == "stop")
    transmitting = false;
  else if (request == "start")
    transmitting = true;
  else
    for (int i=0; i < 100000; i++) {
      if (SerialPort.availableForWrite()) {
          SerialPort.write(request.c_str());
          break;
      }
    }
  
  return;
}

void handleSTMData() {
  String Buffer = SerialPort.readString();
  Serial.print(Buffer);
  Serial.print("\n");
}

void loop() {
  client = server.available();
  if (client){
    client.setTimeout(0);
    while (client.connected()) {
      // Check for input
      delay(TIMEOUT);
      String request = client.readStringUntil('\r');
      request.trim();
      if(!request.isEmpty()) handleRequest(request);

      // check for readings from STM
      if (SerialPort.available()) handleSTMData();

      // Send data to connected device
      if(transmitting) client.println(generateJsonData());
    }
  }
  Serial.print(".");
  delay(500);
}

String generateJsonData() {
  String jsonString = "";                           // create a JSON string for sending data to the client
  JsonDocument doc;                                 // create a JSON container
  JsonObject object = doc.to<JsonObject>();         // create a JSON Object
  object["CF"] = 20;
  object["CB"] = 15;
  object["LC"] = 76;
  object["RC"] = 23;
  object["LB"] = 23;
  object["RB"] = 12;
  object["ENC"] = 123;
  object["SERV"] = 56;
  object["TIME"] = 324;
  serializeJson(doc, jsonString);                   // convert JSON object to string
  return jsonString;
}