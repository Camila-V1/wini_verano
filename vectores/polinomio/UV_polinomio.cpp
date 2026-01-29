//---------------------------------------------------------------------------

#pragma hdrstop
  #include <iostream>

#include "UV_polinomio.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#define MAX 100

Polinomio::Polinomio(){
nt=0;
}


 // Constructor
bool Polinomio::EsCero()
{
    return nt == 0;
}
int Polinomio::Grado()
{
    if(nt > 0)
    {
		int maxGrado = VE[1];
        for(int i = 1; i <= nt; i++)
        {
            if(VE[i] > maxGrado)
                maxGrado = VE[i];
        }
        return maxGrado;
    }
    else
    {
        throw "Error: no existen términos";
    }
}
int Polinomio::BuscarExponente(int exp){
int i=1; bool b=true;  int r=-1;
while (b&&i<=nt){
 if (VE[i]==exp) {
	r=i;
    return r;
   b=false;
 }
   i++;
} return r;
}
void Polinomio::AsignarCoeficiente(int coef, int exp)
{
	int lug = -1;
    for(int i = 0; i < nt; i++)
    {
        if(VE[i] == exp)
        {
            lug = i;
            break;
        }
    }
    if(lug > -1)
    {
        VC[lug] = coef;
        if(VC[lug] == 0)
        {
            for(int i = lug; i < nt - 1; i++)
            {
                VC[i] = VC[i + 1];
                VE[i] = VE[i + 1];
            }
            nt--;
        }
    }
    else
    {
        throw "Error: no existe término con ese exponente";
    }
}
void Polinomio::poner_termino(int coef, int exp)
{
	int lug = BuscarExponente(exp);
	/*for(int i = 0; i < nt; i++)
	{
		if(VE[i] == exp)
		{
			lug = i;
			break;
		}
	}    */
    if(lug > -1)
    {
        VC[lug] += coef;
        if(VC[lug] == 0)
        {
            for(int i = lug; i < nt - 1; i++)
            {
                VC[i] = VC[i + 1];
                VE[i] = VE[i + 1];
            }
          //  nt--;
        }
    }
    else
    {
        nt++;
        VC[nt] = coef;
        VE[nt] = exp;
    }
}
int Polinomio::numero_terminos()
{
    return nt;
}
int Polinomio::coeficiente(int exp)
{
    if(exp >= 0 && exp <= Grado())
    {
		for(int i = 1; i <= nt; i++)
        {
            if(VE[i] == exp)
                return VC[i];
        }
    }
    // Error: no existe termino con ese exponente
    throw std::invalid_argument("No existe termino con ese exponente");
}
int Polinomio::exponente(int nroter)
{
    if(nroter >= 0 && nroter <= nt)
        return VE[nroter];
    else
        throw std::invalid_argument("No existe termino con ese número");
}
Polinomio Polinomio::Suma(Polinomio p1, Polinomio p2)
{
   /* Polinomio suma;
    int ex, co;
    for(int i = 0; i < p1.NumeroTerminos(); i++)
    {
        ex = p1.Exponente(i);
        co = p1.Coeficiente(ex);
        suma.PonerTermino(co, ex);
    }
    for(int i = 0; i < p2.NumeroTerminos(); i++)
    {
        ex = p2.Exponente(i);
        co = p2.Coeficiente(ex);
        suma.PonerTermino(co, ex);
    }
	return suma; */
}
Polinomio Polinomio::Resta(Polinomio p1, Polinomio p2)
{  /*
	Polinomio resta;
    int ex, co;
    for(int i = 0; i < p1.NumeroTerminos(); i++)
    {
        ex = p1.Exponente(i);
        co = p1.Coeficiente(ex);
        resta.PonerTermino(co, ex);
    }
    for(int i = 0; i < p2.NumeroTerminos(); i++)
    {
        ex = p2.Exponente(i);
        co = p2.Coeficiente(ex) * -1;
        resta.PonerTermino(co, ex);
    }
	return resta;  */
}
Polinomio Polinomio::Multiplicacion(Polinomio p1, Polinomio p2)
{
  /*  Polinomio producto;
    int ex, co;
    for(int i = 0; i < p1.NumeroTerminos(); i++)
    {
        for(int j = 0; j < p2.NumeroTerminos(); j++)
        {
            ex = p1.Exponente(i) + p2.Exponente(j);
            co = p1.Coeficiente(p1.Exponente(i)) * p2.Coeficiente(p2.Exponente(j));
            producto.PonerTermino(co, ex);
        }
    }
    return producto;*/
}
 void Polinomio::Pintado(int posX, int posY, String cad, TColor color, TCanvas *Canvas){
int TamanoCelda = 35;
int TamanoCeldaX = 80;
int TamanoCeldaY = 35;
	//           x1  y1    x2                   y2
	TRect rect(posX,posY,posX+TamanoCeldaX,posY+TamanoCeldaY);
	Canvas->Brush->Color = color;
	Canvas->FillRect(rect);

	Canvas->TextOutW(posX,posY+3,cad);

}
void Polinomio::imprimir( TColor FormColor,TCanvas* Canvas)
{    int posX=1150;
int posY=30;
    int TamanoCeldaX = 80;
    int TamanoCeldaY = 35;
    int auxX = posX;
    int auxY = posY;

    if (!EsCero()) {
        // DIBUJAMOS CABECERA
        Pintado(posX, posY, "Polinomio", FormColor, Canvas);
        posX = auxX;
        posY += TamanoCeldaY;

        Pintado(posX, posY, "< ", FormColor, Canvas);
        posX += 40;
        for (int i = 1; i <= nt; i++) {
			Pintado(posX, posY, IntToStr(VC[i]) + "x^" + IntToStr(VE[i]), FormColor, Canvas);
			posX += 80;
            if (i < nt - 1) {
                Pintado(posX, posY, ",", FormColor, Canvas);
                posX += 40;
            }
        }
        Pintado(posX, posY, " >", FormColor, Canvas);
        posX += 40;
    } else {
        Pintado(posX, posY, "Polinomio Vacío", FormColor, Canvas);
        posX = auxX;
        posY += TamanoCeldaY;
    }
}
