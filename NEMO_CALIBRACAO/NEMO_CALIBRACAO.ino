
#include "Sensores.h"
void setup(){
	Sensores::init();
	Serial.begin(9600);
}

void loop(){
	Sensores::update();
	for(int i = 0; i<4 ; i++){
		Serial.print("Sensor:");
		Serial.println(i);
		Serial.println(Sensores::values[i]);
	}
	delay(1000);
}