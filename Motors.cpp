#include "Motors.h"
// Initialize pins
void Motors::init(){

  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  
  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);

}

void Motors::driveTank(float m1, float m2){

  // Limit Powers
  m1 = min(max(m1, -100), 100);
  m2 = min(max(m2, -100), 100);

  // Map powers
  int powerOutA = m1 * (MOTOR_ABS_MAX / 100.0);
  int powerOutB = m2 * (MOTOR_ABS_MAX / 100.0);

  // Set power
  analogWrite(PWMA, abs(powerOutA));
  analogWrite(PWMB, abs(powerOutB));

  // Set Directions
  digitalWrite(AIN1, powerOutA > 0 ? HIGH : LOW);
  digitalWrite(AIN2, powerOutA > 0 ? LOW : HIGH);

  digitalWrite(BIN1, powerOutB > 0 ? HIGH : LOW);
  digitalWrite(BIN2, powerOutB > 0 ? LOW : HIGH);
}

void Motors::stop(){
  // Set power (0)
  digitalWrite(PWMA, HIGH);
  digitalWrite(PWMB, HIGH);

  // Set both DIRS to 0
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, HIGH);

  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, HIGH);
}
