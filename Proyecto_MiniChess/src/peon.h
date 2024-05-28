#pragma once
#include "pieza.h"

class Peon : public Pieza
{
public:
    Peon(int col) : Pieza(col, col == 0 ? "imagenes/PeonJedi.png" : "imagenes/PeonSith.png") {}
    Peon(Coordenada pos, int col, int fila_, int columna_);

    void dibujaPieza() override;
    TipoPieza getTipo() const override { return TipoPieza::Peon; }
    vector<Casilla> getMovimientosPermitidos(int filaActual, int columnaActualbool, bool turnoBlancas) const override;
};