#pragma once
class Pieza
{
private:
	int valorNumerico;
public:
	Pieza() = default;
	Pieza(int valor) : valorNumerico(valor) {};
	~Pieza();
	int dibujaPieza();
	/*Pieza getPieza();*/
	void setPieza();
	void MoverPieza();
	void ComerPieza();
};

class Torre:public Pieza
{
public:
	Torre(int valor) : Pieza(valor) {};
	void MoverTorre();
};

class Caballo:public Pieza
{
public:
	Caballo(int valor) : Pieza(valor) {};
	void MoverCaballo();
};

class Alfil:public Pieza
{
public:
	Alfil(int valor) : Pieza(valor) {};
	void MoverAlfil();
};

class Rey:public Pieza
{
public:
	Rey(int valor) : Pieza(valor) {};
	void MoverRey();
};

class Reina:public Pieza
{
public:
	Reina(int valor) : Pieza(valor) {};
	void MoverReina();
};

class Peon:public Pieza
{
public:
	Peon(int valor) : Pieza(valor) {};
	void moverPeon();
	void comerPeon();
};

class Vacio:public Pieza
{
public:
	Vacio(int valor) : Pieza(valor) {};
};