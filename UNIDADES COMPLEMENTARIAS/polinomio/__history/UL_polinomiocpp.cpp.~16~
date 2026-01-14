//---------------------------------------------------------------------------

#pragma hdrstop

	#include "Umemoria.h"
#include "UL_polinomiocpp.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
 polinomioL::polinomioL(){
 //CSmemoria* M=new  CSmemoria;
//ls= new Lista(M); //ver el constructor de la clase lista a usar
//ls= new Vlista();
 }

 polinomioL::polinomioL(CSmemoria* M){
ls= new Lista(M);
//ls= new Vlista();
 }

 int polinomioL::exponente(int i){

int dir=BuscarTerminoN(i);

if (dir!=NULO) {
int x =  ls->siguiente(dir);
 x=ls->recupera(x);
			 return x;
}
 // Retorna el exponente del t�rmino
 }
   void  polinomioL::crear(CSmemoria* M){

   //	ls= new Lista(M); //ver el constructor de la clase lista a usar
//ls = new ptrlista();
//ls= new Vlista();
   }
int polinomioL::BuscarExponente(int e){

				int dir =ls->siguiente(ls->primero());

				 int x,q;

				 q=ls->recupera(dir);
				  int direxp=-1;
			 if (dir!=NULO) {

						 while (dir!=NULO&&direxp==-1&&dir<=ls->fin())
							{
									   if (dir<=ls->fin()) {
									  if (ls->recupera(dir)==e) {
									return  direxp=dir;}

											 dir=ls->siguiente(ls->siguiente(dir));
									}


			  }
						   return direxp;
							}  return NULO;


   }


   int polinomioL::BuscarTerminoN(int e){
   int dir=ls->primero();
   int nt=0;
   if (dir!=-1) {
	   int dirter=-1;
	   while (dir!=NULO&&dirter==-1) {
		   nt=nt+1;
		   if (nt==e) {
					 dirter=dir;
		   }
			dir=ls->siguiente(ls->siguiente(dir));
	   }return dirter;
   }else return -1;

   }
   bool polinomioL::EsCero(){
   return (ls->getlongitud());
   }

   int polinomioL::Grado(){
   int dir=ls->siguiente(ls->primero());
   if (dir!=NULO) {
		int MaxG =ls->recupera(dir);
		while (dir!=NULO&&dir<=ls->fin()){
		 if (ls->recupera(dir)>MaxG) {
			 MaxG=ls->recupera(dir);
		 }
		 dir=ls->siguiente(ls->siguiente(dir));
		} return MaxG;
   }else return-1;
   }


   int polinomioL::coeficiente(int exp){
   int dir =BuscarExponente(exp);
   if (dir!=-1) {
	   return ls->recupera(ls->anterior(dir));
   } else return -1;
   }

	void polinomioL::AsignarCoeficiente(int coef, int exp){
	int dir = BuscarExponente(exp);
	if (dir!=-1) {
		int dirCoef=ls->anterior(dir);
		ls->modifica(dirCoef,coef);
		if (coef==0) {
			ls->suprime(dir);
			ls->suprime(dirCoef);

		}
    }
	}

	void polinomioL::poner_termino(int coef, int exp){
	int direxp = BuscarExponente(exp);
	if (direxp!=-1) {
		int dirCoef = ls->anterior(direxp);
		ls->modifica(dirCoef,ls->recupera((dirCoef))+coef);
		if (ls->recupera(dirCoef)==0) {
			ls->suprime(direxp);
			ls->suprime(dirCoef);
		}
	} else{
	if (coef!=0) {
	   ls->inserta_ultimo(exp);
		   ls->insertar(ls->fin(),coef);
	}

	}
	}



	int polinomioL::numero_terminos(){
	return ls->getlongitud()/2;
	}
	 void polinomioL::ponercero(){
	 int p=ls->primero();
	 while (ls->longitud){
	 ls->suprime(p);
	 p=ls->siguiente(p);

	 }
	 }
void polinomioL::sumar(polinomioL* p1, polinomioL* p2){
	ponercero();  int ex,co;
	for (int i = 0; i=numero_terminos(); i++) {
	ex= p1->exponente(i);
	co=p1->coeficiente(ex);
	poner_termino(co,ex);
	}  for (int i = 0; i=numero_terminos(); i++) {
	ex= p2->exponente(i);
	co=p2->coeficiente(ex);
	poner_termino(co,ex);
	}
}
void polinomioL::restar(polinomioL* p1, polinomioL* p2){
ponercero();
	 int ex,co;
	for (int i = 0; i=numero_terminos(); i++) {
	ex= p1->exponente(i);
	co=p1->coeficiente(ex);
	poner_termino(co,ex);
	}  for (int i = 0; i=numero_terminos(); i++) {
	ex= p2->exponente(i);
	co=p2->coeficiente(ex)*-1;
	poner_termino(co,ex);
	}
}
void polinomioL::imprimir2(TColor FormColor, TCanvas *Canvas, int x,int y){

ls->imprimir2(FormColor,Canvas,x,y);

}
void polinomioL::imprimir(TColor FormColor, TCanvas *Canvas){

ls->imprimir2(FormColor,Canvas,200,700);

}
   void polinomioL::vaciar(){
   ls->elimLista();
   }
