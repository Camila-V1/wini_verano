//---------------------------------------------------------------------------

#ifndef Matricez_ptr2H
#define Matricez_ptr2H
//---------------------------------------------------------------------------
#include <vcl.h>
#include <iostream>
using namespace std;
// Definici�n del tipo de dato NodoF
// Forward declaration of NodoC
// Forward declaration of NodoCh
struct NodoCh;

// Definici�n del tipo de dato NodoF
struct NodoFh {
    int Fila;
	NodoFh* SigF;  // Puntero al siguiente NodoF
	NodoFh* AntF;  // Puntero al anterior NodoF
	NodoCh* PtrCol;  // Puntero a NodoC
};

// Definici�n del tipo de dato NodoC
struct NodoCh {
    int Col;
    int Dato;
    NodoCh* SigCol;  // Puntero al siguiente NodoC
};

// Rest of your code...


// Definici�n de la clase Matrizptr2
class Matrizptr2 {
private:
    NodoFh* PtrFil;  // Direcci�n a tipo NodoF
    int rep;
    int dimf;
    int dimc;

public:
    Matrizptr2();  // Constructor
    void dimensionar(int df, int dc);  // Dimensionar la matriz
    int dimension_fila();  // Obtener la dimensión de la fila
    int dimension_columna();  // Obtener la dimensión de la columna
    void poner(int f, int c, int valor);  // Poner un elemento en la matriz
    int Elemento(int f, int c);  // Obtener un elemento de la matriz
	void Definir_valor_repetido(int valor);  // Definir el valor repetido
	  void imprimir(TColor FormColor, TCanvas *Canvas) ;
	  void imprimir2(TColor FormColor, TCanvas *Canvas, int offsetX, int offsetY);
      void eliminarSiIgual(int valor);
};

#endif
