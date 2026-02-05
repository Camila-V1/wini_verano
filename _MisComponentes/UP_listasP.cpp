#pragma hdrstop
#include "UP_listasP.h"
#pragma package(smart_init)

// -----------------------------------------------------------
// CONSTRUCTOR
// -----------------------------------------------------------
__fastcall TPilaP::TPilaP(TComponent* Owner) : TComponent(Owner) {
    ptrpi = NULL;
    cant = 0;
}

// -----------------------------------------------------------
// DESTRUCTOR
// -----------------------------------------------------------
__fastcall TPilaP::~TPilaP() {
    int temp;
    while (!vacio()) {
        Sacar(temp);
    }
}

// -----------------------------------------------------------
// MÉTODOS DE LA PILA
// -----------------------------------------------------------
bool TPilaP::vacio() {
    return cant == 0;
}

void TPilaP::Meter(int e) {
    Nodopi* dir = new Nodopi;
    if (dir != NULL) {
        dir->dato = e;
        dir->sig = ptrpi;
        ptrpi = dir;
        cant++;
    }
}

void TPilaP::Sacar(int &e) {
    if (!vacio()) {
        Nodopi* temp = ptrpi;
        e = temp->dato;
        ptrpi = temp->sig;
        delete temp;
        cant--;
    }
}

int TPilaP::cima() {
    if (!vacio()) return ptrpi->dato;
    return -1;
}

// -----------------------------------------------------------
// DIBUJO (Con Cajas y Flechas)
// -----------------------------------------------------------
void Pintado(int posX, int posY, String cad, TColor color, TCanvas *Canvas){
    int TamanoCeldaX = 80;
    int TamanoCeldaY = 35;
    TRect rect(posX, posY, posX + TamanoCeldaX, posY + TamanoCeldaY);

    Canvas->Brush->Color = color;
    Canvas->FillRect(rect);
    Canvas->TextOut(posX + 10, posY + 8, cad);
}

void TPilaP::imprimir(TColor FormColor, TCanvas *Canvas) {
    int posX = 100;
    int posY = 100;
    int auxX = posX;

    if (!vacio()) {
        Pintado(posX, posY, "Pila", FormColor, Canvas);
        posX = auxX;
        posY += 35; // Bajamos una línea

        Nodopi* x = ptrpi;
        Pintado(posX, posY, "Tope", clSilver, Canvas);
        posX += 80;

        while (x != NULL) {
            Pintado(posX, posY, IntToStr(x->dato), FormColor, Canvas);
            posX += 80;
            x = x->sig;
            if (x != NULL) {
                Canvas->TextOut(posX, posY + 10, "->");
                posX += 30;
            }
        }
        Canvas->TextOut(posX, posY + 10, "-> NULL");
    } else {
        Pintado(posX, posY, "Pila Vacia", FormColor, Canvas);
    }
}

// -----------------------------------------------------------
// NOTIFICACIÓN (Soluciona el error Unresolved External)
// -----------------------------------------------------------
void __fastcall TPilaP::Notification(TComponent* AComponent, TOperation Operation)
{
    TComponent::Notification(AComponent, Operation);
}

namespace Up_listasp {
    void __fastcall PACKAGE Register() {
        TComponentClass classes[1] = {__classid(TPilaP)};
        RegisterComponents(L"Wini", classes, 0);
    }
}
