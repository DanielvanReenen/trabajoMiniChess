#pragma once

class Selector						//Esta clase se utilizar� para definir al selector
{
private:
	int fila, columna;

public:
	Selector();							//Constructor de selector
	void inicializar();					//Este m�todo inicializa el selector
	int getFila();						//Este m�todo duelve la fila original
	int getColumna();					//Este m�todo devuelve la columna original
	void movimiento(unsigned char key);	//Este m�todo permitie mover al selector con el teclado
};