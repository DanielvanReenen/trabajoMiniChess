#include "pieza.h"

Pieza::Pieza(int col, const char* spritePath) : color(col), fila(0), columna(0), sprite(spritePath, 1) { sprite.setSize(1, 1); }

Pieza::~Pieza() {}

int Pieza::getColor() {
    return color;
}

int Pieza::getFila() {
    return fila;
}

int Pieza::getColumna() {
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

void Pieza::MoverPieza() {
}

void Pieza::ComerPieza() {
}
