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

using namespace std;

class Tablero {
	friend Pieza;
public:
	vector<vector<Pieza*>>casillas;
	//vector<Pieza*> lp;
	bool finalJuego = false;
	Coordenada coordenadaSobreTablero[64];
	
public:
	Tablero();
	void dibuja();
	void CasillasaCoordenadas();
	void inicializaTablero();
	void dibujaPieza();
};

//Comentario prueba
