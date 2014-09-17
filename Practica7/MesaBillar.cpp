//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MesaBillar.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

MesaBillar::MesaBillar(unsigned int *tx):ObjetoCompuesto3D(13,new TAfin(),new ColorRGB(0,0,0)){
        Tablero* pata0 = new Tablero(1,1,5,4,4,10,new ColorRGB(0.5,0.3,0.05),new TAfin(),tx,0);
        Tablero* pata1 = new Tablero(1,1,5,4,4,10,new ColorRGB(0.5,0.3,0.05),new TAfin(),tx,0);
        Tablero* pata2 = new Tablero(1,1,5,4,4,10,new ColorRGB(0.5,0.3,0.05),new TAfin(),tx,0);
        Tablero* pata3 = new Tablero(1,1,5,4,4,10,new ColorRGB(0.5,0.3,0.05),new TAfin(),tx,0);

        pata0->trasladar(0,0,10);
        pata1->trasladar(5,0,10);
        pata2->trasladar(5,0,0);

        addObjeto3D(pata0);
        addObjeto3D(pata1);
        addObjeto3D(pata2);
        addObjeto3D(pata3);

        Tablero* base = new Tablero(11,6,0.5,4,4,4,new ColorRGB(0.5,0.3,0.05),new TAfin(),tx,0);
        base->trasladar(0,5,0);
        addObjeto3D(base);

        Tablero* base2 = new Tablero(9,4,0.5,4,4,4,new ColorRGB(0,1,0),new TAfin(),tx,1);
        base2->trasladar(1,5.5,1);
        addObjeto3D(base2);

        Tablero* borde1 = new Tablero(11,1,1.5,4,4,4,new ColorRGB(0.5,0.3,0.05),new TAfin(),tx,0);
        borde1->trasladar(5,5,0);
        addObjeto3D(borde1);

        Tablero* borde2 = new Tablero(11,1,1.5,4,4,4,new ColorRGB(0.5,0.3,0.05),new TAfin(),tx,0);
        borde2->trasladar(0,5,0);
        addObjeto3D(borde2);

        Tablero* borde3 = new Tablero(1,5,1.5,4,4,4,new ColorRGB(0.5,0.3,0.05),new TAfin(),tx,0);
        borde3->trasladar(1,5,0);
        addObjeto3D(borde3);

        Tablero* borde4 = new Tablero(1,5,1.5,4,4,4,new ColorRGB(0.5,0.3,0.05),new TAfin(),tx,0);
        borde4->trasladar(1,5,10);
        addObjeto3D(borde4);

        TAfin* t = new TAfin();
        t->trasladar(-1,6.7,1);
        t->girar(45,0,1,0);
        Cilindro* taco = new Cilindro(t,new ColorRGB(0.5,0.3,0.05),0.2,0.1,15,10,10);
        addObjeto3D(taco);

        Tablero* tiza = new Tablero(0.5,0.5,0.5,4,4,4,new ColorRGB(1,0,0),new TAfin(),tx,-1);
        tiza->trasladar(5.26,6.5,1);
        addObjeto3D(tiza);

        Tablero* tapa_tiza = new Tablero(0.5,0.5,0.1,4,4,4,new ColorRGB(0,0,1),new TAfin(),tx,-1);
        tapa_tiza->trasladar(5.26,7,1);
        addObjeto3D(tapa_tiza);
}
