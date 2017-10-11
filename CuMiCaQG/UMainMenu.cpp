//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UMainMenu.h"
#include "Configuration.h"
#include "DataModule.h"
#include "UProductManagement.h"
#include "UEmployee.h"
#include "UCustomer.h"
#include "USales.h"
#include "UReportsList.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tfrmmenuprincipal *frmmenuprincipal;

//---------------------------------------------------------------------------
__fastcall Tfrmmenuprincipal::Tfrmmenuprincipal(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tfrmmenuprincipal::btncerrarClick(TObject *Sender)
{
Application->Terminate();
}
//---------------------------------------------------------------------------
void __fastcall Tfrmmenuprincipal::FormClose(TObject *Sender,
      TCloseAction &Action)
{
Application->Terminate();
}
//---------------------------------------------------------------------------


void __fastcall Tfrmmenuprincipal::btnproductosClick(TObject *Sender)
{
   if (!DM->QProductManagement->Active) {
      DM->QProductManagement->Open();
   }
   frmgestionproductos->Panel1->Visible=True;
   frmgestionproductos->Panel2->Visible=False;
   frmgestionproductos->ShowModal();
}
//---------------------------------------------------------------------------


void __fastcall Tfrmmenuprincipal::btnclienteClick(TObject *Sender)
{
frmgestioncliente->ShowModal();        
}
//---------------------------------------------------------------------------

void __fastcall Tfrmmenuprincipal::btnvenderClick(TObject *Sender)
{
 frmventas->Show();
}
//---------------------------------------------------------------------------


void __fastcall Tfrmmenuprincipal::btnreportesClick(TObject *Sender)
{
  frmreportes->ShowModal();
}
//---------------------------------------------------------------------------
void Tfrmmenuprincipal::color_ventana(AnsiString formulario, int color)
{
   ShowMessage("Color: [" + IntToStr(color) + "]");
   if (!DM->tMainMenu->Active) {
      DM->tMainMenu->Active = true;
   }
     TLocateOptions op;
     op<<loPartialKey;
     if(DM->tMainMenu->Locate("FORMULARIO",formulario,op)){
        DM->tMainMenu->Edit();
        DBEdit1->Text=color;
        DM->tMainMenu->Post();
        DM->tMainMenu->Refresh();
     }
     else{
      DM->tMainMenu->Insert();
      DBEdit2->Text=formulario;
      DBEdit1->Text=color;
      DM->tMainMenu->Post();
      DM->tMainMenu->Refresh();
     }
}
//---------------------------------------------------------------------------

int Tfrmmenuprincipal::cargar_color_ventana(AnsiString formulario)
{
   if (!DM->tMainMenu->Active) {
      DM->tMainMenu->Active = true;
   }
   TLocateOptions op;
   op<<loPartialKey;
   if(DM->tMainMenu->Locate("FORMULARIO",formulario,op))
   return DBEdit1->Text.ToInt();
   else
   return defaultColor;
}

void __fastcall Tfrmmenuprincipal::btnempleadoClick(TObject *Sender)
{
frmempleado->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall Tfrmmenuprincipal::Configuration1Click(TObject *Sender)
{
   frmConfiguration->ShowModal();   
}
//---------------------------------------------------------------------------

void __fastcall Tfrmmenuprincipal::FormCreate(TObject *Sender)
{
   defaultColor = -2147483646;
   neutroColor = 0;
   defaultColor = StrToInt(frmConfiguration->getValueFromProperty("defaultColor"));
   neutroColor = StrToInt(frmConfiguration->getValueFromProperty("neutroColor"));
}
//---------------------------------------------------------------------------

