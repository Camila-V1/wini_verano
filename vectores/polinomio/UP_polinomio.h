//---------------------------------------------------------------------------
  #include "UPlista.h"
#ifndef UP_polinomioH
#define UP_polinomioH
//---------------------------------------------------------------------------

	struct Nodopr {
    int Coef;
    int Exp;
	Nodopr* sig;
};

class PolinomioP {
private:
	Nodopr* ptrpl;
	int Nt;

	Nodopr* BuscarExponente(int Exp);
	Nodopr* BuscarTerminoN(int Nt);

public:   PolinomioP();
   void crear();
	bool esCero();
    int Grado();
    int coeficiente(int Exp);
    void AsignarCoeficiente(int coef, int exp);
    void poner_termino(int coef, int exp);
    int numero_terminos();
	int exponente(int ntro);
	Nodopr* BuscarTermino(int i);
	void sumar(PolinomioP P1, PolinomioP P2);
	void restar(PolinomioP P1, PolinomioP P2);
	void multiplicar(PolinomioP P1, PolinomioP P2);
		void imprimir(TColor FormColor, TCanvas *Canvas);
		void Pintado(int posX, int posY, String cad, TColor color, TCanvas *Canvas);
};
#endif
