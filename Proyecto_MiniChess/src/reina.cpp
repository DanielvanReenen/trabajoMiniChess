#include "reina.h"
Reina::Reina(Coordenada pos, int col)
{
	sprite5.setSize(0.25, 0.25);
	sprite11.setSize(0.25, 0.25);
	posicion = pos;
	color = col;
	
}

void Reina::dibujaPieza()
{
	if (color == 0) {
		sprite5.setCenter(posicion.x, posicion.y);

		glPushMatrix();
		sprite5.draw();
		glPopMatrix();
	}

	if (color == 1) {
		sprite11.setCenter(posicion.x, posicion.y);

		glPushMatrix();
		sprite11.draw();
		glPopMatrix();
	}

}
