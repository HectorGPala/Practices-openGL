//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#ifndef CamaraH
#define CamaraH
#include <gl\gl.h>
#include <gl\glu.h>

#include "PV3D.h"
//---------------------------------------------------------------------------
#endif

class Camara{
        private:
                PV3D *eye, *look, *up;
                PV3D *u, *v, *n;
                GLdouble left, right, top, bottom;
                GLdouble nearC, farC, fovyC, aspectC;
                void configAxisCam();
                void setModelViewMatrix();
                void proyOblicua(PV3D* d);
        public:
                Camara(PV3D* e,PV3D* l,PV3D* uu);
                ~Camara();
                void roll(GLdouble alfa);
                void yaw(GLdouble alfa);
                void pitch(GLdouble alfa);
                void configProjection(int i);
                void desplazar(GLdouble x,GLdouble y,GLdouble z);
                void recorridoEje(GLdouble x,GLdouble y,GLdouble z);
                void giraX(GLdouble alfa);
                void giraY(GLdouble alfa);
                void giraZ(GLdouble alfa);
                void viewLateral();
                void viewFrontal();
                void viewCenital();
                void viewEsquina(PV3D* e);
                PV3D* getEye(){return eye;};
                PV3D* getLook(){return look;};
                PV3D* getUP(){return up;}; 
};
