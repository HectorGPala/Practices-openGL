//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#ifndef ElipseH
#define ElipseH

#include "Obstaculo.h"
#include "Circulo.h"
#include "PV2D.h"

//---------------------------------------------------------------------------
#endif

class Elipse : public Obstaculo{
        private:
                PV2D* centro;
                GLdouble w,h;
                Circulo* c;

        public:
                Elipse(GLdouble centroX,GLdouble centroY,GLdouble w, GLdouble h);
                ~Elipse();
                virtual bool choque(PV2D* p,PV2D* v,GLdouble &tIn,PV2D*& normalIn);
                virtual void drawObstaculo(bool debug,float r,float g,float b);
                virtual void generaCorteza(list<Obstaculo*>* lista,GLdouble r);
                

};
