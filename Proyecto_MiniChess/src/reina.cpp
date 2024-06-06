#include "reina.h"

Reina::Reina(Coordenada posicion, int color, int fila, int columna, const Tablero& tablero)
	: Pieza(color, color == 0 ? "imagenes/ReinaJedi.png" : "imagenes/ReinaSith.png"), tablero(tablero) {
	this->posicion = posicion;
	this->fila = fila;
	this->columna = columna;
}

void Reina::dibujaPieza() {
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

vector<Casilla> Reina::getMovimientosPermitidos(int filaActual, int columnaActualbool, bool turnoBlancas) const {
	vector<Casilla> movimientos;
	// Movimientos posibles de la reina (una casilla en cualquier dirección)
    const int direcciones[8][2] = {
		//Explicadas en la torre y el alfil
		//Filas y columnas
            {1, 0}, {0, 1}, {-1, 0}, {0, -1},
		//Diagonales
            {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
    };

 for (auto& dir : direcciones) {
        int nuevaFila = filaActual + dir[0];
        int nuevaColumna = columnaActualbool + dir[1];

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
