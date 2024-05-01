#include <WiFi.h>                      // Include the WiFi library
#include <ArduinoJson.h>               // Include the ArduinoJson library
#include <string.h>
//#include <HardwareSerial.h>            // Include the HardwareSerial library
int c;
char c1;
int array[5];

#define TIMEOUT         50            // Timeout value in milliseconds

#define SSID            "ESP32_WIFI"       // WiFi network SSID
#define PASSWORD        "12345678"    // WiFi network password
#define PORT            4000          // Port number for communication

// Configure IP addresses of the local access point
IPAddress local_IP(192,168,1,22);     // Local IP address
IPAddress gateway(192,168,1,22);      // Gateway IP address
IPAddress subnet(255,255,255,0);      // Subnet mask

WiFiServer server(PORT);               // Create a WiFi server object
WiFiClient client;                     // Create a WiFi client object

bool transmitting = true;             // Flag to control data transmission

// Serial for Connecting with STM
//HardwareSerial SerialPort(2);         // Initialize hardware serial port 2

void setup() {
//  Serial.begin(115200);                // Initialize serial communication with the computer
//  SerialPort.begin(115200, SERIAL_8N1, 16, 17);  // Initialize serial communication with STM32

  Serial.begin(19200);// Initialize serial communication with serial monitor
  Serial2.begin(9600); // Initialize serial communication with STM32

  WiFi.softAPConfig(local_IP, gateway, subnet);  // Configure soft AP with specified IP addresses
  WiFi.softAP(SSID, PASSWORD);         // Start the soft access point
  
  Serial.println("");                  // Print a blank line
  Serial.println("WiFi connected");    // Print message indicating WiFi connection
  Serial.println("IP address: ");      // Print message indicating IP address
  Serial.println(WiFi.softAPIP());     // Print the soft AP's IP address
  Serial.println(PORT);                // Print the port number

  server.begin(PORT);                  // Start the WiFi server
}

// Function to handle incoming requests
void handleRequest(String request) {
  //Serial.print(request.length());      // Print the length of the request
  //Serial.print("REQ IS : ");                  // Print a colon
  //Serial.println(request);             // Print the request
  if (!strcmp(request.c_str(),"f"))
  {
      Serial.println("FORW IS RECIEVED : ");
      Serial2.print('f');      
  }
  else if (!strcmp(request.c_str(),"r"))
  {
      Serial.println("Backwards IS RECIEVED : ");
      Serial2.print('b');            
  }
  else if (!strcmp(request.c_str(),"b"))
  {
      Serial.println("Brakes IS RECIEVED : ");  
      Serial2.print('r');      
  }

  // Check the received request and take appropriate action
  if (request == "stop")
    transmitting = false;              // Set transmitting flag to false
  else if (request == "start")
    transmitting = true;               // Set transmitting flag to true
  else
    // Loop to ensure data is sent to STM32
    for (int i=0; i < 100000; i++) {
      if (Serial2.availableForWrite()) {
          Serial2.write(request.c_str());  // Write request to STM32
          break;
      }
    }
  
  return;
}

// Function to handle data received from STM
void handleSTMData() {
  c = Serial2.read();  // Read data from STM32
  Serial.println("Recieved Data :");
 // int i=0;
 // array[i++]=c1;
  Serial.print(c);                     // Print the received data
  Serial.print("\n");                       // Print a newline character
}

void loop() 
{
 // delay(5000);
  client = server.available();              // Check for incoming client connections
  if (client){
    client.setTimeout(0);                   // Set timeout to 0
    while (client.connected()) {
      // Check for input from client
      delay(TIMEOUT);                        // Delay for TIMEOUT milliseconds
      String request = client.readStringUntil('\r');  // Read request from client until carriage return
      request.trim();                        // Remove leading/trailing whitespaces from request
      if(!request.isEmpty()) handleRequest(request);  // Handle the received request

      // check for readings from STM
      if (Serial2.available()) { handleSTMData(); }   // Handle data received from STM32

      // Send data to connected device if transmitting flag is true
      if(transmitting) client.println(generateJsonData());  // Send JSON data to client
    }
  }
 // Serial.print(".");                        // Print a dot to indicate loop iteration
  delay(500);                               // Delay for 500 milliseconds
}

// Function to generate JSON data
String generateJsonData() {
  String jsonString = "";                           // create a JSON string for sending data to the client
  JsonDocument doc;                                 // create a JSON container
  JsonObject object = doc.to<JsonObject>();         // create a JSON Object
  object["MSG"] = c;                                // add data to JSON object
  /*object["CB"] = 15;                                // add data to JSON object
  object["LC"] = 76;                                // add data to JSON object
  object["RC"] = 23;                                // add data to JSON object
  object["LB"] = 23;                                // add data to JSON object
  object["RB"] = 12;                                // add data to JSON object
  object["ENC"] = 123;     */                         // add data to JSON object
  //object["SERV"] = 56;                              // add data to JSON object
 // object["TIME"] = 324;                             // add data to JSON object
  serializeJson(doc, jsonString);                   // convert JSON object to string
  return jsonString;                                // return JSON string
}
