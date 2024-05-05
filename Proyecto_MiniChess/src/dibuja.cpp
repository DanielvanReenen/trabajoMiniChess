#include "dibuja.h"

void Dibuja::dibujaTablero()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/tablero.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex2f(-1, -1);
	glTexCoord2d(1, 1); glVertex2f(1, -1);
	glTexCoord2d(1, 0); glVertex2f(1, 1);
	glTexCoord2d(0, 0); glVertex2f(-1, 1);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

}

void Dibuja::CasillasaCoordenadas()
{
	int k = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			coordenadaenTablero[k].x = (0.93 - 0.23 * i);
			coordenadaenTablero[k].y = (-0.675 + 0.23 * j);
			k++;
		}
	}
	//El incremento correcto es de 0.23
}

void Dibuja::dibujaTorre(int col, int cas)
{
	color = col;
	posicion = coordenadaenTablero[cas];
	

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

void Dibuja::dibujaCaballo(int col, int cas)
{
	color = col;
	posicion = coordenadaenTablero[cas];


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

void Dibuja::dibujaAlfil(int col, int cas)
{
	color = col;
	posicion = coordenadaenTablero[cas];
	

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

void Dibuja::dibujaRey(int col, int cas)
{
	color = col;
	posicion = coordenadaenTablero[cas];
	

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

void Dibuja::dibujaReina(int col, int cas)
{
	color = col;
	posicion = coordenadaenTablero[cas];
	

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


void Dibuja::dibujaPeon(int col, int cas)
{
	color = col;
	posicion = coordenadaenTablero[cas];
	

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



void Dibuja::dibujaPiezas(ListaPiezas piezas) {
	sprite1.setSize(0.25, 0.25);
	sprite7.setSize(0.25, 0.25);
	sprite2.setSize(0.25, 0.25);
	sprite8.setSize(0.25, 0.25);
	sprite3.setSize(0.25, 0.25);
	sprite9.setSize(0.25, 0.25);
	sprite4.setSize(0.25, 0.25);
	sprite10.setSize(0.25, 0.25);
	sprite5.setSize(0.25, 0.25);
	sprite11.setSize(0.25, 0.25);
	sprite6.setSize(0.25, 0.25);
	sprite12.setSize(0.25, 0.25);


	dibujaTorre(piezas.getPieza(0)->color, piezas.getPieza(0)->casilla);
	dibujaTorre(piezas.getPieza(1)->color, piezas.getPieza(1)->casilla);
	dibujaCaballo(piezas.getPieza(2)->color, piezas.getPieza(2)->casilla);
	dibujaCaballo(piezas.getPieza(3)->color, piezas.getPieza(3)->casilla);
	dibujaAlfil(piezas.getPieza(4)->color, piezas.getPieza(4)->casilla);
	dibujaAlfil(piezas.getPieza(5)->color, piezas.getPieza(5)->casilla);
	dibujaRey(piezas.getPieza(6)->color, piezas.getPieza(6)->casilla);
	dibujaReina(piezas.getPieza(7)->color, piezas.getPieza(7)->casilla);
		
	for (int i = 8; i < 16; i++) {
		dibujaPeon(piezas.getPieza(i)->color, piezas.getPieza(i)->casilla);
	}
		
	dibujaTorre(piezas.getPieza(16)->color, piezas.getPieza(16)->casilla);
	dibujaTorre(piezas.getPieza(17)->color, piezas.getPieza(17)->casilla);
	dibujaCaballo(piezas.getPieza(18)->color, piezas.getPieza(18)->casilla);
	dibujaCaballo(piezas.getPieza(19)->color, piezas.getPieza(19)->casilla);
	dibujaAlfil(piezas.getPieza(20)->color, piezas.getPieza(20)->casilla);
	dibujaAlfil(piezas.getPieza(21)->color, piezas.getPieza(21)->casilla);
	dibujaRey(piezas.getPieza(22)->color, piezas.getPieza(22)->casilla);
	dibujaReina(piezas.getPieza(23)->color, piezas.getPieza(23)->casilla);

	for (int i = 23; i < 32; i++) {
		dibujaPeon(piezas.getPieza(i)->color, piezas.getPieza(i)->casilla);
	}
	
}