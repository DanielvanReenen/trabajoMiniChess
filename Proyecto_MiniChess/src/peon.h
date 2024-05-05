#pragma once
#include "pieza.h"

class Peon :public Pieza
{
public:
	Peon(int valor) : Pieza(valor) {};
	Peon(int col, int cas);
	//void moverPeon();
	//void comerPeon();
};

