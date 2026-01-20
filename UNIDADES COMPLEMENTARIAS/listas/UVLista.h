//---------------------------------------------------------------------------

#ifndef UVListaH
#define UVListaH
//---------------------------------------------------------------------------
#include <iostream>
#include <tchar.h>
#include <string>
#include <iomanip>
#include <Graphics.hpp>
using namespace std;

#define MAX 100
#define NULO -1

class Vlista{
	private:

	typedef int Direccion;

	int elementos[MAX];

	public: 	int longitud;
	Vlista();
	int fin();
	int primero();
	int siguiente(int d);
	int anterior(int d);
	bool vacia();
	int recupera(int direcci�n);
	int getlongitud();
	void insertar( int direcci�n,int elemento);
	void inserta_primero(int elemento);
	void inserta_ultimo(int elemento);
	void suprime(int dirección);
	void modifica(int dirección,int elemento);
	void imprimir(TColor FormColor, TCanvas *Canvas);
	void imprimir2(TColor FormColor, TCanvas *Canvas, int posX, int posY);

};


#endif
