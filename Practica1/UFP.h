//HECTOR GUTIERREZ PALANCAREJO 05305699J
//---------------------------------------------------------------------------

#ifndef UFPH
#define UFPH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>

#include <gl\gl.h>
#include <gl\glu.h>

#include "Escena.h"
#include "FormSeleccion.h"

#define KEY_LEFT 37
#define KEY_UP 38
#define KEY_RIGHT 39
#define KEY_DOWN 40
#define ZOOM_IN 187
#define ZOOM_OUT 189
#define TECLA_E 69

//---------------------------------------------------------------------------
class TGLForm2D : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMenuItem *Anyadir;
        TMenuItem *Quitar;
        TMenuItem *ZoomIn;
        TMenuItem *ZoomOut;
        TMenuItem *rand;
        TMenuItem *Select;
  void __fastcall FormCreate(TObject *Sender);
  void __fastcall FormResize(TObject *Sender);
  void __fastcall FormPaint(TObject *Sender);
  void __fastcall FormDestroy(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall randClick(TObject *Sender);
        void __fastcall AnyadirClick(TObject *Sender);
        void __fastcall QuitarClick(TObject *Sender);
        void __fastcall SelectClick(TObject *Sender);
        void __fastcall ZoomInClick(TObject *Sender);
        void __fastcall ZoomOutClick(TObject *Sender);

private:	// User declarations
 HDC hdc;
 HGLRC hrc;
 //definen el tamaño del volumen de vista
 GLfloat xLeft,xRight,yTop,yBot;
 //guarda el radio del puerto de vista
 GLfloat RatioViewPort;
 float centroX,centroY,nuevoAlto,nuevoAncho;

 Escena* sc;
 bool aleatorio,seleccionar,embaldosa;
 int cols;
 Cuadrado* seleccionado;

 //métodos privados
 void __fastcall SetPixelFormatDescriptor();
 void __fastcall GLScene();

 public:		// User declarations
   __fastcall TGLForm2D(TComponent* Owner);
   void embaldosar(int nCol);
};
//---------------------------------------------------------------------------
extern PACKAGE TGLForm2D *GLForm2D;
//---------------------------------------------------------------------------
#endif
