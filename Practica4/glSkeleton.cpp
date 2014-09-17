//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("glSkeleton.res");
USEFORM("UFP.cpp", GLForm2D);
USEUNIT("Pixmap.cpp");
USEUNIT("Arbol.cpp");
USEUNIT("Cuadrado.cpp");
USEUNIT("Escena.cpp");
USEUNIT("FormSeleccion.cpp");
USEUNIT("Lapiz.cpp");
USEUNIT("PVD2.cpp");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TGLForm2D), &GLForm2D);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
