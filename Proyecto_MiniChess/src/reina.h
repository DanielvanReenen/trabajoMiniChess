#pragma once
#include "pieza.h"
#include "tablero.h"

class Reina : public Pieza
{
private:
    const Tablero& tablero;
public:
    Reina(Coordenada pos, int col, int fila_, int columna_, const Tablero& tablero);

    void dibujaPieza() override;
    TipoPieza getTipo() const override { return TipoPieza::Reina; }
    vector<Casilla> getMovimientosPermitidos(int filaActual, int columnaActualbool, bool turnoBlancas) const override;
};

