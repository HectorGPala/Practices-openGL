//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#ifndef EscenaH
#define EscenaH
#include "Arbol.h"
//---------------------------------------------------------------------------

class Escena{
        private:
                GLfloat xL,xR,yT,yB;
                Arbol* arbolito;

        public:
                Escena(GLfloat xl,GLfloat xr,GLfloat yt,GLfloat yb);
                ~Escena();
                void set(GLfloat xl,GLfloat xr,GLfloat yt,GLfloat yb);
                Arbol* getArbol();
                void drawEscena();
                Cuadrado* selCuadrado(PVD2* p);
};

#endif
