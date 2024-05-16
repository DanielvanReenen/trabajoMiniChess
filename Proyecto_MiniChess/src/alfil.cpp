#include "alfil.h"

Alfil::Alfil(Coordenada pos, int col, int columna_, int fila_)
{
	posicion = pos;
	color = col;
	columna = columna_;
	fila = fila_;
}

void Alfil::dibujaPieza()
{

	sprite3.setSize(0.25, 0.25);
	sprite9.setSize(0.25, 0.25);

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

vector<Casilla> Alfil::getMovimientosPermitidos() const {
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