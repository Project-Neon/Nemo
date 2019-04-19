
#ifndef SENSORES_H
#define SENSORES_H
#include "_config.h"
#include <EEPROM.h>
class Sensores{
public:
	static int values[4];
	static int Norte_min;
	static int Norte_max;
	static int Oeste_min;
	static int Oeste_max;
	static int Sul_min;
	static int Sul_max;
	static int Leste_min;
	static int Leste_max;

//inicializa os sensores, ligando-os e puxando os valores de
//calibração da EEPROM
	static void init();
	//Armazena valores de 4 a 20 no array de values[Norte,Oeste,Sul,Leste]
	//Se o valor estiver fora do valor esperado o valor armazenado é NULL
	static void update();
	int getNor();
	int getOes();
	int getSul();
	int getLes();
};
#endif