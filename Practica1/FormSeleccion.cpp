//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormSeleccion.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormS *FormS;
//---------------------------------------------------------------------------
__fastcall TFormS::TFormS(TComponent* Owner,int &x)
        : TForm(Owner),n(x)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormS::BotonClick(TObject *Sender)
{
        try {
                n = StrToInt(Datos->Text);
                ModalResult = mrOk;
        }
        catch (const Exception &e) {
                     ShowMessage(e.Message);
        }
}
//---------------------------------------------------------------------------
