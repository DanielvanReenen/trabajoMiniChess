#pragma once
#include<iostream>
#include<vector>
#include "ETSIDI.h"
#include "Coordenada.h"

using namespace std;

enum TipoPieza {Rey, Reina, Alfil, Caballo, Torre, Peon};		//Se va a utilizar una enumeración para distinguir entre los distintos tipos de piezas
enum Color {Blanco, Negro};										//Se va a utilizar una enumeración para distinguir entre los 2 colores

class Pieza {
private:
	int casilla;
	int color;
	int tipo;
	Coordenada posicion;

public:
	Pieza();								//Constructor de selector
	~Pieza();								//Pieza debe tener un destructor ya que los objetos tipo pieza en el ajedrez pueden "comerse" lo que las haría desaparecer del tablero
	void dibujar();							//Método que se encargará de dibujar cada pieza
	Coordenada getPosiscion();				//Método de tipo coordenada que devolverá la posicion en la que se encuentra la pieza
	int getCasilla();						//Método que devolverá la casilla de la pieza
	int getTipo();							//Método que devolverá el tipo de pieza
	int getColor();							//Método que devolverá el color de pieza
	void mover(Coordenada coorddestino);	//Método que asignará la coordenada de destino a la posición al mover una pieza	
	void setCasilla(int nuevacasilla);		//Método que asignará la nueva casilla a la que se ha movido la pieza
	
};