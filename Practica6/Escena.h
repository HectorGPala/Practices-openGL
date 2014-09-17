//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#ifndef EscenaH
#define EscenaH

#include "ObjetoCompuesto3D.h"
//---------------------------------------------------------------------------
#endif

class Escena{
        private:
                ObjetoCompuesto3D* lista;
                void creaPatas();
                void creaMarco();
                void creaBolas();
                void creaTacoTiza();
        public:
                Escena();
                ~Escena(){};
                void dibuja();
                void escalar(GLdouble x,GLdouble y,GLdouble z);
                void girar(GLdouble alfa,GLdouble x,GLdouble y,GLdouble z);
                void transladar(GLdouble x,GLdouble y,GLdouble z);

};
