//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#ifndef PVD2H
#define PVD2H
#include <gl\gl.h>
#include "Math.h"
//---------------------------------------------------------------------------
class PVD2{
        private:
                GLdouble x;
                GLdouble y;
        public:
                PVD2(){x =0; y = 0;}
                PVD2(GLdouble x,GLdouble y){this->x = x; this->y = y;}
                PVD2(PVD2 *p){x = p->x; y = p->y;}
                ~PVD2(){x =0; y = 0;}
                void setX(GLdouble x){this->x = x;}
                void setY(GLdouble y){this->y = y;}
                GLdouble getX(){return x;}
                GLdouble getY(){return y;}
                GLdouble distancia(PVD2 *p);
                void drawPVD2();
};

#endif
