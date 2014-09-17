//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#ifndef TableroH
#define TableroH

#include "Malla.h"
//---------------------------------------------------------------------------
#endif

class Tablero : public Malla{
        private:
                GLdouble largo;
                GLdouble ancho;
                GLdouble grueso;
        public:
                Tablero(GLdouble l,GLdouble a,GLdouble g,ColorRGB* c,TAfin* t);
                ~Tablero(){};
                void trasladar(GLdouble x, GLdouble y, GLdouble z);
                void girar(GLdouble alfa, GLdouble x, GLdouble y, GLdouble z);
                void escalar(GLdouble x, GLdouble y, GLdouble z);
};
