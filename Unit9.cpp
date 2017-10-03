//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit9.h"
#include "Unit2.h"
#include "Unit6.h"
#include "Unit7.h"
#include "Unit10.h"
#include "Unit12.h"
#include "Unit13.h"
#include "Unit14.h"
#include "Unit18.h"
#include "Unit19.h"
#include "Unit21.h"
#include "SegProductosForm.h"
#include "RepVentasFecha.h"
#include "UMainMenu.h"
#include "UProductManagement.h"
#include "UCustomer.h"
#include "UProforma.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tfrmreportes *frmreportes;
//---------------------------------------------------------------------------
__fastcall Tfrmreportes::Tfrmreportes(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall Tfrmreportes::btnimprimirClick(TObject *Sender)
{
frmrepproducto->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall Tfrmreportes::Button1Click(TObject *Sender)
{
frmreporteventa->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall Tfrmreportes::btnsalirClick(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void __fastcall Tfrmreportes::btnproformasClick(TObject *Sender)
{
frmrepproforma->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall Tfrmreportes::btncolorClick(TObject *Sender)
{
   ColorDialog1->Execute();
      this->Color=ColorDialog1->Color;
      frmmenuprincipal->color_ventana(this->Name,ColorDialog1->Color);    
}
//---------------------------------------------------------------------------

void __fastcall Tfrmreportes::FormCreate(TObject *Sender)
{
 this->Color=(TColor)frmmenuprincipal->cargar_color_ventana(this->Name);   
}
//---------------------------------------------------------------------------

void __fastcall Tfrmreportes::btnempleadosClick(TObject *Sender)
{
frmrepempleados->QuickRep1->PreviewModal();
}
//---------------------------------------------------------------------------

void __fastcall Tfrmreportes::btnclientesClick(TObject *Sender)
{
frmrepcliente->QuickRep1->PreviewModal();
}
//---------------------------------------------------------------------------

void __fastcall Tfrmreportes::btnventaempClick(TObject *Sender)
{
  frmventaempleado->ShowModal();
}
//---------------------------------------------------------------------------


void __fastcall Tfrmreportes::Button2Click(TObject *Sender)
{
   fSeguimiento->ShowModal();   
}
//---------------------------------------------------------------------------

void __fastcall Tfrmreportes::Button3Click(TObject *Sender)
{
   frmrepventasfecha->ShowModal();   
}
//---------------------------------------------------------------------------

