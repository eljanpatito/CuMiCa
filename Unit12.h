//----------------------------------------------------------------------------
#ifndef Unit12H
#define Unit12H
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
class Tfrmproformas : public TForm
{
__published:
        TQuickRep *QuickRep1;
	TTable *MasterTable; 
	TQRBand *DetailBand1;
	TQRBand *PageFooterBand1;
	TQRBand *TitleBand1;
	TQRBand * ColumnHeaderBand1;
	TQRSysData *QRSysData2;
	TTable *DetailTable;
	TQRSubDetail *QRSubDetail1;  
	TDataSource *MasterDS;
        TQRDBText *QRDBText1;
        TQRDBText *QRDBText2;
        TQRLabel *QRLabel1;
        TQRLabel *QRLabel2;
   TQRLabel *QRLabel3;
   TQRLabel *QRLabel4;
private:
public:
	virtual __fastcall Tfrmproformas(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE Tfrmproformas *frmproformas;
//----------------------------------------------------------------------------
#endif    
