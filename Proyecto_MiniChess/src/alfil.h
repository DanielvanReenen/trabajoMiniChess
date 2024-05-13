#pragma once
#include "pieza.h"

class Alfil :public Pieza
{
public:
	Alfil(int valor) : Pieza(valor) {};
	Alfil(Coordenada pos, int col, int fila_, int columna_);
	//void MoverAlfil();
	void dibujaPieza();
};
