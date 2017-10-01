object DM: TDM
  OldCreateOrder = False
  Left = 196
  Top = 124
  Height = 431
  Width = 628
  object BdD: TDatabase
    AliasName = 'Cumica2017Alias'
    Connected = True
    DatabaseName = 'CuMiCaBdD'
    LoginPrompt = False
    SessionName = 'Default'
    Left = 16
    Top = 8
  end
  object DataSource1: TDataSource
    DataSet = Query1
    Left = 61
    Top = 59
  end
  object Query1: TQuery
    DatabaseName = 'CuMiCaBdD'
    SQL.Strings = (
      'Select *'
      'From USUARIO')
    Left = 16
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
    Top = 136
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
    Top = 136
  end
  object qSumCajas: TQuery
    DatabaseName = 'CuMiCaBdD'
    SQL.Strings = (
      'SELECT Sum([DETALLE_VENTA.CANTIDAD]) AS TOTAL_CAJAS'
      'FROM DETALLE_VENTA'
      'WHERE (((DETALLE_VENTA.CODIGO)=:a))'
      'GROUP BY DETALLE_VENTA.CODIGO;')
    Left = 24
    Top = 192
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
    Top = 192
  end
  object dsVentasFecha: TDataSource
    DataSet = qVentasFecha
    Left = 240
    Top = 8
  end
  object qVentasFecha: TQuery
    DatabaseName = 'CuMiCaBdD'
    SQL.Strings = (
      'SELECT VENTA.FECHA, Sum(VENTA.TOTAL_BS) AS TOTAL'
      'FROM VENTA'
      'WHERE VENTA.FECHA>=#09/11/2012# AND VENTA.FECHA<=#13/11/2015#'
      'GROUP BY VENTA.FECHA'
      'ORDER BY VENTA.FECHA DESC;')
    Left = 176
    Top = 8
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
    Left = 168
    Top = 64
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
    Left = 232
    Top = 64
  end
  object qFindProduct: TQuery
    DatabaseName = 'CuMiCaBdD'
    SQL.Strings = (
      'SELECT * FROM PRODUCTO'
      'WHERE CODIGO=:codigo')
    Left = 168
    Top = 136
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
    Left = 352
    Top = 8
  end
  object dsMainMenu: TDataSource
    DataSet = tMainMenu
    Left = 416
    Top = 8
  end
  object DSProductManagement: TDataSource
    DataSet = QProductManagement
    Left = 469
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
    Left = 352
    Top = 56
  end
  object QSalesMasterDetail1: TQuery
    DatabaseName = 'CuMiCaBdD'
    SQL.Strings = (
      'SELECT VENTA.IDNOTA, VENTA.NOMBRE_CLIENTE,'
      'VENTA.TOTAL_CAJAS, VENTA.TOTAL_BS, VENTA.FECHA, VENTA.TOTAL'
      'FROM VENTA'
      'ORDER BY VENTA.IDNOTA DESC')
    Left = 353
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
    Left = 353
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
    Left = 469
    Top = 107
  end
  object DSSalesMasterDetail2: TDataSource
    DataSet = QSalesMasterDetail2
    Left = 469
    Top = 155
  end
  object DSSalesMasterDetail3: TDataSource
    DataSet = TSalesMasterDetail
    Left = 472
    Top = 200
  end
  object TSalesMasterDetail: TTable
    DatabaseName = 'CuMiCaBdD'
    IndexFieldNames = 'ID_NOTA'
    MasterFields = 'IDNOTA'
    MasterSource = DSSalesMasterDetail1
    TableName = 'DEVOLUCION'
    Left = 352
    Top = 201
  end
  object TProduct: TTable
    DatabaseName = 'CuMiCaBdD'
    TableName = 'PRODUCTO'
    Left = 352
    Top = 256
  end
  object DSProduct: TDataSource
    DataSet = TProduct
    Left = 469
    Top = 251
  end
end
