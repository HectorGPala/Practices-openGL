//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFP.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TGLForm2D *GLForm2D;
//---------------------------------------------------------------------------
__fastcall TGLForm2D::TGLForm2D(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TGLForm2D::FormCreate(TObject *Sender)
{
    hdc = GetDC(Handle);
    SetPixelFormatDescriptor();
    hrc = wglCreateContext(hdc);
    if(hrc == NULL)
    	ShowMessage(":-)~ hrc == NULL");
    if(wglMakeCurrent(hdc, hrc) == false)
    	ShowMessage("Could not MakeCurrent");
    //Cor de fondo de la ventana
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    //inicialización del volumen de vista
    xRight=200.0; xLeft=-xRight;
    yTop=xRight; yBot=-yTop;
    //Radio del volumen de vista == 1

    //inicialización del puerto de vista
    //ClientWidth=400;
    //ClientHeight=400;
    RatioViewPort=1.0;
    p = new Pixmap();
    p2 = NULL;
    e = new Escena(xLeft,xRight,yTop,yBot);
    rotar = false;
    mArbol = false;
    pintarP = true;
    ModoArbol1->Caption = "Modo Arbol NO";

    // inicialización de las variables del programa
}
//---------------------------------------------------------------------------
void __fastcall TGLForm2D::SetPixelFormatDescriptor()
{
    PIXELFORMATDESCRIPTOR pfd = {
    	sizeof(PIXELFORMATDESCRIPTOR),
        1,
        PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
        PFD_TYPE_RGBA,
        32,
        0,0,0,0,0,0,
        0,0,
        0,0,0,0,0,
        32,
        0,
        0,
        PFD_MAIN_PLANE,
        0,
        0,0,0
    };
    int PixelFormat = ChoosePixelFormat(hdc, &pfd);
    SetPixelFormat(hdc, PixelFormat, &pfd);
}
//---------------------------------------------------------------------
void __fastcall TGLForm2D::FormResize(TObject *Sender)
{

 //se actualiza puerto de vista y su radio
  if ((ClientWidth<=1)||(ClientHeight<=1)){
     ClientWidth=400;
     ClientHeight=400;
     RatioViewPort=1.0;
     }
  else RatioViewPort= (float)ClientWidth/(float)ClientHeight;

  glViewport(0,0,ClientWidth,ClientHeight);

  // se actualiza el volumen de vista
  // para que su radio coincida con ratioViewPort
  GLfloat RatioVolVista=xRight/yTop;

  if (RatioVolVista>=RatioViewPort){
     //Aumentamos yTop-yBot
     yTop= xRight/RatioViewPort;
     yBot=-yTop;
     }
  else{
     //Aumentamos xRight-xLeft
     xRight=RatioViewPort*yTop;
     xLeft=-xRight;
     }

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(xLeft,xRight, yBot,yTop);


  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  GLScene();

}
//---------------------------------------------------------------------------
void __fastcall TGLForm2D::GLScene()
{
glClear(GL_COLOR_BUFFER_BIT);

// comandos para dibujar la escena
if(pintarP && p != NULL)
        p->drawPixmap(xLeft,yBot);
else if(!pintarP && p2 != NULL)
        p2->drawPixmap(xLeft,yBot);
if(e != NULL)
        e->drawEscena();
glFlush();
SwapBuffers(hdc);
}

//---------------------------------------------------------------------------
void __fastcall TGLForm2D::FormPaint(TObject *Sender)
{
  GLScene();
}
//---------------------------------------------------------------------------
void __fastcall TGLForm2D::FormDestroy(TObject *Sender)
{
    ReleaseDC(Handle,hdc);
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(hrc);
    // eliminar objetos creados
    delete p; p = NULL;
    delete e; e = NULL;
    if(p2 != NULL){
        delete p2;
        p2 = NULL;
    }
}
//---------------------------------------------------------------------------

void __fastcall TGLForm2D::LeerPixmap1Click(TObject *Sender)
{
        glFlush();
        SwapBuffers(hdc);
        int rows = ClientHeight;
        int cols = ClientWidth;
        p->readFrameBuffer(rows,cols);
        GLScene();
}
//---------------------------------------------------------------------------

void __fastcall TGLForm2D::AbrirBMP1Click(TObject *Sender)
{
        if(OpenDialog1->Execute()){
                String s = OpenDialog1->FileName;
                delete p;
                p = new Pixmap(s.c_str());
        }
        GLScene();
}
//---------------------------------------------------------------------------

void __fastcall TGLForm2D::Rotar1Click(TObject *Sender)
{
        rotar = !rotar;
}
//---------------------------------------------------------------------------

void __fastcall TGLForm2D::ModoArbol1Click(TObject *Sender)
{
        mArbol = !mArbol;
        if(mArbol)
                ModoArbol1->Caption = "Modo Arbol SI";
        else
                ModoArbol1->Caption = "Modo Arbol NO";
}
//---------------------------------------------------------------------------

void __fastcall TGLForm2D::FormMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        GLdouble relacionAncho = (xRight-xLeft)/ClientWidth;
        GLdouble relacionAlto = (yTop-yBot)/ClientHeight;
        GLdouble cx = xLeft + (GLfloat)X*relacionAncho;
        GLdouble cy = yTop - (GLfloat)Y*relacionAlto;
        
        if(mArbol){
                GLdouble tam = 0.0;
                if(Button == mbLeft){
                        if(e->getArbol()->empty()){
                                TForm* z = new TFormS(this,tam);
                                z->Caption = "Introduce Tamaño";
                                z->ShowModal();
                        }
                        int t = tam;
                        e->getArbol()->anidar(cx,cy,false,t);
                }
                else
                        e->getArbol()->desanidar();
        }
        if(rotar){
                GLdouble alfa;
                TForm* z = new TFormS(this,alfa);
                z->Caption = "Introduce Angulo";
                z->ShowModal();
                p->rotar(alfa,X,ClientHeight-Y);
                //rotar = false;
        }
        GLScene();
}
//---------------------------------------------------------------------------

void __fastcall TGLForm2D::MediaPonderada1Click(TObject *Sender)
{
        if(p2 == NULL){
                if(OpenDialog1->Execute()){
                        String s = OpenDialog1->FileName;
                        p2 = new Pixmap(s.c_str());
                }
        }
        GLdouble k = 0.0;
        TForm* z = new TFormS(this,k);
        z->Caption = "Introduce factor k";
        z->ShowModal();
        if(k > 1.0 || k < 0.0)
                ShowMessage("Valor Erroneo");
        else{
                p->mediaPonderada(k,p2);
                GLScene();
        }
}
//---------------------------------------------------------------------------

void __fastcall TGLForm2D::SuavizadoGaussiano1Click(TObject *Sender)
{
        p->suavizadoGaussiano();
        GLScene();
}
//---------------------------------------------------------------------------

void __fastcall TGLForm2D::P1Click(TObject *Sender)
{
        pintarP = true;
        GLScene();        
}
//---------------------------------------------------------------------------

void __fastcall TGLForm2D::Secundario1Click(TObject *Sender)
{
        pintarP = false;
        GLScene();        
}
//---------------------------------------------------------------------------

void __fastcall TGLForm2D::Diferencia1Click(TObject *Sender)
{
        if(p2 == NULL){
                if(OpenDialog1->Execute()){
                        String s = OpenDialog1->FileName;
                        p2 = new Pixmap(s.c_str());
                }
        }
        p->diferencia(p2);
        GLScene();

}
//---------------------------------------------------------------------------

