#include "MatrizEnLista.h"

LBCS::LBCS() {
    L = new ptrlista();
    repe = 0;
}

LBCS::~LBCS() {
    if (L) delete L;
}

// Encuentra el nodo que contiene las FILAS de las dimensiones (penúltimo nodo)
Nodolista* LBCS::BuscarNodoDimensionFilas() {
    if (L->vacia()) return nullptr;
    
    Nodolista* aux = L->primero();
    
    // Avanzar hasta que aux->sig->sig == nullptr
    // Entonces aux apunta al penúltimo nodo (dimensión filas)
    while (aux != nullptr && aux->sig != nullptr && aux->sig->sig != nullptr) {
        aux = aux->sig;
    }
    
    return aux;
}

// Busca una tripleta (f, c, valor) y retorna la dirección del nodo FILA
Nodolista* LBCS::BuscarElemento(int f, int c) {
    if (L->vacia()) return nullptr;
    
    Nodolista* aux = L->primero();
    
    // Contar cuántos nodos hay en total
    int totalNodos = 0;
    Nodolista* temp = L->primero();
    while (temp != nullptr) {
        totalNodos++;
        temp = temp->sig;
    }
    
    // Si solo hay 2 nodos o menos, son solo las dimensiones, no hay datos
    if (totalNodos <= 2) return nullptr;
    
    // Recorrer de 3 en 3, deteniéndose antes de las dimensiones (últimos 2 nodos)
    int nodosRecorridos = 0;
    while (aux != nullptr && nodosRecorridos + 2 < totalNodos) {
        // Verificar que tengamos espacio para una tripleta completa
        if (nodosRecorridos + 5 > totalNodos) {
            // No hay espacio para tripleta + dimensiones, salir
            break;
        }
        
        Nodolista* sigFila = aux->sig;
        if (sigFila == nullptr) break;
        
        Nodolista* sigCol = sigFila->sig;
        if (sigCol == nullptr) break;
        
        int filaActual = aux->elemento;
        int colActual = sigFila->elemento;
        
        if (filaActual == f && colActual == c) {
            return aux;  // Retorna la dirección del nodo FILA
        }
        
        // Avanzar 3 posiciones (a la siguiente tripleta)
        aux = sigCol->sig;
        nodosRecorridos += 3;
    }
    
    return nullptr;
}

// Dimensionar: Crea una lista con solo las dimensiones al final
void LBCS::dimensionar(int f, int c) {
    // Limpiar lista
    while (!L->vacia()) {
        L->suprime(L->primero());
    }
    
    // Insertar solo las dimensiones: <filas, columnas>
    L->inserta_ultimo(f);
    L->inserta_ultimo(c);
}

// Obtiene el elemento en (f, c)
int LBCS::elemento(int f, int c) {
    Nodolista* dir = BuscarElemento(f, c);
    
    if (dir != nullptr) {
        // dir apunta a FILA
        // dir->sig apunta a COLUMNA
        // dir->sig->sig apunta a DATO
        return dir->sig->sig->elemento;
    }
    
    return repe;  // No existe, retornar valor repetido
}

// Poner un valor en (f, c)
void LBCS::poner(int f, int c, int valor) {
    Nodolista* dir = BuscarElemento(f, c);
    
    // CASO 1: Existe y ponemos valor repetido (0) -> ELIMINAR
    if (dir != nullptr && valor == repe) {
        Nodolista* dirFila = dir;
        Nodolista* dirCol = dirFila->sig;
        Nodolista* dirDato = dirCol->sig;
        
        L->suprime(dirDato);
        L->suprime(dirCol);
        L->suprime(dirFila);
        return;
    }
    
    // CASO 2: Existe y ponemos valor diferente -> MODIFICAR
    if (dir != nullptr && valor != repe) {
        Nodolista* dirDato = dir->sig->sig;
        dirDato->elemento = valor;
        return;
    }
    
    // CASO 3: No existe y valor es repetido -> NO HACER NADA
    if (dir == nullptr && valor == repe) {
        return;
    }
    
    // CASO 4: No existe y valor != repetido -> INSERTAR ANTES de dimensiones
    if (dir == nullptr && valor != repe) {
        Nodolista* nodoDimFilas = BuscarNodoDimensionFilas();
        
        if (nodoDimFilas != nullptr) {
            // Insertar fila antes de dimensiones
            L->insertar(nodoDimFilas, f);
            
            // Ahora nodoDimFilas sigue siendo el mismo nodo (dimensión filas)
            // pero hay un nuevo nodo (fila) justo antes de él
            // Insertar columna antes de dimensiones (después de fila)
            L->insertar(nodoDimFilas, c);
            
            // Insertar valor antes de dimensiones (después de fila y columna)
            L->insertar(nodoDimFilas, valor);
            
            // Resultado final: [..., f, c, valor, dimFilas, dimCols]
        }
    }
}

