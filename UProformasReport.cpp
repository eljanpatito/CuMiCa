//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UProformasReport.h"
#include "DataModule.h"
//---------------------------------------------------------------------
#pragma resource "*.dfm"
Tfrmrepproforma *frmrepproforma;
//--------------------------------------------------------------------- 
__fastcall Tfrmrepproforma::Tfrmrepproforma(TComponent* AOwner)
	: TForm(AOwner)
{
}
//---------------------------------------------------------------------
void __fastcall Tfrmrepproforma::btnimprimirClick(TObject *Sender)
{
if(DateTimePicker1->Date>DateTimePicker2->Date)
{
   Application->MessageBox("La fecha inicial debe ser menor o igual a fecha final","OK",MB_OK | MB_ICONINFORMATION);
   return;
   }
AnsiString ini="",s= DateTimePicker1->Date,s1,s2,s3,st;
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
s= DateTimePicker2->Date;
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
/*   AnsiString ini, st;
   ini = FormatDateTime("dd/mm/yyyy", DateTimePicker1->Date);
   st = FormatDateTime("dd/mm/yyyy", DateTimePicker2->Date);   */
   DM->QProformas->Close();
   DM->QProformas->SQL->Clear();
   DM->QProformas->SQL->Add("SELECT * FROM VENTA WHERE FECHA >= #"+ini+"# and FECHA <= #"+st+"#");
   DM->QProformas->Open();
   if (!DM->TProformas->Active) {
      DM->TProformas->Active = true;
   }
   QRLabel9->Caption="Desde "+DateTimePicker1->Date+" Hasta "+DateTimePicker2->Date;
   QuickRep1->PreviewModal();
}
//---------------------------------------------------------------------------

void __fastcall Tfrmrepproforma::btnsalirClick(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------


void __fastcall Tfrmrepproforma::FormActivate(TObject *Sender)
{
   DateTimePicker1->Date = Now();
   DateTimePicker2->Date = Now();   
}
//---------------------------------------------------------------------------

