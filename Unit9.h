//---------------------------------------------------------------------------

#ifndef Unit9H
#define Unit9H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class Tfrmreportes : public TForm
{
__published:	// IDE-managed Components
        TButton *btnimprimir;
        TLabel *Label7;
        TButton *Button1;
        TImage *Image1;
        TButton *btnsalir;
        TButton *btnproformas;
   TColorDialog *ColorDialog1;
   TButton *btncolor;
        TButton *btnempleados;
        TButton *btnclientes;
        TButton *btnventaemp;
   TButton *Button2;
        void __fastcall btnimprimirClick(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall btnsalirClick(TObject *Sender);
        void __fastcall btnproformasClick(TObject *Sender);
   void __fastcall btncolorClick(TObject *Sender);
   void __fastcall FormCreate(TObject *Sender);
        void __fastcall btnempleadosClick(TObject *Sender);
        void __fastcall btnclientesClick(TObject *Sender);
        void __fastcall btnventaempClick(TObject *Sender);
   void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tfrmreportes(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tfrmreportes *frmreportes;
//---------------------------------------------------------------------------
#endif
