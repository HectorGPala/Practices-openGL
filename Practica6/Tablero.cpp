//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Tablero.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

Tablero::Tablero(GLdouble l,GLdouble a,GLdouble g,ColorRGB* c,TAfin* t):Malla(8,6,6,new PV3D*[8],new PV3D*[6],new Cara*[6],c,t){
        vertices[0] = new PV3D(0,0,l,1);
        vertices[1] = new PV3D(a,0,l,1);
        vertices[2] = new PV3D(a,g,l,1);
        vertices[3] = new PV3D(0,g,l,1);
        vertices[4] = new PV3D(0,0,0,1);
        vertices[5] = new PV3D(a,0,0,1);
        vertices[6] = new PV3D(a,g,0,1);
        vertices[7] = new PV3D(0,g,0,1);

        int i = 0;
        VerticeNormal** v = new VerticeNormal*[4];
        v[0] = new VerticeNormal(0,i);
        v[1] = new VerticeNormal(1,i);
        v[2] = new VerticeNormal(2,i);
        v[3] = new VerticeNormal(3,i);
        caras[i] = new Cara(4,v);
        normales[i] = calculoNormalNewell(caras[i]);

        i++;
        v = new VerticeNormal*[4];
        v[0] = new VerticeNormal(1,i);
        v[1] = new VerticeNormal(5,i);
        v[2] = new VerticeNormal(6,i);
        v[3] = new VerticeNormal(2,i);
        caras[i] = new Cara(4,v);
        normales[i] = calculoNormalNewell(caras[i]);

        i++;
        v = new VerticeNormal*[4];
        v[0] = new VerticeNormal(2,i);
        v[1] = new VerticeNormal(6,i);
        v[2] = new VerticeNormal(7,i);
        v[3] = new VerticeNormal(3,i);
        caras[i] = new Cara(4,v);
        normales[i] = calculoNormalNewell(caras[i]);

        i++;
        v = new VerticeNormal*[4];
        v[0] = new VerticeNormal(3,i);
        v[1] = new VerticeNormal(7,i);
        v[2] = new VerticeNormal(4,i);
        v[3] = new VerticeNormal(0,i);
        caras[i] = new Cara(4,v);
        normales[i] = calculoNormalNewell(caras[i]);

        i++;
        v = new VerticeNormal*[4];
        v[0] = new VerticeNormal(4,i);
        v[1] = new VerticeNormal(7,i);
        v[2] = new VerticeNormal(6,i);
        v[3] = new VerticeNormal(5,i);
        caras[i] = new Cara(4,v);
        normales[i] = calculoNormalNewell(caras[i]);

        i++;
        v = new VerticeNormal*[4];
        v[0] = new VerticeNormal(5,i);
        v[1] = new VerticeNormal(1,i);
        v[2] = new VerticeNormal(0,i);
        v[3] = new VerticeNormal(4,i);
        caras[i] = new Cara(4,v);
        normales[i] = calculoNormalNewell(caras[i]);

        i++;
}

void Tablero::trasladar(GLdouble x, GLdouble y, GLdouble z){
        m->trasladar(x,y,z);
}

void Tablero::girar(GLdouble alfa, GLdouble x, GLdouble y, GLdouble z){
        m->girar(alfa,x,y,z);
}

void Tablero::escalar(GLdouble x, GLdouble y, GLdouble z){
        m->escalar(x,y,z);
}
