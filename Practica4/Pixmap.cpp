//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Pixmap.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

Pixmap::Pixmap(){
        rows = 0;
        cols = 0;
        rgb = true;
        matrix = NULL;
}

Pixmap::Pixmap(const string &f){
        Graphics::TBitmap* AuxBMP = new Graphics::TBitmap();
        AuxBMP->LoadFromFile(f.c_str());
        cols=AuxBMP->Width;
        rows=AuxBMP->Height;
        matrix = new colorRGBA[cols*rows];
        int c = 0;
        for (int i = 0; i < rows; i++)
                for (int j = 0; j < cols; j++) {
                        c = i * cols + j;
                        matrix[c][0]=GetRValue(AuxBMP->Canvas->Pixels[j][rows-i-1]);
                        matrix[c][1]=GetGValue(AuxBMP->Canvas->Pixels[j][rows-i-1]);
                        matrix[c][2]=GetBValue(AuxBMP->Canvas->Pixels[j][rows-i-1]);
                }
}

Pixmap::~Pixmap(){
        delete[] matrix;
}
void Pixmap::readFrameBuffer(int r, int c){
        if(matrix != NULL)
                delete[] matrix;
        rows = r;
        cols = c;
        matrix = new colorRGBA[cols*rows];
        glPixelStorei(GL_PACK_ALIGNMENT,1);
        glReadPixels(0,0,cols,rows,GL_RGB,GL_UNSIGNED_BYTE,matrix);
        /*for(int i = 0; i < rows;i++)
                        for(int j = 0; j < cols;j++){
                                int c = i * cols + j;
                                matrix[c][0] = matrix1[c][0];
                                matrix[c][1] = matrix1[c][1];
                                matrix[c][2] = matrix1[c][2];
                        }*/
}

void Pixmap::drawPixmap(int x,int y){
        if(matrix != NULL){
                glPixelStorei(GL_UNPACK_ALIGNMENT,1);
                glRasterPos2i(x,y);
                if(rgb)
                        glDrawPixels(cols,rows,GL_RGB,GL_UNSIGNED_BYTE,matrix);
                else
                        glDrawPixels(cols,rows,GL_LUMINANCE,GL_UNSIGNED_BYTE,matrix);
        }
}

void Pixmap::convertirA_YIQ(){
        if(matrix != NULL && rgb){
                colorRGBA aux;
                for(int i = 0; i < rows;i++)
                        for(int j = 0; j < cols;j++){
                                int c = i * cols + j;
                                aux[0] = matrix[c][0]*0.299+matrix[c][1]*0.587+matrix[c][2]*0.114;
                                aux[1] = 0;//matrix[c][0]*0.596-matrix[c][1]*0.274-matrix[c][2]*0.322;
                                aux[2] = 0;//matrix[c][0]*0.211-matrix[c][1]*0.523+matrix[c][2]*0.312;
                                matrix[c][0] = aux[0];
                                matrix[c][1] = aux[1];
                                matrix[c][2] = aux[2];
                        }
                rgb = false;
        }
}

void Pixmap::convertirA_RGB(){
        if(matrix != NULL && !rgb){
                colorRGBA aux;
                for(int i = 0; i < rows;i++)
                        for(int j = 0; j < cols;j++){
                                int c = i * cols + j;
                                aux[0] = matrix[c][0]*1.0+matrix[c][1]*0.956+matrix[c][2]*0.621;
                                aux[1] = matrix[c][0]*1.0-matrix[c][1]*0.272-matrix[c][2]*0.647;
                                aux[2] = matrix[c][0]*1.0-matrix[c][1]*1.106-matrix[c][2]*1.703;
                                matrix[c][0] = aux[0];
                                matrix[c][1] = aux[1];
                                matrix[c][2] = aux[2];
                        }
                rgb = true;
        }
}

void Pixmap::rotar(GLdouble alfa,int x,int y){
        //al rotar se pierden pixeles!
        if(matrix != NULL){
                GLdouble coseno = cos((alfa*M_PI)/180.0);
                GLdouble seno = sin((alfa*M_PI)/180.0);
                GLdouble dx = x - x*coseno + y*seno;//respecto del centro
                GLdouble dy = y - x*seno - y*coseno;
                colorRGBA* aux = new colorRGBA[rows*cols];
                int c;
                colorRGBA* aux2;
                for(int i = 0; i < rows;i++)
                        for(int j = 0; j < cols;j++){
                                c = i * cols + j;
                                GLdouble newI = j*seno + i*coseno + dy;
                                GLdouble newJ = j*coseno - i*seno + dx;
                                aux2 = interpolacionBilineal(i,j,newI,newJ);
                                aux[c][0] = aux2[0][0];
                                aux[c][1] = aux2[0][1];
                                aux[c][2] = aux2[0][2];
                                delete[] aux2;
                        }
                delete[] matrix;//borro matriz vieja
                matrix = new colorRGBA[rows*cols];
                for(int i = 0; i < rows;i++)//COPIAAAAA
                        for(int j = 0; j < cols;j++){
                                c = i * cols + j;
                                matrix[c][0] = aux [c][0];
                                matrix[c][1] = aux [c][1];
                                matrix[c][2] = aux [c][2];
                        }
                delete[] aux;
        }
}

