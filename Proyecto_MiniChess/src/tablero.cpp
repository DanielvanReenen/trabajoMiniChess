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

void Tablero::SetJugador1(Jugador jugador1)
{
	this->jugador1 = jugador1;
}

void Tablero::SetJugador2(Jugador jugador2)
{
	this->jugador2 = jugador2;
}

Jugador Tablero::GetJugador1()
{
	return jugador1;
}

Jugador Tablero::GetJugador2()
{
	return jugador2;
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
	std::cout << "Usted ha pinchado en la casilla: Columna: (" << casSeleccion.columna << ")" << " , " << " Fila: (" << casSeleccion.fila << ")" << std::endl;

	Casilla positionRey = encontrarRey(turno1);
	bool jaque = estaEnJaque(positionRey, turno1);
	cout << "HAY JAQUE??? => " << jaque << endl;

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
				ETSIDI::play("sonidos/seleccion.wav");
			}
			else {
				std::cout << "Estas no son tus piezas." << std::endl;
			}
		}
		else {
			std::cout << "Usted ha pinchado en la casilla: Columna: (" << casSeleccion.columna << ")" << " , " << " Fila: (" << casSeleccion.fila << ")" << std::endl;
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
			std::cout << "Usted ha pinchado en la casilla: Fila: (" << casSeleccion.fila << ")" << " , " << " Columna: (" << casSeleccion.columna << ")" << std::endl;
			ETSIDI::play("sonidos/seleccion.wav");
		}

		else {//PARA EL MOVIMIENTO
			std::vector<Casilla> movimientosPermitidos = piezaOrigen->getMovimientosPermitidos(casOrigen.fila, casOrigen.columna, turno1);
			bool movimientoPermitido = false;
			for (const auto& movimiento : movimientosPermitidos)
			{
				Casilla casillaValida = movimiento;

				if (movimiento.fila == casSeleccion.fila && movimiento.columna == casSeleccion.columna) {
					movimientoPermitido = true;
					break;
				}
			}

			if (movimientoPermitido) 
			{
				casDestino = casSeleccion;
				movimientoActivado = true;
				piezaDestino = piezaOrigen;
				piezaDestino->setColumna(casDestino.columna);
				piezaDestino->setFila(casDestino.fila);
				if (casillas[piezaDestino->getColumna()][piezaDestino->getFila()] != nullptr) {
					cout << "te has comido una pieza" << endl;	//detecta que se ha comido una pieza
					delete casillas[piezaDestino->getColumna()][piezaDestino->getFila()];
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


Casilla Tablero::encontrarRey(int colorRey) {
	for (int fila = 0; fila < 8; ++fila) {
		for (int columna = 0; columna < 8; ++columna) {
			Pieza* pieza = casillas[fila][columna];
			if (pieza != nullptr && pieza->getTipo() == TipoPieza::Rey && pieza->getColor() == colorRey) {
				return Casilla{ columna, fila };
			}
		}
	}
	return Casilla{ -1, -1 }; // No debería ocurrir si el rey siempre está presente en el tablero
}

bool Tablero::casillaOcupada(int fila, int columna) {
	return casillas[fila][columna] != nullptr;
}

bool Tablero::caminoDespejado( int filaInicial, int columnaInicial, int filaFinal, int columnaFinal) {
	int incrementoFila = (filaFinal > filaInicial) ? 1 : (filaFinal < filaInicial) ? -1 : 0;
	int incrementoColumna = (columnaFinal > columnaInicial) ? 1 : (columnaFinal < columnaInicial) ? -1 : 0;

	int fila = filaInicial + incrementoFila;
	int columna = columnaInicial + incrementoColumna;

	while (fila != filaFinal || columna != columnaFinal) {
		if (casillaOcupada(fila, columna)) {
			return false;
		}
		fila += incrementoFila;
		columna += incrementoColumna;
	}
	return true;
}

std::string Tablero::tipoPiezaToString(TipoPieza tipo) {
	switch (tipo) {
	case TipoPieza::Torre: return "Torre";
	case TipoPieza::Caballo: return "Caballo";
	case TipoPieza::Alfil: return "Alfil";
	case TipoPieza::Rey: return "Rey";
	case TipoPieza::Reina: return "Reina";
	case TipoPieza::Peon: return "Peon";
	case TipoPieza::Ninguno: return "Ninguno";
	}
	return "Desconocido";
}

bool Tablero::estaEnJaque(Casilla posicionRey, int colorRey) {
	// Recorre todas las piezas del oponente
	for (int fila = 0; fila < 8; ++fila) {
		for (int columna = 0; columna < 8; ++columna) {
			Pieza* pieza = casillas[fila][columna];
			if (pieza != nullptr && pieza->getColor() != colorRey) {
				vector<Casilla> movimientos = pieza->getMovimientosPermitidos(fila, columna, pieza->getColor() == 0);
				for (const Casilla& movimiento : movimientos) {
					if (movimiento.fila == posicionRey.fila && movimiento.columna == posicionRey.columna) {
						if (pieza->getTipo() == TipoPieza::Caballo) {
							std::cout << "El rey está en jaque por un " << tipoPiezaToString(pieza->getTipo())
								<< " en la posición (" << fila << ", " << columna << ")\n";
							return true; // El caballo puede saltar, no necesita camino despejado
						}
						else if (caminoDespejado(fila, columna, movimiento.fila, movimiento.columna)) {
							std::cout << "El rey está en jaque por un " << tipoPiezaToString(pieza->getTipo())
								<< " en la posición (" << fila << ", " << columna << ")\n";
							return true; // El camino hacia el rey está despejado
						}
					}
				}
			}
		}
	}

	return false; // El rey no está en jaque
}
