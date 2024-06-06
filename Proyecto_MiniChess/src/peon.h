#pragma once
#include "pieza.h"
#include "tablero.h"

class Peon : public Pieza {
private:
    const Tablero& tablero;
public:
    Peon(Coordenada posicion, int color, int fila, int columna, const Tablero& tablero);
    
    virtual void dibujaPieza() override;
    virtual TipoPieza getTipo() const override;
    virtual vector<Casilla> getMovimientosPermitidos(int filaActual, int columnaActual, bool turnoBlancas) const override;
};
