//----------------------------------------------------------------------------
#ifndef Unit8H
#define Unit8H
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
class TQRListForm : public TForm
{
__published:
private:
public:
	virtual __fastcall TQRListForm(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE TQRListForm *QRListForm;
//----------------------------------------------------------------------------
#endif    
