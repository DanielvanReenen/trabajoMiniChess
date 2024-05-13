#pragma once
#include "tablero.h"
#include "pieza.h"
#include<vector>

class Interaccion
{

public:
	void moverPieza(Pieza* pieza, Pieza* vacio, int nuevaFila, int nuevaColumna, vector<vector<Pieza*>>& cas);
};

