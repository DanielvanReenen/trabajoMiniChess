#pragma once
#include "pieza.h"

class Alfil :public Pieza
{
public:
	Alfil(int valor) : Pieza(valor) {};
	Alfil(Coordenada pos, int col, int fila_, int columna_);

	void dibujaPieza() override;
	TipoPieza getTipo() const override { return TipoPieza::Alfil; }
	vector<Casilla> getMovimientosPermitidos() const override; //Vector con las casillas permitidas por las restricciones de movimiento
};
