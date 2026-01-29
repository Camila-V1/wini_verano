//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <algorithm>
  #include <vector>
#include "UFormmemoria.h"
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
M= new  CSmemoria();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{      String d=Edit3->Text;
	String p= Edit4->Text;



	 Canvas->Brush->Color = clBtnFace;
	Canvas->FillRect(Canvas->ClipRect);
	M->ImprimirP_DE_A_A_B(Form1->Color,Canvas,600,20,StrToInt(d),StrToInt(p));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
	  String d=Edit5->Text;
	String p= Edit6->Text;
	String v= Edit7->Text;
	M->poner_dato(StrToInt(AnsiString(d).c_str()),AnsiString(p).c_str(),StrToInt(AnsiString(v).c_str()));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
 String d=Edit2->Text;
M-> Delete_espacio(StrToInt(d));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
ma = new LBCS();

}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button9Click(TObject *Sender)
{

  int  v= StrToInt(InputBox("el valor", "Por favor,valor", ""));
ma->Definir_valor_repetido(v);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender)
{

   int direccion = StrToInt(Edit10->Text);
	string id = AnsiString(Edit11->Text).c_str();
	M->sumarValorDesdeDireccion(direccion, id, 5);

}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button11Click(TObject *Sender)
{
   	 ma-> imprimir(Form1->Color,Canvas) ;
   // ma->DibujarVectores(Canvas,150,400);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button13Click(TObject *Sender)
{
 poli-> imprimir(Form1->Color,Canvas);
}
//---------------------------------------------------------------------------
void vaciar (polinomioL* &deri,CSmemoria* M) {
	if (deri->numero_terminos()!=0) {
	 deri->vaciar();
	 deri=new polinomioL(M);
 }
}
void DERIVAR (polinomioL* &p1,polinomioL* poli)

{  int ex,co;
  for (int i=1; i <= poli->numero_terminos(); i++) {
ex=poli->exponente(i);
co=poli->coeficiente(ex);
 p1->poner_termino((co*ex),(ex-1));  //puntero siempre al final y enlazes como se inserte

}
}
 void copiar (polinomioL* &p1,polinomioL* poli)
 {
	// Recorre todos los t�rminos del polinomio
	for (int i = 1; i <= poli->numero_terminos(); i++) {
		// Obtiene el coeficiente y el exponente del t�rmino
		int exp = poli->exponente(i);
		int coef = poli->coeficiente(exp);
	p1->poner_termino(coef,exp);

	}


 }

void __fastcall TForm1::Button14Click(TObject *Sender)
{
  vaciar (deri,M);
   copiar (deri,poli)   ;
	 vaciar (poli,M);
   //	deri-> imprimir(Form1->Color,Canvas);
	 //vaciar (poli,M);
 DERIVAR(poli,deri);
// deri-> imprimir(Form1->Color,Canvas);
}
//---------------------------------------------------------------------------
  double evaluar2(polinomioL* poli, double x) {
	double resultado = 0.0;
	double valorTermino;
	// Recorre todos los t�rminos del polinomio
	for (int i = 1; i <= poli->numero_terminos(); i++) {
		// Obtiene el coeficiente y el exponente del t�rmino
		int exp = poli->exponente(i);
		int coef = poli->coeficiente(exp);
		// Calcula el valor del t�rmino para el valor dado de x
		valorTermino = coef * pow(x, exp);
		// Suma el valor del t�rmino al resultado
		resultado += valorTermino;
	}
	return resultado;
}
void drawPolynomial2(polinomioL* poli, TColor color, int x0, int y0, int anchoPlano, int altoPlano, double xMin, double xMax,TCanvas* Canvas)
{
	bool firstPoint = true;
	Canvas->Pen->Color = color;
	double p=poli->Grado();
	p=poli->coeficiente(p);
	for (int i = x0 - anchoPlano / 2; i <= x0 + anchoPlano / 2; i++)
	{
		double x =(double)(i - x0) / (anchoPlano / 2);
		if (x < xMin || x > xMax) continue; // Ignora los valores de x fuera de los l�mites
		double y = evaluar2(poli, x);
		y = min(max(y, -100.0), 100.0); // Limitamos el valor de y entre -1 y 1
		int j = y0 - (int)(y * (altoPlano / 2));
		if (j >= y0 - altoPlano / 2 && j <= y0 + altoPlano / 2)
		{
			int j_line;
			if (p >= 0) // Si el coeficiente principal es positivo
			{
				Canvas->MoveTo(i, j);
				j_line = min(j, y0 - altoPlano / 2); // Limita la l�nea a los l�mites de la gr�fica
				Canvas->LineTo(i, j_line); // Dibujamos una l�nea desde el eje x hasta el punto del polinomio
			}
			else // Si el coeficiente principal es negativo
			{      //	Canvas->LineTo(i, j);
				Canvas->MoveTo(i, j);
				j_line = max(j, y0 + altoPlano / 2); // Limita la l�nea a los l�mites de la gr�fica
			Canvas->LineTo(i, j_line); // Dibujamos una l�nea desde el punto del polinomio hasta el l�mite inferior
			}
		}
	}
}


double evaluar(polinomioL* poli, double x) {
	double resultado = 0.0;
	// Recorre todos los t�rminos del polinomio
	for (int i = 1; i <= poli->numero_terminos(); i++) {
		// Obtiene el exponente y coeficiente del t�rmino
		int exp = poli->exponente(i);
		int coef = poli->coeficiente(exp);
		// Manejar el caso de x == 0 y exponente negativo para evitar divisi�n por cero
		if (x == 0 && exp < 0) {
			// Si el exponente es negativo y x es 0, podemos decidir no sumar nada a resultado
			// Alternativamente, podr�as asignar alg�n valor espec�fico seg�n el comportamiento que desees.
			continue; // O puedes retornar un valor predefinido
		}
		// Suma el valor del t�rmino (coef * x^exp) al resultado
		resultado += coef * pow(x, exp);
	}
	return resultado;

}
void drawPolynomial(polinomioL* poli, TColor color, int x0, int y0, int anchoPlano, int altoPlano, double xMin, double xMax, TCanvas* Canvas)
{
	Canvas->Pen->Color = color;
	 int puntoGrosor = 2; // Define el tama�o de los circulos
	// Recorre el plano para dibujar el �rea entre la curva y los l�mites del plano
	for (int i = x0 - anchoPlano / 2; i <= x0 + anchoPlano / 2; i++)
	{
		//double x = (double)(i - x0) / (anchoPlano / 2); // Escalamos el valor de x al rango [-1, 1]
			  double x = (double)(i - x0) / ( 50);
		if (x < xMin || x > xMax) continue; // Ignoramos los valores de x fuera de los l�mites

		double y = evaluar(poli, x); // Evaluamos el valor del polinomio en x
		y = min(max(y, -100.0), 50.0); // Limitamos el valor de y entre -100 y 100 para evitar desbordes

		//int j = y0 - (int)(y * (altoPlano / 2)); // Convertimos y a coordenadas del canvas
		int j = y0 - (int)(y * (50));
		// Si el punto est� dentro del �rea del plano de la gr�fica
		if (j >= y0 - altoPlano / 2 && j <= y0 + altoPlano / 2)
		{
		 //----rellena la forma   ----------------
		  /*
			if (y >= 0) {
				// Si el valor de y es positivo, dibuja hacia el l�mite inferior del plano
				Canvas->MoveTo(i, j); // Comienza en el punto del polinomio
				Canvas->LineTo(i, y0 - altoPlano / 2);  // Dibuja hacia el l�mite inferior del plano
			} else {
				// Si el valor de y es negativo, dibuja hacia el l�mite superior del plano
				Canvas->MoveTo(i, j); // Comienza en el punto del polinomio
				Canvas->LineTo(i, y0 + altoPlano / 2);  // Dibuja hacia el l�mite superior del plano
			}

		   //----------------------------------
				*/


			// si solo es punto; ////////

			 Canvas->Pen->Width = 3; // grosor del punto
			Canvas->MoveTo(i, j); // Mueve el l�piz a la posici�n del punto
			Canvas->LineTo(i, j); // Dibuja un punto (l�nea de longitud cero) con el grosor del l�piz
			Canvas->Pen->Width = 1; // grosor del punto

		   //---------------------


			// usa circulos como punto////------------

			// Canvas->Ellipse(i - puntoGrosor, j - puntoGrosor, i + puntoGrosor, j + puntoGrosor);

			//-------------
		}
	}
}



//-----------------

void __fastcall TForm1::Button15Click(TObject *Sender)
{
	   Canvas->Brush->Color = clBtnFace;
	Canvas->FillRect(Canvas->ClipRect);
	int ancho = Form1->Width;
	int alto = Form1->Height;
	int anchoPlano = ancho /2.3; //2.3
	int altoPlano = alto /1.4;      //1.4
	int x0 = ancho / 2;
	int y0 = alto / 2;
	Canvas->Pen->Color = clBlack;
	Canvas->MoveTo(x0 - anchoPlano / 2, y0);
	Canvas->LineTo(x0 + anchoPlano / 2, y0);
	Canvas->Pen->Color= clRed;
	Canvas->MoveTo(x0, y0 - altoPlano / 2);
	Canvas->LineTo(x0, y0 + altoPlano / 2);
	Canvas->Pen->Color= clBlack;
double p = StrToFloat(InputBox("izq", "Por favor, introduce coeficiente", ""));
double v = StrToFloat(InputBox("dere", "Por favor, introduce el exponente", ""));
drawPolynomial(poli, clBlue, x0, y0, anchoPlano, altoPlano,p,v,Canvas);
//drawPolynomial(poli2, clRed, x0, y0, anchoPlano, altoPlano,p,v,Canvas);
// encontrarYMostrarInterseccion(poli, poli2, 500,800, Canvas);
//drawPolynomial(poli, clBlack, x0, y0, anchoPlano, altoPlano,-2,2,Canvas);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button16Click(TObject *Sender)
{
M= new  CSmemoria();
String d ="Hola";
int x =M->new_espacio(AnsiString(d).c_str());
 d ="Que,tal";
int y=M->new_espacio(AnsiString(d).c_str());
	  String i=IntToStr(x);
	String p= "->Hola";
	String v= IntToStr(100);
	M->poner_dato(StrToInt(AnsiString(i).c_str()),AnsiString(p).c_str(),StrToInt(AnsiString(v).c_str()));
  String z=IntToStr(x);
M-> Delete_espacio(StrToInt(z));

	 L= new Lista (M);
L->insertar(L->primero(),500);
 L->insertar(L->primero(),200);
 L->insertar(L->anterior( L->fin()),300);
	 Canvas->Brush->Color = clBtnFace;
	Canvas->FillRect(Canvas->ClipRect);
	M->ImprimirP_DE_A_A_B(Form1->Color,Canvas,600,20,1,20);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
String d =Edit1->Text;
M->new_espacio(AnsiString(d).c_str());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button17Click(TObject *Sender)
{
  a=new conjuntoM(M);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button20Click(TObject *Sender)
{

 String p= InputBox("conjuto", "Por favor, introduce un conjunto ","");
 String v= InputBox("valor", "Por favor, introduce un valor ", "");
if (p=="a") {
  a->inserta(StrToInt(AnsiString(v).c_str()));
}
else
 {
	if (p=="b") {
	b->inserta(StrToInt(AnsiString(v).c_str()));
	}else {
	if (p=="c") {
       c->inserta(StrToInt(AnsiString(v).c_str()));
	}

	}
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button21Click(TObject *Sender)
{
 Canvas->Brush->Color = clBtnFace;
	Canvas->FillRect(Canvas->ClipRect);
	String p= InputBox("conjunto", "Por favor, introduce un conjunto ", "");
if (p=="a") {
  a->imprimir(Form1->Color,Canvas);
}
else {
	if (p=="b") {
		 b->imprimir(Form1->Color,Canvas) ;
	} else {
	c->imprimir(Form1->Color,Canvas)  ;
	}
	}

String y=Edit3->Text;
	String z= Edit4->Text;
	M->ImprimirP_DE_A_A_B(Form1->Color,Canvas,600,20,StrToInt(y),StrToInt(z));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button18Click(TObject *Sender)
{
       b=new conjuntoM(M);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button19Click(TObject *Sender)
{
 c=new conjuntoM(M);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button22Click(TObject *Sender)
{
   int e,x;
while (a->cardinal()!=0){
x=a->cardinal();
 e=a->muestrea();
 c->inserta(e);
 a->suprime(e);
x=a->cardinal();
}
while (b->cardinal()!=0){
x=b->cardinal();
 e=b->muestrea();
 c->inserta(e);
 b->suprime(e);
  x=b->cardinal();
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button23Click(TObject *Sender)
{
 //--------------------------elimina de 1 --------------------------
  /* while (a->vacio() == false) {
		int r = a->muestrea();
		if (a->pertenece(r) && b->pertenece(r)){
			c->inserta(r);
		}

		   a->suprime(r);

	}
		  */

 //--------------------------elimina de 2 --------------------------
 /*
while (a->vacio() == false) {
		int r = a->muestrea();
		if (a->pertenece(r) && b->pertenece(r)){
			c->inserta(r);
		}
		if (a->pertenece(r)) {
		   a->suprime(r);
		}
			if (b->pertenece(r)) {
		   b->suprime(r);
		}
	}
	 /
	 */
  //--------------------de ninguno//////////////////////
	 a->interseccion(a,b,c);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button25Click(TObject *Sender)
{
poli2 =    new polinomioL(M);
}
//---------------------------------------------------------------------------

double evaluar3(polinomioM* poli, double x) {
    double resultado = 0.0;
    // Recorre todos los t�rminos del polinomio
    for (int i = 1; i <= poli->numero_terminos(); i++) {
        // Obtiene el exponente y coeficiente del t�rmino
        int exp = poli->exponente(i);
        int coef = poli->coeficiente(exp);
        // Eval�a el t�rmino: coef * x^exp
        resultado += coef * pow(x, exp);
    }
    return resultado;
}

void encontrarYMostrarInterseccion(polinomioL* poli1, polinomioL* poli2, int x0, int y0, TCanvas* Canvas) {
    double x, y1, y2;
    bool interseccionEncontrada = false;
    double paso = 0.001;  // Paso peque�o para mayor precisi�n
    double inicio = -10.0;  // Rango inicial de x
    double fin = 10.0;      // Rango final de x
    double interseccionX = 0.0, interseccionY = 0.0;

    // Primer paso: B�squeda inicial en un rango amplio
    for (x = inicio; x <= fin; x += paso) {
        y1 = evaluar(poli1, x); // Eval�a el polinomio 1 en x
        y2 = evaluar(poli2, x); // Eval�a el polinomio 2 en x

        // Comparamos los resultados de ambos polinomios. Si la diferencia es peque�a, consideramos que intersectan.
        if (fabs(y1 - y2) < 0.01) {  // Aumentamos el margen a 0.01
            interseccionEncontrada = true;
            interseccionX = x;  // Guardamos el valor de x donde encontramos la intersecci�n
            interseccionY = y1; // Asumimos que y1 es el valor de la intersecci�n, dado que y1 == y2
            break;  // Salimos del bucle al encontrar el primer punto de intersecci�n
        }
    }

    if (interseccionEncontrada) {
        // Reevaluamos el valor de Y para asegurarnos
        interseccionY = evaluar(poli1, interseccionX);

        // Formatear los valores de las coordenadas para que solo muestren dos decimales
        String coordX = FormatFloat("0.00", interseccionX);
        String coordY = FormatFloat("0.00", interseccionY);

        // Generar el string con las coordenadas de la intersecci�n
        String coords = "Intersecci�n: (" + coordX + ", " + coordY + ")";
        Canvas->TextOut(x0, y0, coords);  // Escribimos las coordenadas en el Canvas
    } else {
        // Si no se encontr� una intersecci�n, mostrar un mensaje
        //Canvas->Brush->Color = clBlack;
		Canvas->TextOut(x0, y0, "No se encontr� un punto de intersecci�n en el rango dado.");
    }
}


void __fastcall TForm1::Button26Click(TObject *Sender)
{ 
         encontrarYMostrarInterseccion(poli, poli2, 500,800, Canvas);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
 int p= StrToInt(InputBox("el fila", "Por favor, fila", ""));
int  v= StrToInt(InputBox("el columna", "Por favor, columna", ""));
 ma->dimensionar(p, v);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
  int f= StrToInt(InputBox("el fila", "Por favor, fila", ""));
int  c= StrToInt(InputBox("el columna", "Por favor, columna", ""));
 int valor= StrToInt(InputBox("el valor", "Por favor, valor", ""));

ma->poner(f, c,  valor);
}
//---------------------------------------------------------------------------

