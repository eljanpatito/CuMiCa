//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "RepVentasFecha.h"
#include "DataModule.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tfrmrepventasfecha *frmrepventasfecha;
//---------------------------------------------------------------------------
__fastcall Tfrmrepventasfecha::Tfrmrepventasfecha(TComponent* Owner)
   : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tfrmrepventasfecha::BitBtn1Click(TObject *Sender)
{
   ShortDateFormat = "dd/MM/yyyy";
   AnsiString dateFrom = dtpFrom->Date;
   AnsiString dateTo = dtpTo->Date;
   dateFrom = dateFrom.SubString(1,10);
   dateFrom = dateFrom.SubString(7,4)+"/"+dateFrom.SubString(4,2)+"/"+dateFrom.SubString(1,2);
   dateTo = dateTo.SubString(1,10);
   dateTo = dateTo.SubString(7,4)+"/"+dateTo.SubString(4,2)+"/"+dateTo.SubString(1,2);
   ShowMessage("From: "+dateFrom+" To: "+dateTo);

   DM->qVentasFecha->SQL->Clear();
   DM->qVentasFecha->SQL->Add("SELECT VENTA.FECHA, Sum(VENTA.TOTAL_BS) AS TOTAL");
   DM->qVentasFecha->SQL->Add("FROM VENTA");
   DM->qVentasFecha->SQL->Add("WHERE VENTA.FECHA>=#"+dateFrom+"# AND VENTA.FECHA<=#"+dateTo+"#");
   DM->qVentasFecha->SQL->Add("GROUP BY VENTA.FECHA");
   DM->qVentasFecha->SQL->Add("ORDER BY VENTA.FECHA DESC");
   DM->qVentasFecha->Open();
}
//---------------------------------------------------------------------------

void __fastcall Tfrmrepventasfecha::FormActivate(TObject *Sender)
{
   dtpFrom->Date = Now();
   dtpTo->Date = Now();   
}
//---------------------------------------------------------------------------

