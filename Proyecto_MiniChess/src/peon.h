#pragma once
#include "pieza.h"

class Peon :public Pieza
{
public:
	Peon(int valor) : Pieza(valor) {};
	Peon(Coordenada pos, int col, int fila_, int columna_);
	//void comerPeon();
	void dibujaPieza() override;
	TipoPieza getTipo() const override { return TipoPieza::Peon; }
	vector<Casilla> getMovimientosPermitidos() const override; //Vector con las casillas permitidas por las restricciones de movimiento
};

