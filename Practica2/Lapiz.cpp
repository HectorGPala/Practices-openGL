//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Lapiz.h"

//---------------------------------------------------------------------------

Lapiz::Lapiz(){
        pos = new PV2D();
        dir = 0;
}

Lapiz::Lapiz(PV2D *p,GLdouble d){
        pos = new PV2D(p);
        dir = d;
}

Lapiz::~Lapiz(){
        delete pos;
        pos = NULL;
}

void Lapiz::moveTo(PV2D *p,bool draw){
        //this->lookAt(p);
        if(draw){
                glBegin(GL_LINES);
                        glVertex2d(pos->getX(),pos->getY());
                        glVertex2d(p->getX(),p->getY());
                glEnd();
        }
        pos->setX(p->getX());
        pos->setY(p->getY());
}

void Lapiz::turnTo(GLdouble a){
        dir = a;
}

void Lapiz::turn(GLdouble a){
        dir += a;
}

void Lapiz::forward(GLdouble dist, bool draw){
        GLdouble x = pos->getX()+dist*cos(dir);
        GLdouble y = pos->getY()+dist*sin(dir);
        if(draw){
                PV2D* punto = new PV2D(x,y);
                glBegin(GL_LINES);
                        glVertex2d(pos->getX(),pos->getY());
                        glVertex2d(punto->getX(),punto->getY());
                glEnd();
                delete punto; punto = NULL;
        }
        pos->setX(x);
        pos->setY(y);
}

void Lapiz::lookAt(PV2D *p){
        turnTo(0);//revisar
        turn(atan2(p->getY()-pos->getY(),p->getX()-pos->getX()));
}

PV2D* Lapiz::getPos(){
       return pos;
}

GLdouble Lapiz::getDir(){
        return dir;
}

void Lapiz::generaPoligono(list<PV2D*>* lados, int n,GLdouble r){
        GLdouble alfa = (2*M_PI) / n;
        GLdouble beta = (M_PI - alfa) / 2.0;
        this->forward(r,false);
        lados->push_back(new PV2D(getPos()));
        turn(M_PI - beta);//orientar hacia dir primer lado
        GLdouble l = 2*cos(beta)*r;
        for(int i = 1;i < n;i++){
                this->forward(l,false);
                lados->push_back(new PV2D(getPos()));
                turn(alfa);
        }
}


#pragma package(smart_init)
