//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#ifndef ColorRGBH
#define ColorRGBH

#include <gl\gl.h>
#include <gl\glu.h>
//---------------------------------------------------------------------------
#endif

class ColorRGB{
        private:
                GLdouble red;
                GLdouble green;
                GLdouble blue;
        public:
                ColorRGB(GLdouble ,GLdouble g,GLdouble b);
                ~ColorRGB(){};
                GLdouble getRed(){return red;};
                GLdouble getGreen(){return green;};
                GLdouble getBlue(){return blue;};
};
