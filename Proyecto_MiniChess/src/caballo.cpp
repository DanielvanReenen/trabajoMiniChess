#include "caballo.h"
Caballo::Caballo(Coordenada pos, int col)
{
	sprite2.setSize(0.25, 0.25);
	sprite8.setSize(0.25, 0.25);
	posicion = pos;
	color = col;
	
}

void Caballo::dibujaPieza()
{
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
