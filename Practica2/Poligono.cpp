//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Poligono.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

Poligono::Poligono(int n,PV2D* c,GLdouble r){
        n_lados = n;
        centro = new PV2D(c);
        radio = r;
        lado = new list<PV2D*>;
        normales = new list<PV2D*>;
        Lapiz* l = new Lapiz();
        l->moveTo(centro,false);
        l->generaPoligono(lado,n,r);
        delete l; l = NULL;
        
}

Poligono::~Poligono(){
        delete centro; centro = NULL;
        //delete mov; mov = NULL;
        while(!lado->empty()){
                PV2D* punto = lado->back();
                lado->pop_back();
                delete punto; punto = NULL;
        }
        delete lado; lado = NULL;
        delete normales; normales = NULL;
}

bool Poligono::choque(PV2D* p,PV2D* v,GLdouble &tIn,PV2D*& normalIn){
        return false;
}

void Poligono::drawObstaculo(bool debug,float r,float g,float b){
        glBegin(GL_POLYGON);
                list<PV2D*>::iterator it;
                it = lado->begin();
                for(int i = 0; i < n_lados; i++){
                        PV2D* punto = *it;
                        glVertex2d(punto->getX(),punto->getY());
                        it++;
                }
        glEnd();
}

void Poligono::generaCorteza(list<Obstaculo*>* lista,GLdouble r){
        
}

