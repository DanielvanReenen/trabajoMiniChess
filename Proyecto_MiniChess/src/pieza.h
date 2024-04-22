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

class Torre :public Pieza
{
public:
	Torre(int valor) : Pieza(valor) {};
	void inicializa();//													xx
	void MoverTorre();
};

class Caballo :public Pieza
{
public:
	Caballo(int valor) : Pieza(valor) {};
	void MoverCaballo();
};

class Alfil :public Pieza
{
public:
	Alfil(int valor) : Pieza(valor) {};
	void MoverAlfil();
};

class Rey :public Pieza
{
public:
	Rey(int valor) : Pieza(valor) {};
	void MoverRey();
};

class Reina :public Pieza
{
public:
	Reina(int valor) : Pieza(valor) {};
	void MoverReina();
};

class Peon :public Pieza
{
public:
	Peon(int valor) : Pieza(valor) {};
	void moverPeon();
	void comerPeon();
};

class Vacio :public Pieza
{
public:
	Vacio(int valor) : Pieza(valor) {};
};