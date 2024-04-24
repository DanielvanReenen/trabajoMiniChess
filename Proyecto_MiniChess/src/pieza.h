#pragma once
#include"freeglut.h"
#include"ETSIDI.h"

using ETSIDI::SpriteSequence;

class Pieza
{
private:
	int valorNumerico;

	SpriteSequence sprite1{ "imagenes/AlfilJedi.png",1 };
	SpriteSequence sprite2{ "imagenes/CaballoJedi.png",1 };
	SpriteSequence sprite3{ "imagenes/PeonJedi.png",1 };
	SpriteSequence sprite4{ "imagenes/ReinaJedi.png",1 };
	SpriteSequence sprite5{ "imagenes/ReyJedi.png",1 };
	SpriteSequence sprite6{ "imagenes/TorreJedi.png",1 };
	SpriteSequence sprite7{ "imagenes/AlfilSith.png",1 };
	SpriteSequence sprite8{ "imagenes/CaballoSith.png",1 };
	SpriteSequence sprite9{ "imagenes/PeonSith.png",1 };
	SpriteSequence sprite10{ "imagenes/ReinaSith.png",1 };
	SpriteSequence sprite11{ "imagenes/ReySith.png",1 };
	SpriteSequence sprite12{ "imagenes/TorreSith.png",1 };

public:
	Pieza() ;
	Pieza(int valor) : valorNumerico(valor) {};
	~Pieza();
	int dibujaPieza();
	/*Pieza getPieza();*/
	void setPieza();
	void MoverPieza();
	void ComerPieza();
};

class Vacio :public Pieza
{
public:
	Vacio(int valor) : Pieza(valor) {};
};
