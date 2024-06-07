#include "rey.h"

Rey::Rey(Coordenada posicion, int color, int fila, int columna, const Tablero& tablero)
	: Pieza(color, color == 0 ? "imagenes/ReyJedi.png" : "imagenes/ReySith.png"), tablero(tablero) {
	this->posicion = posicion;
	this->fila = fila;
	this->columna = columna;
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

vector<Casilla> Rey::getMovimientosPermitidos(int filaActual, int columnaActual, bool turnoBlancas) const {
    vector<Casilla> movimientos;

    // Movimientos posibles del rey (una casilla en cualquier dirección)
    const int direcciones[8][2] = {
        {1, 0}, {0, 1}, {-1, 0}, {0, -1}, // Horizontales y verticales
        {1, 1}, {1, -1}, {-1, 1}, {-1, -1} // Diagonales
    };

    for (auto& dir : direcciones) {
        int nuevaFila = filaActual + dir[0];
        int nuevaColumna = columnaActual + dir[1];

        // Verificar que la nueva posición está dentro del tablero
        if (nuevaFila >= 0 && nuevaFila < 8 && nuevaColumna >= 0 && nuevaColumna < 8) {
            // Verificar si la casilla está ocupada
            if (tablero.casillaOcupada(nuevaFila, nuevaColumna)) {
                // Si la casilla está ocupada por una pieza del oponente, se puede mover allí
                if (tablero.hayPiezaOponente(nuevaFila, nuevaColumna, turnoBlancas)) {
                    movimientos.push_back(Casilla{ nuevaColumna, nuevaFila });
                }
            }
            else {
                // Si la casilla está vacía, se puede mover allí
                movimientos.push_back(Casilla{ nuevaColumna, nuevaFila });
            }
        }
    }
    return movimientos;
}
