#pragma once
#include "pieza.h"

class Peon :public Pieza
{
public:
	Peon(int valor) : Pieza(valor) {};
	Peon(Coordenada pos, int col);
	void dibujaPieza();
	//void moverPeon();
	//void comerPeon();
};

