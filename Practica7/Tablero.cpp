//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Tablero.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

Tablero::Tablero(GLdouble l,GLdouble a,GLdouble g,GLdouble rl,GLdouble ra,GLdouble rg,ColorRGB* c,TAfin* t,unsigned int *tx,int nt)
:ObjetoCompuesto3D(rl*ra*rg,t,c){
        largo = l;
        ancho = a;
        grueso = g;
        GLdouble largoC = l/rl;
        GLdouble anchoC = a/ra;
        GLdouble gruesoC = g/rg;
        for(int i = 0; i < ra;i++){
                for(int j = 0; j < rg;j++){
                        for(int k = 0; k < rl;k++){
                                TAfin* tc = new TAfin();
                                tc->trasladar(anchoC*i,gruesoC*j,largoC*k);
                                Cubo* cb = new Cubo(anchoC,largoC,gruesoC,c,tc,tx,nt);
                                addObjeto3D(cb);
                        }
                }
        }
}
