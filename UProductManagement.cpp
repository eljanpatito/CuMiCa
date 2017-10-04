//----------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UProductManagement.h"
#include "UMainMenu.h"
#include "DataModule.h"
#include "UProduct.h"
#include "UProductReport.h"
#include "USales.h"
//----------------------------------------------------------------------------
#pragma resource "*.dfm"
Tfrmgestionproductos *frmgestionproductos;
//----------------------------------------------------------------------------
__fastcall Tfrmgestionproductos::Tfrmgestionproductos(TComponent *Owner)
	: TForm(Owner)
{
}
//----------------------------------------------------------------------------
void __fastcall Tfrmgestionproductos::FormCreate(TObject *Sender)
{
   this->Color=(TColor)frmmenuprincipal->cargar_color_ventana(this->Name);
}
//----------------------------------------------------------------------------
void __fastcall Tfrmgestionproductos::txtbuscarChange(TObject *Sender)
{
   DM->QProductManagement->SQL->Clear();
   DM->QProductManagement->SQL->Add("Select  `PRODUCTO`.`ID`,  `PRODUCTO`.`CODIGO`,  `PRODUCTO`.`DESCRIPCION`,  `PRODUCTO`.`CANTIDAD_CAJAS`,  `PRODUCTO`.`CANTIDAS_POR_CAJA`, `PRODUCTO`.`PRECIO_DE_COMPRA`,  `PRODUCTO`.`PRECIO_UNIDAD`,`PRODUCTO`.`PRECIO_CAJA`From `PRODUCTO`");
   DM->QProductManagement->SQL->Add("WHERE (CODIGO LIKE '%"+txtbuscar->Text+"%' OR DESCRIPCION LIKE '%"+txtbuscar->Text+"%')");
   if (!Panel1->Visible) {
      DM->QProductManagement->SQL->Add("AND CANTIDAD_CAJAS > 0");
   }
   DM->QProductManagement->Close();
   DM->QProductManagement->Open();
}
//---------------------------------------------------------------------------
void __fastcall Tfrmgestionproductos::btncerrarClick(TObject *Sender)
{
   Close();
}
//---------------------------------------------------------------------------
void Tfrmgestionproductos::actualizar_consulta()
{
  DM->QProductManagement->Close();
  DM->QProductManagement->Open();
}
void __fastcall Tfrmgestionproductos::txtbuscarEnter(TObject *Sender)
{
   ((TEdit *)Sender)->Color=clLime;
}
//---------------------------------------------------------------------------
void __fastcall Tfrmgestionproductos::txtbuscarExit(TObject *Sender)
{
   ((TEdit *)Sender)->Color=clWhite;
}
//---------------------------------------------------------------------------
void __fastcall Tfrmgestionproductos::btnnuevoprodClick(TObject *Sender)
{
  frmdatosproducto->Label8->Caption="NUEVO PRODUCTO";
  frmdatosproducto->Caption="NUEVO PRODUCTO";
   if (!DM->TProduct->Active) {
      DM->TProduct->Active = true;
   }
  DM->TProduct->Insert();
  frmdatosproducto->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall Tfrmgestionproductos::btnmodificarprodClick(
      TObject *Sender)
{
  frmdatosproducto->Label8->Caption="MODIFICAR PRODUCTO";
  frmdatosproducto->Caption="MODIFICAR PRODUCTO";
  TLocateOptions op;
  op<<loPartialKey;
   if (!DM->TProduct->Active) {
      DM->TProduct->Active = true;
   }
  DM->TProduct->Locate("ID",DBEdit1->Text,op);
  DM->TProduct->Edit();
  frmdatosproducto->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall Tfrmgestionproductos::btneliminarprodClick(TObject *Sender) {
   if (Application->MessageBox("¿Seguro que desea Borrar los datos de este PRODUCTO?","Eliminar Datos de Producto",MB_YESNO | MB_ICONQUESTION) == ID_YES) {
      TLocateOptions op;
      op<<loPartialKey;
      DM->TProduct->Locate("ID",DBEdit1->Text,op);
      DM->TProduct->Delete();
      DM->TProduct->Refresh();
      actualizar_consulta();
   }
}
//---------------------------------------------------------------------------


void __fastcall Tfrmgestionproductos::btnaumentarClick(TObject *Sender) {
   frmgestionproductos->locateTableByField(DM->TProduct, "ID", DBEdit1->Text);
   AnsiString amountStr = InputBox("Actualizar cajas","CODIGO: "+frmdatosproducto->EditCODIGO->Text+"\nDESCRIPCION: "+frmdatosproducto->EditDESCRIPCION->Text+"\n\nCantidad de Cajas:","");
   int amount = 0;
   try {
      amount = amountStr.ToInt();
   } catch (EConvertError &e) {
      Application->MessageBox(("'" + amountStr + "' No es un valor de numero entero valido").c_str(), "Error",MB_OK | MB_ICONERROR);
      return;
   }
   try {
      if (amount > 0) {
         frmgestionproductos->addAmountByID(amount, DBEdit1->Text);
         Application->MessageBox("Cantidad actualizada correctamente","OK",MB_OK | MB_ICONINFORMATION);
         actualizar_consulta();
      } else {
         Application->MessageBox("Cantidad debe ser mayor a 0 (cero)","Error",MB_OK | MB_ICONERROR);
      }
   }
   catch(...) {
      Application->MessageBox("Cantidad no Valida, no se actualiza la cantidad","Error",MB_OK | MB_ICONERROR);
   }
}
//---------------------------------------------------------------------------

void __fastcall Tfrmgestionproductos::btnseleccionarClick(TObject *Sender)
{
   int amount = 0;
   try {
      amount = Edit1->Text.ToInt();
   } catch (EConvertError &e) {
      Application->MessageBox(("'" + Edit1->Text + "' No es un valor de numero entero valido").c_str(), "Error",MB_OK | MB_ICONERROR);
      return;
   }
   try {
      if ((amount > 0) && (amount <= DBEdit5->Text.ToInt())) {
         if (!DM->TProduct->Active) {
            DM->TProduct->Active = true;
         }
         DM->TSales2->Active = false;
         DM->TSales2->Filter = "CODIGO='"+DBEdit2->Text+"'";
         DM->TSales2->Filtered = true;
         DM->TSales2->Active = true;
         if (DM->TSales2->RecordCount > 0) {
            int oldBoxQuantity = DM->TSales2->FieldByName("CANTIDAD")->AsInteger;
            int boxQuantity = oldBoxQuantity + amount;
            DM->TSales2->Edit();
            DM->TSales2->FieldByName("CANTIDAD")->Text = boxQuantity;
            DM->TSales2->FieldByName("PARCIAL")->Text=AnsiString(boxQuantity*DBEdit4->Text.ToDouble());
         } else {
            DM->TSales2->Insert();
            DM->TSales2->FieldByName("CODIGO")->Text=DBEdit2->Text;
            DM->TSales2->FieldByName("DESCRIPCION")->Text=DBEdit3->Text;
            DM->TSales2->FieldByName("CANTIDAD")->Text=Edit1->Text;
            DM->TSales2->FieldByName("CANTIDAD_POR_CAJA")->Text = dbeAmountByBox->Text;
            DM->TSales2->FieldByName("PRECIO")->Text=DBEdit4->Text;
            DM->TSales2->FieldByName("PARCIAL")->Text=AnsiString(Edit1->Text.ToDouble()*DBEdit4->Text.ToDouble());
            DM->TSales2->FieldByName("ID_NOTA")->Text=frmventas->EditIDNOTA->Text;
         }
         frmventas->EditTOTAL_CAJAS->Text=frmventas->EditTOTAL_CAJAS->Text.ToInt() + amount;
         frmventas->EditTOTAL_BS->Text=frmventas->EditTOTAL_BS->Text.ToDouble()+(amount*DBEdit4->Text.ToDouble());
         DM->TSales2->Post();
         DM->TSales2->Refresh();
         DM->TSales2->Filtered = false;

         frmgestionproductos->locateTableByField(DM->TProduct, "ID", DBEdit1->Text);
         frmgestionproductos->addAmountByID(-amount, DBEdit1->Text);
         actualizar_consulta();
         Panel1->Visible=True;
         Panel2->Visible=False;
         Close();
      } else {
         Application->MessageBox("Cantidad debe ser mayor a 0 (cero) y menor a la cantidad existente","Error",MB_OK | MB_ICONERROR);
      }
   } catch(...) {
      Application->MessageBox("Se produjo un error inesperado","Error",MB_OK | MB_ICONERROR);
   }
}
//---------------------------------------------------------------------------

void __fastcall Tfrmgestionproductos::Edit1KeyPress(TObject *Sender,
      char &Key)
{
  if (!((Key >= '0' && Key <= '9') || Key == '\b'))
    Key = 0;
}
//---------------------------------------------------------------------------


void __fastcall Tfrmgestionproductos::btncolorClick(TObject *Sender)
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

void __fastcall Tfrmgestionproductos::FormActivate(TObject *Sender)
{
  txtbuscar->Text="";
   Edit1->Text="";   
}
//---------------------------------------------------------------------------

void Tfrmgestionproductos::addAmountByID(int amount, AnsiString id) {
   AnsiString idTmp = DM->TProduct->FieldByName("ID")->AsString;
   if (id != idTmp) {
      frmgestionproductos->locateTableByField(DM->TProduct, "ID", id);
   }
   DM->TProduct->Edit();
   frmdatosproducto->EditCANTIDAD_CAJAS->Text=frmdatosproducto->EditCANTIDAD_CAJAS->Text.ToInt()+amount;
   DM->TProduct->Post();
}
//---------------------------------------------------------------------------

void Tfrmgestionproductos::locateTableByField(TTable *table, AnsiString field, AnsiString value) {
   TLocateOptions op;
   op<<loPartialKey;
   table->Locate(field, value, op);
}
