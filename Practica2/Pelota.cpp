//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Pelota.h"

//---------------------------------------------------------------------------

Pelota::Pelota(GLdouble x, GLdouble y){
         vector = new PV2D(x,y);
         vector->normalizarV();
         radio = 20;
         centro = new PV2D();
         r = 1.0f; g = 1.0f; b = 0.0f;
         poligono = new list<PV2D*>;
         Lapiz* l = new Lapiz();
         l->moveTo(centro,false);
         l->generaPoligono(poligono,50,radio);
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
        glColor3f(r,g,b);
        if(d)
                glBegin(GL_LINE_LOOP);
        else
        glBegin(GL_POLYGON);
                list<PV2D*>::iterator it;
                it = poligono->begin();
                for(int i = 0; i < 50; i++){
                        PV2D* punto = *it;
                        glVertex2d(punto->getX(),punto->getY());
                        it++;
                }
        glEnd();
        if(d){
                glBegin(GL_LINES);
                        glVertex2d(centro->getX(),centro->getY());
                        PV2D* vr = vector->vectorEscalado(radio);
                        PV2D* cr = centro->sumaPuntoVector(vr);
                        glVertex2d(cr->getX(),cr->getY());
                        delete vr; delete cr;
                glEnd();
        }
}

void Pelota::moverPelota(GLdouble t){
        PV2D* aux = centro;
        PV2D* vEscalado = vector->vectorEscalado(t);
        centro = aux->sumaPuntoVector(vEscalado);// centro = p + t*v
        delete aux;
        list<PV2D*>::iterator it;
        it = poligono->begin();
        for(int i = 0; i < 50; i++){
                PV2D* punto = *it;
                PV2D* puntoNuevo = punto->sumaPuntoVector(vEscalado);
                punto->setX(puntoNuevo->getX());
                punto->setY(puntoNuevo->getY());
                delete puntoNuevo;
                it++;
        }
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
