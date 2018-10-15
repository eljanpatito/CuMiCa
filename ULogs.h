//---------------------------------------------------------------------------

#ifndef ULogsH
#define ULogsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TFRMLogs : public TForm
{
__published:	// IDE-managed Components
   TGroupBox *GroupBox1;
   TLabel *Label1;
   TEdit *EFileName;
   TLabel *Label2;
   TEdit *EStartCounter;
   TLabel *Label3;
   TEdit *ECounterFormat;
   TLabel *Label4;
   TLabel *LSampleFileName;
   TLabel *Label5;
   TEdit *EMaxLines;
   TBitBtn *BitBtn1;
   TButton *Button1;
   TMemo *Memo1;
   TLabel *Label6;
   TEdit *EExtension;
   void __fastcall myEvent(TObject *Sender);
   void __fastcall EStartCounterKeyPress(TObject *Sender, char &Key);
   void __fastcall FormCreate(TObject *Sender);
   void __fastcall BitBtn1Click(TObject *Sender);
   AnsiString __fastcall generateLogFileName(int fileNumber);
   void __fastcall Button1Click(TObject *Sender);
   AnsiString __fastcall createMessage(AnsiString message);
   void __fastcall saveMessages();
private:	// User declarations
public:		// User declarations
   __fastcall TFRMLogs(TComponent* Owner);
   void __fastcall logMessage(AnsiString message);
};
//---------------------------------------------------------------------------
extern PACKAGE TFRMLogs *FRMLogs;
//---------------------------------------------------------------------------
#endif
