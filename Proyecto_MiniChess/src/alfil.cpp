#include "alfil.h"

Alfil::Alfil(Coordenada pos, int col)
{
	sprite3.setSize(0.25, 0.25);
	sprite9.setSize(0.25, 0.25);
	posicion = pos;
	color = col;
	
}

void Alfil::dibujaPieza()
{
	if (color == 0) {
		sprite3.setCenter(posicion.x, posicion.y);

		glPushMatrix();
		sprite3.draw();
		glPopMatrix();
	}

	if (color == 1) {
		sprite9.setCenter(posicion.x, posicion.y);

		glPushMatrix();
		sprite9.draw();
		glPopMatrix();
	}

}
