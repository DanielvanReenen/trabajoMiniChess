#pragma once
#include "freeglut.h"
#include "ETSIDI.h"
#include "Coordenada.h"
#include "casilla.h"
#include <vector>

using ETSIDI::SpriteSequence;
using std::vector;

class Tablero; // Forward declaration

enum class TipoPieza { Torre, Caballo, Alfil, Rey, Reina, Peon, Ninguno };

class Pieza {
protected:
    int color;
    int fila;
    int columna;
    Coordenada posicion;
    SpriteSequence sprite;

public:
    bool seleccionActivada = false;

    Pieza(int col, const char* spritePath);
    virtual ~Pieza();
    virtual void dibujaPieza() = 0;
    virtual TipoPieza getTipo() const = 0;
    virtual vector<Casilla> getMovimientosPermitidos(int filaActual, int columnaActual, bool turnoBlancas) const = 0;

    int getColor() const;
    int getFila() const;
    int getColumna() const;
    void setFila(int fila_);
    void setColumna(int columna_);
    void setPosicion(Coordenada posicion_);
    Coordenada getPosicion();
    void DibujarSeleccion();
};
