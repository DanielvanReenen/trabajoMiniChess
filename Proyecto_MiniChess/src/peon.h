#pragma once
#include "pieza.h"

class Peon :public Pieza
{
public:
	Peon(int valor) : Pieza(valor) {};
	Peon(Coordenada pos, int col, int fila_, int columna_);
	//void moverPeon();
	//void comerPeon();
	void dibujaPieza();
};

