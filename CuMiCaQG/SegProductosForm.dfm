object fSeguimiento: TfSeguimiento
  Left = 192
  Top = 124
  Width = 651
  Height = 456
  Caption = 'CuMiCa - Seguimiento de productos'
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
    Top = 16
    Width = 117
    Height = 13
    Caption = 'Ingrese Codigo Producto'
  end
  object Label2: TLabel
    Left = 8
    Top = 32
    Width = 33
    Height = 13
    Caption = 'Codigo'
  end
  object Label3: TLabel
    Left = 8
    Top = 48
    Width = 56
    Height = 13
    Caption = 'Descripcion'
  end
  object DBText1: TDBText
    Left = 80
    Top = 32
    Width = 65
    Height = 17
    DataField = 'CODIGO'
    DataSource = DM.dsSeguimiento
  end
  object DBText2: TDBText
    Left = 80
    Top = 48
    Width = 166
    Height = 13
    AutoSize = True
    DataField = 'DESCRIPCION'
    DataSource = DM.dsSeguimiento
  end
  object Label4: TLabel
    Left = 320
    Top = 32
    Width = 89
    Height = 13
    Caption = 'TOTAL DE CAJAS'
  end
  object DBText3: TDBText
    Left = 424
    Top = 32
    Width = 18
    Height = 13
    AutoSize = True
    DataField = 'TOTAL_CAJAS'
    DataSource = DM.dsSumCajas
  end
  object DBGrid1: TDBGrid
    Left = 8
    Top = 72
    Width = 617
    Height = 297
    DataSource = DM.dsSeguimiento
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'IDNOTA'
        Width = 50
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'CANTIDAD'
        Width = 60
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'NOMBRE_CLIENTE'
        Width = 350
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'FECHA'
        Visible = True
      end>
  end
  object Edit1: TEdit
    Left = 136
    Top = 8
    Width = 121
    Height = 21
    TabOrder = 1
    Text = 'Edit1'
    OnChange = Edit1Change
  end
  object BitBtn1: TBitBtn
    Left = 264
    Top = 384
    Width = 75
    Height = 25
    Caption = 'IMPRIMIR'
    TabOrder = 2
    OnClick = BitBtn1Click
  end
end
