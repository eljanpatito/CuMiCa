//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SegProductos.h"
#include "DataModule.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfRepSeguimiento *fRepSeguimiento;
//---------------------------------------------------------------------------
__fastcall TfRepSeguimiento::TfRepSeguimiento(TComponent* Owner)
   : TForm(Owner)
{
}
//---------------------------------------------------------------------------
