//----------------------------------------------------------------------------
#ifndef URepaymentH
#define URepaymentH
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
//----------------------------------------------------------------------------
class Tfrmdevolucion : public TForm
{
__published:
        TLabel *Label7;
        TDBEdit *DBEdit1;
        TDBEdit *DBEdit2;
   TDBEdit *DBEdit3;
   TDBEdit *DBEdit4;
   TDBEdit *DBEdit5;
   TColorDialog *ColorDialog1;
   TButton *btncolor;
   TPanel *Panel1;
   TLabel *Label1;
   TEdit *Edit2;
   TButton *btnbuscar;
   TLabel *Label2;
   TEdit *Edit1;
   TDBGrid *DBGrid3;
   TButton *btnaceptarempleado;
   TPanel *Panel2;
   TLabel *Label8;
   TLabel *Label4;
   TLabel *Label3;
   TDBEdit *DBEdit7;
   TDBEdit *DBEdit10;
   TDBEdit *DBEdit6;
   TDBEdit *DBEdit9;
   TDBEdit *DBEdit11;
   TDBEdit *DBEdit8;
   TDBGrid *DBGrid2;
   TButton *btnimprimir;
   TDBEdit *EditTOTAL;
   TDBEdit *EditTOTAL_BS;
   TDBEdit *EditTOTAL_CAJAS;
   TButton *Button1;
   TDBEdit *DBEdit12;
   TDBText *DBText1;
	void __fastcall FormCreate(TObject *Sender);
        void __fastcall Edit1Change(TObject *Sender);
        void __fastcall DBEdit1Change(TObject *Sender);
   void __fastcall DBEdit8Change(TObject *Sender);
   void __fastcall btnimprimirClick(TObject *Sender);
   void __fastcall EditTOTAL_BSChange(TObject *Sender);
   void __fastcall btncolorClick(TObject *Sender);
   void __fastcall btnbuscarClick(TObject *Sender);
   void __fastcall btnaceptarempleadoClick(TObject *Sender);
   void __fastcall Button1Click(TObject *Sender);
   void __fastcall FormActivate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
private:
	// private declarations
public:
	// public declarations
	__fastcall Tfrmdevolucion(TComponent *Owner);
};
//----------------------------------------------------------------------------
extern Tfrmdevolucion *frmdevolucion;
//----------------------------------------------------------------------------
#endif
