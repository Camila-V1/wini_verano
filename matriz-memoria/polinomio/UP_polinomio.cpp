//---------------------------------------------------------------------------

#pragma hdrstop

#include "UP_polinomio.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
void PolinomioP::crear(){
Nt=0;
ptrpl=nullptr;
}
PolinomioP::PolinomioP(){
crear(); ptrpl=nullptr;
}   Nodopr* PolinomioP::BuscarTermino(int i) {
    Nodopr* Dir = ptrpl;
    int Nt = 0;

    if (Dir != nullptr) {
        while ((Dir != nullptr) && (Nt < i)) {
            Nt = Nt + 1;
            Dir = Dir->sig;
        }
        if (Nt == i) {
            return Dir;
        } else {
            // Lanzar excepción: no existe ese término
        }
    } else {
        // Lanzar excepción: no existen términos
    }
}
   Nodopr* PolinomioP::BuscarExponente(int Exp){

       

  Nodopr* Dir = ptrpl   ;
	Nodopr* dirEx = nullptr;

	if (Dir ==nullptr) {

		return dirEx;
	}else {
     	dirEx=nullptr;
		while ((Dir != nullptr) && (dirEx == nullptr)) {
		 if (Exp==Dir->Exp) {
			  dirEx = Dir;
		 }
			Dir = Dir->sig;
		}
		return dirEx;
    }


  
	
   }


   
Nodopr* PolinomioP::BuscarTerminoN(int i) {
	Nodopr* Dir = ptrpl;
	Nodopr* dirTer = nullptr;
	int Nt = 0;

	if (Dir != nullptr) {
        while ((Dir != nullptr) && (dirTer == nullptr)) {
			Nt = Nt + 1;
            if (Nt == i) {
                dirTer = Dir;
            }
            Dir = Dir->sig;
        }
        return dirTer;
    }
}


bool PolinomioP::esCero(){
return (Nt==0);
}
int PolinomioP::Grado() {
	Nodopr* Dir = ptrpl;
	int MaxG;
	if (Dir != nullptr) {
		MaxG = Dir->Exp;
		while (Dir != nullptr) {
			if (Dir->Exp > MaxG) {
				MaxG = Dir->Exp;
			}
			Dir = Dir->sig;
		}return MaxG;
	} else{
		// Lanzar excepción: no existe ese término
	}
}
int PolinomioP::coeficiente(int Exp) {
	Nodopr* Dir = BuscarTermino(Exp);

    if (Dir != nullptr) {
        return Dir->Coef;
    } else {
        // Lanzar excepción: no existe ese término
    }
}
void PolinomioP::AsignarCoeficiente(int coef, int exp) {
    Nodopr* Dir = BuscarExponente(exp);

    if (Dir != nullptr) {
        Dir->Coef = coef;
        if (coef == 0) {
            // Implementar lógica para eliminar nodo Dir
        }
    } else {
        // Lanzar excepción: no existe ese término
    }
}
void PolinomioP::poner_termino(int coef, int exp) {
	Nodopr* existe = BuscarExponente(exp);

    if (existe == nullptr) {
		Nodopr* aux = new Nodopr;
        if (aux != nullptr) {
			aux->Coef = coef;
			aux->Exp = exp;
            aux->sig = ptrpl;
            ptrpl = aux;
			Nt = Nt + 1;
		} else {
			// Error: espacio de memoria
        }
    } else {
		int NuevoCoef = existe->Coef + coef;
		existe->Coef = NuevoCoef;
		// Implementar lógica para eliminar nodo si NuevoCoef es 0
		if (NuevoCoef==0) {
			delete existe;
		}
    }
}
	int PolinomioP::exponente(int ntro){

		Nodopr* Dir = BuscarTerminoN(ntro);

	if (Dir != nullptr) {
        return Dir->Exp;
    } else {
        // Lanzar excepción: no existe ese término
    }
	
	}
 void PolinomioP::Pintado(int posX, int posY, String cad, TColor color, TCanvas *Canvas){
int TamanoCelda = 35;
int TamanoCeldaX = 80;
int TamanoCeldaY = 35;
	//           x1  y1    x2                   y2
	TRect rect(posX,posY,posX+TamanoCeldaX,posY+TamanoCeldaY);
	Canvas->Brush->Color = color;
	Canvas->FillRect(rect);

	Canvas->TextOutW(posX,posY+3,cad);

}
 int PolinomioP::numero_terminos(){
 return Nt;
 }
 void PolinomioP::imprimir(TColor FormColor, TCanvas *Canvas){
	//ptr->imprimir2( FormColor, Canvas,180,800); int TamanoCelda = 35;
  int TamanoCeldaX = 70;
	int TamanoCeldaY = 35;

	int posX = 1100;
	int posY = 30;

	if (Nt!=0) {
		//DIBUJAMOS CABECERA
		Pintado(posX,posY,"Lista",FormColor,Canvas);
		posY+= TamanoCeldaY;

		Nodopr* x = ptrpl;   int q;

		Pintado(posX,posY,"< ",FormColor,Canvas);
		posX+=40;
		while (x != nullptr) {


			   if (x->Coef>0&&x->Exp>=0) {
                   


				Pintado(posX,posY,IntToStr(x->Coef),FormColor,Canvas);
				posX+=70;

					Pintado(posX,posY,",",FormColor,Canvas);
					posX+=40;

				// Imprimimos el último elemento
               	Pintado(posX,posY,IntToStr(x->Exp),FormColor,Canvas);
				posX+=70;
				if (x->sig != nullptr) {
					Pintado(posX,posY,",",FormColor,Canvas);
					posX+=40;
				}
			

			   }
				x = x->sig;
		}
		Pintado(posX,posY,">",FormColor,Canvas);
		posX+=40;
	}else{
		Pintado(posX,posY,"Lista Vacia",FormColor,Canvas);
		posY+= TamanoCeldaY;
	}
}
