/*

   tornado.ino
   
   Autor: Project Neon - Felipe Andrade
   Março de 2010


*/


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
#define Led_Azul               2
#define Led_Vermelho           10 

////Motor A
#define PIN_M1_EN              3
#define PIN_M1_IN1             4
#define PIN_M1_IN2             5

////Motor B
#define PIN_M2_EN              9
#define PIN_M2_IN1             7
#define PIN_M2_IN2             8

boolean cond = false;
int vel = 150;
void frente(){
  digitalWrite(PIN_M1_IN1, LOW);
  digitalWrite(PIN_M1_IN2, HIGH);
  analogWrite(PIN_M1_EN, vel );
  digitalWrite(PIN_M2_IN1, HIGH);
  digitalWrite(PIN_M2_IN2, LOW);
  analogWrite(PIN_M2_EN, vel );
  Serial.println("frente");
}

void back(){ // ok
  digitalWrite(PIN_M1_IN1, HIGH);
  digitalWrite(PIN_M1_IN2, LOW);
  analogWrite(PIN_M1_EN, vel );
  digitalWrite(PIN_M2_IN1, LOW);
  digitalWrite(PIN_M2_IN2, HIGH);
  analogWrite(PIN_M2_EN, vel );
  Serial.println("back");
}

void esquerda(){ // ok
  digitalWrite(PIN_M1_IN1, LOW);
    digitalWrite(PIN_M1_IN2, HIGH);
    analogWrite(PIN_M1_EN, vel );
    digitalWrite(PIN_M2_IN1, LOW);
    digitalWrite(PIN_M2_IN2, HIGH);
    analogWrite(PIN_M2_EN, vel );
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

void brake(){ // ok
   digitalWrite(PIN_M1_IN1, HIGH);
   digitalWrite(PIN_M1_IN2, HIGH);
   analogWrite(PIN_M1_EN, 0);
   digitalWrite(PIN_M2_IN1, HIGH);
   digitalWrite(PIN_M2_IN2, HIGH);
   analogWrite(PIN_M2_EN, 0);
   Serial.println("brake");
   
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
  digitalWrite(Led_Vermelho, HIGH);
  // PARA DEBUG
  Serial.begin(115200);


}
int dire = 0;
void loop() {
  brake();
  digitalWrite(Led_Azul, LOW);
  while(!digitalRead(pinBot)){
    delay(10);
  }
  digitalWrite(Led_Azul, HIGH);
  delay(1000);
  while(!digitalRead(pinBot)){
  if(analogRead(pinFront)>300){
      frente();
      dire = 0;
      cond = true;
      Serial.println("vi frente");
      delay(50);
  }
  else if(analogRead(pinTras)>300){
      back();
      dire = 1;
      cond = true;
      Serial.println("Atras");
      delay(50);
      
  }
  
  if(cond){
    while(analogRead(pinEsq) > 300 || analogRead(pinDir) > 300 || 
    analogRead(pinTras) > 300 || analogRead(pinFront) > 300){
       if(dire == 0){
        frente();
        delay(100);
       }
       else{
        back();
        delay(100);
       }
    }
    cond = !cond;
  }
  if(analogRead(pinEsq)>300){
      esquerda();
      delay(100); // determinar valor pra girar certo
  }
  else if(analogRead(pinDir)>300){
      direita();
      delay(100); // determinar valor pra girar certo
  }
  }
}
