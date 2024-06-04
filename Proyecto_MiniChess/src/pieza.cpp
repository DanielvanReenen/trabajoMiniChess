#include "pieza.h"

Pieza::Pieza(int col, const char* spritePath) : color(col), sprite(spritePath,1) {}

Pieza::~Pieza() {}

int Pieza::getColor() const {
    return color;
}

int Pieza::getFila() const {
    return fila;
}

int Pieza::getColumna() const {
    return columna;
}

void Pieza::setFila(int fila_) {
    fila = fila_;
}

void Pieza::setColumna(int columna_) {
    columna = columna_;
}

void Pieza::setPosicion(Coordenada posicion_) {
    posicion = posicion_;
}
