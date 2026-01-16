//---------------------------------------------------------------------------
	#pragma hdrstop
	#include "Umemoria.h"
	#include <algorithm>
     #include <vcl.h>
#pragma hdrstop
#include <Vcl.Dialogs.hpp>
	//---------------------------------------------------------------------------
	#pragma package(smart_init)
	int Numero_Ids(string cadena){
	int cantidad=0;
	for (int i =0; i < cadena.length(); i++) {
		if (cadena[i]==',') {
		  cantidad++;
		}
	}
	if(!cadena.empty()){cantidad+=1;}
	else{ cantidad+=0;}
	return cantidad;
	}
	string Obtener_Id(string cadena, int n){
	 string palabra="";
	 int contador=0;
	 int i=0;
	 while ((contador<n-1) && (i<cadena.length()))
	 { if (cadena.at(i)==',') {
		   contador++;
		   cadena=cadena.substr(i+1,cadena.length()-cadena.substr(0,i).length());
		   i=-1;
	   }
	   i++;
	 }
	 i=0;
	 while (cadena[i]!=',' && i<cadena.length())
	 {
	 i++;
	 }
	 palabra=cadena.substr(0,i);
	 return palabra;
	}
	void eliminarflecha(string &cadena){
	int pos=0;
		if (cadena!="") {
		  while (cadena[pos]!='-' && cadena[pos+1]!='>')
			  {
				pos++;
			  }
		  cadena=cadena.substr(pos+2,cadena.length()-cadena.substr(0,pos+1).length());
		}
	}
	char Memoria(int i){
	string M="MEMORIA";
	char aux;
	if ((i>=0) && (i<M.length())) {
		aux=M.at(i);
	}else{
	  aux=' ';
	}
	return aux;
	}

	CSmemoria::CSmemoria(){
	  mem = new NodoMem[MAX];
	  for (int i = 0; i < MAX; i++) {
		mem[i].link= i+1;
		mem[i].dato=0;
	  }
	  mem[MAX - 1].link=-1;
	  libre = 0;
	}
	int CSmemoria::new_espacio(string cadena){   //a,b,c,d,e,r
	int cant = Numero_Ids(cadena);
	int dir=libre;
	int d=libre;
	for (int i = 1; i <= cant-1; i++) {
		mem[d].id=Obtener_Id(cadena,i);
		d=mem[d].link;
	}
	libre=mem[d].link;
	mem[d].link=-1;
	mem[d].id=Obtener_Id(cadena,cant);
	return dir;
	}
	void CSmemoria::Delete_espacio(int dir){  // si pide dejar en la memoria al eliminar
	int x = dir;                              //comemtar las lineas que dice que hace
	while (mem[x].link != -1)
		{  // mem[x].id="";    //borra el id de la memoria
			//mem[x].dato=0;   // pone en 0 el dato
		x=mem[x].link;
		}
	   // mem[x].id="";   // borra el id
	   //	mem[x].dato=0; //pone en 0
	mem[x].link=libre;
	libre=dir;
	}
	int CSmemoria::Espacio_Disponible(){
	// Cantidad de memoria disponible
	int x = libre;
	int c = 0; // CONTADOR
	while (x != -1)
	{
	c++;
	x=mem[x].link;
	}
	// RETORNAR C
	return c;
	}
	int CSmemoria::Espacio_ocupado(){
	return MAX - Espacio_Disponible();
	}
	bool CSmemoria::dir_libre(int dir){
	int x =libre;
	bool c=false;
		while ((x!= NULO) && (c==false)){
		if (x==dir) {
			c=true;
		}
		x=mem[x].link;
		}
	 return c;
	}
	void CSmemoria::poner_dato(int dir, string id, int valor){         //->como
	int z=dir;
	eliminarflecha(id);
		while (z!=NULO){
		if (mem[z].id==id) {
			mem[z].dato=valor;
		}
		z=mem[z].link;
		}
	}
	int CSmemoria::obtenerDato(int dir, string id){
	int z=dir;
	bool ex=false;
	eliminarflecha(id);
	while (z!=NULO){
	if (mem[z].id==id) {
	 return mem[z].dato;
	}
	z=mem[z].link;
	}
	}
	void Pintado(int posX, int posY, String cad, TColor color, TCanvas *Canvas){
	   TRect rect(posX,posY,posX+TamanoCeldaX,posY+TamanoCeldaY);
		TColor oldPenColor = Canvas->Pen->Color; // Guarda el color original del lápiz
		Canvas->Brush->Color = color;
		Canvas->Pen->Color = clBlack; // Cambia el color del lápiz a negro
		///Canvas->Rectangle(rect.Left, rect.Top, rect.Right, rect.Bottom); // Dibuja un rectángulo
		Canvas->Pen->Color = oldPenColor; // Restablece el color del lápiz al color original
		Canvas->TextOutW(posX+3,posY+3,cad);
	}
	String libre_casilla(int i,bool dir_libre){
		if (dir_libre) {
		return "L";
		}else{
		return " ";
		}
	}
 void CSmemoria::ImprimirPantalla2(TColor FormColor, TCanvas *Canvas,int posX,int posY){
	int auxX = posX;
	int auxY = posY;
		Canvas->Font->Size =7;
	bool b = true;
	int p=0;
	   int y = 30;int rowHeight = 20;  Canvas->Font->Size =8;
	//DIBUJAMOS CABECERA
	Pintado(posX,posY-p,"dir",FormColor,Canvas);
	posX+=TamanoCeldaX;
	Pintado(posX,posY-p,"dato",FormColor,Canvas);
	posX+=TamanoCeldaX;
	Pintado(posX,posY-p,"id",FormColor,Canvas);
	posX+=TamanoCeldaX;
	Pintado(posX,posY-p,"link",FormColor,Canvas);
	posX= auxX;
	posY+= TamanoCeldaY;
	Canvas->Font->Size =7;
	//CICLO FOR PARA LEER EL VECTOR SIMULACION DE MEMORIA
	for(int i = 0; i < 4+Espacio_ocupado(); i++){
	//if ( (mem[i].dato ==0 && mem[i].id == "")) {
	if (mem[i].link!=libre) {
	//Canvas->Brush->Color =clLime;
	Canvas->Pen->Color = clBlack; // Cambia el color del lápiz a negro
	//Canvas->Rectangle(posX,posY,posX+TamanoCeldaX,posY+TamanoCeldaY);
	Canvas->TextOutW(posX+3,posY+3,IntToStr(i));
	posX+=TamanoCeldaX;
	Canvas->Brush->Color = clGreen ;    //clLime
	//Canvas->Pen->Color = clBlack; // Cambia el color del lápiz a negro
	Canvas->Rectangle(posX,posY,posX+TamanoCeldaX,posY+TamanoCeldaY);
	Canvas->TextOutW(posX+3,posY+3,IntToStr(mem[i].dato));
	posX+=TamanoCeldaX;
	Canvas->Brush->Color= FormColor;
	Canvas->Brush->Color = clYellow;
	//Canvas->Rectangle(posX,posY,posX+TamanoCeldaX,posY+TamanoCeldaY);
	Canvas->TextOutW(posX+3,posY+3,mem[i].id.c_str());

	posX+=TamanoCeldaX;

	Canvas->Rectangle(posX,posY,posX+TamanoCeldaX,posY+TamanoCeldaY);
	Canvas->TextOutW(posX+3,posY+3,IntToStr(mem[i].link));
			posX=auxX;
			posY+=TamanoCeldaY;
			Canvas->Brush->Color= FormColor;
	}
   //	}
	}	String as = "Libre: " + IntToStr(libre);
		Pintado(posX,posY+10,as,FormColor,Canvas);
}
void CSmemoria::ImprimirPantalla(TColor FormColor, TCanvas *Canvas){
int posX = 180;
	int posY = 30;
	int auxX = posX;
	int auxY = posY;
	bool b = true;
	   int y = 30;int rowHeight = 20;  Canvas->Font->Size =8;
	//DIBUJAMOS CABECERA
	Pintado(posX,posY,"dir",FormColor,Canvas);
	posX+=TamanoCeldaX;
	Pintado(posX,posY,"dato",FormColor,Canvas);
	posX+=TamanoCeldaX;
	Pintado(posX,posY,"id",FormColor,Canvas);
	posX+=TamanoCeldaX;
	Pintado(posX,posY,"link",FormColor,Canvas);
	posX= auxX;
	posY+= TamanoCeldaY;
	Canvas->Font->Size =7;
	//CICLO FOR PARA LEER EL VECTOR SIMULACION DE MEMORIA
	for(int i = 0; i < 4+Espacio_ocupado(); i++){
	//if ( (mem[i].dato ==0 && mem[i].id == "")) {
	if (mem[i].link!=libre) {
	//Canvas->Brush->Color =clLime;
	Canvas->Pen->Color = clBlack; // Cambia el color del lápiz a negro
	//Canvas->Rectangle(posX,posY,posX+TamanoCeldaX,posY+TamanoCeldaY);
	Canvas->TextOutW(posX+3,posY+3,IntToStr(i));
	posX+=TamanoCeldaX;
	Canvas->Brush->Color = clSkyBlue;
	Canvas->Pen->Color = clBlack; // Cambia el color del lápiz a negro
	Canvas->Rectangle(posX,posY,posX+TamanoCeldaX,posY+TamanoCeldaY);
	Canvas->TextOutW(posX+3,posY+3,IntToStr(mem[i].dato));
	posX+=TamanoCeldaX;
	Canvas->Brush->Color= FormColor;
	Canvas->Brush->Color = clYellow;
	Canvas->Rectangle(posX,posY,posX+TamanoCeldaX,posY+TamanoCeldaY);
	Canvas->TextOutW(posX+3,posY+3,mem[i].id.c_str());
	posX+=TamanoCeldaX;
	Canvas->Rectangle(posX,posY,posX+TamanoCeldaX,posY+TamanoCeldaY);
	Canvas->TextOutW(posX+3,posY+3,IntToStr(mem[i].link));
			posX=auxX;
			posY+=TamanoCeldaY;
			Canvas->Brush->Color= FormColor;
	}
   //	}
	}	String as = "Libre: " + IntToStr(libre);
		Canvas->TextOutW (posX,posY+10,as);
}

   /*
void CSmemoria::ImprimirP_DE_A_A_B(TColor FormColor, TCanvas *Canvas,int posX,int posY,int A , int B){
   if (A<=B) {

	int auxX = posX;
	int auxY = posY;
		Canvas->Font->Size =7;
	bool b = true;
	int p=0;
	   int y = 30;int rowHeight = 20;  Canvas->Font->Size =8;
	//DIBUJAMOS CABECERA
	Pintado(posX,posY-p,"dir",FormColor,Canvas);
	posX+=TamanoCeldaX;
	Pintado(posX,posY-p,"dato",FormColor,Canvas);
	posX+=TamanoCeldaX;
	Pintado(posX,posY-p,"id",FormColor,Canvas);
	posX+=TamanoCeldaX;
	Pintado(posX,posY-p,"link",FormColor,Canvas);
	posX= auxX;
	posY+= TamanoCeldaY;
	Canvas->Font->Size =7;
	//CICLO FOR PARA LEER EL VECTOR SIMULACION DE MEMORIA
	for(int i = A; i <= B; i++){
	//if ( (mem[i].dato ==0 && mem[i].id == "")) {
	if (mem[i].link!=libre) {
	//Canvas->Brush->Color =clLime;
	Canvas->Pen->Color = clBlack; // Cambia el color del lápiz a negro
	//Canvas->Rectangle(posX,posY,posX+TamanoCeldaX,posY+TamanoCeldaY);
	Canvas->TextOutW(posX+3,posY+3,IntToStr(i));
	posX+=TamanoCeldaX;
	Canvas->Brush->Color = clGreen ;    //clLime
	//Canvas->Pen->Color = clBlack; // Cambia el color del lápiz a negro
	Canvas->Rectangle(posX,posY,posX+TamanoCeldaX,posY+TamanoCeldaY);
	Canvas->TextOutW(posX+3,posY+3,IntToStr(mem[i].dato));
	posX+=TamanoCeldaX;
	Canvas->Brush->Color= FormColor;
	Canvas->Brush->Color = clYellow;
	Canvas->Rectangle(posX,posY,posX+TamanoCeldaX,posY+TamanoCeldaY);
	Canvas->TextOutW(posX+3,posY+3,mem[i].id.c_str());

	posX+=TamanoCeldaX;

	Canvas->Rectangle(posX,posY,posX+TamanoCeldaX,posY+TamanoCeldaY);
	Canvas->TextOutW(posX+3,posY+3,IntToStr(mem[i].link));
			posX=auxX;
			posY+=TamanoCeldaY;
			Canvas->Brush->Color= FormColor;
	}
   //	}
	}

		Canvas->Brush->Color= FormColor;
		String as = "Libre: " + IntToStr(libre);
		Pintado(posX,posY+10,as,FormColor,Canvas);


   }else {
	 ShowMessage("A tiene que ser mayor que B");
   }
   }
	*/
   //






   void CSmemoria::ImprimirP_DE_A_A_B(TColor FormColor, TCanvas *Canvas, int posX, int posY, int A, int B) {
    if (B < MAX - 1) {
        if (A <= B) {
            int auxX = posX;
            Canvas->Font->Size = 8;

            // --- DIBUJAMOS CABECERA ---
            // Dejamos la primera columna (Estado) vacía de encabezado
            // Avanzamos posX para empezar a dibujar "dir" en la segunda columna
                 posX += TamanoCeldaX; //

            Pintado(posX, posY, "dir", FormColor, Canvas);
            posX += TamanoCeldaX;
            Pintado(posX, posY, "dato", FormColor, Canvas);
            posX += TamanoCeldaX;
            Pintado(posX, posY, "id", FormColor, Canvas);
            posX += TamanoCeldaX;
            Pintado(posX, posY, "link", FormColor, Canvas);

            // Reiniciamos posX al inicio real y bajamos una fila
            posX = auxX;
            posY += TamanoCeldaY;
            Canvas->Font->Size = 7;

            // --- CICLO PARA EL RANGO A..B ---
            for (int i = A; i <= B; i++) {

                // Determinamos si es Libre (LB) u Ocupado (OC)
				String estado = dir_libre(i) ? "LB" : "OC";

                Canvas->Pen->Color = clBlack;


                Canvas->Brush->Color = FormColor;
                Canvas->TextOutW(posX + 3, posY + 3, estado);
				  posX += TamanoCeldaX; //
                // 2. Columna "dir"
                Canvas->Brush->Color = FormColor; // Fondo normal para dir
                Canvas->TextOutW(posX + 3, posY + 3, IntToStr(i));
                posX += TamanoCeldaX;

                // 3. Columna "dato"
                Canvas->Brush->Color = clGreen;
                Canvas->Rectangle(posX, posY, posX + TamanoCeldaX, posY + TamanoCeldaY);
                Canvas->TextOutW(posX + 3, posY + 3, IntToStr(mem[i].dato));
                posX += TamanoCeldaX;

                // 4. Columna "id"
                Canvas->Brush->Color = clYellow;
                Canvas->Rectangle(posX, posY, posX + TamanoCeldaX, posY + TamanoCeldaY);
                Canvas->TextOutW(posX + 3, posY + 3, mem[i].id.c_str());
                posX += TamanoCeldaX;

                // 5. Columna "link"
                Canvas->Brush->Color = clYellow;
                Canvas->Rectangle(posX, posY, posX + TamanoCeldaX, posY + TamanoCeldaY);
                Canvas->TextOutW(posX + 3, posY + 3, IntToStr(mem[i].link));



                // Reiniciar X y bajar Y
                posX = auxX;
                posY += TamanoCeldaY;
				Canvas->Brush->Color = FormColor;
            }

            String as = "Libre: " + IntToStr(libre);
            Pintado(posX, posY + 10, as, FormColor, Canvas);

        } else {
            ShowMessage("A tiene que ser menor o igual a B");
        }
    } else {
        ShowMessage("Valor excede el tamaño de la memoria");
    }
}










 void CSmemoria::ImprimirP_DE_A_A_B2(TColor FormColor, TCanvas *Canvas, int posX, int posY, int A, int B) {
	if (B < MAX - 1) {
		if (A <= B) {
			int auxX = posX;
			Canvas->Font->Size = 8;
			// DIBUJAMOS CABECERA
			Pintado(posX , posY, "dir", FormColor, Canvas);
			posX += TamanoCeldaX;
			Pintado(posX , posY, "dato", FormColor, Canvas);
			posX += TamanoCeldaX;
			Pintado(posX , posY, "id", FormColor, Canvas);
			posX += TamanoCeldaX;
			Pintado(posX , posY, "link", FormColor, Canvas);
			posX = auxX;
			posY += TamanoCeldaY;
			 int xx,yy,xxa;
			 int aa=50,bb=400,xa=400;
			Canvas->Font->Size = 7;
			  bool xb=false;
			for (int i = A; i <= B; i++) {
				if (mem[i].link != libre) {
				/*
				if (i %2==0 ) {
				 xx=posX,yy=posY;
				   xb=true;  xxa=  auxX;
				   posX =aa;posY=bb;
				   auxX=xa;
				}    */
					Canvas->Pen->Color = clBlack;
					// "dir"
					Canvas->TextOutW(posX + 3, posY + 3, IntToStr(i));
					posX += TamanoCeldaX;
					// "dato"
					Canvas->Brush->Color = clGreen;
					Canvas->Rectangle(posX, posY, posX + TamanoCeldaX, posY + TamanoCeldaY);
					Canvas->TextOutW(posX + 3, posY + 3, IntToStr(mem[i].dato));
					posX += TamanoCeldaX;
					// "id"
					Canvas->Brush->Color = clRed;
					Canvas->Rectangle(posX, posY, posX + TamanoCeldaX, posY + TamanoCeldaY);
					Canvas->TextOutW(posX + 3, posY + 3, mem[i].id.c_str());
					posX += TamanoCeldaX;
					// "link" con línea horizontal a la mitad
					Canvas->Brush->Color = clYellow;
					Canvas->Rectangle(posX, posY, posX + TamanoCeldaX, posY + TamanoCeldaY);
					Canvas->TextOutW(posX + 3, posY + 3, IntToStr(mem[i].link));
					// Línea horizontal en la mitad
					/*int midY = posY + TamanoCeldaY / 2;
					Canvas->Pen->Color = clBlack;
					Canvas->MoveTo(posX, midY);
					Canvas->LineTo(posX + TamanoCeldaX, midY);
						 */
					posX = auxX;
					posY += TamanoCeldaY;
					Canvas->Brush->Color = FormColor;
					/*if (xb) {
					  xb=false;
					  aa=  posX; bb= posY; xa=auxX;
					  posX=xx;posY=yy;
					  auxX=xxa;
					}   */
				}
			}
			String as = "Libre: " + IntToStr(libre);
			Pintado(posX, posY + 10, as, FormColor, Canvas);
		} else {
			ShowMessage("A tiene que ser menor o igual a B");
		}
	} else {
		ShowMessage("Valor excede el tamaño de la memoria");
	}
}
  String CSmemoria::libre_casilla6(int i,bool dir_libre){
		if (dir_libre) {
		return "L";
		}else{
		return " ";
		}
	}
	void CSmemoria::prubea()  {

	}







