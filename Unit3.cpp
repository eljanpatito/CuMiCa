//----------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit4.h"
#include "Unit6.h"
#include "Unit8.h"
#include "Unit7.h"
#include "Unit1.h"
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
	Query1->Open();
}
//----------------------------------------------------------------------------
void __fastcall Tfrmgestionproductos::txtbuscarChange(TObject *Sender)
{

Query1->SQL->Clear();
Query1->SQL->Add("Select  `PRODUCTO`.`ID`,  `PRODUCTO`.`CODIGO`,  `PRODUCTO`.`DESCRIPCION`,  `PRODUCTO`.`CANTIDAD_CAJAS`,  `PRODUCTO`.`CANTIDAS_POR_CAJA`, `PRODUCTO`.`PRECIO_DE_COMPRA`,  `PRODUCTO`.`PRECIO_UNIDAD`,`PRODUCTO`.`PRECIO_CAJA`From `PRODUCTO`");
Query1->SQL->Add("WHERE (CODIGO LIKE '%"+txtbuscar->Text+"%' OR DESCRIPCION LIKE '%"+txtbuscar->Text+"%')");
if (!Panel1->Visible) {
   Query1->SQL->Add("AND CANTIDAD_CAJAS > 0");
//   ShowMessage("Entro");
}
Query1->Close();
Query1->Open();
}
//---------------------------------------------------------------------------
void __fastcall Tfrmgestionproductos::btncerrarClick(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void Tfrmgestionproductos::actualizar_consulta()
{
/*  Query1->SQL->Clear();
  Query1->SQL->Add("Select  `PRODUCTO`.`ID`,  `PRODUCTO`.`CODIGO`,  `PRODUCTO`.`DESCRIPCION`,  `PRODUCTO`.`CANTIDAD_CAJAS`,  `PRODUCTO`.`CANTIDAS_POR_CAJA`, `PRODUCTO`.`PRECIO_DE_COMPRA`,  `PRODUCTO`.`PRECIO_UNIDAD`,`PRODUCTO`.`PRECIO_CAJA`From `PRODUCTO`");*/
  Query1->Close();
  Query1->Open();
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
  frmdatosproducto->Table1->Insert();
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
  frmdatosproducto->Table1->Locate("ID",DBEdit1->Text,op);
  frmdatosproducto->Table1->Edit();
  frmdatosproducto->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall Tfrmgestionproductos::btneliminarprodClick(TObject *Sender) {
   if (Application->MessageBox("¿Seguro que desea Borrar los datos de este PRODUCTO?","Eliminar Datos de Producto",MB_YESNO | MB_ICONQUESTION) == ID_YES) {
      TLocateOptions op;
      op<<loPartialKey;
      frmdatosproducto->Table1->Locate("ID",DBEdit1->Text,op);
      frmdatosproducto->Table1->Delete();
      frmdatosproducto->Table1->Refresh();
      actualizar_consulta();
   }
}
//---------------------------------------------------------------------------


void __fastcall Tfrmgestionproductos::btnaumentarClick(TObject *Sender) {
   frmgestionproductos->locateTableByField(frmdatosproducto->Table1, "ID", DBEdit1->Text);
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
         frmventas->Table2->Active = false;
         frmventas->Table2->Filter = "CODIGO='"+DBEdit2->Text+"'";
         frmventas->Table2->Filtered = true;
         frmventas->Table2->Active = true;
         if (frmventas->Table2->RecordCount > 0) {
            int oldBoxQuantity = frmventas->Table2->FieldByName("CANTIDAD")->AsInteger;
            int boxQuantity = oldBoxQuantity + amount;
            frmventas->Table2->Edit();
            frmventas->Table2->FieldByName("CANTIDAD")->Text = boxQuantity;
            frmventas->Table2->FieldByName("PARCIAL")->Text=AnsiString(boxQuantity*DBEdit4->Text.ToDouble());
         } else {
            frmventas->Table2->Insert();
            frmventas->Table2->FieldByName("CODIGO")->Text=DBEdit2->Text;
            frmventas->Table2->FieldByName("DESCRIPCION")->Text=DBEdit3->Text;
            frmventas->Table2->FieldByName("CANTIDAD")->Text=Edit1->Text;
            frmventas->Table2->FieldByName("CANTIDAD_POR_CAJA")->Text = dbeAmountByBox->Text;
            frmventas->Table2->FieldByName("PRECIO")->Text=DBEdit4->Text;
            frmventas->Table2->FieldByName("PARCIAL")->Text=AnsiString(Edit1->Text.ToDouble()*DBEdit4->Text.ToDouble());
            frmventas->Table2->FieldByName("ID_NOTA")->Text=frmventas->EditIDNOTA->Text;
         }
         frmventas->EditTOTAL_CAJAS->Text=frmventas->EditTOTAL_CAJAS->Text.ToInt() + amount;
         frmventas->EditTOTAL_BS->Text=frmventas->EditTOTAL_BS->Text.ToDouble()+(amount*DBEdit4->Text.ToDouble());
         frmventas->Table2->Post();
         frmventas->Table2->Refresh();
         frmventas->Table2->Filtered = false;

         frmgestionproductos->locateTableByField(frmdatosproducto->Table1, "ID", DBEdit1->Text);
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
      this->Color=ColorDialog1->Color;
      frmmenuprincipal->color_ventana(this->Name,ColorDialog1->Color);   
}
//---------------------------------------------------------------------------

void __fastcall Tfrmgestionproductos::FormActivate(TObject *Sender)
{
  txtbuscar->Text="";
   Edit1->Text="";   
}
//---------------------------------------------------------------------------

void Tfrmgestionproductos::addAmountByID(int amount, AnsiString id) {
   AnsiString idTmp = frmdatosproducto->Table1->FieldByName("ID")->AsString;
   if (id != idTmp) {
      frmgestionproductos->locateTableByField(frmdatosproducto->Table1, "ID", id);
   }
   frmdatosproducto->Table1->Edit();
   frmdatosproducto->EditCANTIDAD_CAJAS->Text=frmdatosproducto->EditCANTIDAD_CAJAS->Text.ToInt()+amount;
   frmdatosproducto->Table1->Post();
}
//---------------------------------------------------------------------------

void Tfrmgestionproductos::locateTableByField(TTable *table, AnsiString field, AnsiString value) {
   TLocateOptions op;
   op<<loPartialKey;
   table->Locate(field, value, op);
}
