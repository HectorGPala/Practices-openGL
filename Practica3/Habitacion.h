//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#ifndef HabitacionH
#define HabitacionH

#include "Pelota.h"
#include "Triangulo.h"


//---------------------------------------------------------------------------

class Habitacion{
        private:
                Pelota* p;
                list<Obstaculo*>* listaObs;
                list<Obstaculo*>* listaCor;//cortezas
        public:
                Habitacion();
                ~Habitacion();
                void addObstaculo(Obstaculo* ob);
                void avanzaPelota();
                void generarCortezas();
                void quitarCortezas();
                void drawHabitacion(bool debug);
};

#endif
