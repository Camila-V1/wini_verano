//---------------------------------------------------------------------------

#pragma hdrstop

#include "DiColaVector.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

DiColaVector::DiColaVector() {
    ini = 0;
    fin = MAXD - 1;
}
  int siguiente(int dir) {
	return (dir + 1) % MAXD;
}
bool DiColaVector::vacia() const {
	return (siguiente(fin) == ini);
}

bool DiColaVector::llena() const {
    return (siguiente(siguiente(fin)) == ini);
}



bool DiColaVector::ponerFinal(int valor) {
    if (llena()) return false;
    fin = siguiente(fin);
    datos[fin] = valor;
    return true;
}

bool DiColaVector::ponerInicio(int valor) {
    if (llena()) return false;
    ini = (ini - 1 + MAXD) % MAXD;  // retrocede circularmente
	datos[ini] = valor;             // coloca el dato al frente
    return true;
}


bool DiColaVector::sacarInicio(int& valor) {
    if (vacia()) return false;
    valor = datos[ini];
    ini = siguiente(ini);
    return true;
}

bool DiColaVector::sacarFinal(int& valor) {
    if (vacia()) return false;
    valor = datos[fin];
	fin = (fin - 1 + MAXD) % MAXD;
    return true;
}

int DiColaVector::primero() const {
    if (!vacia()) return datos[ini];
    return -1; // o lanzar excepcion
}

int DiColaVector::ultimo() const {
    if (!vacia()) return datos[fin];
    return -1;
}
		/*
void DiColaVector::imprimir(TColor color, TCanvas* canvas) {
	int x = 600;
	int y = 500;
	int ancho = 50;

	canvas->Brush->Color = color;
	canvas->Font->Color = clBlack;

	int idx = ini;
	while (idx != siguiente(fin)) {
		TRect rect(x, y, x + ancho, y + 30);
		canvas->Rectangle(rect);
		canvas->TextOutW(x + 10, y + 5, IntToStr(datos[idx]));
		idx = siguiente(idx);
		x += ancho;
	}

	if (!vacia()) {
		canvas->TextOutW(550, y + 35, "<-- Frente");
		canvas->TextOutW(x, y + 35, "Final -->");
	} else {
		canvas->TextOutW(x, y, "Dicola vacía");
	}
}    */
void DiColaVector::imprimir(TColor FormColor, TCanvas* Canvas) {
    const int cx = 600;
    const int cy = 300;
    const int radio = 100;

    Canvas->Font->Size = 10;
    Canvas->Brush->Color = FormColor;
    Canvas->Pen->Color = clBlack;

    if (vacia()) {
        Canvas->TextOutW(cx - 50, cy, "Dicola vacía");
        return;
    }

    // Contar cantidad de elementos reales
    int cantidad = 0;
    int idx = ini;
    while (idx != siguiente(fin)) {
        cantidad++;
        idx = siguiente(idx);
    }

    double paso = (cantidad > 1) ? 2 * M_PI / cantidad : 0;  // Si hay uno solo, paso = 0
    idx = ini;

    for (int i = 0; i < cantidad; i++) {
        double theta = i * paso;

        int x = cx + cos(theta) * radio;
        int y = cy + sin(theta) * radio;

        // Mostrar índice
        Canvas->Font->Color = clRed;
        Canvas->TextOutW(x, y, IntToStr(idx));

        // Mostrar dato
        int ex = cx + cos(theta) * (radio - 25);
        int ey = cy + sin(theta) * (radio - 25);
        Canvas->Font->Color = clPurple;
        Canvas->TextOutW(ex - 10, ey - 10, "E" + IntToStr(datos[idx]));

        // Dibujar flecha al siguiente (solo si hay más de uno)
        if (cantidad > 1) {
            int nextIdx = siguiente(idx);
            double nextTheta = (i + 1) * paso;
            int x2 = cx + cos(nextTheta) * (radio - 5);
            int y2 = cy + sin(nextTheta) * (radio - 5);
            Canvas->Pen->Color = clGray;
            Canvas->MoveTo(x, y);
            Canvas->LineTo(x2, y2);
        }

        idx = siguiente(idx);
    }

    // Etiquetas de frente y final
    double thetaIni = 0;
    double thetaFin = (cantidad - 1) * paso;

    int xf = cx + cos(thetaIni) * (radio + 20);
    int yf = cy + sin(thetaIni) * (radio + 20);
    Canvas->Font->Color = clBlack;
    Canvas->TextOutW(xf, yf, "Frente");

    int xt = cx + cos(thetaFin) * (radio + 20);
    int yt = cy + sin(thetaFin) * (radio + 20);
    Canvas->TextOutW(xt, yt, "Final");
}


String DiColaVector::comoTexto() {
    String resultado = "[";
    int idx = ini;
    while (idx != siguiente(fin)) {
        resultado += IntToStr(datos[idx]);
        if (siguiente(idx) != siguiente(fin)) resultado += ", ";
        idx = siguiente(idx);
    }
    resultado += "]";
    return resultado;
}
