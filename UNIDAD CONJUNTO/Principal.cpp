//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("PrincipalF.cpp", Form1);
//---------------------------------------------------------------------------
// La palabra clave 'int' estaba mal escrita como 'nt'
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;

		// LÍNEA FALTANTE: Crea la instancia de tu formulario principal.
		Application->CreateForm(__classid(TForm1), &Form1);

		// LÍNEA FALTANTE: Inicia el bucle de la aplicación para que se ejecute.
		Application->Run();
	}
	catch (Exception &exception)
	{
		// BLOQUE FALTANTE: Captura y muestra errores específicos de VCL.
		Application->ShowException(&exception);
	}
	catch (...)
	{
		// BLOQUE FALTANTE: Captura cualquier otro tipo de error.
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
