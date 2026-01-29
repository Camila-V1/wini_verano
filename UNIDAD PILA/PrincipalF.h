//---------------------------------------------------------------------------
#ifndef PrincipalFH
#define PrincipalFH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
	#include "Umemoria.h"
#include "UCSLista.h"
#include "UPlista.h"
#include "UM_conjunto.h"
#include "UL_Coonjunto.h"
#include "UC_Conjunto.h"
#include "UPtr_conjunto.h"
#include "UPtr_conjunto.h"
	#include "Umemoria.h"
    	#include "UP_memoria.h"
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
	TButton *Button10;
	TButton *Button11;
	TButton *Button12;
	TButton *Button13;
	TButton *Button14;
	TButton *Button15;
	TButton *Button16;
	TEdit *Edit10;
	TEdit *Edit11;
	TEdit *Edit12;
	TButton *Button17;
	TButton *Button6;
	TButton *Button7;
	TButton *Button8;
	TButton *Button9;
	TEdit *Edit8;
	TEdit *Edit9;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button10Click(TObject *Sender);
	void __fastcall Button11Click(TObject *Sender);
	void __fastcall Button12Click(TObject *Sender);
	void __fastcall Button13Click(TObject *Sender);
	void __fastcall Button14Click(TObject *Sender);
	void __fastcall Button15Click(TObject *Sender);
	void __fastcall Button16Click(TObject *Sender);
	void __fastcall Button17Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall Button9Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
  //-----------------Memoria-------------------//
   int x;
  CSmemoria* M;
 Lista * l;     //memoria
//ptrlista *    l ;  //puntero
 //Vlista *l  ;       //vector
	ptr_conjunto* a;
   ptr_conjunto* c;
   ptr_conjunto* b;
	   //	conjuntolista* a;
  // conjuntolista* c;
  // conjuntolista* b;
  /*
	// OPCI�N 3: Implementaci�n con Punteros
	ptr_conjunto* a;
	ptr_conjunto* b;
	ptr_conjunto* c;
	*/

	/*
	// OPCI�N 4: Implementaci�n con Vector Caracter�stico
	conjunto* a;
	conjunto* b;
	conjunto* c;
	*/


	//------------------
	//PILA
  pilaM   *pila;
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
