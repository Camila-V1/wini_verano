//---------------------------------------------------------------------------

#ifndef UC_ConjuntoH
#define UC_ConjuntoH
//---------------------------------------------------------------------------


class conjunto{
	private:

	static const int m = 100;
	static const int NULO = -1;
	typedef int Direccion;

              static const int MAXX = 100;
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
