//---------------------------------------------------------------------------

#ifndef UPtr_conjuntoH
#define UPtr_conjuntoH
#include "UPlista.h"
#define UPlistaH
//---------------------------------------------------------------------------
#include <cmath> // Necesario para sin(), cos() y M_PI
using namespace std;

//defino a direccionL como un struct
struct NodoConj {
	int dato;
	NodoConj* sig;
};

class ptr_conjunto{
	private:
	NodoConj* ptrConj;
	int cant;
	NodoConj* localiza(int e);
	NodoConj* anterior(NodoConj *p);
	public:
   ptr_conjunto();
	void crear();
	 bool vacio();
	 bool pertenece(int e);
	 void inserta (int e );
	 void suprime(int e);
	 int cardinal();
	 int ordinal(int e)   ;
	 int muestrea();
     int primero();
  int elemento(int pos) ;
	void imprimir(TColor FormColor, TCanvas *Canvas);
   void mostrarEnCirculo(int centerX, int centerY, int radio, TColor color, TCanvas *Canvas);
	 void Pintado(int posX, int posY, String cad, TColor color, TCanvas *Canvas);

};
#endif
