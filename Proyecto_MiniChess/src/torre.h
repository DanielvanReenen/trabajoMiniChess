#pragma once
#include "pieza.h"

class Torre : public Pieza
{
public:
    Torre(int col) : Pieza(col, col == 0 ? "imagenes/TorreJedi.png" : "imagenes/TorreSith.png") {}
    Torre(Coordenada pos, int col, int fila_, int columna_);

    void dibujaPieza() override;
    TipoPieza getTipo() const override { return TipoPieza::Torre; }
    vector<Casilla> getMovimientosPermitidos() const override;
};
