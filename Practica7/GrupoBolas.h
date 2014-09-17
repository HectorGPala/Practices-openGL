//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#ifndef GrupoBolasH
#define GrupoBolasH

#include "Esfera.h"
#include "PV3D.h"
#include "ObjetoCompuesto3D.h"
//---------------------------------------------------------------------------
class GrupoBolas : public ObjetoCompuesto3D{
        private:
                GLdouble r;
                PV3D* p;//posicion de la primera bola
                int nBolas(int n);
                ColorRGB* generaColor(int n);
        public:
                GrupoBolas(int n,PV3D* p1,GLdouble r);
                ~GrupoBolas(){delete p;};

};

#endif
