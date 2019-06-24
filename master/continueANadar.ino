int freq = 5000;
int resolution = 8;

// Motor Direito
#define BIN1 3   //Modo de operação 
#define BIN2  18 //Modo de operação 
#define PWMB 19  //Controle de Velocidade
#define MOTOR_A 0 // Define motor da direita com valor 1


//Motor Esquerdo 
#define AIN1 5  // Modo de operação 
#define AIN2 17 // Modo de operação 
#define PWMA 16 // Controle de Velocidade
#define MOTOR_B 1 //Define motor da direita com valor 2

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

void setup() {
  // CONFIGURACAO DOS PINOS USADOS
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);

  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);

  // PARA DEBUG
  Serial.begin(115200);

  // CONFIGURACAO DO PWM
  ledcSetup(MOTOR_A, freq, resolution);
  ledcSetup(MOTOR_B, freq, resolution);

  ledcAttachPin(PWMA, MOTOR_A);
  ledcAttachPin(PWMB, MOTOR_B);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  //Andar para frente!
  move(MOTOR_A, 255, 1); //Motor da Esquerda, para o Motor, sentido de rotação
  move(MOTOR_B, 255, 2); //Motor da Direita, a toda velocidade, sentido de rotação
  Serial.println("frente");
  delay(1000);

  // Andar para trás!
  move(MOTOR_A, 255, 2); //Motor da Esquerda, para o Motor, sentido de rotação
  move(MOTOR_B, 255, 1); //Motor da Direita, a toda velocidade, sentido de rotação
  Serial.println("Tras");
  delay(1000);

  // Girar direita!
  move(MOTOR_A, 255, 1); //Motor da Esquerda, para o Motor, sentido de rotação
  move(MOTOR_B, 255, 1); //Motor da Direita, a toda velocidade, sentido de rotação
  Serial.println("direita");
  delay(1000);

  // Girar esquerda!
  move(MOTOR_A, 255, 2); //Motor da Esquerda, para o Motor, sentido de rotação
  move(MOTOR_B, 255, 2); //Motor da Direita, a toda velocidade, sentido de rotação
  Serial.println("Esquerda");
  delay(1000);

  // Stop!
  move(MOTOR_A, 0, 2); //Motor da Esquerda, para o Motor, sentido de rotação
  move(MOTOR_B, 0, 2); //Motor da Direita, a toda velocidade, sentido de rotação
  Serial.println("Stop");
  delay(1000);
}
