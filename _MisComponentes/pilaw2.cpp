#pragma hdrstop
#include "pilaw2.h"
#pragma package(smart_init)

__fastcall Tmario_lopez::Tmario_lopez(TComponent* Owner) : TComponent(Owner) {
    tope = -1;
}

bool Tmario_lopez::vacio() { return tope == -1; }
bool Tmario_lopez::llena() { return tope == MAXS - 1; }

void Tmario_lopez::Meter(int e) {
    if (e < 10) {
        if (!llena()) {
            tope++;
            elementos[tope] = e;
        }
    }
}

void Tmario_lopez::Sacar(int &e) {
    if (!vacio()) {
        e = elementos[tope];
        tope--;
    }
}

int Tmario_lopez::cima() {
    if (!vacio()) return elementos[tope];
    return -1;
}

void PintarCaja2(int x, int y, String texto, TColor color, TCanvas *c) {
    c->Brush->Color = color;
    c->Rectangle(x, y, x + 50, y + 30);
    c->TextOut(x + 15, y + 8, texto);
}

void Tmario_lopez::imprimir(TColor FormColor, TCanvas *Canvas) {
    int x = 50; int y = 50;
    Canvas->Brush->Color = FormColor;
    Canvas->FillRect(TRect(x, y, x + (MAXS * 55), y + 100));
    Canvas->TextOut(x, y - 20, "Pila Mario (Vector) - Tope: " + IntToStr(tope));

    if (vacio()) {
        Canvas->TextOut(x, y, "Pila Vacia");
        return;
    }
    for (int i = 0; i <= tope; i++) {
        PintarCaja2(x, y, IntToStr(elementos[i]), clSkyBlue, Canvas);
        Canvas->Brush->Color = FormColor;
        Canvas->TextOut(x + 20, y + 32, "[" + IntToStr(i) + "]");
        x += 50;
    }
}

void __fastcall Tmario_lopez::Notification(TComponent* AComponent, TOperation Operation) {
    TComponent::Notification(AComponent, Operation);
}


namespace Pilaw2 {
    void __fastcall PACKAGE Register() {
        TComponentClass classes[1] = {__classid(Tmario_lopez)};
        RegisterComponents(L"Wini", classes, 0);
    }
}
