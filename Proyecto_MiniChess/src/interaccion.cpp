#include "interaccion.h"

void Interaccion::moverPieza(Pieza* pieza, Pieza* vacio, int nuevaFila, int nuevaColumna, vector<vector<Pieza*>>& cas)
{
	int columnaActual = pieza->getColumna();
	int filaActual = pieza->getFila();
	
	pieza->setColumna(nuevaColumna);
	pieza->setFila(nuevaFila);

	cas[nuevaColumna][nuevaFila] = pieza;
	cas[columnaActual][filaActual] = vacio;
}
