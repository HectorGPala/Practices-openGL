//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#ifndef PixmapH
#define PixmapH
#include <gl\gl.h>
#include <gl\glu.h>
#include <Math.h>
#include <string>
#define _USE_MATH_DEFINES
using namespace std;

//---------------------------------------------------------------------------

typedef GLubyte colorRGBA[3];

class Pixmap{
        private:
                int rows;
                int cols;
                bool rgb;
                colorRGBA* matrix;
                colorRGBA* interpolacionBilineal(int i,int j,GLdouble newI,GLdouble newJ);

        public:
                Pixmap();
                Pixmap(const string &f);
                ~Pixmap();
                void readFrameBuffer(int r,int c);
                void drawPixmap(int x,int y);
                void convertirA_YIQ();
                void convertirA_RGB();
                void rotar(GLdouble alfa,int x, int y);
                void mediaPonderada(double k,Pixmap *p);
                void diferencia(Pixmap *p);
                void suavizadoGaussiano();
                int getRows(){return rows;};
                int getCols(){return cols;};
                colorRGBA* getMatrix(){return matrix;};
};

#endif
