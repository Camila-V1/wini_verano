//---------------------------------------------------------------------------
#pragma hdrstop
#include "UCSLista.h"
#include "Umemoria.h"
#include <cmath>
//---------------------------------------------------------------------------
#pragma package(smart_init)
//-------------------------------------------------
Lista::Lista(){
 PtrElementos=NULO;
 longitud=0;
 Cmemoria = new CSmemoria();
}
//-------------------------------------------------
Lista::Lista(CSmemoria* m){
  PtrElementos=NULO;
 longitud=0;
 Cmemoria = m;
}
//-------------------------------------------------
direccion Lista::fin(){
 if (vacia()) {
	 cout<<"lista vacia";
 }
 else
 {
	 int x = PtrElementos;
	 int ptrfin;
	 while (x!=NULO)
		 {
			 ptrfin = x;
			 x=Cmemoria->obtenerDato(x,sigNL);//x=x->sig;
		 }
	 return ptrfin;
 }
}
//-------------------------------------------------
direccion Lista::primero(){
if (!vacia()) {
	return PtrElementos;
}else return NULO;
{cout<<"ERROR/Primero():ListaVacia\n";}
}
//-------------------------------------------------
direccion Lista::siguiente(direccion d){
if (vacia()==true) {
	cout<<"lista vacia en siguiente();";
  return NULO;
}
else{
	if (d == fin()) {
	cout<<"no hay mas dato en siguiente();";return NULO;
	}
	else
	{
	return Cmemoria->obtenerDato(d,sigNL);
	}//direccion->sig;
}
}
//-------------------------------------------------
direccion Lista::anterior(direccion d){
if (vacia()) {
	cout<<"no hay mas dato en anterior();";  return NULO;
}
else
{
	if (d == primero()) {
	  return NULO;	cout<<"se declaro que la direccion es igual a la primera direccion de la lista en anterior();";
	}
	else
	{
		direccion x = PtrElementos;//Nodolista* x=ptrelemento;
		direccion ant=NULO;//Nodolista* ant=NULL;
		while (x!=NULO)
			{
			   if (x==d) {
				   return ant;
			   }
			   else
			   {
				ant = x;
				x = Cmemoria->obtenerDato(x,sigNL);//Obtener_dato();x->sig;
			   }
            }
	}
}
}
//-------------------------------------------------
bool Lista::vacia(){
return longitud==0;
}
//-------------------------------------------------
int Lista::recupera(direccion d){
if (!vacia()){
return Cmemoria->obtenerDato(d,elementNL);    //->elemento
}else
{
return NULO;}
}
//-------------------------------------------------
int Lista::getlongitud(){return longitud;}
//-------------------------------------------------
void Lista::insertar(direccion d, int elemento) {
    // 1. Pedir espacio nuevo en memoria
    int x = Cmemoria->new_espacio(datoNL);
    if (x == NULO) {
        cout << "ERROR: No existe espacio en la memoria.";
        return; // Salir si no hay memoria
    }

    // 2. Colocar el dato en el nuevo nodo
    Cmemoria->poner_dato(x, elementNL, elemento);
    Cmemoria->poner_dato(x, sigNL, NULO); // El 'siguiente' por defecto es NULO

    // 3. Manejar el caso de que la lista esté vacía
    if (vacia()) {
        PtrElementos = x;
        longitud = 1;
        return; // El nodo es el primero y único
    }

    // ---- INICIO DE LA MODIFICACIÓN ----

    // 4. CASO ESPECIAL: Si la dirección 'd' es la del último elemento (fin)
    // Se inserta el nuevo nodo DESPUÉS del último
    if (d == fin()) {
        Cmemoria->poner_dato(d, sigNL, x); // El 'siguiente' del actual último apunta al nuevo
        longitud++;
    }
    // ---- FIN DE LA MODIFICACIÓN ----

    // 5. CASO ORIGINAL: Si la dirección 'd' es cualquier otra, se inserta ANTES
    else {
        if (d == primero()) {
            Cmemoria->poner_dato(x, sigNL, d); // El 'siguiente' del nuevo apunta al antiguo primero
            PtrElementos = x; // El puntero principal apunta ahora al nuevo nodo
        } else {
            direccion ant = anterior(d);
            Cmemoria->poner_dato(ant, sigNL, x); // El 'siguiente' del anterior a 'd' apunta al nuevo
            Cmemoria->poner_dato(x, sigNL, d);   // El 'siguiente' del nuevo apunta a 'd'
        }
        longitud++;
    }
}//-------------------------------------------------
void Lista::inserta_primero(int elemento){
int x = Cmemoria->new_espacio(datoNL);
if (x!=NULO) {
 Cmemoria->poner_dato(x,elementNL,elemento);
 Cmemoria->poner_dato(x,sigNL,PtrElementos);
 PtrElementos=x;
 longitud++;
}
else
{
	cout<<"ERROR NO EXISTE MAS ESPACIO EN LA MEMORIA";
}
}
//-------------------------------------------------
void Lista::inserta_ultimo(int elemento){
  int x= Cmemoria->new_espacio(datoNL);
if (x!=NULO) {
	Cmemoria->poner_dato(x,elementNL,elemento);
	Cmemoria->poner_dato(x,sigNL,NULO);
	if (longitud!=0) {
	   Cmemoria->poner_dato(fin(),sigNL,x);	//fin()->sig=x;
	}
	else
	{
		PtrElementos=x;
	}
	longitud++;
}else
{
	cout<<"no existe espacio en la memoria";
}
}

