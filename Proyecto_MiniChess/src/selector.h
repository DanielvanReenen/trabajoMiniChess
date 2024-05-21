#pragma once
#include "Coordenada.h"
#include "casilla.h"
#include "pieza.h"
#include <chrono>
#include <thread>
#include "jugador.h"

using namespace std::this_thread;
using namespace std::chrono;



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
	Jugador jugador1;
	Jugador jugador2;
	bool seleccionActiva = false;
	bool movimientoActivado = false;
	int colorjugador = 0;
	bool turnos(bool turno);
	
public:
	Selector();
	int getFila();
	int getColumna();
	void raton(int x, int y, Tablero& tablero);
	void origen();
	Pieza* getPiezaSeleccionada() const;
};

