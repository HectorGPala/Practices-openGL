//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#ifndef PelotaH
#define PelotaH

#include "PV2D.h"
#include "Lapiz.h"

//---------------------------------------------------------------------------

class Pelota{
        private:
                PV2D* vector;
                PV2D* centro;
                list<PV2D*>* poligono;
                GLdouble radio;
                GLdouble alfa;
                int incremento;
                float r,g,b;
        public:
                Pelota(GLdouble x, GLdouble y);
                ~Pelota();
                void drawPelota(bool d);
                PV2D* getVector();
                PV2D* getCentro();
                GLdouble getRadio(){return radio;}
                void setVector(PV2D* v);
                void moverPelota(GLdouble t,GLdouble v);
};

#endif
