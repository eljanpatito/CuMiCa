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
      'SELECT VENTA.IDNOTA, VENTA.NOMBRE_CLIENTE,'
      'VENTA.TOTAL_CAJAS, VENTA.TOTAL_BS, VENTA.FECHA, VENTA.TOTAL'
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
      DisplayFormat = '#.00'
    end
    object Query1TOTAL: TStringField
      FieldName = 'TOTAL'
      Size = 255
    end
    object Query1FECHA: TDateTimeField
      FieldName = 'FECHA'
    end
  end
  object QSalesMasterDetail2: TQuery
    DatabaseName = 'CuMiCaBdD'
    DataSource = DSSalesMasterDetail1
    SQL.Strings = (
      'Select'
      '  `DETALLE_VENTA`.`CODIGO`,'
      '  `DETALLE_VENTA`.`DESCRIPCION`,'
      '  `DETALLE_VENTA`.`CANTIDAD`,'
      '  `DETALLE_VENTA`.`PRECIO`,'
      '  `DETALLE_VENTA`.`PARCIAL`'
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
end
