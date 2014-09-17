//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#ifndef CaraH
#define CaraH
#include "VerticeNormal.h"
//---------------------------------------------------------------------------
#endif

class Cara{
        private:
                int numVertices;
                VerticeNormal** arrayVN;
        public:
                Cara(int n, VerticeNormal** vn);
                ~Cara();
                int getNumVertices(){return numVertices;};
                VerticeNormal* getIndice(int n){return arrayVN[n];};
};
 
