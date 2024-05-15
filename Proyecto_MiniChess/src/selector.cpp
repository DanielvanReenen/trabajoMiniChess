#include "selector.h"
#include "tablero.h"
#include <iostream>



Selector::Selector()
{
    casOrigen = { 0,0 };
    casDestino = { 0,0 };
}

int Selector::getFila()
{
    
    return casOrigen.fila;
}

int Selector::getColumna() {
    return casOrigen.columna;
}

void Selector::raton(int x, int y, Tablero& tablero)
{
    //revisar que es fila y que es columna
    casOrigen.columna = (y - 36) / 90;
    casOrigen.fila = (x - 36) / 90;
    piezaSeleccionada = tablero.getPieza(casOrigen.fila, casOrigen.columna);
    std::cout << "Usted ha pinchado en la casilla: (" << casOrigen.fila << ", " << casOrigen.columna << ")" << std::endl;

    if (piezaSeleccionada != nullptr) {
        std::cout << "Has seleccionado un " << static_cast<int>(piezaSeleccionada->getTipo())
            << " y esta en las coordenadas (" << casOrigen.fila << ", " << casOrigen.columna << ")" << std::endl;
    }
    else {
        std::cout << "No hay ninguna pieza en la casilla (" << casOrigen.fila << ", " << casOrigen.columna << ")" << std::endl;
    }
}


Pieza* Selector::getPiezaSeleccionada() const {
    return piezaSeleccionada;
}




//void Selector::origen()
//{
//    casillaOriginal = columna * 8 + fila;
//}

