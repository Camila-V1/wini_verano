//---------------------------------------------------------------------------
#ifndef PrincipalFH
#define PrincipalFH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
	#include "Umemoria.h"
#include "Umemoria.h"
 #include "UPlista.h"
#include "UCSLista.h"
#include "UPlista.h"
  #include "UMS_polinomio.h"
#include "UP_polinomio.h"
#include "UP_polinomio.h"
#include "UL_polinomiocpp.h"
#include "Umemoria.h"
#include "UL_polinomiocpp.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TEdit *Edit4;
	TEdit *Edit5;
	TEdit *Edit6;
	TEdit *Edit7;
	TButton *Button6;
	TButton *Button7;
	TButton *Button8;
	TButton *Button9;
	TButton *Button10;
	TEdit *Edit8;
	TEdit *Edit9;
	TEdit *Edit10;
	TEdit *Edit11;
	TButton *Button11;
	TButton *Button12;
	TButton *Button13;
	TButton *Button14;
	TButton *Button15;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall Button9Click(TObject *Sender);
	void __fastcall Button10Click(TObject *Sender);
	void __fastcall Button11Click(TObject *Sender);
	void __fastcall Button12Click(TObject *Sender);
	void __fastcall Button13Click(TObject *Sender);
	void __fastcall Button14Click(TObject *Sender);
	void __fastcall Button15Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
  //-----------------Memoria-------------------//
   int x;
  CSmemoria* M;
 Lista * l;     //memoria
//ptrlista *    l ;  //puntero
 //Vlista *l  ;       //vector


 //  Vlista* L    ;
  // ptrlista*  L;
  //polinomios
  //LP_polinomio* poli;
  //polinomioL* poli;
	 //polinomioL* deri;
	  ///	polinomioL* poli2;
	// polinomioL* deri2;
  polinomioL* poli;
  PolinomioP* deri;
	polinomioL* poli2;
 PolinomioP* deri2;
  //PolinomioP* poli;
  // Polinomio* poli;
  //----------CONJUNTO


	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
