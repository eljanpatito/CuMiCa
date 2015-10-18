//----------------------------------------------------------------------------
#ifndef Unit14H
#define Unit14H
//----------------------------------------------------------------------------
#include <SysUtils.hpp>
#include <Windows.hpp>
#include <Messages.hpp>
#include <Classes.hpp>
#include <Graphics.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBCtrls.hpp>
#include <DB.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <DBTables.hpp>
#include <Grids.hpp>
#include <Mask.hpp>
#include <Dialogs.hpp>
#include <Buttons.hpp>
#include <QRCtrls.hpp>
#include <QuickRpt.hpp>
//----------------------------------------------------------------------------
class Tfrmmaestrodetalleventa : public TForm
{
__published:
	TIntegerField *Query1IDNOTA;
	TStringField *Query1NOMBRE_CLIENTE;
	TIntegerField *Query1TOTAL_CAJAS;
	TFloatField *Query1TOTAL_BS;
	TStringField *Query1TOTAL;
	TDateTimeField *Query1FECHA;
	TStringField *Query2CODIGO;
	TStringField *Query2DESCRIPCION;
	TIntegerField *Query2CANTIDAD;
	TFloatField *Query2PRECIO;
	TFloatField *Query2PARCIAL;
	TDataSource *DataSource1;
	TQuery *Query1;
	TQuery *Query2;
	TDataSource *DataSource2;
        TDBGrid *DBGrid1;
        TDBGrid *DBGrid2;
        TLabel *Label7;
        TEdit *Edit1;
        TLabel *Label2;
        TButton *btnimprimir;
        TDBEdit *DBEdit1;
        TDBEdit *DBEdit2;
        TDBEdit *DBEdit3;
        TDBEdit *DBEdit4;
   TColorDialog *ColorDialog1;
   TButton *btncolor;
   TTable *Table1;
   TDataSource *DataSource3;
   TDBGrid *DBGrid3;
   TLabel *Label1;
   TLabel *Label3;
   TQuickRep *QuickRep1;
   TQRBand *QRBand1;
   TQRLabel *QRLabel1;
   TQRLabel *QRLabel2;
   TQRLabel *QRLabel3;
   TQRLabel *QRLabel4;
   TQRLabel *QRLabel5;
   TQRLabel *QRLabel6;
   TQRLabel *QRLabel7;
   TQRLabel *QRLabel8;
   TQRBand *QRBand2;
   TQRDBText *QRDBText1;
   TQRDBText *QRDBText2;
   TQRDBText *QRDBText3;
   TQRDBText *QRDBText4;
   TQRDBText *QRDBText5;
   TBitBtn *BitBtn1;
   TQRBand *QRBand3;
   TQRExpr *QRExpr1;
   TQRLabel *QRLabel9;
	void __fastcall FormCreate(TObject *Sender);
        void __fastcall Edit1Change(TObject *Sender);
        void __fastcall btnimprimirClick(TObject *Sender);
   void __fastcall btncolorClick(TObject *Sender);
   void __fastcall FormActivate(TObject *Sender);
   void __fastcall BitBtn1Click(TObject *Sender);
private:
	// private declarations
public:
	// public declarations
	__fastcall Tfrmmaestrodetalleventa(TComponent *Owner);
};
//----------------------------------------------------------------------------
extern Tfrmmaestrodetalleventa *frmmaestrodetalleventa;
//----------------------------------------------------------------------------
#endif
