//---------------------------------------------------------------------------

	#pragma hdrstop
	//#include "UFormmemoria.h"
	#include "Umemoria.h"
    #include <algorithm>
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

	int CSmemoria::new_espacio(string cadena){
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

	void CSmemoria::poner_dato(int dir, string id, int valor){
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
		Canvas->Rectangle(rect.Left, rect.Top, rect.Right, rect.Bottom); // Dibuja un rectángulo
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
	/*if (mem[i].dato != 0 || mem[i].id != ""){
	Canvas->Pen->Width = 3;
	Canvas->Pen->Color = clBlue;
						 Canvas->MoveTo(posX,posY);
						 Canvas->LineTo(posX,posY+TamanoCeldaY);
						Canvas->Pen->Color = clBlack;
						Canvas->Pen->Width = 1;
						 }   */
	posX+=TamanoCeldaX;
	Canvas->Brush->Color= FormColor;

	Canvas->Brush->Color = clYellow;
	Canvas->Rectangle(posX,posY,posX+TamanoCeldaX,posY+TamanoCeldaY);
	Canvas->TextOutW(posX+3,posY+3,mem[i].id.c_str());


	/*if (mem[i].dato != 0 || mem[i].id != ""){
	Canvas->Pen->Width = 3;
	Canvas->Pen->Color = clBlue;
						Canvas->MoveTo(posX,posY);
						Canvas->LineTo(posX,posY+TamanoCeldaY);
						Canvas->Pen->Color = clBlack;
						Canvas->Pen->Width = 1;
						 }*/
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
	/*if (mem[i].dato != 0 || mem[i].id != "") {
						 Canvas->Pen->Width = 3;
						 Canvas->Pen->Color = clBlue;
						 Canvas->MoveTo(posX,posY);
						 Canvas->LineTo(posX,posY+TamanoCeldaY);
						 Canvas->Pen->Color = clBlack;
						 Canvas->Pen->Width = 1;
						 } */
	posX+=TamanoCeldaX;
	Canvas->Brush->Color= FormColor;
	Canvas->Brush->Color = clYellow;
	Canvas->Rectangle(posX,posY,posX+TamanoCeldaX,posY+TamanoCeldaY);
	Canvas->TextOutW(posX+3,posY+3,mem[i].id.c_str());
	/*if (mem[i].dato != 0 || mem[i].id != "") {
						 Canvas->Pen->Width = 3;
						 Canvas->Pen->Color = clBlue;
						 Canvas->MoveTo(posX,posY);
						 Canvas->LineTo(posX,posY+TamanoCeldaY);
						 Canvas->Pen->Color = clBlack;
						 Canvas->Pen->Width = 1;
						 }  */
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
	// Nueva tabla para espacios ocupados
  /*
  Canvas->Font->Size =7;
	Canvas->Pen->Color = clRed;
	Canvas->TextOutW(posX,posY,"+"));
	   Canvas->Font->Size =4;
   int occupiedTableX =(posX*3); // 30 pixeles a la derecha de la tabla existente
	   //cabecera nueva memoria
	Canvas->Font->Size =10;
	Canvas->TextOut(occupiedTableX , 0, "espacios ocupados");
	Canvas->Font->Size =7;
	Canvas->TextOut(occupiedTableX, y+10, "Dir");
	Canvas->TextOut(occupiedTableX + 50, y+10, "Dato");
	Canvas->TextOut(occupiedTableX + 140, y+10, "ID");
	Canvas->TextOut(occupiedTableX + 240, y+10, "Link");
			y=y+30;    b=true;
for (int i = 0; i < MAX; ++i) {
	// Dibujar la nueva tabla de espacios ocupados
	if ((mem[i].dato != 0 || mem[i].id != "") ) { // Si el espacio está ocupado
	  if ( b) {  // comento desde aqui hasta donde finalize para que muestre las direcciones una a una
		Canvas->Brush->Color =  clLime;
		Canvas->Rectangle(occupiedTableX, y, occupiedTableX + 80, y + rowHeight);
		Canvas->TextOut(occupiedTableX+3, y+2, IntToStr(i));
		b=false;if (mem[i].link==-1) {
			   b=true;
			}
		} else {
			if (mem[i].link==-1) {
			   b=true;
			}
		} // hasta aqui y desactivo muevo los tres canvas debajod e dir
		 // Dir
		Canvas->Brush->Color = FormColor;
		Canvas->Rectangle(occupiedTableX + 50, y, occupiedTableX + 130, y + rowHeight);
		Canvas->TextOut(occupiedTableX+53, y+2, IntToStr(mem[i].dato)); // Dato
		Canvas->Rectangle(occupiedTableX + 130, y, occupiedTableX + 230, y + rowHeight);
		Canvas->TextOut(occupiedTableX+133, y+2, mem[i].id.c_str()); // ID
		Canvas->Rectangle(occupiedTableX + 230, y, occupiedTableX + 300, y + rowHeight);
		Canvas->TextOut(occupiedTableX+233, y+2, IntToStr(mem[i].link)); // Link
		Canvas->Brush->Color = FormColor; // Cambia Form1 por FormColor
		y += rowHeight;
	}
} /*
 */
}
 void CSmemoria::ImprimirDireccion(int d,TColor FormColor, TCanvas *Canvas,int posX,int posY){
	int auxX = posX;
	int auxY = posY;
	bool b = true;
	int y = posY;int rowHeight = 20;  Canvas->Font->Size =8;
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
	b=true;
	for(int i = 0; i < 11; i++){
	if ( (i >= d && b )) {
		b=true;

	if (b){//condicion para las filas

	if (mem[i].link!=libre) {
	Canvas->Brush->Color =  FormColor;
	Canvas->Pen->Color = clBlack; // Cambia el color del lápiz a negro
   //	Canvas->Rectangle(posX,posY,posX+TamanoCeldaX,posY+TamanoCeldaY);
   //
   //if (mem[i].id=="x") {
	 Canvas->TextOutW(posX+3,posY+3,IntToStr(i));
   //}

	posX+=TamanoCeldaX;
	Canvas->Brush->Color =  clSkyBlue;
	Canvas->Pen->Color = clBlack; // Cambia el color del lápiz a negro
	Canvas->Rectangle(posX,posY,posX+TamanoCeldaX,posY+TamanoCeldaY);
	Canvas->TextOutW(posX+3,posY+3,IntToStr(mem[i].dato));
	posX+=TamanoCeldaX;
	Canvas->Brush->Color = clYellow;

	Canvas->Rectangle(posX,posY,posX+TamanoCeldaX,posY+TamanoCeldaY);
	Canvas->TextOutW(posX+3,posY+3,mem[i].id.c_str());

	posX+=TamanoCeldaX;

	Canvas->Rectangle(posX,posY,posX+TamanoCeldaX,posY+TamanoCeldaY);
	Canvas->TextOutW(posX+3,posY+3,IntToStr(mem[i].link));

			posX=auxX;
			posY+=TamanoCeldaY;
			if (mem[i].link==-1 ) {
				b=false;
			}
	}
	}
	}
	}	String as = "Libre: " + IntToStr(libre);

		Pintado(posX,posY+10,as,FormColor,Canvas);

	y=y+30;

}
int CSmemoria::leng(int i){
 int datoLen = std::to_string(mem[i].dato).length();
 int idLen = mem[i].id.length();
	return max(datoLen,idLen);
}
 void CSmemoria::ImprimirDireccionVertical(int d,TColor FormColor, TCanvas *Canvas,int posX,int posY){
 int tx=40;  // poner en 40 para tama;o normal y en 10 tama;o ajustable
 int car=0;
 int auxX = posX;
	int auxY = posY;
	bool b = true;
	int y = posY;int rowHeight = 20;  Canvas->Font->Size =8;
	//DIBUJAMOS CABECERA
	Pintado(posX-15,posY-5,"dir",FormColor,Canvas);
	posY+=TamanoCeldaY;
	//Pintado(posX-30,posY,"dato",FormColor,Canvas);
	posY+=TamanoCeldaY;
	Pintado(posX-15,posY,"id",FormColor,Canvas);
	posY= auxY;
	posX+= tx;
	Canvas->Font->Size =7;
	//CICLO FOR PARA LEER EL VECTOR SIMULACION DE MEMORIA
	b=true;
	int prelink=-1;
	for(int i = 0; i < 11; i++){
	if (i==prelink || (i == d  && b)) {
		b=true;
	if (b){
	if (mem[i].link!=libre){
   /*	car= leng(i);
		if (car>0) {
		 tx=car*10;
		}  */
	//Canvas->Brush->Color =clLime;
	Canvas->Pen->Color = clBlack; // Cambia el color del lápiz a negro
	//direccion dibujo
   //  Canvas->Rectangle(posX,posY,posX+TamanoCeldaX,posY+TamanoCeldaY);
   if (true){    /// direccion
		//mem[i].id=="x"   // muestra solo la direccion que le esta mandando
	Canvas->TextOutW(posX+3,posY+3,IntToStr(i));
   }
	posY+=TamanoCeldaY;
	// inicio de datos
	Canvas->Brush->Color =  FormColor;
	Canvas->Pen->Color = clBlack; // Cambia el color del lápiz a negro
	// aqui comienza dato
	Canvas->Brush->Color =  clSkyBlue;
	Canvas->Rectangle(posX,posY,posX+tx,posY+TamanoCeldaY);
	Canvas->TextOutW(posX+3,posY+3,IntToStr(mem[i].dato));
	// fin de dato
	posY+=TamanoCeldaY;
	//aqui comienza el id
		if (true) {     //if pal ide
		//mem[i].id=="x"   //solo muestra el id que pides "x"
	Canvas->Brush->Color =  clYellow;
	Canvas->Rectangle(posX,posY,posX+tx,posY+TamanoCeldaY);
	Canvas->TextOutW(posX+3,posY+3,mem[i].id.c_str());
	Canvas->Brush->Color =  FormColor;
		}
	//-----------fin de id
	posY=auxY;
	posX+=tx;
	prelink=mem[i].link;
			if (mem[i].link==-1 ) {
				b=false;
	}
	}
	}
	}
	}
   //String as = "Libre: " + IntToStr(libre);
   //Pintado(posX,posY+10,as,FormColor,Canvas);
	y=y+30;
 }


void CSmemoria::ImprimirDireccionHorizontal(int d, TColor FormColor, TCanvas *Canvas, int &posX, int posY){
   int auxX = posX;
	int auxY = posY;
	Canvas->Font->Size = 8;
	int i = d;
	   Canvas->Font->Size = 8;
	 int x= posX;
	// Dibujamos la cabecera
	 Pintado(x, posY-25, "coef", FormColor, Canvas);
	Pintado(x+40, posY-25, "exp", FormColor, Canvas);
	x += TamanoCeldaX;
	Pintado(x+45, posY-25, "sig", FormColor, Canvas);
	x += TamanoCeldaX;
	Canvas->Font->Size = 7;

	// Mientras no lleguemos al final de los enlaces
	while (i != -1 && mem[i].link != libre) {
		// Dibujamos el dato de la dirección i
	   //	Canvas->Brush->Color = clSkyBlue;
		Canvas->Pen->Color = clBlack;
		Canvas->Rectangle(posX, posY, posX + TamanoCeldaX, posY + TamanoCeldaY);
		Canvas->TextOutW(posX + 3, posY+1 , IntToStr(mem[i].dato));
		// Pasamos a la siguiente dirección enlazada
		i = mem[i].link;
		posX += TamanoCeldaX;
	}
}  //final

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
	/*if (mem[i].dato != 0 || mem[i].id != ""){
	Canvas->Pen->Width = 3;
	Canvas->Pen->Color = clBlue;
						 Canvas->MoveTo(posX,posY);
						 Canvas->LineTo(posX,posY+TamanoCeldaY);
						Canvas->Pen->Color = clBlack;
						Canvas->Pen->Width = 1;
						 }   */
	posX+=TamanoCeldaX;
	Canvas->Brush->Color= FormColor;

	Canvas->Brush->Color = clYellow;
	Canvas->Rectangle(posX,posY,posX+TamanoCeldaX,posY+TamanoCeldaY);
	Canvas->TextOutW(posX+3,posY+3,mem[i].id.c_str());


	/*if (mem[i].dato != 0 || mem[i].id != ""){
	Canvas->Pen->Width = 3;
	Canvas->Pen->Color = clBlue;
						Canvas->MoveTo(posX,posY);
						Canvas->LineTo(posX,posY+TamanoCeldaY);
						Canvas->Pen->Color = clBlack;
						Canvas->Pen->Width = 1;
						 }*/
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




   }else {
     ShowMessage("A tiene que ser mayor que B");
   }
   }
void CSmemoria::sumarValorDesdeDireccion(int dir, const string& id, int valor) {
	int current = dir;  // Inicia desde la dirección proporcionada

    // Recorre los nodos mientras la dirección no sea nula y está dentro de los límites válidos
		int x=obtenerDato(current, id);
		poner_dato(current, id, x + valor);

}



