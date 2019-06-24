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
void frente(int picollo){
  digitalWrite(PIN_M1_IN1, LOW);
  digitalWrite(PIN_M1_IN2, HIGH);
  analogWrite(PIN_M1_EN, picollo);
  digitalWrite(PIN_M2_IN1, HIGH);
  digitalWrite(PIN_M2_IN2, LOW);
  analogWrite(PIN_M2_EN, picollo);
  
}

void back(int picollo){ // ok
  digitalWrite(PIN_M1_IN1, HIGH);
  digitalWrite(PIN_M1_IN2, LOW);
  analogWrite(PIN_M1_EN, picollo);
  digitalWrite(PIN_M2_IN1, LOW);
  digitalWrite(PIN_M2_IN2, HIGH);
  analogWrite(PIN_M2_EN, picollo);
  
}

void esquerda(int pistola){ // ok
  digitalWrite(PIN_M1_IN1, LOW);
    digitalWrite(PIN_M1_IN2, HIGH);
    analogWrite(PIN_M1_EN, pistola );
    digitalWrite(PIN_M2_IN1, LOW);
    digitalWrite(PIN_M2_IN2, HIGH);
    analogWrite(PIN_M2_EN, pistola );
  
 }

void direita(int pistola){ // ok
    digitalWrite(PIN_M1_IN1, HIGH);
    digitalWrite(PIN_M1_IN2, LOW);
    analogWrite(PIN_M1_EN, pistola);
    digitalWrite(PIN_M2_IN1, HIGH);
    digitalWrite(PIN_M2_IN2, LOW);
    analogWrite(PIN_M2_EN, pistola);
  
}
void brake(){ // ok
   digitalWrite(PIN_M1_IN1, HIGH);
   digitalWrite(PIN_M1_IN2, HIGH);
   analogWrite(PIN_M1_EN, 0);
   digitalWrite(PIN_M2_IN1, HIGH);
   digitalWrite(PIN_M2_IN2, HIGH);
   analogWrite(PIN_M2_EN, 0);
    
}

void sRefletancia(int luz,int STX){
  if(luz < 300) agir(STX);
  else return;
}

void agir(int STX){
  if(STX == 0){ // 0 para o traseiro
    frente(200);
    delay(100);
    return;
  } 
    back(200);// 0 para o traseiro
    delay(100); 
  
}
void continueANadar(int dire){
  if(dire == 0){
    while(analogRead(pinEsq) > 300 || analogRead(pinDir) > 300 || 
    analogRead(pinTras) > 300 || analogRead(pinFront) > 300){    
     frente(150);
     delay(100);
     sRefletancia(analogRead(SRT),0);   // 0 para o traseiro // 1 para o frontal 
     sRefletancia(analogRead(SRF),1);
       }
  }
  else{
    while(analogRead(pinEsq) > 300 || analogRead(pinDir) > 300 || 
    analogRead(pinTras) > 300 || analogRead(pinFront) > 300){    
     back(150);
     delay(100);
     sRefletancia(analogRead(SRT),0);   // 0 para o traseiro // 1 para o frontal 
       sRefletancia(analogRead(SRF),1);
    }
       }
}


void setup() {
  // put your setup code here, to run once:
  pinMode(Led_Azul, OUTPUT);
  pinMode(Led_Vermelho, OUTPUT);
  pinMode(A6, INPUT);
  pinMode(A7, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A0, INPUT);
  pinMode(PIN_M1_IN1, OUTPUT);
  pinMode(PIN_M1_IN2, OUTPUT);
  pinMode(PIN_M1_EN, OUTPUT);
  pinMode(PIN_M2_IN1, OUTPUT);
  pinMode(PIN_M2_IN2, OUTPUT);
  pinMode(PIN_M2_EN, OUTPUT);
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
    Serial.println("Wait");
    delay(10);
  }
  digitalWrite(Led_Azul, HIGH);
  delay(1000);

  
  while(!digitalRead(pinBot)){
  sRefletancia(analogRead(SRT),0);   // 0 para o traseiro // 1 para o frontal 
 
  sRefletancia(analogRead(SRF),1);
 
  if(analogRead(pinFront)>300){
      frente(150);
      dire = 0;
      cond = true;
      Serial.println("vi frente");
      delay(50);
  }
  else if(analogRead(pinTras)>300){
      back(150);
      dire = 1;
      cond = true;
      Serial.println("Atras");
      delay(50);
      
  }
  sRefletancia(analogRead(SRT),0);   // 0 para o traseiro // 1 para o frontal 
 
  sRefletancia(analogRead(SRF),1);
  
  if(cond){
    /*
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
       sRefletancia(analogRead(SRT),0);   // 0 para o traseiro // 1 para o frontal 
       sRefletancia(analogRead(SRF),1);
    } */
    continueANadar(dire);
    delay(5);
    cond = !cond;
  }
  sRefletancia(analogRead(SRT),0);   // 0 para o traseiro // 1 para o frontal 
  sRefletancia(analogRead(SRF),1);
  if(analogRead(pinEsq)>300){
      esquerda(150);
      dire = 0;
      Serial.println("Esquerda");
      delay(195); // determinar valor pra girar certo
  }
  else if(analogRead(pinDir)>300){
      direita(150);
      dire = 1;
      Serial.println("direita");
      delay(195); // determinar valor pra girar certo
  }
  else{
    if(dire == 1){
      direita(97);
      Serial.println("procura direita");
      delay(195); // determinar valor pra girar certo
    }
    else{
      direita(97);
      Serial.println("procura esquerda");
      delay(195); // determinar valor pra girar certo
    }
  sRefletancia(analogRead(SRT),0);   // 0 para o traseiro // 1 para o frontal 
 
  sRefletancia(analogRead(SRF),1);
  }
  }
}
