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
M->MostrarMemoriaDesplazada(Form1->Color, Canvas, 450, 20, StrToInt(d), StrToInt(p));
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
	//libres
    int cantLibres = M->Espacio_Disponible();
	Edit8->Text = IntToStr(cantLibres);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
	   // ocupados
       int cantOcupados = M->Espacio_ocupado();
	Edit9->Text = IntToStr(cantOcupados);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
    // 1. m.crear (Reinicializamos la memoria)
    // Es recomendable liberar la anterior si existía para evitar fugas de memoria
    if (M != NULL) delete M;
    M = new CSmemoria();

    // 2. x = m.new_espacio('c,s,i')
    int x = M->new_espacio("c,s,i");

    // 3. y = m.new_espacio('otra')
    int y = M->new_espacio("otra");

    // 4. w = m.new_espacio('vez')
    int w = M->new_espacio("vez");

    // 5. q = m.new_espacio('eleccion')
    int q = M->new_espacio("eleccion");

    // 6. m.delete_espacio(y)
    M->Delete_espacio(y);

    // 7. q = m.new_espacio('que,tal')
    // Nota: La imagen reasigna 'q', perdiendo la referencia anterior a 'eleccion'
    q = M->new_espacio("que,tal");

    // (Opcional) Refrescar la pantalla para ver los cambios
    // Puedes llamar a tu función de pintar aquí o forzar el repintado
    Refresh();
}
//---------------------------------------------------------------------------

