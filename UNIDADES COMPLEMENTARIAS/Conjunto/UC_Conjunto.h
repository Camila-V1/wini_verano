//---------------------------------------------------------------------------

#ifndef UC_ConjuntoH
#define UC_ConjuntoH
//---------------------------------------------------------------------------

#define MAXX 100
#define NULO -1

class conjunto{
	private:

	typedef int Direccion;

	int elemento[MAXX];

	int longitud;
	 public   :
	 void crear();
	 bool vacio();
	 bool pertenece(int e);
	 void inserta (int e );
	 void suprime(int e);
	 int cardinal();
	 int getvalor(int x);
	 int ordinal(int e)   ;
	 int muestrea();
	 int primero();
	 int generarNumeroAleatorio() ;
    void imprimir(TColor FormColor, TCanvas *Canvas);
};

#endif
