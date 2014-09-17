//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#ifndef FormSeleccionH
#define FormSeleccionH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>

//---------------------------------------------------------------------------
class TFormS : public TForm
{
__published:	// IDE-managed Components
        TEdit *Datos;
        TButton *Boton;
        void __fastcall BotonClick(TObject *Sender);
private:	// User declarations
        double &n;
public:		// User declarations
        __fastcall TFormS(TComponent* Owner,double &x);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormS *FormS;
//---------------------------------------------------------------------------
#endif
