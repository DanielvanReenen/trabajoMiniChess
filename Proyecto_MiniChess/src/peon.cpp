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

std::vector<Casilla> Peon::getMovimientosPermitidos(int filaActual, int columnaActual, bool turnoBlancas) const {

    // EL PEON NO TIENE ESTA FUNCIÓN PORQUE NECESITA LA INFORMACIÓN DEL TABLERO
    //Estoy probando cosas con esta funcion por eso da error aqui
}