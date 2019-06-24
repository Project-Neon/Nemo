#define pinBot                  A5 

// pinos analogicos dos sensores Refletancia
#define SRF                    A6 
#define SRT                    A7 

// pinos analogicos dos sensores UF
// Ver se de fato estão nos pinos certos 
#define pinFront               A1 
#define pinDir                 A2
#define pinEsq                 A3 
#define pinTras                A0 


// pinos dos leds
#define Led_Azul               10 
#define Led_Vermelho           2 

////Motor A
#define PIN_M1_EN              3
#define PIN_M1_IN1             4
#define PIN_M1_IN2             5

////Motor B
#define PIN_M2_EN              9
#define PIN_M2_IN1             7
#define PIN_M2_IN2             8

void brake(){ // ok
   digitalWrite(PIN_M1_IN1, HIGH);
   digitalWrite(PIN_M1_IN2, HIGH);
   analogWrite(PIN_M1_EN, 0);
   digitalWrite(PIN_M2_IN1, HIGH);
   digitalWrite(PIN_M2_IN2, HIGH);
   analogWrite(PIN_M2_EN, 0);
   Serial.println("brake");
   
}

void esquerda(){ // ok
  digitalWrite(PIN_M1_IN1, LOW);
    digitalWrite(PIN_M1_IN2, HIGH);
    analogWrite(PIN_M1_EN, 150 );
    digitalWrite(PIN_M2_IN1, LOW);
    digitalWrite(PIN_M2_IN2, HIGH);
    analogWrite(PIN_M2_EN, 150 );
    Serial.println("esquerda");
 }

void direita(){ // ok
    digitalWrite(PIN_M1_IN1, HIGH);
    digitalWrite(PIN_M1_IN2, LOW);
    analogWrite(PIN_M1_EN, 150 );
    digitalWrite(PIN_M2_IN1, HIGH);
    digitalWrite(PIN_M2_IN2, LOW);
    analogWrite(PIN_M2_EN, 150 );
    Serial.println("direita");
}
  
void setup() {
  // put your setup code here, to run once:
  pinMode(Led_Azul, OUTPUT);
  pinMode(Led_Vermelho, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(pinBot, INPUT);
  pinMode(6, OUTPUT);
  digitalWrite(A4, HIGH);
  digitalWrite(6, HIGH);

  // PARA DEBUG
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(Led_Azul, LOW);
  delay(1000);
  while(!digitalRead(pinBot)){
    Serial.println("Wait");
    delay(10);
  }
  digitalWrite(Led_Azul, HIGH);
  delay(1000);
  while(!digitalRead(pinBot)){
    Serial.println("let it rip");
    esquerda();
    delay(190);
    brake();
    delay(3000);
  }
}
