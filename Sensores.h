#ifndef SENSORES_H
#define SENSORES_H

#include "_config.h"

#include <Thread.h>
#include <ThreadController.h>

#include <Wire.h>
#include <VL53L0X.h>
#include <MPU6050_tockn.h>

extern VL53L0X sensor;
extern VL53L0X sensor2;
extern VL53L0X sensor3;
extern VL53L0X sensor4;
extern MPU6050 mpu6050;

extern ThreadController controller; 

class Sensores{
public:
  static long distance[4];
  static bool direcao;
  static bool preto;
  static bool white;
  
  static void init();
  static void update();

  static bool getColorSensors(); 
  static bool visao(); 

  static int getAngleY();
  static int getAngleX();
  static int getAngleZ();

};
#endif
