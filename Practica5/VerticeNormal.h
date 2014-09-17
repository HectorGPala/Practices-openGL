//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#ifndef VerticeNormalH
#define VerticeNormalH
//---------------------------------------------------------------------------
#endif

class VerticeNormal{
        private:
                int indiceVertice;
                int indiceNormal;
        public:
                VerticeNormal(int iV,int iN);
                ~VerticeNormal(){};
                int get_indiceVertice(){return indiceVertice;};
                int get_indiceNormal(){return indiceNormal;};
};
