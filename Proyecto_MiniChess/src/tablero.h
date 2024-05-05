#pragma once
#include<iostream>
#include<vector>
#include "pieza.h"
#include "Coordenada.h"
#include "listaPiezas.h"
#include "dibuja.h"

using namespace std;

class Tablero {
private:
	vector<vector<Pieza*>>casillas;
	//vector<Pieza*> lp;
	bool finalJuego = false;
	

public:
	ListaPiezas piezas;
	Tablero();
	void dibuja();
	void inicializaTablero();

};

//Comentario prueba
