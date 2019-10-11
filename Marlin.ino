#include "Motors.h"
#include "Sensores.h"
#include "_config.h"

void setup() {
  // put your setup code here, to run once:
  Sensores::init();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(mpu6050.getAngleX());
}
