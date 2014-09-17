//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PVD2.h"

//---------------------------------------------------------------------------

void PVD2::drawPVD2(){
        glBegin(GL_POINTS);
                glVertex2d(x,y);
        glEnd();
}

GLdouble PVD2::distancia(PVD2 *p){
        return sqrt(pow(x-p->x,2.0)+pow(y-p->y,2.0));
}

#pragma package(smart_init)
