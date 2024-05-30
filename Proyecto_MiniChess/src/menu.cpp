#include "menu.h"
#include <cstdlib> // para std::rand y std::srand
#include <ctime> 
#include "ETSIDI.h"

Menu::Menu() : tablero(Jugador(false), Jugador(false)), estado(INICIO) {}

void Menu::inicializa() {
    std::srand(std::time(0));
    Jugador jugador = new Jugador(false);
    
    // De momento empiezan siempre las blancas => TODO
    if (true) {
        cout << "EMPIEZAN LAS BLANCAS" << std::endl;
        jugador = tablero.GetJugador1();
        jugador.SetTurno(true);
        tablero.SetJugador1(jugador);
    }
    else {
        cout << "EMPIEZAN LAS NEGRAS" << std::endl;
        jugador = tablero.GetJugador2();
        jugador.SetTurno(true);
        tablero.SetJugador2(jugador);
    }
    estado = INICIO;
}



void Menu::tecla(unsigned char key) {
    switch (estado) {
    case INICIO:
    //ETSIDI::playMusica("musica/musica_principio.mp3", true); Tenemos que hacer que funcione
        if (key == 's') exit(0);
        if (key == 'e') {
            //ETSIDI::stopMusica();
            tablero.CasillasaCoordenadas();
            tablero.inicializaTablero();
            ETSIDI::play("sonidos/inicio.wav");
            estado = JUEGO;
        }

        break;
    case JUEGO:
        if (key == 'p') estado = PAUSA;
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
    switch (estado) {
    case INICIO:
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
    //tablero.aplicarGravedad();
}

void Menu::Selector(int x, int y) {
    tablero.Selector(x, y);
}
Menu::Estado Menu::getEstado() const {
    return estado;
}