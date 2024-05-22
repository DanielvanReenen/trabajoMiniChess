#pragma once
#include <iostream>
#include <vector>
#include "pieza.h"
#include "Coordenada.h"
#include "torre.h"
#include "caballo.h"
#include "alfil.h"
#include "rey.h"
#include "reina.h"
#include "peon.h"
#include "selector.h"

using namespace std;

class Tablero {
    friend class Pieza;
    friend class Selector;

private:
    vector<vector<Pieza*>> casillas;
    bool finalJuego = false;
    Coordenada coordenadaSobreTablero[64];
    Selector selector;
    Jugador jugador1;
    Jugador jugador2;

public:
    Tablero(const Jugador& j1, const Jugador& j2);
    ~Tablero();
    void dibuja();
    void CasillasaCoordenadas();
    void inicializaTablero();
    void dibujaPieza();
    void selectorRaton(int x, int y);
    void aplicarGravedad();
    void actualizarJugadores(Jugador j1, Jugador j2);
    Pieza* getPieza(int columna, int fila);
};