/*

   tornado.ino
   
   Autor: Project Neon - Felipe Andrade
   Março de 2010


*/

#include "Thread.h"
#include "ThreadController.h"

// pinos analogicos dos sensores UF
#define pinFront 35
#define pinDir 32
#define pinEsq 33
#define pinTras 25

// Motor Direito
#define BIN1 3   //Modo de operação 
#define BIN2  18 //Modo de operação 
#define PWMB 19  //Controle de Velocidade
#define MOTOR_A 1 // Define motor da direita com valor 1


//Motor Esquerdo 
#define AIN1 5  // Modo de operação 
#define AIN2 17 // Modo de operação 
#define PWMA 16 // Controle de Velocidade
#define MOTOR_B 2 //Define motor da direita com valor 2

#define pinBotao 36 // pino do botao

int local = 0;

int UF_Fr;
int UF_dir;
int UF_esq;
int UF_tr;

Thread ThreadDosSesores_UF;
Thread controlaRobo; 

ThreadController cpu;

void procura(){

  UF_Frente = analogRead(pinFront); 
  UF_Dir = analogRead(pinDir);
  UF_Esq = analogRead(pinEsq);
  UF_Tras = analogRead(pinTras);  

  if(UF_Frente < 612 && UF_Dir < 612 
  && UF_Frente < 612 && UF_ < 612 ){
    local = -1; // Todos os objetos estão a mais de 25 cm
    return;  // Gira
  }
  
  if(UF_Frente < UF_Dir && UF_Frente < UF_Esq 
  && UF_Frente < UF_Tras ){
    local = 0; // achou na frente
    return;  
  }
  
  if(UF_Dir < UF_Frente && UF_Dir < UF_Esq && 
  UF_Dir < UF_Tras){
    local = 1; // Achou na direita
    return; 
  }

  if(UF_Esq < UF_Frente && UF_Esq < UF_Dir && 
  UF_Esq < UF_Tras) {
    local = 2; // Achou na esquerda
    return;
  }

  if(UF_Tras < UF_dir && UF_tras < UF_Esq && 
  UF_Tras < UF_Frente ){
    local = 3; // Achou atras
    return;
  }
  
}

void move(int motor, int speed, int direction){ // Funcao usada para movimentar os motores
  boolean inPin1 = LOW;
  boolean inPin2 = HIGH;

  if(direction == 1){
    inPin1 = HIGH;
    inPin2 = LOW;
  }
  if(speed == 0){ // Caso queremos parar os motores
    inPin1 = LOW; // Deixamos o AIN1 e AIN2 em "LOW"
    inPin2 = LOW;
}
  if(motor == 0)  {
    digitalWrite(AIN1, inPin1);
    digitalWrite(AIN2, inPin2);
    ledcWrite(MOTOR_A, speed);
  }
  else{
    digitalWrite(BIN1, inPin1);
    digitalWrite(BIN2, inPin2);
    ledcWrite(MOTOR_A, speed);
  }
}

void cerebro(){ Função usada para, através da funcao procura, tomar a decisão correta
  if (local == -1){ // gira direita se nao ver nada
    move(MOTOR_A, 255, 1); //Motor da Esquerda, para o Motor, sentido de rotação
    move(MOTOR_B, 255, 1); //Motor da Direita, a toda velocidade, sentido de rotação
  } // ver se o speed esta bom para achar objetos

  if (local == 0){ // Frente
    move(MOTOR_A, 255, 1);
    move(MOTOR_B, 255, 2);
  } // confirmar se ele realmente vai pra frente

  if(local == 1){ // gira direita 
    move(MOTOR_A, 255, 1);
    move(MOTOR_B, 255, 1);
  } // confirmar se ele realmente vai pra direita
  
  if(local == 2){ // gira esquerda 
    move(MOTOR_A, 255, 2);
    move(MOTOR_B, 255, 2);
  } // confirmar se ele realmente vai pra esquerda

  if(local == 3){ // anda pra tras
    move(MOTOR_A, 255, 2);
    move(MOTOR_B, 255, 1);
  } // confirmar se ele realmente vai pra tras
}


void setup() {
  // put your setup code here, to run once:
  
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);

  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);

  pinMode(pinBotao, INPUT);

  ThreadDosSesores_UF.setInterval(50);
  ThreadDosSesores_UF.onRun(procura);

  controlaRobo.setInterval(55);
  controlaRobo.onRun(cerebro);

  // CONFIGURACAO DO PWM
  ledcSetup(MOTOR_A, freq, resolution);
  ledcSetup(MOTOR_B, freq, resolution);

  ledcAttachPin(PWMA, MOTOR_A);
  ledcAttachPin(PWMB, MOTOR_B);
  
  cpu.add(&controlaRobo);
  cpu.add(&ThreadDosSesores_UF);
}

void loop() {
  while(!digitalRead(pinBotao)){
    cpu.run();
  }
  while(!digitalRead(pinBotao)){
  move(MOTOR_A, 0, 2); //Motor da Esquerda, para o Motor, sentido de rotação
  move(MOTOR_B, 0, 2); //Motor da Direita, a toda velocidade, sentido de rotação
  }
}
