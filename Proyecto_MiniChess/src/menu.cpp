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
    ETSIDI::playMusica("sonidos/inicio_sonido.mp3");
}



void Menu::tecla(unsigned char key) {
    switch (estado) {
    case INICIO:
        if (key == 's') {
            ETSIDI::stopMusica();
            exit(0);
        }
        if (key == 'e') {
            ETSIDI::stopMusica();
            tablero.CasillasaCoordenadas();
            tablero.inicializaTablero();
            ETSIDI::playMusica("sonidos/fondo.mp3");
            estado = JUEGO;
        }

        break;
    case JUEGO:
        if (key == 'p') estado = PAUSA;
        break;
    case WINBLANCAS:
        if (key == 'c') estado = INICIO;
        if (key == 's') exit(0);
        break;
    case WINNEGRAS:
        if (key == 'c') estado = INICIO;
        if (key == 's') exit(0);
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

    case WINNEGRAS:
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/victoriaN.png").id);
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

    case WINBLANCAS:
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/victoriab.png").id);
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

    case PAUSA:
        std::cout << "Dibujando la pantalla de pausa" << std::endl;
        tablero.dibuja();
        tablero.dibujaPieza();
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