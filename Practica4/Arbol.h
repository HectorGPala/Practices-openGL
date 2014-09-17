//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#ifndef ArbolH
#define ArbolH

#include <list>
#include "Cuadrado.h"
#include "Lapiz.h"
//#include "Math.h"
#define _USE_MATH_DEFINES
using namespace std;
//---------------------------------------------------------------------------

class Arbol{
        private:
                list< list<Cuadrado*>* >* arb;
                Lapiz* l;
                float rojo,verde,azul;
                Cuadrado* selec;

        public:
                Arbol();
                ~Arbol();
                void anidar(GLdouble x,GLdouble y,bool random,int tam);
                void desanidar();
                void drawArbol();
                bool empty();
                bool selCuadrado(PVD2* p);
                void desSelec();

};
#endif
