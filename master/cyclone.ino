#include <Motor.h>

Move walk(3,4,5,9,7,8);
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

int last = 0;

boolean dire = true; // True -> frente| False -> tras

boolean cond = false; // Viu alguma algo, ou nao

unsigned long zeit = 0;

boolean sloth (boolean FrTr, int wohin){
  
 if(FrTr == true){
     if((wohin)>150){
        for(int i = 0 ; i<3;i++){
          zeit = millis(); 
          while((millis()-zeit)<95){
            walk.left(150);
            if(analogRead(pinFront) > 300 ){
              return;
            }
          }
          zeit = millis(); 
          while((millis()-zeit)<95){
            walk.right(150);
            if(analogRead(pinFront) > 300 ){
              return;
            }
          }
        }
    }
    else{
      while(analogRead(pinEsq) < 300 || analogRead(pinDir) < 300 || 
    analogRead(pinTras) < 300 || analogRead(pinFront) < 300){
      walk.front(200);
    }
    return;
    }
 }

 
  else{
     if((wohin)>150){
        for(int i = 0 ; i<3;i++){
          zeit = millis(); 
          while((millis()-zeit)<95){
            walk.left(150);
            if(analogRead(pinTras) > 300 ){
              return;
            }
          }
          zeit = millis(); 
          while((millis()-zeit)<95){
            walk.right(150);
            if(analogRead(pinTras) > 300 ){
              return;
            }
          }
        }
    }
     else{
      while(analogRead(pinEsq) < 300 || analogRead(pinDir) < 300 || 
    analogRead(pinTras) < 300 || analogRead(pinFront) < 300){
      walk.back(200);
    }
    return;
    }
 }
}
          
void setup() {
  pinMode(Led_Azul, OUTPUT);
  pinMode(Led_Vermelho, OUTPUT);
  pinMode(A6, INPUT);
  pinMode(A7, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A0, INPUT);
  pinMode(A4, OUTPUT);
  pinMode(pinBot, INPUT);
  pinMode(6, OUTPUT);
  digitalWrite(A4, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(Led_Vermelho, HIGH);
  // PARA DEBUG
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  walk.brake();
  digitalWrite(Led_Azul, LOW);
  while(!digitalRead(pinBot)){
    Serial.println("Wait");
    delay(10);
  }
  digitalWrite(Led_Azul, HIGH);
  delay(2000);
  
  while(!digitalRead(pinBot)){
    
    while(analogRead(pinFront) > 300 ){ // enquanto ele vê alguma 
      last = analogRead(pinFront);      // coisa na frente dele
      walk.front(200);                  // ele vai para frente
      cond = true;
      Serial.println("vi frente");
      delay(10);
    }
    
    while(analogRead(pinTras) > 300 ){  // enquanto ele vê alguma
      last = analogRead(pinTras);  // coisa na tras dele
      walk.back(200);                   // ele vai para tras
      cond = true;
      Serial.println("vi tras");
      delay(10);
    }
      if(cond){ // Se ele entrou em um dos pontos cegos do Sensor IF
        sloth(dire, last);
      }
    cond = !cond;
  }
  if(analogRead(pinEsq)>300){
      walk.left(200);
      delay(195); // determinar valor pra girar certo
  }
  else if(analogRead(pinDir)>300){
      walk.right(200);
      delay(195); // determinar valor pra girar certo
  }
  }
