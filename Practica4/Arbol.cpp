//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Arbol.h"

//---------------------------------------------------------------------------

Arbol::Arbol(){
        arb = new list< list<Cuadrado*>* >;
        l = new Lapiz();
        rojo = 0.5; verde = 0.3; azul = 0.0;
        selec = NULL;
}

Arbol::~Arbol(){
        while(!arb->empty()){
                list<Cuadrado*>* ultima = arb->back();
                arb->pop_back();
                while(!ultima->empty()){
                        Cuadrado* c = ultima->back();
                        delete c; c = NULL;
                        ultima->pop_back();
                }
                delete ultima; ultima = NULL;
        }
        delete arb; arb = NULL;
        delete l; l = NULL;
}

void Arbol::anidar(GLdouble x,GLdouble y,bool random,int tam){
        if(arb->empty()){
                PVD2* centro = new PVD2(x,y);
                Cuadrado* c = new Cuadrado(centro,tam);
                delete centro; centro = NULL;
                list<Cuadrado*>* primera = new list<Cuadrado*>;
                primera->push_back(c);
                arb->push_back(primera);
                c->setColor(rojo,verde,azul);
        }
        else{
        double alfa = M_PI/4;
        /*if(random){
                alfa = (rand() % 100)/100.0;
                alfa = (M_PI/2)*alfa;
        }*/
        list<Cuadrado*>* gen = arb->back();//ultimo elemento
        list<Cuadrado*>::iterator it;
        it = gen->begin();
        list<Cuadrado*>* nueva = new list<Cuadrado*>;
        rojo -= 0.02; verde += 0.1;
        while(it != gen->end()){
                Cuadrado* c = *it;
                Cuadrado* neo1 = new Cuadrado();//izq
                l->moveTo(c->getIesima(3),false);
                l->lookAt(c->getIesima(2));
                if(random){
                        alfa = (rand() % 100)/100.0;
                        alfa = (M_PI/2)*alfa;
                }
                l->turn(alfa);
                neo1->setIesima(0,c->getIesima(3));
                l->forward(c->getLado()*sqrt(2)/2,false);
                PVD2* pos = l->getPos();
                neo1->setIesima(1,pos);
                l->turn(M_PI/2);//90º
                l->forward(c->getLado()*sqrt(2)/2,false);
                pos = l->getPos();
                neo1->setIesima(2,pos);
                l->turn(M_PI/2);
                l->forward(c->getLado()*sqrt(2)/2,false);
                pos = l->getPos();
                neo1->setIesima(3,pos);
                neo1->setColor(rojo,verde,azul);
                nueva->push_back(neo1);
                Cuadrado* neo2 = new Cuadrado();//derecho
                l->moveTo(c->getIesima(2),false);
                l->lookAt(c->getIesima(3));
                if(random){
                        alfa = (rand() % 100)/100.0;
                        alfa = (M_PI/2)*alfa;
                }
                l->turn(-1*alfa);
                neo2->setIesima(1,c->getIesima(2));
                l->forward(c->getLado()*sqrt(2)/2,false);
                pos = l->getPos();
                neo2->setIesima(0,pos);
                l->turn(-1*M_PI/2);//90º
                l->forward(c->getLado()*sqrt(2)/2,false);
                pos = l->getPos();
                neo2->setIesima(3,pos);
                l->turn(-1*M_PI/2);
                l->forward(c->getLado()*sqrt(2)/2,false);
                pos = l->getPos();
                neo2->setIesima(2,pos);
                neo2->setColor(rojo,verde,azul);
                nueva->push_back(neo2);
                it++;

        }
        arb->push_back(nueva);
        }
}

void Arbol::desanidar(){
        if(!arb->empty()){
                rojo += 0.02; verde -= 0.1;
                list<Cuadrado*>* ultima = arb->back();
                while(!ultima->empty()){
                        Cuadrado* c = ultima->back();
                        if(c == selec)
                                selec = NULL;
                        delete c; c = NULL;
                        ultima->pop_back();
                }
                delete ultima; ultima = NULL;
                arb->pop_back();
        }
}

void Arbol::drawArbol(){
          if(!arb->empty()){
                list<Cuadrado*>* actual;
                list< list<Cuadrado*>* >::iterator it;
                list<Cuadrado*>::iterator it2;
                it = arb->begin();
                while(it != arb->end()){
                        actual = *it;
                        it2 = actual->begin();
                        while(it2 != actual->end()){
                                Cuadrado* c = *it2;
                                c->drawCuadrado();
                                it2++;
                        }
                        it++;
                }
          }
}

bool Arbol::empty(){
        return arb->empty();
}

bool Arbol::selCuadrado(PVD2* p){
        if(!arb->empty()){
                list<Cuadrado*>* actual;
                list< list<Cuadrado*>* >::iterator it;
                list<Cuadrado*>::iterator it2;
                it = arb->begin();
                while(it != arb->end()){
                        actual = *it;
                        it2 = actual->begin();
                        while(it2 != actual->end()){
                                Cuadrado* c = *it2;
                                if(c->seleccionado(p)){
                                        if(selec != NULL)
                                               selec->deseleccionar();
                                        selec = c;
                                        selec->seleccionar();
                                        return true;
                                }
                                it2++;
                        }
                        it++;
                }
                return false; //no lo ha encontrado
          }
          return false;//arbol vacio
}

void Arbol::desSelec(){
        if(selec != NULL)
                selec->deseleccionar();
}



#pragma package(smart_init)
