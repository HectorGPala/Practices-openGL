//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#ifndef UFPH
#define UFPH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>

#include <gl\gl.h>
#include <gl\glu.h>

#include "Pixmap.h"
#include "Escena.h"
#include "FormSeleccion.h"

//---------------------------------------------------------------------------
class TGLForm2D : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMenuItem *Archivo1;
        TMenuItem *AbrirBMP1;
        TMenuItem *Operaciones1;
        TMenuItem *Rotar1;
        TMenuItem *MediaPonderada1;
        TMenuItem *SuavizadoGaussiano1;
        TMenuItem *Pixels1;
        TMenuItem *LeerPixmap1;
        TMenuItem *DibujarPixmap1;
        TMenuItem *P1;
        TMenuItem *Secundario1;
        TMenuItem *GuardarBMP1;
        TMenuItem *ModoArbol1;
        TOpenDialog *OpenDialog1;
        TMenuItem *Diferencia1;
  void __fastcall FormCreate(TObject *Sender);
  void __fastcall FormResize(TObject *Sender);
  void __fastcall FormPaint(TObject *Sender);
  void __fastcall FormDestroy(TObject *Sender);
        void __fastcall LeerPixmap1Click(TObject *Sender);
        void __fastcall AbrirBMP1Click(TObject *Sender);
        void __fastcall Rotar1Click(TObject *Sender);
        void __fastcall ModoArbol1Click(TObject *Sender);
        void __fastcall FormMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall MediaPonderada1Click(TObject *Sender);
        void __fastcall SuavizadoGaussiano1Click(TObject *Sender);
        void __fastcall P1Click(TObject *Sender);
        void __fastcall Secundario1Click(TObject *Sender);
        void __fastcall Diferencia1Click(TObject *Sender);

private:	// User declarations
 HDC hdc;
 HGLRC hrc;
 //definen el tamaño del volumen de vista
 GLfloat xLeft,xRight,yTop,yBot;
 //guarda el radio del puerto de vista
 GLfloat RatioViewPort;
 Pixmap* p,*p2;
 Escena* e;
 bool mArbol,rotar,pintarP;
 // métodos privados
 void __fastcall SetPixelFormatDescriptor();
 void __fastcall GLScene();

 public:		// User declarations
   __fastcall TGLForm2D(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TGLForm2D *GLForm2D;
//---------------------------------------------------------------------------
#endif
