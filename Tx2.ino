int c;
String dataLen;
int LED = 15;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(19200);// esp to serial monitor
  Serial2.begin(9600); // esp to stm
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int c1=1;
  Serial2.print(c1);
  Serial.println(c1);
  delay(200);
}

