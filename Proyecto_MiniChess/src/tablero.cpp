#include "tablero.h"
#include "iostream"
#include <vector>
#include "freeglut.h"
#include "ETSIDI.h"



Tablero::Tablero()
{
	vector<Pieza*> columnas(8, nullptr); // Inicializa cada fila con 8 punteros nulos
	for (int i = 0; i < 8; i++) {
		casillas.push_back(columnas);
	}
}



Tablero::~Tablero() {
	for (auto& fila : casillas) {
		for (auto& pieza : fila) {
			delete pieza;
		}
	}
}

void Tablero::inicializaTablero()
{
	//oordenada pos = { 100, 100 };
	//Vacio* vacio = new Vacio(pos, 100, 100, 100);

	enum {blanco, negro};

	int columna = 0;
	int fila = 0;
	Coordenada posinicial = coordenadaSobreTablero[columna * 8 + fila];
	Torre* torreblanca = new Torre(posinicial, blanco, columna, fila);
	
	columna = 0; 
	fila = 7;
	posinicial = coordenadaSobreTablero[columna * 8 + fila];
	Torre* torreblanca1 = new Torre(posinicial, blanco, columna, fila);

	columna = 7;
	fila = 0;
	posinicial = coordenadaSobreTablero[columna * 8 + fila];
	Torre* torrenegra = new Torre(posinicial, negro, columna, fila);

	columna = 7;
	fila = 7;
	posinicial = coordenadaSobreTablero[columna * 8 + fila];
	Torre* torrenegra1 = new Torre(posinicial, negro, columna, fila);

	
	columna = 0;
	fila = 1;
	posinicial = coordenadaSobreTablero[columna * 8 + fila];
	Caballo* caballoblanco = new Caballo(posinicial, blanco, columna, fila);
	
	columna = 0;
	fila = 6;
	posinicial = coordenadaSobreTablero[columna * 8 + fila];
	Caballo* caballoblanco1 = new Caballo(posinicial, blanco, columna, fila);
	
	columna = 7;
	fila = 1;
	posinicial = coordenadaSobreTablero[columna * 8 + fila];
	Caballo* caballonegro = new Caballo(posinicial, negro, columna, fila);
	
	columna = 7;
	fila = 6;
	posinicial = coordenadaSobreTablero[columna * 8 + fila];
	Caballo* caballonegro1 = new Caballo(posinicial, negro, columna, fila);

	
	columna = 0;
	fila = 2;
	posinicial = coordenadaSobreTablero[columna * 8 + fila];
	Alfil* alfilblanco = new Alfil(posinicial, blanco, columna, fila);
	
	columna = 0;
	fila = 5;
	posinicial = coordenadaSobreTablero[columna * 8 + fila];
	Alfil* alfilblanco1 = new Alfil(posinicial, blanco, columna, fila);
	
	columna = 7;
	fila = 2;
	posinicial = coordenadaSobreTablero[columna * 8 + fila];
	Alfil* alfilnegro = new Alfil(posinicial, negro, columna, fila);
	
	columna = 7;
	fila = 5;
	posinicial = coordenadaSobreTablero[columna * 8 + fila];
	Alfil* alfilnegro1 = new Alfil(posinicial, negro, columna, fila);

	
	columna = 0;
	fila = 3;
	posinicial = coordenadaSobreTablero[columna * 8 + fila];
	Rey* reyblanco = new Rey(posinicial, blanco, columna, fila);
	
	columna = 7;
	fila = 3;
	posinicial = coordenadaSobreTablero[columna * 8 + fila];
	Rey* reynegro = new Rey(posinicial, negro, columna, fila);

	
	columna = 0;
	fila = 4;
	posinicial = coordenadaSobreTablero[columna * 8 + fila];
	Reina* reinablanca = new Reina(posinicial, blanco, columna, fila);
	
	columna = 7;
	fila = 4;
	posinicial = coordenadaSobreTablero[columna * 8 + fila];
	Reina* reinanegra = new Reina(posinicial, negro, columna, fila);

	
	columna = 1;
	fila = 0;
	posinicial = coordenadaSobreTablero[columna * 8 + fila];
	Peon* peonblanco = new Peon(posinicial, blanco, columna, fila);
	
	columna = 1;
	fila = 1;
	posinicial = coordenadaSobreTablero[columna * 8 + fila];
	Peon* peonblanco1 = new Peon(posinicial, blanco, columna, fila);
	
	columna = 1;
	fila = 2;
	posinicial = coordenadaSobreTablero[columna * 8 + fila];
	Peon* peonblanco2 = new Peon(posinicial, blanco, columna, fila);;
	
	columna = 1;
	fila = 3;
	posinicial = coordenadaSobreTablero[columna * 8 + fila];
	Peon* peonblanco3 = new Peon(posinicial, blanco, columna, fila);
	
	columna = 1;
	fila = 4;
	posinicial = coordenadaSobreTablero[columna * 8 + fila];
	Peon* peonblanco4 = new Peon(posinicial, blanco, columna, fila);
	
	columna = 1;
	fila = 5;
	posinicial = coordenadaSobreTablero[columna * 8 + fila];
	Peon* peonblanco5 = new Peon(posinicial, blanco, columna, fila);
	
	columna = 1;
	fila = 6;
	posinicial = coordenadaSobreTablero[columna * 8 + fila];
	Peon* peonblanco6 = new Peon(posinicial, blanco, columna, fila);
	
	columna = 1;
	fila = 7;
	posinicial = coordenadaSobreTablero[columna * 8 + fila];
	Peon* peonblanco7 = new Peon(posinicial, blanco, columna, fila);

	
	columna = 6;
	fila = 0;
	posinicial = coordenadaSobreTablero[columna * 8 + fila];
	Peon* peonnegro = new Peon(posinicial, negro, columna, fila);
	
	columna = 6;
	fila = 1;
	posinicial = coordenadaSobreTablero[columna * 8 + fila];
	Peon* peonnegro1 = new Peon(posinicial, negro, columna, fila);
	
	columna = 6;
	fila = 2;
	posinicial = coordenadaSobreTablero[columna * 8 + fila];
	Peon* peonnegro2 = new Peon(posinicial, negro, columna, fila);
	
	columna = 6;
	fila = 3;
	posinicial = coordenadaSobreTablero[columna * 8 + fila];
	Peon* peonnegro3 = new Peon(posinicial, negro, columna, fila);

	columna = 6;
	fila = 4;
	posinicial = coordenadaSobreTablero[columna * 8 + fila];
	Peon* peonnegro4 = new Peon(posinicial, negro, columna, fila);
	
	columna = 6;
	fila = 5;
	posinicial = coordenadaSobreTablero[columna * 8 + fila];
	Peon* peonnegro5 = new Peon(posinicial, negro, columna, fila);
	
	columna = 6;
	fila = 6;
	posinicial = coordenadaSobreTablero[columna * 8 + fila];
	Peon* peonnegro6 = new Peon(posinicial, negro, columna, fila);

	columna = 6;
	fila = 7;
	posinicial = coordenadaSobreTablero[columna * 8 + fila];
	Peon* peonnegro7 = new Peon(posinicial, negro, columna, fila);

	casillas[0][0] = torreblanca;
	casillas[0][1] = caballoblanco;
	casillas[0][2] = alfilblanco;
	casillas[0][3] = reyblanco;
	casillas[0][4] = reinablanca;
	casillas[0][5] = alfilblanco1;
	casillas[0][6] = caballoblanco1;
	casillas[0][7] = torreblanca1;

	casillas[1][0] = peonblanco;
	casillas[1][1] = peonblanco1;
	casillas[1][2] = peonblanco2;
	casillas[1][3] = peonblanco3;
	casillas[1][4] = peonblanco4;
	casillas[1][5] = peonblanco5;
	casillas[1][6] = peonblanco6;
	casillas[1][7] = peonblanco7;

	casillas[6][0] = peonnegro;
	casillas[6][1] = peonnegro1;
	casillas[6][2] = peonnegro2;
	casillas[6][3] = peonnegro3;
	casillas[6][4] = peonnegro4;
	casillas[6][5] = peonnegro5;
	casillas[6][6] = peonnegro6;
	casillas[6][7] = peonnegro7;

	casillas[7][0] = torrenegra;
	casillas[7][1] = caballonegro;
	casillas[7][2] = alfilnegro;
	casillas[7][3] = reynegro;
	casillas[7][4] = reinanegra;
	casillas[7][5] = alfilnegro1;
	casillas[7][6] = caballonegro1;
	casillas[7][7] = torrenegra1;

	
	/*
	torreblanca->setCasilla(16);
	casillas[2][0] = torreblanca;
	casillas[0][0] = vacio;
	Debuggeando movimientos || problemas con su representacion
	*/
}

