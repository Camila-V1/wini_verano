//---------------------------------------------------------------------------

#pragma hdrstop
 #include "UPlista.h"
#include "UC_lista.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
	   colal::colal(){
		//CSmemoria* M =new CSmemoria();;
		   //	ls= new Lista();
//ls= new Vlista();
  ptrlista* ls =new ptrlista();
		}

bool colal::Vacia(){
return ls->vacia();
}void colal::Meter(int e){
ls->insertar(ls->primero(),e);
}
void colal::Sacar(int &e){
ls->recupera(ls->fin());
ls->suprime(ls->fin() );

}
int colal::cima(){

return ls->recupera(ls->primero());

}
 int colal::colaprimero(){
 return ls->recupera(ls->fin());
 }
 void colal::imprimir(TColor FormColor, TCanvas *Canvas){

 ls->imprimir2(FormColor,Canvas,1150,800)   ;
 }


