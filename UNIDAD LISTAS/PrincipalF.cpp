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
   //	M->MostrarMemoriaDesplazada(Form1->Color,Canvas,500,20,StrToInt(d),StrToInt(p));
	 M->	ImprimirP_DE_A_A_B   (Form1->Color,Canvas,500,20,StrToInt(d),StrToInt(p));
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
  //l = new ptrlista();
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
			l->imprimir2(Form1->Color,Canvas, 200,600);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender)
{   	int p= StrToInt(Edit10->Text);
l->suprime(p);
}
//---------------------------------------------------------------------------

