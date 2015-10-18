//---------------------------------------------------------------------------
#ifndef Unit17H
#define Unit17H
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
class Tfrmrepdevolucion : public TForm
{
__published:	// IDE-managed Components
   TQuickRep *Quickrep1;
    TQRBand *PageFooterBand1;
    TQRExpr *QRExpr1;
    TQRBand *ColumnHeaderBand1;
    TQRBand *DetailBand1;
    TQRLabel *QRLabel1;
    TQRLabel *QRLabel2;
    TQRExpr *QRExpr3;
    TQRLabel *QRLabel3;
   TQuery *Query1;
   TQRBand *QRBand1;
   TQRLabel *QRLabel4;
   TQRExpr *QRExpr2;
   TQRExpr *QRExpr5;
   TQRLabel *QRLabel5;
   TQRExpr *QRExpr4;
private:	// User declarations
public:		// User declarations
    __fastcall Tfrmrepdevolucion(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tfrmrepdevolucion *frmrepdevolucion;
//---------------------------------------------------------------------------
#endif