colorRGBA* Pixmap::interpolacionBilineal(int i,int j,GLdouble newI,GLdouble newJ){
        colorRGBA* r = new colorRGBA[1];
        if((0 <  newJ && newJ < cols-1) && (0 < newI && newI < rows-1)){
                int xx = floor(newJ);
                int yy = floor(newI);
                GLdouble deltaX = newJ-xx;
                GLdouble deltaY = newI-yy;

                r[0][0] = (1-deltaX)*(1-deltaY)*matrix[yy*cols+xx][0]+
                (1-deltaX)*deltaY*matrix[yy*cols+xx+1][0]+
                deltaX*deltaY*matrix[(yy+1)*cols+xx+1][0]+
                deltaX*(1-deltaY)*matrix[(yy+1)*cols+xx][0];

                r[0][1] = (1-deltaX)*(1-deltaY)*matrix[yy*cols+xx][1]+
                (1-deltaX)*deltaY*matrix[yy*cols+xx+1][1]+
                deltaX*deltaY*matrix[(yy+1)*cols+xx+1][1]+
                deltaX*(1-deltaY)*matrix[(yy+1)*cols+xx][1];

                r[0][2] = (1-deltaX)*(1-deltaY)*matrix[yy*cols+xx][2]+
                (1-deltaX)*deltaY*matrix[yy*cols+xx+1][2]+
                deltaX*deltaY*matrix[(yy+1)*cols+xx+1][2]+
                deltaX*(1-deltaY)*matrix[(yy+1)*cols+xx][2];
        }
        else{
                r[0][0] = 255;
                r[0][1] = 255;
                r[0][2] = 255;
        }
        return r;
}

void Pixmap::mediaPonderada(double k,Pixmap *p){
        if(p->rows == rows && p->cols == cols){
                for(int i = 0; i < rows;i++)
                        for(int j = 0; j < cols;j++){
                                int c = i * cols + j;
                                matrix[c][0] = k*matrix[c][0]+(1-k)*p->matrix[c][0];
                                matrix[c][1] = k*matrix[c][1]+(1-k)*p->matrix[c][1];
                                matrix[c][2] = k*matrix[c][2]+(1-k)*p->matrix[c][2];
                        }
        }
}

void Pixmap::diferencia(Pixmap *p){
        convertirA_YIQ();
        p->convertirA_YIQ();
        convertirA_RGB();
        p->convertirA_RGB();
        if(p->rows == rows && p->cols == cols){
                for(int i = 0; i < rows;i++)
                                for(int j = 0; j < cols;j++){
                                        int c = i * cols + j;
                                        matrix[c][0] = abs(matrix[c][0]-p->matrix[c][0]);
                                        matrix[c][1] = abs(matrix[c][1]-p->matrix[c][1]);
                                        matrix[c][2] = abs(matrix[c][2]-p->matrix[c][2]);
                                }
        }
}

void Pixmap::suavizadoGaussiano(){
        GLdouble m[9];
        m[0] = 0.095; m[1] = 0.118; m[2] = 0.095;
        m[3] = 0.118; m[4] = 0.148; m[5] = 0.118;
        m[6] = 0.095; m[7] = 0.118; m[8] = 0.095;

        colorRGBA* aux = new colorRGBA[rows*cols];
        for(int i = 1; i < rows-1;i++)
                        for(int j = 1; j < cols/2;j++){
                                int c = i * cols + j;
                                aux[c][0] = m[4]*matrix[c][0]+m[3]*matrix[c-1][0]+m[5]*matrix[c+1][0]+
                                m[0]*matrix[(i+1) * cols + j-1][0]+m[1]*matrix[(i+1) * cols + j][0]+
                                m[2]*matrix[(i+1) * cols + j+1][0]+m[6]*matrix[(i-1) * cols + j-1][0]+
                                m[7]*matrix[(i-1) * cols + j][0]+m[8]*matrix[(i-1) * cols + j+1][0];

                                aux[c][1] = m[4]*matrix[c][1]+m[3]*matrix[c-1][1]+m[5]*matrix[c+1][1]+
                                m[0]*matrix[(i+1) * cols + j-1][1]+m[1]*matrix[(i+1) * cols + j][1]+
                                m[2]*matrix[(i+1) * cols + j+1][1]+m[6]*matrix[(i-1) * cols + j-1][1]+
                                m[7]*matrix[(i-1) * cols + j][1]+m[8]*matrix[(i-1) * cols + j+1][1];

                                aux[c][2] = m[4]*matrix[c][2]+m[3]*matrix[c-1][2]+m[5]*matrix[c+1][2]+
                                m[0]*matrix[(i+1) * cols + j-1][2]+m[1]*matrix[(i+1) * cols + j][2]+
                                m[2]*matrix[(i+1) * cols + j+1][2]+m[6]*matrix[(i-1) * cols + j-1][2]+
                                m[7]*matrix[(i-1) * cols + j][2]+m[8]*matrix[(i-1) * cols + j+1][2];
                        }
        for(int i = 1; i < rows-1;i++)//COPIAAA
                        for(int j = 1; j < cols/2;j++){
                                int c = i * cols + j;
                                matrix[c][0] = aux[c][0];
                                matrix[c][1] = aux[c][1];
                                matrix[c][2] = aux[c][2];
                        }
        delete[] aux;
}

