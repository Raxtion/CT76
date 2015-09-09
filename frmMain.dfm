object fmMain: TfmMain
  Left = 326
  Top = 19
  Width = 960
  Height = 548
  Caption = 'frmMain'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  DesignSize = (
    952
    514)
  PixelsPerInch = 96
  TextHeight = 13
  object listHistory: TListBox
    Left = 0
    Top = 0
    Width = 705
    Height = 516
    Anchors = [akLeft, akTop, akRight, akBottom]
    Color = clBlack
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clLime
    Font.Height = -16
    Font.Name = 'GulimChe'
    Font.Style = []
    ItemHeight = 16
    ParentFont = False
    TabOrder = 0
  end
  object Panel1: TPanel
    Left = 704
    Top = 0
    Width = 249
    Height = 516
    Anchors = [akTop, akRight, akBottom]
    TabOrder = 1
    DesignSize = (
      249
      516)
    object Label1: TLabel
      Left = 23
      Top = 32
      Width = 47
      Height = 13
      Anchors = [akTop]
      Caption = 'Custromer'
    end
    object Label2: TLabel
      Left = 23
      Top = 56
      Width = 38
      Height = 13
      Anchors = [akTop]
      Caption = 'Supplier'
    end
    object Label3: TLabel
      Left = 23
      Top = 80
      Width = 15
      Height = 13
      Anchors = [akTop]
      Caption = 'PN'
    end
    object Label4: TLabel
      Left = 23
      Top = 104
      Width = 21
      Height = 13
      Anchors = [akTop]
      Caption = 'LOT'
    end
    object Label5: TLabel
      Left = 23
      Top = 128
      Width = 14
      Height = 13
      Anchors = [akTop]
      Caption = 'XX'
    end
    object Label6: TLabel
      Left = 23
      Top = 152
      Width = 27
      Height = 13
      Anchors = [akTop]
      Caption = 'DWG'
    end
    object Label8: TLabel
      Left = 23
      Top = 176
      Width = 44
      Height = 13
      Anchors = [akTop]
      Caption = 'MFGdate'
    end
    object Label7: TLabel
      Left = 23
      Top = 200
      Width = 42
      Height = 13
      Anchors = [akTop]
      Caption = 'EXPdate'
    end
    object Label9: TLabel
      Left = 23
      Top = 400
      Width = 10
      Height = 13
      Anchors = [akTop]
      Caption = 'IP'
    end
    object Label10: TLabel
      Left = 23
      Top = 424
      Width = 19
      Height = 13
      Anchors = [akTop]
      Caption = 'Port'
    end
    object editCustromer: TEdit
      Left = 78
      Top = 28
      Width = 130
      Height = 21
      Anchors = [akTop]
      AutoSize = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
    end
    object btnStart: TBitBtn
      Left = 41
      Top = 455
      Width = 169
      Height = 49
      Anchors = []
      Caption = 'Start'
      TabOrder = 1
      OnClick = btnStartClick
    end
    object editSupplier: TEdit
      Left = 78
      Top = 52
      Width = 130
      Height = 21
      Anchors = [akTop]
      AutoSize = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
    end
    object editPN: TEdit
      Left = 78
      Top = 76
      Width = 130
      Height = 21
      Anchors = [akTop]
      AutoSize = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
    end
    object editLOT: TEdit
      Left = 78
      Top = 100
      Width = 130
      Height = 21
      Anchors = [akTop]
      AutoSize = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 4
    end
    object editXX: TEdit
      Left = 78
      Top = 124
      Width = 130
      Height = 21
      Anchors = [akTop]
      AutoSize = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 5
    end
    object editDWG: TEdit
      Left = 78
      Top = 148
      Width = 130
      Height = 21
      Anchors = [akTop]
      AutoSize = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 6
    end
    object editMFGdate: TEdit
      Left = 78
      Top = 172
      Width = 130
      Height = 21
      Anchors = [akTop]
      AutoSize = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 7
    end
    object editEXPdate: TEdit
      Left = 78
      Top = 196
      Width = 130
      Height = 21
      Anchors = [akTop]
      AutoSize = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 8
    end
    object editIP: TEdit
      Left = 70
      Top = 396
      Width = 130
      Height = 21
      Anchors = [akTop]
      AutoSize = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 9
    end
    object editPort: TEdit
      Left = 70
      Top = 420
      Width = 130
      Height = 21
      Anchors = [akTop]
      AutoSize = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 10
    end
  end
  object ClientSocket1: TClientSocket
    Active = False
    ClientType = ctNonBlocking
    Host = '192.168.100.10'
    Port = 9004
    OnConnect = ClientSocket1Connect
    OnRead = ClientSocket1Read
    Left = 656
    Top = 464
  end
end
