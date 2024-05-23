#pragma once
#include "pieza.h"

class Alfil : public Pieza
{
public:
    Alfil( int col) : Pieza( col, col == 0 ? "imagenes/AlfilJedi.png" : "imagenes/AlfilSith.png") {}
    Alfil(Coordenada pos, int col, int fila_, int columna_);

    void dibujaPieza() override;
    TipoPieza getTipo() const override { return TipoPieza::Alfil; }
    vector<Casilla> getMovimientosPermitidos() const override;
};
