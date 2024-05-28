#pragma once
#include "pieza.h"

class Caballo : public Pieza
{
public:
    Caballo( int col) : Pieza( col, col == 0 ? "imagenes/CaballoJedi.png" : "imagenes/CaballoSith.png") {}
    Caballo(Coordenada pos, int col, int fila_, int columna_);

    void dibujaPieza() override;
    TipoPieza getTipo() const override { return TipoPieza::Caballo; }
    vector<Casilla> getMovimientosPermitidos(int filaActual, int columnaActualbool, bool turnoBlancas) const override;
};


