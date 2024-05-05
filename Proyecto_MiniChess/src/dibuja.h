#pragma once

#include"freeglut.h"
#include"ETSIDI.h"
#include"tablero.h"
#include"pieza.h"
#include"listaPiezas.h"
#include"torre.h"
#include<vector>

using ETSIDI::SpriteSequence;

class Dibuja
{
protected:
	Coordenada posicion;
	int color;

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
	void dibujaTablero();
	void dibujaTorre(int col, int cas);
	void dibujaCaballo(int col, int cas);
	void dibujaAlfil(int col, int cas);
	void dibujaRey(int col, int cas);
	void dibujaReina(int col, int cas);
	void dibujaPeon(int col, int cas);
	void dibujaPiezas(ListaPiezas piezas);
	void CasillasaCoordenadas();

	Coordenada coordenadaenTablero[64];
};

