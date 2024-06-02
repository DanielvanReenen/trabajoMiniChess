#pragma once
#include "freeglut.h"
#include "ETSIDI.h"
#include "Coordenada.h"
#include "casilla.h"
#include <vector>
#include "tablero.h"

using ETSIDI::SpriteSequence;
using std::vector;

enum class TipoPieza { Torre, Caballo, Alfil, Rey, Reina, Peon, Ninguno };

class Pieza
{
protected:
    int color;
    int fila;
    int nuevaFilaGravitatoria;
    int columna;
    Coordenada posicion;
    SpriteSequence sprite;

public:
    Pieza(int col, const char* spritePath);
    virtual ~Pieza();
    virtual void dibujaPieza() = 0;
    virtual TipoPieza getTipo() const = 0;
    virtual vector<Casilla> getMovimientosPermitidos(int filaActual, int columnaActualbool, bool turnoBlancas) const = 0;

    void MoverPieza();
    void ComerPieza();
    int getColor();
    int getFila();
    int getColumna();
    void setFila(int fila_);
    void setColumna(int columna_);
    void setPosicion(Coordenada posicion_);
};
