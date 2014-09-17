//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Lapiz.h"

//---------------------------------------------------------------------------

Lapiz::Lapiz(){
        pos = new PVD2();
        dir = 0;
}

Lapiz::Lapiz(PVD2 *p,GLdouble d){
        pos = new PVD2(p);
        dir = d;
}

Lapiz::~Lapiz(){
        delete pos;
        pos = NULL;
}

void Lapiz::moveTo(PVD2 *p,bool draw){
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
                PVD2* punto = new PVD2(x,y);
                glBegin(GL_LINES);
                        glVertex2d(pos->getX(),pos->getY());
                        glVertex2d(punto->getX(),punto->getY());
                glEnd();
                delete punto; punto = NULL;
        }
        pos->setX(x);
        pos->setY(y);
}

void Lapiz::lookAt(PVD2 *p){
        turnTo(0);//revisar
        turn(atan2(p->getY()-pos->getY(),p->getX()-pos->getX()));
}

PVD2* Lapiz::getPos(){
       return pos;
}

GLdouble Lapiz::getDir(){
        return dir;
}


#pragma package(smart_init)
