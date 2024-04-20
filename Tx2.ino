
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
/*  
  while (Serial2.available())
  {
    c=Serial2.read();
    break;
  }
  Serial.println(c);

  if (c==1)
  {
    c=0;
  //  dataLen="";
    digitalWrite(LED, HIGH);
  }*/
    //  delay(5000);
}

/*      while (Serial2.available())
  {
    c=Serial2.read();
    if (c != '3') {dataLen+=c;}
    else   {break;}
  }
  if (c=='3')
  {
    Serial.println(dataLen);
    c=0;
    dataLen="";
  }*/
