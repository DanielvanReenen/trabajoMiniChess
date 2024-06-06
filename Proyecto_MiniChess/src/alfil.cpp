#include "alfil.h"


Alfil::Alfil(Coordenada posicion, int color, int fila, int columna, const Tablero& tablero)
    : Pieza(color, color == 0 ? "imagenes/AlfilJedi.png" : "imagenes/AlfilSith.png"), tablero(tablero) {
    this->posicion = posicion;
    this->fila = fila;
    this->columna = columna;
}

void Alfil::dibujaPieza()
{
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

vector<Casilla> Alfil::getMovimientosPermitidos(int filaActual, int columnaActual, bool turnoBlancas) const {
    vector<Casilla> movimientos;
    // Movimientos posibles del alfil
    int direcciones[4][2] = {
        {1, 1},   // Diagonal hacia abajo a la derecha
        {1, -1},  // Diagonal hacia abajo a la izquierda
        {-1, 1},  // Diagonal hacia arriba a la derecha
        {-1, -1}  // Diagonal hacia arriba a la izquierda
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

