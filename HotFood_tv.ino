#include <SoftwareSerial.h>
SoftwareSerial bluetooth(2, 3);
int relay=10;
boolean toggle=0;
void setup() 
{
  bluetooth.begin(9600);
  Serial.begin(9600);
  pinMode(relay,OUTPUT);
}
void loop()
{
  if(bluetooth.read()=='1'){

  Serial.println("1");
  digitalWrite(relay,LOW);
  
  }
  else if(bluetooth.read()=='0'){
    Serial.println("0");
  digitalWrite(relay,HIGH);

  }
 
}
