#include "Arduino.h"
#include "Motor.h"

Move::Move(int PIN_M1_EN , int PIN_M1_IN1, int PIN_M1_IN2, int PIN_M2_EN, int PIN_M2_IN1, int PIN_M2_IN2){
  pinMode(PIN_M1_IN1, OUTPUT);
  pinMode(PIN_M1_IN2, OUTPUT);
  pinMode(PIN_M1_EN, OUTPUT);
  pinMode(PIN_M2_IN1, OUTPUT);
  pinMode(PIN_M2_IN2, OUTPUT);
  pinMode(PIN_M2_EN, OUTPUT);
  _PIN_M1_EN = PIN_M1_EN;
  _PIN_M1_IN1 = PIN_M1_IN1;
  _PIN_M1_IN2 = PIN_M1_IN2 ;
  _PIN_M2_EN = PIN_M2_EN;
  _PIN_M2_IN1 = PIN_M2_IN1;
  _PIN_M2_IN2 = PIN_M2_IN2;
}
void Move::front(int vel){
  digitalWrite(_PIN_M1_IN1, LOW);
  digitalWrite(_PIN_M1_IN2, HIGH);
  analogWrite(_PIN_M1_EN, vel );
  digitalWrite(_PIN_M2_IN1, HIGH);
  digitalWrite(_PIN_M2_IN2, LOW);
  analogWrite(_PIN_M2_EN, vel );
}
void Move::back(int vel){
  digitalWrite(_PIN_M1_IN1, HIGH);
  digitalWrite(_PIN_M1_IN2, LOW);
  analogWrite(_PIN_M1_EN, vel );
  digitalWrite(_PIN_M2_IN1, LOW);
  digitalWrite(_PIN_M2_IN2, HIGH);
  analogWrite(_PIN_M2_EN, vel );
}
void Move::left(int vel){ // ok
    digitalWrite(_PIN_M1_IN1, LOW);
    digitalWrite(_PIN_M1_IN2, HIGH);
    analogWrite(_PIN_M1_EN, vel );
    digitalWrite(_PIN_M2_IN1, LOW);
    digitalWrite(_PIN_M2_IN2, HIGH);
    analogWrite(_PIN_M2_EN, vel );
 }
 void Move::right(int vel){ // ok
    digitalWrite(_PIN_M1_IN1, HIGH);
    digitalWrite(_PIN_M1_IN2, LOW);
    analogWrite(_PIN_M1_EN, 150 );
    digitalWrite(_PIN_M2_IN1, HIGH);
    digitalWrite(_PIN_M2_IN2, LOW);
    analogWrite(_PIN_M2_EN, 150 );
}
void Move::brake(){ // ok
   digitalWrite(_PIN_M1_IN1, HIGH);
   digitalWrite(_PIN_M1_IN2, HIGH);
   analogWrite(_PIN_M1_EN, 0);
   digitalWrite(_PIN_M2_IN1, HIGH);
   digitalWrite(_PIN_M2_IN2, HIGH);
   analogWrite(_PIN_M2_EN, 0);   
}


