//---------------------------------------------------------------------------

#ifndef UV_polinomioH
#define UV_polinomioH
//---------------------------------------------------------------------------
#define MAX 100

class Polinomio
{
private:
	int VC[MAX]; // Coeficientes
	int VE[MAX]; // Exponentes

public:
	int nt;      // Número de términos
	Polinomio();  // Constructor
	bool EsCero();
	int Grado();
	int BuscarExponente(int exp);
	void AsignarCoeficiente(int coef, int exp);
	void poner_termino(int coef, int exp);
	int numero_terminos();
	int coeficiente(int exp);
	int exponente(int nroter);
    void imprimir( TColor FormColor,TCanvas* Canvas)  ;
    void Pintado(int posX, int posY, String cad, TColor color, TCanvas *Canvas);
	Polinomio Suma(Polinomio p1, Polinomio p2);
	Polinomio Resta(Polinomio p1, Polinomio p2);
	Polinomio Multiplicacion(Polinomio p1, Polinomio p2);
};
#endif // POLINOMIO_H
