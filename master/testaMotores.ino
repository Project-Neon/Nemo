////Motor A
#define PIN_M1_EN              3
#define PIN_M1_IN1             4
#define PIN_M1_IN2             5


////Motor B
#define PIN_M2_EN              9
#define PIN_M2_IN1             7
#define PIN_M2_IN2             8

void frente(){
  digitalWrite(PIN_M1_IN1, HIGH);
  digitalWrite(PIN_M1_IN2, LOW);
  analogWrite(PIN_M1_EN, 70);
  digitalWrite(PIN_M2_IN1, HIGH);
  digitalWrite(PIN_M2_IN2, LOW);
  analogWrite(PIN_M2_EN, 70);
}

void back(){
  digitalWrite(PIN_M1_IN1, LOW);
  digitalWrite(PIN_M1_IN2, HIGH);
  analogWrite(PIN_M1_EN, 70);
  digitalWrite(PIN_M2_IN1, LOW);
  digitalWrite(PIN_M2_IN2, HIGH);
  analogWrite(PIN_M2_EN, 70);
}

void esquerda(){
  digitalWrite(PIN_M1_IN1, HIGH);
  digitalWrite(PIN_M1_IN2, LOW);
  analogWrite(PIN_M1_EN, 130);
  digitalWrite(PIN_M2_IN1, LOW);
  digitalWrite(PIN_M2_IN2, HIGH);
  analogWrite(PIN_M2_EN, 130);
}

void direita(){
  digitalWrite(PIN_M1_IN1, LOW);
  digitalWrite(PIN_M1_IN2, HIGH);
  analogWrite(PIN_M1_EN, 130);
  digitalWrite(PIN_M2_IN1, HIGH);
  digitalWrite(PIN_M2_IN2, LOW);
  analogWrite(PIN_M2_EN, 130);
}

void brake(){
  digitalWrite(PIN_M1_IN1, HIGH);
  digitalWrite(PIN_M1_IN2, HIGH);
  analogWrite(PIN_M1_EN, 0);
  digitalWrite(PIN_M2_IN1, HIGH);
  digitalWrite(PIN_M2_IN2, HIGH);
  analogWrite(PIN_M2_EN, 0);
}

void setup() {
  // CONFIGURACAO DOS PINOS USADOS
  pinMode(PIN_M1_EN, OUTPUT);
  pinMode(PIN_M1_IN1, OUTPUT);
  pinMode(PIN_M1_IN2, OUTPUT);
  
  pinMode(PIN_M2_EN, OUTPUT);
  pinMode(PIN_M2_IN1, OUTPUT);
  pinMode(PIN_M2_IN2, OUTPUT);

  // PARA DEBUG
  Serial.begin(115200);
  
}

void loop() {
  frente();
  delay(1000);
  back();
  delay(1000);
  esquerda();
  delay(1000);
  direita();
  delay(1000);
}
