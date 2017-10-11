//----------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UCustomer.h"
#include "UMainMenu.h"
#include "UProductManagement.h"
#include "UProduct.h"
#include "DataModule.h"
#include "USales.h"
#include "ULogin.h"
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
	DM->QCustomer->Open();
}
//----------------------------------------------------------------------------
void __fastcall Tfrmgestioncliente::btncerrarClick(TObject *Sender)
{
btncancelar->Click();
Close();
}
//---------------------------------------------------------------------------
void Tfrmgestioncliente::iniciar_ingreso_de_datos() {
   DM->DSCustomer1->DataSet=DM->TCustomer;
   Panel2->Enabled=True;
   Panel1->Enabled=False;
   DBEdit1->SetFocus();
   DBGrid1->Enabled=False;
   frmgestioncliente->Height=_fClientHeightEdit;
}
void __fastcall Tfrmgestioncliente::btnnuevoclienteClick(TObject *Sender)
{
   iniciar_ingreso_de_datos();
   if (!DM->TCustomer->Active) {
      DM->TCustomer->Active = true;
   }
   DM->TCustomer->Insert();
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
   DM->TCustomer->Cancel();
   DBGrid1->Enabled=True;
   DM->DSCustomer1->DataSet=DM->QCustomer;
}
//---------------------------------------------------------------------------
void __fastcall Tfrmgestioncliente::btnguardarClick(TObject *Sender)
{
try{
DM->TCustomer->Post();
Panel2->Enabled=False;
Panel1->Enabled=True;
frmgestioncliente->Height=_fClientHeightSearch;
DBGrid1->Enabled=True;
DM->DSCustomer1->DataSet=DM->QCustomer;
/*Query1->SQL->Clear();
Query1->SQL->Add("Select  `CLIENTE`.`NIT`,  `CLIENTE`.`NOMBRE`,  `CLIENTE`.`APELLIDO`From `CLIENTE`");
Query1->Open();*/
DM->QCustomer->Close();
DM->QCustomer->Open();
}
catch(...)
{
Application->MessageBox("Debe ingresar todos los campos correctamente","Error",MB_OK | MB_ICONERROR);
}
}
//---------------------------------------------------------------------------
void __fastcall Tfrmgestioncliente::txtbuscarChange(TObject *Sender)
{
DM->QCustomer->SQL->Clear();
DM->QCustomer->SQL->Add("Select  * From `CLIENTE` WHERE NIT LIKE '%"+txtbuscar->Text+"%' OR APELLIDO LIKE '%"+txtbuscar->Text+"%'");
DM->QCustomer->Open();
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
   DM->TCustomer->Locate("NIT",nit,op);
   DM->TCustomer->Edit();
}
//---------------------------------------------------------------------------
void __fastcall Tfrmgestioncliente::btneliminarclienteClick(
      TObject *Sender)
{
if (Application->MessageBox("¿Seguro que desea Borrar los datos de este CLIENTE?","Eliminar Datos de CLIENTE",MB_YESNO | MB_ICONQUESTION) == ID_YES)
{
AnsiString nit;
nit=DBEdit1->Text;
DM->DSCustomer1->DataSet=DM->TCustomer;
TLocateOptions op;
op<<loPartialKey;
DM->TCustomer->Locate("NIT",nit,op);
DM->TCustomer->Delete();
DM->DSCustomer1->DataSet=DM->QCustomer;
DM->QCustomer->SQL->Clear();
DM->QCustomer->SQL->Add("Select * From `CLIENTE`");
DM->QCustomer->Open();
}
}
//---------------------------------------------------------------------------
void __fastcall Tfrmgestioncliente::btnseleccionarClick(TObject *Sender)
{
btnseleccionar->Visible=False;
frmventas->DBEdit1->Text=DBEdit3->Text+" "+DBEdit2->Text;
   // Asign values from actual client to ventas table
   DM->TSales1CLI_TEL->Value = DBEdit4->Text;
   DM->TSales1CLI_CEL->Value = dbeCliCelular->Text;
   DM->TSales1CLI_CIUDAD->Value = dbeCliCiudad->Text;
   DM->TSales1CLI_NIT->Value = DBEdit1->Text;
Close();
}
//---------------------------------------------------------------------------

void __fastcall Tfrmgestioncliente::FormActivate(TObject *Sender)
{
   txtbuscar->Text="";
   Height = _fClientHeightSearch;
}
//---------------------------------------------------------------------------

