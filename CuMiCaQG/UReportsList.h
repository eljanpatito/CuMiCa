//---------------------------------------------------------------------------

#ifndef UReportsListH
#define UReportsListH
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
        TLabel *Label7;
        TImage *Image1;
        TButton *btnsalir;
   TColorDialog *ColorDialog1;
   TButton *btncolor;
   TGroupBox *GroupBox1;
   TButton *btnimprimir;
   TButton *btnempleados;
   TButton *btnclientes;
   TGroupBox *GroupBox2;
   TButton *Button1;
   TButton *btnproformas;
   TButton *btnventaemp;
   TButton *Button2;
   TButton *Button3;
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
   void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tfrmreportes(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tfrmreportes *frmreportes;
//---------------------------------------------------------------------------
#endif
