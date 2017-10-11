//----------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UProduct.h"
#include "DataModule.h"
#include "UMainMenu.h"
#include "UProductManagement.h"
#include "ULogin.h"
//----------------------------------------------------------------------------
#pragma resource "*.dfm"
Tfrmdatosproducto *frmdatosproducto;
AnsiString oldProductCode, newProductCode;
//----------------------------------------------------------------------------
__fastcall Tfrmdatosproducto::Tfrmdatosproducto(TComponent *Owner)
	: TForm(Owner)
{
}
//----------------------------------------------------------------------------
void __fastcall Tfrmdatosproducto::btnguardarClick(TObject *Sender)
{
   try {
      if (EditCODIGO->Text.Trim().IsEmpty()) {
         Application->MessageBox("El codigo ingresado no puede ser vacio. Ingrese un codigo válido o cancele la operacion.","Error",MB_OK | MB_ICONERROR);
      }
      if (oldProductCode != EditCODIGO->Text) {
         DM->qFindProduct->Close();
         DM->qFindProduct->ParamByName("codigo")->AsString = EditCODIGO->Text;
         DM->qFindProduct->Open();
         if (DM->qFindProduct->RecordCount > 0) {
            Application->MessageBox("El codigo ingresado ya existe. Ingrese un codigo diferente o cancele la operacion.","Error",MB_OK | MB_ICONERROR);
            EditCODIGO->SetFocus();
            return;
         }
      }
      DM->TProduct->Post();
      Application->MessageBox("DATOS DE PRODUCTO CORRECTAMENTE GUARDADOS","OK",MB_OK | MB_ICONINFORMATION);
      frmgestionproductos->actualizar_consulta();
      Close();
   } catch(...) {
      Application->MessageBox("Debe ingresar todos los campos correctamente","Error",MB_OK | MB_ICONERROR);
   }
}
//---------------------------------------------------------------------------
void __fastcall Tfrmdatosproducto::btncancelarClick(TObject *Sender)
{
EditCODIGO->Color=clWhite;EditDESCRIPCION->Color=clWhite;
EditCANTIDAD_CAJAS->Color=clWhite;EditCANTIDAS_POR_CAJA->Color=clWhite;
EditPRECIO_CAJA->Color=clWhite;EditPRECIO_DE_COMPRA->Color=clWhite;
EditPRECIO_UNIDAD->Color=clWhite;
   DM->TProduct->Cancel();
Close();
}
//---------------------------------------------------------------------------
void __fastcall Tfrmdatosproducto::EditCODIGOEnter(TObject *Sender)
{
((TEdit *)Sender)->Color=clLime;
}
//---------------------------------------------------------------------------

void __fastcall Tfrmdatosproducto::EditCODIGOExit(TObject *Sender)
{
   if( ((TEdit *)Sender)->Text=="") {
      ((TEdit *)Sender)->Color=clMaroon;
   } else {
      ((TEdit *)Sender)->Color=clWhite;
   }
}
//---------------------------------------------------------------------------


void __fastcall Tfrmdatosproducto::FormActivate(TObject *Sender)
{
   EditCODIGO->SetFocus();
   oldProductCode = EditCODIGO->Text;
}
//---------------------------------------------------------------------------

