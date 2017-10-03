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
   TQuery *QSalesMasterDetail1;
   TIntegerField *Query1IDNOTA;
   TStringField *Query1NOMBRE_CLIENTE;
   TIntegerField *Query1TOTAL_CAJAS;
   TFloatField *Query1TOTAL_BS;
   TStringField *Query1TOTAL;
   TDateTimeField *Query1FECHA;
   TQuery *QSalesMasterDetail2;
   TStringField *Query2CODIGO;
   TStringField *Query2DESCRIPCION;
   TIntegerField *Query2CANTIDAD;
   TFloatField *Query2PRECIO;
   TFloatField *Query2PARCIAL;
   TDataSource *DSSalesMasterDetail1;
   TDataSource *DSSalesMasterDetail2;
   TDataSource *DSSalesMasterDetail3;
   TTable *TSalesMasterDetail;
   TTable *TProduct;
   TDataSource *DSProduct;
   TTable *TRepayment1;
   TDataSource *DSRepayment3;
   TTable *TRepayment2;
   TDataSource *DSRepayment4;
   TQuery *QRepayment1;
   TIntegerField *IntegerField1;
   TStringField *StringField1;
   TIntegerField *IntegerField2;
   TFloatField *FloatField1;
   TStringField *StringField2;
   TDateTimeField *DateTimeField1;
   TDataSource *DSRepayment1;
   TTable *TRepayment3;
   TDataSource *DSRepayment2;
   TDataSource *DSRepayment5;
   TQuery *QRepayment3;
   TTable *TEmployee;
   TStringField *TEmployeeCODIGO;
   TStringField *TEmployeeNOMBRE_COMPLETO;
   TStringField *TEmployeeTELEFONO;
   TDataSource *DSEmployee;
private:	// User declarations
public:		// User declarations
   __fastcall TDM(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDM *DM;
//---------------------------------------------------------------------------
#endif
