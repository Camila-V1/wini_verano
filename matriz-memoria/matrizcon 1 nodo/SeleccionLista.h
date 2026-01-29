#ifndef SeleccionListaH
#define SeleccionListaH

#include "..\..\UNIDADES COMPLEMENTARIAS\Memoria\Umemoria.h"

// =========================================================
//   ELIGE EL TIPO DE LISTA AQUÍ
// =========================================================
// 1 = Lista Punteros (ptrlista)
// 2 = Lista Vector (Vlista)
// 3 = Lista Memoria (Lista - CSM)

#define TIPO_LISTA 1  // <--- CAMBIA ESTO PARA PROBAR OTRAS

// =========================================================
//   INCLUDES Y TYPEDEF
// =========================================================
#if TIPO_LISTA == 1
    #include "..\..\UNIDADES COMPLEMENTARIAS\listas\UPlista.h"
    typedef ptrlista TLista;
    typedef Nodolista* TDireccion;

#elif TIPO_LISTA == 2
    #include "..\..\UNIDADES COMPLEMENTARIAS\listas\UVLista.h"
    typedef Vlista TLista;
    typedef int TDireccion;

#elif TIPO_LISTA == 3
    #include "..\..\UNIDADES COMPLEMENTARIAS\listas\UCSLista.h"
    typedef Lista TLista;
    typedef direccion TDireccion;
#endif

#endif
