// =======================================================================
// ===== REEMPLAZA TODO EL CONTENIDO DE UL_polinomiocpp.cpp CON ESTO =====
// =======================================================================

#pragma hdrstop
#include "Umemoria.h"
#include "UL_polinomiocpp.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

// Constructor for the model that stores the grade at the end.
// Creates the list <0, 0> to represent the polynomial P(x) = 0.
polinomioL::polinomioL(CSmemoria* M) {
    ls = new Lista(M);
    ls->inserta_primero(0); // Coefficient for x^0
    ls->inserta_ultimo(0);  // Grade of the polynomial is 0
}

// The Grade is the value of the last element in the list.
int polinomioL::Grado() {
    if (ls->vacia() || ls->getlongitud() < 2) {
        return 0;
    }
    return ls->recupera(ls->fin());
}

// The method for setting terms, corrected and unified.
// I've named it poner_termino2 as you requested in the prompt.
void polinomioL::poner_termino2(int coef, int exp) {
    // If the coefficient is zero and the exponent is greater than the current grade,
    // we do nothing to avoid expanding the polynomial unnecessarily.
    if (coef == 0 && exp > Grado()) {
        return;
    }

    int grado_actual = Grado();

    if (exp > grado_actual) {
        // --- The new term expands the polynomial ---
        ls->suprime(ls->fin()); // 1. Remove the old grade from the end

        // 2. Fill with zeros up to the position BEFORE the new coefficient.
        while (ls->getlongitud() < exp) {
            ls->inserta_ultimo(0);
        }

        // 3. Insert the new coefficient.
        ls->inserta_ultimo(coef);

        // 4. Add the new grade at the end.
        ls->inserta_ultimo(exp);

    } else {
        // --- The term does NOT expand the polynomial ---
        // 1. Find the node at the position of the exponent.
        direccion d = ls->primero();
        for (int i = 0; i < exp; i++) {
            d = ls->siguiente(d);
        }

        // 2. Modify the coefficient by adding the new value.
        int coef_actual = ls->recupera(d);
        ls->modifica(d, coef_actual + coef);

        // Optional but important: Logic to reduce the grade if the highest-exponent term becomes zero.
        if (exp == grado_actual && (coef_actual + coef) == 0) {
            // Find the first non-zero term backwards to define the new grade.
            int nuevo_grado = grado_actual - 1;
            while (nuevo_grado > 0 && coeficiente(nuevo_grado) == 0) {
                nuevo_grado--;
            }

             // Shorten the list by removing trailing zeros
            while (Grado() > nuevo_grado) {
                ls->suprime(ls->fin()); // Remove old grade
                ls->suprime(ls->fin()); // Remove unnecessary coefficient
            }
             // Add the correct new grade
            ls->inserta_ultimo(nuevo_grado);
        }
    }
}


// Returns the coefficient for a given exponent.
int polinomioL::coeficiente(int exp) {
    if (exp > Grado() || exp < 0) {
        return 0;
    }
    // Find the node at position 'exp'
    direccion d = ls->primero();
    for (int i = 0; i < exp; i++) {
        d = ls->siguiente(d);
    }
    return ls->recupera(d);
}

// Returns the number of terms with a non-zero coefficient.
int polinomioL::numero_terminos() {
    if (ls->vacia()) {
        return 0;
    }
    int contador = 0;
    // Iterate through all possible exponents up to the grade
    for (int i = 0; i <= Grado(); i++) {
        if (coeficiente(i) != 0) {
            contador++;
        }
    }
    return contador;
}


// --- OTHER METHODS YOU SHOULD KEEP ---

// Default constructor (if you need it)
polinomioL::polinomioL() {
    ls = nullptr;
}

// Empties the list
void polinomioL::vaciar(){
   if (ls != nullptr) {
       ls->elimLista();
   }
}

// Prints the list for debugging or visualization
void polinomioL::imprimir(TColor FormColor, TCanvas *Canvas) {
    if (ls != nullptr) {
        ls->imprimir2(FormColor, Canvas, 200, 700);
    }
}

void polinomioL::imprimir2(TColor FormColor, TCanvas *Canvas, int x,int y){
    if (ls != nullptr) {
        ls->imprimir2(FormColor,Canvas,x,y);
    }
}


// --- METHODS THAT ARE NO LONGER COMPATIBLE ---
// The following methods were for the <coef, exp> pair logic and will not
// work with the new dense vector logic. They should be removed or adapted.
// I am leaving them commented out so your project still compiles if they are
// referenced in the .h file, but they will not function correctly.

/*
void polinomioL::poner_termino(int coef, int exp) { }
void polinomioL::AsignarCoeficiente(int coef, int exp){ }
int polinomioL::exponente(int i){ return -1; }
int polinomioL::BuscarExponente(int e){ return -1;}
int polinomioL::BuscarTerminoN(int e){ return -1;}
void polinomioL::ponercero(){ }
void polinomioL::sumar(polinomioL* p1, polinomioL* p2){ }
void polinomioL::restar(polinomioL* p1, polinomioL* p2){ }
*/
