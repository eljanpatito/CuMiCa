object DM: TDM
  OldCreateOrder = False
  Left = 252
  Top = 304
  Height = 431
  Width = 512
  object BdD: TDatabase
    AliasName = 'Cumica2016Alias'
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
    Left = 368
    Top = 16
  end
  object qVentasFecha: TQuery
    DatabaseName = 'CuMiCaBdD'
    SQL.Strings = (
      'SELECT VENTA.FECHA, Sum(VENTA.TOTAL_BS) AS TOTAL'
      'FROM VENTA'
      'WHERE VENTA.FECHA>=#09/11/2012# AND VENTA.FECHA<=#13/11/2015#'
      'GROUP BY VENTA.FECHA'
      'ORDER BY VENTA.FECHA DESC;')
    Left = 304
    Top = 16
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
    Left = 296
    Top = 72
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
    Left = 360
    Top = 72
  end
end
