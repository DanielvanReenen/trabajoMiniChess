#include "rey.h"

Rey::Rey(Coordenada pos, int col, int columna_, int fila_)
{
	posicion = pos;
	color = col;
	columna = columna_;
	fila = fila_;
}

void Rey::dibujaPieza()
{
	sprite4.setSize(0.25, 0.25);
	sprite10.setSize(0.25, 0.25);

	if (color == 0) {
		sprite4.setCenter(posicion.x, posicion.y);

		glPushMatrix();
		sprite4.draw();
		glPopMatrix();
	}

	if (color == 1) {
		sprite10.setCenter(posicion.x, posicion.y);

		glPushMatrix();
		sprite10.draw();
		glPopMatrix();
	}

}

vector<Casilla> Rey::getMovimientosPermitidos() const {
    vector<Casilla> movimientos;
    // Movimientos posibles del rey (una casilla en cualquier dirección)
    int direcciones[8][2] = {
        {1, 0}, {1, 1}, {0, 1}, {-1, 1},
        {-1, 0}, {-1, -1}, {0, -1}, {1, -1}
    };

    for (auto& dir : direcciones) {
        int nuevaFila = fila + dir[0];
        int nuevaColumna = columna + dir[1];
		movimientos.push_back( Casilla{ nuevaColumna, nuevaFila });

    }

    return movimientos;
}
