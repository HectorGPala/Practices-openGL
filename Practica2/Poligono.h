//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#ifndef PoligonoH
#define PoligonoH

#include "Obstaculo.h"
#include "PV2D.h"
#include "Lapiz.h"
//---------------------------------------------------------------------------

class Poligono : public Obstaculo{
        private:
                int n_lados;
                PV2D* centro;
                GLdouble radio;
                list<PV2D*>* lado;
                list<PV2D*>* normales;
        public:
                Poligono(int n,PV2D* c,GLdouble r);
                ~Poligono();
                void drawPoligono();
                virtual bool choque(PV2D* p,PV2D* v,GLdouble &tIn,PV2D*& normalIn);
                virtual void drawObstaculo(bool debug,float r,float g,float b);
                virtual void generaCorteza(list<Obstaculo*>* lista,GLdouble r);
};

#endif
