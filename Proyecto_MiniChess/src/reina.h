#pragma once
#include "pieza.h"

class Reina :public Pieza
{
public:
	Reina(int valor) : Pieza(valor) {};
	Reina(Coordenada pos, int col);
	void dibujaPieza();
	//void MoverReina();
};

