object DM: TDM
  OldCreateOrder = False
  Left = 196
  Top = 124
  Height = 591
  Width = 1072
  object BdD: TDatabase
    AliasName = 'Cumica2017Alias'
    Connected = True
    DatabaseName = 'CuMiCaBdD'
    LoginPrompt = False
    SessionName = 'Default'
    Left = 24
    Top = 8
  end
  object DataSource1: TDataSource
    DataSet = Query1
    Left = 93
    Top = 59
  end
  object Query1: TQuery
    DatabaseName = 'CuMiCaBdD'
    SQL.Strings = (
      'Select *'
      'From USUARIO')
    Left = 24
    Top = 56
  end
  object qSeguimiento: TQuery
    DatabaseName = 'CuMiCaBdD'
    SQL.Strings = (
      
        'SELECT VENTA.NOMBRE_CLIENTE, VENTA.IDNOTA, DETALLE_VENTA.DESCRIP' +
        'CION, DETALLE_VENTA.CODIGO, VENTA.FECHA, DETALLE_VENTA.CANTIDAD'
      
        'FROM VENTA INNER JOIN DETALLE_VENTA ON VENTA.IDNOTA = DETALLE_VE' +
        'NTA.ID_NOTA'
      'WHERE (((DETALLE_VENTA.CODIGO)=:a))'
      
        'GROUP BY VENTA.NOMBRE_CLIENTE, VENTA.IDNOTA, DETALLE_VENTA.DESCR' +
        'IPCION, DETALLE_VENTA.CODIGO, VENTA.FECHA, DETALLE_VENTA.CANTIDA' +
        'D'
      'ORDER BY VENTA.NOMBRE_CLIENTE, VENTA.IDNOTA;')
    Left = 24
    Top = 104
    ParamData = <
      item
        DataType = ftString
        Name = 'a'
        ParamType = ptUnknown
        Value = '3021'
      end>
  end
  object dsSeguimiento: TDataSource
    DataSet = qSeguimiento
    Left = 96
    Top = 104
  end
  object qSumCajas: TQuery
    DatabaseName = 'CuMiCaBdD'
    SQL.Strings = (
      'SELECT Sum([DETALLE_VENTA.CANTIDAD]) AS TOTAL_CAJAS'
      'FROM DETALLE_VENTA'
      'WHERE (((DETALLE_VENTA.CODIGO)=:a))'
      'GROUP BY DETALLE_VENTA.CODIGO;')
    Left = 24
    Top = 152
    ParamData = <
      item
        DataType = ftString
        Name = 'a'
        ParamType = ptUnknown
        Value = '3021'
      end>
  end
  object dsSumCajas: TDataSource
    DataSet = qSumCajas
    Left = 96
    Top = 152
  end
  object dsVentasFecha: TDataSource
    DataSet = qVentasFecha
    Left = 96
    Top = 200
  end
  object qVentasFecha: TQuery
    DatabaseName = 'CuMiCaBdD'
    SQL.Strings = (
      'SELECT VENTA.FECHA, Sum(VENTA.TOTAL_BS) AS TOTAL'
      'FROM VENTA'
      'WHERE VENTA.FECHA>=#09/11/2012# AND VENTA.FECHA<=#13/11/2015#'
      'GROUP BY VENTA.FECHA'
      'ORDER BY VENTA.FECHA DESC;')
    Left = 24
    Top = 200
    object qVentasFechaFECHA: TDateTimeField
      FieldName = 'FECHA'
    end
    object qVentasFechaTOTAL: TFloatField
      FieldName = 'TOTAL'
      DisplayFormat = '#,##0.00'
    end
  end
  object tConfiguration: TTable
    DatabaseName = 'CuMiCaBdD'
    TableName = 'configuration'
    Left = 24
    Top = 248
    object tConfigurationproperty: TStringField
      FieldName = 'property'
      Size = 25
    end
    object tConfigurationvalue: TStringField
      FieldName = 'value'
      Size = 200
    end
  end
  object dsConfiguration: TDataSource
    DataSet = tConfiguration
    Left = 96
    Top = 248
  end
  object qFindProduct: TQuery
    DatabaseName = 'CuMiCaBdD'
    SQL.Strings = (
      'SELECT * FROM PRODUCTO'
      'WHERE CODIGO=:codigo')
    Left = 24
    Top = 296
    ParamData = <
      item
        DataType = ftString
        Name = 'codigo'
        ParamType = ptUnknown
        Value = '1010'
      end>
  end
  object tMainMenu: TTable
    Active = True
    DatabaseName = 'CuMiCaBdD'
    TableName = 'FORMULARIO'
    Left = 184
    Top = 8
  end
  object dsMainMenu: TDataSource
    DataSet = tMainMenu
    Left = 296
    Top = 8
  end
  object DSProductManagement: TDataSource
    DataSet = QProductManagement
    Left = 293
    Top = 56
  end
  object QProductManagement: TQuery
    DatabaseName = 'CuMiCaBdD'
    SQL.Strings = (
      'Select'
      ' `PRODUCTO`.`ID`, '
      '  `PRODUCTO`.`CODIGO`,'
      '  `PRODUCTO`.`DESCRIPCION`,'
      '  `PRODUCTO`.`CANTIDAD_CAJAS`,'
      '  `PRODUCTO`.`CANTIDAS_POR_CAJA`,'
      '  `PRODUCTO`.`PRECIO_DE_COMPRA`,'
      '  `PRODUCTO`.`PRECIO_UNIDAD`,'
      '  `PRODUCTO`.`PRECIO_CAJA`'
      'From `PRODUCTO`'
      'ORDER BY CODIGO')
    Left = 184
    Top = 56
  end
  object QSalesMasterDetail1: TQuery
    DatabaseName = 'CuMiCaBdD'
    SQL.Strings = (
      'SELECT *'
      'FROM VENTA'
      'ORDER BY VENTA.IDNOTA DESC')
    Left = 185
    Top = 107
    object Query1IDNOTA: TIntegerField
      FieldName = 'IDNOTA'
    end
    object Query1NOMBRE_CLIENTE: TStringField
      FieldName = 'NOMBRE_CLIENTE'
      Size = 100
    end
    object Query1TOTAL_CAJAS: TIntegerField
      FieldName = 'TOTAL_CAJAS'
    end
    object Query1TOTAL_BS: TFloatField
      FieldName = 'TOTAL_BS'
      DisplayFormat = '###,###,###.00'
      currency = True
    end
    object Query1TOTAL: TStringField
      FieldName = 'TOTAL'
      Size = 255
    end
    object Query1FECHA: TDateTimeField
      FieldName = 'FECHA'
    end
    object QSalesMasterDetail1COD_EMP: TStringField
      FieldName = 'COD_EMP'
      Origin = 'CUMICABDD.VENTA.COD_EMP'
      Size = 30
    end
    object QSalesMasterDetail1CLI_TEL: TStringField
      FieldName = 'CLI_TEL'
      Origin = 'CUMICABDD.VENTA.CLI_TEL'
      Size = 12
    end
    object QSalesMasterDetail1CLI_CEL: TStringField
      FieldName = 'CLI_CEL'
      Origin = 'CUMICABDD.VENTA.CLI_CEL'
      Size = 12
    end
    object QSalesMasterDetail1CLI_CIUDAD: TStringField
      FieldName = 'CLI_CIUDAD'
      Origin = 'CUMICABDD.VENTA.CLI_CIUDAD'
      Size = 12
    end
    object QSalesMasterDetail1CLI_NIT: TStringField
      FieldName = 'CLI_NIT'
      Origin = 'CUMICABDD.VENTA.CLI_NIT'
      Size = 30
    end
  end
  object QSalesMasterDetail2: TQuery
    DatabaseName = 'CuMiCaBdD'
    DataSource = DSSalesMasterDetail1
    SQL.Strings = (
      'Select *'
      'From `DETALLE_VENTA`'
      'Where'
      '  `DETALLE_VENTA`.`ID_NOTA` =:"IDNOTA"')
    Left = 185
    Top = 155
    ParamData = <
      item
        DataType = ftInteger
        Name = 'IDNOTA'
        ParamType = ptUnknown
        Size = 4
      end>
    object Query2CODIGO: TStringField
      FieldName = 'CODIGO'
      Size = 30
    end
    object Query2DESCRIPCION: TStringField
      FieldName = 'DESCRIPCION'
      Size = 255
    end
    object Query2CANTIDAD: TIntegerField
      FieldName = 'CANTIDAD'
    end
    object Query2PRECIO: TFloatField
      FieldName = 'PRECIO'
    end
    object Query2PARCIAL: TFloatField
      FieldName = 'PARCIAL'
    end
    object QSalesMasterDetail2Id: TIntegerField
      FieldName = 'Id'
    end
    object QSalesMasterDetail2ID_NOTA: TIntegerField
      FieldName = 'ID_NOTA'
    end
    object QSalesMasterDetail2CANTIDAD_POR_CAJA: TIntegerField
      FieldName = 'CANTIDAD_POR_CAJA'
    end
  end
  object DSSalesMasterDetail1: TDataSource
    DataSet = QSalesMasterDetail1
    Left = 293
    Top = 107
  end
  object DSSalesMasterDetail2: TDataSource
    DataSet = QSalesMasterDetail2
    Left = 293
    Top = 155
  end
  object DSSalesMasterDetail3: TDataSource
    DataSet = TSalesMasterDetail
    Left = 296
    Top = 200
  end
  object TSalesMasterDetail: TTable
    DatabaseName = 'CuMiCaBdD'
    IndexFieldNames = 'ID_NOTA'
    MasterFields = 'IDNOTA'
    MasterSource = DSSalesMasterDetail1
    TableName = 'DEVOLUCION'
    Left = 184
    Top = 201
    object TSalesMasterDetailId: TAutoIncField
      FieldName = 'Id'
    end
    object TSalesMasterDetailCODIGO_EMPLEADO: TStringField
      FieldName = 'CODIGO_EMPLEADO'
      Size = 100
    end
    object TSalesMasterDetailCODIGO_PRODUCTO: TStringField
      FieldName = 'CODIGO_PRODUCTO'
      Size = 100
    end
    object TSalesMasterDetailCANTIDAD: TIntegerField
      FieldName = 'CANTIDAD'
    end
    object TSalesMasterDetailID_NOTA: TIntegerField
      FieldName = 'ID_NOTA'
    end
  end
  object TProduct: TTable
    DatabaseName = 'CuMiCaBdD'
    TableName = 'PRODUCTO'
    Left = 184
    Top = 248
  end
  object DSProduct: TDataSource
    DataSet = TProduct
    Left = 293
    Top = 251
  end
  object TRepayment1: TTable
    AutoRefresh = True
    DatabaseName = 'CuMiCaBdD'
    Filtered = True
    TableName = 'VENTA'
    Left = 184
    Top = 296
  end
  object DSRepayment3: TDataSource
    DataSet = TRepayment1
    Left = 296
    Top = 296
  end
  object TRepayment2: TTable
    AutoRefresh = True
    DatabaseName = 'CuMiCaBdD'
    Filtered = True
    IndexFieldNames = 'ID_NOTA'
    MasterFields = 'IDNOTA'
    MasterSource = DSRepayment3
    TableName = 'DETALLE_VENTA'
    Left = 184
    Top = 344
  end
  object DSRepayment4: TDataSource
    DataSet = TRepayment2
    Left = 296
    Top = 344
  end
  object QRepayment1: TQuery
    AutoRefresh = True
    DatabaseName = 'CuMiCaBdD'
    SQL.Strings = (
      'Select'
      '  `VENTA`.`IDNOTA`,'
      '  `VENTA`.`NOMBRE_CLIENTE`,'
      '  `VENTA`.`TOTAL_CAJAS`,'
      '  `VENTA`.`TOTAL_BS`,'
      '  `VENTA`.`TOTAL`,'
      '  `VENTA`.`FECHA`'
      'From `VENTA`')
    Left = 185
    Top = 387
    object IntegerField1: TIntegerField
      FieldName = 'IDNOTA'
    end
    object StringField1: TStringField
      FieldName = 'NOMBRE_CLIENTE'
      Size = 100
    end
    object IntegerField2: TIntegerField
      FieldName = 'TOTAL_CAJAS'
    end
    object FloatField1: TFloatField
      FieldName = 'TOTAL_BS'
    end
    object StringField2: TStringField
      FieldName = 'TOTAL'
      Size = 255
    end
    object DateTimeField1: TDateTimeField
      FieldName = 'FECHA'
    end
  end
  object DSRepayment1: TDataSource
    DataSet = QRepayment1
    Left = 293
    Top = 387
  end
  object TRepayment3: TTable
    DatabaseName = 'CuMiCaBdD'
    TableName = 'DEVOLUCION'
    Left = 184
    Top = 432
  end
  object DSRepayment2: TDataSource
    DataSet = TRepayment3
    Left = 296
    Top = 432
  end
  object DSRepayment5: TDataSource
    DataSet = QRepayment3
    Left = 296
    Top = 480
  end
  object QRepayment3: TQuery
    AutoRefresh = True
    DatabaseName = 'CuMiCaBdD'
    DataSource = DSRepayment1
    SQL.Strings = (
      'Select'
      '`DETALLE_VENTA`.`ID`,  '
      '`DETALLE_VENTA`.`CODIGO`,'
      '  `DETALLE_VENTA`.`DESCRIPCION`,'
      '  `DETALLE_VENTA`.`CANTIDAD`,'
      '  `DETALLE_VENTA`.`PRECIO`,'
      '  `DETALLE_VENTA`.`PARCIAL`'
      'From `DETALLE_VENTA`'
      'Where'
      '  `DETALLE_VENTA`.`ID_NOTA` =:"IDNOTA"')
    Left = 184
    Top = 480
    ParamData = <
      item
        DataType = ftInteger
        Name = 'IDNOTA'
        ParamType = ptUnknown
        Size = 4
      end>
  end
  object TEmployee: TTable
    DatabaseName = 'CuMiCaBdD'
    TableName = 'EMPLEADO'
    Left = 401
    Top = 11
    object TEmployeeCODIGO: TStringField
      FieldName = 'CODIGO'
      Size = 30
    end
    object TEmployeeNOMBRE_COMPLETO: TStringField
      FieldName = 'NOMBRE_COMPLETO'
      Size = 100
    end
    object TEmployeeTELEFONO: TStringField
      FieldName = 'TELEFONO'
      Size = 25
    end
  end
  object DSEmployee: TDataSource
    DataSet = TEmployee
    Left = 461
    Top = 11
  end
  object QCustomer: TQuery
    DatabaseName = 'CuMiCaBdD'
    SQL.Strings = (
      'SELECT * FROM `CLIENTE`'
      'WHERE NIT LIKE :nit'
      'OR APELLIDO LIKE :lastname'
      'ORDER BY NIT')
    Left = 401
    Top = 107
    ParamData = <
      item
        DataType = ftString
        Name = 'nit'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'lastname'
        ParamType = ptUnknown
      end>
    object Query1NIT: TStringField
      FieldName = 'NIT'
      Size = 30
    end
    object Query1NOMBRE: TStringField
      FieldName = 'NOMBRE'
      Size = 50
    end
    object Query1APELLIDO: TStringField
      FieldName = 'APELLIDO'
      Size = 50
    end
    object Query1TELEFONO: TStringField
      FieldName = 'TELEFONO'
      Origin = 'CUMICAALIAS.CLIENTE.TELEFONO'
      Size = 25
    end
    object Query1CELULAR: TStringField
      FieldName = 'CELULAR'
      Origin = 'CUMICAALIAS.CLIENTE.CELULAR'
      Size = 25
    end
    object Query1DIRECCION: TStringField
      FieldName = 'DIRECCION'
      Origin = 'CUMICAALIAS.CLIENTE.DIRECCION'
      Size = 50
    end
    object Query1CIUDAD: TStringField
      FieldName = 'CIUDAD'
      Origin = 'CUMICAALIAS.CLIENTE.CIUDAD'
      Size = 15
    end
  end
  object DSCustomer1: TDataSource
    DataSet = QCustomer
    Left = 461
    Top = 107
  end
  object TCustomer: TTable
    DatabaseName = 'CuMiCaBdD'
    TableName = 'CLIENTE'
    Left = 400
    Top = 56
    object TCustomerNIT: TStringField
      FieldName = 'NIT'
      Size = 30
    end
    object TCustomerNOMBRE: TStringField
      FieldName = 'NOMBRE'
      Size = 50
    end
    object TCustomerAPELLIDO: TStringField
      FieldName = 'APELLIDO'
      Size = 50
    end
    object TCustomerTELEFONO: TStringField
      FieldName = 'TELEFONO'
      Size = 25
    end
    object TCustomerCELULAR: TStringField
      FieldName = 'CELULAR'
      Size = 25
    end
    object TCustomerDIRECCION: TStringField
      FieldName = 'DIRECCION'
      Size = 50
    end
    object TCustomerCIUDAD: TStringField
      FieldName = 'CIUDAD'
      Size = 15
    end
  end
  object DSCustomer2: TDataSource
    DataSet = TCustomer
    Left = 464
    Top = 56
  end
  object QProforma1: TQuery
    DatabaseName = 'CuMiCaBdD'
    SQL.Strings = (
      'SELECT DETALLE_VENTA.*, producto.*'
      
        'FROM  PRODUCTO INNER JOIN DETALLE_VENTA ON PRODUCTO.CODIGO = DET' +
        'ALLE_VENTA.CODIGO'
      'WHERE (((DETALLE_VENTA.ID_NOTA)=148));')
    Left = 400
    Top = 160
    object QProforma1Id: TIntegerField
      FieldName = 'Id'
      Origin = 'CUMICAALIAS.PRODUCTO.Id'
    end
    object QProforma1CODIGO: TStringField
      FieldName = 'CODIGO'
      Origin = 'CUMICAALIAS.PRODUCTO.CODIGO'
      Size = 30
    end
    object QProforma1DESCRIPCION: TStringField
      FieldName = 'DESCRIPCION'
      Origin = 'CUMICAALIAS.PRODUCTO.DESCRIPCION'
      Size = 255
    end
    object QProforma1CANTIDAD: TIntegerField
      FieldName = 'CANTIDAD'
      Origin = 'CUMICAALIAS.PRODUCTO.CANTIDAD_CAJAS'
    end
    object QProforma1PRECIO: TFloatField
      FieldName = 'PRECIO'
      Origin = 'CUMICAALIAS.PRODUCTO.CANTIDAS_POR_CAJA'
    end
    object QProforma1PARCIAL: TFloatField
      FieldName = 'PARCIAL'
      Origin = 'CUMICAALIAS.PRODUCTO.PRECIO_DE_COMPRA'
    end
    object QProforma1ID_NOTA: TIntegerField
      FieldName = 'ID_NOTA'
      Origin = 'CUMICAALIAS.PRODUCTO.PRECIO_UNIDAD'
    end
    object QProforma1CANTIDAS_POR_CAJA: TSmallintField
      FieldName = 'CANTIDAD_POR_CAJA'
      Origin = 'CUMICAALIAS.DETALLE_VENTA.CANTIDAD'
    end
  end
  object TProforma: TTable
    DatabaseName = 'CuMiCaBdD'
    TableName = 'VENTA'
    Left = 400
    Top = 256
    object TProformaIDNOTA: TIntegerField
      FieldName = 'IDNOTA'
    end
    object TProformaNOMBRE_CLIENTE: TStringField
      FieldName = 'NOMBRE_CLIENTE'
      Size = 100
    end
    object TProformaTOTAL_CAJAS: TIntegerField
      FieldName = 'TOTAL_CAJAS'
    end
    object TProformaTOTAL_BS: TFloatField
      FieldName = 'TOTAL_BS'
    end
    object TProformaTOTAL: TStringField
      FieldName = 'TOTAL'
      Size = 255
    end
    object TProformaFECHA: TDateTimeField
      FieldName = 'FECHA'
    end
    object TProformaCOD_EMP: TStringField
      FieldName = 'COD_EMP'
      Size = 30
    end
  end
  object DSProforma1: TDataSource
    DataSet = QProforma1
    Left = 464
    Top = 160
  end
  object DSProforma2: TDataSource
    DataSet = TProforma
    Left = 464
    Top = 208
  end
  object QProforma2: TQuery
    DatabaseName = 'CuMiCaBdD'
    SQL.Strings = (
      'SELECT * FROM VENTA'
      'WHERE IDNOTA = 140')
    Left = 400
    Top = 208
  end
  object MasterDS: TDataSource
    DataSet = MasterTable
    Left = 460
    Top = 308
  end
  object MasterTable: TTable
    DatabaseName = 'CuMiCaBdD'
    TableName = 'VENTA'
    Left = 400
    Top = 308
  end
  object DetailTable: TTable
    DatabaseName = 'CuMiCaBdD'
    IndexFieldNames = 'ID_NOTA'
    MasterFields = 'IDNOTA'
    MasterSource = MasterDS
    TableName = 'DETALLE_VENTA'
    Left = 404
    Top = 356
  end
  object TCustomerList: TTable
    DatabaseName = 'CuMiCaBdD'
    TableName = 'CLIENTE'
    Left = 400
    Top = 400
  end
  object QRepaymentList: TQuery
    DatabaseName = 'CuMiCaBdD'
    SQL.Strings = (
      'select * from devolucion')
    Left = 400
    Top = 440
  end
  object TEmployeeList: TTable
    DatabaseName = 'CuMiCaBdD'
    TableName = 'EMPLEADO'
    Left = 400
    Top = 488
  end
  object QDaySales1: TQuery
    DatabaseName = 'CuMiCaBdD'
    SQL.Strings = (
      'select * from venta')
    Left = 536
    Top = 8
  end
  object QDaySales2: TQuery
    DatabaseName = 'CuMiCaBdD'
    SQL.Strings = (
      'select sum(total_bs) from venta')
    Left = 536
    Top = 56
  end
  object QProductList: TQuery
    DatabaseName = 'CuMiCaBdD'
    SQL.Strings = (
      'select * from producto order by codigo')
    Left = 536
    Top = 104
  end
  object TProformas: TTable
    DatabaseName = 'CuMiCaBdD'
    IndexFieldNames = 'ID_NOTA'
    MasterFields = 'IDNOTA'
    MasterSource = DSQProformas
    TableName = 'DETALLE_VENTA'
    Left = 532
    Top = 204
  end
  object DSQProformas: TDataSource
    DataSet = QProformas
    Left = 612
    Top = 156
  end
  object QProformas: TQuery
    DatabaseName = 'CuMiCaBdD'
    SQL.Strings = (
      'select * from venta')
    Left = 536
    Top = 152
  end
  object TSalesByEmployee: TTable
    DatabaseName = 'CuMiCaBdD'
    TableName = 'AUX'
    Left = 536
    Top = 256
  end
  object DSSalesByEmployee2: TDataSource
    DataSet = TSalesByEmployee
    Left = 616
    Top = 256
  end
  object QSalesByEmployee2: TQuery
    DatabaseName = 'CuMiCaBdD'
    Left = 536
    Top = 304
  end
  object QSalesByEmployee1: TQuery
    DatabaseName = 'CuMiCaBdD'
    SQL.Strings = (
      'select *'
      'from v_e'
      'ORDER BY NOMBRE_COMPLETO;')
    Left = 537
    Top = 352
  end
  object DSSalesByEmployee1: TDataSource
    DataSet = QSalesByEmployee1
    Left = 616
    Top = 352
  end
  object TSales1: TTable
    DatabaseName = 'CuMiCaBdD'
    TableName = 'VENTA'
    Left = 536
    Top = 400
    object TSales1IDNOTA: TIntegerField
      FieldName = 'IDNOTA'
      DisplayFormat = '00000000'
    end
    object TSales1NOMBRE_CLIENTE: TStringField
      FieldName = 'NOMBRE_CLIENTE'
      Size = 100
    end
    object TSales1TOTAL_CAJAS: TIntegerField
      FieldName = 'TOTAL_CAJAS'
    end
    object TSales1TOTAL_BS: TFloatField
      FieldName = 'TOTAL_BS'
      DisplayFormat = '0.00'
      EditFormat = '###,###,###.00'
    end
    object TSales1TOTAL: TStringField
      FieldName = 'TOTAL'
      Size = 255
    end
    object TSales1FECHA: TDateTimeField
      FieldName = 'FECHA'
    end
    object TSales1COD_EMP: TStringField
      FieldName = 'COD_EMP'
      Size = 30
    end
    object TSales1CLI_TEL: TStringField
      FieldName = 'CLI_TEL'
      Size = 12
    end
    object TSales1CLI_CEL: TStringField
      FieldName = 'CLI_CEL'
      Size = 12
    end
    object TSales1CLI_CIUDAD: TStringField
      FieldName = 'CLI_CIUDAD'
      Size = 12
    end
    object TSales1CLI_NIT: TStringField
      FieldName = 'CLI_NIT'
      Size = 30
    end
  end
  object DSSales1: TDataSource
    DataSet = TSales1
    Left = 621
    Top = 403
  end
  object TSales2: TTable
    DatabaseName = 'CuMiCaBdD'
    IndexFieldNames = 'ID_NOTA'
    MasterFields = 'IDNOTA'
    MasterSource = DSSales1
    TableName = 'DETALLE_VENTA'
    Left = 536
    Top = 448
  end
  object DSSales2: TDataSource
    DataSet = TSales2
    Left = 616
    Top = 448
  end
  object QSales1: TQuery
    DatabaseName = 'CuMiCaBdD'
    SQL.Strings = (
      'select maX(IDNOTA)+1 AS MAY FROM VENTA')
    Left = 728
    Top = 8
  end
  object TSales3: TTable
    DatabaseName = 'CuMiCaBdD'
    TableName = 'VENTA'
    Left = 536
    Top = 496
    object TSales3IDNOTA: TIntegerField
      FieldName = 'IDNOTA'
    end
    object TSales3NOMBRE_CLIENTE: TStringField
      FieldName = 'NOMBRE_CLIENTE'
      Size = 100
    end
    object TSales3TOTAL_CAJAS: TIntegerField
      FieldName = 'TOTAL_CAJAS'
    end
    object TSales3TOTAL_BS: TFloatField
      FieldName = 'TOTAL_BS'
    end
    object TSales3TOTAL: TStringField
      FieldName = 'TOTAL'
      Size = 255
    end
    object TSales3FECHA: TDateTimeField
      FieldName = 'FECHA'
    end
    object TSales3COD_EMP: TStringField
      FieldName = 'COD_EMP'
      Size = 30
    end
    object TSales3CLI_TEL: TStringField
      FieldName = 'CLI_TEL'
      Size = 12
    end
    object TSales3CLI_CEL: TStringField
      FieldName = 'CLI_CEL'
      Size = 12
    end
    object TSales3CLI_CIUDAD: TStringField
      FieldName = 'CLI_CIUDAD'
      Size = 12
    end
    object TSales3CLI_NIT: TStringField
      FieldName = 'CLI_NIT'
      Size = 30
    end
  end
  object DSSales3: TDataSource
    DataSet = TSales3
    Left = 616
    Top = 496
  end
  object QCustomerFind: TQuery
    DatabaseName = 'CuMiCaBdD'
    SQL.Strings = (
      'SELECT * FROM `CLIENTE`'
      'WHERE NIT = :nit')
    Left = 728
    Top = 56
    ParamData = <
      item
        DataType = ftString
        Name = 'nit'
        ParamType = ptUnknown
      end>
  end
  object TOrderLine: TTable
    DatabaseName = 'CuMiCaBdD'
    TableName = 'ORDER_LINE'
    Left = 728
    Top = 112
    object TOrderLineId: TAutoIncField
      FieldName = 'Id'
    end
    object TOrderLineCODIGO: TStringField
      FieldName = 'CODIGO'
      Size = 30
    end
    object TOrderLineDESCRIPCION: TStringField
      FieldName = 'DESCRIPCION'
      Size = 255
    end
    object TOrderLineCANTIDAD: TIntegerField
      FieldName = 'CANTIDAD'
    end
    object TOrderLinePRECIO: TFloatField
      FieldName = 'PRECIO'
    end
    object TOrderLinePARCIAL: TFloatField
      FieldName = 'PARCIAL'
    end
    object TOrderLineID_NOTA: TIntegerField
      FieldName = 'ID_NOTA'
    end
    object TOrderLineCANTIDAD_POR_CAJA: TIntegerField
      FieldName = 'CANTIDAD_POR_CAJA'
    end
  end
  object TOrder: TTable
    DatabaseName = 'CuMiCaBdD'
    TableName = 'ORDER'
    Left = 728
    Top = 160
    object TOrderIDNOTA: TIntegerField
      FieldName = 'IDNOTA'
    end
    object TOrderNOMBRE_CLIENTE: TStringField
      FieldName = 'NOMBRE_CLIENTE'
      Size = 100
    end
    object TOrderTOTAL_CAJAS: TIntegerField
      FieldName = 'TOTAL_CAJAS'
    end
    object TOrderTOTAL_BS: TFloatField
      FieldName = 'TOTAL_BS'
    end
    object TOrderTOTAL: TStringField
      FieldName = 'TOTAL'
      Size = 255
    end
    object TOrderFECHA: TDateTimeField
      FieldName = 'FECHA'
    end
    object TOrderCOD_EMP: TStringField
      FieldName = 'COD_EMP'
      Size = 30
    end
    object TOrderCLI_TEL: TStringField
      FieldName = 'CLI_TEL'
      Size = 12
    end
    object TOrderCLI_CEL: TStringField
      FieldName = 'CLI_CEL'
      Size = 12
    end
    object TOrderCLI_CIUDAD: TStringField
      FieldName = 'CLI_CIUDAD'
      Size = 12
    end
    object TOrderCLI_NIT: TStringField
      FieldName = 'CLI_NIT'
      Size = 30
    end
  end
end
