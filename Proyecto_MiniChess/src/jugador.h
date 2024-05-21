#pragma once
class Jugador
{
private:
	//Turnos 
	bool turno;
	//Puntos que tiene con una lista de cuantas piezas comidas
	int puntos;
	//Estado final del juego


public: 
	Jugador(bool);
	void SetTurno(bool turno);

};

