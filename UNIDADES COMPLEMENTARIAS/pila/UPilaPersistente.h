//---------------------------------------------------------------------------

#ifndef UPilaPersistenteH
#define UPilaPersistenteH
//---------------------------------------------------------------------------
#include <vcl.h> // Para String, TCanvas, TColor
#include <System.Classes.hpp> // Para TStream (aunque usaremos TFile)
#include <System.SysUtils.hpp> // Para FileExists
#include <System.IOUtils.hpp> // Para TFile (MUY IMPORTANTE)
#include <vector> // Para la lógica interna de MostrarPila

using namespace std;

class PilaPersistente {
private:
	/**
	 * @brief Atributo 'nom' que almacena el nombre del archivo (ej: "nom.txt").
	 */
	String nom;

public:
	/**
	 * @brief Constructor por defecto.
	 */
	PilaPersistente();

	/**
	 * @brief Asigna el nombre del archivo a la pila y lo crea/limpia.
	 * @param nombreArchivo El nombre del archivo (ej: "nom.txt")
	 */
	void CrearPila(String nombreArchivo);

	/**
	 * @brief Añade un elemento al archivo de texto (al final).
	 * Usa operaciones de String (Append).
	 * @param elemento El valor a insertar.
	 */
	void PonerPila(int elemento);

	/**
	 * @brief Saca el último elemento del archivo de texto.
	 * Usa operaciones de String (LastDelimiter, SubString).
	 * @param elemento Variable (pasada por referencia) donde se guardará el valor sacado.
	 * @return true si se pudo sacar, false si la pila estaba vacía.
	 */
	bool SacarPila(int &elemento);

	/**
	 * @brief Dibuja el contenido del archivo de texto en un TCanvas.
	 * Usa operaciones de String (Pos, SubString, Delete) para parsear.
	 * @param Canvas El lienzo donde se dibujará.
	 * @param x Posición X de inicio.
	 * @param y Posición Y de inicio.
	 * @param colorFondo Color de fondo del Canvas (para el texto).
	 */
	void MostrarPila(TCanvas *Canvas, int x, int y, TColor colorFondo);

	/**
	 * @brief Comprueba si el archivo (pila) está vacío leyendo su contenido.
	 * @return true si está vacía, false si no.
	 */
	bool Vacia();
};
//---------------------------------------------------------------------------
#endif


