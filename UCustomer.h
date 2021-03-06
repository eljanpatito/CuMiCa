//----------------------------------------------------------------------------
#ifndef UCustomerH
#define UCustomerH
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
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <Mask.hpp>
//----------------------------------------------------------------------------
class Tfrmgestioncliente : public TForm
{
__published:
        TDBGrid *DBGrid1;
        TLabel *Label2;
        TPanel *Panel1;
        TButton *btnnuevocliente;
        TButton *btnmodificarcliente;
        TButton *btneliminarcliente;
        TButton *btncerrar;
        TPanel *Panel2;
        TDBEdit *DBEdit1;
        TDBEdit *DBEdit2;
        TDBEdit *DBEdit3;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TButton *btnguardar;
        TButton *btncancelar;
        TLabel *Label1;
        TEdit *txtbuscar;
        TButton *btnseleccionar;
   TLabel *Label6;
   TDBEdit *DBEdit4;
   TLabel *Label7;
   TDBEdit *dbeCliCelular;
   TLabel *Label8;
   TDBEdit *dbeCliCiudad;
   TLabel *Label9;
   TDBEdit *DBEdit5;
        void __fastcall btncerrarClick(TObject *Sender);
        void __fastcall btnnuevoclienteClick(TObject *Sender);
        void __fastcall DBEdit1Enter(TObject *Sender);
        void __fastcall DBEdit1Exit(TObject *Sender);
        void __fastcall btncancelarClick(TObject *Sender);
        void __fastcall btnguardarClick(TObject *Sender);
        void __fastcall txtbuscarChange(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall btnmodificarclienteClick(TObject *Sender);
        void __fastcall btneliminarclienteClick(TObject *Sender);
        void __fastcall btnseleccionarClick(TObject *Sender);
   void __fastcall FormActivate(TObject *Sender);
private:
	// private declarations
public:
	// public declarations
	__fastcall Tfrmgestioncliente(TComponent *Owner);
        void iniciar_ingreso_de_datos();
        bool customerIsNew(AnsiString nit);
};
//----------------------------------------------------------------------------
extern Tfrmgestioncliente *frmgestioncliente;
//----------------------------------------------------------------------------
#endif
