#include<iostream>
#include "tablero.h"
#include<vector>

Tablero tablero;
Pieza piezas;

void OnDraw(void);

int main(int argc, char* argv[]) {

	tablero.creaTablero();

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
	//Inicializar el gestor de ventanas GLUT
		//y crear la ventana

	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Chess Wars");

	glClearColor(0, 0, 0, 1);
	glColor3f(1.f, 0, 0);
	glOrtho(700, 0, 700, 0, -1, 1);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);

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

