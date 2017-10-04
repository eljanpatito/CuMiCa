//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UProforma.h"
#include "Configuration.h"
#include "DataModule.h"
#include "USales.h"
#include "USalesMasterDetail.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tfrmproforma *frmproforma;
//---------------------------------------------------------------------------
__fastcall Tfrmproforma::Tfrmproforma(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void Tfrmproforma::setValues()
{
   qrlAddress->Caption = frmConfiguration->getValueFromProperty("address");
   qrlPhone->Caption = frmConfiguration->getValueFromProperty("phone");
   qrlAddress->Font->Name = frmConfiguration->getValueFromProperty("fontName");
   qrlAddress->Font->Size = StrToInt(frmConfiguration->getValueFromProperty("fontSize"));
   qrlAddress->Font->Color = StringToColor(frmConfiguration->getValueFromProperty("fontColor"));
   qrlPhone->Font = qrlAddress->Font;
}
//---------------------------------------------------------------------------

