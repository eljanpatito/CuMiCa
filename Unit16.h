//----------------------------------------------------------------------------
#ifndef Unit16H
#define Unit16H
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
#include <ExtCtrls.hpp>
#include <Mask.hpp>
//----------------------------------------------------------------------------
class Tfrmempleado : public TForm
{
__published:
	TStringField *Table1CODIGO;
	TStringField *Table1NOMBRE_COMPLETO;
	TDataSource *DataSource1;
	TTable *Table1;
   TLabel *Label1;
   TPanel *Panel1;
   TButton *btnnuevoprod;
   TButton *btnmodificarprod;
   TPanel *Panel2;
   TButton *Button1;
   TButton *Button2;
   TDBGrid *DBGrid1;
   TButton *btneliminarprod;
   TButton *btncerrar;
   TButton *btnseleccionar;
   TDBEdit *DBEdit1;
        TDBEdit *DBEdit2;
   TStringField *Table1TELEFONO;
	void __fastcall FormCreate(TObject *Sender);
   void __fastcall btnnuevoprodClick(TObject *Sender);
   void __fastcall Button1Click(TObject *Sender);
   void __fastcall Button2Click(TObject *Sender);
   void __fastcall btnmodificarprodClick(TObject *Sender);
   void __fastcall btncerrarClick(TObject *Sender);
   void __fastcall btneliminarprodClick(TObject *Sender);
   void __fastcall btnseleccionarClick(TObject *Sender);
private:
	// private declarations
public:
	// public declarations
	__fastcall Tfrmempleado(TComponent *Owner);
};
//----------------------------------------------------------------------------
extern Tfrmempleado *frmempleado;
//----------------------------------------------------------------------------
#endif
