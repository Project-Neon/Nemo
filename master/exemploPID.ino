// vou usar um D 
// Fazer thread do PID?

double D = 0;
double lastdist;
double dist;

double kD = 1 ; // Achar melhor valor para definir aproximação 

void setup() {

}

void loop() {
  dist = map(analogRead(pIR), 0, 1023, 4 , 70); 
  D = (dist - lastdist)*kD ;
  // Como integrar os 4 sensores ?
  if (D < 50){ // definir valor de interesse
    // Acionar os motores ( melhor acionar apenas 1 motor? Acionar os dois motores? - Fazer testes) 
    analogWrite(pMotor, D);
  }
  lastdist = dist;
}
