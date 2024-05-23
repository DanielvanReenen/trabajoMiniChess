#include "tablero.h"
#include "freeglut.h"
#include "ETSIDI.h"

Tablero::Tablero(const Jugador& j1, const Jugador& j2) : jugador1(j1), jugador2(j2), casillas(8, vector<Pieza*>(8, nullptr)) {
    CasillasaCoordenadas();
    inicializaTablero();
}

Tablero::~Tablero() {
    for (auto& fila : casillas) {
        for (auto& pieza : fila) {
            delete pieza;
        }
    }
}

void Tablero::dibujaPieza() {
    for (auto& fila : casillas) {
        for (auto& pieza : fila) {
            if (pieza != nullptr) {
                pieza->dibujaPieza();
            }
        }
    }
}

Pieza* Tablero::getPieza(int columna, int fila) {
    if (columna < 0 || columna >= 8 || fila < 0 || fila >= 8) {
        return nullptr;
    }
    return casillas[columna][fila];
}

void Tablero::aplicarGravedad() {
    for (int i = 0; i < 8; i++) {
        for (int j = 6; j >= 0; j--) {
            if (casillas[i][j] != nullptr) {
                int nuevaFilaGravitatoria = j;
                while (nuevaFilaGravitatoria < 7 && casillas[i][nuevaFilaGravitatoria + 1] == nullptr) {
                    nuevaFilaGravitatoria++;
                }
                if (nuevaFilaGravitatoria != j) {
                    casillas[i][nuevaFilaGravitatoria] = casillas[i][j];
                    casillas[i][j] = nullptr;
                    casillas[i][nuevaFilaGravitatoria]->setFila(nuevaFilaGravitatoria);
                    casillas[i][nuevaFilaGravitatoria]->setPosicion(coordenadaSobreTablero[i * 8 + nuevaFilaGravitatoria]);
                }
            }
        }
    }
}

void Tablero::calcularJaque()
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (casillas[i][j] != nullptr) {

            }
        }
    }
    
}

void Tablero::dibuja() {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/tablero.png").id);
    glDisable(GL_LIGHTING);
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glTexCoord2d(0, 1); glVertex2f(-1, -1);
    glTexCoord2d(1, 1); glVertex2f(1, -1);
    glTexCoord2d(1, 0); glVertex2f(1, 1);
    glTexCoord2d(0, 0); glVertex2f(-1, 1);
    glEnd();
    glEnable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);
}

void Tablero::CasillasaCoordenadas() {
    int k = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            coordenadaSobreTablero[k].x = 0.93 - 0.23 * i;
            coordenadaSobreTablero[k].y = -0.675 + 0.23 * j;
            k++;
        }
    }
}

void Tablero::inicializaTablero() {
    enum { blanco, negro };

    // Torres
    casillas[0][0] = new Torre(coordenadaSobreTablero[0 * 8 + 0], blanco, 0, 0);
    casillas[0][7] = new Torre(coordenadaSobreTablero[0 * 8 + 7], blanco, 0, 7);
    casillas[7][0] = new Torre(coordenadaSobreTablero[7 * 8 + 0], negro, 7, 0);
    casillas[7][7] = new Torre(coordenadaSobreTablero[7 * 8 + 7], negro, 7, 7);

    // Caballos
    casillas[0][1] = new Caballo(coordenadaSobreTablero[0 * 8 + 1], blanco, 0, 1);
    casillas[0][6] = new Caballo(coordenadaSobreTablero[0 * 8 + 6], blanco, 0, 6);
    casillas[7][1] = new Caballo(coordenadaSobreTablero[7 * 8 + 1], negro, 7, 1);
    casillas[7][6] = new Caballo(coordenadaSobreTablero[7 * 8 + 6], negro, 7, 6);

    // Alfiles
    casillas[0][2] = new Alfil(coordenadaSobreTablero[0 * 8 + 2], blanco, 0, 2);
    casillas[0][5] = new Alfil(coordenadaSobreTablero[0 * 8 + 5], blanco, 0, 5);
    casillas[7][2] = new Alfil(coordenadaSobreTablero[7 * 8 + 2], negro, 7, 2);
    casillas[7][5] = new Alfil(coordenadaSobreTablero[7 * 8 + 5], negro, 7, 5);

    // Reyes
    casillas[0][3] = new Rey(coordenadaSobreTablero[0 * 8 + 3], blanco, 0, 3);
    casillas[7][3] = new Rey(coordenadaSobreTablero[7 * 8 + 3], negro, 7, 3);

    // Reinas
    casillas[0][4] = new Reina(coordenadaSobreTablero[0 * 8 + 4], blanco, 0, 4);
    casillas[7][4] = new Reina(coordenadaSobreTablero[7 * 8 + 4], negro, 7, 4);

    // Peones
    for (int i = 0; i < 8; ++i) {
        casillas[1][i] = new Peon(coordenadaSobreTablero[1 * 8 + i], blanco, 1, i);
        casillas[6][i] = new Peon(coordenadaSobreTablero[6 * 8 + i], negro, 6, i);
    }
}

void Tablero::Selector(int x, int y) {
	raton(x, y);
}

void Tablero::raton(int x, int y)
{
	Casilla casSeleccion;
    Casilla casOrigen = { 0,0 };
    Casilla casDestino = { 0,0 };
    Pieza* piezaSeleccionada = nullptr;
    Pieza* piezaOrigen = nullptr;
    Pieza* piezaDestino = nullptr;
    bool seleccionActiva = false;
    bool movimientoActivado = false;
	
	bool turno1 = jugador1.getTurno();
	bool turno2 = jugador2.getTurno();
	int colorturno;

	if (turno1 == turno2) {
		cout << "error: no puede ser el turno de los 2 a la vez" << endl;
	}

	//revisar que es fila y que es columna
	casSeleccion.columna = (x - 36) / 90;
	casSeleccion.fila = (y - 36) / 90;
	piezaSeleccionada = getPieza(casSeleccion.columna, casSeleccion.fila);
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
				std::cout << "Has seleccionado un " << static_cast<int>(piezaOrigen->getTipo()) << " y esta en las coordenadas (" << casOrigen.columna << ", " << casOrigen.fila << ")" << std::endl;
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
				if (casillas[piezaDestino->getColumna()][piezaDestino->getFila()] != nullptr) {
					cout << "te has comido una pieza" << endl;	//detecta que se ha comido una pieza
				}
				casillas[piezaDestino->getColumna()][piezaDestino->getFila()] = piezaDestino;
				piezaDestino->setPosicion(coordenadaSobreTablero[piezaDestino->getColumna() * 8 + piezaDestino->getFila()]);
				ETSIDI::play("sonidos/movimiento.wav");
				std::cout << "Has seleccionado un movimiento desde (" << casOrigen.columna << ", " << casOrigen.fila << ") hasta (" << casDestino.columna << ", " << casDestino.fila << ")" << std::endl;
				casillas[casOrigen.columna][casOrigen.fila] = nullptr;


				movimientoActivado = false;
				seleccionActiva = false;
				piezaOrigen = nullptr;
				piezaSeleccionada = nullptr;
				piezaDestino = nullptr;

				if (turno1 == true) {
					jugador1.SetTurno(false);
					jugador2.SetTurno(true);
				}
				else {
					jugador1.SetTurno(true);
					jugador2.SetTurno(false);
				}
			}
			
			else {
				std::cout << "No se permite ese movimiento." << std::endl;
			}
		}
	}
	
}