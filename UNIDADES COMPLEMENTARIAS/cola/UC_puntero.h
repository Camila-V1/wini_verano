//---------------------------------------------------------------------------

#ifndef UC_punteroH
#define UC_punteroH
#include <vcl.h>
//---------------------------------------------------------------------------
struct Nodopc {
	int dato;
	Nodopc* sig;
};

class ptr_cola {
	private:
	Nodopc* ini;
	Nodopc* fin;


	public:
    	int cant;
	ptr_cola();
	bool vacia();
	int recupera(Nodopc* d);
	Nodopc* primero();
	Nodopc* ultimo();
	void Meter(int e);
	void Sacar(int &e);
	int frente();
	int final();
	void imprimir(TColor FormColor, TCanvas *Canvas);
};
#endif
