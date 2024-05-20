#include "reina.h"

Reina::Reina(Coordenada pos, int col, int columna_, int fila_)
{
	posicion = pos;
	color = col;
	columna = columna_;
	fila = fila_;
}


void Reina::dibujaPieza()
{

	sprite5.setSize(0.25, 0.25);
	sprite11.setSize(0.25, 0.25);

	if (color == 0) {
		sprite5.setCenter(posicion.x, posicion.y);

		glPushMatrix();
		sprite5.draw();
		glPopMatrix();
	}

	if (color == 1) {
		sprite11.setCenter(posicion.x, posicion.y);

		glPushMatrix();
		sprite11.draw();
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
