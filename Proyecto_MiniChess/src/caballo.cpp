#include "caballo.h"

Caballo::Caballo(Coordenada pos, int col, int columna_, int fila_)
{
	posicion = pos;
	color = col;
	columna = columna_;
	fila = fila_;
}

void Caballo::dibujaPieza()
{
	sprite2.setSize(0.25, 0.25);
	sprite8.setSize(0.25, 0.25);

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

vector<Casilla> Caballo::getMovimientosPermitidos() const { //TODO ESTO HAY QUE CAMBIARLO
	vector<Casilla> movimientos;

	// Definir todos los posibles movimientos del caballo en forma de L
	const int movimientosPosibles[8][2] = {
		{2, 1}, {2, -1}, {-2, 1}, {-2, -1},
		{1, 2}, {1, -2}, {-1, 2}, {-1, -2}
	};

	for (const auto& movimiento : movimientosPosibles) {
		int nuevaFila = fila + movimiento[0];
		int nuevaColumna = columna + movimiento[1];

		// Verificar que la nueva posición esté dentro de los límites del tablero
		if (nuevaFila >= 0 && nuevaFila < 8 && nuevaColumna >= 0 && nuevaColumna < 8) {
			movimientos.push_back(Casilla{ nuevaColumna, nuevaFila });
		}
	}

	return movimientos;
}