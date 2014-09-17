//Hector Gutierrez Palancarejo
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormSeleccion.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormS *FormS;
//---------------------------------------------------------------------------
__fastcall TFormS::TFormS(TComponent* Owner,double &x)
        : TForm(Owner),n(x)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormS::BotonClick(TObject *Sender)
{
        try {
                n = atof(Datos->Text.c_str());
                ModalResult = mrOk;
        }
        catch (const Exception &e) {
                     ShowMessage(e.Message);
        }
}
//---------------------------------------------------------------------------


