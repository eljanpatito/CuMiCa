//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "USalesByEmployeeReport.h"
#include "DataModule.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tfrmventaempleado *frmventaempleado;
//---------------------------------------------------------------------------
__fastcall Tfrmventaempleado::Tfrmventaempleado(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tfrmventaempleado::btnimprimirClick(TObject *Sender)
{
if(dpini->Date>dpfin->Date)
{
   Application->MessageBox("La fecha inicial debe ser menor o igual a fecha final","OK",MB_OK | MB_ICONINFORMATION);
   return;
   }
AnsiString ini="",s= dpini->Date,s1,s2,s3,st;
int i;
i=s.Pos("/");
s1=s.SubString(1,i-1);
st=s.SubString(i+1,s.Length()-i);
i=st.Pos("/");
s2=st.SubString(1,i-1);
st=st.SubString(i+1,s.Length()-(i+1));
i=st.Pos("/");
s3=st.SubString(1,i-1);
st=st.SubString(i+1,s.Length()-(i+1));
st=s2+"/"+s1+"/"+st;
ini=st;
s= dpfin->Date;
i=s.Pos("/");
s1=s.SubString(1,i-1);
st=s.SubString(i+1,s.Length()-i);
i=st.Pos("/");
s2=st.SubString(1,i-1);
st=st.SubString(i+1,s.Length()-(i+1));
i=st.Pos("/");
s3=st.SubString(1,i-1);
st=st.SubString(i+1,s.Length()-(i+1));
st=s2+"/"+s1+"/"+st;
   if (!DM->TSalesByEmployee->Active) {
      DM->TSalesByEmployee->Active = true;
   }
DM->QSalesByEmployee1->SQL->Clear();
DM->QSalesByEmployee1->SQL->Add("SELECT * FROM v_e WHERE FECHA >= #"+ini+"# and FECHA <= #"+st+"# ORDER BY EMPLEADO.NOMBRE_COMPLETO,VENTA.FECHA;");
DM->QSalesByEmployee1->Open();
QRLabel2->Caption="Desde "+dpini->Date+" Hasta "+dpfin->Date;
//Table1->DeleteTable();
//Table1->Refresh();
DM->TSalesByEmployee->First();
while(!DM->TSalesByEmployee->Eof)
{
  DM->TSalesByEmployee->Delete();
  DM->TSalesByEmployee->Refresh();
  DM->TSalesByEmployee->First();
}
DM->QSalesByEmployee1->First();
AnsiString nom=""; double suma=0;
while(!DM->QSalesByEmployee1->Eof)
{
   DM->TSalesByEmployee->Insert();
   if(nom != DBEdit1->Text)
   {
      if(nom!="")
      {
        DM->TSalesByEmployee->FieldByName("DOS")->Text="TOTAL";
        DM->TSalesByEmployee->FieldByName("TRES")->Text=AnsiString(suma)+" ";
        suma=0;
        DM->TSalesByEmployee->Post();
        DM->TSalesByEmployee->Refresh();
        DM->TSalesByEmployee->Insert();
        nom=DBEdit1->Text;
        DM->TSalesByEmployee->FieldByName("UNO")->Text=" "+nom;
      }
      else
      {
        DM->TSalesByEmployee->Insert();
        nom=DBEdit1->Text;
        DM->TSalesByEmployee->FieldByName("UNO")->Text=" "+nom;
      }
      DM->TSalesByEmployee->Post();
      DM->TSalesByEmployee->Refresh();

   }
   else
   {
     DM->TSalesByEmployee->FieldByName("UNO")->Text=" "+DBEdit2->Text;
     DM->TSalesByEmployee->FieldByName("DOS")->Text=DBEdit3->Text;
     DM->TSalesByEmployee->FieldByName("TRES")->Text=DBEdit4->Text+" ";
     DM->TSalesByEmployee->Post();
     DM->TSalesByEmployee->Refresh();
     suma=suma+DBEdit4->Text.ToDouble();
     DM->QSalesByEmployee1->Next();
   }
}
if(suma>0){
        DM->TSalesByEmployee->Insert();
        DM->TSalesByEmployee->FieldByName("TRES")->Text=AnsiString(suma)+" ";
        DM->TSalesByEmployee->Post();
        DM->TSalesByEmployee->Refresh();
}

DM->TSalesByEmployee->Close();DM->TSalesByEmployee->Open();
QuickRep1->PreviewModal();
}
//---------------------------------------------------------------------------


void __fastcall Tfrmventaempleado::btnsalirClick(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall Tfrmventaempleado::FormActivate(TObject *Sender)
{
   dpini->Date = Now();
   dpfin->Date = Now();   
}
//---------------------------------------------------------------------------

