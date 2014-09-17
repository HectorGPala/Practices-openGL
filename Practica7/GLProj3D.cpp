//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("GLProj3D.res");
USEFORM("GLSkel3D.cpp", GLForm3D);
USEUNIT("Camara.cpp");
USEUNIT("TAfin.cpp");
USEUNIT("ColorRGB.cpp");
USEUNIT("Objeto3D.cpp");
USEUNIT("ObjetoCompuesto3D.cpp");
USEUNIT("ObjetoCuadrico.cpp");
USEUNIT("Cilindro.cpp");
USEUNIT("Disco.cpp");
USEUNIT("Esfera.cpp");
USEUNIT("Tablero.cpp");
USEUNIT("Escena.cpp");
USEUNIT("Cara.cpp");
USEUNIT("Malla.cpp");
USEUNIT("PV3D.cpp");
USEUNIT("VerticeNormal.cpp");
USEUNIT("Cubo.cpp");
USEUNIT("GrupoBolas.cpp");
USEUNIT("MesaBillar.cpp");
USEUNIT("Lampara.cpp");
USEUNIT("\\vboxsrv\Compartido\glSkeleton3D_\Pixmap.cpp");
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
