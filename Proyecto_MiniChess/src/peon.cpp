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

vector<Casilla> Peon::getMovimientosPermitidos(int filaActual, int columnaActual, bool turnoBlancas) const {
    vector<Casilla> movimientos;
    int direccion;
    if (turnoBlancas) {
        direccion = 1; // Blancos avanzan hacia derecha (positiva)
    }
    else {
        direccion = -1; // Negros avanzan hacia izquierda (negativa)
    }

    int movimientoDoble = 0;
    if (turnoBlancas) 
    {
        if (columnaActual == 1) 
        {
            movimientoDoble = 1;
            movimientos.push_back(Casilla{ columnaActual + direccion + movimientoDoble, filaActual });
        }
        movimientos.push_back(Casilla{ columnaActual + direccion, filaActual });
    }
    else
    {
        if (columnaActual == 6) 
        {
            movimientoDoble = -1;
            movimientos.push_back(Casilla{ columnaActual + direccion + movimientoDoble, filaActual });
        }

        movimientos.push_back(Casilla{ columnaActual + direccion, filaActual });

    }
    return movimientos;
}