//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Objeto3D.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

Objeto3D::Objeto3D(TAfin* mm,ColorRGB* co){
        m = mm;
        c = co;
}

Objeto3D::~Objeto3D(){
        delete m;
        delete c;
}
