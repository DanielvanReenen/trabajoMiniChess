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
#include "jugador.h"

using namespace std;

class Tablero {
    friend class Pieza;
    friend class Selector;

private:
    vector<vector<Pieza*>> casillas;
    bool finalJuego = false;
    Coordenada coordenadaSobreTablero[64];
    Jugador jugador1;
    Jugador jugador2;
    Casilla casSeleccion;
    Casilla casOrigen = { 0,0 };
    Casilla casDestino = { 0,0 };
    Pieza* piezaSeleccionada = nullptr;
    Pieza* piezaOrigen = nullptr;
    Pieza* piezaDestino = nullptr;
    bool seleccionActiva = false;
    bool movimientoActivado = false;


    bool jaque;

public:
    Tablero(const Jugador& j1, const Jugador& j2);
    ~Tablero();
    void dibuja();
    void CasillasaCoordenadas();
    void inicializaTablero();
    void Selector(int x, int y);
    void raton(int x, int y);
    void dibujaPieza();
    void aplicarGravedad();
    void calcularJaque();
    Jugador GetJugador1();
    Jugador GetJugador2();
    Pieza* getPieza(int columna, int fila);
};