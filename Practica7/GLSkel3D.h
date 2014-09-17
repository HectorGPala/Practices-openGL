//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------
#ifndef GLSkel3DH
#define GLSkel3DH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <gl\gl.h>
#include <gl\glu.h>

#include "Camara.h"
//#include "ObjetoCompuesto3D.h"
#include "Escena.h"
#include "Lampara.h"
#include "Pixmap.h"

//---------------------------------------------------------------------------
class TGLForm3D : public TForm
{
__published:	//IDE-managed Components
    void __fastcall FormResize(TObject *Sender);
    void __fastcall FormPaint(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);

private:        //User declarations
    HDC hdc;
    HGLRC hrc;
    //GLfloat eyeX, eyeY, eyeZ, lookX, lookY, lookZ, upX, upY, upZ; //Cámara
    GLdouble RatioViewPort, xLeft, xRight, yBot, yTop, N, F;  //Volumen de vista
    GLUquadricObj* esfera;  //Esfera inicial de la escena
    Camara* c;
    Escena* e;
    Lampara* l;
    bool luzEste,luzAmbiente,luzLampara,niebla;
    unsigned int texturas[2];
    
    void __fastcall SetPixelFormatDescriptor();
    void __fastcall GLScene();
    void crearObjetosEscena();
    void liberarObjetosEscena();

public:		//User declarations
    __fastcall TGLForm3D(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TGLForm3D *GLForm3D;
//---------------------------------------------------------------------------
#endif
