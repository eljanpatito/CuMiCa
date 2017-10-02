//----------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit5.h"
#include "Unit2.h"
#include "Unit6.h"
#include "UMainMenu.h"
#include "UProductManagement.h"
#include "UProduct.h"
//----------------------------------------------------------------------------
#pragma resource "*.dfm"
Tfrmgestioncliente *frmgestioncliente;
int _fClientHeightEdit=585;
int _fClientHeightSearch=535;
//----------------------------------------------------------------------------
__fastcall Tfrmgestioncliente::Tfrmgestioncliente(TComponent *Owner)
	: TForm(Owner)
{
}
//----------------------------------------------------------------------------
void __fastcall Tfrmgestioncliente::FormCreate(TObject *Sender)
{
	Query1->Open();
}
//----------------------------------------------------------------------------
void __fastcall Tfrmgestioncliente::btncerrarClick(TObject *Sender)
{
btncancelar->Click();
Close();
}
//---------------------------------------------------------------------------
void Tfrmgestioncliente::iniciar_ingreso_de_datos() {
   DataSource1->DataSet=Table1;
   Panel2->Enabled=True;
   Panel1->Enabled=False;
   DBEdit1->SetFocus();
   DBGrid1->Enabled=False;
   frmgestioncliente->Height=_fClientHeightEdit;
}
void __fastcall Tfrmgestioncliente::btnnuevoclienteClick(TObject *Sender)
{
   iniciar_ingreso_de_datos();
   Table1->Insert();
}
//---------------------------------------------------------------------------
void __fastcall Tfrmgestioncliente::DBEdit1Enter(TObject *Sender)
{
((TEdit *)Sender)->Color=clLime;         
}
//---------------------------------------------------------------------------
void __fastcall Tfrmgestioncliente::DBEdit1Exit(TObject *Sender)
{
((TEdit *)Sender)->Color=clWhite;
}
//---------------------------------------------------------------------------
void __fastcall Tfrmgestioncliente::btncancelarClick(TObject *Sender)
{
   frmgestioncliente->Height=_fClientHeightSearch;
   Panel2->Enabled=False;
   Panel1->Enabled=True;
   Table1->Cancel();
   DBGrid1->Enabled=True;
   DataSource1->DataSet=Query1;
}
//---------------------------------------------------------------------------
void __fastcall Tfrmgestioncliente::btnguardarClick(TObject *Sender)
{
try{
Table1->Post();
Panel2->Enabled=False;
Panel1->Enabled=True;
frmgestioncliente->Height=_fClientHeightSearch;
DBGrid1->Enabled=True;
DataSource1->DataSet=Query1;
/*Query1->SQL->Clear();
Query1->SQL->Add("Select  `CLIENTE`.`NIT`,  `CLIENTE`.`NOMBRE`,  `CLIENTE`.`APELLIDO`From `CLIENTE`");
Query1->Open();*/
Query1->Close();
Query1->Open();
}
catch(...)
{
Application->MessageBox("Debe ingresar todos los campos correctamente","Error",MB_OK | MB_ICONERROR);
}
}
//---------------------------------------------------------------------------
void __fastcall Tfrmgestioncliente::txtbuscarChange(TObject *Sender)
{
Query1->SQL->Clear();
Query1->SQL->Add("Select  * From `CLIENTE` WHERE NIT LIKE '%"+txtbuscar->Text+"%' OR APELLIDO LIKE '%"+txtbuscar->Text+"%'");
Query1->Open();
}
//---------------------------------------------------------------------------
void __fastcall Tfrmgestioncliente::FormClose(TObject *Sender,
      TCloseAction &Action)
{
btncerrar->Click();
}
//---------------------------------------------------------------------------
void __fastcall Tfrmgestioncliente::btnmodificarclienteClick(
      TObject *Sender) {
   AnsiString nit;
   nit=DBEdit1->Text;
   iniciar_ingreso_de_datos();
   TLocateOptions op;
   op<<loPartialKey;
   Table1->Locate("NIT",nit,op);
   Table1->Edit();
}
//---------------------------------------------------------------------------
void __fastcall Tfrmgestioncliente::btneliminarclienteClick(
      TObject *Sender)
{
if (Application->MessageBox("¿Seguro que desea Borrar los datos de este CLIENTE?","Eliminar Datos de CLIENTE",MB_YESNO | MB_ICONQUESTION) == ID_YES)
{
AnsiString nit;
nit=DBEdit1->Text;
DataSource1->DataSet=Table1;
TLocateOptions op;
op<<loPartialKey;
Table1->Locate("NIT",nit,op);
Table1->Delete();
DataSource1->DataSet=Query1;
Query1->SQL->Clear();
Query1->SQL->Add("Select * From `CLIENTE`");
Query1->Open();
}
}
//---------------------------------------------------------------------------
void __fastcall Tfrmgestioncliente::btnseleccionarClick(TObject *Sender)
{
btnseleccionar->Visible=False;
frmventas->DBEdit1->Text=DBEdit3->Text+" "+DBEdit2->Text;
   // Asign values from actual client to ventas table
   frmventas->Table1CLI_TEL->Value = DBEdit4->Text;
   frmventas->Table1CLI_CEL->Value = dbeCliCelular->Text;
   frmventas->Table1CLI_CIUDAD->Value = dbeCliCiudad->Text;
   frmventas->Table1CLI_NIT->Value = DBEdit1->Text;
Close();
}
//---------------------------------------------------------------------------

void __fastcall Tfrmgestioncliente::FormActivate(TObject *Sender)
{
   txtbuscar->Text="";
   Height = _fClientHeightSearch;
}
//---------------------------------------------------------------------------

