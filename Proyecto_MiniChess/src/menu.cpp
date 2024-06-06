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
    ETSIDI::playMusica("musica/musica principio.mp3");
}

void Menu::tecla(unsigned char key) {
    switch (estado) {
    case INICIO:

        if (key == 's' || key == 'S') {
            ETSIDI::stopMusica();
            exit(0);
        }
        if (key == 'e' || key == 'E') {
            ETSIDI::stopMusica();
            tablero.CasillasaCoordenadas();
            tablero.inicializaTablero();
            ETSIDI::play("musica/fondo.mp3");
            estado = JUEGO;
        }
        else if (key == 'c' || key == 'C') {
            estado = CREDITOS;
        }
        break;

    case JUEGO:
        if (key == 'p' || key == 'P') estado = PAUSA;
        if (key == 's' || key == 'S') {
            exit(0);
        }
        if (tablero.coronacion) {                              //esto
            estado = CAMBIOPIEZA;
        }
        break;
    case WINBLANCAS:
        if (key == 'c' || key == 'C') estado = INICIO;
        break;
    case WINNEGRAS:
        if (key == 'c' || key == 'C') estado = INICIO;
        break;
    case PAUSA:
        if (key == 'c' || key == 'C') estado = JUEGO;
        break;
    case CREDITOS:
        if (key == 's' || key == 'S') exit(0);
        if (key == 'e' || key == 'E') {

            tablero.CasillasaCoordenadas();
            tablero.inicializaTablero();
            ETSIDI::stopMusica();
            //  ETSIDI::playMusica("musica/fondo.mp3");
            estado = JUEGO;
        }
        break;
         
    case CAMBIOPIEZA:                                                //esto
        
        if (key == 't' || key == 'T') {
            tablero.setCambioPieza(key); 
            estado = JUEGO;
            break;
        }
        if (key == 'r' || key ==  'R') { 
            tablero.setCambioPieza(key); 
            estado = JUEGO;
            break;
        }
        if (key == 'c' || key == 'C') { 
            tablero.setCambioPieza(key); 
            estado = JUEGO;
            break;
        }
        if (key == 'a' || key == 'A') { 
            tablero.setCambioPieza(key); 
            estado = JUEGO;
            break;
        }
       
    }
}


void Menu::dibuja() {
    switch (estado) {
    case INICIO:
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Inicio.png").id);
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

    case WINBLANCAS:
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/winblancas.png").id);
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

    case WINNEGRAS:
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/winnegras.png").id);
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

    case CREDITOS:
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Creditos.png").id);
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
