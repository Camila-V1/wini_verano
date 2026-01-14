#pragma hdrstop
#include "colaCircular.h"
#pragma package(smart_init)

colaCircular::colaCircular() {
    ini = 0;
    fin = 0;
}

bool colaCircular::vacia() {
    return ini == fin;
}

bool colaCircular::llena() {
    return (fin + 1) % MAX == ini;
}

void colaCircular::Meter(int e) {
    if (!llena()) {
        V[fin] = e;
        fin = (fin + 1) % MAX;
    } else {
        ShowMessage("Cola circular llena");
    }
}

void colaCircular::Sacar(int &e) {
    if (!vacia()) {
        e = V[ini];
        ini = (ini + 1) % MAX;
    } else {
        ShowMessage("Cola circular vacía");
    }
}

int colaCircular::primero() {
    if (!vacia()) {
        return V[ini];
    }
    return -1; // señal de error
}

int colaCircular::ultimo() {
    if (!vacia()) {
        return V[(fin - 1 + MAX) % MAX];
    }
    return -1;
}

void colaCircular::imprimir(TColor FormColor, TCanvas *Canvas) {
    int posX = 100;
    int posY = 100;
    int TamanoCeldaX = 60;
    int TamanoCeldaY = 30;
    int i = ini;

    Canvas->TextOutW(posX, posY - 20, "Cola Circular:");

    while (i != fin) {
        TRect rect(posX, posY, posX + TamanoCeldaX, posY + TamanoCeldaY);
        Canvas->Brush->Color = clWhite;
        Canvas->Rectangle(rect);
        Canvas->TextOutW(posX + 5, posY + 5, IntToStr(V[i]));

        posX += TamanoCeldaX + 10;
        i = (i + 1) % MAX;
    }

    // Indicadores
    Canvas->TextOutW(100, posY + 40, "ini = " + IntToStr(ini));
    Canvas->TextOutW(200, posY + 40, "fin = " + IntToStr(fin));
}

