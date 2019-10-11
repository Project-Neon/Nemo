#include <Thread.h>
#include <ThreadController.h>
#include <Wire.h>
#include <VL53L0X.h>

#include "Sensores.h"

ThreadController controller;

VL53L0X sensor;
VL53L0X sensor2;
VL53L0X sensor3;
VL53L0X sensor4;
MPU6050 mpu6050(Wire);

  long Sensores::distance[4];
  bool Sensores::direcao;
  bool Sensores::preto;
  bool Sensores::white;


//declaração das threads
void threadColorSensors_run();
Thread threadColorSensors(threadColorSensors_run, 25);

void Sensores::update();
Thread threadTOFSensor(Sensores::update, 25);

void threadColorSensors_run(){
  if(analogRead(SRT) < Sensores::preto||digitalRead(SRF)< Sensores::preto){ // 1 -> preto / 0 -> Black
    Sensores::white=0;
    analogRead(SRT) < Sensores::preto ? Sensores::direcao = true : Sensores::direcao = false;    
  }
  else{
    Sensores::white=1;
  }
}

void Sensores::init(){

  controller.add(&threadColorSensors);
  controller.add(&threadTOFSensor);
  
// Sensores refletância  
  pinMode(SRF, INPUT);
  pinMode(SRT, INPUT);
  Sensores::preto = analogRead(SRT);

// Sensores TOF  
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);

  delay(500);
  Wire.begin();
  
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
  
  //SENSOR
  pinMode(9, INPUT);
  delay(150);
  sensor.init(true);
  delay(100);
  sensor.setAddress((uint8_t)22);


  //SENSOR 2
  pinMode(10, INPUT);
  delay(150);
  delay(100);
  sensor2.setAddress((uint8_t)25);

  //SENSOR 3
  delay(150);
  sensor3.init(true);
  delay(100);
  sensor3.setAddress((uint8_t)28);

  //SENSOR 4
  pinMode(12, INPUT);
  delay(150);
  delay(100);
  sensor3.setAddress((uint8_t)31);

  sensor.setTimeout(500);
  sensor2.setTimeout(500);
  sensor3.setTimeout(500);
  sensor4.setTimeout(500);

}

void Sensores::update(){
  Sensores::distance[0] = (sensor.readRangeSingleMillimeters());
  Sensores::distance[1] = (sensor2.readRangeSingleMillimeters());
  Sensores::distance[2] = (sensor3.readRangeSingleMillimeters());
  Sensores::distance[3] = (sensor4.readRangeSingleMillimeters()); 
  mpu6050.update();
}

boolean Sensores::visao(){ // Uma função que retorna false se o robô não viu alguma coisa em qualquer um dos sensores
  
if(Sensores::distance[0] != -1 || Sensores::distance[1] != -1 || Sensores::distance[3] != -1|| Sensores::distance[4]!=-1)
  return false;
  else return true;
  
}
