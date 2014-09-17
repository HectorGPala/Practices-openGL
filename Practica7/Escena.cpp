//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Escena.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

Escena::Escena(unsigned int *tx):ObjetoCompuesto3D(2,new TAfin(),new ColorRGB(0,0,0)){
        GrupoBolas* gb = new GrupoBolas(5,new PV3D(2,6.25,9,1),0.25);
        addObjeto3D(gb);
        MesaBillar* ms = new MesaBillar(tx);
        addObjeto3D(ms);
}
