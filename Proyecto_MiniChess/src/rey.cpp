#include "rey.h"
Rey::Rey(Coordenada pos, int col)
{
	sprite4.setSize(0.25, 0.25);
	sprite10.setSize(0.25, 0.25);
	posicion = pos;
	color = col;
	
}

void Rey::dibujaPieza()
{
	if (color == 0) {
		sprite4.setCenter(posicion.x, posicion.y);

		glPushMatrix();
		sprite4.draw();
		glPopMatrix();
	}

	if (color == 1) {
		sprite10.setCenter(posicion.x, posicion.y);

		glPushMatrix();
		sprite10.draw();
		glPopMatrix();
	}

}
