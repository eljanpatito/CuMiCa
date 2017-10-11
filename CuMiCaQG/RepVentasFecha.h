//---------------------------------------------------------------------------

#ifndef RepVentasFechaH
#define RepVentasFechaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <Grids.hpp>
#include <DBGrids.hpp>
#include <Chart.hpp>
#include <DbChart.hpp>
#include <ExtCtrls.hpp>
#include <Series.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
//---------------------------------------------------------------------------
class Tfrmrepventasfecha : public TForm
{
__published:	// IDE-managed Components
   TDateTimePicker *dtpFrom;
   TLabel *Label1;
   TDateTimePicker *dtpTo;
   TLabel *Label2;
   TBitBtn *BitBtn1;
   TDBGrid *DBGrid1;
   TDBChart *DBChart1;
   TBarSeries *Series1;
   void __fastcall BitBtn1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
   __fastcall Tfrmrepventasfecha(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tfrmrepventasfecha *frmrepventasfecha;
//---------------------------------------------------------------------------
#endif
