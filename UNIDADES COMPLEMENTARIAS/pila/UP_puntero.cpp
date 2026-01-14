//---------------------------------------------------------------------------

#pragma hdrstop

#include "UP_puntero.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
ptr_pila::ptr_pila(){
cant=0;
ptrp=nullptr;
} bool ptr_pila::vacio(){
  return (cant==0);
}

int  ptr_pila::recupera(Nodopil* d)
{if (!vacio()){
return d->dato;
}else{ return -1 ;}}



	Nodopil* ptr_pila::primero(){
	if (!vacio()) {
	return ptrp;
}else{ return nullptr ;}
	}

	Nodopil* ptr_pila::fin(){
if (vacio()) {
   return nullptr ;//cout<<"ERROR/FIN():LISTA VACIA";
}else{
Nodopil* x= ptrp;
Nodopil* ptrfin;
	while (x != nullptr){
	ptrfin=x;
    x=x->sig;
	}
	return ptrfin;
}
}

 void ptr_pila::Sacar(int &e){
 if (vacio()) return;  // Protección adicional
 
 Nodopil* p = ptrp;     // Guardar el nodo a eliminar
 e = p->dato;           // Recuperar el dato
 ptrp = p->sig;         // Actualizar ptrp al siguiente nodo
 delete p;              // Eliminar el nodo
 cant--;                // Decrementar contador
 }
  void ptr_pila::Meter(int e){
  Nodopil* x=new Nodopil;
if (x!=nullptr) {
	x->dato=e;
	x->sig=ptrp;
	cant++;
	ptrp=x;
}
  }
  int ptr_pila::cima(){
  return recupera(primero());
  }
