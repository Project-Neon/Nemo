#include "_config.h"

#ifndef MOTORS_H
#define MOTORS_H


class Motors{
public:

  // Initialize pins
  static void init();

  // Set power of both motors
  static void driveTank(float m1, float m2);

  // Set state as Iddle (Turn off motors)
  static void stop();
};

#endif
