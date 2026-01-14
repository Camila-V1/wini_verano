//---------------------------------------------------------------------------

#pragma hdrstop

#include "ColaArchivo.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
     #pragma package(smart_init)

void ColaArchivo::meter(int valor) {
	TFileStream* archivo = new TFileStream(ARCHIVO_COLA, fmOpenReadWrite | fmShareDenyNone);
	archivo->Position = archivo->Size;  // Ir al final sin ambigüedad
	String texto = (archivo->Size > 0 ? "," : "") + IntToStr(valor);
	archivo->WriteBuffer(texto.c_str(), texto.Length() * sizeof(wchar_t));
	delete archivo;
}


bool ColaArchivo::sacar(int& valor) {
	TFileStream* archivo = new TFileStream(ARCHIVO_COLA, fmOpenReadWrite | fmShareDenyNone);
	int size = archivo->Size;
    if (size == 0) {
        delete archivo;
        return false;  // Archivo vacío
    }

	wchar_t* buffer = new wchar_t[size / sizeof(wchar_t) + 1];
	archivo->ReadBuffer(buffer, size);
    buffer[size / sizeof(wchar_t)] = '\0';
    String contenido = buffer;
    delete[] buffer;

	TStringList* partes = new TStringList();
	partes->StrictDelimiter = true;
	partes->Delimiter = ',';
	partes->DelimitedText = contenido;

    if (partes->Count == 0) {
        delete partes;
        delete archivo;
        return false;
    }

    valor = StrToInt(partes->Strings[0]);
    partes->Delete(0);

    String nuevoContenido = partes->DelimitedText;
    delete partes;

    archivo->Size = 0;  // Borrar contenido
    if (!nuevoContenido.IsEmpty())
        archivo->WriteBuffer(nuevoContenido.c_str(), nuevoContenido.Length() * sizeof(wchar_t));

    delete archivo;
    return true;
}

bool ColaArchivo::vacia() {
	TFileStream* archivo = new TFileStream(ARCHIVO_COLA, fmOpenRead | fmShareDenyNone);
	bool estaVacia = archivo->Size == 0;
	delete archivo;
	return estaVacia;
}

String ColaArchivo::comoTexto() {
	TFileStream* archivo = new TFileStream(ARCHIVO_COLA, fmOpenRead | fmShareDenyNone);
	int size = archivo->Size;
	if (size == 0) {
		delete archivo;
		return "[vacía]";
	}

	wchar_t* buffer = new wchar_t[size / sizeof(wchar_t) + 1];
	archivo->ReadBuffer(buffer, size);
	buffer[size / sizeof(wchar_t)] = '\0';
	String resultado = "[" + String(buffer) + "]";
	delete[] buffer;
	delete archivo;
	return resultado;
}