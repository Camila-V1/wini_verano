// PrincipalF.h
#ifndef PrincipalFH
#define PrincipalFH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>

// TUS INCLUDES
#include "..\UNIDADES COMPLEMENTARIAS\Memoria\Umemoria.h"
#include "..\UNIDADES COMPLEMENTARIAS\cola\UC_memoria.h"    // Cola con memoria
// ... mant�n tus otros includes aqu� ...
#include "..\UNIDADES COMPLEMENTARIAS\cola\ColaDVector.h"   //
#include "..\UNIDADES COMPLEMENTARIAS\cola\ColaPrioridad.h" //

//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TButton *Button5;
    TButton *Button6;
    TButton *Button7;
	TEdit *Edit5;
	TEdit *Edit6;
	TEdit *Edit7;
	TEdit *Edit8;
	TEdit *Edit9;
	TButton *Button9;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	TButton *Button8;
	TButton *Button10;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TEdit *Edit4;
	void __fastcall Edit3Change(TObject *Sender);
	void __fastcall Button9Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall Button10Click(TObject *Sender); // Este es el de CREAR


	// ---------------------------------------------

private:	// User declarations
    // Punteros a tus objetos
    CSmemoria   *M;            // Memoria
    colaM       *Cola;         // Cola con memoria
    ColaDVector *Dicola;
    ColaPri     *CPrioridad;

    void __fastcall ActualizarDibujo();

public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
