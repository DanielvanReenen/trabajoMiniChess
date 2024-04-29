#include "tablero.h"
#include "iostream"
#include <vector>
#include "freeglut.h"
#include "ETSIDI.h"

using namespace std;



Tablero::Tablero()
{
	Vacio* vacio = new Vacio(0);
	vector<Pieza*> columnas;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			columnas.push_back(vacio);
		}
		casillas.push_back(columnas);
	}
}

void Tablero::inicializaTablero()
{
	for(int i = 0; i < 2; i++) {
		Coordenada posinicial = coordenadaenTablero[0 + i * 56];
		Torre* torreaux = new Torre(posinicial, i);
		piezas.agregar(torreaux);
		posinicial = coordenadaenTablero[7 + i * 56];
		Torre* torreaux1 = new Torre(posinicial, i);
		piezas.agregar(torreaux1);
		
		posinicial = coordenadaenTablero[1 + i * 56];
		Caballo* caballoaux = new Caballo(posinicial, i);
		piezas.agregar(caballoaux);
		posinicial = coordenadaenTablero[6 + i * 56];
		Caballo* caballoaux1 = new Caballo(posinicial, i);
		piezas.agregar(caballoaux1);

		posinicial = coordenadaenTablero[2 + i * 56];
		Alfil* alfilaux = new Alfil(posinicial, i);
		piezas.agregar(alfilaux);
		posinicial = coordenadaenTablero[5 + i * 56];
		Alfil* alfilaux1 = new Alfil(posinicial, i);
		piezas.agregar(alfilaux1);

		posinicial = coordenadaenTablero[4 + i * 56];
		Rey* reyaux = new Rey(posinicial, i);
		piezas.agregar(reyaux);

		posinicial = coordenadaenTablero[3 + i * 56];
		Reina* reinaaux = new Reina(posinicial, i);
		piezas.agregar(reinaaux);

		for (int j = 0; j < 8; j++) {
			posinicial = coordenadaenTablero[j + 8 + i * 40];
			Peon* peonesaux = new Peon(posinicial, i);
			piezas.agregar(peonesaux);
		}
	}
	/*
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
	*/
}

void Tablero::CoordenadasaCasillas()
{
	int k = 0;
	for (float i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			coordenadaenTablero[k].x = (0.93 - 0.23 * i);
			coordenadaenTablero[k].y = (-0.675 + 0.23 * j);
			k++;
		}
	}
	//El incremento correcto es de 0.23
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
