//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Camara.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

Camara::Camara(PV3D* e,PV3D* l,PV3D* uu){
        eye = e;
        look = l;
        up = uu;
        configAxisCam();
        setModelViewMatrix();
        right = 10;left = -right;
        top = 10; bottom = -top;
        nearC = 1; farC = 1000;
        fovyC = 5; aspectC = 2;
        configProjection(2);        
}

Camara::~Camara(){
        delete eye; delete look; delete up;
        delete u; delete v; delete n;
}

void Camara::configAxisCam(){
        n = new PV3D(eye->getX()-look->getX(),eye->getY()-look->getY(),eye->getZ()-look->getZ(),0);
        if(n->modulo() != 0)
                n->normalizar();
        u = up->productoVectorial(n);
        if(u->modulo() != 0)
                u->normalizar();
        v = n->productoVectorial(u);
}

void Camara::configProjection(int i){
        GLfloat m[16];
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        switch(i){
                case 0://ortogonal
                        glOrtho(left,right,bottom,top,nearC,farC);
                        break;
                case 1://perspectiva
                        //glFrustum(left,right,bottom,top,nearC,farC);
                        gluPerspective(fovyC,aspectC,nearC,farC);
                        break;
                case 2://oblicua
                        proyOblicua(new PV3D(0,0,0.9,0));
                        break;

                default:
                        glOrtho(left,right,bottom,top,nearC,farC);
                        break;
        }
}

void Camara::setModelViewMatrix(){
        glMatrixMode(GL_MODELVIEW);
        GLfloat m[16];
        m[0]=u->getX(); m[4]=u->getY(); m[8]=u->getZ(); m[12]= -eye->productoEscalar(u);
        m[1]=v->getX(); m[5]=v->getY(); m[9]=v->getZ(); m[13]= -eye->productoEscalar(v);
        m[2]=n->getX(); m[6]=n->getY(); m[10]=n->getZ();m[14]= -eye->productoEscalar(n);
        m[3]=0;         m[7]=0;         m[11]=0;        m[15]=1;
        glLoadMatrixf(m);
}

void Camara::pitch(GLdouble alfa){
        GLdouble coseno = cos(alfa*M_PI/180);
        GLdouble seno = sin(alfa*M_PI/180);
        PV3D* auxV = v;
        PV3D* auxN = n;
        GLdouble auxX = auxV->getX()*coseno - auxN->getX()*seno;
        GLdouble auxY = auxV->getY()*coseno - auxN->getY()*seno;
        GLdouble auxZ = auxV->getZ()*coseno - auxN->getZ()*seno;
        v = new PV3D(auxX,auxY,auxZ,0);
        auxX = auxN->getX()*coseno + auxV->getX()*seno;
        auxY = auxN->getY()*coseno + auxV->getY()*seno;
        auxZ = auxN->getZ()*coseno + auxV->getZ()*seno;
        n = new PV3D(auxX,auxY,auxZ,0);
        delete auxV;
        delete auxN;
        setModelViewMatrix();
}

void Camara::yaw(GLdouble alfa){
        GLdouble coseno = cos(alfa*M_PI/180);
        GLdouble seno = sin(alfa*M_PI/180);
        PV3D* auxU = u;
        PV3D* auxN = n;
        GLdouble auxX = auxU->getX()*coseno + auxN->getX()*seno;
        GLdouble auxY = auxU->getY()*coseno + auxN->getY()*seno;
        GLdouble auxZ = auxU->getZ()*coseno + auxN->getZ()*seno;
        u = new PV3D(auxX,auxY,auxZ,0);
        auxX = auxN->getX()*coseno - auxU->getX()*seno;
        auxY = auxN->getY()*coseno - auxU->getY()*seno;
        auxZ = auxN->getZ()*coseno - auxU->getZ()*seno;
        n = new PV3D(auxX,auxY,auxZ,0);
        delete auxU;
        delete auxN;
        setModelViewMatrix();
}

void Camara::roll(GLdouble alfa){
        GLdouble coseno = cos(alfa*M_PI/180);
        GLdouble seno = sin(alfa*M_PI/180);
        PV3D* auxU = u;
        PV3D* auxV = v;
        GLdouble auxX = auxU->getX()*coseno + auxV->getX()*seno;
        GLdouble auxY = auxU->getY()*coseno + auxV->getY()*seno;
        GLdouble auxZ = auxU->getZ()*coseno + auxV->getZ()*seno;
        u = new PV3D(auxX,auxY,auxZ,0);
        auxX = auxV->getX()*coseno - auxU->getX()*seno;
        auxY = auxV->getY()*coseno - auxU->getY()*seno;
        auxZ = auxV->getZ()*coseno - auxU->getZ()*seno;
        v = new PV3D(auxX,auxY,auxZ,0);
        delete auxU;
        delete auxV;
        setModelViewMatrix();
}

