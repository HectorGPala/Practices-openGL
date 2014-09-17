//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PV2D.h"

//---------------------------------------------------------------------------

void PV2D::drawPV2D(){
        glBegin(GL_POINTS);
                glVertex2d(x,y);
        glEnd();
}

GLdouble PV2D::distancia(PV2D *p){
        return sqrt(pow(x-p->x,2.0)+pow(y-p->y,2.0));
}

//operaciones nuevas

PV2D* PV2D::dameVector(PV2D* q){//devuelve vector thisQ
        GLdouble px,py;
        px = q->x - x;
        py = q->y - y;
        return new PV2D(px,py);
}

PV2D* PV2D::sumaPuntoVector(PV2D* v){
        GLdouble px,py;
        px = x + v->x;
        py = y + v->y;
        return new PV2D(px,py);
}

PV2D* PV2D::sumaVectores(PV2D* w){
        GLdouble px,py;
        px = x + w->x;
        py = y + w->y;
        return new PV2D(px,py);
}

PV2D* PV2D::restaVectores(PV2D* w){
        GLdouble px,py;
        px = x - w->x;
        py = y - w->y;
        return new PV2D(px,py);
}

PV2D* PV2D::vectorEscalado(GLdouble k){
        return new PV2D(k*x,k*y);
}

GLdouble PV2D::moduloV(){
        return sqrt(pow(x,2.0)+pow(y,2.0));
}

void PV2D::normalizarV(){
        GLdouble mod = moduloV();
        x = (1/mod)*x;
        y = (1/mod)*y;
}

GLdouble PV2D::prodEscalar(PV2D* w){
        return (x*w->x)+(y*w->y);
}

PV2D* PV2D::normalIzq(){
           return new PV2D(-y,x);
}

PV2D* PV2D::normalDer(){
        return new PV2D(y,-x);
}

PV2D* PV2D::refleja(PV2D* n){
        PV2D* factor2 = n->vectorEscalado(2*this->prodEscalar(n));
        PV2D* r = this->restaVectores(factor2);
        delete factor2;
        r->normalizarV();
        return r;
}

#pragma package(smart_init)