void CSmemoria::MostrarMemoriaDesplazada(TColor FormColor, TCanvas *Canvas, int posX, int posY, int A, int B) {
    int auxX = posX;

    // Definimos el tamaño del "hueco" para el desplazamiento.
    // Queremos que quepan DATO e ID en el hueco, así que reservamos 2 espacios.
    int GAPCeldas = 2 * TamanoCeldaX;

    Canvas->Font->Size = 8;

    // --- DIBUJAMOS CABECERA (Alineada a la derecha / Posición "Libre") ---
    // Columna 1: DIR
    Pintado(posX, posY, "dir", FormColor, Canvas);

    // Saltamos el DIR + el HUECO para pintar los títulos de DATO e ID
    // Posición normal: dir + hueco
    int posColDato = posX + TamanoCeldaX + GAPCeldas;
    int posColId   = posColDato + TamanoCeldaX;
    int posColLink = posColId + TamanoCeldaX;

    Pintado(posColDato, posY, "dato", FormColor, Canvas);
    Pintado(posColId,   posY, "id",   FormColor, Canvas);
    Pintado(posColLink, posY, "link", FormColor, Canvas);

    posY += TamanoCeldaY;
    posX = auxX; // Regresamos al inicio para las filas

    if (B >= MAX || A < 0 || A > B) {
        ShowMessage("Rango inválido.");
        return;
    }

    Canvas->Font->Size = 8;
    Canvas->Pen->Color = clBlack;

    for (int i = A; i <= B; i++) {
        posX = auxX; // Reinicia X al borde izquierdo
        bool ocupado = !dir_libre(i);

        // 1. DIBUJAR 'DIR' (Siempre fijo a la izquierda)
        TRect dirRect(posX, posY, posX + TamanoCeldaX, posY + TamanoCeldaY);
        Canvas->Brush->Color = clWhite;
        Canvas->Rectangle(dirRect);
        Canvas->Brush->Style = bsClear;
        Canvas->TextOut(posX + 5, posY + 7, IntToStr(i));
        Canvas->Brush->Style = bsSolid;

        // 2. DIBUJAR 'LINK' (Siempre fijo a la derecha extrema)
        // Calculamos su posición fija basada en la estructura con hueco
        int linkX = posX + TamanoCeldaX + GAPCeldas + (2 * TamanoCeldaX);
        TRect linkRect(linkX, posY, linkX + TamanoCeldaX, posY + TamanoCeldaY);
        Canvas->Brush->Color = clYellow;
        Canvas->Rectangle(linkRect);
        Canvas->Brush->Style = bsClear;
        Canvas->TextOut(linkX + 5, posY + 7, IntToStr(mem[i].link));
        Canvas->Brush->Style = bsSolid;

        // 3. DIBUJAR 'DATO' e 'ID' (Posición dinámica)
        int datoX, idX;

        if (ocupado) {
            // CASO OCUPADO: Se desplazan al HUECO (a la izquierda, pegado a DIR)
            datoX = posX + TamanoCeldaX; // Justo después de DIR
            idX   = datoX + TamanoCeldaX;
        } else {
            // CASO LIBRE: Se quedan en su posición original (a la derecha)
            datoX = posX + TamanoCeldaX + GAPCeldas;
            idX   = datoX + TamanoCeldaX;
        }

        // Pintar DATO
        TRect datoRect(datoX, posY, datoX + TamanoCeldaX, posY + TamanoCeldaY);
        Canvas->Brush->Color = clGreen;
        Canvas->Rectangle(datoRect);
        Canvas->Brush->Style = bsClear;
        Canvas->TextOut(datoX + 5, posY + 7, IntToStr(mem[i].dato));
        Canvas->Brush->Style = bsSolid;

        // Pintar ID
        TRect idRect(idX, posY, idX + TamanoCeldaX, posY + TamanoCeldaY);
        Canvas->Brush->Color = clYellow;
        Canvas->Rectangle(idRect);
        Canvas->Brush->Style = bsClear;
        Canvas->TextOut(idX + 5, posY + 7, mem[i].id.c_str());
        Canvas->Brush->Style = bsSolid;

        posY += TamanoCeldaY;
    }

    // Muestra el puntero 'libre' al final
    Canvas->Brush->Color = FormColor;
    Canvas->TextOut(auxX, posY + 10, "Libre: " + IntToStr(libre));
}
