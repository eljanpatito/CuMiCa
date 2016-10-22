//---------------------------------------------------------------------------

#ifndef ConfigurationH
#define ConfigurationH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <Mask.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TfrmConfiguration : public TForm
{
__published:	// IDE-managed Components
   TDBGrid *DBGrid1;
   TDBNavigator *DBNavigator1;
   TLabel *Label1;
   TDBEdit *dbeProperty;
   TLabel *Label2;
   TDBEdit *dbeValue;
   TLabel *lFont;
   TFontDialog *fdFont;
   TPopupMenu *PopupMenu1;
   TMenuItem *Font1;
   TMenuItem *Copiaralvalor1;
   TEdit *eFont;
   void __fastcall Font1Click(TObject *Sender);
   void __fastcall Copiaralvalor1Click(TObject *Sender);
   void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
   __fastcall TfrmConfiguration(TComponent* Owner);
   void TfrmConfiguration::loadDefaultConfiguration();
   AnsiString TfrmConfiguration::getValueFromProperty(AnsiString property);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmConfiguration *frmConfiguration;
//---------------------------------------------------------------------------
#endif
