#include "torre.h"

Torre::Torre(Coordenada pos, int col, int fila_, int columna_) : Pieza(col, col == 0 ? "imagenes/TorreJedi.png" : "imagenes/TorreSith.png") {
	setPosicion(pos);
	fila = fila_;
	columna = columna_;
}

void Torre::dibujaPieza() {
	sprite.setSize(0.25, 0.25);

	if (color == 0) {
		sprite.setCenter(posicion.x, posicion.y);

		glPushMatrix();
		sprite.draw();
		glPopMatrix();
	}

	if (color == 1) {
		sprite.setCenter(posicion.x, posicion.y);

		glPushMatrix();
		sprite.draw();
		glPopMatrix();
	}
}

vector<Casilla> Torre::getMovimientosPermitidos(int filaActual, int columnaActualbool, bool turnoBlancas) const {
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