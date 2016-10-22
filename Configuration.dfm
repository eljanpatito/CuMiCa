object frmConfiguration: TfrmConfiguration
  Left = 192
  Top = 124
  Width = 346
  Height = 343
  Caption = 'Configuration'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 168
    Width = 48
    Height = 13
    Caption = 'Propiedad'
    FocusControl = dbeProperty
  end
  object Label2: TLabel
    Left = 8
    Top = 208
    Width = 24
    Height = 13
    Caption = 'Valor'
    FocusControl = dbeValue
  end
  object lFont: TLabel
    Left = 8
    Top = 256
    Width = 78
    Height = 13
    Caption = 'Texto de prueba'
  end
  object DBGrid1: TDBGrid
    Left = 8
    Top = 40
    Width = 300
    Height = 120
    DataSource = DM.dsConfiguration
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
  end
  object DBNavigator1: TDBNavigator
    Left = 8
    Top = 8
    Width = 240
    Height = 25
    DataSource = DM.dsConfiguration
    TabOrder = 1
  end
  object dbeProperty: TDBEdit
    Left = 8
    Top = 184
    Width = 300
    Height = 21
    DataField = 'property'
    DataSource = DM.dsConfiguration
    TabOrder = 2
  end
  object dbeValue: TDBEdit
    Left = 8
    Top = 224
    Width = 300
    Height = 21
    DataField = 'value'
    DataSource = DM.dsConfiguration
    TabOrder = 3
  end
  object eFont: TEdit
    Left = 96
    Top = 256
    Width = 121
    Height = 21
    ReadOnly = True
    TabOrder = 4
  end
  object fdFont: TFontDialog
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    MinFontSize = 0
    MaxFontSize = 0
    Left = 48
    Top = 272
  end
  object PopupMenu1: TPopupMenu
    Left = 8
    Top = 272
    object Font1: TMenuItem
      Caption = 'Font'
      OnClick = Font1Click
    end
    object Copiaralvalor1: TMenuItem
      Caption = 'Copiar al valor'
      OnClick = Copiaralvalor1Click
    end
  end
end
