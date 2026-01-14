//---------------------------------------------------------------------------

#ifndef UC_vectoresH
#define UC_vectoresH
#include <vcl.h>
//---------------------------------------------------------------------------

const int maxx = 100;
class colaV1 {
    private:



	public:	int V[100];
	   int ini;
		int fin;
        colaV1();
        bool vacia();
		void Meter(int e);
		void Sacar(int &e);
		int primero();
		void imprimir(TColor FormColor, TCanvas *Canvas) ;
	    int ultimoElemento();       // Devuelve el �ltimo elemento de la cola
		void SacarUltimo(int &e);   // Elimina el �ltimo elemento de la cola
		void MeterAlPrincipio(int e);
};
#endif
