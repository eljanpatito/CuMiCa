//---------------------------------------------------------------------------

#ifndef UMainMenuH
#define UMainMenuH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <DB.hpp>
#include <DBCtrls.hpp>
#include <DBTables.hpp>
#include <Mask.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class Tfrmmenuprincipal : public TForm
{
__published:	// IDE-managed Components
        TButton *btncerrar;
        TButton *btnproductos;
        TButton *btncliente;
   TButton *btnempleado;
        TLabel *Label1;
        TImage *Image1;
        TImage *Image2;
        TImage *Image3;
        TImage *Image4;
        TButton *btnvender;
        TButton *btnreportes;
        TImage *Image5;
   TDBEdit *DBEdit1;
   TDBEdit *DBEdit2;
   TPopupMenu *PopupMenu1;
   TMenuItem *Configuration1;
        void __fastcall btncerrarClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall btnproductosClick(TObject *Sender);
        void __fastcall btnclienteClick(TObject *Sender);
        void __fastcall btnvenderClick(TObject *Sender);
        void __fastcall btnreportesClick(TObject *Sender);
   void __fastcall btnempleadoClick(TObject *Sender);
   void __fastcall Configuration1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tfrmmenuprincipal(TComponent* Owner);
        void Tfrmmenuprincipal::color_ventana(AnsiString formulario, int color);
        int Tfrmmenuprincipal::cargar_color_ventana(AnsiString formulario);
};
//---------------------------------------------------------------------------
extern PACKAGE Tfrmmenuprincipal *frmmenuprincipal;
//---------------------------------------------------------------------------
#endif
