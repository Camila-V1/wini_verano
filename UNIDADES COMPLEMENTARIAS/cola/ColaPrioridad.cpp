//---------------------------------------------------------------------------
#pragma hdrstop
#include "ColaPrioridad.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

ColaPri::ColaPri() {
    colaActual = 0;
    cant = 0;
    for (int i = 0; i < MAXP; i++) {
        prioridad[i] = 1;  // Prioridad por defecto
    }
}

bool ColaPri::vacia() {
    for (int i = 0; i < MAXP; i++) {
        if (!vc[i].vacia()) return false;
    }
    return true;
}

int ColaPri::primero() {
    for (int i = 0; i < MAXP; i++) {
        if (!vc[i].vacia()) return vc[i].colaprimero(); // Devuelve el valor
    }
    return -1;
}

void ColaPri::poner(int e, int numCola) {
    if (numCola >= 0 && numCola < MAXP) {
        vc[numCola].Meter(e);
    }
}

void ColaPri::asignarPrioridadCola(int valorPrioridad, int numCola) {
	if (numCola >= 0 && numCola < MAXP) {
		prioridad[numCola] = valorPrioridad;
	}
}
bool ColaPri::sacar(int& e) {
    int intentos = 0;
    while (intentos < MAXP) {
        // CASO 1: La cola actual TIENE datos
        if (!vc[colaActual].vacia()) {

            // Verificamos si puede sacar según su prioridad
            if (cant < prioridad[colaActual]) {
                cant++;
                vc[colaActual].Sacar(e);

                if (cant == prioridad[colaActual]) {
                    colaActual = (colaActual + 1) % MAXP;
                    cant = 0;
                }
                return true; // Éxito!
            }
            // Si ya cumplió su cuota de prioridad, pasamos a la siguiente cola
            else {
                colaActual = (colaActual + 1) % MAXP;
                cant = 0;
                // No hacemos 'return', dejamos que el while continúe
                // para probar inmediatamente la siguiente cola.
            }
        }
        // CASO 2: La cola actual está VACÍA
        else {
            colaActual = (colaActual + 1) % MAXP;
            cant = 0;
        }

        intentos++;
    }

    return false; // Dio toda la vuelta y no pudo sacar nada
}

void ColaPri::imprimir(TColor FormColor, TCanvas* Canvas) {
    int x = 600; // Posición X en pantalla
    int y = 100; // Posición Y en pantalla

    Canvas->Font->Color = clBlack;
    Canvas->Brush->Color = FormColor;

    // Solo mostrar las primeras 2 colas (jugadores)
    for (int i = 0; i < 2; i++) {
        String linea = "COLA " + IntToStr(i) + ": ";
        
        if (vc[i].vacia()) {
            linea += "[vacia]";
        } else {
            linea += "[tiene datos]";
        }

        // Mostrar prioridad y si es la activa
        linea += " | Prioridad: " + IntToStr(prioridad[i]);
        if (i == colaActual) linea += "  <-- Activa";

        Canvas->TextOutW(x, y, linea);
        y += 20; // Bajamos una línea
        
        // Dibujar el contenido de cada cola usando su propio método imprimir
        if (!vc[i].vacia()) {
            vc[i].imprimir(FormColor, Canvas);
            y += 60; // Espacio adicional después de dibujar la cola
        }
    }
}
