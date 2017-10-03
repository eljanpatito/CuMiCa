//----------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit6.h"
#include "Unit2.h"
#include "Unit14.h"
#include "URepayment.h"
#include "num_a_letra.h"
#include "Unit17.h"
#include "UMainMenu.h"
#include "UProductManagement.h"
#include "DataModule.h"
#include "UProduct.h"
#include "UEmployee.h"
#include "UCustomer.h"
#include "UProforma.h"
//----------------------------------------------------------------------------
#pragma resource "*.dfm"
Tfrmdevolucion *frmdevolucion;
int cajas;
//----------------------------------------------------------------------------
__fastcall Tfrmdevolucion::Tfrmdevolucion(TComponent *Owner)
	: TForm(Owner)
{
}
//----------------------------------------------------------------------------
void __fastcall Tfrmdevolucion::FormCreate(TObject *Sender)
{
   this->Color=(TColor)frmmenuprincipal->cargar_color_ventana(this->Name);
	DM->QRepayment1->Open();
	DM->QRepayment3->Open();
}
//----------------------------------------------------------------------------
void __fastcall Tfrmdevolucion::Edit1Change(TObject *Sender)
{
DM->QRepayment1->SQL->Clear();
 DM->QRepayment1->SQL->Add("select * from venta where nombre_cliente like '%"+Edit1->Text+"%'");
 DM->QRepayment1->Open();
}
//---------------------------------------------------------------------------

void __fastcall Tfrmdevolucion::DBEdit1Change(TObject *Sender)
{
if(DBEdit1->Text!=""){
        DM->TRepayment1->Filter= "IDNOTA="+DBEdit1->Text;
        DM->TRepayment1->Filtered=True;
}
}
//---------------------------------------------------------------------------
void __fastcall Tfrmdevolucion::DBEdit8Change(TObject *Sender)
{
   if(DBEdit8->Text!=""){
      DM->TRepayment2->Filter= "ID="+DBEdit8->Text;
      DM->TRepayment2->Filtered=True;
   }
}
//---------------------------------------------------------------------------

void __fastcall Tfrmdevolucion::btnimprimirClick(TObject *Sender)
{
  AnsiString cantidad; double aux;
  cantidad=InputBox("Devolver cajas","DESCRIPCION: "+DBEdit9->Text+"\n\nCantidad de Cajas:","");
  if (!DM->TRepayment2->Active) {
      DM->TRepayment2->Active=true;
  }
  aux= DBEdit7->Text.ToDouble();
  try{
   int a=cantidad.ToInt();
//   if(DBEdit6->Text.ToInt()-a==0)
//   {
//    Application->MessageBox("No puede devolver todos los productos pedidos","OK",MB_OK | MB_ICONERROR);
//    return;
//   }
       if(a>0 && a<=DBEdit6->Text.ToInt()){

        DM->TRepayment2->Edit();
        DBEdit6->Text=DBEdit6->Text.ToInt()-a;
        DBEdit7->Text=DBEdit10->Text.ToDouble()*DBEdit6->Text.ToDouble();
        DM->TRepayment2->Post();
        DM->TRepayment2->Refresh();

        DM->TRepayment1->Edit();
        EditTOTAL_CAJAS->Text=EditTOTAL_CAJAS->Text.ToInt()-a;
        EditTOTAL_BS->Text=EditTOTAL_BS->Text.ToDouble()-aux+DBEdit7->Text.ToDouble();
        DM->TRepayment1->Post();
        DM->TRepayment1->Refresh();
         if (!DM->TProduct->Active) {
            DM->TProduct->Active=true;
         }
        TLocateOptions op;
        op<<loPartialKey;
        DM->TProduct->Locate("CODIGO",DBEdit11->Text,op);

        DM->TProduct->Edit();
        frmdatosproducto->EditCANTIDAD_CAJAS->Text=frmdatosproducto->EditCANTIDAD_CAJAS->Text.ToInt()+a;
        DM->TProduct->Post();
        frmgestionproductos->actualizar_consulta();

         if (!DM->TRepayment3->Active) {
            DM->TRepayment3->Active=true;
         }
        DM->TRepayment3->Insert();
        DM->TRepayment3->FieldByName("CODIGO_EMPLEADO")->Text=Edit2->Text;
        DM->TRepayment3->FieldByName("CODIGO_PRODUCTO")->Text= DBEdit11->Text;
        DM->TRepayment3->FieldByName("CANTIDAD")->Text=a;
        DM->TRepayment3->FieldByName("ID_NOTA")->Text=DBEdit12->Text;
        DM->TRepayment3->Post();
        DM->TRepayment3->Refresh();
        if(DBEdit6->Text=="0"){
            DM->TRepayment2->Delete();
            DM->TRepayment2->Refresh();
        }
        DM->QRepayment3->Close();
        DM->QRepayment3->Open();
        Application->MessageBox("Cantidad actualizada correctamente","OK",MB_OK | MB_ICONINFORMATION);

   }
   else
    Application->MessageBox("Cantidad debe ser mayor a 0 (cero) y menor o igual a la catidad de cajas","Error",MB_OK | MB_ICONERROR);
  } catch (EDatabaseError &e) {
      Application->MessageBox(e.Message.c_str(), "Error", MB_OK);
  }
  catch(...) {
      Application->MessageBox("Cantidad no Valida, no se actualiza la cantidad","Error",MB_OK | MB_ICONERROR);
  }

}
//---------------------------------------------------------------------------

