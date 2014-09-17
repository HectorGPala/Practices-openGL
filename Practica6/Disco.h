//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#ifndef DiscoH
#define DiscoH

#include "ObjetoCuadrico.h"
//---------------------------------------------------------------------------
#endif

class Disco : public ObjetoCuadrico{
        private:
                GLdouble rInt;
                GLdouble rExt;
                GLdouble nLados;
                GLdouble nRings;
        public:
                Disco(TAfin* t,ColorRGB* c,GLdouble ri,GLdouble re,GLdouble nL,GLdouble nR);
                virtual ~Disco();
                void dibuja();
};
