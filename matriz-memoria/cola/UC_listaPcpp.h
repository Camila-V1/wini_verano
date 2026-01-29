//---------------------------------------------------------------------------
 #include "UPlista.h"
#ifndef UC_listaPcppH
#define UC_listaPcppH
//---------------------------------------------------------------------------

class colalp {
private:
 //Lista* ls;
    ptrlista* ls;
//Vlista* ls;

public:
	colalp();
   //pilal(CSmemoria* M);

  bool Vacia();
  void Meter(int e);
  void Sacar(int &e);
  int cima();
  int colaprimero();
 void imprimir(TColor FormColor, TCanvas *Canvas);
};
#endif
