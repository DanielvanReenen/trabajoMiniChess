#pragma once
#include "Coordenada.h"
#include "casilla.h"
#include "pieza.h"


//class Tablero;

class Selector
{
	friend class Tablero;
private:
	Casilla casOrigen;
	Casilla casDestino;
	Pieza* piezaSeleccionada = nullptr;
public:
	Selector();
	int getFila();
	int getColumna();
	void raton(int x, int y, Tablero& tablero);
	void origen();
	Pieza* getPiezaSeleccionada() const;


	//primer pixel de casilla = 30
	//ultimo pixel de casilla = 120,625
};

