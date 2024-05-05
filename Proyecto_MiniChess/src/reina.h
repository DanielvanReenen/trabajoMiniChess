#pragma once
#include "pieza.h"

class Reina :public Pieza
{
public:
	Reina(int valor) : Pieza(valor) {};
	Reina(int col, int cas);
	//void MoverReina();
};

