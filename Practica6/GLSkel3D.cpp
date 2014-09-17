//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "GLSkel3D.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TGLForm3D *GLForm3D;
//---------------------------------------------------------------------------
__fastcall TGLForm3D::TGLForm3D(TComponent* Owner): TForm(Owner) {
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void __fastcall TGLForm3D::FormCreate(TObject *Sender) {
  hdc=GetDC(Handle);
  SetPixelFormatDescriptor();
  hrc=wglCreateContext(hdc);
  if(hrc==NULL) ShowMessage("Error CreateContex");
  if(wglMakeCurrent(hdc, hrc)==false) ShowMessage("Error MakeCurrent");

  crearObjetosEscena();

  glClearColor(0.6,0.7,0.8,1.0);
  glEnable(GL_LIGHTING);

  glEnable(GL_COLOR_MATERIAL);
  glMaterialf(GL_FRONT, GL_SHININESS, 0.1);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_NORMALIZE);
  glShadeModel(GL_SMOOTH);   //Defecto

  //Cámara
  /*eyeX=100.0; eyeY=100.0; eyeZ=100.0;
  lookX=0.0; lookY=0.0; lookZ=0.0;
  upX=0; upY=1; upZ=0;
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(eyeX, eyeY, eyeZ, lookX, lookY, lookZ, upX, upY, upZ);*/

  //Volumen de vista
  N=1; F=1000;
  xRight=10; xLeft=-xRight;
  yTop=10; yBot=-yTop;

  //Ratio del volumen de vista =1
  //ClientWidth=400;
  //ClientHeight=400;
  RatioViewPort=1.0;

  //Luz0
  glEnable(GL_LIGHT0);
  GLfloat LuzDifusa[]={1.0,1.0,1.0,1.0};
  glLightfv(GL_LIGHT0, GL_DIFFUSE, LuzDifusa);
  GLfloat LuzAmbiente[]={0.3,0.3,0.3,1.0};
  glLightfv(GL_LIGHT0, GL_AMBIENT, LuzAmbiente);
  GLfloat PosicionLuz0[]={25.0, 25.0, 0.0, 1.0};
  glLightfv(GL_LIGHT0, GL_POSITION, PosicionLuz0);
}
//---------------------------------------------------------------------------
void __fastcall TGLForm3D::SetPixelFormatDescriptor() {
  PIXELFORMATDESCRIPTOR pfd = {
    	sizeof(PIXELFORMATDESCRIPTOR),
        1,
        PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
        PFD_TYPE_RGBA,
        24,
        0,0,0,0,0,0,
        0,0,
        0,0,0,0,0,
        32,
        0,
        0,
        PFD_MAIN_PLANE,
        0,
        0,0,0 };
  int PixelFormat=ChoosePixelFormat(hdc,&pfd);
  SetPixelFormat(hdc,PixelFormat,&pfd);
}
//---------------------------------------------------------------------------
void __fastcall TGLForm3D::FormResize(TObject *Sender) {
  //Se actualiza puerto de vista y ratio
  if ((ClientHeight<=1.0) || (ClientHeight<=1.0)) {
        ClientWidth=400;
        ClientHeight=400;
        RatioViewPort=1.0;
  }
  else RatioViewPort=(GLfloat)ClientWidth/(GLfloat)ClientHeight;

  glViewport(0,0,ClientWidth,ClientHeight);

  //Se actualiza el volumen de vista
  //para que su ratio coincida con RatioViewPort
  GLfloat RatioVolVista=xRight/yTop;

  if (RatioVolVista>=RatioViewPort) {
     //Aumentamos yTop-yBot
     yTop=xRight/RatioViewPort;
     yBot=-yTop;
     }
  else {
     //Aumentamos xRight-xLeft
     xRight=RatioViewPort*yTop;
     xLeft=-xRight;
     }

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(xLeft, xRight, yBot, yTop, N, F);

  GLScene();
}
//---------------------------------------------------------------------------
void __fastcall TGLForm3D::GLScene() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  //Dibujo de los ejes
  glBegin(GL_LINES);
        glColor4f(1.0, 0.0, 0.0, 1.0);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(10.0, 0.0, 0.0);

        glColor4f(0.0, 1.0, 0.0, 1.0);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.0, 10.0, 0.0);

        glColor4f(0.0, 0.0, 1.0, 1.0);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.0, 0.0, 10.0);
  glEnd();

  //Dibujo de la esfera blanca
  glColor3f(1.0, 1.0, 1.0);
