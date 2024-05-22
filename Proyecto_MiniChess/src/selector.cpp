#include "selector.h"
#include <iostream>
#include "tablero.h"

bool Selector::turnos(bool turno)
{
	if (turno == false) {
		turno = true;
	}
	else turno = false;
	cout << "Estas en el turno de false =blancas, true=negras" << turno;
	return turno;
}

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
	Jugador Jugador1 = tablero.jugador1;
	Jugador Jugador2 = tablero.jugador2;
	bool turno1 = Jugador1.getTurno();
	bool turno2 = Jugador2.getTurno();
	int colorturno;

	if (turno1 == turno2) {
		cout << "error, no puede ser el turno de los 2 a la vez" << endl;
	}

	//revisar que es fila y que es columna
	casSeleccion.columna = (x - 36) / 90;
	casSeleccion.fila = (y - 36) / 90;
	piezaSeleccionada = tablero.getPieza(casSeleccion.columna, casSeleccion.fila);
	std::cout << "Usted ha pinchado en la casilla: (" << casSeleccion.columna << ", " << casSeleccion.fila << ")" << std::endl;

	if (turno1 == true) {
		colorturno = 0;
		cout << "Se dispone a jugar el jugador 1 con las blancas" << endl;
	}
	else {
		colorturno = 1;
		cout << "Se dispone a jugar el jugador 2 con las negras" << endl;
	}

	if (!seleccionActiva) { //si no tenia nada seleccionado antes
		if (piezaSeleccionada != nullptr) {//si no estoy seleccionando un vacio

			if (piezaSeleccionada->getColor() == colorturno) {//si es el color del jugador
				casOrigen.fila = casSeleccion.fila;
				casOrigen.columna = casSeleccion.columna;
				piezaOrigen = piezaSeleccionada;
				seleccionActiva = true;
				std::cout << "Has seleccionado un " << static_cast<int>(piezaOrigen->getTipo()) << " y está en las coordenadas (" << casOrigen.columna << ", " << casOrigen.fila << ")" << std::endl;
				ETSIDI::play("sonidos/seleccion.wav");
			}
			else {
				std::cout << "Estas no son tus piezas." << std::endl;
			}
		}
		else {
			std::cout << "No hay ninguna pieza en la casilla (" << casSeleccion.columna << ", " << casSeleccion.fila << ")" << std::endl;
		}

	}
	else {
		//si volvemos a hacer click deseleccionamos
		if (casOrigen.fila == casSeleccion.fila && casOrigen.columna == casSeleccion.columna) {
			std::cout << "Deseleccionando la pieza en la casilla: (" << casOrigen.columna << ", " << casOrigen.fila << ")" << std::endl;
			piezaOrigen = nullptr;
			seleccionActiva = false;
		}
		//si cogemos otra pieza nuestra cambiamos la seleccion
		else if (piezaSeleccionada != nullptr && piezaSeleccionada->getColor() == piezaOrigen->getColor()) {
			casOrigen.fila = casSeleccion.fila;
			casOrigen.columna = casSeleccion.columna;
			piezaOrigen = piezaSeleccionada;
			std::cout << "Has cambiado la seleccion a un " << static_cast<int>(piezaOrigen->getTipo()) << " en la casilla: (" << casOrigen.columna << ", " << casOrigen.fila << ")" << std::endl;
			ETSIDI::play("sonidos/seleccion.wav");
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
				piezaDestino = piezaOrigen;
				piezaDestino->setColumna(casDestino.columna);
				piezaDestino->setFila(casDestino.fila);
				tablero.casillas[piezaDestino->getColumna()][piezaDestino->getFila()] = piezaDestino;
				piezaDestino->setPosicion(tablero.coordenadaSobreTablero[piezaDestino->getColumna() * 8 + piezaDestino->getFila()]);
				ETSIDI::play("sonidos/movimiento.wav");
				std::cout << "Has seleccionado un movimiento desde (" << casOrigen.columna << ", " << casOrigen.fila << ") hasta (" << casDestino.columna << ", " << casDestino.fila << ")" << std::endl;
				tablero.casillas[casOrigen.columna][casOrigen.fila] = nullptr;

				
				movimientoActivado = false;
				seleccionActiva = false;
				piezaOrigen = nullptr;
				piezaSeleccionada = nullptr;
				piezaDestino = nullptr;


			}

			//AQUI DEBERIAMOS LLAMAR A UNA FUNCION MIEMBRO DE ITERACCION PARA EJECUTAR LOS MOVIMIENTOS Y COMER FICHAS

		// }
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

