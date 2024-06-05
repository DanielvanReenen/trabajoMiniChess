#pragma once
#include "tablero.h"
#include "freeglut.h"
#include "ETSIDI.h"

class Menu {
public:
    enum Estado { INICIO, JUEGO, WINBLANCAS, WINNEGRAS, PAUSA };

private:
    Estado estado;
    Tablero tablero;

public:
    Menu();
    void tecla(unsigned char key);
    void dibuja();
    void inicializa();
    void aplicarGravedad();
    void Selector(int x, int y);
    Estado getEstado() const;  // Declaración de la función getEstado
};


