#pragma once
#include "pieza.h"

class Torre :public Pieza
{
public:
	Torre(int valor) : Pieza(valor) {};
	Torre(Coordenada pos, int col);
	void dibujaPieza();
	//void inicializa();												
	//void MoverTorre();
};