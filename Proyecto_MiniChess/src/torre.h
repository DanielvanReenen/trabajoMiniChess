#pragma once
#include "pieza.h"

class Torre :public Pieza
{
public:
	Torre(int valor) : Pieza(valor) {};	
	Torre(int col, int cas);
	//void MoverTorre();
};