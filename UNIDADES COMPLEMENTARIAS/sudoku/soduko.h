//---------------------------------------------------------------------------

#ifndef sodukoH
#define sodukoH
#include "matriz_2N.h"
//---------------------------------------------------------------------------

//defino a direccionL como un struct

class Sudoku{
    private:
    MatrizDispersa2* matriz; // Puntero a la matriz dispersa
    static const int N = 9; // Tamaño fijo del Sudoku (9x9)
    bool verificarFila(int fila);
    bool verificarColumna(int columna);
    bool verificarSubCuadrante(int filaInicio, int colInicio);
public:
    Sudoku(MatrizDispersa2* matrizDispersa);
      bool EsSudoku();
    bool estaLleno();
    bool esValido();
};


#endif
