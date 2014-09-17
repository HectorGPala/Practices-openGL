//HECTOR GUTIERREZ PALANCAREJO 05305699J
//---------------------------------------------------------------------------

#ifndef CuadradoH
#define CuadradoH

#include "PVD2.h"
#include "Math.h"
//---------------------------------------------------------------------------

class Cuadrado{
        private:
                PVD2* coordenada[4];
                float rojo,verde,azul;
                bool selec;
        public:
                Cuadrado();
                Cuadrado(PVD2 *centro,GLdouble l); //cuadrado inicial
                ~Cuadrado();
                void setIesima(int i,PVD2 *p);
                void setColor(float r,float g,float b);
                PVD2* getIesima(int i);
                void drawCuadrado();
                GLdouble getLado();
                bool seleccionado(PVD2* p);
                void deseleccionar(){selec = false;};
                void seleccionar(){selec = true;};
};

#endif
