#pragma hdrstop
#include "UP_pilaV.h"
#pragma package(smart_init)

// -----------------------------------------------------------
// CONSTRUCTOR
// -----------------------------------------------------------
__fastcall TPilaV::TPilaV(TComponent* Owner) : TComponent(Owner) {
    tope = -1; // -1 indica que está vacía (índice 0 es el primero)
}

// -----------------------------------------------------------
// MÉTODOS
// -----------------------------------------------------------
bool TPilaV::vacio() {
    return tope == -1;
}

bool TPilaV::llena() {
    return tope == MAXS - 1;
}

void TPilaV::Meter(int e) {
    if (!llena()) {
        tope++;
        elementos[tope] = e;
    }
}

void TPilaV::Sacar(int &e) {
    if (!vacio()) {
        e = elementos[tope];
        tope--;
    }
}

int TPilaV::cima() {
    if (!vacio()) return elementos[tope];
    return -1;
}

// -----------------------------------------------------------
// DIBUJO (Cajas estilo Vector)
// -----------------------------------------------------------
void PintarCaja(int x, int y, String texto, TColor color, TCanvas *c) {
    c->Brush->Color = color;
    c->Rectangle(x, y, x + 50, y + 30);
    c->TextOut(x + 15, y + 8, texto);
}

void TPilaV::imprimir(TColor FormColor, TCanvas *Canvas) {
    int x = 50;
    int y = 50;

    // Limpiamos un área
    Canvas->Brush->Color = FormColor;
    Canvas->FillRect(TRect(x, y, x + (MAXS * 55), y + 100));

    Canvas->TextOut(x, y - 20, "Pila (Vector) - Tope: " + IntToStr(tope));

    if (vacio()) {
        Canvas->TextOut(x, y, "Pila Vacia");
        return;
    }

    // Dibujamos el vector horizontalmente
    for (int i = 0; i <= tope; i++) {
        PintarCaja(x, y, IntToStr(elementos[i]), clSkyBlue, Canvas);

        // Dibujamos el índice abajo
        Canvas->Brush->Color = FormColor; // Fondo transparente visualmente
        Canvas->TextOut(x + 20, y + 32, "[" + IntToStr(i) + "]");

        x += 50; // Mover a la derecha
    }
}

// -----------------------------------------------------------
// REGISTRO
// -----------------------------------------------------------
void __fastcall TPilaV::Notification(TComponent* AComponent, TOperation Operation) {
    TComponent::Notification(AComponent, Operation);
}

// Namespace único para evitar errores de linkeo
namespace Up_pilav {
    void __fastcall PACKAGE Register() {
        TComponentClass classes[1] = {__classid(TPilaV)};
        RegisterComponents(L"Wini", classes, 0);
    }
}
