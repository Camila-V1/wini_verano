//---------------------------------------------------------------------------

#pragma hdrstop

#include "LP_Polinomio.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
	LP_polinomio::LP_polinomio(){
	ls=new ptrlista;
	}
Nodolista* LP_polinomio::BuscarExponente(int e){
   Nodolista* dir=ls->siguiente(ls->primero());
				if (dir!=nullptr) {
				   Nodolista* dirter=nullptr;
	while (dir!=nullptr&&dirter==nullptr&&dir<=ls->fin()){
								if (ls->recupera(dir)==e) {
										  dirter=dir;
								}

			if (dir<=ls->fin()) {
				dir=ls->siguiente(dir);
			} else
			{
				if (dir<=ls->fin()) {
				 dir= ls->siguiente(dir);
				}else {
					return nullptr;
				}
			}

							}

						 return dirter;


				 }  return nullptr;


		}

  Nodolista* LP_polinomio::BuscarExponente1(int e){
   Nodolista* dir=ls->siguiente(ls->primero());
				if (dir!=nullptr) {
				   Nodolista* dirter=nullptr;
	while (dir!=nullptr&&dirter==nullptr){
								if (ls->recupera(dir)==e) {
										  return dirter=dir;
								}
							 if (ls->siguiente(ls->siguiente(dir))<=ls->fin()) {
									dir= ls->siguiente(ls->siguiente(dir));

							 }   else dir=nullptr;

							}

						 return dirter;


				 }  return nullptr;


		}





Nodolista* LP_polinomio::BuscarTerminoN(int e){

   Nodolista* dir=ls->primero();
 int nt=0;
   if (dir!=nullptr) {
		 Nodolista* dirter=nullptr;
		 while (dir!=nullptr&&dirter==nullptr){

		   nt+=1;
		   if (nt==e) {
				 dirter=dir;
		   }

		dir=ls->siguiente(ls->siguiente(dir));
		 }
         return dirter;
   }
}
 int LP_polinomio::Grado(){
  Nodolista* dir=ls->siguiente(ls->primero());
  if (dir!=nullptr) {     int n=0;
    	int MaxG =ls->recupera(dir);
		while (dir!=nullptr&&n<=(ls->getlongitud()/2)){
				 n++;
		 if (ls->recupera(dir)>MaxG) {
			 MaxG=ls->recupera(dir);

		 }  if (n<(ls->getlongitud()/2)&& ls->siguiente(ls->siguiente(dir))<=ls->fin()&&ls->siguiente(dir)<=ls->fin()) {
				dir=ls->siguiente(ls->siguiente(dir));
			}  else return MaxG;
		} return MaxG;
  }
 }
   int LP_polinomio::coeficiente(int exp){
  Nodolista* dir =BuscarExponente1(exp);
   Nodolista* di;
   di=ls->anterior(dir);

  int z=  di->elemento;
   if (dir!=nullptr) {
   int x= ls->recupera(dir);
   x=ls->recupera(ls->anterior(dir));
	   return ls->recupera(ls->anterior(dir));
   } else return -1;
   }
  void LP_polinomio::AsignarCoeficiente(int coef, int exp){
	Nodolista* dir = BuscarExponente(exp);
	if (dir!=nullptr) {
			Nodolista* dirCoef=ls->anterior(dir);
		ls->modifica(dirCoef,coef);
		if (coef==0) {
			ls->suprime(dir);
			ls->suprime(dirCoef);

		}
	}


	}

		void LP_polinomio::poner_termino(int coef, int exp){
	Nodolista* direxp = BuscarExponente(exp);
	if (direxp!=nullptr) {
	Nodolista* dirCoef = ls->anterior(direxp);
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
		int LP_polinomio::numero_terminos(){
		int x= ls->getlongitud();
	return ls->getlongitud()/2;
	}
	 int LP_polinomio::exponente(int i){

Nodolista* dir=BuscarTerminoN(i);

if (dir!=nullptr) {

      int x= ls->recupera(dir);
   x=ls->recupera(ls->siguiente(dir));
			 return ls->recupera(ls->siguiente(dir));
}

 }
   void  LP_polinomio::imprimir(TColor FormColor, TCanvas *Canvas){
   //	int	posX = 180;
	 //		int	posY = 500;
ls->imprimir2(FormColor,Canvas,1150,100);

}


