//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#ifndef TableroH
#define TableroH

#include "Cubo.h"
#include "ObjetoCompuesto3D.h"
//---------------------------------------------------------------------------


class Tablero : public ObjetoCompuesto3D{
        private:
                GLdouble largo;
                GLdouble ancho;
                GLdouble grueso;
        public:
                Tablero(GLdouble l,GLdouble a,GLdouble g,GLdouble rl,GLdouble ra,GLdouble rg,ColorRGB* c,TAfin* t,unsigned int *tx,int nt);
                ~Tablero(){};
};

#endif
