//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#ifndef PV2DH
#define PV2DH
#include <gl\gl.h>
#include "Math.h"
//---------------------------------------------------------------------------
class PV2D{
        private:
                GLdouble x;
                GLdouble y;
        public:
                PV2D(){x =0; y = 0;}
                PV2D(GLdouble x,GLdouble y){this->x = x; this->y = y;}
                PV2D(PV2D *p){x = p->x; y = p->y;}
                ~PV2D(){x =0; y = 0;}
                void setX(GLdouble x){this->x = x;}
                void setY(GLdouble y){this->y = y;}
                GLdouble getX(){return x;}
                GLdouble getY(){return y;}
                GLdouble distancia(PV2D *p);
                void drawPV2D();
                //añadidas en prac2.0
                PV2D* dameVector(PV2D* q);//devuelve vector thisQ
                PV2D* sumaPuntoVector(PV2D* v);//devuelve un punto
                PV2D* sumaVectores(PV2D* w);
                PV2D* restaVectores(PV2D* w);
                PV2D* vectorEscalado(GLdouble k);
                GLdouble moduloV();
                void normalizarV();
                GLdouble prodEscalar(PV2D* w);
                PV2D* normalIzq();
                PV2D* normalDer();
                PV2D* refleja(PV2D* n);
};

#endif
