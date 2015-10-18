//---------------------------------------------------------------------------
#ifndef Unit7H
#define Unit7H
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
class Tfrmrepproducto : public TForm
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
    TQRLabel *QRLabel4;
    TQRExpr *QRExpr5;
    TQRLabel *QRLabel5;
    TQRExpr *QRExpr6;
    TQRLabel *QRLabel6;
    TQRExpr *QRExpr7;
        TQRBand *QRBand2;
        TQRLabel *QRLabel7;
        TQRDBText *QRDBText1;
        TQRLabel *QRLabel8;
        TButton *Button1;
        TQuery *Query1;
        TLabel *Label2;
        TButton *Button2;
        TButton *btnsalir;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall btnsalirClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall Tfrmrepproducto(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tfrmrepproducto *frmrepproducto;
//---------------------------------------------------------------------------
#endif
