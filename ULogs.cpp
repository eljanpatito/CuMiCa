//---------------------------------------------------------------------------

#include <vcl.h>
#include <IniFiles.hpp>
#pragma hdrstop

#include "ULogs.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFRMLogs *FRMLogs;
TMemo *myMemo;
int fileNumber;
AnsiString appName = "CuMiCa";
//---------------------------------------------------------------------------
__fastcall TFRMLogs::TFRMLogs(TComponent* Owner)
   : TForm(Owner)
{
}
//---------------------------------------------------------------------------
AnsiString __fastcall TFRMLogs::generateLogFileName(int fileNumber) {
   return EFileName->Text
   + FormatFloat(ECounterFormat->Text, fileNumber)
   + "." + EExtension->Text;
}
//---------------------------------------------------------------------------
void __fastcall TFRMLogs::myEvent(TObject *Sender) {
   if (EStartCounter->Text.Trim().IsEmpty()) {
      EStartCounter->Text = 1;
   }
   LSampleFileName->Caption = generateLogFileName(EStartCounter->Text.ToInt());
}
//---------------------------------------------------------------------------
void __fastcall TFRMLogs::EStartCounterKeyPress(TObject *Sender, char &Key)
{
   if (((Key < '0') || (Key > '9')) && ((WORD)Key != 8)) {
      Key = 0;
   }
}
//---------------------------------------------------------------------------
void __fastcall TFRMLogs::FormCreate(TObject *Sender)
{
/*   TIniFile *StartUp = new TIniFile(appName + "Logs.ini");

   EFileName->Text = StartUp->ReadString("Configuration", "FileName", "Log");
   EExtension->Text = StartUp->ReadString("Configuration", "FileExtension", "txt");
   EStartCounter->Text = StartUp->ReadInteger("Configuration", "StartAt", 1);
   ECounterFormat->Text = StartUp->ReadString("Configuration", "Format", "000");
   EMaxLines->Text = StartUp->ReadInteger("Configuration", "MaxLines", 500);

   delete StartUp;

   // Starting memo component
   myMemo = new TMemo(this);
   myMemo->Parent = this;
   myMemo->Height = 89;
   myMemo->Left = 272;
   myMemo->Top = 98;
   myMemo->Visible = true;
   myMemo->Width = 1024;

   fileNumber = EStartCounter->Text.ToInt();
   AnsiString fileName = generateLogFileName(fileNumber);
   if (!FileExists(fileName)) {
      myMemo->Lines->Clear();
      myMemo->Lines->SaveToFile(fileName);
   }
   myMemo->Lines->LoadFromFile(generateLogFileName(fileNumber));
   while (myMemo->Lines->Count >= EMaxLines->Text.ToInt()) {
      fileName = generateLogFileName(++fileNumber);
      if (!FileExists(fileName)) {
         myMemo->Lines->Clear();
         myMemo->Lines->SaveToFile(fileName);
      }
      myMemo->Lines->LoadFromFile(fileName);
   }
   //logMessage("App was open");*/
}
//---------------------------------------------------------------------------
void __fastcall TFRMLogs::BitBtn1Click(TObject *Sender)
{
   TIniFile *StartUp = new TIniFile("Logs.ini");

   StartUp->WriteString("Configuration", "FileName", EFileName->Text);
   StartUp->WriteString("Configuration", "FileExtension", EExtension->Text);
   StartUp->WriteInteger("Configuration", "StartAt", EStartCounter->Text.ToInt());
   StartUp->WriteString("Configuration", "Format", ECounterFormat->Text);
   StartUp->WriteInteger("Configuration", "MaxLines", EMaxLines->Text.ToInt());

   delete StartUp;
}
//---------------------------------------------------------------------------
void __fastcall TFRMLogs::Button1Click(TObject *Sender)
{
   int line = (int)(rand() % Memo1->Lines->Count);
//   ShowMessage("Random Line: " + IntToStr(line) + "\nTotal Lines: " + Memo1->Lines->Count);
   logMessage(Memo1->Lines->Strings[line]);
}
//---------------------------------------------------------------------------
void __fastcall TFRMLogs::logMessage(AnsiString message) {
//   ShowMessage("Log: " + message);
//   saveMessages();
//   myMemo->Lines->Insert(0, createMessage(message));
//   saveMessages();
}
//---------------------------------------------------------------------------
void __fastcall TFRMLogs::saveMessages() {
   if (myMemo->Lines->Count >= EMaxLines->Text.ToInt()) {
      AnsiString fileName = generateLogFileName(fileNumber++);
      myMemo->Lines->SaveToFile(fileName);
      fileName = generateLogFileName(fileNumber);
      if (!FileExists(fileName)) {
         myMemo->Lines->Clear();
         myMemo->Lines->SaveToFile(fileName);
      }
      myMemo->Lines->LoadFromFile(fileName);
   } else {
      myMemo->Lines->SaveToFile(generateLogFileName(fileNumber));
   }
}
//---------------------------------------------------------------------------
AnsiString __fastcall TFRMLogs::createMessage(AnsiString message) {
   TDateTime now = Now();
   return ("[" + ExtractFileName(Application->ExeName) + "] - "
   + now.FormatString(L"YYYY-MM-DD HH:mm:ss")
   + " - " + message);
}
//---------------------------------------------------------------------------
