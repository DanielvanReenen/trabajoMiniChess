#include "alfil.h"

Alfil::Alfil(Coordenada pos, int col, int fila_, int columna_) : Pieza(col, col == 0 ? "imagenes/AlfilJedi.png" : "imagenes/AlfilSith.png") {
	setPosicion(pos);
	fila = fila_;
	columna = columna_;
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

vector<Casilla> Alfil::getMovimientosPermitidos() const {
	vector<Casilla> movimientos;
	
	// Movimientos posibles del alfil
	int direcciones[4][2] = {
		
		{1, 1},   // Diagonal hacia arriba a la derecha
		{1, -1},  // Diagonal hacia abajo a la derecha
		{-1, 1},  // Diagonal hacia arriba a la izquierda
		{-1, -1}  // Diagonal hacia abajo a la izquierda 
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