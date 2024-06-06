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

Coordenada Pieza::getPosicion()
{
    return posicion;
}

void Pieza::DibujarSeleccion() {
    float Sel_x = posicion.x - 0.125;
    float Sel_y = posicion.y - 0.14;
    // Configurar el color para que sea semitransparente (blanco con alfa)
    glColor4f(1.0, 1.0, 1.0, 0.5); // Color blanco semitransparente

    // Dibujar el c�rculo
    glPushMatrix();
    glTranslatef(Sel_x, Sel_y, 0.1); // Transladar al centro del c�rculo
    GLUquadric* qobj = gluNewQuadric();
    gluDisk(qobj, 0, 0.1, 50, 1); // Dibujar un disco con radio y 100 subdivisiones
    gluDeleteQuadric(qobj);
    glPopMatrix();
}