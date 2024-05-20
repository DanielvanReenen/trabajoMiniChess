#pragma once
#include "pieza.h"

class Reina :public Pieza
{
public:
	Reina(int valor) : Pieza(valor) {};
	Reina(Coordenada pos, int col, int fila_, int columna_);

	void dibujaPieza() override;
	TipoPieza getTipo() const override { return TipoPieza::Reina; }
	vector<Casilla> getMovimientosPermitidos() const override; //Vector con las casillas permitidas por las restricciones de movimiento
};

