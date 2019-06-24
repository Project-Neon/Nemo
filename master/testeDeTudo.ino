unsigned long tem = 0;

#define SRF 39 //Sensor Refletancia Frontal
#define SRT 34 //Sensor Refletancia Traseiro

// pinos analogicos dos sensores UF
#define pinFront 35
#define pinDir 32
#define pinEsq 33
#define pinTras 25

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

#define pinBot 36

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

}

void loop() {
  if(!digitalRead(pinBot)){

    // 0101
    inPin1 = LOW;
    inPin2 = HIGH;
    digitalWrite(AIN1, inPin1); // 0101
    digitalWrite(AIN2, inPin2);
    analogWrite(PWMA , 255);
    digitalWrite(BIN1, inPin1);
    digitalWrite(BIN2, inPin2);
    analogWrite(PWMB , 255);

// 0110
    inPin1 = LOW;
    inPin2 = HIGH;
    digitalWrite(AIN1, inPin1); // 0110
    digitalWrite(AIN2, inPin2);
    analogWrite(PWMA, 255);
    digitalWrite(BIN1, !inPin1);
    digitalWrite(BIN2, !inPin2);
    analogWrite(PWMB , 255);

// 1010
    inPin1 = HIGH;
    inPin2 = LOW;
    digitalWrite(AIN1, inPin1); // 1010
    digitalWrite(AIN2, inPin2);
    analogWrite(PWMA , 255);
    digitalWrite(BIN1, inPin1);
    digitalWrite(BIN2, inPin2);
    analogWrite(PWMB , 255);

// 1001
    inPin1 = HIGH;
    inPin2 = LOW;
    digitalWrite(AIN1, inPin1); // 1001
    digitalWrite(AIN2, inPin2);
    analogWrite(PWMA , 255);
    digitalWrite(BIN1, !inPin1);
    digitalWrite(BIN2, !inPin2);
    analogWrite(PWMB, 255);
  }

  // Testar sensor if front
    Serial.println("Testar if front longe");        // Implementar millis
    delay(500);
    tem = millis();
    while((millis()-tem>1000)){
      Serial.println(analogRead(pinFront)); 
      delay(50);
    }
    Serial.println("Testar if front perto");
    delay(500);
    tem = millis();
    while((millis()-tem>1000)){
      Serial.println(analogRead(pinFront));
      delay(50);
    }

    Serial.println("Testar if dir longe");          
    delay(500);
    tem = millis();
    while((millis()-tem>1000)){
      Serial.println(analogRead(pinDir));
      delay(50);
    }

    Serial.println("Testar if dir perto");          
    delay(500);
    tem = millis();
    while((millis()-tem>1000)){
      Serial.println(analogRead(pinDir));
      delay(50);
    }
    Serial.println("Testar if esq longe");            
    delay(500);
    tem = millis();
    while((millis()-tem>1000)){
      Serial.println(analogRead(pinEsq));
      delay(50);
    }

    Serial.println("Testar if esq perto");            
    delay(500);
    tem = millis();
    while((millis()-tem>1000)){
      Serial.println(analogRead(pinDir));
      delay(50);
    }
    
    Serial.println("Testar if tras longe");            
    delay(500);
    tem = millis();
    while((millis()-tem>1000)){
      Serial.println(analogRead(pinTras));
      delay(50);
    }

    
    Serial.println("Testar if tras perto");            
    delay(500);
    tem = millis();
    while((millis()-tem>1000)){
      Serial.println(analogRead(pinTras));
      delay(50);
    }

    Serial.println("Testar refletância tras colocar no preto"); // implementar millis
    delay(500);
    tem = millis();
    while((millis()-tem>1000)){
    Serial.println(analogRead(SRT));
    delay(10);
    }
    Serial.println("Testar refletância tras colocar no branco");
    delay(1000);
    Serial.println(analogRead(SRT));
    delay(1000);

    Serial.println("Testar refletância front colocar no preto");  // implementar millis
    delay(1000);
    Serial.println(analogRead(SRF));
    delay(1000);
    Serial.println("Testar refletância front colocar no branco"); 
    delay(1000);
    Serial.println(analogRead(SRF));
    delay(1000);
}
