#ifndef UP_listasPH
#define UP_listasPH
// Importante: Incluir System.Classes.hpp para TComponent
#include <System.Classes.hpp>
#include <vcl.h>
// #include "UPlista.h" // Asegúrate que este archivo exista o su contenido esté aquí

// Estructura del Nodo (puede ir dentro o fuera, lo dejo fuera por simplicidad)
struct Nodopi {
    int dato;
    Nodopi* sig;
};

// 1. La clase debe heredar de TComponent
// 2. Usar la macro PACKAGE
class PACKAGE TPilaP : public TComponent { 
private:
    Nodopi* ptrpi;
    int cant;

protected:
    // Los componentes necesitan este constructor sobrecargado
    void __fastcall Notification(TComponent* AComponent, TOperation Operation);

public:
    // El constructor debe recibir (TComponent* Owner)
    __fastcall TPilaP(TComponent* Owner);
    
    // Destructor (importante para limpiar memoria)
    __fastcall ~TPilaP();

    bool vacio();
    void Meter(int e);
    void Sacar(int &e);
    int cima();
    void imprimir(TColor FormColor, TCanvas *Canvas);

// Las propiedades que quieras ver en el Inspector de Objetos (opcional)
__published:
    // Aquí podrías poner propiedades si quisieras editarlas visualmente
};

// Función de registro (necesaria para que aparezca en la paleta)
void Register(); 

#endif