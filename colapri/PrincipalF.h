// PrincipalF.h
#ifndef PrincipalFH
#define PrincipalFH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>

// TUS INCLUDES
#include "Umemoria.h"
// ... mantén tus otros includes aquí ...
#include "ColaDVector.h"   //
#include "ColaPrioridad.h" //

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
    void __fastcall Button5Click(TObject *Sender);
    void __fastcall Button6Click(TObject *Sender);
    void __fastcall Button7Click(TObject *Sender);
	void __fastcall Edit3Change(TObject *Sender);
	void __fastcall Button9Click(TObject *Sender); // Este es el de CREAR


	// ---------------------------------------------

private:	// User declarations
    // Punteros a tus objetos
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
