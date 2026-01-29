//---------------------------------------------------------------------------

#pragma hdrstop

#include "UC_listaPcpp.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
	  colalp::colalp(){
		//CSmemoria* M =new CSmemoria();;
		  //	ls= new Lista();
//ls= new Vlista();
 ptrlista* ls =new ptrlista();
		}

bool colalp::Vacia(){
return ls->vacia();
}void colalp::Meter(int e){
ls->insertar(ls->primero(),e);
}
void colalp::Sacar(int &e){
ls->recupera(ls->fin());
ls->suprime(ls->fin() );

}
int colalp::cima(){

return ls->recupera(ls->primero());

}
 int colalp::colaprimero(){
 return ls->recupera(ls->fin());
 }
 void colalp::imprimir(TColor FormColor, TCanvas *Canvas){

 ls->imprimir2(FormColor,Canvas,1150,800)   ;
 }