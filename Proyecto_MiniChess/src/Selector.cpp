#include "Selector.h"
#include "freeglut.h"

Selector::Selector() {		//Se define el constructor del selector
	fila = 0;
	columna = 0;
}


void Selector::inicializar() {		//Se inicializa el selector
	Selector selector;
}

int Selector::getFila() {			//Retorna la fila en la que se encuentra el selector
	return fila;
}

int Selector::getColumna() {		//Retorna la columna en la que se encuentra el selector
	return columna;
}

void Selector::movimiento(unsigned char key) {		//Se puede mover el selector a través de las teclas deseadas
	switch (key)
	{
	case GLUT_KEY_UP:				//En el caso de que la tecla pulsada sea la flecha de arriba, y que el selector no esté en la última fila, se moverá una fila para arriba
		if (fila < 7) fila++;		
		break;

	case GLUT_KEY_DOWN:				//En el caso de que la tecla pulsada sea la flecha de abajo, y que el selector no esté en la priemra fila, se moverá una fila para abajo
		if (fila > 0) fila--;
		break;
	
	case GLUT_KEY_RIGHT:			//En el caso de que la tecla pulsada sea la flecha de la derecha, y que el selector no esté en la última columna, se moverá una columna para la derecha
		if (columna < 7)
			columna++;
		break;

	case GLUT_KEY_LEFT:				//En el caso de que la tecla pulsada sea la flecha de la izquierda, y que el selector no esté en la primera columna, se moverá una columna para la izquierda
		if (columna > 0)
			columna--;
		break;
	
	}
}