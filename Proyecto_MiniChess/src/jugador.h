#pragma once
class Jugador
{
private:
	//Turnos 
	bool turno;
	//Puntos que tiene con una lista de cuantas piezas comidas
	int puntos;
	//Estado final del juego
	bool esMaquina;


public:
	Jugador(bool);
	void SetTurno(bool turno);
	bool getTurno();
	void SetEsMaquina(bool esMaquina);
	bool EsMaquina() const;

};
