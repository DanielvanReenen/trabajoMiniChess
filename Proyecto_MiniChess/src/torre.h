#pragma once
#include "pieza.h"

class Torre :public Pieza
{
public:
	Torre(int valor) : Pieza(valor) {};	
	Torre(Coordenada pos, int col, int fila_, int columna_);

	void dibujaPieza() override;
	TipoPieza getTipo() const override { return TipoPieza::Torre; }
	//void MoverTorre();
};