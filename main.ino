#include <Servo.h>
int servoPin = 3;
Servo servo1;

const int ZERO = 2;
const int ONE = 4;
const int TWO = 5;
const int THREE = 6;
const int FOUR = 7;
const int FIVE = 8;
const int SIX = 9;
const int SEVEN = 10;

String angleString = "";
//String digit = "";

void setup() {
  servo1.attach(servoPin);
  pinMode(ZERO,OUTPUT);
  pinMode(ONE,OUTPUT);
  pinMode(TWO,OUTPUT);
  pinMode(THREE,OUTPUT);
  pinMode(FOUR,OUTPUT);
  pinMode(FIVE,OUTPUT);
  pinMode(SIX,OUTPUT);
  pinMode(SEVEN,OUTPUT);
  
  Serial.begin(9600);
}

String pinReader() {
  if (digitalRead(ZERO) == HIGH) {
    return "0";
  }
  else if (digitalRead(ONE) == HIGH) {
    return "1";
  }
  else if (digitalRead(TWO) == HIGH) {
    return "2";
  }
  else if (digitalRead(THREE) == HIGH) {
    return "3";
  }
  else if (digitalRead(FOUR) == HIGH) {
    return "4";
  }
  else if (digitalRead(FIVE) == HIGH) {
    return "5";
  }
  else if (digitalRead(SIX) == HIGH) {
    return "6";
  }
  else if (digitalRead(SEVEN) == HIGH) {
    return "7";
  }
  else {
    return "null";
  }
}

void loop() {
  for (int i = 0; i < 3; i++) {
    while (true) {
      String digit = pinReader();
      Serial.println("Digit is:" + digit);
      delay(500);
      if (digit != "null") {
        angleString = angleString + digit;
        //Serial.println("Angle in string type is: " + angleString); //test
        break;
      }
    }
  }

  //rotating the servo shaft
  int angleInt = angleString.toInt();
  servo1.write(angleInt);
  delay(1000);

  angleString = "";
  
 /* if (digitalRead(ZERO) == HIGH) {
    unsigned long t1 = millis();
    while (true) {
      unsigned long t2 = millis();
      int timeElapsed = (int(t2) - int(t1))/1000;
      int angleMove = timeElapsed + 5; //To move the servo faster
      Serial.println(angleMove);
      servo1.write(angleMove);
      if (digitalRead(ZERO) == LOW) {
        break;
      }
    } */
   /* while (true) {
      if (digitalRead(PIN_NUMBER) == LOW) {
        unsigned long t2 = millis();
        int timeElapsed = (int(t2) - int(t1))/1000;
        Serial.println(timeElapsed);
        servo1.write(timeElapsed);
        delay(5000);
        break;
      }
    } */
}
