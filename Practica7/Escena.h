//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#ifndef EscenaH
#define EscenaH

#include "MesaBillar.h"
#include "GrupoBolas.h"
#include "ObjetoCompuesto3D.h"

//---------------------------------------------------------------------------


class Escena : public ObjetoCompuesto3D{
        public:
                Escena(unsigned int *tx);
                ~Escena(){};
};
#endif
