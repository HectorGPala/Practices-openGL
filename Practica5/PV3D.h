//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#ifndef PV3DH
#define PV3DH
#include <gl\gl.h>
#include "Math.h"

//---------------------------------------------------------------------------
#endif

class PV3D{
        private:
                GLdouble x,y,z;
                int pv;
        public:
                PV3D(int pv);
                PV3D(GLdouble x,GLdouble y,GLdouble z,int pv);
                PV3D(PV3D *p);
                ~PV3D(){};
                GLdouble getX(){return x;};
                GLdouble getY(){return y;};
                GLdouble getZ(){return z;};
                int getPV(){return pv;};
                GLdouble productoEscalar(PV3D* p);
                PV3D* productoVectorial(PV3D* p);
                GLdouble modulo();
                void normalizar();

};
