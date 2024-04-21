#include "pieza.h"

Pieza::Pieza()
{
	sprite1.setCenter(0.93, -0.225);
	sprite1.setSize(0.25, 0.25);

	sprite2.setCenter(0.93, -0.45);
	sprite2.setSize(0.25, 0.25);

	sprite6.setCenter(0.93, -0.675);
	sprite6.setSize(0.25, 0.25);

	sprite5.setCenter(0.93, 0.015);
	sprite5.setSize(0.25, 0.25);

	sprite4.setCenter(0.93, 0.245);
	sprite4.setSize(0.25, 0.25);

	sprite3.setCenter(0.7, -0.675);
	sprite3.setSize(0.25, 0.25);

	sprite3.setCenter(-0.68, -0.675);
	sprite3.setSize(0.25, 0.25);

	//El incremento correcto es de 0.23
}

Pieza::~Pieza()
{

}

int Pieza::dibujaPieza()
{
	glPushMatrix();
	glColor3f(1.0f, 0.0f, 0.0f);
	sprite1.draw();
	sprite2.draw();
	sprite6.draw();
	sprite4.draw();
	sprite5.draw();
	sprite3.draw();
	glPopMatrix();

	return valorNumerico;
}
/*
Pieza Pieza::getPieza()
{
	Pieza nuevapieza;



	return Pieza(nuevapieza);
}*/

void Pieza::MoverPieza()
{

}

void Pieza::ComerPieza()
{
}
