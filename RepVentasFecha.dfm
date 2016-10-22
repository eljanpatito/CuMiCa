object frmrepventasfecha: Tfrmrepventasfecha
  Left = 299
  Top = 121
  Width = 955
  Height = 516
  Caption = 'Reporte de ventas por fecha'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 8
    Width = 31
    Height = 13
    Caption = 'Desde'
  end
  object Label2: TLabel
    Left = 176
    Top = 8
    Width = 28
    Height = 13
    Caption = 'Hasta'
  end
  object dtpFrom: TDateTimePicker
    Left = 48
    Top = 8
    Width = 121
    Height = 21
    CalAlignment = dtaLeft
    Date = 42301.5787774769
    Format = 'ddMMMMyyyy'
    Time = 42301.5787774769
    DateFormat = dfShort
    DateMode = dmComboBox
    Kind = dtkDate
    ParseInput = False
    TabOrder = 0
  end
  object dtpTo: TDateTimePicker
    Left = 216
    Top = 8
    Width = 121
    Height = 21
    CalAlignment = dtaLeft
    Date = 42301.5787774769
    Format = 'ddMMMMyyyy'
    Time = 42301.5787774769
    DateFormat = dfLong
    DateMode = dmComboBox
    Kind = dtkDate
    ParseInput = False
    TabOrder = 1
  end
  object BitBtn1: TBitBtn
    Left = 344
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Ver'
    TabOrder = 2
    OnClick = BitBtn1Click
  end
  object DBGrid1: TDBGrid
    Left = 8
    Top = 48
    Width = 320
    Height = 417
    DataSource = DM.dsVentasFecha
    TabOrder = 3
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'FECHA'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'TOTAL'
        Width = 97
        Visible = True
      end>
  end
  object DBChart1: TDBChart
    Left = 336
    Top = 48
    Width = 585
    Height = 417
    AnimatedZoom = True
    BackWall.Brush.Color = clWhite
    BackWall.Brush.Style = bsClear
    LeftWall.Brush.Color = clWhite
    LeftWall.Brush.Style = bsClear
    Title.Text.Strings = (
      'REPORTE DE VENAS POR FECHAS')
    Chart3DPercent = 20
    LeftAxis.AxisValuesFormat = '#,##0.00'
    LeftAxis.LabelsSeparation = 20
    Legend.Visible = False
    TabOrder = 4
    object Series1: TBarSeries
      ColorEachPoint = True
      Marks.ArrowLength = 20
      Marks.Style = smsValue
      Marks.Visible = True
      DataSource = DM.qVentasFecha
      SeriesColor = clRed
      XLabelsSource = 'FECHA'
      XValues.DateTime = True
      XValues.Name = 'X'
      XValues.Multiplier = 1
      XValues.Order = loAscending
      XValues.ValueSource = 'FECHA'
      YValues.DateTime = False
      YValues.Name = 'Bar'
      YValues.Multiplier = 1
      YValues.Order = loNone
      YValues.ValueSource = 'TOTAL'
    end
  end
end