void __fastcall Tfrmdevolucion::EditTOTAL_BSChange(TObject *Sender)
{
AnsiString sum=EditTOTAL_BS->Text;
AnsiString s1="",st="",s2="";
int i=sum.Pos(",");
if(i!=0){
        s1=sum.SubString(1,i-1);
        st=sum.SubString(i+1,sum.Length()-i);
        if(st.Length()==1)
        EditTOTAL->Text=AnsiString(convertir(s1.c_str()))+" "+st+"0/100 Bs.";
        else
        EditTOTAL->Text=AnsiString(convertir(s1.c_str()))+" "+st+"/100 Bs.";
}
else
{
     EditTOTAL->Text=AnsiString(convertir(sum.c_str()))+"00/100 Bs.";
}

}
//---------------------------------------------------------------------------

void __fastcall Tfrmdevolucion::btncolorClick(TObject *Sender)
{
      ColorDialog1->Execute();
      this->Color=ColorDialog1->Color;
      frmmenuprincipal->color_ventana(this->Name,ColorDialog1->Color);
}
//---------------------------------------------------------------------------

void __fastcall Tfrmdevolucion::btnbuscarClick(TObject *Sender)
{
frmempleado->btnseleccionar->Visible=True;
frmempleado->ShowModal();
frmventas->txtnombre->Text="";
}
//---------------------------------------------------------------------------

void __fastcall Tfrmdevolucion::btnaceptarempleadoClick(TObject *Sender)
{
   if(DBEdit12->Text!="" && Edit2->Text !=""){
      Panel2->Enabled=True;
      Panel1->Enabled=False;
      Panel1->Color=clRed;
      Panel2->Color=(TColor)0x0000D900;
      if (DBEdit6->Text.Length()>0)
         cajas=DBEdit6->Text.ToInt();
      else
         cajas = 0;
   }
   else
   Application->MessageBox("Debe seleccionar un EMPLEADO y un CLIENTE","Error",MB_OK | MB_ICONERROR);


}
//---------------------------------------------------------------------------

void __fastcall Tfrmdevolucion::Button1Click(TObject *Sender)
{
   Panel1->Enabled=True;
   Panel2->Enabled=False;
   Panel2->Color=clRed;
   Panel1->Color=(TColor)0x0000D900;
   
//   if(cajas==DBEdit6->Text.ToInt())
//   {
//     Application->MessageBox("No se hizo ninguna modificacion","OK",MB_OK | MB_ICONINFORMATION);
//     Close();
//    return;

//   }
   frmrepdevolucion->Query1->SQL->Clear();
   frmrepdevolucion->Query1->SQL->Add("select * from devolucion where id_nota ="+DBEdit12->Text);
   frmrepdevolucion->Query1->Open();
   frmrepdevolucion->Quickrep1->PreviewModal();
   DM->QRepayment1->SQL->Clear();
   DM->QRepayment1->SQL->Add("select * from venta where nombre_cliente like '%"+Edit1->Text+"%'");
   DM->QRepayment1->Open();
   Close();

}
//---------------------------------------------------------------------------

void __fastcall Tfrmdevolucion::FormActivate(TObject *Sender)
{
   Panel1->Enabled=True;
   Panel2->Enabled=False;
   Panel2->Color=clRed;
   Panel1->Color=(TColor)0x0000D900;
   Edit1->Text="";
   Edit2->Text="";
   DM->QRepayment1->Close();
   DM->QRepayment1->Open();
   DM->TRepayment1->Active = true;
}
//---------------------------------------------------------------------------

void __fastcall Tfrmdevolucion::FormClose(TObject *Sender,
      TCloseAction &Action)
{
frmventas->txtnombre->Text="";
}
//---------------------------------------------------------------------------

void __fastcall Tfrmdevolucion::FormCloseQuery(TObject *Sender,
      bool &CanClose)
{
  if(Panel2->Enabled)
  {
     Application->MessageBox("DEBE TERMINAR LA DEVOLUCION","OK",MB_OK | MB_ICONINFORMATION);
     CanClose=False;
  }
}
//---------------------------------------------------------------------------

