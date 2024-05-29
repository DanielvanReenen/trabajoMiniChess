#include "menu.h"
#include <cstdlib> // para std::rand y std::srand
#include <ctime> 
#include "ETSIDI.h"

Menu::Menu() : tablero(Jugador(false), Jugador(false)), estado(INICIO) {}

void Menu::inicializa() {
    // Asignar turno aleatoriamente a un jugador
    std::srand(std::time(0));
    Jugador jugador = new Jugador(false);
    
    if (std::rand() % 2 == 0) {
        jugador = tablero.GetJugador1();
        jugador.SetTurno(true);
        tablero.SetJugador1(jugador);
    }
    else {
        jugador = tablero.GetJugador2();
        jugador.SetTurno(true);
        tablero.SetJugador2(jugador);
    }
    estado = INICIO;
}



void Menu::tecla(unsigned char key) {
    std::cout << "se ha reconocido una letra: " << key << std::endl;
    switch (estado) {
    case INICIO:
        if (key == 's') exit(0);
        if (key == 'e') {
            tablero.CasillasaCoordenadas();
            tablero.inicializaTablero();
            estado = JUEGO;
        }
        estado = JUEGO;
        break;
    case JUEGO:
        if (key == 'p') estado = PAUSA;
        // Agregar más lógica específica del juego de ajedrez si es necesario
        break;
    case GAMEOVER:
        if (key == 'c') estado = INICIO;
        break;
    case FIN:
        if (key == 'c') estado = INICIO;
        break;
    case PAUSA:
        if (key == 'c') estado = JUEGO;
        break;
    }
}

void Menu::dibuja() {
    std::cout << "Estado actual: " << estado << std::endl;
    switch (estado) {
    case INICIO:
        std::cout << "Dibujando la pantalla de inicio" << std::endl;

        // Configuración de la vista para el inicio del juego
     //   glMatrixMode(GL_MODELVIEW);
        //glLoadIdentity();
        //gluLookAt(0, 7.5, 30, // posicion del ojo
        //    0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
        //    0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
       // ETSIDI::setTextColor(1, 1, 0);
       // ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
      //  ETSIDI::printxy("Pang 1.2", -5, 8);
      //  ETSIDI::setTextColor(1, 1, 1);
      //  ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
      //  ETSIDI::printxy("PULSE LA TECLA -E- PARA EMPEZAR", -5, 7);
      //  ETSIDI::printxy("PULSE LA TELCA -S- PARA SALIR", -5, 6);
      //  ETSIDI::printxy("nombres", 2, 1);
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/inicio.png").id);
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
        break;

    case JUEGO:
        tablero.dibuja(); // Dibujar el tablero y sus piezas
        tablero.dibujaPieza();
        break;

    case GAMEOVER:
        tablero.dibuja();
        ETSIDI::setTextColor(1, 0, 0);
        ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
        ETSIDI::printxy("GAME OVER: Has perdido", -5, 10);
        ETSIDI::printxy("Pulsa -C- para continuar", -5, 5);
        break;

    case FIN:
        tablero.dibuja();
        ETSIDI::setTextColor(1, 0, 0);
        ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
        ETSIDI::printxy("ENHORABUENA, ¡Has triunfado!", -5, 10);
        ETSIDI::printxy("Pulsa -C- para continuar", -5, 9);
        break;

    case PAUSA:
        std::cout << "Dibujando la pantalla de pausa" << std::endl;
        tablero.dibuja();
        tablero.dibujaPieza();
        ETSIDI::setTextColor(1, 1, 0);
        ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
        ETSIDI::printxy("PAUSA", -5, 10);
        ETSIDI::printxy("Pulsa -C- para continuar", -5, 5);
        break;
    }
}
void Menu::aplicarGravedad() {
    tablero.aplicarGravedad();
}

void Menu::Selector(int x, int y) {
    tablero.Selector(x, y);
}
Menu::Estado Menu::getEstado() const {
    return estado;
}