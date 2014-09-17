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
#include <ExtCtrls.hpp>

#include <gl\gl.h>
#include <gl\glu.h>

#include "Pelota.h"
#include "Triangulo.h"
#include "Habitacion.h"
#include "Elipse.h"
//---------------------------------------------------------------------------
class TGLForm2D : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMenuItem *Debug;
        TMenuItem *Step;
        TTimer *Timer1;
        TMenuItem *Debug1;
        TMenuItem *Corteza1;
  void __fastcall FormCreate(TObject *Sender);
  void __fastcall FormResize(TObject *Sender);
  void __fastcall FormPaint(TObject *Sender);
  void __fastcall FormDestroy(TObject *Sender);
        void __fastcall DebugClick(TObject *Sender);
        void __fastcall StepClick(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall Debug1Click(TObject *Sender);
        void __fastcall Corteza1Click(TObject *Sender);

private:	// User declarations
 HDC hdc;
 HGLRC hrc;
 //definen el tamaño del volumen de vista
 GLfloat xLeft,xRight,yTop,yBot;
 //guarda el radio del puerto de vista
 GLfloat RatioViewPort;
 //Circulo* c;
 bool debug;
 bool pasos;
 bool corteza;
 Habitacion* h;
 //Pelota* p;
 // métodos privados
 void __fastcall SetPixelFormatDescriptor();
 void __fastcall GLScene();

 public:		// User declarations
        void creaObstaculos();
   __fastcall TGLForm2D(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TGLForm2D *GLForm2D;
//---------------------------------------------------------------------------
#endif
