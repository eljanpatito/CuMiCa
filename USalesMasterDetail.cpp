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
int normalClientWidth = 560;
int expandedClientWidth = 760;
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
   int colorIntValue = ColorDialog1->Color;
   if (colorIntValue == frmmenuprincipal->neutroColor) {
      colorIntValue = frmmenuprincipal->defaultColor;
   }
   this->Color = TColor(colorIntValue);
   frmmenuprincipal->color_ventana(this->Name, colorIntValue);
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

void __fastcall Tfrmmaestrodetalleventa::btnMoreOptsClick(TObject *Sender)
{
   if (ClientWidth == 560) {
      btnMoreOpts->Caption = "<<";
      ClientWidth = expandedClientWidth;
   } else {
      btnMoreOpts->Caption = ">>";
      ClientWidth = normalClientWidth;
   }
}
//---------------------------------------------------------------------------

void __fastcall Tfrmmaestrodetalleventa::Button1Click(TObject *Sender)
{
   if (DM->QSalesMasterDetail1->RecordCount == 0) {
      ShowMessage("Debe seleccionar una nota");
      return;
   }
   idNota = DM->QSalesMasterDetail1->FieldByName("IDNOTA")->AsString;
   AnsiString nameCustomer = DM->QSalesMasterDetail1->FieldByName("NOMBRE_CLIENTE")->AsString;
   if (Application->MessageBox(("¿Seguro que desea Anular (Borrar) esta venta?\
   \n\nEsta acción no podrá deshacerse\
   \n\nNOTA: " + idNota +
   "\nNombre Cliente: " + nameCustomer).c_str(),"Anular Venta",MB_YESNO | MB_ICONQUESTION) == ID_YES) {
      ShowMessage("Nota sera anulada");
      DM->QSalesMasterDetail2->First();
      DM->TOrderLine->Active = true;
      while (!DM->QSalesMasterDetail2->Eof) {
         DM->TOrderLine->Insert();
         DM->TOrderLine->FieldByName("CODIGO")->AsString =
            DM->QSalesMasterDetail2->FieldByName("CODIGO")->AsString;
         DM->TOrderLine->FieldByName("DESCRIPCION")->AsString =
            DM->QSalesMasterDetail2->FieldByName("DESCRIPCION")->AsString;
         DM->TOrderLine->FieldByName("CANTIDAD")->AsString =
            DM->QSalesMasterDetail2->FieldByName("CANTIDAD")->AsString;
         DM->TOrderLine->FieldByName("PRECIO")->AsString =
            DM->QSalesMasterDetail2->FieldByName("PRECIO")->AsString;
         DM->TOrderLine->FieldByName("PARCIAL")->AsString =
            DM->QSalesMasterDetail2->FieldByName("PARCIAL")->AsString;
         DM->TOrderLine->FieldByName("ID_NOTA")->AsString =
            DM->QSalesMasterDetail2->FieldByName("ID_NOTA")->AsString;
         DM->TOrderLine->FieldByName("CANTIDAD_POR_CAJA")->AsString =
            DM->QSalesMasterDetail2->FieldByName("CANTIDAD_POR_CAJA")->AsString;
         DM->TOrderLine->Post();
         DM->QSalesMasterDetail2->Next();
      }
      DM->TOrderLine->Active = false;

      DM->TOrder->Active = true;
      DM->TOrder->Insert();
      DM->TOrder->FieldByName("IDNOTA")->AsString =
         DM->QSalesMasterDetail1->FieldByName("IDNOTA")->AsString;
      DM->TOrder->FieldByName("NOMBRE_CLIENTE")->AsString =
         DM->QSalesMasterDetail1->FieldByName("NOMBRE_CLIENTE")->AsString;
      DM->TOrder->FieldByName("TOTAL_CAJAS")->AsString =
         DM->QSalesMasterDetail1->FieldByName("TOTAL_CAJAS")->AsString;
      DM->TOrder->FieldByName("TOTAL_BS")->AsString =
         DM->QSalesMasterDetail1->FieldByName("TOTAL_BS")->AsString;
      DM->TOrder->FieldByName("TOTAL")->AsString =
         DM->QSalesMasterDetail1->FieldByName("TOTAL")->AsString;
      DM->TOrder->FieldByName("FECHA")->AsString =
         DM->QSalesMasterDetail1->FieldByName("FECHA")->AsString;
      DM->TOrder->FieldByName("COD_EMP")->AsString =
         DM->QSalesMasterDetail1->FieldByName("COD_EMP")->AsString;
      DM->TOrder->FieldByName("CLI_TEL")->AsString =
         DM->QSalesMasterDetail1->FieldByName("CLI_TEL")->AsString;
      DM->TOrder->FieldByName("CLI_CEL")->AsString =
         DM->QSalesMasterDetail1->FieldByName("CLI_CEL")->AsString;
      DM->TOrder->FieldByName("CLI_CIUDAD")->AsString =
         DM->QSalesMasterDetail1->FieldByName("CLI_CIUDAD")->AsString;
      DM->TOrder->FieldByName("CLI_NIT")->AsString =
         DM->QSalesMasterDetail1->FieldByName("CLI_NIT")->AsString;
      DM->TOrder->Post();
      DM->TOrder->Active = false;

      btnMoreOpts->Click();
      frmventas->newSale(idNota);
      Close();
   }
}
//---------------------------------------------------------------------------

