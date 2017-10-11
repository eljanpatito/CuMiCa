//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UProductReport.h"
#include "DataModule.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tfrmrepproducto *frmrepproducto;
//---------------------------------------------------------------------------
__fastcall Tfrmrepproducto::Tfrmrepproducto(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------



void __fastcall Tfrmrepproducto::Button1Click(TObject *Sender)
{
DM->QProductList->SQL->Clear();
DM->QProductList->SQL->Add("select * from producto order by codigo");
DM->QProductList->Open();
QuickRep1->PreviewModal();
}
//---------------------------------------------------------------------------


void __fastcall Tfrmrepproducto::Button2Click(TObject *Sender)
{
DM->QProductList->SQL->Clear();
DM->QProductList->SQL->Add("select * from producto order by descripcion");
DM->QProductList->Open();
QuickRep1->PreviewModal();
}
//---------------------------------------------------------------------------
void __fastcall Tfrmrepproducto::btnsalirClick(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
