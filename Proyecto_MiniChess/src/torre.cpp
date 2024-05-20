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

vector<Casilla> Torre::getMovimientosPermitidos() const {
	vector<Casilla> movimientos;
	// Movimientos posibles de la torre
	int direcciones[4][2] = {
		{0, 1},   // Movimiento hacia arriba 
		{0, -1},  // Movimiento hacia abajo 
		{-1, 0},  // Movimiento hacia la izquierda
		{1, 0}  // Movimiento hacia la derecha
	};

	for (auto& dir : direcciones) {
		int nuevaFila = fila + dir[0];
		int nuevaColumna = columna + dir[1];

		// Verificar que la nueva posición está dentro del tablero
		while (nuevaFila >= 0 && nuevaFila < 8 && nuevaColumna >= 0 && nuevaColumna < 8) {
			movimientos.push_back(Casilla{ nuevaColumna, nuevaFila });
			nuevaFila += dir[0];
			nuevaColumna += dir[1];
		}

	}

	return movimientos;
}