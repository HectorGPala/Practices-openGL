//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#ifndef RollerCoasterH
#define RollerCoasterH

#include "Malla.h"
//---------------------------------------------------------------------------
#endif

class RollerCoaster : public Malla {
        private:
                int nP;
                int nS;
                GLdouble radius;//radio del tubo
                PV3D** perfil;
                //funciones privadas:
                void generarPerfil(int nP,GLdouble r);
                void generarRoller();
                PV3D* generarVertice(GLdouble t,PV3D* p);
                PV3D* C(GLdouble t);
                PV3D* CP(GLdouble t);
                PV3D* CPP(GLdouble t);
        public:
                RollerCoaster(int nP, int nS,GLdouble r);
                ~RollerCoaster();
};
