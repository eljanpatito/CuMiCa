//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit3.h"
#include "Unit5.h"
#include "Unit6.h"
#include "Unit9.h"
#include "Unit16.h"
#include "Configuration.h"

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
     TLocateOptions op;
     op<<loPartialKey;
     if(Table1->Locate("FORMULARIO",formulario,op)){
        Table1->Edit();
        DBEdit1->Text=color;
        Table1->Post();
        Table1->Refresh();
     }
     else{
      Table1->Insert();
      DBEdit2->Text=formulario;
      DBEdit1->Text=color;
      Table1->Post();
      Table1->Refresh();
     }
}
//---------------------------------------------------------------------------

int Tfrmmenuprincipal::cargar_color_ventana(AnsiString formulario)
{
   TLocateOptions op;
   op<<loPartialKey;
   if(Table1->Locate("FORMULARIO",formulario,op))
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

