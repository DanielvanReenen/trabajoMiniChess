#pragma once
#include"freeglut.h"
#include"ETSIDI.h"
#include"Coordenada.h"

using ETSIDI::SpriteSequence;

class Pieza
{
public:
	int valorNumerico;
	int color;
	int casilla;

public:
	Pieza();
	Pieza(int valor) : valorNumerico(valor) {};
	~Pieza();
	//Pieza getPieza();
	//void setPieza();
	void MoverPieza();
	void ComerPieza();
};

class Vacio :public Pieza
{
public:
	Vacio(int valor) : Pieza(valor) {};
};
