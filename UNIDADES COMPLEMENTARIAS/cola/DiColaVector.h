//---------------------------------------------------------------------------

#ifndef DiColaVectorH
#define DiColaVectorH
//---------------------------------------------------------------------------

const int MAXD = 100;

class DiColaVector {
private:
    int datos[MAXD];
    int ini;
    int fin;

public:
    DiColaVector();

    bool vacia() const;
    bool llena() const;

	bool ponerFinal(int valor);
    bool ponerInicio(int valor);

	bool sacarInicio(int& valor);
	bool sacarFinal(int& valor);

    int primero() const;
    int ultimo() const;

    void imprimir(TColor color, TCanvas* canvas);
    String comoTexto();
};

#endif
