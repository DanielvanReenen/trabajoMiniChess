#include "selector.h"

Selector::Selector()
{
    fila = 0;
    columna = 0;
}

int Selector::getFila()
{
    return fila;
}

int Selector::getColumna() {
    return columna;
}

void Selector::raton(int x, int y)
{
    columna = (y - 36) / 90;
    fila = (x - 36) / 90;
}

//void Selector::origen()
//{
//    casillaOriginal = columna * 8 + fila;
//}

