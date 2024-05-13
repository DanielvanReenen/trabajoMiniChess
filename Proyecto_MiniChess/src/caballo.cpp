#include "caballo.h"

Caballo::Caballo(Coordenada pos, int col, int columna_, int fila_)
{
	posicion = pos;
	color = col;
	columna = columna_;
	fila = fila_;
}

void Caballo::dibujaPieza()
{
	sprite2.setSize(0.25, 0.25);
	sprite8.setSize(0.25, 0.25);

	if (color == 0) {
		sprite2.setCenter(posicion.x, posicion.y);

		glPushMatrix();
		sprite2.draw();
		glPopMatrix();
	}

	if (color == 1) {
		sprite8.setCenter(posicion.x, posicion.y);

		glPushMatrix();
		sprite8.draw();
		glPopMatrix();
	}
}
