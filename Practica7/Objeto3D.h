//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#ifndef Objeto3DH
#define Objeto3DH

#include "ColorRGB.h"
#include "TAfin.h"
//---------------------------------------------------------------------------


class Objeto3D{
        protected:
                TAfin* m;
                ColorRGB* c;
        public:
                Objeto3D(TAfin* mm,ColorRGB* co);
                virtual ~Objeto3D();
                virtual void dibuja()=0;
};
#endif
