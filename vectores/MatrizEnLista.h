#ifndef MatrizEnListaH
#define MatrizEnListaH

#include <vcl.h>
#include "../UNIDADES COMPLEMENTARIAS/listas/UPlista.h"

class LBCS {
private:
    // ÚNICO ATRIBUTO: Lista donde formato es <f1,c1,v1, f2,c2,v2, ..., filas, columnas>
    ptrlista* L;
    
    // Valor repetido (por defecto, no se guarda en la lista)
    int repe;
    
    // Métodos auxiliares
    Nodolista* BuscarNodoDimensionFilas();  // Encuentra el penúltimo nodo (filas)
    Nodolista* BuscarElemento(int f, int c);  // Busca tripleta (f,c,v)
    
public:
    LBCS();
    ~LBCS();
    
    void dimensionar(int f, int c);
    void poner(int f, int c, int valor);
    int elemento(int f, int c);
    void definir_valor_repetido(int valor);
    
    // Métodos de visualización
    void imprimir(TColor FormColor, TCanvas* Canvas);
    void imprimir2(TColor FormColor, TCanvas* Canvas, int posX, int posY);
    void imprimirLista(TColor FormColor, TCanvas* Canvas, int posX, int posY);
    
    // Alias para compatibilidad
    void Dimensionar(int f, int c) { dimensionar(f, c); }
    void Poner(int f, int c, int valor) { poner(f, c, valor); }
    int Elemento(int f, int c) { return elemento(f, c); }
    void Definir_valor_repetido(int valor) { definir_valor_repetido(valor); }
};

#endif
