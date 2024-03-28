#pragma once

class Selector						//Esta clase se utilizará para definir al selector
{
private:
	int fila, columna;

public:
	Selector();							//Constructor de selector
	void inicializar();					//Este método inicializa el selector
	int getFila();						//Este método duelve la fila original
	int getColumna();					//Este método devuelve la columna original
	void movimiento(unsigned char key);	//Este método permitie mover al selector con el teclado
};