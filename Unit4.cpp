//----------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
//----------------------------------------------------------------------------
#pragma resource "*.dfm"
Tfrmdatosproducto *frmdatosproducto;
//----------------------------------------------------------------------------
__fastcall Tfrmdatosproducto::Tfrmdatosproducto(TComponent *Owner)
	: TForm(Owner)
{
}
//----------------------------------------------------------------------------
void __fastcall Tfrmdatosproducto::FormCreate(TObject *Sender)
{
	Table1->Open();
}
//----------------------------------------------------------------------------
void __fastcall Tfrmdatosproducto::btnguardarClick(TObject *Sender)
{
try{
Table1->Post();
Application->MessageBox("DATOS DE PRODUCTO CORRECTAMENTE GUARDADOS","OK",MB_OK | MB_ICONINFORMATION);
frmgestionproductos->actualizar_consulta();
Close();
}
catch(...)
{
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
   Table1->Cancel();
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
if( ((TEdit *)Sender)->Text=="")
((TEdit *)Sender)->Color=clMaroon;
else
((TEdit *)Sender)->Color=clWhite;
}
//---------------------------------------------------------------------------


void __fastcall Tfrmdatosproducto::FormActivate(TObject *Sender)
{
   EditCODIGO->SetFocus();
}
//---------------------------------------------------------------------------

