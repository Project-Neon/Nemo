//LER ANTES DE CALIBRAR
//ESSE PROGRAMA CALIBRA 4 SENSORES E GUARDA SEUS VALORES MIN E MAX DENTRO DA EEPROM DO ARDUINO, OU SEJA, 
//GUARDA 8 VALORES NAS MEMORIAS DE 0 A 7 PARA FUTURA REFERÊNCIA
//INSTRUÇÕES:
//PRIMEIRO SE COLOCA ALGO PERTO DO SENSOR NUMERO 1 E APERTA O BOTAO, ESPERA-SE 2 SEGUNDOS, E COLOCA 
//ALGO NA DISTANCIA MAXIMA DO SENSOR E APERTA NOVAMENTE O BOTÃO
//SE REPETE ESSE PROCEDIMENTO PARA OS 4 SENSORES
//CASO QUEIRA VER QUE VALORES ESTÃO SENDO GUARDADOS, DEIXAR O ARDUINO CONECTADO COM O PC E ABRA A PORTA SERIAL NO IDE DO ARDUINO
//APOS OS 8 VALORES SEREM GUARDADOS PODE-SE DESLIGAR O ARDUINO E USAR ESSES VALORES EM OUTRO PROGRAMA COM
// A FUNÇÃO EEPROM.read(Address) ONDE O ADDRESS É UM NUMERO INTEIRO DE 0 A 7
#include <EEPROM.h>
#define botao A5
#define SensorNorte A0
#define SensorOeste A1
#define SensorSul A2
#define SensorLeste A3
#define LedAzul 10
#define LedVermelho 2
#define GPIO_sensores A4
int Address = 0;
int sensor = 0;
int valor_sensor;
void setup(){
	Serial.begin(9600);
	pinMode(botao,INPUT);
	pinMode(LedAzul,OUTPUT);
	pinMode(LedVermelho,OUTPUT);
	digitalWrite(A4,HIGH);
}
void loop(){
//Switch statement para selecionar qual sensor deve ser lido no momento
	switch(sensor/2){
			case 0:
				valor_sensor = analogRead(SensorNorte)/4;
				break;
			case 1:
				valor_sensor = analogRead(SensorOeste)/4;
				break;
			case 2:
				valor_sensor = analogRead(SensorSul)/4;
				break;
			case 3:
				valor_sensor = analogRead(SensorLeste)/4;
				break;
		}
	if(digitalRead(botao) == HIGH && Address <=7){
		Serial.println("AQUI");
//Dividido por 4 pois o byte da EEPROM só armazena valores de 0 a 255 e os valores analogicos são de 0 a 1023
		EEPROM.write(Address, valor_sensor);
		sensor++;
		Address++;
//delay para impedir que um unico aperto de botao faça duas leituras;
		Serial.println(String(valor_sensor) + " gravado em "+ String(Address));
		delay(2000);
	}
	else{
		if (Address > 7){
		Serial.println("Calibracao encerrada");
	}
		else {
//Se ainda existem sensores a serem calibrados
			Serial.println("--Aperte para gravar "+ String(valor_sensor) + " no Address "+ String(Address));
		}
	
	}
	
}