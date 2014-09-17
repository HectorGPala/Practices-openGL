//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Habitacion.h"

//---------------------------------------------------------------------------

Habitacion::Habitacion(){
        randomize();
        int x = random(10)+1;
        int y = random(10)+1;
        x = pow(-1,x)*x;
        y = pow(-1,y)*y;
        p = new Pelota(x,y);
        listaObs = new list<Obstaculo*>;
        listaCor = listaObs;

}

Habitacion::~Habitacion(){
        delete p; p = NULL;
        if(listaCor != listaObs){
                while(!listaCor->empty()){
                        Obstaculo* ob = listaCor->back();
                        listaCor->pop_back();
                        delete ob; ob = NULL;
                }
                delete listaCor; listaCor = NULL;
        }
        while(!listaObs->empty()){
                Obstaculo* ob = listaObs->back();
                listaObs->pop_back();
                delete ob; ob = NULL;
        }
        delete listaObs; listaObs = NULL;
}

void Habitacion::addObstaculo(Obstaculo* ob){
        listaObs->push_back(ob);
}

void Habitacion::avanzaPelota(){
        GLdouble v = 3.0;
        PV2D* centro = p->getCentro();
        PV2D* vector = p->getVector();
        list<Obstaculo*>::iterator it;
        it = listaCor->begin();
        int n = listaCor->size();
        PV2D *normalElegida;
        normalElegida = NULL;
        bool existe;
        GLdouble tHit,tHitElegida;
        tHitElegida = v;
        for(int i = 0; i < n; i++){
                PV2D* normal = NULL;
                Obstaculo* ob = *it;
                existe = ob->choque(centro,vector,tHit,normal);
                if(existe && tHit > 0 && tHit <= tHitElegida){
                        if(normalElegida != NULL)
                                delete normalElegida;
                        if(tHit == tHitElegida)//golpea en dos objetos a la vez
                                normalElegida = new PV2D(vector);
                        else
                                normalElegida = new PV2D(normal);
                        tHitElegida = tHit;
                }
                if(normal != NULL)
                        delete normal;
                it++;
        }
        p->moverPelota(tHitElegida);
        if(tHitElegida < v){//no puede avanzar todo
                PV2D* nuevaDir = vector->refleja(normalElegida);
                p->setVector(nuevaDir);
        }
        if(normalElegida != NULL)
                delete normalElegida;
}
void Habitacion::drawHabitacion(bool debug){
        list<Obstaculo*>::iterator it;
        int n;
        if(debug){
                it = listaCor->begin();
                n = listaCor->size();
                for(int i = 0; i < n; i++){
                        Obstaculo* ob = *it;
                        ob->drawObstaculo(debug,1,1,1);
                        it++;
                }
        }
        it = listaObs->begin();
        n = listaObs->size();
        for(int i = 0; i < n; i++){
                Obstaculo* ob = *it;
                ob->drawObstaculo(debug,1,1,1);
                it++;
        }
        p->drawPelota(debug);
}

void Habitacion::generarCortezas(){
        list<Obstaculo*>::iterator it;
        it = listaObs->begin();
        int n = listaObs->size();
        GLdouble r = p->getRadio();
        listaCor = new list<Obstaculo*>;
        for(int i = 0; i < n; i++){
                Obstaculo* ob = *it;
                ob->generaCorteza(listaCor,r);
                it++;
        }
}

void Habitacion::quitarCortezas(){
        if(listaCor != listaObs){
                while(!listaCor->empty()){
                        Obstaculo* ob = listaCor->back();
                        listaCor->pop_back();
                        delete ob; ob = NULL;
                }
                delete listaCor; listaCor = NULL;
        }
        listaCor = listaObs;
}

#pragma package(smart_init)
