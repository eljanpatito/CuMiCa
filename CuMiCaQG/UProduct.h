//----------------------------------------------------------------------------
#ifndef UProductH
#define UProductH
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
#include <DBTables.hpp>
#include <Mask.hpp>
//----------------------------------------------------------------------------
class Tfrmdatosproducto : public TForm
{
__published:
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TDBEdit *EditCODIGO;
        TDBEdit *EditDESCRIPCION;
        TDBEdit *EditCANTIDAD_CAJAS;
        TDBEdit *EditCANTIDAS_POR_CAJA;
        TDBEdit *EditPRECIO_DE_COMPRA;
        TDBEdit *EditPRECIO_UNIDAD;
        TDBEdit *EditPRECIO_CAJA;
        TLabel *Label8;
        TButton *btnguardar;
        TButton *btncancelar;
        void __fastcall btnguardarClick(TObject *Sender);
        void __fastcall btncancelarClick(TObject *Sender);
        void __fastcall EditCODIGOEnter(TObject *Sender);
        void __fastcall EditCODIGOExit(TObject *Sender);
   void __fastcall FormActivate(TObject *Sender);
private:
	// private declarations
public:
	// public declarations
	__fastcall Tfrmdatosproducto(TComponent *Owner);
};
//----------------------------------------------------------------------------
extern Tfrmdatosproducto *frmdatosproducto;
//----------------------------------------------------------------------------
#endif
