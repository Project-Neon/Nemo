#include <Motor.h>
#include <Sensores.h>
Move walk(3,4,5,9,7,8);
Sensores eyes;
#define pinBot                  A5 

// pinos analogicos dos sensores Refletancia
#define SRF                    A6 
#define SRT                    A7 

// pinos dos leds
#define Led_Azul               2
#define Led_Vermelho           10 

int last = 0;

boolean dire = true; // True -> frente| False -> tras

boolean cond = false; // Viu alguma algo, ou nao

unsigned long zeit = 0;

void sloth (boolean FrTr, int wohin){
  
 if(FrTr == true){
     if((wohin)>6){
        eyes.update();
        zeit = millis(); 
        while((millis()-zeit)<48){
        if(eyes.getNor() != -1 )
          return;
        walk.right(150);         // vira para a direita
        }
        for(int i = 0 ; i<3;i++){ // repete a procura 3 vezes 
          zeit = millis(); 
          while((millis()-zeit)<95){ // usa isso invés de usar o delay
            eyes.update();
            if(eyes.getNor() != -1 ) // se ele ver alguma coisa ele retorna
              return;
            walk.left(150);          // vira para a esquerda
            Serial.println("frente sloth esquerda"); 
          }
          zeit = millis(); 
          while((millis()-zeit)<95){
            eyes.update();
            if(eyes.getNor() != -1 )
              return;
            walk.right(150);         // vira para a direita
            Serial.println("frente sloth direita"); 
          }
        }
        return;
    }
    else{
      while(eyes.getNor() != -1 || eyes.getLes() != -1 || 
    eyes.getSul() != -1 || eyes.getOes() != -1){
      eyes.update();
      walk.front(200);
      Serial.println("Agora vou te matar frente");
    }
    return;
    }
 }

 
  else{
     if((wohin)>6){
        zeit = millis(); 
        while((millis()-zeit)<48){
        eyes.update();
        if(eyes.getNor() != -1 )
          return;
        walk.right(150);         // vira para a direita
        }
        for(int i = 0 ; i<3;i++){
          zeit = millis(); 
          while((millis()-zeit)<95){
            eyes.update();
            if(eyes.getSul() != -1  )
              return;
            walk.left(150);
            Serial.println("tras sloth esquerda");
          }
          zeit = millis(); 
          while((millis()-zeit)<95){
            eyes.update();
            if(eyes.getSul() != -1  )
              return;
            walk.right(150);
            Serial.println("tras sloth direita");
          }
        }
        return;
    }
     else{
      while(eyes.getNor() != -1 || eyes.getLes() != -1 || 
    eyes.getSul() != -1 || eyes.getOes() != -1){
      eyes.update();
      walk.back(200);
      Serial.println("Agora eu vou te matar tras");
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
    eyes.update();
    while( eyes.getNor() != -1){ // enquanto ele vê alguma 
      last = eyes.getNor();      // coisa na frente dele
      walk.front(200);           // ele vai para frente
      cond = true;
      dire = true;
      Serial.println("vi frente");
      delay(10);
    }
    
    while(eyes.getSul() != -1 ){  // enquanto ele vê alguma
      last = eyes.getSul();       // coisa na tras dele
      walk.back(200);             // ele vai para tras
      cond = true;
      dire = false;
      Serial.println("vi tras");
      delay(10);
    }
      if(cond){ // Se ele entrou em um dos pontos cegos do Sensor IF
        sloth(dire, last);
        cond = !cond;
      }
      
  if(eyes.getOes () != -1 && eyes.getSul() == -1 && eyes.getNor() == -1){
      walk.left(200);
      delay(195); // determinar valor pra girar certo
  }
  
  else if(eyes.getLes() != -1 && eyes.getSul() == -1 && eyes.getNor() == -1){
      walk.right(200);
      delay(195); // determinar valor pra girar certo
  }
  }
}
