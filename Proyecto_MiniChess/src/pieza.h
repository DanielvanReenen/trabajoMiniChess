#pragma once
#include"freeglut.h"
#include"ETSIDI.h"
#include"Coordenada.h"
#include"pieza.h"
#include <vector>
#include "casilla.h"


using ETSIDI::SpriteSequence;
using std::vector;

enum class TipoPieza { Torre, Caballo, Alfil, Rey, Reina, Peon, Ninguno };

class Pieza
{
protected:
	int valorNumerico = 0;
	int color;
	int fila;
	int nuevaFilaGravitatoria;
	int columna;
	Coordenada posicion;
	Coordenada velocidad = { 0, 0.5 };
	Coordenada aceleracion = { 0,0 };
	SpriteSequence sprite1{ "imagenes/TorreJedi.png",1 };
	SpriteSequence sprite2{ "imagenes/CaballoJedi.png",1 };
	SpriteSequence sprite3{ "imagenes/AlfilJedi.png",1 };
	SpriteSequence sprite4{ "imagenes/ReyJedi.png",1 };
	SpriteSequence sprite5{ "imagenes/ReinaJedi.png",1 };
	SpriteSequence sprite6{ "imagenes/PeonJedi.png",1 };
	SpriteSequence sprite7{ "imagenes/TorreSith.png",1 };
	SpriteSequence sprite8{ "imagenes/CaballoSith.png",1 };
	SpriteSequence sprite9{ "imagenes/AlfilSith.png",1 };
	SpriteSequence sprite10{ "imagenes/ReySith.png",1 };
	SpriteSequence sprite11{ "imagenes/ReinaSith.png",1 };
	SpriteSequence sprite12{ "imagenes/PeonSith.png",1 };

public:
	Pieza();
	Pieza(int valor) : valorNumerico(valor) {};
	~Pieza();
	virtual void dibujaPieza();
	virtual TipoPieza getTipo() const = 0; // Método virtual para obtener el tipo de pieza
	virtual vector<Casilla> getMovimientosPermitidos() const = 0; // Método virtual para obtener movimientos permitidos


	//Pieza getPieza();
	void MoverPieza();
	void ComerPieza();
	int getColor();
	int getFila();
	int getColumna();
	void setFila(int fila_);
	void setColumna(int columna_);
	void setPosicion(Coordenada posicion_);
};
/*
class Vacio :public Pieza
{
public:
	Vacio(int valor) : Pieza(valor) {};
	Vacio(Coordenada pos, int col, int fila_, int columna_) { posicion = pos, color = col; fila = fila_; columna = columna_; }
	void dibujaPieza() {};

};
*/