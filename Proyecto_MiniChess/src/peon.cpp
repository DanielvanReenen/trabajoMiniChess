#include "peon.h"

Peon::Peon(Coordenada posicion, int color, int fila, int columna, const Tablero& tablero)
    : Pieza(color, color == 0 ? "imagenes/PeonJedi.png" : "imagenes/PeonSith.png"), tablero(tablero) {
    this->posicion = posicion;
    this->fila = fila;
    this->columna = columna;
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

TipoPieza Peon::getTipo() const {
    return TipoPieza::Peon;
}

vector<Casilla> Peon::getMovimientosPermitidos(int filaActual, int columnaActual, bool turnoBlancas) const {
    vector<Casilla> movimientos;
    int direccion = turnoBlancas ? 1 : -1;

    // Movimiento hacia adelante
    int nuevaFila = filaActual + direccion;
    if (nuevaFila >= 0 && nuevaFila < 8) {
        if (!tablero.casillaOcupada(nuevaFila, columnaActual)) {
            movimientos.push_back(Casilla{ columnaActual, nuevaFila });
            if ((filaActual == 1 && turnoBlancas) || (filaActual == 6 && !turnoBlancas)) {
                nuevaFila += direccion;
                if (!tablero.casillaOcupada(nuevaFila, columnaActual)) {
                    movimientos.push_back(Casilla{ columnaActual, nuevaFila });
                }
            }
        }
    }

    // Captura en diagonal
    int nuevaColumna = columnaActual - 1;
    if (nuevaColumna >= 0 && nuevaFila >= 0 && nuevaFila < 8 && tablero.casillaOcupada(nuevaFila, nuevaColumna) && tablero.hayPiezaOponente(nuevaFila, nuevaColumna, turnoBlancas)) {
        movimientos.push_back(Casilla{ nuevaColumna, nuevaFila });
    }
    nuevaColumna = columnaActual + 1;
    if (nuevaColumna < 8 && nuevaFila >= 0 && nuevaFila < 8 && tablero.casillaOcupada(nuevaFila, nuevaColumna) && tablero.hayPiezaOponente(nuevaFila, nuevaColumna, turnoBlancas)) {
        movimientos.push_back(Casilla{ nuevaColumna, nuevaFila });
    }

    return movimientos;
}
