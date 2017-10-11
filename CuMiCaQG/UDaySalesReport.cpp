//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UDaySalesReport.h"
#include "num_a_letra.h"
#include "DataModule.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tfrmreporteventa *frmreporteventa;
//---------------------------------------------------------------------------
__fastcall Tfrmreporteventa::Tfrmreporteventa(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall Tfrmreporteventa::btnimprimirClick(TObject *Sender)
{
   AnsiString st;
   st = FormatDateTime("mm/dd/yyyy", DateTimePicker1->Date);

   DM->QDaySales1->SQL->Clear();
DM->QDaySales1->SQL->Add("SELECT * FROM VENTA WHERE FECHA = #"+st+"#");
DM->QDaySales1->Open();

DM->QDaySales2->SQL->Clear();
DM->QDaySales2->SQL->Add("SELECT sum(total_bs) as TOTAL FROM VENTA WHERE FECHA = #"+st+"#");
DM->QDaySales2->Open();
AnsiString sum= DM->QDaySales2->FieldByName("TOTAL")->Text;
   AnsiString s1="", s2="";
   st = "";
   int i;

i=sum.Pos(",");
if(i!=0){
        s1=sum.SubString(1,i-1);
        st=sum.SubString(i+1,sum.Length()-i);
        QRLabel9->Caption=convertir(s1.c_str());
        QRLabel6->Caption=st+"/100 Bs.";
}
else
{
     QRLabel9->Caption=convertir(sum.c_str());
     QRLabel6->Caption="00/100 Bs.";
}
QuickRep1->PreviewModal();

}
//---------------------------------------------------------------------------
void __fastcall Tfrmreporteventa::btnsalirClick(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void __fastcall Tfrmreporteventa::FormActivate(TObject *Sender)
{
   DateTimePicker1->Date = Now();   
}
//---------------------------------------------------------------------------

