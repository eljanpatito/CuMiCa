//---------------------------------------------------------------------------
#ifndef USalesByEmployeeReportH
#define USalesByEmployeeReportH
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
#include <ComCtrls.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
//---------------------------------------------------------------------------
class Tfrmventaempleado : public TForm
{
__published:	// IDE-managed Components
    TQuickRep *QuickRep1;
    TQRBand *ColumnHeaderBand1;
    TQRBand *DetailBand1;
    TQRExpr *QRExpr2;
        TQRExpr *QRExpr3;
        TQRExpr *QRExpr4;
        TDBGrid *DBGrid1;
        TLabel *Label1;
        TLabel *Label2;
        TDateTimePicker *dpini;
        TButton *btnimprimir;
        TButton *btnsalir;
        TDateTimePicker *dpfin;
        TLabel *Label8;
        TDBGrid *DBGrid2;
        TDBEdit *DBEdit1;
        TDBEdit *DBEdit2;
        TDBEdit *DBEdit3;
        TDBEdit *DBEdit4;
        TQRBand *QRBand1;
        TQRLabel *QRLabel3;
        TQRLabel *QRLabel2;
        TQRLabel *QRLabel1;
        TQRLabel *QRLabel4;
        TQRLabel *QRLabel5;
        void __fastcall btnimprimirClick(TObject *Sender);
        void __fastcall btnsalirClick(TObject *Sender);
   void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall Tfrmventaempleado(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tfrmventaempleado *frmventaempleado;
//---------------------------------------------------------------------------
#endif
