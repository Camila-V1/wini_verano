 //---------------------------------------------------------------------------

#pragma hdrstop

#include "UC_memoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
colaM::colaM(CSmemoria* m) {
 ini=-1;
 longitud=0;
 fin=-1;
 Cm= m;
}
bool colaM::vacia(){
if (ini==-1) {
   return true;
}              else return false;

}
void colaM::Meter(int e){
    int aux=Cm->new_espacio("elemento,sig");
if (aux!=-1) {
	 Cm->poner_dato(aux,"->elemento" ,e);
		 Cm->poner_dato(aux, "->sig" ,-1) ;
	 if (vacia()==true) {
		 ini=aux;
		 fin=aux;

	 } else {
		 Cm->poner_dato(fin,"->sig",aux);
         fin=aux;
	 }
}
}
void colaM::Sacar(int &e){
  if (vacia()==false) {
				 e=Cm->obtenerDato(ini,"->elemento");
				 int x=ini;
				 ini=Cm->obtenerDato(ini,"->sig");
                 Cm->Delete_espacio(x);
  }
}

	  int colaM::colaprimero(){
if (vacia()==false) {
             return Cm->obtenerDato(ini,"->elemento") ;
}
	  }

      int colaM::ultimoElemento() {
	if (!vacia()) {
        return Cm->obtenerDato(fin, "->elemento");
    }
    else {
        // Aquí puedes manejar el caso cuando la cola está vacía
        // Por ejemplo, puedes lanzar una excepción o devolver un valor especial
    }
}
void colaM::MeterAlPrincipio(int e) {
    int aux = Cm->new_espacio("elemento,sig");
    if (aux != -1) {
        Cm->poner_dato(aux, "->elemento", e);
        Cm->poner_dato(aux, "->sig", ini);
        ini = aux;
        if (fin == -1) {
            fin = aux;
        }
    }
}
void colaM::SacarUltimo(int &e) {
    if (!vacia()) {
        e = Cm->obtenerDato(fin, "->elemento");
        if (ini == fin) {
            // Si solo hay un elemento en la cola
            Cm->Delete_espacio(fin);
            ini = fin = -1;
        } else {
            // Si hay más de un elemento en la cola
            int x = ini;
            while (Cm->obtenerDato(x, "->sig") != fin) {
                x = Cm->obtenerDato(x, "->sig");
            }
            Cm->Delete_espacio(fin);
            fin = x;
            Cm->poner_dato(fin, "->sig", -1);
        }
    }
    else {
        // Aquí puedes manejar el caso cuando la cola está vacía
        // Por ejemplo, puedes lanzar una excepción o devolver un valor especial
    }
}

 void colaM::imprimir(TColor FormColor, TCanvas *Canvas){
 }
