#include "jugador.h"

Jugador::Jugador(bool turno)
{
	this->turno = turno; //empiezan blancas
	this->puntos = 0;
}

void Jugador::SetTurno(bool turno)
{
	this->turno = turno;
}

bool Jugador::getTurno()
{
	return turno;
}
