//---------------------------------------------------------------------------

#pragma hdrstop

#include "soduko.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


Sudoku::Sudoku(MatrizDispersa2* matrizDispersa) {
    this->matriz = matrizDispersa;
}

bool Sudoku::estaLleno() {
    // Recorre todas las filas y columnas verificando si todas las celdas están llenas
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (matriz->Elemento(i, j) == 0) {
                return false; // Si alguna celda está vacía (valor 0), el Sudoku no está lleno
            }
        }
    }
    return true;
}

bool Sudoku::verificarFila(int fila) {
    bool numeros[N+1] = {false}; // Un arreglo para verificar si cada número aparece una vez
	for (int col = 1; col <= N; col++) {
		int valor = matriz->Elemento(fila, col);
		if (valor < 1 || valor > N || numeros[valor]) {
			return false; // Número inválido o repetido
        }
		numeros[valor] = true;
    }
	return true;
}

bool Sudoku::verificarColumna(int columna) {
    bool numeros[N+1] = {false}; // Un arreglo para verificar si cada número aparece una vez
    for (int fila = 1; fila <= N; fila++) {
        int valor = matriz->Elemento(fila, columna);
        if (valor < 1 || valor > N || numeros[valor]) {
            return false; // Número inválido o repetido
        }
        numeros[valor] = true;
    }
    return true;
}

bool Sudoku::verificarSubCuadrante(int filaInicio, int colInicio) {
    bool numeros[N+1] = {false};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int valor = matriz->Elemento(filaInicio + i, colInicio + j);
            if (valor < 1 || valor > N || numeros[valor]) {
                return false; // Número inválido o repetido
            }
            numeros[valor] = true;
        }
    }
    return true;
}

bool Sudoku::esValido() {
			 //ShowMessage(N);
    // Verificar filas y columnas
    for (int i = 1; i <= N; i++) {
        if (!verificarFila(i) || !verificarColumna(i)) {
            return false;
        }
    }

    // Verificar subcuadrantes 3x3
    for (int i = 1; i <= N; i += 3) {
        for (int j = 1; j <= N; j += 3) {
            if (!verificarSubCuadrante(i, j)) {
                return false;
            }
        }
    }

    return true;
}


bool Sudoku::EsSudoku(){
return esValido()  and estaLleno();
}
