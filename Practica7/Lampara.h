//---------------------------------------------------------------------------

#ifndef LamparaH
#define LamparaH

#include "Cilindro.h"
#include "Disco.h"
#include "ObjetoCompuesto3D.h"
//---------------------------------------------------------------------------

class Lampara : public ObjetoCompuesto3D{
        private:
                GLfloat alfa;
                GLfloat b;
                GLfloat posX,posY,posZ;
        public:
                Lampara();
                ~Lampara(){};
                void escalaLampara(GLdouble x, GLdouble y, GLdouble z);                
};



#endif
