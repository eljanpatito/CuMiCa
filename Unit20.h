//----------------------------------------------------------------------------
#ifndef Unit20H
#define Unit20H
//----------------------------------------------------------------------------
#include <vcl\ExtCtrls.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Quickrpt.hpp>
#include <vcl\Dialogs.hpp>
#include <vcl\Forms.hpp>
#include <vcl\Controls.hpp>
#include <vcl\Graphics.hpp>
#include <vcl\Classes.hpp>
#include <vcl\SysUtils.hpp>
#include <vcl\Messages.hpp>
#include <vcl\Windows.hpp>
#include <vcl\System.hpp>
#include <DB.hpp>
#include <DBTables.hpp>
#include <QRCtrls.hpp>
#include <QuickRpt.hpp>
//----------------------------------------------------------------------------
class TQRMDForm : public TForm
{
__published:
        TQuickRep *QuickRep1; 
	TQRBand *DetailBand1;
	TQRBand *TitleBand1;
	TQRSysData *QRSysData1;
	TTable *DetailTable;  
	TDataSource *MasterDS;
        TQRLabel *QRLabel8;
        TQuery *Query1;
        TQuery *Query2;
        TQRExpr *QRExpr1;
private:
public:
	virtual __fastcall TQRMDForm(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE TQRMDForm *QRMDForm;
//----------------------------------------------------------------------------
#endif    
