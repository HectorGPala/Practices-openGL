//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#ifndef CirculoH
#define CirculoH
#define TAM 50
#include "Obstaculo.h"
#include "PV2D.h"
#include "Lapiz.h"
//---------------------------------------------------------------------------

class Circulo : public Obstaculo{
        private:
                GLdouble radio,r2;
                PV2D* centro;
                list<PV2D*>* poligono;
        public:
                Circulo(GLdouble r,GLdouble x,GLdouble y);
                ~Circulo();
                PV2D* getCentro();
                GLdouble getRadio(){return radio;}
                void drawCircle(bool d,float r,float g,float b);
                virtual bool choque(PV2D* p,PV2D* v,double &tIn,PV2D*& normalIn);
                virtual void drawObstaculo(bool debug,float r,float g,float b);
                virtual void generaCorteza(list<Obstaculo*>* lista,GLdouble r);
};
#endif
