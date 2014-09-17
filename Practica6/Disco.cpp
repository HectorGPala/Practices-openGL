//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Disco.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

Disco::Disco(TAfin* t,ColorRGB* c,GLdouble ri,GLdouble re,GLdouble nL,GLdouble nR):ObjetoCuadrico(t,c){
        rInt = ri;
        rExt = re;
        nLados = nL;
        nRings = nR;
}

Disco::~Disco(){

}

void Disco::dibuja(){
        GLUquadricObj* quadratic=gluNewQuadric();
        glColor4f(c->getRed(),c->getGreen(),c->getBlue(),1.0);
        GLdouble mm[16];
        m->getMatrix(mm);
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
                glMultMatrixd(mm);
                gluQuadricDrawStyle(quadratic,GLU_FILL);
                gluDisk(quadratic,rInt,rExt,nLados,nRings);
        glPopMatrix();
        gluDeleteQuadric(quadratic);
}
