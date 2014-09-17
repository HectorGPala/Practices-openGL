//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "GrupoBolas.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

GrupoBolas::GrupoBolas(int n,PV3D* p1,GLdouble r):ObjetoCompuesto3D(nBolas(n)+1,new TAfin(),new ColorRGB(0,0,0)){
        this->r = r;
        p = p1;
        int aux = nBolas(n);
        GLdouble posX = 0;
        GLdouble posZ = 0;
        int nf = 0;
        int nb = 0;
        while(aux != 0){
                for(int i = 0; i < n;i++){
                        TAfin* t = new TAfin();
                        t->trasladar(p->getX()+posX,p->getY(),p->getZ()-posZ);
                        Esfera* bola0;
                        bola0 = new Esfera(t,generaColor(nb),r,10,10);
                        addObjeto3D(bola0);
                        posX += r*2;
                        nb++;
                }
                aux -= n;
                nf++;
                posZ += r*2;
                posX = r*nf;
                n--;
        }
        TAfin* t = new TAfin();
        t->trasladar(p->getX()+4*r,p->getY(),p->getZ()-posZ-4);
        Esfera* bolaBlanca;
        bolaBlanca = new Esfera(t,generaColor(20),0.25,10,10);
        addObjeto3D(bolaBlanca);

}

int GrupoBolas::nBolas(int n){
        int res = 0;
        while(n != 0){
                res += n;
                n--;
        }
        return res;
}

ColorRGB* GrupoBolas::generaColor(int n){
        switch(n){
                case 0:
                        return new ColorRGB(1,0,0);
                        break;
                case 1:
                        return new ColorRGB(1,1,0);
                        break;
                case 2:
                        new ColorRGB(1,0,1);
                        break;
                case 3:
                        new ColorRGB(0,0,1);
                        break;
                case 4:
                        new ColorRGB(0,1,1);
                        break;
                case 5:
                        new ColorRGB(0.5,0,0);
                        break;
                case 6:
                        new ColorRGB(0.5,0.5,0);
                        break;
                case 7:
                        new ColorRGB(0.5,0,0.5);
                        break;
                case 8:
                        new ColorRGB(0,0,0.5);
                        break;
                case 9:
                        new ColorRGB(0,0.5,0.5);
                        break;
                case 10:
                        new ColorRGB(0,0,0);
                        break;
                case 11:
                        new ColorRGB(1,0.6,0.4);
                        break;
                case 12:
                        new ColorRGB(0.5,1,0.8);
                        break;
                case 13:
                        new ColorRGB(0.3,0.5,1);
                        break;
                case 14:
                        new ColorRGB(0.5,0.5,0.5);
                        break;
                default:
                        new ColorRGB(1,1,1);
                        break;
        }
}
