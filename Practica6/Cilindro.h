//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#ifndef CilindroH
#define CilindroH

#include "ObjetoCuadrico.h"
//---------------------------------------------------------------------------
#endif

class Cilindro : public ObjetoCuadrico{
    private:
        GLdouble rBase;
        GLdouble rBase2;
        GLdouble h;
        GLint numM;
        GLint numP;
    public:
        Cilindro(TAfin* m,ColorRGB* c,GLdouble rb,GLdouble rb2,GLdouble h,GLint nM,GLint nP);
        virtual ~Cilindro(){};
        void dibuja();
};
