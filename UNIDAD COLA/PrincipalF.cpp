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

}

// Funci�n auxiliar de dibujo
void __fastcall TForm1::ActualizarDibujo() {


}


void __fastcall TForm1::Button9Click(TObject *Sender)
{
if (CPrioridad != NULL) delete CPrioridad;
   	CPrioridad = new ColaPri();       //
   ActualizarDibujo();
}

void __fastcall TForm1::Button1Click(TObject *Sender)
{

    M = new CSmemoria();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
String d=Edit3->Text;

String p= Edit4->Text;

Canvas->Brush->Color = clBtnFace;

Canvas->FillRect(Canvas->ClipRect);

M-> MostrarMemoriaDesplazada   (Form1->Color,Canvas,800,20,StrToInt(d),StrToInt(p));

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{

	Cola = new colaM(M);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{

	Cola->Meter(StrToInt(Edit1->Text));



}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
	int elemento;
    Cola->Sacar(elemento);
        Edit2->Text=elemento;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender)
{
         	Cola->imprimir(Form1->Color,Canvas);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit3Change(TObject *Sender)
{
    // Función vacía para corregir error del linker
}
//---------------------------------------------------------------------------
