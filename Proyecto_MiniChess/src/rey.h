#pragma once
#include "pieza.h"

class Rey : public Pieza
{
public:
    Rey( int col) : Pieza( col, col == 0 ? "imagenes/ReyJedi.png" : "imagenes/ReySith.png") {}
    Rey(Coordenada pos, int col, int fila_, int columna_);

    void dibujaPieza() override;
    TipoPieza getTipo() const override { return TipoPieza::Rey; }
    vector<Casilla> getMovimientosPermitidos() const override;
};

