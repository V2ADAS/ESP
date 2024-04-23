char c;
char array[4];
int k,i=0;
String dataLen;
int LED = 15;
#define size_A  4
void setup() {
  // put your setup code here, to run once:
  Serial.begin(19200);// esp to serial monitor
  Serial2.begin(9600); // esp to stm
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int c1=1;
  char c2='f';
  Serial2.print(c2);
  Serial.println("message 1 sent from esp = ");
  Serial.println(c2);
  delay(200);

   char c3='b';
  Serial2.print(c3);
  Serial.println("message 2 sent from esp = ");
  Serial.println(c3);
  delay(200);

   char c4='r';
  Serial2.print(c4);
  Serial.println("message 3 sent from esp = ");
  Serial.println(c4);
  delay(200);

  
  while (Serial2.available())
  {
    c=Serial2.read();
    if (i==0)
    {
      i++;
    }
    else
    {
    array[k++]=c;
    Serial.println("char. recieved  = ");
    Serial.println(c);
    if (k==(size_A))
    {
      Serial.println("WORD. recieved  = ");
      for (int j=0; j<4 ; j++)
      {
        Serial.print(array[j]);
      }
      digitalWrite(LED, HIGH);
      break;
    }
    }
  }
 
/*
  if (c==2)
  {
    c=0;
  //  dataLen="";
    digitalWrite(LED, HIGH);
  }*/
      delay(5000);
}
