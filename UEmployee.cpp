//----------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UEmployee.h"
#include "Unit6.h"
#include "URepayment.h"
#include "DataModule.h"
//----------------------------------------------------------------------------
#pragma resource "*.dfm"
Tfrmempleado *frmempleado;
//----------------------------------------------------------------------------
__fastcall Tfrmempleado::Tfrmempleado(TComponent *Owner)
	: TForm(Owner)
{
}
//----------------------------------------------------------------------------
void __fastcall Tfrmempleado::FormCreate(TObject *Sender)
{
         Panel1->Enabled=True;
         Panel2->Color=clRed;
         Panel1->Color=(TColor)0x0000D900;
      	DM->TEmployee->Open();
}
//----------------------------------------------------------------------------
void __fastcall Tfrmempleado::btnnuevoprodClick(TObject *Sender)
{
   Panel1->Enabled=False;
   Panel1->Color=clRed;
   Panel2->Color=(TColor)0x0000D900;
   DM->TEmployee->Insert();
   DBGrid1->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall Tfrmempleado::Button1Click(TObject *Sender)
{
   try{
      if(!Panel1->Enabled){
         Panel1->Enabled=True;
         Panel2->Color=clRed;
         Panel1->Color=(TColor)0x0000D900;
         DM->TEmployee->Post();
         DM->TEmployee->Refresh();
         Application->MessageBox("Datos de empleado guardado correctamente","OK",MB_OK | MB_ICONINFORMATION);
      }
   }
   catch(...)
   {
    Application->MessageBox("Debe llenar todos los campos de EMPLEADO","ERROR",MB_YESNO | MB_ICONERROR);
   }
}
//---------------------------------------------------------------------------
void __fastcall Tfrmempleado::Button2Click(TObject *Sender)
{
 try{
      Panel1->Enabled=True;
      Panel2->Color=clRed;
      Panel1->Color=(TColor)0x0000D900;
      DM->TEmployee->Cancel();
      DM->TEmployee->Refresh();
   }
   catch(...){}
}
//---------------------------------------------------------------------------
void __fastcall Tfrmempleado::btnmodificarprodClick(TObject *Sender)
{
   Panel1->Enabled=False;
   Panel1->Color=clRed;
   Panel2->Color=(TColor)0x0000D900;
   DM->TEmployee->Edit();
   DBGrid1->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall Tfrmempleado::btncerrarClick(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void __fastcall Tfrmempleado::btneliminarprodClick(TObject *Sender)
{
   if (Application->MessageBox("¿Seguro que desea Borrar los datos de este EMPLEADO?","Eliminar Datos de Empleado",MB_YESNO | MB_ICONQUESTION) == ID_YES)
   {
      DM->TEmployee->Delete();
      DM->TEmployee->Refresh();
    }
}
//---------------------------------------------------------------------------
void __fastcall Tfrmempleado::btnseleccionarClick(TObject *Sender)
{
   if(DBEdit1->Text==""){
      Application->MessageBox("Debe seleccionar un empleado","OK",MB_OK | MB_ICONINFORMATION);
      return;
   }
   frmdevolucion->Edit2->Text=DBEdit1->Text;
   frmventas->txtnombre->Text=DBEdit2->Text;
   frmventas->DBEdit4->Text=DBEdit1->Text;
   btnseleccionar->Visible=True;
   Close();
}
//---------------------------------------------------------------------------
