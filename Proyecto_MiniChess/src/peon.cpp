#include "peon.h"

Peon::Peon(Coordenada pos, int col, int fila_, int columna_) : Pieza(col, col == 0 ? "imagenes/PeonJedi.png" : "imagenes/PeonSith.png") {
    setPosicion(pos);
    fila = fila_;
    columna = columna_;
}

void Peon::dibujaPieza() {
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

vector<Casilla> Peon::getMovimientosPermitidos(int filaActual, int columnaActualbool, bool turnoBlancas) const {
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