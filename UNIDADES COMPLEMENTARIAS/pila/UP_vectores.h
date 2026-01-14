//---------------------------------------------------------------------------

#ifndef UP_vectoresH
#define UP_vectoresH
#include <vcl.h>
//---------------------------------------------------------------------------
using namespace std;

class pilav{
	private:

	public:

	static const int MAXXX = 100;
	static const int NULO = -1;
	typedef int Direccion;

	int elementos[MAXXX];
		int tope;

		int longitud;
  pilav();

  bool vacio();
  void Meter(int e);
  void Sacar(int &e);
  int cima();
 void imprimir(TColor FormColor, TCanvas *Canvas);
  	void imprimir(TColor FormColor, TCanvas *Canvas,  int posX ,int posY) ;

};

#endif
