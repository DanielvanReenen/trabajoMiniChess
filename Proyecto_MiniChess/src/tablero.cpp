#include "tablero.h"
#include "freeglut.h"
#include "ETSIDI.h"
#include <stdlib.h>

Tablero::Tablero(const Jugador& j1, const Jugador& j2)
    : jugador1(j1), jugador2(j2), casillas(8, vector<Pieza*>(8, nullptr)) {
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

Pieza* Tablero::getPieza(int fila, int columna) {
    if (fila < 0 || fila >= 8 || columna < 0 || columna >= 8) {
        return nullptr;
    }
    return casillas[fila][columna];
}

bool Tablero::hayPiezaOponente(int fila, int columna, bool turnoBlancas) const {
    Pieza* pieza = casillas[fila][columna];
    if (pieza == nullptr)
        return false;

    return (turnoBlancas && pieza->getColor() == 1) || (!turnoBlancas && pieza->getColor() == 0);
}

void Tablero::aplicarGravedad() {
    for (int i = 0; i < 8; i++) {
        for (int j = 6; j >= 0; j--) {
            if (casillas[j][i] != nullptr) {
                int nuevaFilaGravitatoria = j;
                while (nuevaFilaGravitatoria < 7 && casillas[nuevaFilaGravitatoria + 1][i] == nullptr) {
                    nuevaFilaGravitatoria++;
                }
                if (nuevaFilaGravitatoria != j) {
                    casillas[nuevaFilaGravitatoria][i] = casillas[j][i];
                    casillas[j][i] = nullptr;
                    casillas[nuevaFilaGravitatoria][i]->setFila(nuevaFilaGravitatoria);
                    casillas[nuevaFilaGravitatoria][i]->setPosicion(coordenadaSobreTablero[nuevaFilaGravitatoria * 8 + i]);
                }
            }
        }
    }
}

void Tablero::SetJugador1(Jugador jugador1) {
    this->jugador1 = jugador1;
}

void Tablero::SetJugador2(Jugador jugador2) {
    this->jugador2 = jugador2;
}

Jugador Tablero::GetJugador1() {
    return jugador1;
}

Jugador Tablero::GetJugador2() {
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
    if (seleccionActiva) {
        DibujarPasosPermitidos();
    }
}

void Tablero::CasillasaCoordenadas() {
    int k = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            coordenadaSobreTablero[k].x = 0.93 - 0.23 * j;
            coordenadaSobreTablero[k].y = -0.675 + 0.23 * i;
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
    for (int i = 0; i < 8; i++) {
        casillas[1][i] = new Peon(coordenadaSobreTablero[1 * 8 + i], blanco, 1, i, *this);
        casillas[6][i] = new Peon(coordenadaSobreTablero[6 * 8 + i], negro, 6, i, *this);
    }
}

void Tablero::Selector(int x, int y) {

    system("cls");
    bool turno1 = jugador1.getTurno();
    bool turno2 = jugador2.getTurno();
    int colorturno;

    if (turno1 == turno2) {
        //cout << "error: no puede ser el turno de los 2 a la vez" << endl;
        return;
    }

    //Registramos lo que hemos pinchado, 
    casSeleccion.columna = (x - 36) / 90;
    casSeleccion.fila = (y - 36) / 90;
    piezaSeleccionada = getPieza(casSeleccion.fila, casSeleccion.columna);
    std::cout << "Usted ha pinchado en la casilla: Columna: (" << casSeleccion.columna << ")" << " , " << " Fila: (" << casSeleccion.fila << ")" << std::endl;

    if (turno1) {
        colorturno = 0;
        cout << "Se dispone a jugar el jugador 1 con las blancas" << endl;
    }
    else {
        colorturno = 1;
        cout << "Se dispone a jugar el jugador 2 con las negras" << endl;
    }

    if (!seleccionActiva) {  //Seleccionar casilla cuando el selector esta apagado
        if (piezaSeleccionada != nullptr && piezaSeleccionada->getColor() == colorturno) {
            casOrigen.fila = casSeleccion.fila;
            casOrigen.columna = casSeleccion.columna;
            piezaOrigen = piezaSeleccionada;
            seleccionActiva = true;
            ETSIDI::play("musica/the-force.mp3");
            piezaSeleccionada->seleccionActivada = true;                                       //ESTO
        }
        else {
            std::cout << "Estas no son tus piezas o la casilla está vacía." << std::endl;
        }
    }
    else {
        //Deseleccionamos la casilla al pulsar de nuevo sobre esta
        if (casOrigen.fila == casSeleccion.fila && casOrigen.columna == casSeleccion.columna) {
            std::cout << "Deseleccionando la pieza en la casilla: (" << casOrigen.columna << ", " << casOrigen.fila << ")" << std::endl;
            piezaOrigen = nullptr;
            seleccionActiva = false;
            piezaSeleccionada->seleccionActivada = false;                                      //ESTO
        }
        //Cambiamos la casilla que habiamos seleccionado por otra del mismo jugador
        else if (piezaSeleccionada != nullptr && piezaSeleccionada->getColor() == piezaOrigen->getColor()) {
            piezaOrigen->seleccionActivada = false;                                           //ESTO
            casOrigen.fila = casSeleccion.fila;
            casOrigen.columna = casSeleccion.columna;
            piezaOrigen = piezaSeleccionada;
            piezaSeleccionada->seleccionActivada = true;                                      //ESTO
            std::cout << "Usted ha pinchado en la casilla: Fila: (" << casSeleccion.fila << ")" << " , " << " Columna: (" << casSeleccion.columna << ")" << std::endl;
            ETSIDI::play("musica/the-force.mp3");
        }
        else {
            bool movimientoPermitido = false;
            ValidarMovimiento(turno1, movimientoPermitido);

            if (movimientoPermitido) {
                casDestino = casSeleccion;
                movimientoActivado = true;
                piezaDestino = piezaOrigen;
                piezaDestino->setColumna(casDestino.columna);
                piezaDestino->setFila(casDestino.fila);
                piezaOrigen->seleccionActivada = false;                                      //ESTO

                //Realizamos la omprobacion de la captura al paso
                if (piezaOrigen->getTipo() == TipoPieza::Peon && std::abs(casDestino.fila - casOrigen.fila) == 1 && std::abs(casDestino.columna - casOrigen.columna) == 1 && casillas[casDestino.fila][casDestino.columna] == nullptr) {
                    int direction = (piezaOrigen->getColor() == 0) ? -1 : 1; // White moves up, black moves down
                    delete casillas[casDestino.fila + direction][casDestino.columna];
                    casillas[casDestino.fila + direction][casDestino.columna] = nullptr;
                    std::cout << "Se ha capturado al paso en (" << casDestino.columna << ", " << casDestino.fila + direction << ")" << std::endl;
                }

                if (casillas[casDestino.fila][casDestino.columna] != nullptr) {
                    cout << "Te has comido una pieza" << endl;
                    if (casillas[casDestino.fila][casDestino.columna]->getTipo() == TipoPieza::Peon) {
                        piezaComida = new Peon(casillas[casDestino.fila][casDestino.columna]->getPosicion(), casillas[casDestino.fila][casDestino.columna]->getColor(), casillas[casDestino.fila][casDestino.columna]->getFila(), casillas[casDestino.fila][casDestino.columna]->getColumna(), *this);
                    }

                    if (casillas[casDestino.fila][casDestino.columna]->getTipo() == TipoPieza::Torre) {
                        piezaComida = new Torre(casillas[casDestino.fila][casDestino.columna]->getPosicion(), casillas[casDestino.fila][casDestino.columna]->getColor(), casillas[casDestino.fila][casDestino.columna]->getFila(), casillas[casDestino.fila][casDestino.columna]->getColumna());
                    }

                    if (casillas[casDestino.fila][casDestino.columna]->getTipo() == TipoPieza::Caballo) {
                        piezaComida = new Caballo(casillas[casDestino.fila][casDestino.columna]->getPosicion(), casillas[casDestino.fila][casDestino.columna]->getColor(), casillas[casDestino.fila][casDestino.columna]->getFila(), casillas[casDestino.fila][casDestino.columna]->getColumna());
                    }

                    if (casillas[casDestino.fila][casDestino.columna]->getTipo() == TipoPieza::Alfil) {
                        piezaComida = new Alfil(casillas[casDestino.fila][casDestino.columna]->getPosicion(), casillas[casDestino.fila][casDestino.columna]->getColor(), casillas[casDestino.fila][casDestino.columna]->getFila(), casillas[casDestino.fila][casDestino.columna]->getColumna());
                    }

                    if (casillas[casDestino.fila][casDestino.columna]->getTipo() == TipoPieza::Reina) {
                        piezaComida = new Reina(casillas[casDestino.fila][casDestino.columna]->getPosicion(), casillas[casDestino.fila][casDestino.columna]->getColor(), casillas[casDestino.fila][casDestino.columna]->getFila(), casillas[casDestino.fila][casDestino.columna]->getColumna());
                    }
                    
                    delete casillas[casDestino.fila][casDestino.columna];
                    comer = true;
                }
                
               
                 casillas[casDestino.fila][casDestino.columna] = piezaDestino;
                 piezaDestino->setPosicion(coordenadaSobreTablero[casDestino.fila * 8 + casDestino.columna]);
                 ETSIDI::play("musica/sonido-mover.mp3");
                 std::cout << "Has seleccionado un movimiento desde (" << casOrigen.columna << ", " << casOrigen.fila << ") hasta (" << casDestino.columna << ", " << casDestino.fila << ")" << std::endl;
                 casillas[casOrigen.fila][casOrigen.columna] = nullptr;
                 

                Casilla positionRey = encontrarRey(turno2);
                jaque = estaEnJaque(positionRey, turno2);
                cout << "HAY JAQUE??? => " << jaque << endl;
                

                if (jaque) {
                    if (comer = true) {
                        casillas[piezaDestino->getFila()][piezaDestino->getColumna()] = piezaComida;
                        casillas[casOrigen.fila][casOrigen.columna] = piezaDestino;
                        piezaDestino->setColumna(casOrigen.columna);
                        piezaDestino->setFila(casOrigen.fila);
                        piezaDestino->setPosicion(coordenadaSobreTablero[piezaDestino->getFila() * 8 + piezaDestino->getColumna()]);
                    }

                    if (comer = false) {
                        casillas[piezaDestino->getFila()][piezaDestino->getColumna()] = nullptr;
                        casillas[casOrigen.fila][casOrigen.columna] = piezaDestino;
                        piezaDestino->setColumna(casOrigen.columna);
                        piezaDestino->setFila(casOrigen.fila);
                        piezaDestino->setPosicion(coordenadaSobreTablero[piezaDestino->getFila() * 8 + piezaDestino->getColumna()]);
                    }

                    

                }

                //jaqueMate = estaEnJaqueMate(turno2);
                //if (jaqueMate = true) ;
                

                // Guardamos el valor del ultimo movimiento doble realizado por un peon
                if (piezaOrigen->getTipo() == TipoPieza::Peon && std::abs(casDestino.fila - casOrigen.fila) == 2) {
                    ultimoPeonDobleMovFila= casDestino.fila;
                    ultimoPeonDobleMovColumna= casDestino.columna;
                }
                else {
                    ultimoPeonDobleMovFila= -1;
                    ultimoPeonDobleMovColumna= -1;
                  
                }

                
            
                Pieza* piezaCoronada = HayCoronacion(casSeleccion, piezaOrigen);
                if (piezaCoronada != nullptr)
                {
                    // TODO: Cambiar este sonido a uno de celebración
                    ETSIDI::play("musica/Chewbacca.mp3");
                    casillas[piezaDestino->getFila()][piezaDestino->getColumna()] = piezaCoronada;
                }


                movimientoActivado = false;
                seleccionActiva = false;
                piezaOrigen = nullptr;
                piezaSeleccionada = nullptr;
                piezaDestino = nullptr;
                piezaComida = nullptr;
                comer = false;

                if (!jaque) {
                    if (turno1) {
                        jugador1.SetTurno(false);
                        jugador2.SetTurno(true);
                    }
                    else {
                        jugador1.SetTurno(true);
                        jugador2.SetTurno(false);
                    }
                }

            }
            else {
                std::cout << "No se permite ese movimiento." << std::endl;
            }
        }
    }
}

Casilla Tablero::encontrarRey(bool turnoBlancas) {

    int colorRey = turnoBlancas ? 1 : 0;
    std::cout << "Estamos buscando el rey de color " << colorRey << std::endl;

    for (int fila = 0; fila < 8; fila++) {
        for (int columna = 0; columna < 8; columna++) {
            Pieza* pieza = casillas[fila][columna];
            if (pieza != nullptr && pieza->getTipo() == TipoPieza::Rey && pieza->getColor() == colorRey)
            {
                return Casilla{ columna, fila };
            }
        }
    }
    return Casilla{ -1, -1 };
}

bool Tablero::casillaOcupada(int fila, int columna) const {
    return casillas[fila][columna] != nullptr;
}

bool Tablero::caminoDespejado(int filaInicial, int columnaInicial, int filaFinal, int columnaFinal) {
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

Pieza* Tablero::HayCoronacion(Casilla casillaDestino, Pieza* tipoPieza)
{
    Pieza* piezaDeseada = nullptr;
    if (tipoPieza != nullptr) 
    {
        if (tipoPieza->getTipo() == TipoPieza::Peon)
        {
            if (casillaDestino.fila == 0)
            {
                piezaDeseada = CoronacionDeseada(tipoPieza, casillaDestino, false);
            }
            else if (casillaDestino.fila == 7)
            {
                piezaDeseada = CoronacionDeseada(tipoPieza, casillaDestino, true);
            }
        }
    }
    return piezaDeseada;
}

Pieza* Tablero::CoronacionDeseada(Pieza* piezaActual, Casilla casillaDestino, bool blancas)
{
    //El color de pieza tiene que ser el mismo que del turno
    //GetConsoleWindow();
    char piezaDeseada = 'z';
    Pieza* nuevaPieza = nullptr;
    int colorPieza = blancas ? 0 : 1;

    do {
        std::cout << "Escoge a que tipo de pieza quieres convertirla ( T : Torre , C : Caballo , A: Alfil, R : Reina)" << endl;
        std::cin >> piezaDeseada;

        if (piezaDeseada != 't' && piezaDeseada != 'c' && piezaDeseada != 'a' && piezaDeseada != 'r' && piezaDeseada != 'T' && piezaDeseada != 'C' && piezaDeseada != 'A' && piezaDeseada != 'R')
        {
            std::cout << "El tipo de pieza seleccionada no está disponible." << endl;
        }
    } while (piezaDeseada != 't' && piezaDeseada != 'c' && piezaDeseada != 'a' && piezaDeseada != 'r' &&  piezaDeseada != 'T' && piezaDeseada != 'C' && piezaDeseada != 'A' && piezaDeseada != 'R');


    switch (piezaDeseada) {
    case 't':
        nuevaPieza = new Torre(piezaActual->getPosicion(), colorPieza, casillaDestino.fila, casillaDestino.columna);

        break;
    case 'T':
        nuevaPieza = new Torre(piezaActual->getPosicion(), colorPieza, casillaDestino.fila, casillaDestino.columna);

        break;
    case 'c':
        nuevaPieza = new Caballo(piezaActual->getPosicion(), colorPieza, casillaDestino.fila, casillaDestino.columna);

        break;
    case 'C':
        nuevaPieza = new Caballo(piezaActual->getPosicion(), colorPieza, casillaDestino.fila, casillaDestino.columna);

        break;
    case 'a':
        nuevaPieza = new Alfil(piezaActual->getPosicion(), colorPieza, casillaDestino.fila, casillaDestino.columna);
        break;
    case 'A':
        nuevaPieza = new Alfil(piezaActual->getPosicion(), colorPieza, casillaDestino.fila, casillaDestino.columna);
        break;
    case 'r':
        nuevaPieza = new Reina(piezaActual->getPosicion(), colorPieza, casillaDestino.fila, casillaDestino.columna);
        break;
    case 'R':
        nuevaPieza = new Reina(piezaActual->getPosicion(), colorPieza, casillaDestino.fila, casillaDestino.columna);
        break;
    }
    return nuevaPieza;
}

void Tablero::ValidarMovimiento(bool turnoBlancas, bool& movimientoPermitido)
{
    Pieza* piezaOrigenColision = casillas[casOrigen.fila][casOrigen.columna];
    if (piezaOrigenColision == nullptr)
        return;

    MovimientoGeneral(turnoBlancas, movimientoPermitido);
    
}

void Tablero::MovimientoGeneral(bool turnoBlancas, bool& movimientoPermitido) {
    std::vector<Casilla> movimientosPermitidos = piezaOrigen->getMovimientosPermitidos(casOrigen.fila, casOrigen.columna, turnoBlancas);
    for (const auto& movimiento : movimientosPermitidos) 
    {
        if (movimiento.fila == casSeleccion.fila && movimiento.columna == casSeleccion.columna) 
        {
                movimientoPermitido = true;
        }
    }
}

bool Tablero::estaEnJaque(Casilla posicionRey, bool turnoBlancas) {
    int colorReyOponente = turnoBlancas ? 0 : 1; // Cambiado para buscar el rey del oponente
    for (int fila = 0; fila < 8; fila++) {
        for (int columna = 0; columna < 8; columna++) {
            Pieza* pieza = casillas[fila][columna];
            if (pieza != nullptr && pieza->getColor() == colorReyOponente) {
                vector<Casilla> movimientos = pieza->getMovimientosPermitidos(fila, columna, !turnoBlancas);
                for (const Casilla& movimiento : movimientos) {
                    if (movimiento.fila == posicionRey.fila && movimiento.columna == posicionRey.columna) {
                        if (pieza->getTipo() == TipoPieza::Caballo || caminoDespejado(fila, columna, movimiento.fila, movimiento.columna)) {
                            std::cout << "El rey está en jaque por un " << tipoPiezaToString(pieza->getTipo())
                                << " en la posición (" << fila << ", " << columna << ")\n";
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

bool Tablero::estaEnJaqueMate(bool turnoBlancas) {
    Casilla posicionReyOponente = encontrarRey(!turnoBlancas);
    if (!estaEnJaque(posicionReyOponente, turnoBlancas)) {
        return false;
    }

    for (int fila = 0; fila < 8; fila++) {
        for (int columna = 0; columna < 8; columna++) {
            Pieza* pieza = casillas[fila][columna];
            if (pieza != nullptr && pieza->getColor() == (!turnoBlancas ? 0 : 1)) {
                vector<Casilla> movimientos = pieza->getMovimientosPermitidos(fila, columna, !turnoBlancas);
                for (const Casilla& movimiento : movimientos) {
                    Pieza* piezaDestinoOriginal = casillas[movimiento.fila][movimiento.columna];
                    casillas[movimiento.fila][movimiento.columna] = pieza;
                    casillas[fila][columna] = nullptr;

                    Casilla nuevaPosicionRey = pieza->getTipo() == TipoPieza::Rey ? movimiento : posicionReyOponente;
                    bool sigueEnJaque = estaEnJaque(nuevaPosicionRey, turnoBlancas);

                    casillas[fila][columna] = pieza;
                    casillas[movimiento.fila][movimiento.columna] = piezaDestinoOriginal;

                    if (!sigueEnJaque) {
                        return false;
                        std::cout << "Movimiento que saca del jaque: (" << fila << ", " << columna << ") -> ("
                            << movimiento.fila << ", " << movimiento.columna << ")\n";
                    }

                }
            }
        }
    }
    return true;
    std::cout << "¡Jaque mate! El jugador " << (turnoBlancas ? "2 (negro)" : "1 (blanco)") << " ha ganado.\n";
}

bool Tablero::estaEnJaqueDespuesDeMover(int filaOrigen, int columnaOrigen, int filaDestino, int columnaDestino, bool turnoBlancas)
{

    Pieza* piezaOrigen = casillas[filaOrigen][columnaOrigen];
    Pieza* piezaDestino = casillas[filaDestino][columnaDestino];
    casillas[filaDestino][columnaDestino] = piezaOrigen;
    casillas[filaOrigen][columnaOrigen] = nullptr;

    Casilla posicionRey = encontrarRey(turnoBlancas);
    if (piezaOrigen->getTipo() == TipoPieza::Rey) {
        posicionRey = { columnaDestino, filaDestino };
    }

    bool enJaque = estaEnJaque(posicionRey, turnoBlancas);
    casillas[filaOrigen][columnaOrigen] = piezaOrigen;
    casillas[filaDestino][columnaDestino] = piezaDestino;

    return enJaque;
}


void Tablero::DibujarPasosPermitidos() {
    bool turnoBlancas = true;//la funcion getmovimientospermitidos necesita esto para funcionar

    if (jugador1.getTurno() && (!jugador2.getTurno())) {
        turnoBlancas = true;
    }
    else if(jugador2.getTurno() && (!jugador1.getTurno())){
        turnoBlancas = false;
    }


    // Deshabilitar iluminación y texturas para asegurar que no interfieran
    glDisable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


    // dibujar la pieza seleccionada en blanco
    float xSeleccion = coordenadaSobreTablero[casOrigen.fila * 8 + casOrigen.columna].x;
    float ySeleccion = coordenadaSobreTablero[casOrigen.fila * 8 + casOrigen.columna].y;


    glColor4f(1.0, 1.0, 1.0, 0.5); // color blanco semitransparente

    // dibujar el círculo en las coordenadas reales
    glPushMatrix();
    glTranslatef(-xSeleccion + 0.125, -ySeleccion + 0.12, 0.1); // centro del círculo
    GLUquadric* qobj = gluNewQuadric();
    gluDisk(qobj, 0, 0.1, 20, 1); // disco con radio y 10 subdivisiones
    gluDeleteQuadric(qobj);
    glPopMatrix();


    //ahora dibujamos los circulitos verdes
    std::vector<Casilla> movimientosPermitidos = piezaOrigen->getMovimientosPermitidos(casOrigen.fila, casOrigen.columna, turnoBlancas);
    for (const Casilla& casilla : movimientosPermitidos) {


        // coordenadas reales de la casilla
        float sel_x = coordenadaSobreTablero[casilla.fila * 8 + casilla.columna].x;
        float sel_y = coordenadaSobreTablero[casilla.fila * 8 + casilla.columna].y;

        if (casillas[casilla.fila][casilla.columna] == nullptr) {
            glColor4f(0.2, 1.0, 0.2, 0.5); // color verde semitransparente

            //  coordenadas reales
            glPushMatrix();
            glTranslatef(-sel_x + 0.125, -sel_y + 0.12, 0.1); //  centro del círculo
            GLUquadric* qobj = gluNewQuadric();
            gluDisk(qobj, 0, 0.05, 20, 1); //disco con radio y 10 subdivisiones
            gluDeleteQuadric(qobj);
            glPopMatrix();

        }
         else if (casillas[casilla.fila][casilla.columna]->getColor() != piezaSeleccionada->getColor()) {

            glColor4f(1.0, 1.0, 0.0, 0.5); // color amarillo semitransparente

            //  coordenadas reales
            glPushMatrix();
            glTranslatef(-sel_x + 0.125, -sel_y + 0.12, 0.1); //  centro del círculo
            GLUquadric* qobj = gluNewQuadric();
            gluDisk(qobj, 0, 0.05, 20, 1); //disco con radio y 10 subdivisiones
            gluDeleteQuadric(qobj);
            glPopMatrix();
        }
    }

    // Restaurar el estado anterior de OpenGL
    glDisable(GL_BLEND);
    glEnable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);
}