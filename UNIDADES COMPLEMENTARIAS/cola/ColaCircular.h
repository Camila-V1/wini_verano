#ifndef ColaCircularH
#define ColaCircularH

const int MAX = 100;

class colaCircular {
private:
    int V[MAX];
    int ini;
    int fin;

public:
    colaCircular();

    bool vacia();
    bool llena();

    void Meter(int e);
    void Sacar(int &e);
    int primero();
    int ultimo();

    void imprimir(TColor FormColor, TCanvas *Canvas);
};

#endif

