//---------------------------------------------------------------------------
#ifndef ColaStringH
#define ColaStringH
//---------------------------------------------------------------------------
#include <System.Classes.hpp> // Para VCL String
#include <System.SysUtils.hpp> // Para IntToStr, StrToInt y Excepciones

// Definición de la clase Cola que solo usa un String
class ColaString {
private:
	// ÚNICO ATRIBUTO PERMITIDO
	String S;

public:
	// Constructor
	ColaString();

	// --- Métodos estándar de la Cola ---

	/**
	 * @brief Verifica si la cola está vacía.
	 * @return true si el string S está vacío, false en caso contrario.
	 */
	bool vacia();

	/**
	 * @brief Añade un elemento al final de la cola (Enqueue).
	 * Simula esto añadiendo el número y un delimitador al final del string S.
	 * @param e El elemento (entero) a insertar.
	 */
	void meter(int e);

	/**
	 * @brief Saca un elemento del frente de la cola (Dequeue).
	 * Simula esto encontrando el primer delimitador, extrayendo el
	 * elemento y recortando el string S.
	 * @param e Variable (pasada por referencia) donde se almacenará el elemento sacado.
	 */
	void sacar(int &e);

	/**
	 * @brief Obtiene el elemento del frente de la cola sin sacarlo (Peek).
	 * @return El entero al frente de la cola.
	 */
	int frente();

	/**
	 * @brief Método de ayuda para visualizar el estado interno del string.
	 * @return El contenido actual del string S.
	 */
	String verContenidoInterno();
};
//---------------------------------------------------------------------------
#endif
