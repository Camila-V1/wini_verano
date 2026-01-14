//---------------------------------------------------------------------------
#pragma hdrstop

#include "UPilaPersistente.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

// --- Implementación de Métodos Públicos ---

PilaPersistente::PilaPersistente() {
	this->nom = "";
}

/**
 * @brief Asigna el nombre y crea/limpia el archivo.
 * (Usa TFile::WriteAllText para crear un archivo vacío)
 */
void PilaPersistente::CrearPila(String nombreArchivo) {
	this->nom = nombreArchivo;
	try {
		// Crea o sobrescribe el archivo con contenido vacío
		TFile::WriteAllText(this->nom, "");
	}
	catch (Exception &e) {
		ShowMessage("Error al crear el archivo: " + e.Message);
	}
}

/**
 * @brief Añade un elemento al final del archivo.
 * (Usa TFile::AppendAllText para añadir la línea)
 */
void PilaPersistente::PonerPila(int elemento) {
	if (this->nom.IsEmpty()) {
		ShowMessage("Error: La pila no ha sido creada (el 'nom' está vacío).");
		return;
	}

	// Crea la línea a añadir (ej: "123\r\n")
	String linea = IntToStr(elemento) + "\r\n";

	try {
		// Añade la línea al final del archivo
		TFile::AppendAllText(this->nom, linea);
	}
	catch (Exception &e) {
		ShowMessage("Error al escribir en el archivo: " + e.Message);
	}
}

/**
 * @brief Saca el último elemento del archivo usando manipulación de String.
 */
bool PilaPersistente::SacarPila(int &elemento) {
	if (Vacia()) { // Vacia() revisará si el archivo está vacío
		return false;
	}

	String contenido = "";
	try {
		// 1. Leer todo el contenido del archivo en una String
		contenido = TFile::ReadAllText(this->nom);
		// Quita espacios/saltos de línea al final
		contenido = contenido.Trim();

		if (contenido.IsEmpty()) {
			return false; // Estaba vacío o solo tenía espacios
		}

		// 2. Buscar el último salto de línea ("\r\n")
		// LastDelimiter devuelve la POSICIÓN (base 1) donde comienza "\r\n"
		int pos = contenido.LastDelimiter("\r\n");

		String nuevoContenido = "";

		if (pos == 0) {
			// No se encontró "\r\n", significa que solo hay UNA línea
			elemento = StrToInt(contenido);
			// El nuevo contenido es un string vacío
			nuevoContenido = "";
		}
		else {
			// Se encontró "\r\n", hay múltiples líneas

			// 3. Extraer el valor (la cima)
			// (Lo que está DESPUÉS del último "\r\n")
			String valorStr = contenido.SubString(pos + 2, contenido.Length());
			elemento = StrToInt(valorStr);

			// 4. Truncar la String
			// (Lo que está ANTES del último "\r\n", más el salto de línea)
			nuevoContenido = contenido.SubString(1, pos + 1); // (pos+1 incluye el \n)
		}

		// 5. Sobrescribir el archivo con el contenido truncado
		TFile::WriteAllText(this->nom, nuevoContenido);
		return true;

	}
	catch (Exception &e) {
		ShowMessage("Error al sacar de la pila: " + e.Message);
		return false;
	}
}

/**
 * @brief Comprueba si el archivo está vacío leyendo su contenido.
 */
bool PilaPersistente::Vacia() {
	if (this->nom.IsEmpty() || !FileExists(this->nom)) {
		return true;
	}

	try {
		String contenido = TFile::ReadAllText(this->nom);
		// Si el contenido (sin espacios) está vacío, la pila está vacía
		return contenido.Trim().IsEmpty();
	}
	catch (Exception &e) {
		ShowMessage("Error al verificar si la pila está vacía: " + e.Message);
		return true; // Asumir vacía si hay error
	}
}

/**
 * @brief Dibuja la pila (leyendo el archivo) usando manipulación de String.
 */
void PilaPersistente::MostrarPila(TCanvas *Canvas, int x, int y, TColor colorFondo) {

	Canvas->Brush->Color = colorFondo;
	Canvas->Font->Size = 8;
	Canvas->Font->Color = clBlack; // Forzar fuente negra
	Canvas->Brush->Style = bsClear;

	if (Vacia()) {
		Canvas->TextOut(x, y, "Pila Persistente Vacia");
		Canvas->Brush->Style = bsSolid; // Restaurar
		return;
	}

	// Vector temporal SOLO para dibujar. La clase no almacena listas.
	std::vector<String> lineas;
	String contenido = "";

	try {
		// 1. Leer todo el contenido
		contenido = TFile::ReadAllText(this->nom);
		contenido = contenido.Trim();

		// 2. Parsear la String línea por línea (buscando "\r\n")
		String temp = contenido;
		int pos;
		while ((pos = temp.Pos("\r\n")) > 0) {
			// Extraer la línea antes del "\r\n"
			lineas.push_back(temp.SubString(1, pos - 1));
			// Borrar esa línea y el "\r\n"
			temp.Delete(1, pos + 1);
		}
		// Añadir la última línea (la que no tiene "\r\n" al final)
		if (!temp.IsEmpty()) {
			lineas.push_back(temp);
		}

		// 3. Dibujar la pila (en orden inverso al vector)
		int posY = y;
		int anchoCelda = 80;
		int altoCelda = 25;

		Canvas->TextOut(x + anchoCelda + 5, y + 5, "<- Cima (Archivo: " + ExtractFileName(this->nom) + ")");

		// Iteramos desde el final del vector (cima) hasta el principio (fondo)
		for (int i = lineas.size() - 1; i >= 0; i--) {
			TRect rect(x, posY, x + anchoCelda, posY + altoCelda);

			Canvas->Brush->Color = clWhite;
			Canvas->Pen->Color = clBlack;
			Canvas->Rectangle(rect); // Dibuja la celda

			// Dibuja el número dentro
			Canvas->Font->Color = clBlack;
			Canvas->Brush->Style = bsClear;
			Canvas->TextOut(x + 5, posY + 5, lineas[i]);
			Canvas->Brush->Style = bsSolid;

			posY += altoCelda; // Mueve la posición Y hacia abajo
		}

		Canvas->Brush->Style = bsClear;
		Canvas->TextOut(x + 5, posY + 5, "<- Fondo");
		Canvas->Brush->Style = bsSolid; // Restaura
	}
	catch (Exception &e) {
		ShowMessage("Error al dibujar la pila: " + e.Message);
	}
}


