#include <SoftwareSerial.h>
#include <DHT11.h>
#include <Timer.h>
Timer ts;
int samplingT = 5000;
int checkCNT = 0;
unsigned long time;
unsigned long preTime = 0;
int err;
SoftwareSerial BTSerial(0, 1);`
SoftwareSerial bluetooth(2, 3);
int pin1=5;
int pin2=6;
int pin3=7;
float temp1,temp2,temp3, humi;
DHT11 dht111(pin1); 
DHT11 dht112(pin2); 
DHT11 dht113(pin3);
void setup() 
{
  bluetooth.begin(9600);
  BTSerial.begin(9600);
  ts.every(samplingT, doTest);
}
void loop(){
  ts.update();
  if(BTSerial.available()){
    bluetooth.write(BTSerial.read()); 
    Serial.println(BTSerial.read());
  }
  if(Serial.available()){
    BTSerial.write(Serial.read());    
  }
}

void doTest() {
  time = millis();
  if((err=dht111.read(humi, temp1))==0)
  {
    BTSerial.print(temp1);
    BTSerial.print(":");
  }
  if((err=dht112.read(humi, temp2))==0)
  {
    BTSerial.print(temp2);
    BTSerial.print(":");
  }
  if((err=dht113.read(humi, temp3))==0)
  {
    BTSerial.println(temp3);
  }
  
}
