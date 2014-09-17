//HECTOR GUTIERREZ PALANCAREJO 05305699J
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
    sc = new Escena(xLeft,xRight,yTop,yBot);
    aleatorio = false;
    seleccionar = false;
    embaldosa = false;
    Caption = "Arbol Fractal de Pitagoras";

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
  GLfloat RatioVolVista=(xRight-xLeft)/(yTop-yBot);

  if (RatioVolVista>=RatioViewPort){
     //Aumentamos yTop-yBot
     nuevoAlto = (xRight-xLeft)*ClientHeight/ClientWidth;
     centroY = (yBot+yTop)/2.0;
     yBot = centroY-(nuevoAlto/2.0);
     yTop = centroY+(nuevoAlto/2.0);
     }
  else{
     //Aumentamos xRight-xLeft
     nuevoAncho = (yTop-yBot)*ClientWidth/ClientHeight;
     centroX = (xLeft+xRight)/2.0;
     xRight=centroX+(nuevoAncho/2.0);
     xLeft=centroX-(nuevoAncho/2.0);
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

if(sc != NULL)
        if(embaldosa)
                embaldosar(cols);
        else
                sc->drawEscena();
//PINTAR CENTRO
glColor3f(0.0f, 0.0f, 0.0f);
glBegin(GL_POINTS);
glVertex2i(centroX,centroY);
glEnd();

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
    delete sc;sc = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TGLForm2D::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{

switch(Key){
        case(TECLA_E):
                cols = 0;
                while(!embaldosa && cols <= 0){
                        TForm* x = new TFormS(this,cols);
                        x->Caption = "Introduce Columnas";
                        x->ShowModal();
                }
                embaldosa = !embaldosa;
                if(!embaldosa)
                        glViewport(0,0,ClientWidth,ClientHeight);
                break;
        case(KEY_LEFT):
                xLeft += 5;
                xRight += 5;
                centroX += 5;
                sc->set(xLeft,xRight,yTop,yBot);
                break;
        case(KEY_RIGHT):
                xLeft -= 5;
                xRight -= 5;
                centroX -= 5;
                sc->set(xLeft,xRight,yTop,yBot);
                break;
        case(KEY_UP):
                yTop -= 5;
                yBot -= 5;
                centroY -= 5;
                sc->set(xLeft,xRight,yTop,yBot);
                break;
        case(KEY_DOWN):
                yTop += 5;
                yBot += 5;
                centroY += 5;
                sc->set(xLeft,xRight,yTop,yBot);
                break;
        case(ZOOM_IN):
                nuevoAncho = (xRight-xLeft)/1.1;
                nuevoAlto = (yTop-yBot)/1.1;
                yBot = centroY-(nuevoAlto/2.0);
                yTop = centroY+(nuevoAlto/2.0);
                xRight = centroX+(nuevoAncho/2.0);
                xLeft = centroX-(nuevoAncho/2.0);
                sc->set(xLeft,xRight,yTop,yBot);
                break;
        case(ZOOM_OUT):
                nuevoAncho = (xRight-xLeft)*1.1;
                nuevoAlto = (yTop-yBot)*1.1;
                yBot = centroY-(nuevoAlto/2.0);
                yTop = centroY+(nuevoAlto/2.0);
                xRight = centroX+(nuevoAncho/2.0);
                xLeft = centroX-(nuevoAncho/2.0);
                sc->set(xLeft,xRight,yTop,yBot);
                break;
}
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(xLeft,xRight, yBot,yTop);

glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
GLScene();
}
//---------------------------------------------------------------------------

void __fastcall TGLForm2D::FormMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        GLdouble relacionAncho = (xRight-xLeft)/ClientWidth;
        GLdouble relacionAlto = (yTop-yBot)/ClientHeight;
        GLdouble cx = xLeft + (GLfloat)X*relacionAncho;
        GLdouble cy = yTop - (GLfloat)Y*relacionAlto;
        if(Button == mbLeft){
                if(!seleccionar){
                        int tam;
                        if(sc->getArbol()->empty()){
                                TForm* x = new TFormS(this,tam);
                                x->Caption = "Introduce Tamaño";
                                x->ShowModal();
                        }
                        sc->getArbol()->anidar(cx,cy,aleatorio,tam);
                }
                else if(!sc->getArbol()->empty()){
                        PVD2* p = new PVD2(cx,cy);
                        if(sc->getArbol()->selCuadrado(p))
                                seleccionar = false;
                        delete p; p = NULL;
                }else{
                        seleccionar = false;
                        ShowMessage("No hay nada que seleccionar!");
                }
                GLScene();
        }
        else{
                sc->getArbol()->desanidar();
                GLScene();
        }
}
//---------------------------------------------------------------------------

