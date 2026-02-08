#include <BTAddress.h>
#include <BTAdvertisedDevice.h>
#include <BTScan.h>
#include <BluetoothSerial.h>
BluetoothSerial ESPBT;
int EN_1=13;
int EN_2=25;
int IN_1=12;
int IN_2=14;
int IN_3=27;
int IN_4=26;
void setup() {
  ESPBT.begin("MyCar");
  pinMode(EN_1,OUTPUT);
  pinMode(EN_2,OUTPUT);
  pinMode(IN_1,OUTPUT);
  pinMode(IN_2,OUTPUT);
  pinMode(IN_3,OUTPUT);
  pinMode(IN_4,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  String command=ESPBT.readString();
  if(command=="Front" || command=="front"){
    Serial.println(command);
    digitalWrite(EN_1,HIGH);
  digitalWrite(EN_2,HIGH);
  analogWrite(IN_1,200);
  analogWrite(IN_2,0);       //forwaard
  analogWrite(IN_3,200);
  analogWrite(IN_4,0);
  delay(1500);
  digitalWrite(EN_1,HIGH);
  digitalWrite(EN_2,HIGH);
  analogWrite(IN_1,0);
  analogWrite(IN_2,0);      //stop
  analogWrite(IN_3,0);
  analogWrite(IN_4,0);
  delay(2000);
  }
  else if(command=="Right" || command=="right"){
    Serial.println(command);
  digitalWrite(EN_1,HIGH);
  digitalWrite(EN_2,HIGH);
  analogWrite(IN_1,0);
  analogWrite(IN_2,0);       //right
  analogWrite(IN_3,200);
  analogWrite(IN_4,0);
  delay(1500);
  digitalWrite(EN_1,HIGH);
  digitalWrite(EN_2,HIGH);
  analogWrite(IN_1,0);
  analogWrite(IN_2,0);      //stop
  analogWrite(IN_3,0);
  analogWrite(IN_4,0);
  delay(2000);
  }
  else if(command=="Left" || command=="left"){
    Serial.println(command);
  digitalWrite(EN_1,HIGH);
  digitalWrite(EN_2,HIGH);
  analogWrite(IN_1,200);
  analogWrite(IN_2,0);      //left
  analogWrite(IN_3,0);
  analogWrite(IN_4,0);
  delay(1500);
  digitalWrite(EN_1,HIGH);
  digitalWrite(EN_2,HIGH);
  analogWrite(IN_1,0);
  analogWrite(IN_2,0);      //stop
  analogWrite(IN_3,0);
  analogWrite(IN_4,0);
  delay(2000);
  }
  else if(command=="Back" || command=="back"){
    Serial.println(command);
  digitalWrite(EN_1,HIGH);
  digitalWrite(EN_2,HIGH);
  analogWrite(IN_1,0);
  analogWrite(IN_2,200);      //Back
  analogWrite(IN_3,0);
  analogWrite(IN_4,200);
  delay(2000);
  digitalWrite(EN_1,HIGH);
  digitalWrite(EN_2,HIGH);
  analogWrite(IN_1,0);
  analogWrite(IN_2,0);      //stop
  analogWrite(IN_3,0);
  analogWrite(IN_4,0);
  delay(2000);
  }


}
