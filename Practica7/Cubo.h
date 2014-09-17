//---------------------------------------------------------------------------

#ifndef CuboH
#define CuboH
#include <gl\gl.h>
#include <gl\glu.h>

#include "Malla.h"
//---------------------------------------------------------------------------


class Cubo : public Malla{
        public:
                Cubo(GLdouble a,GLdouble l,GLdouble g,ColorRGB* c,TAfin* t,unsigned int *tx,int nt);
                ~Cubo(){};
                void trasladar(GLdouble x, GLdouble y, GLdouble z);
                void girar(GLdouble alfa, GLdouble x, GLdouble y, GLdouble z);
                void escalar(GLdouble x, GLdouble y, GLdouble z);
};
#endif
