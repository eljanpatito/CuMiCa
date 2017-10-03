//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("UMainMenu.cpp", frmmenuprincipal);
USEFORM("Unit2.cpp", frmlogin);
USEFORM("UProductManagement.cpp", frmgestionproductos);
USEFORM("UProduct.cpp", frmdatosproducto);
USEFORM("UCustomer.cpp", frmgestioncliente);
USEFORM("Unit6.cpp", frmventas);
USEFORM("Unit7.cpp", frmrepproducto);
USEFORM("Unit8.cpp", QRListForm);
USEFORM("Unit9.cpp", frmreportes);
USEFORM("Unit10.cpp", frmreporteventa);
USEFORM("Unit11.cpp", frmproforma);
USEFORM("Unit12.cpp", frmproformas);
USEFORM("Unit13.cpp", frmrepproforma);
USEFORM("USalesMasterDetail.cpp", frmmaestrodetalleventa);
USEFORM("URepayment.cpp", frmdevolucion);
USEFORM("UEmployee.cpp", frmempleado);
USEFORM("Unit17.cpp", frmrepdevolucion);
USEFORM("Unit18.cpp", frmrepempleados);
USEFORM("Unit19.cpp", frmrepcliente);
USEFORM("Unit20.cpp", QRMDForm);
USEFORM("Unit21.cpp", frmventaempleado);
USEFORM("DataModule.cpp", DM); /* TDataModule: File Type */
USEFORM("SegProductos.cpp", fRepSeguimiento);
USEFORM("SegProductosForm.cpp", fSeguimiento);
USEFORM("RepVentasFecha.cpp", frmrepventasfecha);
USEFORM("Configuration.cpp", frmConfiguration);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(Tfrmlogin), &frmlogin);
       Application->CreateForm(__classid(TDM), &DM);
       Application->CreateForm(__classid(Tfrmmenuprincipal), &frmmenuprincipal);
       Application->CreateForm(__classid(Tfrmgestionproductos), &frmgestionproductos);
       Application->CreateForm(__classid(Tfrmdatosproducto), &frmdatosproducto);
       Application->CreateForm(__classid(Tfrmgestioncliente), &frmgestioncliente);
       Application->CreateForm(__classid(Tfrmventas), &frmventas);
       Application->CreateForm(__classid(Tfrmrepproducto), &frmrepproducto);
       Application->CreateForm(__classid(TQRListForm), &QRListForm);
       Application->CreateForm(__classid(Tfrmreportes), &frmreportes);
       Application->CreateForm(__classid(Tfrmreporteventa), &frmreporteventa);
       Application->CreateForm(__classid(Tfrmproforma), &frmproforma);
       Application->CreateForm(__classid(Tfrmproformas), &frmproformas);
       Application->CreateForm(__classid(Tfrmrepproforma), &frmrepproforma);
       Application->CreateForm(__classid(Tfrmmaestrodetalleventa), &frmmaestrodetalleventa);
       Application->CreateForm(__classid(Tfrmdevolucion), &frmdevolucion);
       Application->CreateForm(__classid(Tfrmempleado), &frmempleado);
       Application->CreateForm(__classid(Tfrmrepdevolucion), &frmrepdevolucion);
       Application->CreateForm(__classid(Tfrmrepempleados), &frmrepempleados);
       Application->CreateForm(__classid(Tfrmrepcliente), &frmrepcliente);
       Application->CreateForm(__classid(TQRMDForm), &QRMDForm);
       Application->CreateForm(__classid(Tfrmventaempleado), &frmventaempleado);
       Application->CreateForm(__classid(TfRepSeguimiento), &fRepSeguimiento);
       Application->CreateForm(__classid(TfSeguimiento), &fSeguimiento);
       Application->CreateForm(__classid(Tfrmrepventasfecha), &frmrepventasfecha);
       Application->CreateForm(__classid(TfrmConfiguration), &frmConfiguration);
       Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        catch (...)
        {
                 try
                 {
                         throw Exception("");
                 }
                 catch (Exception &exception)
                 {
                         Application->ShowException(&exception);
                 }
        }
        return 0;
}
//---------------------------------------------------------------------------
