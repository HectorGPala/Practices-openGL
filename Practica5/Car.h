//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#ifndef CarH
#define CarH

#include <gl\glu.h>

#include "Malla.h"
//---------------------------------------------------------------------------
#endif

class Car: public Malla {
        private:
                GLdouble angWheel;
                GLdouble pos;
                PV3D* C(GLdouble t);
                PV3D* CP(GLdouble t);
                PV3D* CPP(GLdouble t);
        public:
                Car(GLdouble x,GLdouble y,GLdouble z);
                ~Car(){};
                void drawCar();
                void drawWheel(PV3D* p,GLdouble d);
                void run();
                void back();

}; 
