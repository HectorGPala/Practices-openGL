//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Pelota.h"

//---------------------------------------------------------------------------

Pelota::Pelota(GLdouble x, GLdouble y){
         vector = new PV2D(x,y);
         vector->normalizarV();
         radio = 20;//problemas con cortezas!!
         alfa = 0;
         incremento = 1;
         centro = new PV2D();
         r = 1.0f; g = 1.0f; b = 0.0f;
         poligono = new list<PV2D*>;
         Lapiz* l = new Lapiz();
         l->moveTo(centro,false);
         l->generaPoligono(poligono,50,1);
         delete l; l = NULL;
}

Pelota::~Pelota(){
        delete vector; vector = NULL;
        delete centro; centro = NULL;
        while(!poligono->empty()){
                PV2D* punto = poligono->back();
                poligono->pop_back();
                delete punto; punto = NULL;
        }
        delete poligono; poligono = NULL;

}
void Pelota::drawPelota(bool d){
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glTranslated(centro->getX(),centro->getY(),0);
        glScaled(20,20,1);
        glColor3f(r,g,b);
        glBegin(GL_LINE_LOOP);
                list<PV2D*>::iterator it;
                it = poligono->begin();
                for(int i = 0; i < 50; i++){
                        PV2D* punto = *it;
                        glVertex2d(punto->getX(),punto->getY());
                        it++;
                }
        glEnd();
        glLoadIdentity();
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glTranslated(centro->getX(),centro->getY(),0);
        glRotated(alfa,0,0,1);
        glScaled(20,20,1);
        glBegin(GL_LINES);
                glVertex2d(0,0);
                glVertex2d(1,0);
        glEnd();
        glPopMatrix();
}

void Pelota::moverPelota(GLdouble t,GLdouble v){
        if(t < v)
                incremento = -1*incremento;//invierte el incremento
        PV2D* aux = centro;
        PV2D* vEscalado = vector->vectorEscalado(t);
        centro = aux->sumaPuntoVector(vEscalado);// centro = p + t*v
        delete aux;
        alfa += incremento*10;
        delete vEscalado;
}

PV2D* Pelota::getVector(){
        return vector;
}

PV2D* Pelota::getCentro(){
        return centro;
}

void Pelota::setVector(PV2D* v){
        delete vector;
        vector = v;
        vector->normalizarV();
}

#pragma package(smart_init)
