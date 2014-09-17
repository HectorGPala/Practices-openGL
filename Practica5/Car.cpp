//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Car.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

Car::Car(GLdouble x,GLdouble y,GLdouble z):Malla(8,6,6,new PV3D*[8],new PV3D*[6],new Cara*[6]){
        pos = 0;
        angWheel = 0;
        GLdouble auxX = x/2; GLdouble auxY = y/2; GLdouble auxZ = z/2;
        vertices[0] = new PV3D(-auxX,-auxY,auxZ,1);
        vertices[1] = new PV3D(auxX,-auxY,auxZ,1);
        vertices[2] = new PV3D(auxX,auxY,auxZ,1);
        vertices[3] = new PV3D(-auxX,auxY,auxZ,1);
        vertices[4] = new PV3D(-auxX,-auxY,-auxZ,1);
        vertices[5] = new PV3D(auxX,-auxY,-auxZ,1);
        vertices[6] = new PV3D(auxX,auxY,-auxZ,1);
        vertices[7] = new PV3D(-auxX,auxY,-auxZ,1);

        int i = 0;
        VerticeNormal** v = new VerticeNormal*[4];
        v[0] = new VerticeNormal(0,i);
        v[1] = new VerticeNormal(1,i);
        v[2] = new VerticeNormal(2,i);
        v[3] = new VerticeNormal(3,i);
        caras[i] = new Cara(4,v);
        normales[i] = calculoNormalNewell(caras[i]);

        i++;

        v = new VerticeNormal*[4];
        v[0] = new VerticeNormal(1,i);
        v[1] = new VerticeNormal(5,i);
        v[2] = new VerticeNormal(6,i);
        v[3] = new VerticeNormal(2,i);
        caras[i] = new Cara(4,v);
        normales[i] = calculoNormalNewell(caras[i]);
        i++;

        v = new VerticeNormal*[4];
        v[0] = new VerticeNormal(2,i);
        v[1] = new VerticeNormal(6,i);
        v[2] = new VerticeNormal(7,i);
        v[3] = new VerticeNormal(3,i);
        caras[i] = new Cara(4,v);
        normales[i] = calculoNormalNewell(caras[i]);
        i++;

        v = new VerticeNormal*[4];
        v[0] = new VerticeNormal(3,i);
        v[1] = new VerticeNormal(7,i);
        v[2] = new VerticeNormal(4,i);
        v[3] = new VerticeNormal(0,i);
        caras[i] = new Cara(4,v);
        normales[i] = calculoNormalNewell(caras[i]);
        i++;

        v = new VerticeNormal*[4];
        v[0] = new VerticeNormal(4,i);
        v[1] = new VerticeNormal(7,i);
        v[2] = new VerticeNormal(6,i);
        v[3] = new VerticeNormal(5,i);
        caras[i] = new Cara(4,v);
        normales[i] = calculoNormalNewell(caras[i]);
        i++;

        v = new VerticeNormal*[4];
        v[0] = new VerticeNormal(5,i);
        v[1] = new VerticeNormal(1,i);
        v[2] = new VerticeNormal(0,i);
        v[3] = new VerticeNormal(4,i);
        caras[i] = new Cara(4,v);
        normales[i] = calculoNormalNewell(caras[i]);
        i++;
}

void Car::drawCar(){
        PV3D* c = C(pos);
        PV3D* cp = CP(pos);
        PV3D* cpp = CPP(pos);
        PV3D* t = new PV3D(cp);
        if(t->modulo() > 0.0)
                t->normalizar();
        PV3D* b = cp->productoVectorial(cpp);
        if(b->modulo() > 0.0)
                b->normalizar();
        PV3D* n = b->productoVectorial(t);//ya esta normalizado

        GLdouble* m = new GLdouble[16];
        m[0] = n->getX();
        m[1] = n->getY();
        m[2] = n->getZ();
        m[3] = 0;
        m[4] = b->getX();
        m[5] = b->getY();
        m[6] = b->getZ();
        m[7] = 0;
        m[8] = t->getX();
        m[9] = t->getY();
        m[10] = t->getZ();
        m[11] = 0;
        m[12] = c->getX();
        m[13] = c->getY();
        m[14] = c->getZ();
        m[15] = 1;
        glPushMatrix();
        glMatrixMode(GL_MODELVIEW);
        glMultMatrixd(m);
        glRotated(90.0,0,0,1.0);

        drawWheel(vertices[0],0.1);
        drawWheel(vertices[1],0.0);
        drawWheel(vertices[4],0.1);
        drawWheel(vertices[5],0.0);

        glColor4f(1.0, 0.0, 0.0, 1.0);
        dibuja(false);

        glPopMatrix();

        delete c; c = NULL;
        delete cp; cp = NULL;
        delete cpp; cpp = NULL;
        delete t; t = NULL;
        delete b; b = NULL;
        delete n; n = NULL;
        delete[] m;
}

void Car::drawWheel(PV3D* p,GLdouble d){
        glPushMatrix();
        GLUquadricObj* q = gluNewQuadric();
        glTranslated(p->getX()-d,p->getY(),p->getZ());
        glRotated(90,0.0,1.0f,0.0f);
        glRotated(angWheel,0.0,0.0,1.0);
        glColor4d(0.0, 0.0, 0.0, 1.0);
        gluCylinder(q,0.1,0.1,0.1,12,3);
        gluDisk(q,0,0.1,12,12);
        glPopMatrix();
        gluDeleteQuadric(q);
}

void Car::run(){
        pos += 0.2;
        angWheel += 45;
}

void Car::back(){
        pos -= 0.2;
        angWheel -= 45;
}

PV3D* Car::C(GLdouble t){
        //C(t) = (3·cos(t), 2·cos(1.5·t), 3·sen(t))
        GLdouble x = 3*cos(t);
        GLdouble y = 2*cos(1.5*t);
        GLdouble z = 3*sin(t);
        return new PV3D(x,y,z,1);
}

PV3D* Car::CP(GLdouble t){
        //C'(t) = (-3*sin(t),-2*1.5*sin(1.5*t),3*cos(t))
        GLdouble x = -3*sin(t);
        GLdouble y = -2*1.5*sin(1.5*t);
        GLdouble z = 3*cos(t);
        return new PV3D(x,y,z,1);
}

PV3D* Car::CPP(GLdouble t){
        //C''(t) = (-3*cos(t),-2*1.5*1.5*cos(1.5*t),-3*sin(t))
        GLdouble x = -3*cos(t);
        GLdouble y = -2*1.5*1.5*cos(1.5*t);
        GLdouble z = -3*sin(t);
        return new PV3D(x,y,z,1);
}
