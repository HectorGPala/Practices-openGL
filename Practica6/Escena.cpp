//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Escena.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

Escena::Escena(){
        lista = new ObjetoCompuesto3D(11+16+2,new TAfin(),new ColorRGB(0,0,0));
        creaPatas();
        creaMarco();
        creaBolas();
        creaTacoTiza();

}

void Escena::dibuja(){
        lista->dibuja();
}

void Escena::escalar(GLdouble x,GLdouble y,GLdouble z){
        lista->escalar(x,y,z);
}

void Escena::girar(GLdouble alfa,GLdouble x,GLdouble y,GLdouble z){
        lista->girar(alfa,x,y,z);
}

void Escena::transladar(GLdouble x,GLdouble y,GLdouble z){
        lista->trasladar(x,y,z);
}

void Escena::creaPatas(){
        Tablero* pata0 = new Tablero(1,1,5,new ColorRGB(0.5,0.3,0.05),new TAfin());
        Tablero* pata1 = new Tablero(1,1,5,new ColorRGB(0.5,0.3,0.05),new TAfin());
        Tablero* pata2 = new Tablero(1,1,5,new ColorRGB(0.5,0.3,0.05),new TAfin());
        Tablero* pata3 = new Tablero(1,1,5,new ColorRGB(0.5,0.3,0.05),new TAfin());

        pata0->trasladar(0,0,10);
        pata1->trasladar(5,0,10);
        pata2->trasladar(5,0,0);
        //pata3->trasladar(5,0,10);

        lista->addObjeto3D(pata0);
        lista->addObjeto3D(pata1);
        lista->addObjeto3D(pata2);
        lista->addObjeto3D(pata3);
}

void Escena::creaMarco(){
        Tablero* base = new Tablero(11,6,0.5,new ColorRGB(0.5,0.3,0.05),new TAfin());
        base->trasladar(0,5,0);
        lista->addObjeto3D(base);

        Tablero* base2 = new Tablero(9,4,0.5,new ColorRGB(0,1,0),new TAfin());
        base2->trasladar(1,5.5,1);
        lista->addObjeto3D(base2);

        Tablero* borde1 = new Tablero(11,1,1.5,new ColorRGB(0.5,0.3,0.05),new TAfin());
        borde1->trasladar(5,5,0);
        lista->addObjeto3D(borde1);

        Tablero* borde2 = new Tablero(11,1,1.5,new ColorRGB(0.5,0.3,0.05),new TAfin());
        borde2->trasladar(0,5,0);
        lista->addObjeto3D(borde2);

        Tablero* borde3 = new Tablero(1,5,1.5,new ColorRGB(0.5,0.3,0.05),new TAfin());
        borde3->trasladar(1,5,0);
        lista->addObjeto3D(borde3);

        Tablero* borde4 = new Tablero(1,5,1.5,new ColorRGB(0.5,0.3,0.05),new TAfin());
        borde4->trasladar(1,5,10);
        lista->addObjeto3D(borde4);
}

void Escena::creaBolas(){
        TAfin* t = new TAfin();
        t->trasladar(2,6.25,9);
        Esfera* bola0 = new Esfera(t,new ColorRGB(1,0,0),0.25,10,10);
        lista->addObjeto3D(bola0);

        t = new TAfin();
        t->trasladar(2.5,6.25,9);
        Esfera* bola1 = new Esfera(t,new ColorRGB(1,0.5,0),0.25,10,10);
        lista->addObjeto3D(bola1);

        t = new TAfin();
        t->trasladar(3,6.25,9);
        Esfera* bola2 = new Esfera(t,new ColorRGB(1,0,0.5),0.25,10,10);
        lista->addObjeto3D(bola2);

        t = new TAfin();
        t->trasladar(3.5,6.25,9);
        Esfera* bola3 = new Esfera(t,new ColorRGB(1,0.5,0.5),0.25,10,10);
        lista->addObjeto3D(bola3);

        t = new TAfin();
        t->trasladar(4,6.25,9);
        Esfera* bola4 = new Esfera(t,new ColorRGB(1,1,0),0.25,10,10);
        lista->addObjeto3D(bola4);
        //segunda fila
        t = new TAfin();
        t->trasladar(2.25,6.5,8.5);
        Esfera* bola5 = new Esfera(t,new ColorRGB(1,1,0.8),0.25,10,10);
        lista->addObjeto3D(bola5);

        t = new TAfin();
        t->trasladar(2.75,6.5,8.5);
        Esfera* bola6 = new Esfera(t,new ColorRGB(1,0.5,1),0.25,10,10);
        lista->addObjeto3D(bola6);

        t = new TAfin();
        t->trasladar(3.25,6.5,8.5);
        Esfera* bola7 = new Esfera(t,new ColorRGB(1,0,1),0.25,10,10);
        lista->addObjeto3D(bola7);

        t = new TAfin();
        t->trasladar(3.75,6.5,8.5);
        Esfera* bola8 = new Esfera(t,new ColorRGB(0,1,0.2),0.25,10,10);
        lista->addObjeto3D(bola8);
        //tercera fila
        t = new TAfin();
        t->trasladar(2.5,6.5,8);
        Esfera* bola9 = new Esfera(t,new ColorRGB(1,0.7,0.3),0.25,10,10);
        lista->addObjeto3D(bola9);

        t = new TAfin();
        t->trasladar(3,6.5,8); //bola negra
        Esfera* bola10 = new Esfera(t,new ColorRGB(0,0,0),0.25,10,10);
        lista->addObjeto3D(bola10);

        t = new TAfin();
        t->trasladar(3.5,6.5,8);
        Esfera* bola11 = new Esfera(t,new ColorRGB(1,0.6,0.4),0.25,10,10);
        lista->addObjeto3D(bola11);
        //cuarta fila
        t = new TAfin();
        t->trasladar(2.75,6.5,7.5);
        Esfera* bola12 = new Esfera(t,new ColorRGB(0.5,1,0.8),0.25,10,10);
        lista->addObjeto3D(bola12);

        t = new TAfin();
        t->trasladar(3.25,6.5,7.5);
        Esfera* bola13 = new Esfera(t,new ColorRGB(0.3,0.5,1),0.25,10,10);
        lista->addObjeto3D(bola13);
        //ultima fila
        t = new TAfin();
        t->trasladar(3,6.5,7);
        Esfera* bola14 = new Esfera(t,new ColorRGB(0.5,0.5,0.5),0.25,10,10);
        lista->addObjeto3D(bola14);
        //bola blanca
        t = new TAfin();
        t->trasladar(3,6.5,3);
        Esfera* bola15 = new Esfera(t,new ColorRGB(1,1,1),0.25,10,10);
        lista->addObjeto3D(bola15);
}

void Escena::creaTacoTiza(){
        TAfin* t = new TAfin();
        t->trasladar(-1,6.7,1);
        t->girar(45,0,1,0);
        Cilindro* taco = new Cilindro(t,new ColorRGB(0.5,0.3,0.05),0.2,0.1,15,10,10);
        lista->addObjeto3D(taco);

        Tablero* tiza = new Tablero(0.5,0.5,0.5,new ColorRGB(1,0,0),new TAfin());
        tiza->trasladar(5.26,6.5,1);
        lista->addObjeto3D(tiza);

        Tablero* tapa_tiza = new Tablero(0.5,0.5,0.1,new ColorRGB(0,0,1),new TAfin());
        tapa_tiza->trasladar(5.26,7,1);
        lista->addObjeto3D(tapa_tiza);
}
