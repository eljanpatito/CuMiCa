//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SegProductosForm.h"
#include "DataModule.h"
#include "SegProductos.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfSeguimiento *fSeguimiento;
//---------------------------------------------------------------------------
__fastcall TfSeguimiento::TfSeguimiento(TComponent* Owner)
   : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfSeguimiento::BitBtn1Click(TObject *Sender)
{
   fRepSeguimiento->QuickRep1->PreviewModal();   
}
//---------------------------------------------------------------------------
void __fastcall TfSeguimiento::Edit1Change(TObject *Sender)
{
   DM->qSeguimiento->Params->Items[0]->AsString = Edit1->Text;
   DM->qSeguimiento->Close();
   DM->qSeguimiento->Open();
   DM->qSumCajas->Params->Items[0]->AsString = Edit1->Text;
   DM->qSumCajas->Close();
   DM->qSumCajas->Open();
}
//---------------------------------------------------------------------------
