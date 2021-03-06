//----------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "USales.h"
#include "num_a_letra.h"
#include "Configuration.h"
#include "UMainMenu.h"
#include "DataModule.h"
#include "UProductManagement.h"
#include "UProduct.h"
#include "URepayment.h"
#include "UEmployee.h"
#include "UCustomer.h"
#include "UProforma.h"
#include "ULogin.h"
#include "USalesMasterDetail.h"
//----------------------------------------------------------------------------
#pragma resource "*.dfm"
Tfrmventas *frmventas;
bool isReopen;
//----------------------------------------------------------------------------
__fastcall Tfrmventas::Tfrmventas(TComponent *Owner)
	: TForm(Owner)
{
}
//----------------------------------------------------------------------------
void __fastcall Tfrmventas::btnbuscarClick(TObject *Sender)
{
frmgestioncliente->btnseleccionar->Visible=True;
frmgestioncliente->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall Tfrmventas::btnnuevaventaClick(TObject *Sender)
{
DM->TSales1->Open();
DM->TSales2->Open();
btnbuscar->Enabled=True;
DM->QSales1->SQL->Clear();
DM->QSales1->SQL->Add("select MAX(IDNOTA)+1 AS MAY FROM VENTA;");
DM->QSales1->Open();
AnsiString idnota= DM->QSales1->FieldByName("MAY")->Text;
   if (idnota == "") {
      idnota="1";
   }
DM->QSales1->Close();
Panel1->Enabled=False;
DM->TSales1->Insert();
btnbuscar->Click();
EditIDNOTA->Text=idnota;
EditTOTAL_BS->Text="0";
EditTOTAL_CAJAS->Text="0";
EditTOTAL->Text="cero";
Panel2->Enabled=True;
Panel2->Color=(TColor)0x0000D900;

EditFECHA->Text=AnsiString(DateTimePicker1->Date);
btnempleado->Click();
}
//---------------------------------------------------------------------------
void __fastcall Tfrmventas::btncancelarClick(TObject *Sender)
{
   Panel1->Enabled=True;
   Panel2->Enabled=False;
   Panel2->Color=clRed;

   if (isReopen) {
      DM->TSales1->Post();
      DM->TSales1->Close();
      DM->TSales2->Close();
      return;
   }
   DM->TSales2->First();
   while (!DM->TSales2->Eof){
     TLocateOptions op;
     op<<loPartialKey;
     DM->TProduct->Locate("CODIGO",DBEdit2->Text,op);
     int a=DBEdit3->Text.ToInt();
     DM->TProduct->Edit();
     frmdatosproducto->EditCANTIDAD_CAJAS->Text=frmdatosproducto->EditCANTIDAD_CAJAS->Text.ToInt()+a;
     DM->TProduct->Post();
     frmgestionproductos->actualizar_consulta();
     DM->TSales2->Next();
   }
   DM->TSales2->First();
   DM->TSales1->Delete();
   DM->TSales1->Refresh();
   Application->MessageBox("Venta CANCELADA","OK",MB_OK | MB_ICONINFORMATION);
   txtnombre->Text="";
   DM->TSales1->Close();
   DM->TSales2->Close();
}
//---------------------------------------------------------------------------
void __fastcall Tfrmventas::FormClose(TObject *Sender,
      TCloseAction &Action)
{
   if(Panel2->Enabled==True)
   {
      btncancelar->Click();
   }
}
//---------------------------------------------------------------------------
void __fastcall Tfrmventas::btningresarClick(TObject *Sender) {
   if(DBEdit1->Text=="") {
       Application->MessageBox("Debe Seleccionar un cliente","OK",MB_OK | MB_ICONINFORMATION);
       return;
   }
   int maxRecords = 25;
   try {
      maxRecords = frmConfiguration->getValueFromProperty("maxRecords").ToInt();
   } catch (...) {
      ShowMessage("Ocurrio un error al recuperar el maximo de registros permitido, se usara 25 como valor predeterminado");
   }
   if (DM->TSales2->RecordCount < maxRecords) {
      //btnbuscar->Enabled=False;
      DM->TSales1->Post();
      DM->TSales1->Refresh();
      DM->TSales1->Edit();
      if (!DM->QProductManagement->Active) {
         DM->QProductManagement->Open();
      }
      frmgestionproductos->Panel1->Visible=False;
      frmgestionproductos->Panel2->Visible=True;
      frmgestionproductos->ShowModal();
   } else {
      Application->MessageBox("Ya no puede agregar mas items a esta nota,\nle recomendamos crear una nueva nota.","OK",MB_OK | MB_ICONERROR);
      return;
   }
}
//---------------------------------------------------------------------------
void __fastcall Tfrmventas::EditTOTAL_BSChange(TObject *Sender)
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

void __fastcall Tfrmventas::btnvenderClick(TObject *Sender)
{
   if(EditTOTAL_BS->Text=="0")
   {
      Application->MessageBox("Minimo debe haber registrado un producto para la venta o sino presione CANCELAR","OK",MB_OK | MB_ICONINFORMATION);
      return;
   }
   Panel1->Enabled=True;
   Panel2->Enabled=False;
   Panel2->Color=clRed;
   DM->TSales1->Post();
   DM->TSales3->Active = false;
   DM->TSales3->Active = true;
   DM->TSales3->Locate("IDNOTA", DM->TSales1->FieldByName("IDNOTA")->AsString, TLocateOptions()<<loPartialKey);
   DM->TSales1->Refresh();
   Application->MessageBox("VENTA REGISTRADA CORRECTAMENTE","OK",MB_OK | MB_ICONINFORMATION);
   DM->QProforma1->Close();
   DM->QProforma1->SQL->Clear();
   DM->QProforma1->SQL->Add("SELECT DETALLE_VENTA.*, producto.*");
   DM->QProforma1->SQL->Add("FROM  PRODUCTO INNER JOIN DETALLE_VENTA ON PRODUCTO.CODIGO = DETALLE_VENTA.CODIGO");
   DM->QProforma1->SQL->Add("WHERE (((DETALLE_VENTA.ID_NOTA)="+DBEdit5->Text+"))");
// SELECT DETALLE_VENTA.* FROM DETALLE_VENTA WHERE (((DETALLE_VENTA.ID_NOTA)="+DBEdit1->Text+"))");
   DM->QProforma1->Open();
   frmproforma->QRLabel6->Caption=EditTOTAL->Text;
//   TVarRec aux[] = {};
   frmproforma->QRLabel7->Caption=FormatFloat("#,##0.00", StrToFloat(EditTOTAL_BS->Text));
   //FormatFloat("#,##0.00", StrToFloat(EditTOTAL_BS->Text));
   //EditTOTAL_BS->Text;
   DM->QProforma2->SQL->Clear();
   DM->QProforma2->SQL->Add("SELECT * FROM VENTA");
   DM->QProforma2->SQL->Add("WHERE IDNOTA ="+DBEdit5->Text+"");
   DM->QProforma2->Open();
   frmproforma->setValues();
   frmproforma->QuickRep1->PreviewModal();
   txtnombre->Text="";
   DM->TSales1->Close();
   DM->TSales2->Close();
   isReopen = false;
}
//---------------------------------------------------------------------------


void __fastcall Tfrmventas::FormCreate(TObject *Sender)
{
   this->Color=(TColor)frmmenuprincipal->cargar_color_ventana(this->Name);
   DateTimePicker1->Date=Date().CurrentDate();
   Height = StrToInt(frmConfiguration->getValueFromProperty("formHeight"));
}
//---------------------------------------------------------------------------

void __fastcall Tfrmventas::btnverventasClick(TObject *Sender)
{
   frmmaestrodetalleventa->ShowModal();
}
//---------------------------------------------------------------------------


void __fastcall Tfrmventas::btnmodificarClick(TObject *Sender)
{
   frmdevolucion->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall Tfrmventas::btncolorClick(TObject *Sender)
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


void __fastcall Tfrmventas::FormActivate(TObject *Sender)
{
   DBEdit1->Text=="";
   DM->TSales1->Close();
   DM->TSales2->Close();
}
//---------------------------------------------------------------------------


void __fastcall Tfrmventas::btnempleadoClick(TObject *Sender)
{
frmempleado->btnseleccionar->Visible=True;
frmempleado->ShowModal();

}
//---------------------------------------------------------------------------

void __fastcall Tfrmventas::FormCloseQuery(TObject *Sender, bool &CanClose)
{
if(Panel2->Enabled)
{
   Application->MessageBox("DEBE 'GUARDAR VENTA' O 'CANCELAR VENTA'","OK",MB_OK | MB_ICONINFORMATION);
   CanClose=False;
}
}
//---------------------------------------------------------------------------
void __fastcall Tfrmventas::btnQuitarClick(TObject *Sender)
{
   AnsiString code = DM->TSales2->FieldByName("CODIGO")->AsString;
   if (!code.IsEmpty()) {
      if (Application->MessageBox(("�Esta seguro de quitar:\n"
            + DM->TSales2->FieldByName("DESCRIPCION")->AsString
            + "\ndel carrito?").c_str(), "Quitar producto del carrito",
            MB_YESNO | MB_ICONQUESTION) == ID_YES) {
         frmgestionproductos->locateTableByField(DM->TProduct, "CODIGO", code);
         AnsiString id = DM->TProduct->FieldByName("ID")->AsString;
         double price = DM->TProduct->FieldByName("PRECIO_CAJA")->AsString.ToDouble();
         int amount = DBEdit3->Text.ToInt();
         frmgestionproductos->addAmountByID(amount, id);
         frmgestionproductos->actualizar_consulta();
         DM->TSales2->Delete();
         DM->TSales2->Refresh();
         frmventas->EditTOTAL_CAJAS->Text=frmventas->EditTOTAL_CAJAS->Text.ToInt() - amount;
         frmventas->EditTOTAL_BS->Text=frmventas->EditTOTAL_BS->Text.ToDouble()-(amount*price);
      }
   } else {
      ShowMessage("No existen productos para quitar del carrito.");
   }
}
//---------------------------------------------------------------------------

void __fastcall Tfrmventas::Button1Click(TObject *Sender)
{
   // Initial Data form
   DM->TSales1->Close();
   TLocateOptions opt;
   opt<<loPartialKey;
   if (!DM->TSales1->Active) {
      DM->TSales1->Active = true;
   }
   if (!DM->TSales1->Locate("IDNOTA", eIdNota->Text, opt)) {
      DM->TSales1->Close();
      Application->MessageBox("Nro de Nota no v�lido","Error",MB_OK | MB_ICONERROR);
      return;
   } else if (DM->TSales1->FieldByName("IDNOTA")->AsString != eIdNota->Text) {
      DM->TSales1->Close();
      Application->MessageBox("Nro de Nota no encontrado","Error",MB_OK | MB_ICONERROR);
      return;
   }
   if (Application->MessageBox(("�Seguro que desea reabrir la nota nro: "+eIdNota->Text+"?").c_str(),"Actualizar nota",MB_YESNO | MB_ICONQUESTION) == ID_YES) {
      Panel1->Enabled=False;
      DM->TSales1->Edit();
      DateTimePicker1->Date = EditFECHA->Text;
      //=DM->TSales1->FieldByName("FECHA")->AsString;
      txtnombre->Text = DM->TSales1->FieldByName("COD_EMP")->AsString;
      DM->TSales2->Open();
      Panel2->Enabled = true;
      Panel2->Color=(TColor)0x0000D900;
      isReopen = true;
   } else {
      isReopen = false;
      DM->TSales1->Close();
   }
}
//---------------------------------------------------------------------------

