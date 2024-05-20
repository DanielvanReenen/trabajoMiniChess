#include "peon.h"

Peon::Peon(Coordenada pos, int col, int columna_, int fila_)
{
	posicion = pos;
	color = col;
	columna = columna_;
	fila = fila_;
}



void Peon::dibujaPieza()
{
	sprite6.setSize(0.25, 0.25);
	sprite12.setSize(0.25, 0.25);

	if (color == 0) {
		sprite6.setCenter(posicion.x, posicion.y);

		glPushMatrix();
		sprite6.draw();
		glPopMatrix();
	}

	if (color == 1) {
		sprite12.setCenter(posicion.x, posicion.y);

		glPushMatrix();
		sprite12.draw();
		glPopMatrix();
	}
}


vector<Casilla> Peon::getMovimientosPermitidos() const {
    vector<Casilla> movimientos;
    int direccion;
    if (color == 0) {
        direccion = 1; // Blancos avanzan hacia derecha (positiva)
    }
    else {
        direccion = -1; // Negros avanzan hacia izquierda (negativa)
    }
    // Movimiento hacia adelante 
    int nuevaColumna = columna + direccion;
    if (nuevaColumna >= 0 && nuevaColumna < 8) {
        movimientos.push_back(Casilla{ nuevaColumna, fila });
    }

    // Movimiento inicial de dos casillas 
    if ((color == 0 && columna == 1) || (color == 1 && columna == 6)) {
        int dobleColumna = columna + 2 * direccion;
        if (dobleColumna >= 0 && dobleColumna < 8) {
            movimientos.push_back(Casilla{ dobleColumna, fila });
        }
    }
    
    // Captura del peon
    /*
    int diagonalArribaFila = fila - 1;
    int diagonalAbajoFila = fila + 1;

    if (diagonalArribaFila >= 0 && nuevaColumna >= 0 && nuevaColumna < 8) {
        movimientos.push_back(Casilla{ nuevaColumna, diagonalArribaFila });
    }

    if (diagonalAbajoFila < 8 && nuevaColumna >= 0 && nuevaColumna < 8) {
        movimientos.push_back(Casilla{ nuevaColumna, diagonalAbajoFila });
    }
    */
    return movimientos;
}