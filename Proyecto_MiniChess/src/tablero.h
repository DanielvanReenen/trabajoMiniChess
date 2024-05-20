#pragma once
#include<iostream>
#include<vector>
#include "pieza.h"
#include "Coordenada.h"
#include "torre.h"
#include "caballo.h"
#include "alfil.h"
#include "rey.h"
#include "reina.h"
#include "peon.h"
#include "selector.h"


using namespace std;

class Tablero {
	friend Pieza;
	friend class Selector;

public:

	vector<vector<Pieza*>>casillas;
	//vector<Pieza*> lp;
	bool finalJuego = false;
	Coordenada coordenadaSobreTablero[64];
	Selector selector{};
	
public:
	Tablero();
	~Tablero();
	void dibuja();
	void CasillasaCoordenadas();
	void inicializaTablero();
	void dibujaPieza();
	void selectorRaton(int x, int y);
	void aplicarGravedad();

	Pieza* getPieza(int columna, int fila);
	
};


