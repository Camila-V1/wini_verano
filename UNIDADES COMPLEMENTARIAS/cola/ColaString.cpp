//---------------------------------------------------------------------------
#pragma hdrstop
#include "ColaString.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

// Constructor
ColaString::ColaString() {
	// El atributo String S se inicializa automáticamente como vacío ("").
}

// Verifica si el string está vacío
bool ColaString::vacia() {
	return S.IsEmpty();
}

// Mete un elemento (Enqueue)
void ColaString::meter(int e) {

	S = S + IntToStr(e) + ",";
}

// Saca un elemento (Dequeue)
void ColaString::sacar(int &e) {
	if (vacia()) {
		ShowMessage("Error: No se puede sacar de una cola vacía.");
		e = -1; // Asignar un valor de error
		return;
	}

	try {
		// 1. Encontrar la posición del primer delimitador (la coma)
		//    (Pos() en VCL es 1-based)
		int posComa = S.Pos(",");

		if (posComa == 0) {
			// Esto no debería pasar si 'meter' siempre añade una coma
			ShowMessage("Error: Formato de string inválido (sin coma).");
			e = -1;
			S = ""; // Limpiar el string para evitar errores futuros
			return;
		}

		// 2. Extraer la subcadena que representa el número
		//    SubString(índice_inicio, longitud)
		String elementoStr = S.SubString(1, posComa - 1);

		// 3. Convertir el string a entero y guardarlo en 'e'
		e = StrToInt(elementoStr);

		// 4. Actualizar el string S, quitando el elemento y la coma
		//    SubString(índice_inicio, longitud_restante)
		S = S.SubString(posComa + 1, S.Length());

	} catch (const EConvertError &ex) {
		ShowMessage("Error al convertir string a entero durante 'sacar'.");
		e = -1;
		S = ""; // Limpiar el string erróneo
	}
}

// Obtiene el elemento del frente (Peek)
int ColaString::frente() {
	if (vacia()) {
		// No se puede ver el frente si está vacía
		return -1; // Devolver un valor de error
	}

	try {
		// 1. Encontrar la posición del primer delimitador
		int posComa = S.Pos(",");

		if (posComa == 0) {
			return -1; // Formato inválido
		}

		// 2. Extraer la subcadena del número
		String elementoStr = S.SubString(1, posComa - 1);

		// 3. Convertir y devolver el valor
		return StrToInt(elementoStr);

	} catch (const EConvertError &ex) {
		return -1; // Error de conversión
	}
}

// Método de ayuda para depuración
String ColaString::verContenidoInterno() {
	if (vacia()) {
		return "[Cola Vacía]";
	}
	// Devuelve el string S tal como está almacenado
	return S;
}
