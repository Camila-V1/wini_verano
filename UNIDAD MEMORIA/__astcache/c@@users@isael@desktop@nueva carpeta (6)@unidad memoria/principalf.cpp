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