//-------------------------------------------------
void Lista::suprime(direccion d){
if (longitud==0) {
	cout<<"lista vacia en suprime();";
}
else
{
	if (d==PtrElementos) {
		direccion x = PtrElementos;
		PtrElementos=Cmemoria->obtenerDato(PtrElementos,sigNL);
		Cmemoria->Delete_espacio(x);
	}
	else
	{
		direccion ant = anterior(d);
		Cmemoria->poner_dato(ant,sigNL,siguiente(d));
		Cmemoria->Delete_espacio(d);
	}
   longitud--;
}
}
//-------------------------------------------------
void Lista::modifica(direccion d, int elemento){
if (!vacia()) {
	Cmemoria->poner_dato(d,elementNL,elemento);//d->elemento=ele;
}
else
{
	cout<<"lista vacia en modifica();";
}
}
direccion Lista::localiza(int tipoElemento) {
	direccion actual = PtrElementos;
	if (!vacia()) {
	while (actual != NULO) {
		if (Cmemoria->obtenerDato(actual, elementNL) == tipoElemento)
			return actual;
		actual = siguiente(actual);

	} if (actual==NULO) {
		return NULO;
	  }
	}else{
	return NULO;
	}
}
void Lista::elimLista(){
if (!vacia()) {
   while (PtrElementos!=NULO){
   suprime(fin());
}
} else{
  cout<<"no Hay nada;";
}
}
int Lista::sumaIntercalada() {
    int suma = 0;
    direccion actual = PtrElementos;
    bool sumar = true;
    while (actual != NULO) {
        int elemento = Cmemoria->obtenerDato(actual, elementNL);
        if (sumar) {
            suma += elemento;
        }
        sumar = !sumar;
        actual = siguiente(actual);
    }
    return suma;
}

