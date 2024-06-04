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
    Coordenada coordenadaSobreTablero[64];
    bool finalJuego = false;
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

    const int ColorBlancas = 0;
    const int ColorNegras = 1;

    bool jaque;

public:
    Tablero(const Jugador& j1, const Jugador& j2);
    ~Tablero();
    void dibuja();
    void CasillasaCoordenadas();
    void inicializaTablero();
    void Selector(int x, int y);
    void ValidarMovimiento(bool turnoBlancas, bool& movimientoPermitido);
    void MovimientoGeneral(bool turnoBlancas, bool& movimientoPermitido);
    void dibujaPieza();
    void aplicarGravedad();
    void SetJugador1(Jugador jugador1);
    void SetJugador2(Jugador jugador2);
    Jugador GetJugador1();
    Jugador GetJugador2();
    Pieza* getPieza(int fila, int columna);
    bool hayPiezaOponente(int fila, int columna, bool turnoBlancas) const;

    Casilla encontrarRey(bool turnoBlancas);
    bool estaEnJaque(Casilla posicionRey, bool colorRey);
    bool casillaOcupada(int fila, int columna) const;
    bool caminoDespejado(int filaInicial, int columnaInicial, int filaFinal, int columnaFinal);
    string tipoPiezaToString(TipoPieza tipo);
    Pieza* HayCoronacion(Casilla casillaDestino, Pieza* tipoPieza);
    Pieza* CoronacionDeseada(Pieza* piezaActual, Casilla casillaDestino, bool blancas);
};
