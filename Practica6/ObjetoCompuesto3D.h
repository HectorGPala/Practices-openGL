//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#ifndef ObjetoCompuesto3DH
#define ObjetoCompuesto3DH

#include "Objeto3D.h"
#include "Cilindro.h"
#include "Tablero.h"
#include "Disco.h"
#include "Esfera.h"
//---------------------------------------------------------------------------
#endif

class ObjetoCompuesto3D : public Objeto3D{
        protected:
                int numHijos;
                int actual;
                Objeto3D** hijos;
        public:
                ObjetoCompuesto3D(int n,TAfin* t,ColorRGB* c);
                virtual ~ObjetoCompuesto3D();
                void addObjeto3D(Objeto3D* o);
                void dibuja();
                void trasladar(GLdouble x, GLdouble y, GLdouble z);
                void girar(GLdouble alfa, GLdouble x, GLdouble y, GLdouble z);
                void escalar(GLdouble x, GLdouble y, GLdouble z);
};
