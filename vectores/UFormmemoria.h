//---------------------------------------------------------------------------
#include "Umemoria.h"
#include "UCSLista.h"
#include "UPlista.h"
#include "UVLista.h"
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#ifndef UFormmemoriaH
#define UFormmemoriaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "LP_Polinomio.h"
#include "UL_polinomiocpp.h"
#include "UMS_polinomio.h"
#include "UP_polinomio.h"
#include "UV_polinomio.h"
#include "UC_Conjunto.h"
#include "UL_Coonjunto.h"
#include "UM_conjunto.h"
#define UPlistaH
#include "Matriz_1N.h"
#include "matriz_2N.h"
#include "Matricez_ptr1.h"
#include "Matricez_ptr2.h"
#include "matrizCCcpp.h"
#include "matrizSC.h"
#include "MatrizEnLista.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *Button10;
	TEdit *Edit10;
	TEdit *Edit11;
	TButton *Button16;
	TButton *Button5;
	TEdit *Edit7;
	TEdit *Edit6;
	TEdit *Edit5;
	TEdit *Edit4;
	TEdit *Edit3;
	TEdit *Edit2;
	TEdit *Edit1;
	TButton *Button4;
	TButton *Button3;
	TButton *Button1;
	TButton *Button2;
	TButton *Button6;
	TButton *Button7;
	TButton *Button8;
	TButton *Button9;
	TButton *Button11;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button9Click(TObject *Sender);
	void __fastcall Button10Click(TObject *Sender);
	void __fastcall Button11Click(TObject *Sender);
	void __fastcall Button13Click(TObject *Sender);
	void __fastcall Button14Click(TObject *Sender);
	void __fastcall Button15Click(TObject *Sender);
	void __fastcall Button16Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button17Click(TObject *Sender);
	void __fastcall Button20Click(TObject *Sender);
	void __fastcall Button21Click(TObject *Sender);
	void __fastcall Button18Click(TObject *Sender);
	void __fastcall Button19Click(TObject *Sender);
	void __fastcall Button22Click(TObject *Sender);
	void __fastcall Button23Click(TObject *Sender);
	void __fastcall Button25Click(TObject *Sender);
	void __fastcall Button26Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
private:	// User declarations
   CSmemoria*  M;
  Lista* L;
 //  Vlista* L    ;
  // ptrlista*  L;
  //polinomios
  //LP_polinomio* poli;
  polinomioL* poli;
	 polinomioL* deri;
		polinomioL* poli2;
	 polinomioL* deri2;
 // polinomioM* poli;
 // polinomioM* deri;
 //	polinomioM* poli2;
 // polinomioM* deri2;
  //PolinomioP* poli;
  // Polinomio* poli;
  //----------CONJUNTO
  conjuntoM * a;
   conjuntoM * b;
	conjuntoM * c;

 //	MatrizDispersa* ma;
  //	MatrizDispersa2* ma;


  //	MatrizDispersaptr * ma;
  //	Matrizptr2  * ma;
 //	MatrizCC   * ma;
	//	MatrizSC  * ma;
	LBCS* ma;
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
