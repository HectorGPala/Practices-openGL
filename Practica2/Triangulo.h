//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#ifndef TrianguloH
#define TrianguloH
#include "Lapiz.h"
#include "Obstaculo.h"
#include "PV2D.h"
#include "Circulo.h"

//---------------------------------------------------------------------------

class Triangulo : public Obstaculo{
        private:
                PV2D* coordenada[3];
                PV2D* normales[3];
                PV2D* normalesV[3];
                PV2D* centro;
        public:
                Triangulo(PV2D* uno,PV2D* dos,PV2D* tres);
                ~Triangulo();
                virtual bool choque(PV2D* p,PV2D* v,double &tIn,PV2D*& normalIn);
                virtual void drawObstaculo(bool debug,float r,float g,float b);
                virtual void generaCorteza(list<Obstaculo*>* lista,GLdouble r);
};

#endif
