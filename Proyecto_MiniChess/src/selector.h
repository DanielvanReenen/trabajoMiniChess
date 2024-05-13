#pragma once
#include "Coordenada.h"

class Selector
{
private:
	int fila;
	int columna;
	int casillaOriginal;
public:
	Selector();
	int getFila();
	int getColumna();
	void raton(int x, int y);
	void origen();
	//primer pixel de casilla = 30
	//ultimo pixel de casilla = 120,625
};

