//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Circulo.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

Circulo::Circulo(GLdouble r,GLdouble x,GLdouble y){
            radio = r;
            r2 = pow(radio,2);
            centro = new PV2D(x,y);
            poligono = new list<PV2D*>;
            Lapiz* l = new Lapiz();
            l->moveTo(centro,false);
            l->generaPoligono(poligono,TAM,r);
            delete l; l = NULL;
}

Circulo::~Circulo(){
        delete centro; centro = NULL;
        while(!poligono->empty()){
                PV2D* punto = poligono->back();
                poligono->pop_back();
                delete punto; punto = NULL;
        }
        delete poligono; poligono = NULL;
}

void Circulo::drawCircle(bool debug,float r,float g,float b){
        if(debug)
                glBegin(GL_LINE_LOOP);
        else
        glBegin(GL_POLYGON);
                list<PV2D*>::iterator it;
                it = poligono->begin();
                for(int i = 0; i < TAM; i++){
                        PV2D* punto = *it;
                        glVertex2d(punto->getX(),punto->getY());
                        it++;
                }
        glEnd();
        if(debug){
                glBegin(GL_POINTS);
                        glVertex2d(centro->getX(),centro->getY());
                glEnd();
        }
}

PV2D* Circulo::getCentro(){
        return centro;
}

bool Circulo::choque(PV2D* p,PV2D* v,GLdouble &tIn,PV2D*& normalIn){
        GLdouble A = v->prodEscalar(v);
        PV2D* cp = centro->dameVector(p);
        GLdouble B = 2*cp->prodEscalar(v);
        GLdouble C = cp->prodEscalar(cp) - r2;
        GLdouble discr = pow(B,2) - 4*A*C;
        delete cp;
        if(discr < 0)
                return false;
        else{
                GLdouble t1 = (-B + sqrt(discr))/(2*A);
                GLdouble t2 = (-B - sqrt(discr))/(2*A);
                tIn = min(t1,t2);
                PV2D* tv = v->vectorEscalado(tIn);
                PV2D* puntoColision = p->sumaPuntoVector(tv);
                PV2D* normal = centro->dameVector(puntoColision);
                normal->normalizarV();
                normalIn = normal;
                delete tv; delete puntoColision;
                return true;
        }
}

void Circulo::drawObstaculo(bool debug,float r,float g,float b){
        drawCircle(debug,r,g,b);
}

void Circulo::generaCorteza(list<Obstaculo*>* lista,GLdouble r){
        Obstaculo* c = new Circulo(r+radio,centro->getX(),centro->getY());
        lista->push_back(c);
}


