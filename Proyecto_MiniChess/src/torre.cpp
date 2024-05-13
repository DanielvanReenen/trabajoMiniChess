#include "torre.h"

Torre::Torre(Coordenada pos, int col, int columna_, int fila_)
{
	posicion = pos;
	color = col;
	columna = columna_;
	fila = fila_;
	
}

void Torre::dibujaPieza()
{
	sprite1.setSize(0.25, 0.25);
	sprite7.setSize(0.25, 0.25);

	if (color == 0) {
		sprite1.setCenter(posicion.x, posicion.y);

		glPushMatrix();
		sprite1.draw();
		glPopMatrix();
	}

	if (color == 1) {
		sprite7.setCenter(posicion.x, posicion.y);

		glPushMatrix();
		sprite7.draw();
		glPopMatrix();
	}
}