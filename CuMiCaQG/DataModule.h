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
   TQuery *QCustomer;
   TStringField *Query1NIT;
   TStringField *Query1NOMBRE;
   TStringField *Query1APELLIDO;
   TStringField *Query1TELEFONO;
   TStringField *Query1CELULAR;
   TStringField *Query1DIRECCION;
   TStringField *Query1CIUDAD;
   TDataSource *DSCustomer1;
   TTable *TCustomer;
   TStringField *TCustomerNIT;
   TStringField *TCustomerNOMBRE;
   TStringField *TCustomerAPELLIDO;
   TStringField *TCustomerTELEFONO;
   TStringField *TCustomerCELULAR;
   TStringField *TCustomerDIRECCION;
   TStringField *TCustomerCIUDAD;
   TDataSource *DSCustomer2;
   TQuery *QProforma1;
   TIntegerField *QProforma1Id;
   TStringField *QProforma1CODIGO;
   TStringField *QProforma1DESCRIPCION;
   TIntegerField *QProforma1CANTIDAD;
   TFloatField *QProforma1PRECIO;
   TFloatField *QProforma1PARCIAL;
   TIntegerField *QProforma1ID_NOTA;
   TSmallintField *QProforma1CANTIDAS_POR_CAJA;
   TTable *TProforma;
   TIntegerField *TProformaIDNOTA;
   TStringField *TProformaNOMBRE_CLIENTE;
   TIntegerField *TProformaTOTAL_CAJAS;
   TFloatField *TProformaTOTAL_BS;
   TStringField *TProformaTOTAL;
   TDateTimeField *TProformaFECHA;
   TStringField *TProformaCOD_EMP;
   TDataSource *DSProforma1;
   TDataSource *DSProforma2;
   TQuery *QProforma2;
   TDataSource *MasterDS;
   TTable *MasterTable;
   TTable *DetailTable;
   TTable *TCustomerList;
   TQuery *QRepaymentList;
   TTable *TEmployeeList;
   TQuery *QDaySales1;
   TQuery *QDaySales2;
   TQuery *QProductList;
   TTable *TProformas;
   TDataSource *DSQProformas;
   TQuery *QProformas;
   TTable *TSalesByEmployee;
   TDataSource *DSSalesByEmployee2;
   TQuery *QSalesByEmployee2;
   TQuery *QSalesByEmployee1;
   TDataSource *DSSalesByEmployee1;
   TTable *TSales1;
   TIntegerField *TSales1IDNOTA;
   TStringField *TSales1NOMBRE_CLIENTE;
   TIntegerField *TSales1TOTAL_CAJAS;
   TFloatField *TSales1TOTAL_BS;
   TStringField *TSales1TOTAL;
   TDateTimeField *TSales1FECHA;
   TStringField *TSales1COD_EMP;
   TStringField *TSales1CLI_TEL;
   TStringField *TSales1CLI_CEL;
   TStringField *TSales1CLI_CIUDAD;
   TStringField *TSales1CLI_NIT;
   TDataSource *DSSales1;
   TTable *TSales2;
   TDataSource *DSSales2;
   TQuery *QSales1;
   TTable *TSales3;
   TDataSource *DSSales3;
private:	// User declarations
public:		// User declarations
   __fastcall TDM(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDM *DM;
//---------------------------------------------------------------------------
#endif
