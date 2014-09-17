//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("glSkeleton.res");
USEFORM("UFP.cpp", GLForm2D);
USEUNIT("PV2D.cpp");
USEUNIT("Obstaculo.cpp");
USEUNIT("Circulo.cpp");
USEUNIT("Lapiz.cpp");
USEUNIT("Pelota.cpp");
USEUNIT("Triangulo.cpp");
USEUNIT("Habitacion.cpp");
USEUNIT("Poligono.cpp");
USEUNIT("Elipse.cpp");
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
