#pragma once
#include "pieza.h"

class Reina :public Pieza
{
public:
	Reina(int valor) : Pieza(valor) {};
	void MoverReina();
};

