#pragma once

#include "pieza.h"
#include "torre.h"
#include "caballo.h"
#include "alfil.h"
#include "rey.h"
#include "reina.h"
#include "peon.h"
#include <vector>

using std::vector;

class ListaPiezas
{
private:
	vector<Pieza*> lista;
public:
	ListaPiezas() = default;
	void agregar(Pieza *p) { lista.push_back(p); }
	//void dibujaPiezas() { for (auto e : lista) e->dibujaPiezas(); }
	Pieza* getPieza(int index);
	inline int size() { return static_cast<int>(lista.size()); }
};



