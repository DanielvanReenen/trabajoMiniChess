#pragma once
#include<iostream>
#include<vector>
#include "pieza.h"

using namespace std;

class Tablero {
public:
	Tablero();
	vector<vector<Pieza>>casillas;
	bool finalJuego = false;

public:
	void dibuja();
	void creaTablero();
	void segundafuncionprueba();
	void funcionpruebaJavier();
	void tercerafuncionpruebaguille();
	//HOLA COMO ESTAMOS
};
