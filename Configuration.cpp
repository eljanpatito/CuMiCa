//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Configuration.h"
#include "DataModule.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmConfiguration *frmConfiguration;
//---------------------------------------------------------------------------
__fastcall TfrmConfiguration::TfrmConfiguration(TComponent* Owner)
   : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmConfiguration::Font1Click(TObject *Sender)
{
   if (fdFont->Execute()) {
      lFont->Font = fdFont->Font;
   }   
}
//---------------------------------------------------------------------------
void __fastcall TfrmConfiguration::Copiaralvalor1Click(TObject *Sender)
{
   eFont->Text = "fontName="+lFont->Font->Name
         + " fontSize="+lFont->Font->Size
         + " fontColor="+lFont->Font->Color;
}
//---------------------------------------------------------------------------
void TfrmConfiguration::loadDefaultConfiguration() {
   AnsiString values[10][10];
   values[0][0] = "fontName"; values[0][1]="Tahoma";
   values[1][0] = "fontSize"; values[1][1]="10";
   values[2][0] = "fontColor"; values[2][1]="clBlack";
   values[3][0] = "fontStyles"; values[3][1]="";
   values[4][0] = "fontStylesAll"; values[4][1]="fsBold << fsUnderline << fsItalic << fsStrikeOut";
   values[5][0] = "address"; values[5][1]="Av. Villarroel No. A-3, Backovic";
   values[6][0] = "phone"; values[6][1]="Telefono: 2-5236291 - Celular: 71187384";
   values[7][0] = "maxRecords"; values[7][1]="25";
   for (int row = 0; row < 8; row++) {
      DM->tConfiguration->Active = false;
      DM->tConfiguration->Filtered = false;
      DM->tConfiguration->Filter="property='"+values[row][0]+"'";
      DM->tConfiguration->Active = true;
      DM->tConfiguration->Filtered = true;
      //frmgestionproductos->locateTableByField(DM->tConfiguration, "property", values[row][0]);
      if (DM->tConfiguration->RecordCount == 0) {
         DM->tConfiguration->Insert();
         dbeProperty->Text = values[row][0];
         dbeValue->Text = values[row][1];
         DM->tConfiguration->Post();
      }
   }
   DM->tConfiguration->Active = false;
   DM->tConfiguration->Filtered = false;
   DM->tConfiguration->Active = true;
}
void __fastcall TfrmConfiguration::FormCreate(TObject *Sender)
{
   frmConfiguration->loadDefaultConfiguration();   
}
//---------------------------------------------------------------------------
AnsiString TfrmConfiguration::getValueFromProperty(AnsiString property) {
   frmgestionproductos->locateTableByField(DM->tConfiguration, "property", property);
   return DM->tConfiguration->FieldByName("value")->AsString;
}
