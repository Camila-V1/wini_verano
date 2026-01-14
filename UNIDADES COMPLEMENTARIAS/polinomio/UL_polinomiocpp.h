
#include "UCSLista.h"
#include "UPlista.h"
#include "Umemoria.h"
#ifndef UL_polinomiocppH
#define UL_polinomiocppH
//---------------------------------------------------------------------------

class polinomioL {
private:
 Lista* ls;
//Vlista* ls;

public:
	 polinomioL();
        polinomioL(CSmemoria* M);
	 int BuscarExponente(int e);  int BuscarTerminoN(int e);
   void  crear(CSmemoria* M);
 bool EsCero();
 int Grado();
 void ponercero();
    int coeficiente(int Exp);
    void AsignarCoeficiente(int coef, int exp);
	void poner_termino(int coef, int exp);
    void poner_termino2(int coef, int exp);
    int numero_terminos();
	int exponente(int nroter);
	void sumar(polinomioL* p1, polinomioL* p2);
	void restar(polinomioL* p1, polinomioL*  p2);
	void multiplicar(polinomioL*  P1, polinomioL*  P2);
	void imprimir(TColor FormColor, TCanvas *Canvas);
		void imprimir2(TColor FormColor, TCanvas *Canvas,int x,int y);
	void poner_en_cero();
	void vaciar();


    // Inserta en L como vector denso de coeficientes: <c0,c1,...,ck>
    void a_lista_densa(Lista* L);

    // Inserta en L como pares coef-exp sólo para términos ≠ 0: <c1,e1,c2,e2,...>
	void a_lista_pares(Lista* L);

};

#endif
