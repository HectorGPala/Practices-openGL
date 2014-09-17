//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Lampara.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

Lampara::Lampara():ObjetoCompuesto3D(3,new TAfin(),new ColorRGB(0,0,0)){
        alfa = 45;
        b = 4;
        posX = 2.5;
        posY = 15;
        posZ = 5;
        TAfin* t = new TAfin();
        t->girar(90,1,0,0);
        //t->trasladar(0,10,0);
        Cilindro* cable = new Cilindro(t,new ColorRGB(0,0,0),0.1,0.1,5,10,10);
        addObjeto3D(cable);
        TAfin* t2 = new TAfin();
        t2->girar(90,1,0,0);
        t2->trasladar(0,0,5);
        Cilindro* cuerpo = new Cilindro(t2,new ColorRGB(1,0,0),0.1,2,3,10,10);
        addObjeto3D(cuerpo);
        TAfin* t3 = new TAfin();
        t3->girar(90,1,0,0);
        //t3->trasladar(0,10,0);
        Disco* tapa = new Disco(t3,new ColorRGB(0,0,0),0.0,0.1,10,10);
        addObjeto3D(tapa);
        trasladar(2.5,20,5);
        //girar(90,1,0,0);
        GLfloat LuzDifusa[] = {1,1,1,1.0};
        glLightfv(GL_LIGHT1,GL_DIFFUSE,LuzDifusa);
        GLfloat LuzAmbiente[] = {0,0,0,1.0};
        glLightfv(GL_LIGHT1,GL_AMBIENT,LuzAmbiente);
        GLfloat especular[]={1,1,1,1.0};
        glLightfv(GL_LIGHT1, GL_SPECULAR, especular);
        GLfloat PosicionLuz[]={posX,posY,posZ,1.0};
        glLightfv(GL_LIGHT1, GL_POSITION, PosicionLuz);
        //glLightf(GL_LIGHT1, GL_SPOT_CUTOFF,alfa);
        //glLightf(GL_LIGHT1, GL_SPOT_EXPONENT,b);
        //GLfloat dir[]={0.0,0.0,-1.0,1.0};
        //glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, dir);
        glDisable(GL_LIGHT1);
}

void Lampara::escalaLampara(GLdouble x, GLdouble y, GLdouble z){
        escalar(x,y,z);
        alfa /= y;
        b *= y;
        posY /= y;
        GLfloat PosicionLuz[]={posX,posY,posZ,1.0};
        glLightfv(GL_LIGHT1, GL_POSITION, PosicionLuz);
        //glLightf(GL_LIGHT1, GL_SPOT_CUTOFF,alfa);
        //glLightf(GL_LIGHT1, GL_SPOT_EXPONENT,b);
        //GLfloat dir[]={0.0,-1.0,0.0};
        //glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, dir);
        //glEnable(GL_LIGHT1);*/
}
