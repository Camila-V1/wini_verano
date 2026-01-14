//---------------------------------------------------------------------------
#ifndef ColaConPilasH
#define ColaConPilasH

#include "UP_memoria.h"
  #include "UP_vectores.h"
#include "UP_vectores.h"
class colaConPilas {
private:

	  // pilav* pilaOriginal;
		   pilav* cBJR;
public:
	colaConPilas();
    bool vacia();
	void meter(int valor);
	bool sacar(int& valor);
	void imprimir(TColor color, TCanvas* canvas);
    String imprimirComoCola();
};

#endif

