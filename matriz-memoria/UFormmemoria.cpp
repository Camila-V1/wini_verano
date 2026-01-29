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
	M->	MostrarMemoriaDesplazada2   (Form1->Color,Canvas,800,20,StrToInt(d),StrToInt(p));
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
ma = new MatrizDispersa2 (M);
  pilaD = new  pilaMM(M);
   pilaC = new  pilaMM(M);
	pilaF= new  pilaMM(M);
    	pila= new  pilaM(M);
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
ma->imprimir(Form1->Color,Canvas);
}
//---------------------------------------------------------------------------



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
	// Recorre todos los términos del polinomio
	for (int i = 1; i <= poli->numero_terminos(); i++) {
		// Obtiene el coeficiente y el exponente del término
		int exp = poli->exponente(i);
		int coef = poli->coeficiente(exp);
	p1->poner_termino(coef,exp);

	}


 }

  double evaluar2(polinomioL* poli, double x) {
	double resultado = 0.0;
	double valorTermino;
	// Recorre todos los términos del polinomio
	for (int i = 1; i <= poli->numero_terminos(); i++) {
		// Obtiene el coeficiente y el exponente del término
		int exp = poli->exponente(i);
		int coef = poli->coeficiente(exp);
		// Calcula el valor del término para el valor dado de x
		valorTermino = coef * pow(x, exp);
		// Suma el valor del término al resultado
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
		if (x < xMin || x > xMax) continue; // Ignora los valores de x fuera de los límites
		double y = evaluar2(poli, x);
		y = min(max(y, -100.0), 100.0); // Limitamos el valor de y entre -1 y 1
		int j = y0 - (int)(y * (altoPlano / 2));
		if (j >= y0 - altoPlano / 2 && j <= y0 + altoPlano / 2)
		{
			int j_line;
			if (p >= 0) // Si el coeficiente principal es positivo
			{
				Canvas->MoveTo(i, j);
				j_line = min(j, y0 - altoPlano / 2); // Limita la línea a los límites de la gráfica
				Canvas->LineTo(i, j_line); // Dibujamos una línea desde el eje x hasta el punto del polinomio
			}
			else // Si el coeficiente principal es negativo
			{      //	Canvas->LineTo(i, j);
				Canvas->MoveTo(i, j);
				j_line = max(j, y0 + altoPlano / 2); // Limita la línea a los límites de la gráfica
			Canvas->LineTo(i, j_line); // Dibujamos una línea desde el punto del polinomio hasta el límite inferior
			}
		}
	}
}


