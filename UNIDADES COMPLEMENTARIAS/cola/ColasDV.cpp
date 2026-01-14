//---------------------------------------------------------------------------

#pragma hdrstop

#include "ColasDV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
 colaDV1::  colaDV1(){
	ini=0; fin=-1;
	// Constructor


	}

		bool colaDV1:: vacia() {
            return (ini > fin);
        }

		void colaDV1:: Meter(int e) {
            if (fin < maxx - 1) {
                fin++;
                V[fin] = e;
            }
            // Aquí puedes manejar el caso cuando la cola está llena
        }

		void colaDV1:: Sacar(int &e) {
            if (!vacia()) {
                e = V[ini];
                ini++;
            }
            // Aquí puedes manejar el caso cuando la cola está vacía
        }

		int colaDV1:: primero() {
            if (!vacia()) {
                return V[ini];
            }
            // Aquí puedes manejar el caso cuando la cola está vacía
		}

void colaDV1::imprimir(TColor FormColor, TCanvas *Canvas) {
	int posX = 700;
    int posY = 100;
    int TamanoCeldaX = 80;
    int TamanoCeldaY = 35;
    if (!vacia()) {
        // Dibujar el encabezado de la cola
        TRect rect(posX, posY, posX + TamanoCeldaX, posY + TamanoCeldaY);
        Canvas->Brush->Color = FormColor;
        Canvas->FillRect(rect);
        Canvas->TextOutW(posX, posY, "Cola");
        posY += TamanoCeldaY;
        // Iterar sobre los elementos de la cola y mostrarlos
        for (int i = ini; i <= fin; i++) {
            TRect rect(posX, posY, posX + TamanoCeldaX, posY + TamanoCeldaY);
            Canvas->Brush->Color = clWhite;  // Color de fondo de las celdas
			Canvas->FillRect(rect);
			// Convierte el número a string y lo muestra
			Canvas->TextOutW(posX, posY, IntToStr(V[i]));
			posY += TamanoCeldaY;  // Mueve la posición verticalmente para el siguiente elemento
		}
	} else {
		// Si la cola está vacía
		Canvas->TextOutW(posX, posY, "Cola vacía");
	}
}


int colaDV1::ultimoElemento() {
	if (!vacia()) {
		return V[fin]; // Devuelve el último elemento de la cola
	}
	// Manejo del caso en que la cola está vacía
	return -1; // Valor de error o bandera
}

void colaDV1::SacarUltimo(int &e) {
	if (!vacia()) {
		e = V[fin]; // Obtiene el último elemento
		fin--;      // Reduce el índice de fin para eliminar el último elemento
	}
	// Puedes manejar aquí el caso en que la cola está vacía
}

void colaDV1::MeterAlPrincipio(int e) {
	if (ini > 0) {
		ini--;       // Ajusta el índice inicial hacia atrás
		V[ini] = e;  // Inserta el elemento en la nueva posición inicial
	} else if (fin < maxx - 1) {
        // Si no hay espacio para mover ini, desplaza todos los elementos hacia adelante
		for (int i = fin; i >= ini; i--) {
			V[i + 1] = V[i];
		}
		V[ini] = e; // Inserta el nuevo elemento en el inicio
		fin++;      // Ajusta el índice de fin
	}
	// Manejo del caso en que la cola está llena (opcional)
}

