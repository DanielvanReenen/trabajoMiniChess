#include <iostream>
#include "tablero.h"
#include <vector>
#include "freeglut.h"
#include "ETSIDI.h"


Tablero tablero;
Pieza piezas;

void OnDraw(void);
void OnMouseClick(int button, int state, int pantalla_x, int pantalla_y);


int main(int argc, char* argv[]) {

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
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Chess Wars");

	glClearColor(0, 0, 0, 1);
	glColor3f(1.f, 0, 0);
	glOrtho(700, 0, 700, 0, -1, 1);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
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
	piezas.dibujaPieza();

	glutSwapBuffers();
}

void OnMouseClick(int button, int state, int pantalla_x, int pantalla_y) {
	std::cout << "Boton: " << button << ", Stado: " << state << std::endl;
	std::cout << "Coordenadas: (" << pantalla_x << ", " << pantalla_y << ")" << std::endl;
	
//Despues de la comprobacion de que el boton funciona, hacemos que siempre que se fulse el boton pase algo
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		 //Aqui es donde pondr�amos el codigo de cambio de color de las casillas seleccionadas y dem�s
		}
}