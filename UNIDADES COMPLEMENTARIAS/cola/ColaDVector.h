//---------------------------------------------------------------------------

#ifndef ColaDVectorH
#define ColaDVectorH
//---------------------------------------------------------------------------

const int MAXDD = 100;
class ColaDVector {
private:
    int datos[MAXDD];
    int ini;
    int fin;
    int cantidad;
public:
    ColaDVector();
    bool vacia() const;
    bool llena() const;
	bool meterFinal(int valor);
	bool meterInicio(int valor);
    bool sacarInicio(int& valor);
    bool sacarFinal(int& valor);
    void imprimir(TColor color, TCanvas* canvas);
    String comoTexto();
};
#endif