void LBCS::definir_valor_repetido(int valor) {
    repe = valor;
}

// Imprime la lista interna en formato texto
void LBCS::imprimirLista(TColor FormColor, TCanvas* Canvas, int posX, int posY) {
    Canvas->Font->Color = clBlack;
    Canvas->Brush->Color = FormColor;
    
    String linea = "Lista: < ";
    
    if (L && !L->vacia()) {
        Nodolista* actual = L->primero();
        bool primero = true;
        
        while (actual != nullptr) {
            if (!primero) linea += ", ";
            linea += IntToStr(actual->elemento);
            actual = actual->sig;
            primero = false;
        }
    }
    
    linea += " >";
    Canvas->TextOutW(posX, posY, linea);
}

// Imprime la matriz como tabla
void LBCS::imprimir(TColor FormColor, TCanvas* Canvas) {
    imprimir2(FormColor, Canvas, 50, 100);
}

void LBCS::imprimir2(TColor FormColor, TCanvas* Canvas, int posX, int posY) {
    // Leer dimensiones desde el final de la lista
    if (L->vacia()) return;
    
    Nodolista* nodoDimFilas = BuscarNodoDimensionFilas();
    if (nodoDimFilas == nullptr) return;
    
    Nodolista* nodoDimCols = nodoDimFilas->sig;
    if (nodoDimCols == nullptr) return;
    
    int df = nodoDimFilas->elemento;
    int dc = nodoDimCols->elemento;
    
    const int TamCelda = 40;
    int x = posX;
    int y = posY;
    
    Canvas->Font->Color = clBlack;
    Canvas->Brush->Color = FormColor;
    
    // Título
    Canvas->TextOutW(x, y, "Matriz En Lista (dims al final):");
    y += 25;
    
    // Dibujar matriz
    for (int f = 1; f <= df; f++) {
        x = posX;
        for (int c = 1; c <= dc; c++) {
            int valor = elemento(f, c);
            
            if (valor == repe) {
                // Casilla con valor repetido: fondo blanco, CON texto "0"
                Canvas->Brush->Color = clWhite;
                Canvas->Rectangle(x, y, x + TamCelda, y + TamCelda);
                
                String texto = IntToStr(repe);
                int textoWidth = Canvas->TextWidth(texto);
                int textoHeight = Canvas->TextHeight(texto);
                Canvas->TextOutW(x + (TamCelda - textoWidth) / 2, 
                               y + (TamCelda - textoHeight) / 2, texto);
            } else {
                // Casilla con número: fondo amarillo, con texto
                Canvas->Brush->Color = clYellow;
                Canvas->Rectangle(x, y, x + TamCelda, y + TamCelda);
                
                String texto = IntToStr(valor);
                int textoWidth = Canvas->TextWidth(texto);
                int textoHeight = Canvas->TextHeight(texto);
                Canvas->TextOutW(x + (TamCelda - textoWidth) / 2, 
                               y + (TamCelda - textoHeight) / 2, texto);
            }
            
            x += TamCelda;
        }
        y += TamCelda;
    }
    
    Canvas->Brush->Color = FormColor;
    
    // Mostrar la lista serializada debajo
    y += 10;
    imprimirLista(FormColor, Canvas, posX, y);
}
