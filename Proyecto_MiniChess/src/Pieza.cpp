#include "Pieza.h"
#include<iostream>

Pieza::Pieza() {}

void Pieza::dibujar() {}

Coordenada Pieza::getPosiscion() { 
	return posicion; 
}

int getCasilla() { 
	return casilla; 
}

int getTipo() { 
	return tipo; 
}

int getColor() {
	return color; 
}

void Pieza::mover(Coordenada coorddestino) {
	posicion.x = coorddestino.x;
	posicion.y = coorddestino.y;
}

void Pieza::setCasilla(int nuevacasilla) {
	casilla = nuevacasilla;
}