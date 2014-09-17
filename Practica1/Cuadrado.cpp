//HECTOR GUTIERREZ PALANCAREJO 05305699J
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Cuadrado.h"

//---------------------------------------------------------------------------

Cuadrado::Cuadrado(){
        for(int i = 0; i < 4; i++)
                coordenada[i] = new PVD2();
        rojo = verde = azul = 0.0f;
        selec = false;
}

Cuadrado::Cuadrado(PVD2 *centro,GLdouble l){
        coordenada[0] = new PVD2(centro->getX()-(l/2),centro->getY()-(l/2));
        coordenada[1] = new PVD2(centro->getX()+(l/2),centro->getY()-(l/2));
        coordenada[2] = new PVD2(centro->getX()+(l/2),centro->getY()+(l/2));
        coordenada[3] = new PVD2(centro->getX()-(l/2),centro->getY()+(l/2));
        rojo = verde = azul = 0.0f;
        selec = false;
}

Cuadrado::~Cuadrado(){
        for(int i = 0; i < 4; i++){
                delete coordenada[i];
                coordenada[i] = NULL;
        }
}

void Cuadrado::setIesima(int i,PVD2 *p){
        PVD2 *copiaP = new PVD2(p);
        delete coordenada[i];
        coordenada[i] = copiaP;
}

void Cuadrado::setColor(float r,float g,float b){
        rojo = r;
        verde = g;
        azul = b;
}

PVD2* Cuadrado::getIesima(int i){
        return coordenada[i];
}

void Cuadrado::drawCuadrado(){
        if(!selec)
                glColor3f(rojo,verde,azul);
        else
                glColor3f(0.0f,0.0f,0.0f);
        glBegin(GL_QUADS);
                glVertex2d(coordenada[0]->getX(),coordenada[0]->getY());
                glVertex2d(coordenada[1]->getX(),coordenada[1]->getY());
                glVertex2d(coordenada[2]->getX(),coordenada[2]->getY());
                glVertex2d(coordenada[3]->getX(),coordenada[3]->getY());
        glEnd();
}

GLdouble Cuadrado::getLado(){
        return sqrt(pow(coordenada[0]->getX()-coordenada[1]->getX(),2.0)+pow(coordenada[0]->getY()-coordenada[1]->getY(),2.0));
}

bool Cuadrado::seleccionado(PVD2* p){
        //GLdouble d = getLado()*sqrt(2);//diagonal
        //http://trevinca.ei.uvigo.es/~formella/doc/ig02/node45.html
        GLdouble centroX,centroY = 0.0;
        for(int i = 0; i < 4;i++){
                centroX += coordenada[i]->getX();
                centroY += coordenada[i]->getY();
        }
        centroX *= (1.0/4.0);
        centroY *= (1.0/4.0);
        GLdouble l = getLado();
        PVD2* centro = new PVD2(centroX,centroY);
        if(centro->distancia(p) <= (l/2.0)){
                selec = true;
                delete centro; centro = NULL;
                return true;
        }
        else{
                delete centro; centro = NULL;
                return false;
        }
}



#pragma package(smart_init)


