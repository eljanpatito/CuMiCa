//---------------------------------------------------------------------------

#ifndef DataModuleH
#define DataModuleH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <DBTables.hpp>
//---------------------------------------------------------------------------
class TDM : public TDataModule
{
__published:	// IDE-managed Components
   TDatabase *BdD;
   TDataSource *DataSource1;
   TQuery *Query1;
   TQuery *qSeguimiento;
   TDataSource *dsSeguimiento;
   TQuery *qSumCajas;
   TDataSource *dsSumCajas;
   TDataSource *dsVentasFecha;
   TQuery *qVentasFecha;
   TDateTimeField *qVentasFechaFECHA;
   TFloatField *qVentasFechaTOTAL;
   TTable *tConfiguration;
   TDataSource *dsConfiguration;
   TStringField *tConfigurationproperty;
   TStringField *tConfigurationvalue;
   TQuery *qFindProduct;
   TTable *tMainMenu;
   TDataSource *dsMainMenu;
   TDataSource *DSProductManagement;
   TQuery *QProductManagement;
private:	// User declarations
public:		// User declarations
   __fastcall TDM(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDM *DM;
//---------------------------------------------------------------------------
#endif
