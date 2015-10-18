//---------------------------------------------------------------------------
#ifndef Unit11H
#define Unit11H
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
        TQuery *Query1;
        TQRLabel *QRLabel7;
        TQRLabel *QRLabel6;
   TQRBand *QRBand1;
   TQRDBText *QRDBText1;
   TQRLabel *qrlDia;
   TQRLabel *qrlMes;
   TQRLabel *qrlAnio;
   TQRLabel *QRLabel1;
   TQRDBText *QRDBText3;
   TTable *Table1;
   TQRLabel *QRLabel3;
   TQRLabel *QRLabel4;
   TQRShape *QRShape1;
   TQRShape *QRShape2;
   TQRShape *QRShape3;
   TQRShape *QRShape4;
   TQRShape *QRShape5;
   TQRShape *QRShape6;
   TQRLabel *QRLabel5;
   TQRLabel *QRLabel8;
   TQRLabel *QRLabel9;
   TQRLabel *QRLabel11;
   TQRLabel *QRLabel12;
   TQRLabel *QRLabel13;
   TQRLabel *QRLabel14;
   TQRLabel *QRLabel15;
   TQRLabel *QRLabel16;
   TQRLabel *QRLabel17;
   TQRLabel *QRLabel18;
   TQRExpr *QRExpr1;
   TIntegerField *Table1IDNOTA;
   TStringField *Table1NOMBRE_CLIENTE;
   TIntegerField *Table1TOTAL_CAJAS;
   TFloatField *Table1TOTAL_BS;
   TStringField *Table1TOTAL;
   TDateTimeField *Table1FECHA;
   TStringField *Table1COD_EMP;
   TQRExpr *QRExpr7;
   TQRLabel *QRLabel2;
   TDataSource *DataSource1;
   TDBGrid *DBGrid1;
   TDataSource *DataSource2;
   TQuery *Query2;
   TIntegerField *Query1Id;
   TStringField *Query1CODIGO;
   TStringField *Query1DESCRIPCION;
   TIntegerField *Query1CANTIDAD;
   TFloatField *Query1PRECIO;
   TFloatField *Query1PARCIAL;
   TIntegerField *Query1ID_NOTA;
   TSmallintField *Query1CANTIDAD_CAJAS;
   TSmallintField *Query1CANTIDAS_POR_CAJA;
   TFloatField *Query1PRECIO_DE_COMPRA;
   TFloatField *Query1PRECIO_UNIDAD;
   TFloatField *Query1PRECIO_CAJA;
private:	// User declarations
public:		// User declarations
    __fastcall Tfrmproforma(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tfrmproforma *frmproforma;
//---------------------------------------------------------------------------
#endif
