#include "peon.h"
Peon::Peon(Coordenada pos, int col)
{
	sprite6.setSize(0.25, 0.25);
	sprite12.setSize(0.25, 0.25);
	posicion = pos;
	color = col;
	
}

void Peon::dibujaPieza()
{
	if (color == 0) {
		sprite6.setCenter(posicion.x, posicion.y);

		glPushMatrix();
		sprite6.draw();
		glPopMatrix();
	}

	if (color == 1) {
		sprite12.setCenter(posicion.x, posicion.y);

		glPushMatrix();
		sprite12.draw();
		glPopMatrix();
	}

}
