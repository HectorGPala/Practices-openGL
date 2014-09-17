//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PV3D.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

PV3D::PV3D(int pv){
        x = y = z = 0;
        this->pv = pv;
}

PV3D::PV3D(GLdouble x,GLdouble y,GLdouble z,int pv){
        this->x = x;
        this->y = y;
        this->z = z;
        this->pv = pv;
}

PV3D::PV3D(PV3D* p){
        x = p->x;
        y = p->y;
        z = p->z;
        pv = p->pv;
}

GLdouble PV3D::productoEscalar(PV3D* p){
        return x*p->x + y*p->y + z*p->z;
}

PV3D* PV3D::productoVectorial(PV3D* p){
        GLdouble auxX = y*p->z - z*p->y;
        GLdouble auxY = z*p->x - x*p->z;
        GLdouble auxZ = x*p->y - y*p->x;
        return new PV3D(auxX,auxY,auxZ,1);
}

GLdouble PV3D::modulo(){
        return sqrt(x*x + y*y + z*z);
}

void PV3D::normalizar(){
        GLdouble aux = modulo();
        x /= aux;
        y /= aux;
        z /= aux;
}
