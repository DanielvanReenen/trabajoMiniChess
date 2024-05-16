#pragma once
#include "pieza.h"

class Caballo :public Pieza
{
public:
	Caballo(int valor) : Pieza(valor) {};
	Caballo(Coordenada pos, int col, int fila_, int columna_);
	//void MoverCaballo();
	void dibujaPieza() override;
	TipoPieza getTipo() const override { return TipoPieza::Caballo; }
	vector<Casilla> getMovimientosPermitidos() const override; //Vector con las casillas permitidas por las restricciones de movimiento
};