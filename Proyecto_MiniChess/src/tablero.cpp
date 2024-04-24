#include "tablero.h"
#include "iostream"
#include <vector>
#include "freeglut.h"
#include "ETSIDI.h"
#include "peon.h"
#include "alfil.h"
#include "torre.h"
#include "reina.h"
#include "rey.h"
#include "caballo.h"



using namespace std;

Tablero::Tablero()
{
	Vacio vacio = Vacio(0);
	vector<Pieza> columnas;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			columnas.push_back(vacio);
		}
		casillas.push_back(columnas);
	}
}

void Tablero::dibuja()
{
	/*
	for (int i = 0; i < casillas.size(); i++) {
		for (int j = 0; j < casillas.size(); j++) {
			Pieza piezatablero = casillas[i][j];
			cout << piezatablero.dibujaPieza();
		}
		cout << "\n";
	}
	*/
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

}

void Tablero::inicializaTablero()
{
	//Asignamos un número al tipo de pieza
	enum tipospieza{vacio_, torre_, caballo_, alfil_, rey_, reina_, peon_};

	Torre torre = Torre(torre_);
	Caballo caballo = Caballo(caballo_);
	Alfil alfil = Alfil(alfil_);
	Rey rey = Rey(4);
	Reina reina = Reina(5);
	Peon peon = Peon(6);
	//Vacio vacio = Vacio(0);

	int j = 1;
	for (int i = 0; i < casillas.size(); i++) {
		casillas[i][j] = peon;
	}

	j = 6;
	for (int i = 0; i < casillas.size(); i++) {
		casillas[i][j] = peon;
	}

	casillas[0][0] = torre;
	casillas[7][0] = torre;
	casillas[0][7] = torre;
	casillas[7][7] = torre;

	casillas[1][0] = caballo;
	casillas[6][0] = caballo;
	casillas[1][7] = caballo;
	casillas[6][7] = caballo;

	casillas[2][0] = alfil;
	casillas[5][0] = alfil;
	casillas[2][7] = alfil;
	casillas[5][7] = alfil;

	casillas[3][0] = rey;
	casillas[3][7] = rey;

	casillas[4][0] = reina;
	casillas[4][7] = reina;

}
