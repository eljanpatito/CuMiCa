//---------------------------------------------------------------------------
#ifndef Unit10H
#define Unit10H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Graphics.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <QuickRpt.hpp>
#include <QRCtrls.hpp>
#include <ComCtrls.hpp>
#include <DB.hpp>
#include <DBTables.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class Tfrmreporteventa : public TForm
{
__published:	// IDE-managed Components
    TQuickRep *QuickRep1;
    TQRBand *PageFooterBand1;
    TQRExpr *QRExpr1;
    TQRBand *ColumnHeaderBand1;
    TQRLabel *QRLabel1;
    TQRLabel *QRLabel2;
    TQRLabel *QRLabel3;
    TQRLabel *QRLabel4;
        TQRBand *QRBand2;
        TQRLabel *QRLabel7;
        TQRBand *QRBand1;
        TQRExpr *QRExpr6;
        TQRExpr *QRExpr7;
        TQRExpr *QRExpr8;
        TQRExpr *QRExpr9;
        TQRBand *QRBand3;
        TQRLabel *QRLabel5;
        TQRLabel *QRLabel8;
        TQRLabel *QRLabel9;
        TQRExpr *QRExpr2;
        TQRLabel *QRLabel6;
        TDateTimePicker *DateTimePicker1;
        TLabel *Label8;
        TLabel *Label1;
        TQuery *Query1;
        TQRExpr *QRExpr3;
        TButton *btnimprimir;
        TQuery *Query2;
        TButton *btnsalir;
        void __fastcall btnimprimirClick(TObject *Sender);
        void __fastcall btnsalirClick(TObject *Sender);
   void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall Tfrmreporteventa(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tfrmreporteventa *frmreporteventa;
//---------------------------------------------------------------------------
#endif
