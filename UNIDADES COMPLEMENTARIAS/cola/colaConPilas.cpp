#pragma hdrstop
#include "ColaConPilas.h"
#pragma package(smart_init)

colaConPilas::colaConPilas() {
	cBJR = new pilav();
}

bool colaConPilas::vacia() {
	return cBJR->Vacia();
}

void colaConPilas::meter(int valor) {
    cBJR->Meter(valor);
}

bool colaConPilas::sacar(int& valor) {
    if (cBJR->Vacia()) return false;

    pilav aux;
    int temp;

    // Paso 1: pasar todo a auxiliar
    while (!cBJR->Vacia()) {
        cBJR->Sacar(temp);
        aux.Meter(temp);
    }

    // Paso 2: sacar el primer ingresado (último en aux)
    aux.Sacar(temp);
    valor = temp;

    // Paso 3: devolver lo restante a cBJR
    while (!aux.Vacia()) {
        aux.Sacar(temp);
        cBJR->Meter(temp);
    }

    return true;
}

String colaConPilas::imprimirComoCola() {
    String resultado = "[";
    for (int i = 1; i <= cBJR->tope; i++) {
        resultado += IntToStr(cBJR->elementos[i]);
        if (i < cBJR->tope) resultado += ", ";
	}
    resultado += "]";
	return resultado;
}

void colaConPilas::imprimir(TColor color, TCanvas* canvas) {
    const int xInicio = 600;
    const int y = 600;

    String representacion = imprimirComoCola();

    canvas->Font->Color = clBlack;
    canvas->Brush->Color = color;
    canvas->TextOutW(xInicio, y, "Cola: " + representacion);

	if (!cBJR->Vacia()) {
        canvas->TextOutW(xInicio - 80, y + 20, "Final ->");
        canvas->TextOutW(xInicio + representacion.Length() * 7 + 40, y + 20, "<- Frente");
    } else {
		canvas->TextOutW(xInicio, y + 20, "Cola vacía");
    }
}

