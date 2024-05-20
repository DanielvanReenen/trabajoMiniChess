#include "pieza.h"

Pieza::Pieza()
{
	
}

Pieza::~Pieza()
{

}

void Pieza::dibujaPieza()
{
}

/*Pieza Pieza::getPieza()
{
	Pieza nuevapieza;



	return Pieza(nuevapieza);
}*/


void Pieza::MoverPieza()
{

}

void Pieza::ComerPieza()
{
}

int Pieza::getFila()
{
	return fila;
}

int Pieza::getColumna()
{
	return columna;
}

int Pieza::getColor() {
	return color;
}

void Pieza::setFila(int fila_) 
{
	fila = fila_;
}

void Pieza::setColumna(int columna_)
{
	columna = columna_;
}

void Pieza::setPosicion(Coordenada posicion_)
{
	posicion = posicion_;
}
