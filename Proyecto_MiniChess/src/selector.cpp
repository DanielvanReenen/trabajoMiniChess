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
    casSeleccion.columna = (y - 36) / 90;
    casSeleccion.fila = (x - 36) / 90;
    piezaSeleccionada = tablero.getPieza(casSeleccion.fila, casSeleccion.columna);
    std::cout << "Usted ha pinchado en la casilla: (" << casSeleccion.fila << ", " << casSeleccion.columna << ")" << std::endl;


    if (!seleccionActiva ) { //si no tenia nada seleccionado antes
        if (piezaSeleccionada != nullptr) {//si no estoy seleccionando un vacio

            if (piezaSeleccionada->getColor() == colorjugador) {//si es el color del jugador
                casOrigen.fila = casSeleccion.fila;
                casOrigen.columna = casSeleccion.columna;
                piezaOrigen = piezaSeleccionada;
                seleccionActiva = true;
                std::cout << "Has seleccionado un " << static_cast<int>(piezaOrigen->getTipo()) << " y está en las coordenadas (" << casOrigen.fila << ", " << casOrigen.columna << ")" << std::endl;
            }
            else {
                std::cout << "Estas no son tus piezas." << std::endl;
            }
        }
        else {
            std::cout << "No hay ninguna pieza en la casilla (" << casSeleccion.fila << ", " << casSeleccion.columna << ")" << std::endl;
        }

    }
    else {
        //si volvemos a hacer click deseleccionamos
        if (casOrigen.fila == casSeleccion.fila && casOrigen.columna == casSeleccion.columna) { 
            std::cout << "Deseleccionando la pieza en la casilla: (" << casOrigen.fila << ", " << casOrigen.columna << ")" << std::endl;
            piezaOrigen = nullptr;
            seleccionActiva = false;
        }
        //si cogemos otra pieza nuestra cambiamos la seleccion
        else if (piezaSeleccionada != nullptr && piezaSeleccionada->getColor() == piezaOrigen->getColor()) {
            casOrigen.fila = casSeleccion.fila;
            casOrigen.columna = casSeleccion.columna;
            piezaOrigen = piezaSeleccionada;
            std::cout << "Has cambiado la selección a un " << static_cast<int>(piezaOrigen->getTipo()) << " en la casilla: (" << casOrigen.fila << ", " << casOrigen.columna << ")" << std::endl;
        }
        else {//PARA EL MOVIMIENTO
            std::vector<Casilla> movimientosPermitidos = piezaOrigen->getMovimientosPermitidos();

                bool movimientoPermitido = false;
                for (const auto& movimiento : movimientosPermitidos) {
                    if (movimiento.fila == casSeleccion.fila && movimiento.columna == casSeleccion.columna) {
                        movimientoPermitido = true;
                        break;
                    }
                }

                if (movimientoPermitido) {
                    casDestino = casSeleccion;
                    movimientoActivado = true;
                    piezaDestino = piezaSeleccionada;
                    std::cout << "Has seleccionado un movimiento desde (" << casOrigen.fila << ", " << casOrigen.columna << ") hasta (" << casDestino.fila << ", " << casDestino.columna << ")" << std::endl;
                    
                    //AQUI DEBERIAMOS LLAMAR A UNA FUNCION MIEMBRO DE ITERACCION PARA EJECUTAR LOS MOVIMIENTOS Y COMER FICHAS

                 }
            else {
                std::cout << "No se permite ese movimiento." << std::endl;
            }
        }
    }



    };
    
  


Pieza* Selector::getPiezaSeleccionada() const {
    return piezaSeleccionada;
}




//void Selector::origen()
//{
//    casillaOriginal = columna * 8 + fila;
//}

