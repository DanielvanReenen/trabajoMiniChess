#pragma once
#include "pieza.h"

class Rey :public Pieza
{
public:
	Rey(int valor) : Pieza(valor) {};
	Rey(int col, int cas);
	//void MoverRey();
};

