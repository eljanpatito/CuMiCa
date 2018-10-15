object FRMLogs: TFRMLogs
  Left = 192
  Top = 124
  BorderStyle = bsDialog
  Caption = 'Logs'
  ClientHeight = 211
  ClientWidth = 466
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
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 249
    Height = 187
    Caption = 'Configuration'
    TabOrder = 0
    object Label1: TLabel
      Left = 16
      Top = 24
      Width = 76
      Height = 13
      Caption = 'Prefix file names'
    end
    object Label2: TLabel
      Left = 16
      Top = 64
      Width = 72
      Height = 13
      Caption = 'Counter start at'
    end
    object Label3: TLabel
      Left = 136
      Top = 64
      Width = 71
      Height = 13
      Caption = 'Format counter'
    end
    object Label4: TLabel
      Left = 136
      Top = 104
      Width = 80
      Height = 13
      Caption = 'Sample file name'
    end
    object LSampleFileName: TLabel
      Left = 136
      Top = 120
      Width = 85
      Height = 13
      Caption = 'LSampleFileName'
    end
    object Label5: TLabel
      Left = 16
      Top = 104
      Width = 77
      Height = 13
      Caption = 'Max lines log file'
    end
    object Label6: TLabel
      Left = 136
      Top = 24
      Width = 79
      Height = 13
      Caption = 'Extension log file'
    end
    object EFileName: TEdit
      Left = 16
      Top = 40
      Width = 101
      Height = 21
      TabOrder = 1
      Text = 'Log'
      OnChange = myEvent
      OnExit = myEvent
    end
    object EStartCounter: TEdit
      Left = 16
      Top = 80
      Width = 101
      Height = 21
      TabOrder = 0
      Text = '1'
      OnChange = myEvent
      OnExit = myEvent
      OnKeyPress = EStartCounterKeyPress
    end
    object ECounterFormat: TEdit
      Left = 136
      Top = 80
      Width = 101
      Height = 21
      TabOrder = 2
      Text = '000'
      OnChange = myEvent
      OnExit = myEvent
    end
    object EMaxLines: TEdit
      Left = 16
      Top = 120
      Width = 101
      Height = 21
      TabOrder = 3
      Text = '500'
      OnKeyPress = EStartCounterKeyPress
    end
    object BitBtn1: TBitBtn
      Left = 160
      Top = 152
      Width = 75
      Height = 25
      Caption = 'Save'
      TabOrder = 4
      OnClick = BitBtn1Click
      Kind = bkOK
    end
    object Button1: TButton
      Left = 16
      Top = 152
      Width = 129
      Height = 25
      Caption = 'Generate Test Message'
      TabOrder = 5
      OnClick = Button1Click
    end
    object EExtension: TEdit
      Left = 136
      Top = 40
      Width = 101
      Height = 21
      TabOrder = 6
      Text = 'txt'
    end
  end
  object Memo1: TMemo
    Left = 272
    Top = 8
    Width = 185
    Height = 89
    Lines.Strings = (
      '1'#215#215' Informational'
      '100 Continue'
      '101 Switching Protocols'
      '102 Processing'
      '2'#215#215' Success'
      '200 OK'
      '201 Created'
      '202 Accepted'
      '203 Non-authoritative Information'
      '204 No Content'
      '205 Reset Content'
      '206 Partial Content'
      '207 Multi-Status'
      '208 Already Reported'
      '226 IM Used'
      '3'#215#215' Redirection'
      '300 Multiple Choices'
      '301 Moved Permanently'
      '302 Found'
      '303 See Other'
      '304 Not Modified'
      '305 Use Proxy'
      '307 Temporary Redirect'
      '308 Permanent Redirect'
      '4'#215#215' Client Error'
      '400 Bad Request'
      '401 Unauthorized'
      '402 Payment Required'
      '403 Forbidden'
      '404 Not Found'
      '405 Method Not Allowed'
      '406 Not Acceptable'
      '407 Proxy Authentication Required'
      '408 Request Timeout'
      '409 Conflict'
      '410 Gone'
      '411 Length Required'
      '412 Precondition Failed'
      '413 Payload Too Large'
      '414 Request-URI Too Long'
      '415 Unsupported Media Type'
      '416 Requested Range Not Satisfiable'
      '417 Expectation Failed'
      '418 I'#39'm a teapot'
      '421 Misdirected Request'
      '422 Unprocessable Entity'
      '423 Locked'
      '424 Failed Dependency'
      '426 Upgrade Required'
      '428 Precondition Required'
      '429 Too Many Requests'
      '431 Request Header Fields Too '
      'Large'
      '444 Connection Closed Without '
      'Response'
      '451 Unavailable For Legal Reasons'
      '499 Client Closed Request'
      '5'#215#215' Server Error'
      '500 Internal Server Error'
      '501 Not Implemented'
      '502 Bad Gateway'
      '503 Service Unavailable'
      '504 Gateway Timeout'
      '505 HTTP Version Not Supported'
      '506 Variant Also Negotiates'
      '507 Insufficient Storage'
      '508 Loop Detected'
      '510 Not Extended'
      '511 Network Authentication Required'
      '599 Network Connect Timeout Error')
    TabOrder = 1
  end
end
