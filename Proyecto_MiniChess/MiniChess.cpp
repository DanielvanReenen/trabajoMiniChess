#include <iostream>
#include "tablero.h"
#include <vector>
#include "freeglut.h"
#include "ETSIDI.h"
#include "interaccion.h"

Tablero tablero;
Interaccion interaccion;

void OnDraw(void);
void OnMouseClick(int button, int state, int pantalla_x, int pantalla_y);
void resize(int width, int height);

float Width = 785;
float Height = 785; //max height = 785

int main(int argc, char* argv[]) {
	tablero.CasillasaCoordenadas();
	tablero.inicializaTablero();
	
	/*
	do  {
		int posfila;
		int poscolumna;
		do {
			cin >> posfila;
			cin >> poscolumna;
		} while (posfila > 8 && poscolumna > 8);
		posfila = posfila--;
		poscolumna = poscolumna--;


	} while (tablero.finalJuego = false);
	*/

	//Inicializar el gestor de ventanas GLUT y crear la ventana

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(371, 0);
	glutInitWindowSize(Width, Height);
	glutCreateWindow("Chess Wars");

	glutDisplayFunc(OnDraw);
	glutReshapeFunc(resize);
	

	glClearColor(0, 0, 0, 1);
	glColor3f(1.f, 0, 0);
	glOrtho(785, 0, 785, 0, -1, 1);

	//Registrar los callbacks
	

	glutMouseFunc(OnMouseClick);

	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();

	return 0;
}

void OnDraw(void) {
	//Borrado de la pantalla	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	tablero.dibuja();
	tablero.dibujaPieza();

	glutSwapBuffers();
}

void OnMouseClick(int button, int state, int pantalla_x, int pantalla_y) {
	std::cout << "Boton: " << button << ", Stado: " << state << std::endl;
	std::cout << "Coordenadas: (" << pantalla_x << ", " << pantalla_y << ")" << std::endl;
	
//Despues de la comprobacion de que el boton funciona, hacemos que siempre que se fulse el boton pase algo
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
			tablero.selectorRaton(pantalla_x, pantalla_y);
			std::cout << "Usted ha pinchado en la casilla: (" << tablero.selector.getFila() << ", " << tablero.selector.getColumna() << ")" << std::endl;
		}
}



void resize(int width, int height) {
	glutReshapeWindow(Width, Height);
}