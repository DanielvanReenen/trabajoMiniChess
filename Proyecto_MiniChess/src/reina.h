#pragma once
#include "pieza.h"

class Reina : public Pieza
{
public:
    Reina( int col) : Pieza( col, col == 0 ? "imagenes/ReinaJedi.png" : "imagenes/ReinaSith.png") {}
    Reina(Coordenada pos, int col, int fila_, int columna_);

    void dibujaPieza() override;
    TipoPieza getTipo() const override { return TipoPieza::Reina; }
    vector<Casilla> getMovimientosPermitidos() const override;
};

