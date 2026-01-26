//---------------------------------------------------------------------------

#pragma hdrstop

#include "UPtr_conjunto.h"
#define UPlistaH
//---------------------------------------------------------------------------
#pragma package(smart_init)
 ptr_Clista::ptr_Clista(){
	cant = 0;
	ptrConj = NULL;
 }
bool ptr_Clista::vacio() {
	return cant == 0;
}
int ptr_Clista::cardinal() {
	return cant;
}
int ptr_Clista::ordinal(int e) {
	int c = 0;
	NodoConj* aux = ptrConj;
	while (aux != NULL) {
		c++; // empieza en 1
		if (aux->dato == e) {
			return c;
		}
		aux = aux->sig;
	}
	cout << "Error elemento no encontrado\n";
	return -1; // Devuelve -1 por que no lo encuentra
}
void ptr_Clista::inserta(int e) {
	if (!pertenece(e)) {
		NodoConj* dir = new NodoConj;
		if (dir != NULL) {
			dir->dato = e;
			dir->sig = ptrConj;
			ptrConj = dir;
			cant++;
		}
		else
			cout << "ERROR NO EXISTE ESPACIO EN LA MEMORIA\n";
	}
	else
		cout << "ERROR ELEMENTO YA EXISTE\n";
}
NodoConj* ptr_Clista::anterior(NodoConj *p) {
	if (this->vacio()) {
	}
	else if (p == ptrConj) {
	}
	else {
		NodoConj* x = ptrConj;
		NodoConj* ant = NULL;
		while (x != NULL) {
			if (x == p) {
				return ant;
			}
			ant = x;
			x = x->sig;
		}
	}
}
NodoConj* ptr_Clista::localiza(int e) {
	NodoConj* x = ptrConj;
	while (x != NULL) {
		if (x->dato == e)
			return x;
		x = x->sig;
	}
	return NULL;
}
void ptr_Clista::suprime(int e) {
	NodoConj* p = localiza(e);
	if (cant == 0) {
		return;
	}
	else if (p == ptrConj) {
		NodoConj* x = ptrConj;
		ptrConj = ptrConj->sig;
		delete(x);
	}
	else {
		NodoConj* ant = anterior(p);
		ant->sig = p->sig;
		delete(p);
	}
	cant--;
}
bool ptr_Clista::pertenece(int e) {
	NodoConj* x = ptrConj;
	while (x != NULL) {
		if (x->dato == e)
			return true;
		x = x->sig;
	}
	return false;
}
int ptr_Clista::muestrea() {
	if (!vacio()) {
		srand(time(NULL));
		int pos = rand() % cardinal();
		return elemento(pos);
	}
	else
		return 0;
}
int ptr_Clista::elemento(int pos) {
	int c = 0;
	NodoConj* aux = ptrConj;
	while (aux != NULL) {
		if (c == pos)
			return aux->dato;
		c++;
		aux = aux->sig;
	}
	return 0;
}
   void ptr_Clista::Pintado(int posX, int posY, String cad, TColor color, TCanvas *Canvas){
int TamanoCelda = 35;
int TamanoCeldaX = 80;
int TamanoCeldaY = 35;
	//           x1  y1    x2                   y2
	TRect rect(posX,posY,posX+TamanoCeldaX,posY+TamanoCeldaY);
	Canvas->Brush->Color = color;
	Canvas->FillRect(rect);

	Canvas->TextOutW(posX,posY+3,cad);

}
 void ptr_Clista::imprimir(TColor FormColor, TCanvas *Canvas){
	//ptr->imprimir2( FormColor, Canvas,180,800); int TamanoCelda = 35;
  int TamanoCeldaX = 80;
	int TamanoCeldaY = 35;

	int posX = 180;
	int posY = 800;

	if (!vacio()) {
		//DIBUJAMOS CABECERA
		Pintado(posX,posY,"Lista",FormColor,Canvas);
		posY+= TamanoCeldaY;

		NodoConj* x = ptrConj;   int q;

		Pintado(posX,posY,"< ",FormColor,Canvas);
		posX+=40;
		while (x != nullptr) {




				Pintado(posX,posY,IntToStr(x->dato),FormColor,Canvas);
				posX+=80;
				if (x->sig != nullptr) {
					Pintado(posX,posY,",",FormColor,Canvas);
					posX+=40;
				}
				// Imprimimos el último elemento

				x = x->sig;

		}
		Pintado(posX,posY,">",FormColor,Canvas);
		posX+=40;
	}else{
		Pintado(posX,posY,"Lista Vacia",FormColor,Canvas);
		posY+= TamanoCeldaY;
	}
}
int ptr_Clista::primero(){
	return ptrConj->dato;

}

void ptr_Clista::mostrarEnCirculo(int centerX, int centerY, int radio, TColor color, TCanvas *Canvas) {
    // 1. DIBUJAR EL CÍRCULO PRINCIPAL (Fondo)
    Canvas->Pen->Color = clBlack; // Borde negro
    Canvas->Brush->Color = color; // Color de relleno del círculo
    // Ellipse dibuja usando las coordenadas de una caja (x1, y1, x2, y2)
    Canvas->Ellipse(centerX - radio, centerY - radio, centerX + radio, centerY + radio);

    // Obtener la cantidad de elementos
    int N = this->cardinal();

    // Configuración para el texto
    Canvas->Brush->Style = bsClear; // Fondo transparente para que no tape el color del círculo
    Canvas->Font->Color = clBlack;

    if (N == 0) {
        String msj = "Vacio";
        int w = Canvas->TextWidth(msj);
        int h = Canvas->TextHeight(msj);
        Canvas->TextOutW(centerX - (w/2), centerY - (h/2), msj);
        Canvas->Brush->Style = bsSolid; // Restaurar
        return;
    }

    // 2. CALCULAR POSICIONES DE LOS ELEMENTOS
    // Dividimos 2*PI radianes entre el número de elementos
    double anguloPaso = 2 * M_PI / N;

    // El radio donde se ubicará el texto será un poco menor al radio del círculo
    // para que los números queden por dentro del borde.
    int radioTexto = radio - 20;

    NodoConj* aux = ptrConj;
    int i = 0;

    // Recorremos la lista
    while (aux != NULL) {
        double angulo = i * anguloPaso;

        // FÓRMULA POLAR A CARTESIANA:
        // x = cx + r * cos(θ)
        // y = cy + r * sin(θ)
        int px = centerX + radioTexto * cos(angulo);
        int py = centerY + radioTexto * sin(angulo);

        // Obtenemos el texto y sus dimensiones para centrarlo exactamente en el punto
        String texto = IntToStr(aux->dato);
        int anchoTexto = Canvas->TextWidth(texto);
        int altoTexto = Canvas->TextHeight(texto);

        // 3. DIBUJAR EL NÚMERO
        Canvas->TextOutW(px - (anchoTexto / 2), py - (altoTexto / 2), texto);

        aux = aux->sig;
        i++;
    }

    // Restaurar el estilo del pincel
    Canvas->Brush->Style = bsSolid;
}
