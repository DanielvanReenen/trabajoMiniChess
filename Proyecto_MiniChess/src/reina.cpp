#include "reina.h"

Reina::Reina(Coordenada pos, int col, int columna_, int fila_)
{
	posicion = pos;
	color = col;
	columna = columna_;
	fila = fila_;
}


void Reina::dibujaPieza()
{

	sprite5.setSize(0.25, 0.25);
	sprite11.setSize(0.25, 0.25);

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

vector<Casilla> Reina::getMovimientosPermitidos() const {
	vector<Casilla> movimientos;
	// Movimientos posibles del rey (una casilla en cualquier dirección)
	int direcciones[8][2] = {
		{1, 0}, {1, 1}, {0, 1}, {-1, 1},
		{-1, 0}, {-1, -1}, {0, -1}, {1, -1}
	};

	for (auto& dir : direcciones) {
		int nuevaFila = fila + dir[0];
		int nuevaColumna = columna + dir[1];
		movimientos.push_back(Casilla{ nuevaColumna, nuevaFila });

	}

	return movimientos;
}
