//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit7.h"
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
Query1->SQL->Clear();
Query1->SQL->Add("select * from producto order by codigo");
Query1->Open();
QuickRep1->PreviewModal();
}
//---------------------------------------------------------------------------


void __fastcall Tfrmrepproducto::Button2Click(TObject *Sender)
{
Query1->SQL->Clear();
Query1->SQL->Add("select * from producto order by descripcion");
Query1->Open();
QuickRep1->PreviewModal();
}
//---------------------------------------------------------------------------
void __fastcall Tfrmrepproducto::btnsalirClick(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
