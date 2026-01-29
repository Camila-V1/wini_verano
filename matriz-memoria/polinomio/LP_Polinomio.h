//---------------------------------------------------------------------------
 #include "UPlista.h"
#ifndef LP_PolinomioH
#define LP_PolinomioH
#include "UPlista.h"
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <iomanip>
#include <Graphics.hpp>

//defino a direccionL como un struct
ptrlista* ls;
class LP_polinomio{
	private:

		  int longitud;
			Nodolista* BuscarExponente(int e);
		   Nodolista* BuscarTerminoN(int e);
	public:

			  LP_polinomio();
 bool EsCero();
 int Grado();
 void ponercero();
    int coeficiente(int Exp);
    void AsignarCoeficiente(int coef, int exp);
    void poner_termino(int coef, int exp);
    int numero_terminos();
	int exponente(int nroter);
    Nodolista* BuscarExponente1(int e);
   //	void sumar(polinomioL* p1, polinomioL* p2);
	//void restar(polinomioL* p1, polinomioL*  p2);
   //	void multiplicar(polinomioL*  P1, polinomioL*  P2);
	void imprimir(TColor FormColor, TCanvas *Canvas);
	void poner_en_cero();
};
#endif

