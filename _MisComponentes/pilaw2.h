#ifndef pilaw2H
#define pilaw2H
#include <System.Classes.hpp>
#include <vcl.h>

const int MAXS = 6;

class PACKAGE Tmario_lopez : public TComponent {
private:
    int elementos[MAXS];
    int tope;

protected:
    void __fastcall Notification(TComponent* AComponent, TOperation Operation);

public:
    __fastcall Tmario_lopez(TComponent* Owner);

    bool vacio();
    bool llena();
    void Meter(int e);
    void Sacar(int &e);
    int cima();

    void imprimir(TColor FormColor, TCanvas *Canvas);

__published:
};
#endif