void Tablero::dibujaPieza() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (casillas[i][j] != nullptr) {
				casillas[i][j]->dibujaPieza();
			}
		}
	}
}

Pieza* Tablero::getPieza(int columna, int fila) {
	if (fila < 0 || fila >= 8 || columna < 0 || columna >= 8) {
		return nullptr; // Verifica si la coordenada está dentro de los límites del tablero
	}
	return casillas[columna][fila];
}

void Tablero::selectorRaton(int x, int y)
{
	//selector.origen();
	selector.raton(x, y, *this);
}

void Tablero::aplicarGravedad()
{
	for (int i = 0; i < 8; i++) {
		for (int j = 6; j >= 0; j--) {
			// Buscar la posición más baja disponible
			if (casillas[i][j] != nullptr) {
				int nuevaFilaGravitatoria = casillas[i][j]->getFila();
				while (nuevaFilaGravitatoria < 7 && (casillas[i][nuevaFilaGravitatoria + 1] == nullptr)) {
					nuevaFilaGravitatoria++;
			}

			// Mover la pieza a la nueva posición
			if (nuevaFilaGravitatoria != casillas[i][j]->getFila()) {
				casillas[i][nuevaFilaGravitatoria] = casillas[i][j];
				casillas[i][j] = nullptr;
				casillas[i][nuevaFilaGravitatoria]->setFila(nuevaFilaGravitatoria);
				casillas[i][nuevaFilaGravitatoria]->setPosicion(coordenadaSobreTablero[casillas[i][nuevaFilaGravitatoria]->getColumna() * 8 + casillas[i][nuevaFilaGravitatoria]->getFila()]);
			}
			}
		}
	}
	
}

void Tablero::dibuja()
{
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

void Tablero::CasillasaCoordenadas()
{
	int k = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			coordenadaSobreTablero[k].x = (0.93 - 0.23 * i);
			coordenadaSobreTablero[k].y = (-0.675 + 0.23 * j);
			k++;
		}
	}
	//El incremento correcto es de 0.23
}