//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Cara.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

Cara::Cara(int n, VerticeNormal** vn){
        numVertices = n;
        arrayVN = vn;
}

Cara::~Cara(){
        for(int i = 0; i < numVertices; i++)
                delete arrayVN[i];
        delete[] arrayVN;
}
