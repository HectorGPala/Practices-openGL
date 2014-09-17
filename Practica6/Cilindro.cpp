//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Cilindro.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

Cilindro::Cilindro(TAfin* t,ColorRGB* c,GLdouble rb,GLdouble rb2,GLdouble h,GLint nM,GLint nP):ObjetoCuadrico(t,c){
        rBase = rb;
        rBase2 = rb2;
        this->h = h;
        numM = nM;
        numP = nP;
}

void Cilindro::dibuja(){
        GLUquadricObj* quadratic = gluNewQuadric();
        glColor4f(c->getRed(),c->getGreen(),c->getBlue(),1.0);
        GLdouble mm[16];
        m->getMatrix(mm);
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
                glMultMatrixd(mm);
                gluQuadricDrawStyle(quadratic,GLU_FILL);
                gluCylinder(quadratic,rBase,rBase2,h,numM,numP);
        glPopMatrix();
        gluDeleteQuadric(quadratic);
}
