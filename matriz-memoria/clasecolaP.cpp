//---------------------------------------------------------------------------

#pragma hdrstop

#include "clasecolaP.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


// ColaConPila.cpp

// Constructor: Inicializa la pila con la memoria proporcionada.
ColaConPila::ColaConPila(pilaMM* p) {
    pila = p;
}

// Método para verificar si la cola está vacía.
bool ColaConPila::Vacia() {
    return pila->Vacia();
}

// Método para agregar un elemento a la cola.
void ColaConPila::Meter(int elemento) {
    pila->Meter(elemento);
}

// Método para sacar un elemento de la cola.
void ColaConPila::Sacar(int& elemento) {
	pilaMM* temporal = new pilaMM(pila->obtenerMemoria()); // Acceso a la memoria a través del método público.

    // Transfiere todos los elementos a la pila temporal.
    while (!pila->Vacia()) {
        int aux;
        pila->Sacar(aux);
        temporal->Meter(aux);
    }

    // Obtén el primer elemento (FIFO) de la pila temporal.
    temporal->Sacar(elemento);

    // Restaura los elementos en la pila principal.
    while (!temporal->Vacia()) {
        int aux;
        temporal->Sacar(aux);
        pila->Meter(aux);
    }

    delete temporal; // Limpia la memoria de la pila temporal.
}

// Método para obtener el primer elemento de la cola sin sacarlo.
int ColaConPila::Primero() {
    pilaMM* temporal = new pilaMM(pila->obtenerMemoria()); // Acceso a la memoria.
    int primero;

    // Transfiere todos los elementos a la pila temporal.
    while (!pila->Vacia()) {
        int aux;
        pila->Sacar(aux);
        temporal->Meter(aux);
    }

    // Obtén el primer elemento (FIFO) de la pila temporal.
    temporal->Sacar(primero);

    // Restaura los elementos en la pila principal.
    temporal->Meter(primero); // Devuelve el elemento a la temporal.
    while (!temporal->Vacia()) {
        int aux;
        temporal->Sacar(aux);
        pila->Meter(aux);
    }

    delete temporal; // Limpia la memoria de la pila temporal.
    return primero;
}

// Método para imprimir el estado de la cola.
void ColaConPila::Imprimir(TColor FormColor, TCanvas* Canvas) {
    pila->imprimir(FormColor, Canvas);
}

// Destructor
ColaConPila::~ColaConPila() {
    delete pila;
}

