//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit9.h"
#include "Unit14.h"
#include "SegProductosForm.h"
#include "RepVentasFecha.h"
#include "UMainMenu.h"
#include "UProductManagement.h"
#include "UCustomer.h"
#include "UProforma.h"
#include "UProformas.h"
#include "UCustomerReport.h"
#include "DataModule.h"
#include "UEmployeeReport.h"
#include "UDaySalesReport.h"
#include "UProductReport.h"
#include "UProformasReport.h"
#include "USalesByEmployeeReport.h"
#include "USales.h"
#include "ULogin.h"
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
   if (!DM->TEmployeeList->Active) {
      DM->TEmployeeList->Active = true;
   }
   frmrepempleados->QuickRep1->PreviewModal();
}
//---------------------------------------------------------------------------

void __fastcall Tfrmreportes::btnclientesClick(TObject *Sender)
{
   if (!DM->TCustomerList->Active) {
      DM->TCustomerList->Active = true;
   }
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

