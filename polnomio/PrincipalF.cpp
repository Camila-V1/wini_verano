//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "PrincipalF.h"
#include <System.Types.hpp> // para System::Types::TPoint y Point()
#include <vector>
#include <algorithm>
#include <cmath> // Para std::lround

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
	poli =    new polinomioL(M);
	// CORRECCIÓN: La variable 'deri' se usa como PolinomioP, se deja como estaba.
	// La lógica de conversión entre tipos se maneja en los botones.
	deri =    new PolinomioP();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject *Sender)
{
	poli2 =   new polinomioL(M);
	deri2 =   new PolinomioP();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button8Click(TObject *Sender)
{
	int c= StrToInt(Edit8->Text);
	int e= StrToInt(Edit9->Text);
	poli->poner_termino2(c,e)   ;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button9Click(TObject *Sender)
{
	int c= StrToInt(Edit10->Text);
	int e= StrToInt(Edit11->Text);
	// CORRECCIÓN: Se cambió poner_termino a poner_termino2 para ser consistente.
	poli2->poner_termino2(c,e)   ;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button10Click(TObject *Sender)
{
	poli-> imprimir(Form1->Color,Canvas);
}
//---------------------------------------------------------------------------

// CORRECCIÓN: La función 'evaluar' ahora itera por grado.
double evaluar(polinomioL* poli, double x) {
	double resultado = 0.0;
	if (!poli) return 0.0;

	// Recorre el polinomio desde el exponente 0 hasta su grado máximo.
	for (int exp = 0; exp <= poli->Grado(); exp++) {
		int coef = poli->coeficiente(exp);
		if (coef != 0) {
			// Manejar el caso de x == 0 y exponente negativo para evitar división por cero
			if (x == 0 && exp < 0) {
				continue;
			}
			// Suma el valor del término (coef * x^exp) al resultado
			resultado += coef * pow(x, exp);
		}
	}
	return resultado;
}

// Dibuja la gráfica de un polinomio. (Sin cambios, ya usaba 'evaluar' correctamente)
void drawPolynomial(polinomioL* poli, TColor color, int x0, int y0, int anchoPlano, int altoPlano, double xMin, double xMax, double escalaX, double escalaY, TCanvas* Canvas)
{
	if (!poli) return;
	Canvas->Pen->Color = color;

	int xi_min = x0 + static_cast<int>(xMin * escalaX);
	int xi_max = x0 + static_cast<int>(xMax * escalaX);

	bool firstPoint = true;

	for (int i = xi_min; i <= xi_max; i++)
	{
		double x = static_cast<double>(i - x0) / escalaX;
		double y = evaluar(poli, x);

		int j = y0 - static_cast<int>(std::lround(y * escalaY));

		if (j >= y0 - altoPlano / 2 && j <= y0 + altoPlano / 2)
		{
			if (firstPoint) {
				Canvas->MoveTo(i, j);
				firstPoint = false;
			} else {
				Canvas->LineTo(i, j);
			}
		}
		else {
			firstPoint = true;
		}
	}
}


void __fastcall TForm1::Button11Click(TObject *Sender)
{
	poli2-> imprimir(Form1->Color,Canvas);
}
//---------------------------------------------------------------------------
void vaciar (polinomioL* &p,CSmemoria* M) {
	if (p != nullptr) {
		p->vaciar();
		delete p; // Libera la memoria del objeto antiguo
	}
	p = new polinomioL(M); // Crea un nuevo objeto limpio
}

// DERIVAR no cambia porque recibe PolinomioP, que tiene su propia lógica.
void DERIVAR (polinomioL* &p1,PolinomioP* poli_p)
{
	int ex,co;
	for (int i=1; i <= poli_p->numero_terminos(); i++) {
		ex = poli_p->exponente(i);
		co = poli_p->coeficiente(ex);
		if (ex > 0) { // Solo derivar terminos con exponente > 0
			p1->poner_termino2((co*ex),(ex-1));
		}
	}
}

// CORRECCIÓN: La función 'copiar' ahora itera por grado.
void copiar (PolinomioP* &p_destino, polinomioL* p_origen)
{
	if (!p_origen || !p_destino) return;
	// Itera a través del polinomio de origen por grado
	for (int exp = 0; exp <= p_origen->Grado(); exp++) {
		int coef = p_origen->coeficiente(exp);
		// Solo copia los términos que no son cero
		if (coef != 0) {
			p_destino->poner_termino(coef,exp);
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button12Click(TObject *Sender)
{
	// Proceso de derivación para el primer polinomio
	deri->vaciar();       // 1. Limpia el polinomio auxiliar (PolinomioP)
	copiar (deri,poli);   // 2. Copia el polinomioL a PolinomioP
	vaciar (poli,M);      // 3. Limpia el polinomioL original
	DERIVAR(poli,deri);   // 4. Deriva desde PolinomioP y guarda en polinomioL
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button13Click(TObject *Sender)
{
    // Proceso de derivación para el segundo polinomio
	deri2->vaciar();
	copiar (deri2,poli2);
	vaciar (poli2,M);
	DERIVAR(poli2,deri2);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button14Click(TObject *Sender)
{
	Canvas->Brush->Color = clBtnFace;
	Canvas->FillRect(Canvas->ClipRect);
	int ancho = Form1->Width;
	int alto = Form1->Height;
	int anchoPlano = ancho /2.3;
	int altoPlano = alto /1.4;
	int x0 = ancho / 2;
	int y0 = alto / 2;
	const double escala = 50.0;

	Canvas->Pen->Color = clBlack;
	Canvas->MoveTo(x0 - anchoPlano / 2, y0);
	Canvas->LineTo(x0 + anchoPlano / 2, y0);
	Canvas->Pen->Color= clGray;
	Canvas->MoveTo(x0, y0 - altoPlano / 2);
	Canvas->LineTo(x0, y0 + altoPlano / 2);
	Canvas->Pen->Color= clBlack;
	double p = StrToFloat(InputBox("izq", "Por favor, introduce coeficiente", ""));
	double v = StrToFloat(InputBox("dere", "Por favor, introduce el exponente", ""));
	drawPolynomial(poli, clBlue, x0, y0, anchoPlano, altoPlano,p,v, escala, escala, Canvas);
	drawPolynomial(poli2, clRed, x0, y0, anchoPlano, altoPlano,p,v, escala, escala, Canvas);
}

//---------------------------------------------------------------------------
// Las funciones de área no necesitan cambios, ya que dependen de 'evaluar', que ya fue corregida.

void fillAreaUnderCurve(
	polinomioL* poli,
	TColor colorAreaPositiva,
	TColor colorAreaNegativa,
	int x0, int y0,
	int anchoPlano, int altoPlano,
	double xA, double xB,
	double escalaX, double escalaY,
	TCanvas* Canvas)
{
	if (!poli) return;
	if (xA > xB) std::swap(xA, xB);

	const int left   = x0 - anchoPlano / 2;
	const int right  = x0 + anchoPlano / 2;
	const int top    = y0 - altoPlano / 2;
	const int bottom = y0 + altoPlano / 2;

	int xi = std::max(left,  (int)std::lround(x0 + xA * escalaX));
	int xj = std::min(right, (int)std::lround(x0 + xB * escalaX));

	if (xi >= xj) return;

	TColor oldColor = Canvas->Pen->Color;
	int oldWidth = Canvas->Pen->Width;
	Canvas->Pen->Width = 1;

	for (int i = xi; i <= xj; ++i) {
		double x = (double)(i - x0) / escalaX;
		double y = evaluar(poli, x);
		int j = y0 - (int)std::lround(y * escalaY);
		j = std::min(std::max(j, top), bottom);

		if (y >= 0) {
			Canvas->Pen->Color = colorAreaPositiva;
			if (j <= y0) {
				 Canvas->MoveTo(i, y0);
				 Canvas->LineTo(i, j);
			}
		} else {
			Canvas->Pen->Color = colorAreaNegativa;
			if (j > y0) {
				Canvas->MoveTo(i, y0);
				Canvas->LineTo(i, j);
			}
		}
	}
	Canvas->Pen->Color = oldColor;
	Canvas->Pen->Width = oldWidth;
}


void fillAreaBetweenCurves(
	polinomioL* p1, polinomioL* p2,
	TColor colorRelleno,
	int x0, int y0,
	int anchoPlano, int altoPlano,
	double xA, double xB,
	double escalaX, double escalaY,
	TCanvas* Canvas)
{
	if (!p1 || !p2) return;
	if (xA > xB) std::swap(xA, xB);

	const int left   = x0 - anchoPlano / 2;
	const int right  = x0 + anchoPlano / 2;
	const int top    = y0 - altoPlano / 2;
	const int bottom = y0 + altoPlano / 2;

	int xi = std::max(left,  (int)std::lround(x0 + xA * escalaX));
	int xj = std::min(right, (int)std::lround(x0 + xB * escalaX));

	if (xi >= xj) return;

	std::vector<TPoint> poly;
	poly.reserve((xj - xi + 1) * 2);

	for (int i = xi; i <= xj; ++i) {
		double x = (double)(i - x0) / escalaX;
		double y = evaluar(p1, x);
		int j = y0 - (int)std::lround(y * escalaY);
		j = std::min(std::max(j, top), bottom);
		poly.push_back(Point(i, j));
	}

	for (int i = xj; i >= xi; --i) {
		double x = (double)(i - x0) / escalaX;
		double y = evaluar(p2, x);
		int j = y0 - (int)std::lround(y * escalaY);
		j = std::min(std::max(j, top), bottom);
		poly.push_back(Point(i, j));
	}

	if (poly.size() < 3) return;

	TBrushStyle oldB = Canvas->Brush->Style;
	TColor      oldC = Canvas->Brush->Color;
	TPenStyle   oldP = Canvas->Pen->Style;

	Canvas->Brush->Style = bsSolid;
	Canvas->Brush->Color = colorRelleno;
	Canvas->Pen->Style   = psClear;
	Canvas->Polygon(&poly[0], (int)poly.size() - 1);

	Canvas->Brush->Style = oldB;
	Canvas->Brush->Color = oldC;
	Canvas->Pen->Style   = oldP;
}


//---------------------------------------------------------------------------
void __fastcall TForm1::Button15Click(TObject *Sender)
{
	Canvas->Brush->Color = clBtnFace;
	Canvas->FillRect(Canvas->ClipRect);

	const int ancho = this->Width;
	const int alto  = this->Height;
	const int anchoPlano = (int)(ancho / 2.3);
	const int altoPlano  = (int)(alto  / 1.4);
	const int x0 = ancho / 2;
	const int y0 = alto  / 2;

	const double escalaX = 50.0;
	const double escalaY = 50.0;

	Canvas->Pen->Color = clBlack;  //horisoltal
	Canvas->MoveTo(x0 - anchoPlano / 2, y0);
	Canvas->LineTo(x0 + anchoPlano / 2, y0);
	Canvas->Pen->Color = clBlack;        //vertical
	Canvas->MoveTo(x0, y0 - altoPlano / 2);
	Canvas->LineTo(x0, y0 + altoPlano / 2);

	double xA, xB;
	try {
		xA = StrToFloat(InputBox("Límite Izquierdo", "Valor inicial de x (xA):", "-2"));
		xB = StrToFloat(InputBox("Límite Derecho",   "Valor final de x (xB):",   "2"));
	} catch (const EConvertError &e) {
		ShowMessage("Por favor, introduce valores numéricos válidos.");
		return;
	}

	fillAreaUnderCurve(poli, clLime, clLime, x0, y0, anchoPlano, altoPlano, xA, xB, escalaX, escalaY, Canvas);

	Canvas->Pen->Width = 2;
	drawPolynomial(poli, clBlue, x0, y0, anchoPlano, altoPlano, -10, 10, escalaX, escalaY, Canvas);
	Canvas->Pen->Width = 1;
}
//---------------------------------------------------------------------------

