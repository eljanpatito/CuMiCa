//----------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit14.h"
#include "Unit2.h"
#include "Unit6.h"
#include "Unit11.h"
#include "Unit14.h"
#include "UMainMenu.h"
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
	Query1->Open();
	Query2->Open();
}
//----------------------------------------------------------------------------
void __fastcall Tfrmmaestrodetalleventa::Edit1Change(TObject *Sender)
{
   Query1->Close();
   Query1->SQL->Clear();
   Query1->SQL->Add("select * from venta where nombre_cliente like '%"+Edit1->Text+"%'");
   Query1->SQL->Add("ORDER BY IDNOTA DESC");
   Query1->Open();
}
//---------------------------------------------------------------------------
void __fastcall Tfrmmaestrodetalleventa::btnimprimirClick(TObject *Sender)
{
 if(DBEdit1->Text==""){
   Application->MessageBox("Debe seleccionar una venta para poder imprimir","ERROR", MB_OK | MB_ICONERROR);
   return;
 }
 WORD dd, mm, aa;

   frmproforma->Query1->Close();
   frmproforma->Query1->SQL->Clear();
//   frmproforma->Query1->SQL->Add("SELECT DETALLE_VENTA.*, producto.*");
//   frmproforma->Query1->SQL->Add("FROM  PRODUCTO INNER JOIN DETALLE_VENTA ON PRODUCTO.CODIGO = DETALLE_VENTA.CODIGO");
//   frmproforma->Query1->SQL->Add("WHERE (((DETALLE_VENTA.ID_NOTA)="+DBEdit1->Text+"))");
   frmproforma->Query1->SQL->Add("SELECT DETALLE_VENTA.* FROM DETALLE_VENTA WHERE (((DETALLE_VENTA.ID_NOTA)="+DBEdit1->Text+"))");
   frmproforma->Query1->Open();
 frmproforma->QRLabel6->Caption=DBEdit2->Text;
 frmproforma->QRLabel7->Caption=DBEdit3->Text;
   frmproforma->Query2->Close();
 frmproforma->Query2->SQL->Clear();
   frmproforma->Query2->SQL->Add("SELECT * FROM VENTA");
   frmproforma->Query2->SQL->Add("WHERE IDNOTA ="+DBEdit1->Text+"");
    frmproforma->Query2->Open();
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
   Query1->Close();
   Query1->Open();
}
//---------------------------------------------------------------------------


void __fastcall Tfrmmaestrodetalleventa::BitBtn1Click(TObject *Sender)
{
   Query1->Close();
   Query1->Open();
   QuickRep1->PreviewModal();
}
//---------------------------------------------------------------------------

