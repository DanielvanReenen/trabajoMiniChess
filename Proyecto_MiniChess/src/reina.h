#pragma once
#include "pieza.h"

class Reina :public Pieza
{
public:
	Reina(int valor) : Pieza(valor) {};
	Reina(Coordenada pos, int col, int fila_, int columna_);
	//void MoverReina();
	void dibujaPieza();
};

