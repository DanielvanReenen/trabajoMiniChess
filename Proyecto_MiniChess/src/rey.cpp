#include "rey.h"

Rey::Rey(Coordenada pos, int col, int fila_, int columna_) : Pieza(col, col == 0 ? "imagenes/ReyJedi.png" : "imagenes/ReySith.png") {
	setPosicion(pos);
	fila = fila_;
	columna = columna_;
}

void Rey::dibujaPieza() {
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

vector<Casilla> Rey::getMovimientosPermitidos(int filaActual, int columnaActualbool, bool turnoBlancas) const {
    vector<Casilla> movimientos;

    // Movimientos posibles del rey (una casilla en cualquier dirección)
	const int direcciones[8][2] = {
		//Explicadas en la torre y el alfil
		//filas y columnas
			{1, 0}, {0, 1}, {-1, 0}, {0, -1},
		//diagonales
			{1, 1}, {1, -1}, {-1, 1}, {-1, -1}
	};

	for (const auto& dir : direcciones) {
		int nuevaFila = filaActual + dir[0];
		int nuevaColumna = columnaActualbool + dir[1];
		if (nuevaFila >= 0 && nuevaFila < 8 && nuevaColumna >= 0 && nuevaColumna < 8) {
			movimientos.push_back(Casilla{ nuevaColumna, nuevaFila });
		}
	}

    return movimientos;
}
