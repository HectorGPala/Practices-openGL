//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#ifndef ObjetoCuadricoH
#define ObjetoCuadricoH

#include "Objeto3D.h"
//---------------------------------------------------------------------------


class ObjetoCuadrico : public Objeto3D{
        public:
                ObjetoCuadrico(TAfin* t,ColorRGB* c);
                ~ObjetoCuadrico(){};
                virtual void dibuja();
};

#endif
