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
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    //inicialización del volumen de vista
    xRight=300.0; xLeft=-xRight;
    yTop=xRight; yBot=-yTop;
    //Radio del volumen de vista == 1

    //inicialización del puerto de vista
    ClientWidth=600;
    ClientHeight=600;
    RatioViewPort=1.0;
    pasos = true;
    debug = false;
    corteza = false;
    Corteza1->Caption = "Corteza: NO";
    h = new Habitacion();
    creaObstaculos();
    Timer1->Enabled = false;

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

        glColor3f(1.0f, 1.0f, 1.0f);
        if(h != NULL)
                h->drawHabitacion(debug);
        glBegin(GL_POINTS);
                glVertex2i(0,0);
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
    delete h; h = NULL;
}
//---------------------------------------------------------------------------


void __fastcall TGLForm2D::DebugClick(TObject *Sender)
{
        Timer1->Enabled = !Timer1->Enabled;
        pasos = !pasos;
        Step->Enabled = pasos;
        GLScene();
}
//---------------------------------------------------------------------------

void __fastcall TGLForm2D::StepClick(TObject *Sender)
{
        h->avanzaPelota();
        GLScene();
}
//---------------------------------------------------------------------------

void __fastcall TGLForm2D::Timer1Timer(TObject *Sender)
{
       h->avanzaPelota();
       GLScene();        
}
//---------------------------------------------------------------------------

void TGLForm2D::creaObstaculos(){
        creaParedes();
        creaTriangulos();
        creaCirculos();
}

void TGLForm2D::creaParedes(){
        //margen superior
        int n = 100;
        PV2D* p1 = new PV2D(xLeft-n,yTop-10);
        PV2D* p2 = new PV2D(xRight+n,yTop-10);
        PV2D* p3 = new PV2D(xRight+n,yTop+n);
        Obstaculo* ob = new Triangulo(p1,p2,p3);
        h->addObstaculo(ob);
        //margen inferior
        p1 = new PV2D(xRight+n,yBot+10);
        p2 = new PV2D(xLeft-n,yBot+10);
        p3 = new PV2D(xRight+n,yBot-n);
        ob = new Triangulo(p1,p2,p3);
        h->addObstaculo(ob);
        //margen izq
        p1 = new PV2D(xLeft+10,yBot-n);
        p2 = new PV2D(xLeft+10,yTop+n);
        p3 = new PV2D(xLeft-n,yTop+n);
        ob = new Triangulo(p1,p2,p3);
        h->addObstaculo(ob);
        //margen der
        p1 = new PV2D(xRight-10,yTop+n);
        p2 = new PV2D(xRight-10,yBot-n);
        p3 = new PV2D(xRight+n,yTop+n);
        ob = new Triangulo(p1,p2,p3);
        h->addObstaculo(ob);
}

//---------------------------------------------------------------------------

void TGLForm2D::creaTriangulos(){
        PV2D* p1 = new PV2D(117,-124);
        PV2D* p2 = new PV2D(163,-124);
        PV2D* p3 = new PV2D(140,-50);
        Obstaculo* ob = new Triangulo(p1,p2,p3);
        h->addObstaculo(ob);
        p1 = new PV2D(200,100);
        p2 = new PV2D(200,200);
        p3 = new PV2D(100,200);
        ob = new Triangulo(p1,p2,p3);
        h->addObstaculo(ob);
        p1 = new PV2D(-200,50);
        p2 = new PV2D(-50,150);
        p3 = new PV2D(0,200);
        ob = new Triangulo(p1,p2,p3);
        h->addObstaculo(ob);
}

//---------------------------------------------------------------------------

void TGLForm2D::creaCirculos(){
        Obstaculo* ob = new Circulo(60,-100,-100);
        h->addObstaculo(ob);
        ob = new Circulo(20,-213,145);
        h->addObstaculo(ob);
        ob = new Circulo(10,213,-175);
        h->addObstaculo(ob);
        ob = new Circulo(10,150,100);
        h->addObstaculo(ob);
}

//---------------------------------------------------------------------------

void __fastcall TGLForm2D::Debug1Click(TObject *Sender)
{
        debug = !debug;
        GLScene();
}
//---------------------------------------------------------------------------

void __fastcall TGLForm2D::Corteza1Click(TObject *Sender)
{
        //Timer1->Enabled = false;
        //pasos = true;
        delete h;
        h = new Habitacion();
        creaObstaculos();
        Step->Enabled = pasos;
        if(!corteza){
                corteza = true;
                h->generarCortezas();
                Corteza1->Caption = "Corteza : SI";
        }
        else{
                corteza = false;
                h->quitarCortezas();
                Corteza1->Caption = "Corteza : NO";
        }
        GLScene();
}
//---------------------------------------------------------------------------

