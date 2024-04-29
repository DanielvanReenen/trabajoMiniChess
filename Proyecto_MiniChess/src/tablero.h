#pragma once
#include<iostream>
#include<vector>
#include "pieza.h"
#include "Coordenada.h"
#include "listaPiezas.h"

using namespace std;

class Tablero {
private:
	vector<vector<Pieza*>>casillas;
	bool finalJuego = false;

public:
	Tablero();
	ListaPiezas piezas;
	Coordenada coordenadaenTablero[64];
	void dibuja();
	void inicializaTablero();
	void CoordenadasaCasillas();

};

//Comentario prueba
