#ifndef UP_listasPH
#define UP_listasPH

#include <System.Classes.hpp>
#include <vcl.h>

// Estructura del Nodo
struct Nodopi {
    int dato;
    Nodopi* sig;
};

// Clase del Componente
class PACKAGE TPilaP : public TComponent {
private:
    Nodopi* ptrpi;
    int cant;

protected:
    // IMPORTANTE: __fastcall es obligatorio aquí para coincidir con el .cpp
    void __fastcall Notification(TComponent* AComponent, TOperation Operation);

public:
    // Constructor y Destructor
    __fastcall TPilaP(TComponent* Owner);
    __fastcall ~TPilaP();

    // Métodos de la Pila
    bool vacio();
    void Meter(int e);
    void Sacar(int &e);
    int cima();
    void imprimir(TColor FormColor, TCanvas *Canvas);

__published:
    // Aquí irían propiedades visibles en el inspector (si las tuvieras)
};

#endif
