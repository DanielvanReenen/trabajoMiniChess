#pragma once
#include "pieza.h"

class Rey :public Pieza
{
public:
	Rey(int valor) : Pieza(valor) {};
	Rey(Coordenada pos, int col);
	void dibujaPieza();
	//void MoverRey();
};

