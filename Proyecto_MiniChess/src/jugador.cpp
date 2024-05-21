#include "jugador.h"

Jugador::Jugador(bool turno)
{
	this->turno = turno; //empiezan blancas
	this->puntos = 0;
}

void Jugador::SetTurno(bool turno)
{
	if (turno = true) {
		turno = false;
	}
	else if (turno =false) {
		turno = true; 
	}
}
