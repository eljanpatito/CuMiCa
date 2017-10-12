//----------------------------------------------------------------------------
#ifndef USalesH
#define USalesH
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
#include <ComCtrls.hpp>
#include <DBTables.hpp>
#include <ExtCtrls.hpp>
#include <Mask.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <QuickRpt.hpp>
#include <Dialogs.hpp>
//----------------------------------------------------------------------------
class Tfrmventas : public TForm
{
__published:
	TPanel *Panel2;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TDBEdit *EditIDNOTA;
        TDBEdit *EditTOTAL_CAJAS;
        TDBEdit *EditTOTAL_BS;
        TDBEdit *EditTOTAL;
        TLabel *Label7;
        TDBEdit *EditFECHA;
        TLabel *Label8;
        TButton *btnbuscar;
        TDateTimePicker *DateTimePicker1;
        TButton *btncancelar;
        TDBGrid *DBGrid1;
        TDBEdit *DBEdit1;
        TDBGrid *DBGrid2;
        TButton *btningresar;
        TButton *btnvender;
        TDBEdit *DBEdit2;
        TDBEdit *DBEdit3;
   TButton *btncolor;
   TColorDialog *ColorDialog1;
   TPanel *Panel1;
   TButton *btnnuevaventa;
   TButton *btnverventas;
   TButton *btnmodificar;
        TButton *btnempleado;
        TDBEdit *DBEdit4;
        TLabel *Label5;
        TEdit *txtnombre;
   TDBEdit *DBEdit5;
        TButton *btnQuitar;
   TLabel *Label6;
        void __fastcall btnbuscarClick(TObject *Sender);
        void __fastcall btnnuevaventaClick(TObject *Sender);
        void __fastcall btncancelarClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall btningresarClick(TObject *Sender);
        void __fastcall EditTOTAL_BSChange(TObject *Sender);
        void __fastcall btnvenderClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall btnverventasClick(TObject *Sender);
        void __fastcall btnmodificarClick(TObject *Sender);
   void __fastcall btncolorClick(TObject *Sender);
   void __fastcall FormActivate(TObject *Sender);
        void __fastcall btnempleadoClick(TObject *Sender);
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
   void __fastcall btnQuitarClick(TObject *Sender);
private:
	// private declarations
public:
	// public declarations
	__fastcall Tfrmventas(TComponent *Owner);
};
//----------------------------------------------------------------------------
extern Tfrmventas *frmventas;
//----------------------------------------------------------------------------
#endif
