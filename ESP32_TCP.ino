#include <WiFi.h>
#include <ArduinoJson.h>

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

void setup() {
  Serial.begin(115200);

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
  
  return;
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

      // TODO: Receive data from uC

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