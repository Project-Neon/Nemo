#ifndef Motor_n
#define Motor_n

#include "Arduino.h"

class Move
{
  public:
    Move(int PIN_M1_EN , int PIN_M1_IN1, int PIN_M1_IN2, int PIN_M2_EN, int PIN_M2_IN1, int PIN_M2_IN2);
    void front(int vel);
    void back(int vel);
    void left(int vel);
    void right(int vel);
    void brake();
  private:
    int _PIN_M1_EN;
    int _PIN_M1_IN1;
    int _PIN_M1_IN2;
    int _PIN_M2_EN;
    int _PIN_M2_IN1;
    int _PIN_M2_IN2;

};
#endif

