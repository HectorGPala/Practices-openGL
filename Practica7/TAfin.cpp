//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TAfin.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

TAfin::TAfin(){
        m[0] = 1; m[4] = 0; m[8] = 0;  m[12] = 0;
        m[1] = 0; m[5] = 1; m[9] = 0;  m[13] = 0;
        m[2] = 0; m[6] = 0; m[10] = 1; m[14] = 0;
        m[3] = 0; m[7] = 0; m[11] = 0; m[15] = 1;
}

TAfin::TAfin(GLdouble mm[16]){
        for(int i = 0; i < 16;i++)
                m[i] = mm[i];
}

void TAfin::postMultiplica(GLdouble mm[16]){
        GLdouble auxM[16];
        for(int i=0;i<16;i++)
                auxM[i] = m[i];
        for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                        int pos = (4*i)+j;
                        m[pos] = 0;
                        for(int k=0;k<4;k++)
                                m[pos] += auxM[(4*k)+j]*mm[(4*i)+k];
               }
        }
}

void TAfin::trasladar(GLdouble x, GLdouble y, GLdouble z){
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
                glLoadIdentity();
                glTranslated(x,y,z);
                GLdouble* mm = new GLdouble[16];
                glGetDoublev(GL_MODELVIEW_MATRIX,mm);
        glPopMatrix();
        postMultiplica(mm);
}

void TAfin::girar(GLdouble alfa, GLdouble x, GLdouble y, GLdouble z){
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
                glLoadIdentity();
                glRotated(alfa,x,y,z);
                GLdouble* mm = new GLdouble[16];
                glGetDoublev(GL_MODELVIEW_MATRIX,mm);
        glPopMatrix();
        postMultiplica(mm);
}

void TAfin::escalar(GLdouble x, GLdouble y, GLdouble z){
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
                glLoadIdentity();
                glScaled(x,y,z);
                GLdouble* mm = new GLdouble[16];
                glGetDoublev(GL_MODELVIEW_MATRIX,mm);
        glPopMatrix();
        postMultiplica(mm);
}

void TAfin::getMatrix(GLdouble mm[16]){
        for(int i = 0; i < 16;i++)
                mm[i] = m[i];
}
