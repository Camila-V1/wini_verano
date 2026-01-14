//---------------------------------------------------------------------------

#pragma hdrstop

#include "UM_conjunto.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
conjuntoM::conjuntoM(){

  pe=NULO;
 longitud=0;
 Cm = new CSmemoria();
}
	conjuntoM::conjuntoM(CSmemoria* m){
	  pe=NULO;
 longitud=0;
 Cm= m;
	}
		bool conjuntoM::vacio(){
        return (longitud==0);
		}
 bool conjuntoM::pertenece(int e){
 bool r=false;
 int pc=pe;
 while (pc!=-1)   {
 if (Cm->obtenerDato(pc,"->dato")==e) {
   r=true;
 pc=-1;
 }else
   pc=Cm->obtenerDato(pc,"->sig");
 }


 return r;

 }

 void  conjuntoM::inserta(int e){
 if (pertenece(e)==false) {
	 int  di=Cm->new_espacio("dato,sig");
	 if (di!=-1) {
		 Cm->poner_dato(di,"->dato",e);
	   Cm->poner_dato(di,"->sig",pe);
	   pe=di;
	   longitud+=1;
	 }

 }
 }
 int conjuntoM::ordinal(int e){
  int r=0;
  int pc=pe;
  while (pc!=-1){
	 r+=1;
	 if (Cm->obtenerDato(pc,"->dato")==e) {
		 return r;
		 pc=-1;
	 }else pc=Cm->obtenerDato(pc,"->sig")   ;
	  }
 }
  int conjuntoM::cardinal(){
  return longitud;
  }
   int conjuntoM::suprime(int e){
  int  di=-1;
   int pc=pe;
   while (pc!=-1){
	if (Cm->obtenerDato(pc,"->dato")==e) {
		di=pc;
		pc=-1;

	} else {
		pc=Cm->obtenerDato(pc,"->sig");
	}


   }
	longitud--;	Cm->Delete_espacio(di);
  }

	void conjuntoM::eliminaSiPertenece(int e) {
	if (pertenece(e)) {
		suprime(e);
	}
}
	int conjuntoM::generarNumeroAleatorio() {
	srand(time(0)); // Inicializa el generador de números aleatorios
	int min = 1; // Límite inferior del rango
	int max = longitud; // Límite superior del rango
	int num = rand() % (max - min + 1) + min;
	return num;
}

int conjuntoM::muestrea(){
   if (longitud>0){
   int lug=generarNumeroAleatorio();
   int e;
	srand(time(0)) ;
	int l=0;
	 int pc=pe;
	 while (pc!=-1) {
		l+=1;
		if (lug==l) {
		  e=Cm->obtenerDato(pc,"->dato")    ;
		  pc=-1;
		}  else {
			pc=Cm->obtenerDato(pc,"->sig");
		}
	 }
	 return e;
   }
   }

	 void conjuntoM::imprimir(TColor FormColor, TCanvas *Canvas){
	/*

	 //  Cm->ImprimirPantalla2( FormColor, Canvas, 280,700)  ;
	   //Cm->ImprimirDireccionVertical(pe,FormColor,Canvas, 450,700) ;

//Define las nuevas coordenadas del centro
	int centroX = 400; // Más a la derecha
	int centroY = 800; // Más abajo

	// Dibuja un círculo en la nueva posición con un radio de 100
	Canvas->Pen->Color = clBlack;
	Canvas->Brush->Color = FormColor;
	Canvas->Ellipse(centroX-100, centroY-100, centroX+100, centroY+100);

	// Calcula el ángulo entre cada elemento
	int angulo = 360 / longitud;

    int pc = pe;
	for (int i = 0; i < longitud; i++) {
		// Obtiene el elemento del conjunto
		int e = Cm->obtenerDato(pc, "->dato");
		  if (e<999) {


		// Calcula la nueva posición del elemento
		int x = centroX + 70* cos(angulo * i * M_PI / 180.0);
		int y = centroY + 70* sin(angulo * i * M_PI / 180.0);

		// Convierte el elemento a string
        String elemento = IntToStr(e);

        // Dibuja el elemento en la nueva posición calculada
		Canvas->TextOutW(x, y, elemento);

		// Avanza al siguiente elemento en el conjunto
		pc = Cm->obtenerDato(pc, "->sig");
		  }
	}



	*/
		   int posX=400;
		   int posY=400;

     // Guardar los colores originales del lápiz y la brocha
    TColor oldPenColor = Canvas->Pen->Color;
    TColor oldBrushColor = Canvas->Brush->Color;
    // Configurar los nuevos colores
    Canvas->Pen->Color = clBlack; // Lápiz de color negro
    Canvas->Brush->Color = FormColor; // Color de fondo de las celdas
    // Variable auxiliar para la posición horizontal de cada elemento
	int auxX = posX;
    // Recorremos el conjunto y dibujamos cada elemento
    int pc = pe;
    bool primerElemento = true; // Para controlar la coma entre elementos
    while (pc != NULO) {
        // Obtener el dato actual
        int e = Cm->obtenerDato(pc, "->dato");
        // Convertir el dato a cadena para poder dibujarlo
        String elemento = IntToStr(e);
        // Si no es el primer elemento, agregar una coma antes
        if (!primerElemento) {
            Canvas->TextOutW(auxX, posY, ",");
            auxX += Canvas->TextWidth(","); // Mover la posición horizontal después de la coma
        }
        // Dibujar el número en la posición (auxX, posY)
        Canvas->TextOutW(auxX, posY, elemento);
        // Actualizar la posición horizontal para el siguiente elemento
        auxX += 10; // Ajusta la posición horizontal con base en el ancho del texto
        // Avanzar al siguiente nodo
        pc = Cm->obtenerDato(pc, "->sig");
        primerElemento = false; // Después del primer elemento, las comas serán necesarias
    }
    // Restaurar los colores originales
    Canvas->Pen->Color = oldPenColor;
    Canvas->Brush->Color = oldBrushColor;
	 }
	 void conjuntoM::eliminarPorDireccion(int dir) {
	int pc = pe;
	int prev = NULO;
	while (pc != NULO) {
		if (pc == dir) {
            // Encontramos el nodo a eliminar
            if (prev == NULO) {
                // El nodo a eliminar es el primero en la lista
                pe = Cm->obtenerDato(pc, "->sig");
            } else {
                // El nodo a eliminar está en medio o al final de la lista
                Cm->poner_dato(prev, "->sig", Cm->obtenerDato(pc, "->sig"));
            }
            Cm->Delete_espacio(pc);
            longitud--;
            return;
        }
        prev = pc;
        pc = Cm->obtenerDato(pc, "->sig");
	}
}

conjuntoM* conjuntoM::copia() {
	conjuntoM* copia = new conjuntoM();
	int p = this->pe;
	while (p != NULO) {
		int e = this->Cm->obtenerDato(p, "->dato");
		copia->inserta(e);
		p = this->Cm->obtenerDato(p, "->sig");
	}
	return copia;
}
void conjuntoM::interseccion(conjuntoM* a, conjuntoM * b, conjuntoM * & c) {
	// Clear the set c
	while (!c->vacio()) {
		c->suprime(c->muestrea());
	}
	// Traverse set a
	int pc = a->pe;
	while (pc != NULO) {
		// If an element of a is also in b, insert it into c
		if (!b->pertenece(a->Cm->obtenerDato(pc, "->dato"))) {
			c->inserta(Cm->obtenerDato(pc, "->dato"));
		}
		pc = Cm->obtenerDato(pc, "->sig");
	}
}
