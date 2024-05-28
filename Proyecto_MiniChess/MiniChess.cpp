#include <iostream>
#include "tablero.h"
#include <vector>
#include "freeglut.h"
#include "ETSIDI.h"
#include "jugador.h"
#include"menu.h"

//Tablero tablero(Jugador(true), Jugador(false)); //Estaría guay que los 2 empiecen en false y que se asigen true a uno aleatoriamente
Menu menu;
void OnDraw(void);
void OnMouseClick(int button, int state, int pantalla_x, int pantalla_y);
void resize(int width, int height);
void OnTimer(int value);
void OnKeyboard(unsigned char key, int x, int y);

float Width = 785;
float Height = 785; //max height = 785

int main(int argc, char* argv[]) {
    // Initialize tablero
    //tablero.CasillasaCoordenadas();
   // tablero.inicializaTablero();
   

    // Inicializar el gestor de ventanas GLUT y crear la ventana
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(371, 0);
    glutInitWindowSize(Width, Height);
    glutCreateWindow("Chess Wars");

    glutDisplayFunc(OnDraw);
    glutReshapeFunc(resize);
    glutKeyboardFunc(OnKeyboard);

    glClearColor(0, 0, 0, 1);
    glColor3f(1.f, 0, 0);
    glOrtho(785, 0, 785, 0, -1, 1);

    // Registrar los callbacks
    glutTimerFunc(25, OnTimer, 0);
    glutMouseFunc(OnMouseClick);
    menu.inicializa();
    ETSIDI::play("sonidos/inicio.wav");
    // Pasarle el control a GLUT, que llamara a los callbacks
    glutMainLoop();

    return 0;
}

void OnDraw(void) {
    // Borrado de la pantalla    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Para definir el punto de vista
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

   // tablero.dibuja();
   // tablero.dibujaPieza();
    menu.dibuja();
    glutSwapBuffers();
}

void OnMouseClick(int button, int state, int pantalla_x, int pantalla_y) {
    if (menu.getEstado() == Menu::PAUSA) {
        // Si el estado es PAUSA, no hacer nada
        return;
    }
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
      //  tablero.Selector(pantalla_x, pantalla_y);
        menu.Selector(pantalla_x, pantalla_y);
    }
}

    void OnKeyboard(unsigned char key, int x, int y) 
    {
        std::cout << "Tecla presionada: " << key << std::endl;  // Mensaje de depuración
        menu.tecla(key);
        glutPostRedisplay(); // Asegurarse de que se vuelva a dibujar la pantalla después de una tecla
    }
void resize(int width, int height) {
    glutReshapeWindow(Width, Height);
}

void OnTimer(int value) {
    //tablero.aplicarGravedad();
    //menu.tablero.aplicarGravedad();
    menu.aplicarGravedad();
    // No borrar estas lineas
    glutTimerFunc(1000, OnTimer, 0);
    glutPostRedisplay();
}