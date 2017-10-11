//---------------------------------------------------------------------------

#ifndef SegProductosFormH
#define SegProductosFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TfSeguimiento : public TForm
{
__published:	// IDE-managed Components
   TDBGrid *DBGrid1;
   TLabel *Label1;
   TEdit *Edit1;
   TLabel *Label2;
   TLabel *Label3;
   TDBText *DBText1;
   TDBText *DBText2;
   TBitBtn *BitBtn1;
   TLabel *Label4;
   TDBText *DBText3;
   void __fastcall BitBtn1Click(TObject *Sender);
   void __fastcall Edit1Change(TObject *Sender);
private:	// User declarations
public:		// User declarations
   __fastcall TfSeguimiento(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfSeguimiento *fSeguimiento;
//---------------------------------------------------------------------------
#endif
