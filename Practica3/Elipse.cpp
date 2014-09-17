//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Elipse.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

Elipse::Elipse(GLdouble centroX,GLdouble centroY,GLdouble w, GLdouble h){
        centro = new PV2D(centroX,centroY);
        this->w = w;
        this->h = h;
        c = new Circulo(1,0,0);
}

Elipse::~Elipse(){
        delete centro;
        delete c;
}

bool Elipse::choque(PV2D* p,PV2D* v,GLdouble &tIn,PV2D*& normalIn){
        GLdouble px = (1/w)*(p->getX()-centro->getX());
        GLdouble py = (1/h)*(p->getY()-centro->getY());
        GLdouble vx = (1/w)*v->getX();
        GLdouble vy = (1/h)*v->getY();
        PV2D* tp = new PV2D(px,py);
        PV2D* tv = new PV2D(vx,vy);
        //tv->normalizarV();
        bool b = c->choque(tp,tv,tIn,normalIn);
        if(normalIn != NULL){//la normal se genera si hay colision
                normalIn->setX(normalIn->getX()/w);
                normalIn->setY(normalIn->getY()/h);
                normalIn->normalizarV();
        }
        delete tp; delete tv;
        return b;
}

void Elipse::drawObstaculo(bool debug,float r,float g,float b){
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glTranslated(centro->getX(),centro->getY(),0);
        glScaled(w,h,1);
        c->drawCircle(debug,r,g,b);
        glPopMatrix();
}

void Elipse::generaCorteza(list<Obstaculo*>* lista,GLdouble r){
        Elipse* e = new Elipse(centro->getX(),centro->getY(),w+r,h+r);
        lista->push_back(e);
}
