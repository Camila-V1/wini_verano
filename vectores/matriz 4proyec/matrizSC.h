//---------------------------------------------------------------------------

#ifndef matrizSCH
#define matrizSCH
 #define MAX 100
//---------------------------------------------------------------------------
#include <vcl.h>
#include <iostream>
using namespace std;
class MatrizSC {
public:

    // Atributos
    int Vf[MAX]; // filas
    int VC[MAX]; // Columnas
    int VD[MAX]; // elementos
    int df, dc; // Dimensi�n
    int repe; // es el elemento que se repetir� en la matriz
    int nt;
    MatrizSC();
    // M�todos
    void Crear();
    void dimensionar(int df, int dc);
    int dimension_fila();
    int dimension_columna();
    void poner(int f, int c, int valor);
	int Elemento(int f, int c);
    void eliminarSiIgual(int valor) ;
	void Definir_valor_repetido(int valor);
	void imprimir(TColor FormColor, TCanvas *Canvas) ;
	void imprimir2(TColor FormColor, TCanvas *Canvas, int offsetX, int offsetY);
    void desplazar() ;
};
#endif
