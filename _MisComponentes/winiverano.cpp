#include <System.hpp>
#pragma hdrstop
#include <vcl.h> // Asegurate que tenga esta

// ESTA LINEA ES LA CLAVE. SI NO ESTÁ, EL COMPONENTE NO EXISTE.
USEUNIT("UP_listasP.cpp");

#pragma package(smart_init)

//---------------------------------------------------------------------------
//   Package source.
//---------------------------------------------------------------------------
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void*)
{
    return 1;
}