void Camara::desplazar(GLdouble x,GLdouble y,GLdouble z){
        PV3D* auxE = eye;
        GLdouble auxX = eye->getX()+u->getX()*x+v->getX()*y+n->getX()*z;
        GLdouble auxY = eye->getY()+u->getY()*x+v->getY()*y+n->getY()*z;
        GLdouble auxZ = eye->getZ()+u->getZ()*x+v->getZ()*y+n->getZ()*z;
        eye = new PV3D(auxX,auxY,auxZ,0);
        delete auxE;
        setModelViewMatrix();
}

void Camara::recorridoEje(GLdouble x,GLdouble y,GLdouble z){
        GLdouble eyeX = eye->getX() + x;
        GLdouble eyeY = eye->getY() + y;
        GLdouble eyeZ = eye->getZ() + z;
        delete eye;
        eye = new PV3D(eyeX,eyeY,eyeZ,0);
        configAxisCam();
        setModelViewMatrix();
}

void Camara::giraX(GLdouble alfa){
                if(!(eye->getY()==0 && eye->getZ()==0)){
                    GLdouble modulo = sqrt(pow(eye->getY(),2)+pow(eye->getZ(),2));
                    GLdouble pos = atan2(eye->getZ(),eye->getY());
                    GLdouble auxX = eye->getX();
                    GLdouble auxY = modulo*cos(pos+alfa*M_PI/180);
                    GLdouble auxZ = modulo*sin(pos+alfa*M_PI/180);
                    delete eye;
                    eye = new PV3D(auxX,auxY,auxZ,0);
                    configAxisCam();
                    setModelViewMatrix();
                 }
}

void Camara::giraY(GLdouble alfa){
                if(!(eye->getX()==0 && eye->getZ()==0)){
                    GLdouble modulo = sqrt(pow(eye->getX(),2)+pow(eye->getZ(),2));
                    GLdouble pos = atan2(eye->getZ(),eye->getX());
                    GLdouble auxX = modulo*cos(pos+alfa*M_PI/180);
                    GLdouble auxY = eye->getY();
                    GLdouble auxZ = modulo*sin(pos+alfa*M_PI/180);
                    delete eye;
                    eye = new PV3D(auxX,auxY,auxZ,0);
                    configAxisCam();
                    setModelViewMatrix();
                 }
}

void Camara::giraZ(GLdouble alfa){
                if(!(eye->getX()==0 && eye->getY()==0)){
                    GLdouble modulo = sqrt(pow(eye->getX(),2)+pow(eye->getY(),2));
                    GLdouble pos = atan2(eye->getY(),eye->getX());
                    GLdouble auxX = modulo*cos(pos+alfa*M_PI/180);
                    GLdouble auxY = modulo*sin(pos+alfa*M_PI/180);
                    GLdouble auxZ = eye->getZ();
                    delete eye;
                    eye = new PV3D(auxX,auxY,auxZ,0);
                    configAxisCam();
                    setModelViewMatrix();
                 }
}

void Camara::viewLateral(){
        viewEsquina(new PV3D(100,100,100,0));
        PV3D* aux = eye;
        eye = new PV3D(eye->getX(),0,0,0);
        delete aux;
        aux = up;
        up = new PV3D(0,1,0,0);
        delete aux;
        configAxisCam();
        setModelViewMatrix();
}

void Camara::viewFrontal(){
        viewEsquina(new PV3D(100,100,100,0));
        PV3D* aux = eye;
        eye = new PV3D(0,0,eye->getZ(),0);
        delete aux;
        aux = up;
        up = new PV3D(0,1,0,0);
        delete aux;
        configAxisCam();
        setModelViewMatrix();
}

void Camara::viewCenital(){
        viewEsquina(new PV3D(100,100,100,0));
        PV3D* aux = eye;
        eye = new PV3D(0,eye->getY(),0,0);
        delete aux;
        aux = up;
        up = new PV3D(1,0,0,0);
        delete aux;
        configAxisCam();
        setModelViewMatrix();
}

void Camara::viewEsquina(PV3D* e){
        delete up;
        delete look;
        delete eye;
        eye = e;
        look = new PV3D(0,0,0,0);
        up = new PV3D(0,1,0,0);
        configAxisCam();
        setModelViewMatrix();
}

void Camara::proyOblicua(PV3D* d){
        glOrtho(left,right,bottom,top,nearC,farC);
        if(d->getZ() != 0 && !(d->getX() == 0 && d->getY() == 0 && d->getZ() == 1)){
                GLdouble m[16];
                m[0] = 1; m[4] = 0; m[8] = -d->getX()/d->getZ(); m[12] = -nearC*d->getX()/d->getZ();
                m[1] = 0; m[5] = 1; m[9] = -d->getY()/d->getZ(); m[13] = -nearC*d->getY()/d->getZ();
                m[2] = 0; m[6] = 0; m[10] = 1;                   m[14] = 0;
                m[3] = 0; m[7] = 0; m[11] = 0;                   m[15] = 1;
                glMultMatrixd(m);
        }
        delete d;
}   
