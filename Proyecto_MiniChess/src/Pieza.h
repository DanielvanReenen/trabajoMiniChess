#pragma once
#include<iostream>
#include<vector>
#include "ETSIDI.h"
#include "Coordenada.h"

using namespace std;

enum TipoPieza {Rey, Reina, Alfil, Caballo, Torre, Peon};		//Se va a utilizar una enumeraci�n para distinguir entre los distintos tipos de piezas
enum Color {Blanco, Negro};										//Se va a utilizar una enumeraci�n para distinguir entre los 2 colores

class Pieza {
private:
	int casilla;
	int color;
	int tipo;
	Coordenada posicion;

public:
	Pieza();								//Constructor de selector
	~Pieza();								//Pieza debe tener un destructor ya que los objetos tipo pieza en el ajedrez pueden "comerse" lo que las har�a desaparecer del tablero
	void dibujar();							//M�todo que se encargar� de dibujar cada pieza
	Coordenada getPosiscion();				//M�todo de tipo coordenada que devolver� la posicion en la que se encuentra la pieza
	int getCasilla();						//M�todo que devolver� la casilla de la pieza
	int getTipo();							//M�todo que devolver� el tipo de pieza
	int getColor();							//M�todo que devolver� el color de pieza
	void mover(Coordenada coorddestino);	//M�todo que asignar� la coordenada de destino a la posici�n al mover una pieza	
	void setCasilla(int nuevacasilla);		//M�todo que asignar� la nueva casilla a la que se ha movido la pieza
	
};