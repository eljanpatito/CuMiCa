//----------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "ULogin.h"
#include "DataModule.h"
#include "UMainMenu.h"
#include "USales.h"
//----------------------------------------------------------------------------
#pragma resource "*.dfm"
Tfrmlogin *frmlogin;
//----------------------------------------------------------------------------
__fastcall Tfrmlogin::Tfrmlogin(TComponent *Owner)
	: TForm(Owner)
{
}
//----------------------------------------------------------------------------
void __fastcall Tfrmlogin::FormCreate(TObject *Sender)
{
//	DM->Query1->Open();
}
//----------------------------------------------------------------------------
void __fastcall Tfrmlogin::btncancelarClick(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void __fastcall Tfrmlogin::btningresarClick(TObject *Sender)
{
   if ((txtusuario->Text.Trim() == "") || (txtpassword->Text.Trim() == "")) {
      Application->MessageBoxA("Debe ingresar usuario y contraseña", "Error", MB_OK | MB_ICONERROR);
      txtusuario->Text="";
    txtpassword->Text="";
      txtusuario->SetFocus();
      return;
   }
   DM->Query1->SQL->Clear();
   DM->Query1->SQL->Add("Select  * From `USUARIO`");
   DM->Query1->SQL->Add("where USUARIO='"+txtusuario->Text+"' and PASSWORD='"+txtpassword->Text+"'");
   DM->Query1->Open();
   if(EditUSUARIO->Text!="")
   {
   if(DBEdit1->Text=="vendedor")
   {
       frmmenuprincipal->btnproductos->Visible=False;
       frmmenuprincipal->btnreportes->Visible=False;
       frmmenuprincipal->Image5->Visible=False;
       frmmenuprincipal->Image1->Visible=False;
   }
   frmlogin->Visible=False;
   frmmenuprincipal->Label1->Caption="Bienvenido "+EditNOMBRE->Text+" "+EditAPELLIDO->Text;
   frmmenuprincipal->Show();
   }
   else
   {
      Application->MessageBoxA("Error de usuario o contraseña", "Error", MB_OK | MB_ICONERROR);
    txtusuario->Text="";
    txtpassword->Text="";
    txtusuario->SetFocus();
   }
}
//---------------------------------------------------------------------------
void __fastcall Tfrmlogin::txtusuarioEnter(TObject *Sender)
{
((TEdit *)Sender)->Color=clSkyBlue;
}
//---------------------------------------------------------------------------
void __fastcall Tfrmlogin::txtusuarioExit(TObject *Sender)
{
   if (((TEdit *)Sender)->Text.Trim() == "") {
      ((TEdit *)Sender)->Color=clMaroon;
   } else {
      ((TEdit *)Sender)->Color=clWhite;
   }
}
//---------------------------------------------------------------------------
void __fastcall Tfrmlogin::txtusuarioKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if(Key==13)
txtpassword->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall Tfrmlogin::txtusuarioKeyPress(TObject *Sender, char &Key)
{
if(Key=='=' || Key=='\'')
Key=0;
}
//---------------------------------------------------------------------------




void __fastcall Tfrmlogin::txtpasswordKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if(Key==13)
btningresar->Click();        
}
//---------------------------------------------------------------------------

