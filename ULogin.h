//----------------------------------------------------------------------------
#ifndef ULoginH
#define ULoginH
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
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
//----------------------------------------------------------------------------
class Tfrmlogin : public TForm
{
__published:
        TLabel *Label1;
        TLabel *Label2;
        TDBEdit *EditUSUARIO;
        TDBEdit *EditPASSWORD;
        TDBEdit *EditNOMBRE;
        TDBEdit *EditAPELLIDO;
        TLabel *Label5;
        TEdit *txtusuario;
        TEdit *txtpassword;
        TImage *Image1;
        TButton *btningresar;
        TButton *btncancelar;
        TDBEdit *DBEdit1;
	void __fastcall FormCreate(TObject *Sender);
        void __fastcall btncancelarClick(TObject *Sender);
        void __fastcall btningresarClick(TObject *Sender);
        void __fastcall txtusuarioEnter(TObject *Sender);
        void __fastcall txtusuarioExit(TObject *Sender);
        void __fastcall txtusuarioKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall txtusuarioKeyPress(TObject *Sender, char &Key);
        void __fastcall txtpasswordKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:
	// private declarations
public:
	// public declarations
	__fastcall Tfrmlogin(TComponent *Owner);
};
//----------------------------------------------------------------------------
extern Tfrmlogin *frmlogin;
//----------------------------------------------------------------------------
#endif
