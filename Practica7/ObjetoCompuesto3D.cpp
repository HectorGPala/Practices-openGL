//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ObjetoCompuesto3D.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

ObjetoCompuesto3D::ObjetoCompuesto3D(int n,TAfin* t,ColorRGB* c):Objeto3D(t,c){
        numHijos = n;
        actual = 0;
        hijos = new Objeto3D*[numHijos];
}

ObjetoCompuesto3D::~ObjetoCompuesto3D(){
        for(int i = 0; i < actual;i++)
                delete hijos[i];
        delete[] hijos;
}

void ObjetoCompuesto3D::addObjeto3D(Objeto3D* o){
        if(actual < numHijos){
                hijos[actual] = o;
                actual++;
        }
}

void ObjetoCompuesto3D::dibuja(){
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
                GLdouble mm[16];
                m->getMatrix(mm);
                glMultMatrixd(mm);
                for (int i=0; i<actual; i++)
                        hijos[i]->dibuja();
        glPopMatrix();
}

void ObjetoCompuesto3D::trasladar(GLdouble x, GLdouble y, GLdouble z){
        m->trasladar(x,y,z);
}

void ObjetoCompuesto3D::girar(GLdouble alfa, GLdouble x, GLdouble y, GLdouble z){
        m->girar(alfa,x,y,z);
}

void ObjetoCompuesto3D::escalar(GLdouble x, GLdouble y, GLdouble z){
        m->escalar(x,y,z);
}
