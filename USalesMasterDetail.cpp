//----------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "USalesMasterDetail.h"
#include "UMainMenu.h"
#include "DataModule.h"
#include "UProforma.h"
#include "USales.h"
#include "ULogin.h"
//----------------------------------------------------------------------------
#pragma resource "*.dfm"
Tfrmmaestrodetalleventa *frmmaestrodetalleventa;
//----------------------------------------------------------------------------
__fastcall Tfrmmaestrodetalleventa::Tfrmmaestrodetalleventa(TComponent *Owner)
	: TForm(Owner)
{
}
//----------------------------------------------------------------------------
void __fastcall Tfrmmaestrodetalleventa::FormCreate(TObject *Sender)
{
   this->Color=(TColor)frmmenuprincipal->cargar_color_ventana(this->Name);
}
//----------------------------------------------------------------------------
void __fastcall Tfrmmaestrodetalleventa::Edit1Change(TObject *Sender)
{
   DM->QSalesMasterDetail1->Close();
   DM->QSalesMasterDetail1->SQL->Clear();
   DM->QSalesMasterDetail1->SQL->Add("select * from venta where nombre_cliente like '%"+Edit1->Text+"%'");
   DM->QSalesMasterDetail1->SQL->Add("ORDER BY IDNOTA DESC");
   DM->QSalesMasterDetail1->Open();
}
//---------------------------------------------------------------------------
void __fastcall Tfrmmaestrodetalleventa::btnimprimirClick(TObject *Sender)
{
 if(DBEdit1->Text==""){
   Application->MessageBox("Debe seleccionar una venta para poder imprimir","ERROR", MB_OK | MB_ICONERROR);
   return;
 }
 WORD dd, mm, aa;

   DM->QProforma1->Close();
   DM->QProforma1->SQL->Clear();
//   frmproforma->Query1->SQL->Add("SELECT DETALLE_VENTA.*, producto.*");
//   frmproforma->Query1->SQL->Add("FROM  PRODUCTO INNER JOIN DETALLE_VENTA ON PRODUCTO.CODIGO = DETALLE_VENTA.CODIGO");
//   frmproforma->Query1->SQL->Add("WHERE (((DETALLE_VENTA.ID_NOTA)="+DBEdit1->Text+"))");
   DM->QProforma1->SQL->Add("SELECT DETALLE_VENTA.* FROM DETALLE_VENTA WHERE (((DETALLE_VENTA.ID_NOTA)="+DBEdit1->Text+"))");
   DM->QProforma1->Open();
 frmproforma->QRLabel6->Caption=DBEdit2->Text;
 frmproforma->QRLabel7->Caption=DBEdit3->Text;
   DM->QProforma2->Close();
 DM->QProforma2->SQL->Clear();
   DM->QProforma2->SQL->Add("SELECT * FROM VENTA");
   DM->QProforma2->SQL->Add("WHERE IDNOTA ="+DBEdit1->Text+"");
    DM->QProforma2->Open();
   frmproforma->setValues();
 frmproforma->QuickRep1->PreviewModal();
}
//---------------------------------------------------------------------------

void __fastcall Tfrmmaestrodetalleventa::btncolorClick(TObject *Sender)
{
   ColorDialog1->Execute();
      this->Color=ColorDialog1->Color;
      frmmenuprincipal->color_ventana(this->Name,ColorDialog1->Color);
}
//---------------------------------------------------------------------------

void __fastcall Tfrmmaestrodetalleventa::FormActivate(TObject *Sender)
{
   Edit1->Text="";
   DM->QSalesMasterDetail1->Close();
   DM->QSalesMasterDetail1->Open();
   DM->QSalesMasterDetail2->Close();
   DM->QSalesMasterDetail2->Open();
   DM->TSalesMasterDetail->Active = false;
   DM->TSalesMasterDetail->Active = true;
   Edit1->SetFocus();
}
//---------------------------------------------------------------------------


void __fastcall Tfrmmaestrodetalleventa::BitBtn1Click(TObject *Sender)
{
   DM->QSalesMasterDetail1->Close();
   DM->QSalesMasterDetail1->Open();
   QuickRep1->PreviewModal();
}
//---------------------------------------------------------------------------

void __fastcall Tfrmmaestrodetalleventa::FormClose(TObject *Sender,
      TCloseAction &Action)
{
   DM->QSalesMasterDetail1->Close();
   DM->QSalesMasterDetail2->Close();
   DM->TSalesMasterDetail->Active = false;
}
//---------------------------------------------------------------------------

