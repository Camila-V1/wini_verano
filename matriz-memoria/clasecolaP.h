//---------------------------------------------------------------------------

#ifndef clasecolaPH
#define clasecolaPH

    #include "pila2.h"
//---------------------------------------------------------------------------
class ColaConPila {
private:
	pilaMM* pila; // Pila utilizada para simular la cola.
public:
	// Constructor
	ColaConPila(pilaMM* p);
	// Método para verificar si la cola está vacía.
	bool Vacia();
	// Método para agregar un elemento a la cola.
	void Meter(int elemento);
	// Método para sacar un elemento de la cola.
	void Sacar(int& elemento);
	// Método para obtener el primer elemento de la cola sin sacarlo.
	int Primero();
	// Método para imprimir el estado de la cola.
	void Imprimir(TColor FormColor, TCanvas* Canvas);
	// Destructor
	~ColaConPila();
};
// ColaConPila.cpp

#endif
