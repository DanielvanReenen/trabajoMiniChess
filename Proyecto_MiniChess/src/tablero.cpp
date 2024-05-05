#include "tablero.h"
#include "iostream"
#include <vector>
#include "freeglut.h"
#include "ETSIDI.h"


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
		Torre* torreaux = new Torre(i, 0 + i * 56);
		piezas.agregar(torreaux);
		Torre* torreaux1 = new Torre(i, 7 + i * 56);
		piezas.agregar(torreaux1);
		
		Caballo* caballoaux = new Caballo(i, 1 + i * 56);
		piezas.agregar(caballoaux);
		Caballo* caballoaux1 = new Caballo(i, 6 + i * 56);
		piezas.agregar(caballoaux1);

		Alfil* alfilaux = new Alfil(i, 2 + i * 56);
		piezas.agregar(alfilaux);
		Alfil* alfilaux1 = new Alfil(i, 5 + i * 56);
		piezas.agregar(alfilaux1);

		Rey* reyaux = new Rey(i, 3 + i * 56);
		piezas.agregar(reyaux);
		
		Reina* reinaaux = new Reina(i, 4 + i * 56);
		piezas.agregar(reinaaux);

		for (int j = 0; j < 8; j++) {
			Peon* peonesaux = new Peon(i, j + 8 + i * 40);
			piezas.agregar(peonesaux);
		}
	}
	

	
	//Asignamos un número al tipo de pieza
	enum tipospieza{vacio_, torre_, caballo_, alfil_, rey_, reina_, peon_};

	Torre* torre = new Torre(1);
	Caballo* caballo = new Caballo(2);
	Alfil* alfil = new Alfil(3);
	Rey* rey = new Rey(4);
	Reina* reina = new Reina(5);
	Peon* peon = new Peon(6);
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

	casillas[4][0] = rey;
	casillas[4][7] = rey;

	casillas[3][0] = reina;
	casillas[3][7] = reina;
	
}

void Tablero::dibuja()
{
	/*
	for (int i = 0; i < casillas.size(); i++) {
		for (int j = 0; j < casillas.size(); j++) {
			Pieza* piezatablero = casillas[i][j];
			cout << piezatablero;
		}
		cout << "\n";
	}*/
}
