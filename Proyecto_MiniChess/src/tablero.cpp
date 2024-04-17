#include "tablero.h"
#include "iostream"
#include <vector>


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
	for (int i = 0; i < casillas.size(); i++) {
		for (int j = 0; j < casillas.size(); j++) {
			 Pieza piezatablero = casillas[i][j];
			 cout << piezatablero.dibujaPieza();
		}
		cout << "\n";
	}
}

void Tablero::creaTablero()
{
	
	Torre torre = Torre(1);
	Caballo caballo = Caballo(2);
	Alfil alfil = Alfil(3);
	Rey rey = Rey(4);
	Reina reina = Reina(5);
	Peon peon = Peon(6);
	Vacio vacio = Vacio(0);
	
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
