#include "torre.h"

Torre::Torre(Coordenada posicion, int color, int fila, int columna, const Tablero& tablero)
    : Pieza(color, color == 0 ? "imagenes/TorreJedi.png" : "imagenes/TorreSith.png"), tablero(tablero) {
    this->posicion = posicion;
    this->fila = fila;
    this->columna = columna;
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
vector<Casilla> Torre::getMovimientosPermitidos(int filaActual, int columnaActual, bool turnoBlancas) const {
    vector<Casilla> movimientos;
    int direcciones[4][2] = {
        {0, 1},   // Movimiento hacia la derecha
        {0, -1},  // Movimiento hacia la izquierda
        {-1, 0},  // Movimiento hacia arriba
        {1, 0}    // Movimiento hacia abajo
    };

    for (auto& dir : direcciones) {
        int nuevaFila = filaActual + dir[0];
        int nuevaColumna = columnaActual + dir[1];

        // Verificar que la nueva posición está dentro del tablero
        while (nuevaFila >= 0 && nuevaFila < 8 && nuevaColumna >= 0 && nuevaColumna < 8) {
            // Verificar si hay una pieza en el camino
            if (tablero.casillaOcupada(nuevaFila, nuevaColumna)) {
                // Si la casilla está ocupada por una pieza del oponente, se puede mover allí
                if (tablero.hayPiezaOponente(nuevaFila, nuevaColumna, turnoBlancas)) {
                    movimientos.push_back(Casilla{ nuevaColumna, nuevaFila });
                }
                // En cualquier caso, el alfil no puede pasar a través de esta casilla
                break;
            }
            // Si la casilla está vacía, se puede mover allí
            movimientos.push_back(Casilla{ nuevaColumna, nuevaFila });
            nuevaFila += dir[0];
            nuevaColumna += dir[1];
        }
    }

    return movimientos;
}
