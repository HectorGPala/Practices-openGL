//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Malla.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

Malla::Malla(int nV,int nN, int nC,PV3D** vertices,PV3D** normales,Cara** cara,ColorRGB* c,TAfin* t):Objeto3D(t,c){
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

void Malla::dibuja(){
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
                GLdouble mm[16];
                m->getMatrix(mm);
                glMultMatrixd(mm);
        glColor4f(c->getRed(),c->getGreen(),c->getBlue(),1.0);
        for(int i = 0; i < numCaras;i++){
                glLineWidth(1.0);
                glBegin(GL_POLYGON);
                for(int j = 0; j < caras[i]->getNumVertices();j++){
                        int iN = caras[i]->getIndice(j)->get_indiceNormal();
                        int iV = caras[i]->getIndice(j)->get_indiceVertice();
                        glNormal3d(normales[iN]->getX(),normales[iN]->getY(),normales[iN]->getZ());
                        glVertex3d(vertices[iV]->getX(),vertices[iV]->getY(),vertices[iV]->getZ());
                }
                glEnd();
        }
        glPopMatrix();
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
                int v = c->getIndice(0)->get_indiceVertice();
                int n = c->getIndice(0)->get_indiceNormal();
                PV3D* normal = normales[n];
                GLdouble vX = vertices[v]->getX();
                GLdouble vY = vertices[v]->getY();
                GLdouble vZ = vertices[v]->getZ();
                glBegin(GL_LINES);
                        glVertex3d(vX,vY,vZ);
                        glVertex3d(normales[n]->getX()+vX,normales[n]->getY()+vY,normales[n]->getZ()+vZ);
                glEnd();
        }
}
