#include <Arduino.h>

int LEDaPin = 3;int LEDbPin = 7;int LEDcPin = 10;int LEDdPin = 12;
int LEDePin = 13;int LEDfPin = 4;int LEDgPin = 9;int LEDdigit1Pin = 2;
int LEDdigit2Pin = 5;int LEDdigit3Pin = 6;int LEDdigit4Pin = 8; int LEDdotPin = 11;
int JoystickClickPinAnalog = 0;int JoystickYPinAnalog = 1;int JoystickXPinAnalog = 2;int lastJoystickRead = millis();
int NULLint = -404; unsigned long cooldown1OldNumber = millis(); unsigned long cooldown2OldNumber = millis();


const byte LEDpinByNumber[7] = {3, 7, 10, 12, 13, 4, 9};
const byte LEDdigitByNumber[4] = {2, 5, 6, 8};
const byte LEDnumberTranslator[10][7] = {{1, 1, 1, 1, 1, 1, 0},{0, 0, 0, 0, 1, 1, 0},{1, 1, 0, 1, 1, 0, 1},{1, 1, 1, 1, 0, 0, 1},{0, 1, 1, 0, 0, 1, 1},{1, 0, 1, 1, 0, 1, 1},{1, 0, 1, 1, 1, 1, 1},{1, 1, 1, 0, 0, 0, 0},{1, 1, 1, 1, 1, 1, 1},{1, 1, 1, 1, 0, 1, 1},};
int LEDstate[4][3] = {{1, 1, 0},{1, 0, 0},{1, 0, 0},{1, 0, 0}};

int LEDgetDotPosition() {
  for (int i = 0; i < 4; i++){
    if(LEDstate[i][1] == true) {
      return i;
    }
  }
  return NULLint;
}
int LEDgetCurrentNumber() {
  int LEDdotPosition = LEDgetDotPosition();
  return LEDstate[LEDdotPosition][2];
}
void LEDresetDot() {
  for (int i = 0; i < 4; i++){
    LEDstate[i][1] = false;
  }
  LEDstate[0][1] = true;
}
void LEDsetDot(int space) {
  int LEDdotPosition = LEDgetDotPosition();
  int LEDnextDot = LEDdotPosition + space;
  if(LEDnextDot > 3) {LEDnextDot = 0;}
  if(LEDnextDot < 0) {LEDnextDot = 3;}

  LEDstate[LEDdotPosition][1] = 0;
  LEDstate[LEDnextDot][1] = 1;
}
void LEDnextNumber(int space) {
  int LEDdotPosition = LEDgetDotPosition();
  int LEDcurrentNumber = LEDstate[LEDdotPosition][2];
  int LEDnextNumber = LEDcurrentNumber + space;
  if(LEDnextNumber > 9) {LEDnextNumber = 0;}
  if(LEDnextNumber < 0) {LEDnextNumber = 9;}

  LEDstate[LEDdotPosition][2] = LEDnextNumber;
}
void showNumber(int digit, int number, bool isDotActive, bool IsActive) {
  if(IsActive) { 
    if(digit == 1) {
      digitalWrite(LEDdigit1Pin, (IsActive == 1 ? LOW : HIGH));digitalWrite(LEDdigit2Pin, HIGH);digitalWrite(LEDdigit3Pin, HIGH);digitalWrite(LEDdigit4Pin, HIGH);
    }
    if(digit == 2) {
      digitalWrite(LEDdigit1Pin, HIGH);digitalWrite(LEDdigit2Pin, (IsActive == 1 ? LOW : HIGH));digitalWrite(LEDdigit3Pin, HIGH);digitalWrite(LEDdigit4Pin, HIGH);
    }
    if(digit == 3) {
      digitalWrite(LEDdigit1Pin, HIGH);digitalWrite(LEDdigit2Pin, HIGH);digitalWrite(LEDdigit3Pin, (IsActive == 1 ? LOW : HIGH));digitalWrite(LEDdigit4Pin, HIGH);
    }
    if(digit == 4) {
      digitalWrite(LEDdigit1Pin, HIGH);digitalWrite(LEDdigit2Pin, HIGH);digitalWrite(LEDdigit3Pin, HIGH);digitalWrite(LEDdigit4Pin, (IsActive == 1 ? LOW : HIGH));
    }
    if(isDotActive) {
      digitalWrite(LEDdotPin, HIGH);
    } else {
      digitalWrite(LEDdotPin, LOW);
    }
    for (int i = 0; i < 7; i++) {
      digitalWrite(LEDpinByNumber[i], LEDnumberTranslator[number][i]);
    }
  }
}
void toggleNumber() {
  int LEDdotPosition = LEDgetDotPosition();

  LEDstate[LEDdotPosition][0] = 0;
}

void setup() {
  pinMode(LEDaPin, OUTPUT);pinMode(LEDbPin, OUTPUT);pinMode(LEDcPin, OUTPUT);pinMode(LEDdPin, OUTPUT);
  pinMode(LEDePin, OUTPUT);pinMode(LEDfPin, OUTPUT);pinMode(LEDgPin, OUTPUT);pinMode(LEDdigit1Pin, OUTPUT);
  pinMode(LEDdotPin, OUTPUT);
  pinMode(LEDdigit2Pin, OUTPUT);pinMode(LEDdigit3Pin, OUTPUT);pinMode(LEDdigit4Pin, OUTPUT);
  Serial.begin(250000);
}

void loop() {
  int JoystickClickvalue = ((analogRead(JoystickClickPinAnalog) > 20 ? 0 : 1));int JoystickYvalue = (analogRead(JoystickYPinAnalog) > 600 ? -1 : (analogRead(JoystickYPinAnalog) < 430 ? 1 : 0));int JoystickXvalue = (analogRead(JoystickXPinAnalog) > 600 ? -1 : (analogRead(JoystickXPinAnalog) < 440 ? 1 : 0));
  //Serial.println("IsJoyClick: " + String(JoystickClickvalue) + " JoystickYvalue: " + String(JoystickYvalue) + " JoystickXvalue: " + String(JoystickXvalue));
  if((JoystickXvalue == 1 || JoystickXvalue == -1) && millis() - cooldown1OldNumber >= 500) {
    Serial.println(String(LEDgetDotPosition()) + " " + String(millis()) + " " + String(cooldown1OldNumber) + " " + String(millis() - cooldown1OldNumber));
    cooldown1OldNumber = millis();
    delay(2);
    if(JoystickXvalue == 1) {
      LEDsetDot(1);
    }
    if(JoystickXvalue == -1) {
      LEDsetDot(-1);
    }
  }
  if((JoystickYvalue == 1 || JoystickYvalue == -1) && millis() - cooldown2OldNumber >= 250) {
    Serial.println(String(LEDgetDotPosition()) + " " + String(millis()) + " " + String(cooldown2OldNumber) + " " + String(millis() - cooldown2OldNumber));
    cooldown2OldNumber = millis();
    delay(2);
    if(JoystickYvalue == -1) {
      LEDnextNumber(1);
    }
    if(JoystickYvalue == 1) {
      LEDnextNumber(-1);
    }
  }
  showNumber(1, LEDstate[0][2], LEDstate[0][1], LEDstate[0][0]);
  delay(2);
  showNumber(2, LEDstate[1][2], LEDstate[1][1], LEDstate[1][0]);
  delay(2);
  showNumber(3, LEDstate[2][2], LEDstate[2][1], LEDstate[2][0]);
  delay(2);
  showNumber(4, LEDstate[3][2], LEDstate[3][1], LEDstate[3][0]);
  delay(2);
}