void __fastcall TGLForm2D::randClick(TObject *Sender)
{
aleatorio = !aleatorio;
if(aleatorio)
        this->rand->Caption = "Regular:NO";
else
        this->rand->Caption = "Regular:SI";
}
//---------------------------------------------------------------------------

void __fastcall TGLForm2D::AnyadirClick(TObject *Sender)
{
        if(!sc->getArbol()->empty()){
                sc->getArbol()->anidar(0,0,aleatorio,0);
                GLScene();
        }else
                ShowMessage("Hacer click para primer nivel!");

}
//---------------------------------------------------------------------------

void __fastcall TGLForm2D::QuitarClick(TObject *Sender)
{
        sc->getArbol()->desanidar();
        GLScene();        
}
//---------------------------------------------------------------------------

void __fastcall TGLForm2D::SelectClick(TObject *Sender)
{
        seleccionar = !seleccionar;
        sc->getArbol()->desSelec();
        GLScene();        
}
//---------------------------------------------------------------------------

void __fastcall TGLForm2D::ZoomInClick(TObject *Sender)
{
        int factor;
        TForm* x = new TFormS(this,factor);
        x->Caption = "Introduce Factor";
        x->ShowModal();
        int pasos;
        TForm* y = new TFormS(this,pasos);
        y->Caption = "Introduce nº de pasos";
        y->ShowModal();
        GLdouble fIncr= (factor-1)/(GLdouble)pasos;
        GLdouble ancho = (xRight-xLeft); GLdouble alto =(yTop-yBot);
        for(int i=0;i<=pasos;i++){
                GLdouble fAux= 1 + fIncr*i;
                GLdouble anchoNew= ancho/fAux; GLdouble altoNew= alto/fAux;
                glMatrixMode(GL_PROJECTION);
                glLoadIdentity();
                gluOrtho2D(centroX-anchoNew/2.0, centroX+anchoNew/2.0,
                centroY-altoNew/2.0, centroY+altoNew/2.0);
                GLScene();
                Sleep(50);
        }
        nuevoAncho = (xRight-xLeft)/factor;
        nuevoAlto = (yTop-yBot)/factor;
        yBot = centroY-(nuevoAlto/2.0);
        yTop = centroY+(nuevoAlto/2.0);
        xRight = centroX+(nuevoAncho/2.0);
        xLeft = centroX-(nuevoAncho/2.0);
        GLScene();
        sc->set(xLeft,xRight,yTop,yBot);
}
//---------------------------------------------------------------------------

void __fastcall TGLForm2D::ZoomOutClick(TObject *Sender)
{
        int factor;
        TForm* x = new TFormS(this,factor);
        x->Caption = "Introduce Factor";
        x->ShowModal();
        int pasos;
        TForm* y = new TFormS(this,pasos);
        y->Caption = "Introduce nº de pasos";
        y->ShowModal();
        GLdouble fIncr= (factor-1)/(GLdouble)pasos;
        GLdouble ancho = (xRight-xLeft); GLdouble alto =(yTop-yBot);
        for(int i=0;i<=pasos;i++){
                GLdouble fAux= 1 + fIncr*i;
                GLdouble anchoNew= ancho*fAux; GLdouble altoNew= alto*fAux;
                glMatrixMode(GL_PROJECTION);
                glLoadIdentity();
                gluOrtho2D(centroX-anchoNew/2.0, centroX+anchoNew/2.0,
                centroY-altoNew/2.0, centroY+altoNew/2.0);
                GLScene();
                Sleep(50);
        }
        nuevoAncho = (xRight-xLeft)*factor;
        nuevoAlto = (yTop-yBot)*factor;
        yBot = centroY-(nuevoAlto/2.0);
        yTop = centroY+(nuevoAlto/2.0);
        xRight = centroX+(nuevoAncho/2.0);
        xLeft = centroX-(nuevoAncho/2.0);
        GLScene();
        sc->set(xLeft,xRight,yTop,yBot);
}

void TGLForm2D::embaldosar(int nCol){
        GLdouble SVAratio= (xRight-xLeft) / (yTop-yBot);
        GLdouble w= (GLdouble)ClientWidth / (GLdouble)nCol;
        //La altura de cada puerto se calcula proporcionalmente
        GLdouble h= w / SVAratio;
        for(GLint c= 0; c<nCol; c++){
                GLdouble currentH = 0;
                while((currentH + h) < ClientHeight){
                        glViewport((GLint)(c*w), (GLint)currentH, (GLint)w, (GLint)h);
                        sc->drawEscena();
                        currentH += h;
                }
        }
}
//---------------------------------------------------------------------------

