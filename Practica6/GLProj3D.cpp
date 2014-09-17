//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("GLProj3D.res");
USEFORM("GLSkel3D.cpp", GLForm3D);
USEUNIT("\\vboxsrv\Compartido\glSkeleton3D\PV3D.cpp");
USEUNIT("Camara.cpp");
USEUNIT("TAfin.cpp");
USEUNIT("ColorRGB.cpp");
USEUNIT("Objeto3D.cpp");
USEUNIT("ObjetoCompuesto3D.cpp");
USEUNIT("ObjetoCuadrico.cpp");
USEUNIT("Cilindro.cpp");
USEUNIT("Disco.cpp");
USEUNIT("Esfera.cpp");
USEUNIT("\\vboxsrv\Compartido\glSkeleton3D\VerticeNormal.cpp");
USEUNIT("\\vboxsrv\Compartido\glSkeleton3D\Cara.cpp");
USEUNIT("\\vboxsrv\Compartido\glSkeleton3D\Malla.cpp");
USEUNIT("Tablero.cpp");
USEUNIT("Escena.cpp");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TGLForm3D), &GLForm3D);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
