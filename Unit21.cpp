//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit21.h"
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
Query1->SQL->Clear();
Query1->SQL->Add("SELECT * FROM v_e WHERE FECHA >= #"+ini+"# and FECHA <= #"+st+"# ORDER BY EMPLEADO.NOMBRE_COMPLETO,VENTA.FECHA;");
Query1->Open();
QRLabel2->Caption="Desde "+dpini->Date+" Hasta "+dpfin->Date;
//Table1->DeleteTable();
//Table1->Refresh();
Table1->First();
while(!Table1->Eof)
{
  Table1->Delete();
  Table1->Refresh();
  Table1->First();
}
Query1->First();
AnsiString nom=""; double suma=0;
while(!Query1->Eof)
{
   Table1->Insert();
   if(nom != DBEdit1->Text)
   {
      if(nom!="")
      {
        Table1->FieldByName("DOS")->Text="TOTAL";
        Table1->FieldByName("TRES")->Text=AnsiString(suma)+" ";
        suma=0;
        Table1->Post();
        Table1->Refresh();
        Table1->Insert();
        nom=DBEdit1->Text;
        Table1->FieldByName("UNO")->Text=" "+nom;
      }
      else
      {
        Table1->Insert();
        nom=DBEdit1->Text;
        Table1->FieldByName("UNO")->Text=" "+nom;
      }
      Table1->Post();
      Table1->Refresh();

   }
   else
   {
     Table1->FieldByName("UNO")->Text=" "+DBEdit2->Text;
     Table1->FieldByName("DOS")->Text=DBEdit3->Text;
     Table1->FieldByName("TRES")->Text=DBEdit4->Text+" ";
     Table1->Post();
     Table1->Refresh();
     suma=suma+DBEdit4->Text.ToDouble();
     Query1->Next();
   }
}
if(suma>0){
        Table1->Insert();
        Table1->FieldByName("TRES")->Text=AnsiString(suma)+" ";
        Table1->Post();
        Table1->Refresh();
}

Table1->Close();Table1->Open();
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

