#pragma once
#include "pieza.h"

class Torre :public Pieza
{
public:
	Torre(int valor) : Pieza(valor) {};
	void inicializa();												
	void MoverTorre();
};