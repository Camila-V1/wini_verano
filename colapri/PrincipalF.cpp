// PrincipalF.cpp
#include <vcl.h>
#pragma hdrstop
#include "PrincipalF.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
    // 1. INICIALIZAR PUNTEROS EN NULL
    Dicola = NULL;
    CPrioridad = NULL;

    // 2. CONFIGURAR INTERFAZ



    // --- ZONA COLA PRIORIDAD (Derecha) ---
    // Poner
    Button5->Caption = "Poner CP";
	Edit5->Text = ""; Edit5->TextHint = "Dato";
    Edit6->Text = ""; Edit6->TextHint = "Prioridad";

    // Atender (Salida)
    Button6->Caption = "Atender";
    Edit7->Text = ""; Edit7->TextHint = "Atendido";
    Edit7->ReadOnly = true;

    // Frecuencia
    Button7->Caption = "Conf. Frec.";
    Edit8->Text = ""; Edit8->TextHint = "Cual Prioridad?";
    Edit9->Text = ""; Edit9->TextHint = "Cuanta Frec?";
}

// Función auxiliar de dibujo
void __fastcall TForm1::ActualizarDibujo() {
    Refresh(); // Limpia


    // Dibuja la Cola de Prioridad arriba (Y=100 según tu clase)
    if (CPrioridad != NULL) {
        CPrioridad->imprimir(Form1->Color, Canvas); //
    }
}

// =========================================================
//                  BOTÓN 8: CREAR (OBLIGATORIO)
// =========================================================// =========================================================
//                  ZONA DICOLA
// =========================================================

// METER INICIO (Usa Edit1)// METER FINAL (Usa Edit2 - DISTINTO AL EDIT1)// SACAR INICIO (Muestra en Edit3)// SACAR FINAL (Muestra en Edit4)// =========================================================
//                  ZONA COLA PRIORIDAD
// =========================================================

// PONER (Usa Edit5 para Dato, Edit6 para Prioridad)
// PONER (Carga automática según la imagen)
void __fastcall TForm1::Button5Click(TObject *Sender) {
    if (CPrioridad == NULL) {
        ShowMessage("Primero crea la cola con el Button9");
        return;
    }

    // --- Inserciones de la imagen ---

    // Prioridad 1
    CPrioridad->poner(100, 1); //
    CPrioridad->poner(200, 1); //
    CPrioridad->poner(300, 1); //

    // Prioridad 2
    CPrioridad->poner(1, 2);   //
    CPrioridad->poner(2, 2);   //
    CPrioridad->poner(3, 2);   //

    // Prioridad 3
    CPrioridad->poner(10, 3);  //
    CPrioridad->poner(11, 3);  //
    CPrioridad->poner(12, 3);  //

    ActualizarDibujo();
}

// ATENDER/SACAR (Muestra en Edit7)
void __fastcall TForm1::Button6Click(TObject *Sender) {
    if (CPrioridad == NULL) return;
    int x;
    if(CPrioridad->sacar(x)) { //
        Edit7->Text = IntToStr(x); // MOSTRAR EN EDIT
        ActualizarDibujo();
    } else {
        Edit7->Text = "---";
    }
}

// ASIGNAR FRECUENCIA (Usa Edit8 Prio, Edit9 Frec)
void __fastcall TForm1::Button7Click(TObject *Sender) {
    if (CPrioridad == NULL) return;
    if(Edit8->Text == "" || Edit9->Text == "") return;

    CPrioridad->asignarPrioridadCola(StrToInt(Edit9->Text), StrToInt(Edit8->Text)); //
    ActualizarDibujo();
}
void __fastcall TForm1::Edit3Change(TObject *Sender)
{
    // Función vacía para corregir error del linker
}

void __fastcall TForm1::Button9Click(TObject *Sender)
{
if (CPrioridad != NULL) delete CPrioridad;
   	CPrioridad = new ColaPri();       //
   ActualizarDibujo();
}

