#include "headder.h"
int _1fPin, _1bPin, _2fPin, _2bPin;

void bt_car_init(int f1, int b1, int f2, int b2) {
  _1fPin = f1;
  _1bPin = b1;
  _2fPin = f2;
  _2bPin = b2;
}
void stop(void) {
  digitalWrite(_1fPin, LOW);
  digitalWrite(_1bPin, LOW);
  digitalWrite(_2fPin, LOW);
  digitalWrite(_2bPin, LOW);
}

void forword(void) {
  stop();
  delay(100);
  digitalWrite(_1fPin, HIGH);
  digitalWrite(_2fPin, HIGH);
}
void backword(void) {
  stop();
  delay(100);
  digitalWrite(_1bPin, HIGH);
  digitalWrite(_2bPin, HIGH);
}
void fleft(void) {
  stop();
  delay(100);
  digitalWrite(_1fPin, HIGH);
}
void fright(void) {
  stop();
  delay(100);
  digitalWrite(_2fPin, HIGH);
}
void bleft(void) {
  stop();
  delay(100);
  digitalWrite(_1bPin, HIGH);
}
void bright(void) {
  stop();
  delay(100);
  digitalWrite(_2bPin, HIGH);
}

void car_auto(void){
  String receivedData = "";
  char receivedChar;
  while(1){
   if (Serial.available() > 0) 
  {
    receivedChar = Serial.read();
     if (receivedChar == '\n') 
    {
      if ((receivedData == "s") || (receivedData == "S")) 
      { stop(); } 
      else if ((receivedData == "f") || (receivedData == "F")) 
      {  forword(); }
      else if ((receivedData == "b") || (receivedData == "B")) 
      {  backword(); }
      else if ((receivedData == "fl") || (receivedData == "FL"))
      {  fleft(); }
      else if ((receivedData == "fr") || (receivedData == "FR")) 
      {   fright(); }
      else if ((receivedData == "bl") || (receivedData == "BL"))
      {  bleft(); }
      else if ((receivedData == "br") || (receivedData == "BR")) 
      {   bright(); }
      else if ((receivedData == "man") || (receivedData == "MAN")) 
      {   car_manual(); }


      receivedData = "";
    } 
      else { receivedData = receivedData + receivedChar;    }
  }
}
}
void car_manual(void){
  String receivedData = "";
  char receivedChar;
  int my_delay = 100;
  while(1){
   if (Serial.available() > 0) 
  {
    receivedChar = Serial.read();
    delay(5);
    if (receivedChar == '\n') 
    {
      if ((receivedData == "s") || (receivedData == "S")) 
      { stop(); } 
      else if ((receivedData == "f") || (receivedData == "F")) 
      {  forword();delay(my_delay);stop(); }
      else if ((receivedData == "b") || (receivedData == "B")) 
      {  backword();delay(my_delay);stop(); }
      else if ((receivedData == "fl") || (receivedData == "FL"))
      {  fleft();delay(my_delay);stop(); }
      else if ((receivedData == "fr") || (receivedData == "FR")) 
      {   fright();delay(my_delay);stop(); }
      else if ((receivedData == "bl") || (receivedData == "BL"))
      {  bleft();delay(my_delay);stop(); }
      else if ((receivedData == "br") || (receivedData == "BR")) 
      {   bright();delay(my_delay);stop(); }
      else if ((receivedData == "aut") || (receivedData == "AUT")) 
      {   car_auto(); }


      receivedData = "";
    } 
      else { receivedData = receivedData + receivedChar;    }
  }
}
}
