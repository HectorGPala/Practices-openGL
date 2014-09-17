//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#ifndef LapizH
#define LapizH

#include "PV2D.h"
#include "Math.h"
#define _USE_MATH_DEFINES
#include <list>
using namespace std;

//---------------------------------------------------------------------------

class Lapiz{
        private:
                PV2D* pos;
                GLdouble dir;
        public:
                Lapiz();
                Lapiz(PV2D *p,GLdouble d);
                ~Lapiz();
                void moveTo(PV2D *p,bool draw);
                void turnTo(GLdouble a);
                void turn(GLdouble a);
                void forward(GLdouble dist, bool draw);
                void lookAt(PV2D *p);
                PV2D* getPos();
                GLdouble getDir();
                void generaPoligono(list<PV2D*>* lados,int n,GLdouble r);


};
#endif
