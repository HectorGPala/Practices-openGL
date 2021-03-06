//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#ifndef MallaH
#define MallaH

#include "Cara.h"
#include "PV3D.h"

//---------------------------------------------------------------------------

class Malla{
        protected:
                int numVertices;
                PV3D** vertices;
                int numNormales;
                PV3D** normales;
                int numCaras;
                Cara** caras;
        public:
                Malla(int nV,int nN, int nC,PV3D** vertices,PV3D** normales,Cara** cara);
                ~Malla();
                void dibuja(bool lines);
                void drawNormals();
                int getNumVertices(){return numVertices;};
                int getNumNormales(){return numNormales;};
                int getNumCaras(){return numCaras;};
                PV3D* calculoNormalNewell(Cara* c);
};

#endif
