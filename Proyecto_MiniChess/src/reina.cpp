#include "reina.h"

Reina::Reina(Coordenada pos, int col, int fila_, int columna_) : Pieza(col, col == 0 ? "imagenes/ReinaJedi.png" : "imagenes/ReinaSith.png") {
    setPosicion(pos);
    fila = fila_;
    columna = columna_;
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

vector<Casilla> Reina::getMovimientosPermitidos() const {
	vector<Casilla> movimientos;
	// Movimientos posibles de la reina (una casilla en cualquier dirección)
    const int direcciones[8][2] = {
		//Explicadas en la torre y el alfil
		//Filas y columnas
            {1, 0}, {0, 1}, {-1, 0}, {0, -1},
		//Diagonales
            {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
    };

    for (const auto& dir : direcciones) {
        int nuevaFila = fila;
        int nuevaColumna = columna;

		// Verificar que la nueva posición está dentro del tablero
		while (nuevaFila >= 0 && nuevaFila < 8 && nuevaColumna >= 0 && nuevaColumna < 8) {
   
		movimientos.push_back(Casilla{ nuevaColumna, nuevaFila });
		nuevaFila += dir[0];
		nuevaColumna += dir[1];

		}
    }

    return movimientos;
}