double evaluar(polinomioL* poli, double x) {
	double resultado = 0.0;
	// Recorre todos los términos del polinomio
	for (int i = 1; i <= poli->numero_terminos(); i++) {
		// Obtiene el exponente y coeficiente del término
		int exp = poli->exponente(i);
		int coef = poli->coeficiente(exp);
		// Manejar el caso de x == 0 y exponente negativo para evitar división por cero
		if (x == 0 && exp < 0) {
			// Si el exponente es negativo y x es 0, podemos decidir no sumar nada a resultado
			// Alternativamente, podrías asignar algún valor específico según el comportamiento que desees.
			continue; // O puedes retornar un valor predefinido
		}
		// Suma el valor del término (coef * x^exp) al resultado
		resultado += coef * pow(x, exp);
	}
	return resultado;

}
void drawPolynomial(polinomioL* poli, TColor color, int x0, int y0, int anchoPlano, int altoPlano, double xMin, double xMax, TCanvas* Canvas)
{
	Canvas->Pen->Color = color;
	 int puntoGrosor = 2; // Define el tamaño de los circulos
	// Recorre el plano para dibujar el área entre la curva y los límites del plano
	for (int i = x0 - anchoPlano / 2; i <= x0 + anchoPlano / 2; i++)
	{
		//double x = (double)(i - x0) / (anchoPlano / 2); // Escalamos el valor de x al rango [-1, 1]
			  double x = (double)(i - x0) / ( 50);
		if (x < xMin || x > xMax) continue; // Ignoramos los valores de x fuera de los límites

		double y = evaluar(poli, x); // Evaluamos el valor del polinomio en x
		y = min(max(y, -100.0), 50.0); // Limitamos el valor de y entre -100 y 100 para evitar desbordes

		//int j = y0 - (int)(y * (altoPlano / 2)); // Convertimos y a coordenadas del canvas
		int j = y0 - (int)(y * (50));
		// Si el punto está dentro del área del plano de la gráfica
		if (j >= y0 - altoPlano / 2 && j <= y0 + altoPlano / 2)
		{
		 //----rellena la forma   ----------------
		  /*
			if (y >= 0) {
				// Si el valor de y es positivo, dibuja hacia el límite inferior del plano
				Canvas->MoveTo(i, j); // Comienza en el punto del polinomio
				Canvas->LineTo(i, y0 - altoPlano / 2);  // Dibuja hacia el límite inferior del plano
			} else {
				// Si el valor de y es negativo, dibuja hacia el límite superior del plano
				Canvas->MoveTo(i, j); // Comienza en el punto del polinomio
				Canvas->LineTo(i, y0 + altoPlano / 2);  // Dibuja hacia el límite superior del plano
			}

		   //----------------------------------
				*/


			// si solo es punto; ////////

			 Canvas->Pen->Width = 3; // grosor del punto
			Canvas->MoveTo(i, j); // Mueve el lápiz a la posición del punto
			Canvas->LineTo(i, j); // Dibuja un punto (línea de longitud cero) con el grosor del lápiz
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
{  String x=InputBox("InfijaToPostfija", "introdizca exprecion", "");
  pila2->Meter(StrToInt(x));
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




 void intercambiarExtremos2(pilav &K,TColor FormColor, TCanvas *Canvas) {
	if (!K.Vacia() && K.longitud > 1) {
		int valorPrimero, valorUltimo;

		// Sacar todos los elementos de la pila temporalmente
		pilav tempPila;
		while (!K.Vacia()) {
			int valor;
			K.Sacar(valor);
			tempPila.Meter(valor);
		}

		// Guardar los valores extremos
		tempPila.Sacar(valorUltimo); // Obtener el último valor (extremo inferior original)
		int contador = 1;
		while (contador < K.longitud - 1) {
			int valor;
			tempPila.Sacar(valor);
			K.Meter(valor);
			contador++;
		}
		tempPila.Sacar(valorPrimero); // Obtener el primer valor (extremo superior original)

		// Insertar los valores extremos en orden invertido
		K.Meter(valorUltimo); // Insertar el valor que estaba al final en la parte superior
		while (!tempPila.Vacia()) {
			int valor;
			tempPila.Sacar(valor);
			K.Meter(valor);
		}
		K.Meter(valorPrimero);
		// Insertar el valor que estaba al principio en la parte inferior
	}
	ShowMessage("");
	   K.imprimir(FormColor, Canvas);
}
 void intercambiarExtremos(pilav* &K) {
  if (true) {
      int valorPrimero, valorUltimo;
		ptrlista auxLista;
        // Extraer el primer elemento de la pila
		K->Sacar(valorPrimero);
        // Transferir el resto de los elementos a la lista auxiliar
		while (!K->Vacia()) {
            int valor;
			K->Sacar(valor);
			auxLista.inserta_primero(valor);
		}
		// Extraer el último elemento de la lista auxiliar (equivalente al último de la pila original)
		valorUltimo = auxLista.recupera(auxLista.primero());
		auxLista.suprime(auxLista.primero());
		// Insertar el último elemento en la base de la pila y reconstruir el resto de los elementos
		K->Meter(valorPrimero);
		Nodolista* nodo = auxLista.primero();
		while (nodo != nullptr) {
			K->Meter(auxLista.recupera(nodo));
			nodo = auxLista.siguiente(nodo);
		}
		// Insertar el primer valor en la cima de la pila
		K->Meter(valorUltimo);

	}
}

void intercambiarLugares2 (pilav* &K, int Lug1, int Lug2) {
    if (K != nullptr && !K->Vacia() && Lug1 != Lug2) {
        std::vector<int> elementos;
        int valor;
        // Transferir todos los elementos de la pila a un vector para mantener el orden
        while (!K->Vacia()) {
            K->Sacar(valor);
            elementos.push_back(valor);
        }
        // Ahora, los elementos están en el orden en que se extrajeron (invertido con respecto al orden original)
        // Invertimos el vector para recuperar el orden original de la pila
        std::reverse(elementos.begin(), elementos.end());
        // Intercambiar los elementos en Lug1 y Lug2 (índices ajustados para comenzar desde 1)
		if (Lug1 > 0 && Lug1 <= elementos.size() && Lug2 > 0 && Lug2 <= elementos.size()) {
			std::swap(elementos[Lug1 - 1], elementos[Lug2 - 1]);
		}
		// Reconstruir la pila en el orden original, con los lugares intercambiados
		for (int i = 0; i < elementos.size(); i++) {
			K->Meter(elementos[i]);
		}
	}
}    /*
void intercambiarLugares(pilav* &K, int Lug1, int Lug2) {
	if (K != nullptr && !K->Vacia() && Lug1 != Lug2) {
		pilav auxPila;
			pilav auxPila2;// Pila auxiliar para invertir el orden
		int valor1 = 0, valor2 = 0;
		int totalElementos = 0;
        int valor;

        // Transferir todos los elementos de la pila original a la pila auxiliar
		while (!K->Vacia()) {
            K->Sacar(valor);
			auxPila.Meter(valor);
			auxPila2.Meter(valor);
            totalElementos++;
        }
			for (int i = 1; i <= totalElementos; i++) {
            auxPila2.Sacar(valor);
           	if (i == Lug1) {
				valor1 = valor; // Capturar el valor en Lug1
			} else if (i == Lug2) {
				valor2 = valor; // Capturar el valor en Lug2
			}
            }
        // Intercambiar posiciones mientras reconstruimos la pila original
		for (int i = 1; i <= totalElementos; i++) {
			auxPila.Sacar(valor);

			// Detectar las posiciones a intercambiar
			if (i == Lug1) {
				valor1 = valor; // Capturar el valor en Lug1
			} else if (i == Lug2) {
				valor2 = valor; // Capturar el valor en Lug2
			}

			// Meter los elementos de nuevo en la pila original
			if (i == Lug1) {
				K->Meter(valor2); // Intercambiar con el valor de Lug2
			} else if (i == Lug2) {
				K->Meter(valor1); // Intercambiar con el valor de Lug1
			} else {
				K->Meter(valor); // Mantener los valores restantes iguales
			}
		}
	}
}   */
void intercambiarLugares(pilav* &K, int Lug1, int Lug2) {
    if (K != nullptr && !K->Vacia() && Lug1 != Lug2) {
        pilav auxPila, auxPila2; // Pilas auxiliares
        int valor1 = 0, valor2 = 0;
        int totalElementos = 0;
        int valor;

        // Transferir todos los elementos de la pila original a las pilas auxiliares
        while (!K->Vacia()) {
            K->Sacar(valor);
            auxPila.Meter(valor);
            auxPila2.Meter(valor);
            totalElementos++;
        }

        // Capturar los valores en las posiciones Lug1 y Lug2
        for (int i = 1; i <= totalElementos; i++) {
            auxPila2.Sacar(valor);
            if (i == Lug1) {
                valor1 = valor; // Capturar el valor en Lug1
            } else if (i == Lug2) {
                valor2 = valor; // Capturar el valor en Lug2
            }
        }

        // Reconstruir la pila original con los valores intercambiados
        for (int i = 1; i <= totalElementos; i++) {
            auxPila.Sacar(valor);

            // Intercambiar los valores en las posiciones Lug1 y Lug2
            if (i == Lug1) {
                K->Meter(valor2); // Colocar el valor de Lug2 en Lug1
            } else if (i == Lug2) {
                K->Meter(valor1); // Colocar el valor de Lug1 en Lug2
            } else {
                K->Meter(valor); // Colocar los valores restantes sin cambios
            }
        }
    }
}

void __fastcall TForm1::Button18Click(TObject *Sender)
{
//k2 = new pilav();
pilav * k3 = new pilav ();
k3->Meter(10);
k3->Meter(20);
k3->Meter(30);
k3->Meter(40);
k3->imprimir(Form1->Color, Canvas);
ShowMessage("");
 Canvas->Brush->Color = clBtnFace;
	Canvas->FillRect(Canvas->ClipRect);
	intercambiarLugares(k3,1, 2) ;
    k3->imprimir(Form1->Color, Canvas);
}
//---------------------------------------------------------------------------





void __fastcall TForm1::Button25Click(TObject *Sender)
{
int x;
 //pila2->Sacar(x);
 ShowMessage( x);
}
//---------------------------------------------------------------------------

double evaluar3(polinomioM* poli, double x) {
    double resultado = 0.0;
    // Recorre todos los términos del polinomio
    for (int i = 1; i <= poli->numero_terminos(); i++) {
        // Obtiene el exponente y coeficiente del término
        int exp = poli->exponente(i);
        int coef = poli->coeficiente(exp);
        // Evalúa el término: coef * x^exp
        resultado += coef * pow(x, exp);
    }
    return resultado;
}

void encontrarYMostrarInterseccion(polinomioL* poli1, polinomioL* poli2, int x0, int y0, TCanvas* Canvas) {
    double x, y1, y2;
    bool interseccionEncontrada = false;
    double paso = 0.001;  // Paso pequeño para mayor precisión
    double inicio = -10.0;  // Rango inicial de x
    double fin = 10.0;      // Rango final de x
    double interseccionX = 0.0, interseccionY = 0.0;

    // Primer paso: Búsqueda inicial en un rango amplio
    for (x = inicio; x <= fin; x += paso) {
        y1 = evaluar(poli1, x); // Evalúa el polinomio 1 en x
        y2 = evaluar(poli2, x); // Evalúa el polinomio 2 en x

        // Comparamos los resultados de ambos polinomios. Si la diferencia es pequeña, consideramos que intersectan.
        if (fabs(y1 - y2) < 0.01) {  // Aumentamos el margen a 0.01
            interseccionEncontrada = true;
            interseccionX = x;  // Guardamos el valor de x donde encontramos la intersección
            interseccionY = y1; // Asumimos que y1 es el valor de la intersección, dado que y1 == y2
            break;  // Salimos del bucle al encontrar el primer punto de intersección
        }
    }

    if (interseccionEncontrada) {
        // Reevaluamos el valor de Y para asegurarnos
        interseccionY = evaluar(poli1, interseccionX);

        // Formatear los valores de las coordenadas para que solo muestren dos decimales
        String coordX = FormatFloat("0.00", interseccionX);
        String coordY = FormatFloat("0.00", interseccionY);

        // Generar el string con las coordenadas de la intersección
        String coords = "Intersección: (" + coordX + ", " + coordY + ")";
        Canvas->TextOut(x0, y0, coords);  // Escribimos las coordenadas en el Canvas
    } else {
        // Si no se encontró una intersección, mostrar un mensaje
        //Canvas->Brush->Color = clBlack;
		Canvas->TextOut(x0, y0, "No se encontró un punto de intersección en el rango dado.");
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
// int val = ma->Elemento(f,c);
ma->poner(f, c,  valor);
  //pilaD-> Meter(val);  pilaF-> Meter(f); pilaC-> Meter(c);
}
//---------------------------------------------------------------------------
String EsSudoku(MatrizDispersa* Matriz, int n, int m) {
    // Verificar si las dimensiones son correctas
	if (Matriz->dimension_Fila() != n || Matriz->dimension_columna() != m) {
		return "Error: Dimensiones incorrectas";
    }

    // Arreglos estáticos basados en las dimensiones para verificar repetidos
	int fila[m + 1];       // Arreglo para verificar repetidos en cada fila (basado en el número de columnas)
	int columna[n + 1];    // Arreglo para verificar repetidos en cada columna (basado en el número de filas)

    // Verificar filas y columnas
    for (int i = 1; i <= n; i++) {
        // Reiniciar el arreglo de fila
		for (int k = 0; k <= m; k++) {
			fila[k] = 0;
		}
        int sumaFila = 0;

		for (int j = 1; j <= m; j++) {
			int elementoFila = Matriz->Elemento(i, j);

			// Verificar elementos faltantes y repetidos en la fila
			if (elementoFila == 0) {
				return "Error: Faltan elementos en la fila " + String(i);
			} else if (fila[elementoFila] != 0) {
				return "Error: Elemento repetido en la fila " + String(i) + ", columna " + String(j) + " (valor: " + String(elementoFila) + ")";
			}
			fila[elementoFila]++;
			sumaFila += elementoFila;
		}

        // Verificar la suma de la fila si se desea
        // int sumaEsperadaFila = m * (m + 1) / 2; // Si se espera una suma específica
        // if (sumaFila != sumaEsperadaFila) {
        //     return "Error: Suma incorrecta en la fila " + String(i);
        // }
    }

	for (int j = 1; j <= m; j++) {
		// Reiniciar el arreglo de columna
		for (int k = 0; k <= n; k++) {
			columna[k] = 0;
		}
		int sumaColumna = 0;

		for (int i = 1; i <= n; i++) {
			int elementoColumna = Matriz->Elemento(i, j);

			// Verificar elementos faltantes y repetidos en la columna
			if (elementoColumna == 0) {
				return "Error: Faltan elementos en la columna " + String(j);
			} else if (columna[elementoColumna] != 0) {
				return "Error: Elemento repetido en la columna " + String(j) + ", fila " + String(i) + " (valor: " + String(elementoColumna) + ")";
			}
			columna[elementoColumna]++;
			sumaColumna += elementoColumna;
		}

		// Verificar la suma de la columna si se desea
		// int sumaEsperadaColumna = n * (n + 1) / 2; // Si se espera una suma específica
		// if (sumaColumna != sumaEsperadaColumna) {
		//     return "Error: Suma incorrecta en la columna " + String(j);
		// }
	}

	// Si todas las verificaciones se cumplen, es un Sudoku válido
	return "El Sudoku es válido";
}

//---------------------------------------------------------------------------
 void __fastcall TForm1::Button13Click(TObject *Sender)
{

 //  ShowMessage( EsSudoku(ma,ma->dimension_columna(),ma->dimension_Fila()) );
}
void __fastcall TForm1::Button17Click(TObject *Sender)
{
		 String f= (InputBox("InfijaToPostfija", "introdizca exprecion", ""));



 ShowMessage( pila2->EvaluarPostfija2(pila2->InfijaToPostfija2(f,Form1->Color,Canvas),Form1->Color,Canvas));
	//   pila2->InfijaToPostfija2(f,Form1->Color,Canvas);

}
//---------------------------------------------------------------------------

void intercambiarExtremoscola(colaV1* &C) {
	if (C != nullptr && !C->vacia()) {
		int valorPrimero, valorUltimo;
		ptrlista auxLista;

		// Extraer el primer elemento de la cola
		C->sacar(valorPrimero);

		// Transferir el resto de los elementos a la lista auxiliar
		while (!C->vacia()) {
			int valor;
			C->sacar(valor);
			auxLista.inserta_ultimo(valor);  // Insertar al final de la lista auxiliar
		}

        // Extraer el último elemento de la lista auxiliar
        valorUltimo = auxLista.recupera(auxLista.fin());
		auxLista.suprime(auxLista.fin());  // Eliminar el último nodo de la lista

        // Insertar el último elemento como el nuevo primero en la cola
		C->poner(valorUltimo);

        // Insertar los elementos intermedios en el orden original
        Nodolista* nodo = auxLista.primero();
		while (nodo != nullptr) {
            C->poner(auxLista.recupera(nodo));
			nodo = auxLista.siguiente(nodo);
        }

		// Insertar el primer valor extraído al final de la cola
		C->poner(valorPrimero);
	}
}
	  void rotarCola(colaV1* &C) {
    if (C != nullptr && !C->vacia()) {
        int valorUltimo;
        ptrlista auxLista;

        // Transferir todos los elementos de la cola a la lista auxiliar
        while (!C->vacia()) {
            int valor;
            C->sacar(valor);
            auxLista.inserta_ultimo(valor);  // Insertar al final de la lista auxiliar
        }

        // Extraer el último elemento de la lista auxiliar
        valorUltimo = auxLista.recupera(auxLista.fin());
        auxLista.suprime(auxLista.fin());  // Eliminar el último nodo de la lista

        // Insertar el último elemento como el nuevo primero en la cola
        C->poner(valorUltimo);

        // Insertar los elementos restantes en el orden original
        Nodolista* nodo = auxLista.primero();
        while (nodo != nullptr) {
            C->poner(auxLista.recupera(nodo));
            nodo = auxLista.siguiente(nodo);
        }
    }
}

void intercambiarLugarescola(colaV1* &Q, int Lug1, int Lug2) {
	if (Q != nullptr && !Q->vacia() && Lug1 != Lug2) {
		ptr_cola auxCola; // Cola auxiliar
        int valor1 = 0, valor2 = 0;
		int totalElementos = 0;
        int valor;

        // Transferir todos los elementos de la cola original a la cola auxiliar
		while (!Q->vacia()) {
			Q->sacar(valor);
            auxCola.Meter(valor);
            totalElementos++;
        }

        // Capturar los valores en las posiciones Lug1 y Lug2
        for (int i = 1; i <= totalElementos; i++) {
            auxCola.Sacar(valor);
            if (i == Lug1) {
                valor1 = valor; // Capturar el valor en Lug1
            } else if (i == Lug2) {
                valor2 = valor; // Capturar el valor en Lug2
            }
            // Reinsertar en la cola original para preservarla
			Q->poner(valor);
        }

        // Reconstruir la cola original con los valores intercambiados
        for (int i = 1; i <= totalElementos; i++) {
			Q->sacar(valor);

            // Intercambiar los valores en las posiciones Lug1 y Lug2
            if (i == Lug1) {
                auxCola.Meter(valor2); // Colocar el valor de Lug2 en Lug1
            } else if (i == Lug2) {
                auxCola.Meter(valor1); // Colocar el valor de Lug1 en Lug2
            } else {
                auxCola.Meter(valor); // Mantener los valores restantes iguales
            }
        }

        // Restaurar la cola original desde la cola auxiliar
        while (!auxCola.vacio()) {
            auxCola.Sacar(valor);
			Q->poner(valor);
        }
    }
}

void __fastcall TForm1::Button19Click(TObject *Sender)
{
colaV1 * k3 = new colaV1 ();
k3->poner(10);
k3->poner(20);
k3->poner(30);
k3->poner(40);
k3->imprimir(Form1->Color, Canvas);
ShowMessage("");
 Canvas->Brush->Color = clBtnFace;
	Canvas->FillRect(Canvas->ClipRect);
   //rotarCola(k3);
     intercambiarLugarescola(k3,1,2);
   k3->imprimir(Form1->Color, Canvas);
ShowMessage("");
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button24Click(TObject *Sender)
{
	pila= new  pilaM(M);
		pila2= new  pilaMM(M);
			pilaD= new  pilaMM(M);

}
//---------------------------------------------------------------------------




void __fastcall TForm1::Button20Click(TObject *Sender)
{
 colap = new  ColaConPila(pila2);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button21Click(TObject *Sender)
{
 String x= InputBox("meter a colaP", "introdizca ", "")  ;
colap->Meter(StrToInt(x));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button22Click(TObject *Sender)
{
int x;
colap->Sacar(x);
ShowMessage(x);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button23Click(TObject *Sender)
{
ShowMessage("valor primero"+ IntToStr(colap->Primero()));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button12Click(TObject *Sender)
{
	   // 1. Verificar que la matriz 'ma' (MatrizDispersa2) esté inicializada
    if (ma == nullptr) {
		ShowMessage("La matriz 'ma' no ha sido inicializada. (Botón 6)");
        return;
    }
    // 2. COORDENADAS DE INICIO (Como solicitaste)
    // Cambia estos valores para mover todo el texto
	int x_inicio = 100; // Posición X inicial para el texto
    int y_inicio = 450; // Posición Y inicial para el texto
    int separacion_linea = 20; // Espacio vertical entre líneas
    // 3. Obtener dimensiones de la matriz
    int filas = ma->dimension_Fila();
	int cols = ma->dimension_columna();
    if (filas == 0 || cols == 0) {
        ShowMessage("La matriz no ha sido dimensionada. (Botón 7)");
        return;
    }
    // --- ALGORITMO EFICIENTE O(n^2) ---
    // 4. Vectores para guardar los máximos de fila y mínimos de columna
    // Se usa (dim + 1) para poder usar índices base 1 (como la matriz)
    std::vector<int> maximosFila(filas + 1);
	std::vector<int> minimosColumna(cols + 1);
    // 5. PASO 1: Encontrar el máximo de cada fila
    for (int f = 1; f <= filas; f++) {
        int maxActual = ma->Elemento(f, 1); // Asumir el primero como max
        for (int c = 2; c <= cols; c++) {
			// Actualizamos si encontramos uno más grande
            maxActual = std::max(maxActual, ma->Elemento(f, c));
        }
        maximosFila[f] = maxActual;
    }
	// 6. PASO 2: Encontrar el mínimo de cada columna
    for (int c = 1; c <= cols; c++) {
        int minActual = ma->Elemento(1, c); // Asumir el primero como min
        for (int f = 2; f <= filas; f++) {
            // Actualizamos si encontramos uno más pequeño
            minActual = std::min(minActual, ma->Elemento(f, c));
		}
        minimosColumna[c] = minActual;
    }
// 7. PASO 3: Buscar y dibujar los puntos silla en el Canvas
	Canvas->Font->Color = clBlack;
	Canvas->Font->Size = 9;
	Canvas->TextOut(x_inicio, y_inicio, "Buscando Puntos Silla (Mayor en fila, Menor en columna):");
    y_inicio += separacion_linea;
    int puntosEncontrados = 0;
    // *** INICIO DE LA CORRECCIÓN ***
	// Obtenemos el valor repetido UNA SOLA VEZ antes del bucle
    int valorRepetido = ma->valor_repetido();
    for (int f = 1; f <= filas; f++) {
        for (int c = 1; c <= cols; c++) {
            int valor = ma->Elemento(f, c);
			// Comprobar la condición de Punto Silla
            // Y AÑADIMOS LA NUEVA REGLA: (valor != valorRepetido)
            if (valor == maximosFila[f] &&
                valor == minimosColumna[c] &&
                valor != valorRepetido) {
                String resultado = "  Punto Silla en (" + IntToStr(f) +
								   ", " + IntToStr(c) + ") -> Valor: " + IntToStr(valor);
				Canvas->TextOut(x_inicio, y_inicio, resultado);
				y_inicio += separacion_linea;
				puntosEncontrados++;
            }
		}
	}
	// *** FIN DE LA CORRECCIÓN ***

	// 8. Mostrar mensaje final si no se encontró ninguno
	if (puntosEncontrados == 0) {
		Canvas->TextOut(x_inicio, y_inicio, "  No se encontraron puntos silla.");
	}
	Canvas->Font->Color = clBlack;
}
//---------------------------------------------------------------------------

