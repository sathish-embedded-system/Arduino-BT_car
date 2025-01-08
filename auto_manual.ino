#include "headder.h"
/*int motor1fPin = 8;int motor1bPin = 9;int motor2fPin = 10;int motor2bPin = 11;*/
String receivedData = "";
void setup() {
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  bt_car_init(8, 9, 10, 11);
  Serial.begin(9600);
}

void loop() 
{

  if (Serial.available() > 0) 
  {
    char receivedChar = Serial.read();
    delay(5);
    if (receivedChar == '\n') 
    {
      if((receivedData == "aut")||(receivedData == "AUT"))
      {car_auto();}
      else if((receivedData=="man")||(receivedData=="MAN"))
      {car_manual(); }
      receivedData = "";
    } 
      else { receivedData = receivedData + receivedChar;    }
  }
}
