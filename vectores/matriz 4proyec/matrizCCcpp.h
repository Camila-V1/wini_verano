//---------------------------------------------------------------------------

#ifndef matrizCCcppH
#define matrizCCcppH
 #define MAX 100
//---------------------------------------------------------------------------
#include <vcl.h>
#include <iostream>
using namespace std;
class MatrizCC {
private:
    int VF[MAX]; // filas
    int VC[MAX]; // columnas
    int VD[MAX]; // elementos
    int df; // dimensi�n fila
    int dc; // dimensi�n columna
    int repe; // elemento repetido
    int nt; // n�mero de t�rminos

    int Existe_Elemento(int f, int c); // busca en vd,vc y vf si existe el elemento
    int Donde_insertar(int f, int c); // determina donde insertar en vd,vc y vf

public:
    MatrizCC(); // constructor
    void dimensionar(int df, int dc); // dimensionar la matriz
    int dimension_fila(); // obtener la dimensi�n de la fila
	int dimension_columna(); // obtener la dimensi�n de la columna
	void eliminarSiIgual(int valor) ;
    void poner(int f, int c, int valor); // poner un elemento en la matriz
    int Elemento(int f, int c); // obtener un elemento de la matriz
	void Definir_valor_repetido(int valor); // definir el valor repetido
		void imprimir(TColor FormColor, TCanvas *Canvas) ;
		void imprimir2(TColor FormColor, TCanvas *Canvas, int offsetX, int offsetY);
        void DibujarVectores(TCanvas *Canvas, int x, int y);
};

#endif
