#ifndef UP_pilaVH
#define UP_pilaVH

#include <System.Classes.hpp>
#include <vcl.h>

// Definimos el tamaño máximo del vector
const int MAXS = 100;

class PACKAGE TPilaV : public TComponent {
private:
    int elementos[MAXS]; // El vector
    int tope;           // Índice del último elemento

protected:
    void __fastcall Notification(TComponent* AComponent, TOperation Operation);

public:
    // Constructor y Destructor
    __fastcall TPilaV(TComponent* Owner);

    // Métodos
    bool vacio();
    bool llena();
    void Meter(int e);
    void Sacar(int &e);
    int cima();

    // Dibujo
    void imprimir(TColor FormColor, TCanvas *Canvas);

__published:
};

#endif
