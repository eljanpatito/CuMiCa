//---------------------------------------------------------------------------

#ifndef SegProductosH
#define SegProductosH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <QuickRpt.hpp>
#include <QRCtrls.hpp>
//---------------------------------------------------------------------------
class TfRepSeguimiento : public TForm
{
__published:	// IDE-managed Components
   TQuickRep *QuickRep1;
   TQRBand *QRBand1;
   TQRLabel *QRLabel4;
   TQRLabel *QRLabel3;
   TQRLabel *QRLabel1;
   TQRLabel *QRLabel2;
   TQRLabel *QRLabel5;
   TQRDBText *QRDBText1;
   TQRDBText *QRDBText2;
   TQRLabel *QRLabel6;
   TQRLabel *QRLabel7;
   TQRLabel *QRLabel8;
   TQRBand *QRBand2;
   TQRDBText *QRDBText3;
   TQRDBText *QRDBText4;
   TQRDBText *QRDBText5;
   TQRBand *QRBand3;
   TQRLabel *QRLabel10;
   TQRLabel *QRLabel9;
   TQRDBText *QRDBText6;
   TQRDBText *QRDBText7;
private:	// User declarations
public:		// User declarations
   __fastcall TfRepSeguimiento(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfRepSeguimiento *fRepSeguimiento;
//---------------------------------------------------------------------------
#endif
