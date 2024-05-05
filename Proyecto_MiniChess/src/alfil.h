#pragma once
#include "pieza.h"

class Alfil :public Pieza
{
public:
	Alfil(int valor) : Pieza(valor) {};
	Alfil(int col, int cas);
	//void MoverAlfil();
};
