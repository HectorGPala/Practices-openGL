//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Esfera.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

Esfera::Esfera(TAfin* t,ColorRGB* c,GLdouble radio,GLint nM,GLint nP):ObjetoCuadrico(t,c){
        r = radio;
        numM = nM;
        numP = nP;
}

Esfera::~Esfera(){

}

void Esfera::dibuja(){
        GLUquadricObj* quadratic=gluNewQuadric();
        glColor4f(c->getRed(),c->getGreen(),c->getBlue(),1.0);
        GLdouble mm[16];
        m->getMatrix(mm);
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
                glMultMatrixd(mm);
                gluQuadricDrawStyle(quadratic,GLU_FILL);
                gluSphere(quadratic,r,numM,numP);
        glPopMatrix();
        gluDeleteQuadric(quadratic);
}
