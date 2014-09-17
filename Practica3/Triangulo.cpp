//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Triangulo.h"

//---------------------------------------------------------------------------

Triangulo::Triangulo(PV2D* uno,PV2D* dos,PV2D* tres){
        coordenada[0] = uno;
        coordenada[1] = dos;
        coordenada[2] = tres;
        GLdouble px = (coordenada[0]->getX()+coordenada[1]->getX()+coordenada[2]->getX())/3.0;
        GLdouble py = (coordenada[0]->getY()+coordenada[1]->getY()+coordenada[2]->getY())/3.0;
        centro = new PV2D(px,py);
        for(int i = 0; i < 3;i++){
                        int j = (i+1)%3;
                        PV2D* v = coordenada[i]->dameVector(coordenada[j]);
                        normales[i] = v->normalDer();
                        normales[i]->normalizarV();
                        delete v; v = NULL;
                        normalesV[i] = centro->dameVector(coordenada[i]);
        }
}

Triangulo::~Triangulo(){
        for(int i = 0; i < 3;i++){
                delete coordenada[i]; coordenada[i] = NULL;
                delete normales[i]; normales[i] = NULL;
                delete normalesV[i]; normalesV[i] = NULL;
        }
        delete centro; centro = NULL;
}

bool Triangulo::choque(PV2D* p,PV2D* v,GLdouble &tIn,PV2D*& normalIn){
        GLdouble dist[3];
        GLdouble proy[3];
        PV2D* golpeVertice[3];
        golpeVertice[0] = golpeVertice[1] = golpeVertice[2] = NULL;
        int signo[3];
        for(int i = 0;i < 3;i++){
                PV2D* ppi = p->dameVector(coordenada[i]);
                PV2D* normalV = v->normalIzq();
                dist[i] = ppi->prodEscalar(normalV);
                delete normalV; normalV = NULL;
                proy[i] = ppi->prodEscalar(v);
                delete ppi; ppi = NULL;
                if(dist[i] > 0)
                        signo[i] = 1;
                else if(dist[i] < 0)
                        signo[i] = -1;
                else
                        signo[i] = 0;
        }
        int suma = signo[0]+signo[1]+signo[2];
        if(abs(suma)==3)
                return false;
        int nHits = 0; GLdouble hit[3]; PV2D* n[3];//??
        for(int i = 0;i < 3;i++){
                int j = (i+1)%3;
                n[nHits] = NULL;
                if(signo[i]*signo[j] < 0){
                        hit[nHits] = (proy[i]*dist[j] - dist[i]*proy[j]);
                        hit[nHits] /= dist[j] - dist[i];
                        n[nHits] =  normales[i];
                        nHits++;
                }
        }
        if(nHits < 2){ //revisar este apartado es centro del triangulo no del circulo!!
                for(int i = 0;i < 3;i++){
                        if(signo[i] == 0){
                                hit[nHits] = proy[i];
                                n[nHits] = normalesV[i];
                                nHits++;
                        }
                }
        }
        int m = 0;
        for(int i = 1;i < nHits;i++)
                 if(hit[m] > hit[i])
                        m = i;
        tIn = hit[m];
        normalIn = new PV2D(n[m]);
        for(int i = 0;i < 3;i++)
                if(golpeVertice[i] != NULL)
                        delete golpeVertice[i];
        return true;
}


void Triangulo::drawObstaculo(bool debug,float r,float g,float b){
        glColor3f(r,g,b);
        if(debug)
                glBegin(GL_LINE_LOOP);
        else
                glBegin(GL_TRIANGLES);
                for(int i = 0; i < 3;i++)
                        glVertex2d(coordenada[i]->getX(),coordenada[i]->getY());
        glEnd();
        if(debug){//pintar normales
                glBegin(GL_LINES);
                        for(int i = 0; i < 3;i++){
                                int j = (i+1)%3;
                                GLdouble mx = (coordenada[i]->getX()+coordenada[j]->getX())/2;
                                GLdouble my = (coordenada[i]->getY()+coordenada[j]->getY())/2;
                                PV2D* p2 = new PV2D(mx,my);
                                glVertex2d(mx,my);
                                PV2D* n = new PV2D(normales[i]);
                                n->setX(n->getX()*10);
                                n->setY(n->getY()*10);
                                PV2D* p = p2->sumaPuntoVector(n);
                                delete n;
                                glVertex2d(p->getX(),p->getY());
                                delete p2; p2 = NULL;
                                delete p; p = NULL;
                        }
                glEnd();
        }
}

void Triangulo::generaCorteza(list<Obstaculo*>* lista,GLdouble r){
        Obstaculo* c1 = new Circulo(r,coordenada[0]->getX(),coordenada[0]->getY());
        Obstaculo* c2 = new Circulo(r,coordenada[1]->getX(),coordenada[1]->getY());
        Obstaculo* c3 = new Circulo(r,coordenada[2]->getX(),coordenada[2]->getY());
        lista->push_back(c1);lista->push_back(c2);lista->push_back(c3);
        PV2D* v = coordenada[0]->dameVector(coordenada[1]);
        PV2D* centroComun = v->normalIzq();
        centroComun->normalizarV();
        delete v; v = NULL;
        for(int i = 0;i < 3;i++){
                PV2D* d = normales[i]->vectorEscalado(r);
                PV2D* p0 = coordenada[i]->sumaPuntoVector(d);
                PV2D* p1 = coordenada[(i+1)%3]->sumaPuntoVector(d);
                PV2D* p2 = new PV2D(centro);
                Obstaculo* ob = new Triangulo(p0,p1,p2);
                lista->push_back(ob);
                delete d; d = NULL;
        }
        delete centroComun;
}

#pragma package(smart_init)
