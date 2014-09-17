//HECTOR GUTIERREZ PALANCAREJO 05305699J
//---------------------------------------------------------------------------

#ifndef LapizH
#define LapizH

#include "PVD2.h"
#include "Math.h"

//---------------------------------------------------------------------------

class Lapiz{
        private:
                PVD2* pos;
                GLdouble dir;
        public:
                Lapiz();
                Lapiz(PVD2 *p,GLdouble d);
                ~Lapiz();
                void moveTo(PVD2 *p,bool draw);
                void turnTo(GLdouble a);
                void turn(GLdouble a);
                void forward(GLdouble dist, bool draw);
                void lookAt(PVD2 *p);
                PVD2* getPos();
                GLdouble getDir();


};
#endif
