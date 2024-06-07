#pragma once
#include "tablero.h"
#include "freeglut.h"
#include "ETSIDI.h"

class Menu {
public:
    enum Estado { INICIO, JUEGO, WINNEGRAS, WINBLANCAS, PAUSA, CREDITOS, CAMBIOPIEZA, MODOJUEGO, MENU_GRAVEDAD};

private:
    Estado estado;
    Tablero tablero;
    bool gravedadON;

public:
    Menu();
    void tecla(unsigned char key);
    void dibuja();
    void aplicarGravedad();
    bool getGravedad();
    void inicializa();
    void Selector(int x, int y);
    Estado getEstado() const;  // Declaración de la función getEstado
    void ComprobarMaquina();
};


