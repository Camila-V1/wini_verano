//---------------------------------------------------------------------------

#ifndef UMS_polinomioH
#define UMS_polinomioH
#include "Umemoria.h"
//---------------------------------------------------------------------------
using namespace std;
struct Nodop{
	int coef;
	int Exp;
	int sig;
};
//defino a direccionL como un struct
  const int nulo = -1;

class polinomioM{
	private:

	   int nt;

int ptrp;

		CSmemoria* Cm;
	public: int BuscarExponente(int Exp);
int  BuscarTerminoN(int T);
	 polinomioM();
	 polinomioM(CSmemoria* m);
   void  crear();
 bool EsCero();
 int Grado();
	int coeficiente(int Exp);
    int coefN(int N);
    void AsignarCoeficiente(int coef, int exp);
	void poner_termino(int coef, int exp);
    int numero_terminos();
	int exponente(int nroter);
	void sumar(polinomioM p1, polinomioM p2);
	void restar(polinomioM p1, polinomioM p2);
	void multiplicar(polinomioM P1, polinomioM P2);
	void imprimir(TColor FormColor, TCanvas *Canvas);
    	void imprimir2(TColor FormColor, TCanvas *Canvas,int x,int y);

	void vaciar( ) ;
	void poner_termino_ordenado(int coef, int exp);
	void poner_en_cero();
};
#endif


