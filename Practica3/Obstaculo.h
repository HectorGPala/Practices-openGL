//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#ifndef ObstaculoH
#define ObstaculoH
#include <list>
#include "PV2D.h"
using namespace std;

//---------------------------------------------------------------------------

class Obstaculo{
        public:
                virtual ~Obstaculo(){};
                virtual bool choque(PV2D* p,PV2D* v,GLdouble &tIn,PV2D*& normalIn)=0;
                virtual void drawObstaculo(bool debug,float r,float g,float b)=0;
                virtual void generaCorteza(list<Obstaculo*>* lista,GLdouble r)=0;
};

#endif
