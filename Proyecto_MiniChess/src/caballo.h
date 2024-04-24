#pragma once
#include "pieza.h"

class Caballo :public Pieza
{
public:
	Caballo(int valor) : Pieza(valor) {};
	void MoverCaballo();
};