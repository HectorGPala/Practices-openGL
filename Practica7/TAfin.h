//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#ifndef TAfinH
#define TAfinH

#include <gl\gl.h>
#include <gl\glu.h>
//---------------------------------------------------------------------------
#endif

class TAfin{
        private:
                GLdouble m[16];
        public:
                TAfin();
                TAfin(GLdouble mm[16]);
                ~TAfin(){};
                void postMultiplica(GLdouble mm[16]);
                void trasladar(GLdouble x, GLdouble y, GLdouble z);
                void girar(GLdouble alfa, GLdouble x, GLdouble y, GLdouble z);
                void escalar(GLdouble x, GLdouble y, GLdouble z);
                void getMatrix(GLdouble mm[16]);
};
