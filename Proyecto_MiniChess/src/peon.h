#pragma once
#include "pieza.h"

class Peon :public Pieza
{
public:
	Peon(int valor) : Pieza(valor) {};
	void moverPeon();
	void comerPeon();
};

