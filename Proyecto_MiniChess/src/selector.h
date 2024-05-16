#pragma once
#include "Coordenada.h"
#include "casilla.h"
#include "pieza.h"


//class Tablero;

class Selector
{
	friend class Tablero;
private:
	Casilla casSeleccion;
	Casilla casOrigen;
	Casilla casDestino;
	Pieza* piezaSeleccionada = nullptr;
	Pieza* piezaOrigen = nullptr;
	Pieza* piezaDestino = nullptr;
	bool seleccionActiva = false;
	bool movimientoActivado = false;
	int colorjugador = 0;

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

