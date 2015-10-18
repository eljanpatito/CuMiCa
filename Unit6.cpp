//----------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit6.h"
#include "Unit5.h"
#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
#include "num_a_letra.h"
#include "Unit11.h"
#include "Unit14.h"
#include "Unit15.h"
#include "Unit16.h"
//----------------------------------------------------------------------------
#pragma resource "*.dfm"
Tfrmventas *frmventas;
//----------------------------------------------------------------------------
__fastcall Tfrmventas::Tfrmventas(TComponent *Owner)
	: TForm(Owner)
{
}
//----------------------------------------------------------------------------
void __fastcall Tfrmventas::btnbuscarClick(TObject *Sender)
{
frmgestioncliente->btnseleccionar->Visible=True;
frmgestioncliente->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall Tfrmventas::btnnuevaventaClick(TObject *Sender)
{
Table1->Open();
Table2->Open();
btnbuscar->Enabled=True;
Query1->SQL->Clear();
Query1->SQL->Add("select MAX(IDNOTA)+1 AS MAY FROM VENTA;");
Query1->Open();
AnsiString idnota= Query1->FieldByName("MAY")->Text;
if(idnota=="")idnota="1";
Query1->Close();
Panel1->Enabled=False;
Table1->Insert();
btnbuscar->Click();
EditIDNOTA->Text=idnota;
EditTOTAL_BS->Text="0";
EditTOTAL_CAJAS->Text="0";
EditTOTAL->Text="cero";
Panel2->Enabled=True;
Panel2->Color=(TColor)0x0000D900;

EditFECHA->Text=AnsiString(DateTimePicker1->Date);
btnempleado->Click();
}
//---------------------------------------------------------------------------
void __fastcall Tfrmventas::btncancelarClick(TObject *Sender)
{
   Panel1->Enabled=True;
   Panel2->Enabled=False;
   Panel2->Color=clRed;

   Table2->First();
   while (!Table2->Eof){
     TLocateOptions op;
     op<<loPartialKey;
     frmdatosproducto->Table1->Locate("CODIGO",DBEdit2->Text,op);
     int a=DBEdit3->Text.ToInt();
     frmdatosproducto->Table1->Edit();
     frmdatosproducto->EditCANTIDAD_CAJAS->Text=frmdatosproducto->EditCANTIDAD_CAJAS->Text.ToInt()+a;
     frmdatosproducto->Table1->Post();
     frmgestionproductos->actualizar_consulta();
     Table2->Next();
   }
   Table2->First();
   Table1->Delete();
   Table1->Refresh();
   Application->MessageBox("Venta CANCELADA","OK",MB_OK | MB_ICONINFORMATION);
   txtnombre->Text="";
   Table1->Close();
   Table2->Close();
}
//---------------------------------------------------------------------------
void __fastcall Tfrmventas::FormClose(TObject *Sender,
      TCloseAction &Action)
{
   if(Panel2->Enabled==True)
   {
      btncancelar->Click();
   }
}
//---------------------------------------------------------------------------
void __fastcall Tfrmventas::btningresarClick(TObject *Sender)
{

if(DBEdit1->Text=="")
 {
       Application->MessageBox("Debe Seleccionar un cliente","OK",MB_OK | MB_ICONINFORMATION);
       return;
 }
   if (Table2->RecordCount<25) {
      //btnbuscar->Enabled=False;
      Table1->Post();
      Table1->Refresh();
      Table1->Edit();
      frmgestionproductos->Panel1->Visible=False;
      frmgestionproductos->Panel2->Visible=True;
      frmgestionproductos->ShowModal();
   } else {
      Application->MessageBox("Ya no puede agregar mas items a esta nota,\nle recomendamos crear una nueva nota.","OK",MB_OK | MB_ICONERROR);
      return;
   }
}
//---------------------------------------------------------------------------
void __fastcall Tfrmventas::EditTOTAL_BSChange(TObject *Sender)
{
AnsiString sum=EditTOTAL_BS->Text;
AnsiString s1="",st="",s2="";
int i=sum.Pos(",");
if(i!=0){
        s1=sum.SubString(1,i-1);
        st=sum.SubString(i+1,sum.Length()-i);
        if(st.Length()==1)
        EditTOTAL->Text=AnsiString(convertir(s1.c_str()))+" "+st+"0/100 Bs.";
        else
        EditTOTAL->Text=AnsiString(convertir(s1.c_str()))+" "+st+"/100 Bs.";
}
else
{
     EditTOTAL->Text=AnsiString(convertir(sum.c_str()))+"00/100 Bs.";
}
}
//---------------------------------------------------------------------------

void __fastcall Tfrmventas::btnvenderClick(TObject *Sender)
{
   if(EditTOTAL_BS->Text=="0")
   {
      Application->MessageBox("Minimo debe haber registrado un producto para la venta o sino presione CANCELAR","OK",MB_OK | MB_ICONINFORMATION);
      return;
   }
   Panel1->Enabled=True;
   Panel2->Enabled=False;
   Panel2->Color=clRed;
   Table1->Post();
   Table1->Refresh();
   Table3->Active = false;
   Table3->Active = true;
   Table3->Last();
   Application->MessageBox("VENTA REGISTRADA CORRECTAMENTE","OK",MB_OK | MB_ICONINFORMATION);
   frmproforma->Query1->Close();
   frmproforma->Query1->SQL->Clear();
   frmproforma->Query1->SQL->Add("SELECT DETALLE_VENTA.*, producto.*");
   frmproforma->Query1->SQL->Add("FROM  PRODUCTO INNER JOIN DETALLE_VENTA ON PRODUCTO.CODIGO = DETALLE_VENTA.CODIGO");
   frmproforma->Query1->SQL->Add("WHERE (((DETALLE_VENTA.ID_NOTA)="+DBEdit5->Text+"))");
// SELECT DETALLE_VENTA.* FROM DETALLE_VENTA WHERE (((DETALLE_VENTA.ID_NOTA)="+DBEdit1->Text+"))");
   frmproforma->Query1->Open();
   frmproforma->QRLabel6->Caption=EditTOTAL->Text;
   frmproforma->QRLabel7->Caption=EditTOTAL_BS->Text;
   frmproforma->Query2->SQL->Clear();
   frmproforma->Query2->SQL->Add("SELECT * FROM VENTA");
   frmproforma->Query2->SQL->Add("WHERE IDNOTA ="+DBEdit5->Text+"");
   frmproforma->Query2->Open();
   frmproforma->QuickRep1->PreviewModal();
   txtnombre->Text="";
   Table1->Close();
   Table2->Close();
}
//---------------------------------------------------------------------------


void __fastcall Tfrmventas::FormCreate(TObject *Sender)
{
 this->Color=(TColor)frmmenuprincipal->cargar_color_ventana(this->Name);
  DateTimePicker1->Date=Date().CurrentDate();
}
//---------------------------------------------------------------------------

void __fastcall Tfrmventas::btnverventasClick(TObject *Sender)
{
   frmmaestrodetalleventa->ShowModal();
}
//---------------------------------------------------------------------------


void __fastcall Tfrmventas::btnmodificarClick(TObject *Sender)
{
   frmdevolucion->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall Tfrmventas::btncolorClick(TObject *Sender)
{
      ColorDialog1->Execute();
      this->Color=ColorDialog1->Color;
      frmmenuprincipal->color_ventana(this->Name,ColorDialog1->Color);
}
//---------------------------------------------------------------------------


void __fastcall Tfrmventas::FormActivate(TObject *Sender)
{
DBEdit1->Text=="";
Table1->Close();
Table2->Close();
}
//---------------------------------------------------------------------------


void __fastcall Tfrmventas::btnempleadoClick(TObject *Sender)
{
frmempleado->btnseleccionar->Visible=True;
frmempleado->ShowModal();

}
//---------------------------------------------------------------------------

void __fastcall Tfrmventas::FormCloseQuery(TObject *Sender, bool &CanClose)
{
if(Panel2->Enabled)
{
   Application->MessageBox("DEBE 'GUARDAR VENTA' O 'CANCELAR VENTA'","OK",MB_OK | MB_ICONINFORMATION);
   CanClose=False;     
}
}
//---------------------------------------------------------------------------

