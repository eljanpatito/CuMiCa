//----------------------------------------------------------------------------
#ifndef Unit3H
#define Unit3H
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
#include <DBTables.hpp>
#include <Grids.hpp>
#include <Mask.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
//----------------------------------------------------------------------------
class Tfrmgestionproductos : public TForm
{
__published:
	TDataSource *DataSource1;
        TDBGrid *DBGrid1;
        TEdit *txtbuscar;
        TLabel *Label1;
        TLabel *Label2;
        TButton *btncerrar;
        TQuery *Query1;
        TDBEdit *DBEdit1;
        TPanel *Panel1;
        TButton *btnnuevoprod;
        TButton *btnmodificarprod;
        TButton *btneliminarprod;
        TButton *btnaumentar;
        TPanel *Panel2;
        TButton *btnseleccionar;
        TEdit *Edit1;
        TLabel *Label3;
        TDBEdit *DBEdit2;
        TDBEdit *DBEdit3;
        TDBEdit *DBEdit4;
        TDBEdit *DBEdit5;
   TButton *btncolor;
   TColorDialog *ColorDialog1;
   TDBEdit *dbeAmountByBox;
	void __fastcall FormCreate(TObject *Sender);
        void __fastcall txtbuscarChange(TObject *Sender);
        void __fastcall btncerrarClick(TObject *Sender);
        void __fastcall txtbuscarEnter(TObject *Sender);
        void __fastcall txtbuscarExit(TObject *Sender);
        void __fastcall btnnuevoprodClick(TObject *Sender);
        void __fastcall btnmodificarprodClick(TObject *Sender);
        void __fastcall btneliminarprodClick(TObject *Sender);
        void __fastcall btnaumentarClick(TObject *Sender);
        void __fastcall btnseleccionarClick(TObject *Sender);
        void __fastcall Edit1KeyPress(TObject *Sender, char &Key);
   void __fastcall btncolorClick(TObject *Sender);
   void __fastcall FormActivate(TObject *Sender);
private:
	// private declarations
public:
	// public declarations
	__fastcall Tfrmgestionproductos(TComponent *Owner);
   void Tfrmgestionproductos::actualizar_consulta();
   void Tfrmgestionproductos::addAmountByID(int amount, AnsiString id);
   void Tfrmgestionproductos::locateTableByField(TTable *table, AnsiString field, AnsiString value);
};
//----------------------------------------------------------------------------
extern Tfrmgestionproductos *frmgestionproductos;
//----------------------------------------------------------------------------
#endif
