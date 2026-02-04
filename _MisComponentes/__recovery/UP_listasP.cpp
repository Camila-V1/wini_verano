#pragma hdrstop
#include "UP_listasP.h"
#pragma package(smart_init)

// -----------------------------------------------------------
// CONSTRUCTOR: Adaptado para componentes VCL
// -----------------------------------------------------------
__fastcall TPilaP::TPilaP(TComponent* Owner) : TComponent(Owner) {
    ptrpi = NULL;
    cant = 0;
}

// DESTRUCTOR: Limpieza de memoria automática al cerrar el form
__fastcall TPilaP::~TPilaP() {
    int temp;
    while (!vacio()) {
        Sacar(temp);
    }
}

// -----------------------------------------------------------
// TUS MÉTODOS (Lógica intacta)
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
// TU MÉTODO DE PINTADO (Simplificado para el ejemplo)
// -----------------------------------------------------------
void Pintado(int posX, int posY, String cad, TColor color, TCanvas *Canvas){
    int TamanoCeldaX = 80;
    int TamanoCeldaY = 35;

    TRect rect(posX, posY, posX + TamanoCeldaX, posY + TamanoCeldaY);
    Canvas->Brush->Color = color;
    Canvas->FillRect(rect);

    // CAMBIO AQUÍ: Usa TextOut en lugar de TextOutW
    Canvas->TextOut(posX, posY + 3, cad);
}

void TPilaP::imprimir(TColor FormColor, TCanvas *Canvas) {
    // ... (Pega aquí tu lógica de imprimir exacta) ...
    // Solo asegúrate de llamar a Pintado correctamente.
    // Ejemplo rápido basado en tu código:
    int posX = 100; int posY = 100;
    if (!vacio()) {
        Pintado(posX, posY, "Cima: " + IntToStr(ptrpi->dato), FormColor, Canvas);
    } else {
        Pintado(posX, posY, "Pila Vacia", FormColor, Canvas);
    }
}

// -----------------------------------------------------------
// REGISTRO DEL COMPONENTE
// -----------------------------------------------------------
// Esto le dice a C++Builder dónde poner el componente
namespace Uplistasp {
    void __fastcall PACKAGE Register() {
        TComponentClass classes[1] = {__classid(TPilaP)};
        // "WiniEstructuras" será el nombre de la pestaña en la paleta
        RegisterComponents(L"WiniEstructuras", classes, 0);
    }
}
// -----------------------------------------------------------
// Notificación de componentes (necesario porque lo declaramos en el .h)
// -----------------------------------------------------------
void __fastcall TPilaP::Notification(TComponent* AComponent, TOperation Operation)
{
    // Llamamos al método de la clase padre para que haga lo que tenga que hacer
    TComponent::Notification(AComponent, Operation);
}