#include <System.hpp>
#pragma hdrstop
#include <vcl.h>

// ---------------------------------------------------------
// LISTA DE ASISTENCIA (Tienen que estar todos aquí)
// ---------------------------------------------------------
USEUNIT("UP_listasP.cpp");
USEUNIT("UP_pilaV.cpp");
USEUNIT("Pilaw2.cpp");
#pragma package(smart_init)

//---------------------------------------------------------------------------
//   Package source.
//---------------------------------------------------------------------------
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void*)
{
    return 1;
}
