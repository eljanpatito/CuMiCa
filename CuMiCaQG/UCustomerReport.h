//---------------------------------------------------------------------------
#ifndef UCustomerReportH
#define UCustomerReportH
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
//---------------------------------------------------------------------------
class Tfrmrepcliente : public TForm
{
__published:	// IDE-managed Components
    TQuickRep *QuickRep1;
    TQRBand *PageFooterBand1;
    TQRExpr *QRExpr1;
    TQRBand *ColumnHeaderBand1;
    TQRBand *DetailBand1;
    TQRLabel *QRLabel1;
    TQRExpr *QRExpr2;
    TQRLabel *QRLabel2;
    TQRExpr *QRExpr3;
    TQRLabel *QRLabel3;
    TQRExpr *QRExpr4;
        TQRBand *QRBand1;
        TQRLabel *QRLabel4;
private:	// User declarations
public:		// User declarations
    __fastcall Tfrmrepcliente(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tfrmrepcliente *frmrepcliente;
//---------------------------------------------------------------------------
#endif
