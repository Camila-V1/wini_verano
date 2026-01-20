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
   //	M->ImprimirP_DE_A_A_B(Form1->Color,Canvas,800,20,StrToInt(d),StrToInt(p));
	 M->	MostrarMemoriaDesplazada   (Form1->Color,Canvas,800,20,StrToInt(d),StrToInt(p));
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
void __fastcall TForm1::Button6Click(TObject *Sender)
{
		l = new Lista(M);
//  l = new ptrlista();
  //l = new Vlista();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject *Sender)
{
	int p= StrToInt(Edit8->Text);
//l-> inserta_primero(p);
l-> insertar(l-> primero(),p);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button8Click(TObject *Sender)
{   	int p= StrToInt(Edit9->Text);
 //l-> inserta_ultimo(p);
l-> insertar(l-> fin(),p);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button9Click(TObject *Sender)
{
			l->imprimir2(Form1->Color,Canvas, 200,400);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button10Click(TObject *Sender)
{
a = new conjuntoM(M);
	// a = new conjuntolista(M);
	// a = new ptr_Clista();
	// a = new conjunto();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject *Sender)
{
b = new conjuntoM(M);
	// b = new conjuntolista(M);
	// b = new ptr_Clista();
	// b = new conjunto();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button12Click(TObject *Sender)
{
c = new conjuntoM(M);
	// c = new conjuntolista(M);
	// c = new ptr_Clista();
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
//---------------------------------------------------------------------------

void __fastcall TForm1::Button14Click(TObject *Sender)
{
   Canvas->Brush->Color = clBtnFace;
	Canvas->FillRect(Canvas->ClipRect);
	String p=  Edit12->Text;;
if (p=="a") {
  a->imprimir(Form1->Color,Canvas);
}
else {
	if (p=="b") {
		 b->imprimir(Form1->Color,Canvas) ;
	} else {
	c->imprimir(Form1->Color,Canvas)  ;
	}
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
	intersectar_conjuntos(a, b, c);


	Canvas->Brush->Color = clBtnFace;
	Canvas->FillRect(Canvas->ClipRect);

	if (c != NULL) {
		c->imprimir(this->Color, Canvas);
	}


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button17Click(TObject *Sender)
{
diferencia_simetrica_para_M(a, b, c);

	// Limpiar la pantalla y mostrar el nuevo contenido de 'c'.
	Canvas->Brush->Color = clBtnFace;
	Canvas->FillRect(Canvas->ClipRect);
	c->imprimir(this->Color, Canvas);
}
//---------------------------------------------------------------------------

