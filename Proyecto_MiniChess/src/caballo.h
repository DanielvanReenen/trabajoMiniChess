#pragma once
#include "pieza.h"

class Caballo :public Pieza
{
public:
	Caballo(int valor) : Pieza(valor) {};
	Caballo(Coordenada pos, int col);
	void dibujaPieza();
	//void MoverCaballo();
};