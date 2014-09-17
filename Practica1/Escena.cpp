//HECTOR GUTIERREZ PALANCAREJO 05305699J
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Escena.h"

//---------------------------------------------------------------------------

Escena::Escena(GLfloat xl,GLfloat xr,GLfloat yt,GLfloat yb){
        xL = xl; xR = xr; yT = yt; yB = yb;
        arbolito = new Arbol();
}

Escena::~Escena(){
        delete arbolito;
        arbolito = NULL;
}

void Escena::set(GLfloat xl,GLfloat xr,GLfloat yt,GLfloat yb){
        xL = xl; xR = xr; yT = yt; yB = yb;
}

Arbol* Escena::getArbol(){
        return arbolito;
}

void Escena::drawEscena(){
        arbolito->drawArbol();
}
#pragma package(smart_init)