//-------------------------------------------------
void Pintado(int posX, int posY, String cad, TColor color, TCanvas *Canvas){
	//           x1  y1    x2                   y2
	TRect rect(posX,posY,posX+TamanoCeldaX,posY+TamanoCeldaY);
	Canvas->Brush->Color = color;
	Canvas->FillRect(rect);
	Canvas->TextOutW(posX,posY+3,cad);
}
void Lista::imprimir2(TColor FormColor, TCanvas *Canvas,int posX,int posY )   {
	 // Cmemoria->ImprimirPantalla(FormColor,Canvas) ;
			int auxX = posX;
			int auxY = posY;    	Canvas->Font->Size =10;
	if (vacia()==false) {
			//DIBUJAMOS CABECERA
			Pintado(posX,posY,"Lista",FormColor,Canvas);
			posX= auxX;
			posY+= TamanoCeldaY;
			direccion x = PtrElementos;
			Pintado(posX,posY,"< ",FormColor,Canvas);
			posX+=40;
			while (x != NULO){
			Pintado(posX,posY,IntToStr(Cmemoria->obtenerDato(x,elementNL)),FormColor,Canvas);
			posX+=80;
				if (x != NULO) {
				Pintado(posX,posY,", ",FormColor,Canvas);
				posX+=40;
				}
            x = Cmemoria->obtenerDato(x,sigNL);
			}
			Pintado(posX,posY,">",FormColor,Canvas);
			posX+=40;
	}else{
    Pintado(posX,posY,"Lista Vacia",FormColor,Canvas);
			posX= auxX;
			posY+= TamanoCeldaY;
	}
}
void Lista::imprimir(TColor FormColor, TCanvas *Canvas){
			int	posX = 600;
			int	posY = 500;
			int auxX = posX;
			int auxY = posY;    	Canvas->Font->Size =10;
	if (vacia()==false) {
			//DIBUJAMOS CABECERA
			Pintado(posX,posY-10,"Lista",FormColor,Canvas);
			posX= auxX;
			posY+= TamanoCeldaY;
			direccion x = PtrElementos;
			Pintado(posX,posY,"< ",FormColor,Canvas);
			posX+=40;
			while (x != NULO){
			Pintado(posX,posY,IntToStr(Cmemoria->obtenerDato(x,elementNL)),FormColor,Canvas);
			posX+=80;
				if (x != NULO) {
				Pintado(posX,posY,", ",FormColor,Canvas);
				posX+=40;
				}
            x = Cmemoria->obtenerDato(x,sigNL);
			}
			Pintado(posX,posY,">",FormColor,Canvas);
			posX+=40;
	}else{
    Pintado(posX,posY,"Lista Vacia",FormColor,Canvas);
			posX= auxX;
			posY+= TamanoCeldaY;
	}
}
int Lista::getPtr(){
return PtrElementos;
}
void Lista::Pintado2(int posX, int posY, String cad, TColor color, TCanvas *Canvas){
	//           x1  y1    x2                   y2
	TRect rect(posX,posY,posX+TamanoCeldaX,posY+TamanoCeldaY);
	Canvas->Brush->Color = color;
	Canvas->FillRect(rect);
	Canvas->TextOutW(posX,posY+3,cad);
}
void Lista::ordenar() {
  // Si la lista está vacía o solo tiene un elemento, ya está ordenada.
  if (vacia() || longitud <= 1) {
    return;
  }

  // 'ptrOrdenado' será el puntero a la nueva lista que construiremos ya ordenada.
  direccion ptrOrdenado = NULO;
  // 'actual' recorrerá cada nodo de la lista original (desordenada).
  direccion actual = PtrElementos;

  while (actual != NULO) {
    // 1. Tomamos el siguiente nodo de la lista original para ordenarlo.
    direccion nodoAInsertar = actual;
    actual = siguiente(actual); // Avanzamos el puntero de la lista original.

    // 2. Buscamos dónde insertar 'nodoAInsertar' en nuestra nueva lista ordenada.

    // CASO A: La lista ordenada está vacía o el nodo a insertar es menor que su cabeza.
    if (ptrOrdenado == NULO || recupera(nodoAInsertar) < recupera(ptrOrdenado)) {
      // El nuevo nodo apunta a la antigua cabeza de la lista ordenada.
      Cmemoria->poner_dato(nodoAInsertar, sigNL, ptrOrdenado);
      // La cabeza de la lista ordenada ahora es el nuevo nodo.
      ptrOrdenado = nodoAInsertar;
    }
    // CASO B: El nodo debe insertarse en medio o al final de la lista ordenada.
    else {
      // 'temp' busca en la lista ordenada la posición correcta.
      direccion temp = ptrOrdenado;
      // Avanzamos 'temp' mientras el 'siguiente' no sea nulo y su valor sea
      // menor que el valor del nodo que queremos insertar.
      while (siguiente(temp) != NULO && recupera(siguiente(temp)) < recupera(nodoAInsertar)) {
        temp = siguiente(temp);
      }

      // Insertamos el 'nodoAInsertar' entre 'temp' y el 'siguiente de temp'.
      Cmemoria->poner_dato(nodoAInsertar, sigNL, siguiente(temp));
      Cmemoria->poner_dato(temp, sigNL, nodoAInsertar);
    }
  }

  // 3. Finalmente, actualizamos el puntero principal de la lista para que apunte
  // a la nueva lista completamente ordenada.
  PtrElementos = ptrOrdenado;
}

