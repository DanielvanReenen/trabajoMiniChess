#pragma once
#include "pieza.h"

class Rey :public Pieza
{
public:
	Rey(int valor) : Pieza(valor) {};
	Rey(Coordenada pos, int col, int fila_, int columna_);
	//void MoverRey();
	void dibujaPieza() override;
	TipoPieza getTipo() const override { return TipoPieza::Rey; }
};

