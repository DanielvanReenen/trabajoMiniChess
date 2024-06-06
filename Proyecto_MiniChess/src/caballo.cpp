#include "caballo.h"

Caballo::Caballo(Coordenada pos, int col, int fila_, int columna_) : Pieza(col, col == 0 ? "imagenes/CaballoJedi.png" : "imagenes/CaballoSith.png") {
	setPosicion(pos);
	fila = fila_;
	columna = columna_;
}

void Caballo::dibujaPieza() {
	sprite.setSize(0.25, 0.25);

	if (color == 0) {
		sprite.setCenter(posicion.x, posicion.y);

		glPushMatrix();
		if (seleccionActivada) {
			DibujarSeleccion();
		}
		sprite.draw();
		glPopMatrix();
	}

	if (color == 1) {
		sprite.setCenter(posicion.x, posicion.y);

		glPushMatrix();
		if (seleccionActivada) {
			DibujarSeleccion();
		}
		sprite.draw();
		glPopMatrix();
	}
}

vector<Casilla> Caballo::getMovimientosPermitidos(int filaActual, int columnaActualbool, bool turnoBlancas) const { //TODO ESTO HAY QUE CAMBIARLO
	vector<Casilla> movimientos;

	// Definir todos los posibles movimientos del caballo en forma de L
	const int movimientosPosibles[8][2] = {
		{2, 1}, {2, -1}, {-2, 1}, {-2, -1},
		{1, 2}, {1, -2}, {-1, 2}, {-1, -2}
	};

	for (const auto& movimiento : movimientosPosibles) {
		int nuevaFila = filaActual + movimiento[0];
		int nuevaColumna = columnaActualbool + movimiento[1];

		// Verificar que la nueva posición esté dentro de los límites del tablero
		if (nuevaFila >= 0 && nuevaFila < 8 && nuevaColumna >= 0 && nuevaColumna < 8) {
			movimientos.push_back(Casilla{ nuevaColumna, nuevaFila });
		}
	}

	return movimientos;
}