//  gluQuadricDrawStyle(esfera, GLU_FILL);
 // gluSphere(esfera, 3, 30, 30);
  e->dibuja();

  //glFlush();
  SwapBuffers(hdc);
}
//---------------------------------------------------------------------------
void __fastcall TGLForm3D::FormPaint(TObject *Sender) {
  GLScene();
}
//---------------------------------------------------------------------------
void __fastcall TGLForm3D::FormDestroy(TObject *Sender) {
  liberarObjetosEscena();
  ReleaseDC(Handle,hdc);
  wglMakeCurrent(NULL,NULL);
  wglDeleteContext(hrc);
}
//---------------------------------------------------------------------------
void TGLForm3D::crearObjetosEscena() {
  PV3D* eye = new PV3D(100,100,100,0);
  PV3D* look = new PV3D(0,0,0,0);
  PV3D* up = new PV3D(0,1,0,0);
  c = new Camara(eye,look,up);
  e = new Escena();
  //esfera=gluNewQuadric();
}
//---------------------------------------------------------------------------
void TGLForm3D::liberarObjetosEscena() {
  //gluDeleteQuadric(esfera);
  delete c;
  delete e;
}

void __fastcall TGLForm3D::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        Caption = Key;
        switch(Key){
                case 65://a
                        e->girar(10,0,0,1);
                        break;
                case 90://z
                        e->girar(-10,0,0,1);
                        break;
                case 37://left
                        e->girar(10,1,0,0);
                        break;
                case 39://right
                        e->girar(-10,1,0,0);
                        break;
                case 38://up
                        e->girar(10,0,1,0);
                        break;
                case 40://down
                        e->girar(-10,0,1,0);
                        break;
                case 85://u
                        c->roll(-10);
                        break;
                case 73://i
                        c->roll(10);
                        break;
                case 74://j
                        c->yaw(2);
                        break;
                case 75://k
                        c->yaw(-2);
                        break;
                case 78://n
                        c->pitch(-2);
                        break;
                case 77://m
                        c->pitch(2);
                        break;
                case 88://x
                        c->desplazar(0,1,0);
                        break;
                case 83://s
                        c->desplazar(0,-1,0);
                        break;
                case 87://w
                        c->desplazar(-1,0,0);
                        break;
                case 81://q
                        c->desplazar(1,0,0);
                        break;
                case 89://y
                        c->desplazar(0,0,1);
                        break;
                case 84://t
                        c->desplazar(0,0,-1);
                        break;
                case 69://e
                        c->recorridoEje(-5,0,0);
                        break;
                case 82://r
                        c->recorridoEje(5,0,0);
                        break;
                case 68://d
                        c->recorridoEje(0,5,0);
                        break;
                case 70://f
                        c->recorridoEje(0,-5,0);
                        break;
                case 67://c
                        c->recorridoEje(0,0,5);
                        break;
                case 86://v
                        c->recorridoEje(0,0,-5);
                        break;
                case 49://1
                        c->giraX(5);
                        break;
                case 50://2
                        c->giraY(5);
                        break;
                case 51://3
                        c->giraZ(5);
                        break;
                case 52://4
                        c->viewLateral();
                        break;
                case 53://5
                        c->viewFrontal();
                        break;
                case 54://6
                        c->viewCenital();
                        break;
                case 55://7
                        c->viewEsquina(new PV3D(100,100,100,0));
                        break;
                case 48://ejeX desplaza 0
                        e->transladar(1,0,0);
                        break;
                case 219://ejeX desplaza ?
                        e->transladar(-1,0,0);
                        break;
                case 221://ejeY desplaza ¿
                        e->transladar(0,1,0);
                        break;
                case 186://ejeY desplaza [
                        e->transladar(0,-1,0);
                        break;
                case 222://ejeZ desplaza {
                        e->transladar(0,0,1);
                        break;
                case 191://ejeZ desplaza }
                        e->transladar(0,0,-1);
                        break;
                case 189://-
                        e->escalar(1/1.1,1/1.1,1/1.1);
                        break;
                case 187://+
                        e->escalar(1.1,1.1,1.1);
                        break;
                case 79://o
                        c->configProjection(2);
                        break;
                case 80://p
                        c->configProjection(1);
                        break;
                case 76://l
                        c->configProjection(0);
                        break;
        }
        GLScene();
}
//---------------------------------------------------------------------------

