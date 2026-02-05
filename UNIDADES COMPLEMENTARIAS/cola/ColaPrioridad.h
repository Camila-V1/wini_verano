//---------------------------------------------------------------------------
#ifndef ColaPrioridadH
#define ColaPrioridadH
#include <vcl.h>
#include "UC_memoria.h"  // Usamos cola con memoria
//---------------------------------------------------------------------------
// Usamos colaM en lugar de un tipo fijo
typedef colaM TCola;

const int MAXP = 10;

class ColaPri {
private:
    TCola vc[MAXP];       // Arreglo de colas
    int prioridad[MAXP];  // Prioridad de cada cola (mayor valor = mayor prioridad)
    int colaActual;       // Índice de la cola actualmente activa
    int cant;             // Cantidad de elementos servidos de la cola actual

public:
    ColaPri();
    bool vacia();      // Verifica si toda la estructura está vacía
    int primero();     // Devuelve el valor del primero de la cola con mayor prioridad
    void poner(int elemento, int numCola);
    void asignarPrioridadCola(int prioridad, int numCola);
    bool sacar(int &elemento);
    void imprimir(TColor FormColor, TCanvas* Canvas);
};

#endif
