//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#ifndef EsferaH
#define EsferaH

#include "ObjetoCuadrico.h"
//---------------------------------------------------------------------------

class Esfera : public ObjetoCuadrico{
        private:
                GLdouble r;
                GLint numM;
                GLint numP;
        public:
                Esfera(TAfin* t,ColorRGB* c,GLdouble radio,GLint nM,GLint nP);
                virtual ~Esfera();
                void dibuja();
};

#endif
