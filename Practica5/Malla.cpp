//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Malla.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

Malla::Malla(int nV,int nN, int nC,PV3D** vertices,PV3D** normales,Cara** cara){
        numVertices = nV;
        numNormales = nN;
        numCaras = nC;
        this->vertices = vertices;
        this->normales = normales;
        this->caras = cara;
}

Malla::~Malla(){
        for(int i = 0; i < numVertices;i++)
                delete vertices[i];
        for(int i = 0; i < numNormales;i++)
                delete normales[i];
        for(int i = 0; i < numCaras;i++)
                delete caras[i];
        delete[] vertices;
        delete[] normales;
        delete[] caras;
}

void Malla::dibuja(bool lines){
        for(int i = 0; i < numCaras;i++){
                glLineWidth(1.0);
                if(lines)
                        glBegin(GL_LINE_LOOP);
                else
                        glBegin(GL_POLYGON);
                for(int j = 0; j < caras[i]->getNumVertices();j++){
                        int iN = caras[i]->getIndice(j)->get_indiceNormal();
                        int iV = caras[i]->getIndice(j)->get_indiceVertice();
                        glNormal3d(normales[iN]->getX(),normales[iN]->getY(),normales[iN]->getZ());
                        glVertex3d(vertices[iV]->getX(),vertices[iV]->getY(),vertices[iV]->getZ());
                }
                glEnd();
        }
}

PV3D* Malla::calculoNormalNewell(Cara* c){
        GLdouble nx = 0.0;
        GLdouble ny = 0.0;
        GLdouble nz = 0.0;
        PV3D* verticeActual = NULL;
        PV3D* verticeSig = NULL;
        int nV = c->getNumVertices();
        for(int i = 0; i < nV;i++){
                verticeActual = vertices[c->getIndice(i)->get_indiceVertice()];
                verticeSig = vertices[c->getIndice((i+1)%nV)->get_indiceVertice()];
                nx += (verticeActual->getY()-verticeSig->getY())*(verticeActual->getZ()+verticeSig->getZ());
                ny += (verticeActual->getZ()-verticeSig->getZ())*(verticeActual->getX()+verticeSig->getX());
                nz += (verticeActual->getX()-verticeSig->getX())*(verticeActual->getY()+verticeSig->getY());
        }
        PV3D* n = new PV3D(nx,ny,nz,0);
        n->normalizar();
        return n;
}

void Malla::drawNormals(){
        for(int i = 0; i < numCaras;i++){
                Cara* c = caras[i];
                int v0 = c->getIndice(0)->get_indiceVertice();
                int v1 = c->getIndice(1)->get_indiceVertice();
                int v2 = c->getIndice(2)->get_indiceVertice();
                int v3 = c->getIndice(3)->get_indiceVertice();
                int n = c->getIndice(0)->get_indiceNormal();
                PV3D* normal = normales[n];
                GLdouble vX = (vertices[v0]->getX()+vertices[v1]->getX()+vertices[v2]->getX()+vertices[v3]->getX())/4;
                GLdouble vY = (vertices[v0]->getY()+vertices[v1]->getY()+vertices[v2]->getY()+vertices[v3]->getY())/4;
                GLdouble vZ = (vertices[v0]->getZ()+vertices[v1]->getZ()+vertices[v2]->getZ()+vertices[v3]->getZ())/4;
                glBegin(GL_LINES);
                        glVertex3d(vX,vY,vZ);
                        glVertex3d(normales[n]->getX()+vX,normales[n]->getY()+vY,normales[n]->getZ()+vZ);
                glEnd();
        }
}
