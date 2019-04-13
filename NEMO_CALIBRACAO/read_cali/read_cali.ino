#include <EEPROM.h>
void setup(){
	Serial.begin(9600);
	Serial.println("Os valores na EEPROM são: ");
	for(int i=0;i<8;i++){
	byte value = EEPROM.read(i);
	Serial.print(i);
	Serial.print(" ");
	Serial.println(value);
	delay(100);
	}
}
void loop(){
	
}
