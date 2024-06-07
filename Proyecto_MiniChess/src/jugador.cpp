#include "jugador.h"

Jugador::Jugador(bool turno)
{
	this->turno = turno; //empiezan blancas
	this->puntos = 0;
	this->esMaquina = false;
}

void Jugador::SetTurno(bool turno)
{
	this->turno = turno;
}

bool Jugador::getTurno()
{
	return turno;
}

void Jugador::SetEsMaquina(bool esMaquina) {
	this->esMaquina = esMaquina;
}

bool Jugador::EsMaquina() const {
	return esMaquina;
}