void Lista::ordenarPorUltimoDigito() {
  // Si la lista está vacía o solo tiene un elemento, ya está ordenada.
  if (vacia() || longitud <= 1) {
    return;
  }

  direccion ptrOrdenado = NULO;
  direccion actual = PtrElementos;

  while (actual != NULO) {
    direccion nodoAInsertar = actual;
    actual = siguiente(actual);

    // Obtenemos el último dígito del nodo que vamos a insertar.
    int ultimoDigitoAInsertar = recupera(nodoAInsertar) % 10;

    // CASO A: La lista ordenada está vacía o el nuevo nodo debe ir al principio.
    if (ptrOrdenado == NULO || ultimoDigitoAInsertar < (recupera(ptrOrdenado) % 10)) {
      Cmemoria->poner_dato(nodoAInsertar, sigNL, ptrOrdenado);
      ptrOrdenado = nodoAInsertar;
    }
    // CASO B: El nodo debe insertarse en medio o al final de la lista ordenada.
    else {
      direccion temp = ptrOrdenado;
      // Buscamos la posición correcta comparando solo el último dígito.
      while (siguiente(temp) != NULO && (recupera(siguiente(temp)) % 10) < ultimoDigitoAInsertar) {
        temp = siguiente(temp);
      }

      Cmemoria->poner_dato(nodoAInsertar, sigNL, siguiente(temp));
      Cmemoria->poner_dato(temp, sigNL, nodoAInsertar);
    }
  }

  // Actualizamos el puntero principal para que apunte a la nueva lista ordenada.
  PtrElementos = ptrOrdenado;
}


void Lista::ordenarPorUltimoDigito2() {
  // Si la lista está vacía o solo tiene un elemento, ya está ordenada.
  if (vacia() || longitud <= 1) {
	return;
  }

  direccion ptrOrdenado = NULO;
  direccion actual = PtrElementos;

  while (actual != NULO) {
	direccion nodoAInsertar = actual;
	actual = siguiente(actual);

	// **CAMBIO AQUÍ:** Usamos abs() para obtener el último dígito positivo.
	int ultimoDigitoAInsertar = abs(recupera(nodoAInsertar)) % 10;

	// **CAMBIO AQUÍ:** Comparamos usando el valor absoluto.
    if (ptrOrdenado == NULO || ultimoDigitoAInsertar < (abs(recupera(ptrOrdenado)) % 10)) {
      Cmemoria->poner_dato(nodoAInsertar, sigNL, ptrOrdenado);
      ptrOrdenado = nodoAInsertar;
    }
    else {
      direccion temp = ptrOrdenado;
      // **CAMBIO AQUÍ:** Comparamos usando el valor absoluto dentro del bucle.
      while (siguiente(temp) != NULO && (abs(recupera(siguiente(temp))) % 10) < ultimoDigitoAInsertar) {
        temp = siguiente(temp);
	  }

      Cmemoria->poner_dato(nodoAInsertar, sigNL, siguiente(temp));
      Cmemoria->poner_dato(temp, sigNL, nodoAInsertar);
    }
  }

  PtrElementos = ptrOrdenado;
}

void Lista::ordenarPorUltimoDigito3() {
  if (vacia() || longitud <= 1) {
    return;
  }

  direccion ptrOrdenado = NULO;
  direccion actual = PtrElementos;

  while (actual != NULO) {
    direccion nodoAInsertar = actual;
    actual = siguiente(actual);

    // **LÓGICA CLAVE:** Extraer el último dígito de la parte entera.
    float valorCompleto = recupera(nodoAInsertar);
    int parteEntera = (int)valorCompleto; // Convierte 12.4 a 12, o -12.4 a -12
    int ultimoDigitoAInsertar = abs(parteEntera) % 10;

    // Comparar usando la nueva lógica.
    float cabezaOrdenadaValor = recupera(ptrOrdenado);
    int cabezaOrdenadaEntero = (int)cabezaOrdenadaValor;
    if (ptrOrdenado == NULO || ultimoDigitoAInsertar < (abs(cabezaOrdenadaEntero) % 10)) {
      Cmemoria->poner_dato(nodoAInsertar, sigNL, ptrOrdenado);
      ptrOrdenado = nodoAInsertar;
    }
    else {
      direccion temp = ptrOrdenado;

      while (siguiente(temp) != NULO) {
          float siguienteValor = recupera(siguiente(temp));
          int siguienteEntero = (int)siguienteValor;
          if ((abs(siguienteEntero) % 10) >= ultimoDigitoAInsertar) {
              break; // Encontramos la posición, salir del bucle
          }
          temp = siguiente(temp);
      }

      Cmemoria->poner_dato(nodoAInsertar, sigNL, siguiente(temp));
      Cmemoria->poner_dato(temp, sigNL, nodoAInsertar);
    }
  }

  PtrElementos = ptrOrdenado;
}
