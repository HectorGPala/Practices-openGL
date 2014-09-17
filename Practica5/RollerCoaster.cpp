//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "RollerCoaster.h"



//---------------------------------------------------------------------------

#pragma package(smart_init)

RollerCoaster::RollerCoaster(int nP, int nS,GLdouble r):Malla(nS*nP,nS*nP,nS*nP,new PV3D*[nP*nS],new PV3D*[nS*nP],new Cara*[nS*nP]){
        this->nP = nP;
        this->nS = nS;
        radius = r;
        generarPerfil(nP,radius);//figura circunscrita que rotara para generar el poligono por extrusion
        generarRoller();//rellena vertices normales y caras en base a la ecuacion C(t) =  ....
}
RollerCoaster::~RollerCoaster(){
        for(int i = 0; i < nP;i++)
                delete perfil[i];
        delete[] perfil;
}


void RollerCoaster::generarPerfil(int nP,GLdouble r){
        perfil = new PV3D*[nP];
        GLdouble incr = 2*M_PI/nP;
        for(int i = 0; i < nP; i++){
                perfil[i] = new PV3D(r*cos(2*M_PI-i*incr),r*sin(2*M_PI-i*incr),0,1);
        }
}

void RollerCoaster::generarRoller(){
        GLdouble incr = 2*M_PI/nS;
        for(int i = 0; i < nS; i++){
                for(int j = 0; j < nP;j++){
                        int v = i*nP+j;//numero de vertice actual
                        GLdouble t = incr*(nS-i)*2;
                        vertices[v] = generarVertice(t,perfil[j]);                        
                }
        }
        int cara_i = 0;
        for(int i = 0; i < nS; i++){
                for(int j = 0; j < nP;j++){
                        int v0,v1,v2,v3;
                        v0 = (i*nP+j)%numVertices;
                        v1 = (v0 + nP)%numVertices;
                        if(v0%nP == 0)//primera cara
                                v2 = (v1 + (nP-1))%numVertices;
                        else
                                v2 = (v1 - 1)%numVertices;
                        v3 = (v2-nP)%numVertices;
                        if(v0 >= nS*nP -nP)//ultima seccion
                                v3 = v3 + nS*nP;
                        VerticeNormal** v = new VerticeNormal*[4];
                        v[0] = new VerticeNormal(v0,cara_i);
                        v[1] = new VerticeNormal(v1,cara_i);
                        v[2] = new VerticeNormal(v2,cara_i);
                        v[3] = new VerticeNormal(v3,cara_i);
                        caras[cara_i] = new Cara(4,v);
                        normales[cara_i] = calculoNormalNewell(caras[cara_i]);
                        cara_i++;
                }
        } 
}

PV3D* RollerCoaster::generarVertice(GLdouble alfa,PV3D* p){
        PV3D* c = C(alfa);
        PV3D* cp = CP(alfa);
        PV3D* cpp = CPP(alfa);
        PV3D* t = new PV3D(cp); t->normalizar();
        PV3D* b = cp->productoVectorial(cpp); b->normalizar();
        PV3D* n = b->productoVectorial(t);//ya esta normalizado

        //matriz (n,b,t,c) de 4x4:
        GLdouble m11 = n->getX();
        GLdouble m12 = b->getX();
        GLdouble m13 = t->getX();
        GLdouble m14 = c->getX();
        GLdouble m21 = n->getY();
        GLdouble m22 = b->getY();
        GLdouble m23 = t->getY();
        GLdouble m24 = c->getY();
        GLdouble m31 = n->getZ();
        GLdouble m32 = b->getZ();
        GLdouble m33 = t->getZ();
        GLdouble m34 = c->getZ();
        GLdouble m41 = 0;
        GLdouble m42 = 0;
        GLdouble m43 = 0;
        GLdouble m44 = 1;

        //calculo del punto transformado:
        GLdouble auxX = m11*p->getX()+m12*p->getY()+m13*p->getZ()+m14*p->getPV();
        GLdouble auxY = m21*p->getX()+m22*p->getY()+m23*p->getZ()+m24*p->getPV();
        GLdouble auxZ = m31*p->getX()+m32*p->getY()+m33*p->getZ()+m34*p->getPV();
        GLdouble auxPV = m41*p->getX()+m42*p->getY()+m43*p->getZ()+m44*p->getPV();

        delete c; c = NULL;
        delete cp; cp = NULL;
        delete cpp; cpp = NULL;
        delete t; t = NULL;
        delete b; b = NULL;
        delete n; n = NULL;
        
        return new PV3D(auxX,auxY,auxZ,auxPV);
}

PV3D* RollerCoaster::C(GLdouble t){
        //C(t) = (3·cos(t), 2·cos(1.5·t), 3·sen(t))
        GLdouble x = 3*cos(t);
        GLdouble y = 2*cos(1.5*t);
        GLdouble z = 3*sin(t);
        return new PV3D(x,y,z,1);
}

PV3D* RollerCoaster::CP(GLdouble t){
        //C'(t) = (-3*sin(t),-2*1.5*sin(1.5*t),3*cos(t))
        GLdouble x = -3*sin(t);
        GLdouble y = -2*1.5*sin(1.5*t);
        GLdouble z = 3*cos(t);
        return new PV3D(x,y,z,1);
}

PV3D* RollerCoaster::CPP(GLdouble t){
        //C''(t) = (-3*cos(t),-2*1.5*1.5*cos(1.5*t),-3*sin(t))
        GLdouble x = -3*cos(t);
        GLdouble y = -2*1.5*1.5*cos(1.5*t);
        GLdouble z = -3*sin(t);
        return new PV3D(x,y,z,1);
}
