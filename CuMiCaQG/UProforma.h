//---------------------------------------------------------------------------
#ifndef UProformaH
#define UProformaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Graphics.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <QuickRpt.hpp>
#include <QRCtrls.hpp>
#include <DB.hpp>
#include <DBTables.hpp>
#include <ExtCtrls.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class Tfrmproforma : public TForm
{
__published:	// IDE-managed Components
    TQuickRep *QuickRep1;
    TQRBand *PageFooterBand1;
    TQRBand *ColumnHeaderBand1;
    TQRBand *DetailBand1;
    TQRExpr *QRExpr2;
    TQRExpr *QRExpr3;
    TQRExpr *QRExpr4;
    TQRExpr *QRExpr5;
        TQRExpr *QRExpr6;
        TQRLabel *QRLabel7;
        TQRLabel *QRLabel6;
   TQRBand *QRBand1;
   TQRDBText *QRDBText1;
   TQRLabel *QRLabel1;
   TQRLabel *QRLabel4;
   TQRLabel *QRLabel12;
   TQRLabel *QRLabel13;
   TQRLabel *QRLabel14;
   TQRLabel *QRLabel15;
   TQRLabel *QRLabel16;
   TQRLabel *QRLabel17;
   TQRLabel *QRLabel18;
   TQRExpr *QRExpr1;
   TQRExpr *QRExpr7;
   TQRLabel *QRLabel2;
   TDBGrid *DBGrid1;
   TQRLabel *QRLabel3;
   TQRDBText *QRDBText2;
   TQRLabel *QRLabel10;
   TQRDBText *QRDBText4;
   TQRLabel *QRLabel19;
   TQRDBText *QRDBText5;
   TQRLabel *QRLabel20;
   TQRDBText *QRDBText6;
   TQRDBText *QRDBText7;
   TQRLabel *QRLabel21;
   TQRLabel *QRLabel22;
   TQRDBText *QRDBText8;
   TQRShape *QRShape1;
   TQRShape *QRShape2;
   TQRShape *QRShape3;
   TQRShape *QRShape4;
   TQRShape *QRShape5;
   TQRShape *QRShape6;
   TQRShape *QRShape7;
   TQRShape *QRShape8;
   TQRShape *QRShape9;
   TQRShape *QRShape10;
   TQRLabel *QRLabel5;
   TQRLabel *QRLabel8;
   TQRShape *QRShape11;
   TQRShape *QRShape12;
   TQRLabel *QRLabel9;
   TQRDBText *QRDBText3;
   TQRLabel *qrlAddress;
   TQRLabel *qrlPhone;
private:	// User declarations
public:		// User declarations
    __fastcall Tfrmproforma(TComponent* Owner);
    void Tfrmproforma::setValues();
};
//---------------------------------------------------------------------------
extern PACKAGE Tfrmproforma *frmproforma;
//---------------------------------------------------------------------------
#endif
