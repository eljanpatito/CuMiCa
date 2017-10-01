//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UMainMenu.h"
#include "Unit3.h"
#include "Unit5.h"
#include "Unit6.h"
#include "Unit9.h"
#include "Unit16.h"
#include "Configuration.h"
#include "DataModule.h"

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
   ShowMessage("Test");
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
   ShowMessage("Test1");
   if (!DM->tMainMenu->Active) {
      DM->tMainMenu->Active = true;
   }
   ShowMessage("Test2");
   TLocateOptions op;
   op<<loPartialKey;
   if(DM->tMainMenu->Locate("FORMULARIO",formulario,op))
   return DBEdit1->Text.ToInt();
   else
   return -2147483646;
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

