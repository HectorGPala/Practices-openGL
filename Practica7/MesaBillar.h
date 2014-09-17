//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#ifndef MesaBillarH
#define MesaBillarH

#include "Tablero.h"
#include "Cilindro.h"
#include "ObjetoCompuesto3D.h"
//---------------------------------------------------------------------------

class MesaBillar : public ObjetoCompuesto3D{
        public:
                MesaBillar(unsigned int *tx);
                ~MesaBillar(){};
};


#endif
