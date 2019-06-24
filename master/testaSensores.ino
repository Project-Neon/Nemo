#define pinBot                  A5 

// pinos analogicos dos sensores Refletancia
#define SRF                    A6 
#define SRT                    A7 

// pinos analogicos dos sensores UF
// Ver se de fato estão nos pinos certos 
#define pinFront               A3 
#define pinDir                 A2
#define pinEsq                 A1 
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

void setup() {
  // CONFIGURACAO DOS PINOS USADOS
  pinMode(Led_Azul, OUTPUT);
  pinMode(Led_Vermelho, OUTPUT);

  // PARA DEBUG
  Serial.begin(115200);

}

void loop() {
  
  Serial.println("infravermelho frontal");
  delay(200);
  while(!digitalRead(pinBot)){
    Serial.println(analogRead(pinFront)); 
    delay(100);
  }
  
  Serial.println("infravermelho direita");
  delay(200);
  while(!digitalRead(pinBot)){
    Serial.println(analogRead(pinDir)); 
    delay(100);
  }

  Serial.println("infravermelho esquerda");
  delay(200);
  while(!digitalRead(pinBot)){
    Serial.println(analogRead(pinEsq)); 
    delay(100);
  }

  Serial.println("infravermelho traseiro");
  delay(200);
  while(!digitalRead(pinBot)){
    Serial.println(analogRead(pinTras)); 
    delay(100);
  }

  
  Serial.println("Refletância Frete");
  delay(200);
  while(!digitalRead(pinBot)){
    Serial.println(analogRead(SRF)); 
    delay(100);
  }

  
  Serial.println("Refletância Tras");
  delay(200);
  while(!digitalRead(pinBot)){
    Serial.println(analogRead(SRT)); 
    delay(100);
  }
  
}
