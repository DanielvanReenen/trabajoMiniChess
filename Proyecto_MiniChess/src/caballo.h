#pragma once
#include "pieza.h"

class Caballo :public Pieza
{
public:
	Caballo(int valor) : Pieza(valor) {};
	Caballo(int col, int cas);
	//void MoverCaballo();
};