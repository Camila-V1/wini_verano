//---------------------------------------------------------------------------
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
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
M =new CSmemoria();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
   String d =Edit1->Text;
M->new_espacio(AnsiString(d).c_str());
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
          	String d=Edit2->Text;
M-> Delete_espacio(StrToInt(d));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
	  String d=Edit3->Text;
	String p= Edit4->Text;
	 Canvas->Brush->Color = clBtnFace;
   Canvas->FillRect(Canvas->ClipRect);
   M->ImprimirP_DE_A_A_B(Form1->Color,Canvas,800,20,StrToInt(d),StrToInt(p));
   //	 M->	MostrarMemoriaDesplazada   (Form1->Color,Canvas,800,20,StrToInt(d),StrToInt(p));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
  		String d=Edit5->Text;
	String p= Edit6->Text;
	String v=  Edit7->Text;

 M->poner_dato(StrToInt(AnsiString(d).c_str()),AnsiString(p).c_str(),StrToInt(AnsiString(v).c_str()));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button10Click(TObject *Sender)
{
//a = new conjuntoM(M);
	// a = new conjuntolista(M);
	a = new ptr_Clista();
	// a = new conjunto();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject *Sender)
{
//b = new conjuntoM(M);
	// b = new conjuntolista(M);
	b = new ptr_Clista();
	// b = new conjunto();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button12Click(TObject *Sender)
{
//c = new conjuntoM(M);
	// c = new conjuntolista(M);
	 c = new ptr_Clista();
	// c = new conjunto();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button13Click(TObject *Sender)
{
  String p= Edit10->Text;
 String v= Edit11->Text;
if (p=="a") {
  a->inserta(StrToInt(AnsiString(v).c_str()));
}
else
 {
	if (p=="b") {
	b->inserta(StrToInt(AnsiString(v).c_str()));
	}else {
	c->inserta(StrToInt(AnsiString(v).c_str()));
	}
}
}
// Asumiendo que tus objetos a, b y c son de tipo ptr_Clista*
void intersectar_conjuntos(ptr_Clista* A, ptr_Clista* B, ptr_Clista* C) {
    // 1. Limpiar el conjunto C por si tenía basura de antes
    while (!C->vacio()) {
        C->suprime(C->muestrea());
    }

    // Conjunto temporal para no perder los datos de A
    ptr_Clista* Aux = new ptr_Clista();

    // 2. Iterar sobre A usando muestrea()
    while (!A->vacio()) {
        // Sacamos un elemento aleatorio
        int e = A->muestrea();

        // Verificamos si pertenece al otro conjunto (B)
        if (B->pertenece(e)) {
            C->inserta(e); // Si está en ambos, se añade a la intersección (C)
        }

        // Guardamos el elemento en Aux y lo eliminamos de A
        // para que muestrea() pueda darnos uno nuevo en la siguiente vuelta
        Aux->inserta(e);
        A->suprime(e);
    }

    // 3. Restaurar el conjunto A a su estado original
    while (!Aux->vacio()) {
        int e = Aux->muestrea();
        A->inserta(e);
        Aux->suprime(e);
    }

    // Liberar la memoria del conjunto temporal
    delete Aux;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button14Click(TObject *Sender)
{
    // 1. Limpiar el lienzo (Canvas)
    Canvas->Brush->Color = clBtnFace;
    Canvas->FillRect(Canvas->ClipRect);

    // 2. Obtener el nombre del conjunto del Edit
    String p = Edit12->Text;

    // 3. Configurar las dimensiones del círculo
    int centroX = 400; // Posición X del centro en la pantalla
    int centroY = 300; // Posición Y del centro en la pantalla
    int radio = 150;   // Tamaño del círculo
	TColor colorCirculo = Form1->Color; // Color de fondo del círculo

    // 4. Hacer el llamado al conjunto correspondiente
    if (p == "a") {
        a->mostrarEnCirculo(centroX, centroY, radio, colorCirculo, Canvas);
    }
    else if (p == "b") {
        b->mostrarEnCirculo(centroX, centroY, radio, colorCirculo, Canvas);
    }
    else if (p == "c") {
        c->mostrarEnCirculo(centroX, centroY, radio, colorCirculo, Canvas);
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button15Click(TObject *Sender)
{
  int e,x;
while (a->cardinal()!=0){

 e=a->muestrea();
 c->inserta(e);
 a->suprime(e);

}
while (b->cardinal()!=0){

 e=b->muestrea();
 c->inserta(e);
 b->suprime(e);

}
}
//---------------------------------------------------------------------------


void diferencia_simetrica_para_M(conjuntoM* a, conjuntoM* b, conjuntoM* c)
{
	if (a == NULL || b == NULL || c == NULL) {
		ShowMessage("Error: Uno o más conjuntos no han sido creados.");
		return;
	}
while (!c->vacio()) {
		c->suprime(c->muestrea());
	}
conjuntoM* a_copia = a->copia();
	while (!a_copia->vacio()) {
		int elemento_actual = a_copia->muestrea();
		a_copia->suprime(elemento_actual);
		if (!b->pertenece(elemento_actual)) {
			c->inserta(elemento_actual);
		}
	}
	delete a_copia;

	conjuntoM* b_copia = b->copia();
	while (!b_copia->vacio()) {
		int elemento_actual = b_copia->muestrea();
		b_copia->suprime(elemento_actual);
		if (!a->pertenece(elemento_actual)) {
			c->inserta(elemento_actual);
		}
	}
	delete b_copia;
}
void intersectar_conjuntos(conjuntoM* a, conjuntoM* b, conjuntoM* c)
{
	if (a == NULL || b == NULL || c == NULL) {
		ShowMessage("Error: Uno o más conjuntos no han sido creados.");
		return;
	}

		while (!c->vacio()) {
		c->suprime(c->muestrea());
	}

conjuntoM* a_copia = a->copia();

while (!a_copia->vacio()) {
		int elemento_actual = a_copia->muestrea();

		a_copia->suprime(elemento_actual);

	if (b->pertenece(elemento_actual)) {
			c->inserta(elemento_actual);
		}
	}


	delete a_copia;
}


void __fastcall TForm1::Button16Click(TObject *Sender)
{
    // Validar que los conjuntos existan antes de operar
    if (a != NULL && b != NULL && c != NULL) {
        // Llamado a la función que acabamos de crear
        intersectar_conjuntos(a, b, c);
    }

    // Limpiar el lienzo
    Canvas->Brush->Color = clBtnFace;
    Canvas->FillRect(Canvas->ClipRect);

  
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button17Click(TObject *Sender)
{
//diferencia_simetrica_para_M(a, b, c);

	// Limpiar la pantalla y mostrar el nuevo contenido de 'c'.
	Canvas->Brush->Color = clBtnFace;
	Canvas->FillRect(Canvas->ClipRect);
	c->imprimir(this->Color, Canvas);
}
//---------------------------------------------------------------------------



