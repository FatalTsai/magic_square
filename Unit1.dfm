object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 676
  ClientWidth = 980
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 0
    Top = 231
    Width = 985
    Height = 457
    ActivePage = TabSheet3
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = 'original'
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object Memo1: TMemo
        Left = 0
        Top = 0
        Width = 977
        Height = 429
        Align = alClient
        Lines.Strings = (
          'Memo1')
        TabOrder = 0
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'rotate'
      ImageIndex = 1
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object Memo2: TMemo
        Left = 0
        Top = 0
        Width = 977
        Height = 429
        Align = alClient
        Lines.Strings = (
          'Memo2')
        TabOrder = 0
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'check'
      ImageIndex = 2
      object Memo3: TMemo
        Left = 0
        Top = 0
        Width = 977
        Height = 429
        Align = alClient
        Lines.Strings = (
          'Memo3')
        TabOrder = 0
      end
    end
    object TabSheet4: TTabSheet
      Caption = 'DataGridView'
      ImageIndex = 3
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object StringGrid1: TStringGrid
        Left = 0
        Top = 0
        Width = 977
        Height = 429
        Align = alClient
        TabOrder = 0
      end
    end
  end
  object Panel1: TPanel
    Left = -31
    Top = 0
    Width = 1003
    Height = 225
    TabOrder = 1
    object Button1: TButton
      Left = 296
      Top = 86
      Width = 75
      Height = 25
      Caption = 'submit'
      TabOrder = 0
      OnClick = Button1Click
    end
    object Edit1: TEdit
      Left = 96
      Top = 88
      Width = 121
      Height = 21
      TabOrder = 1
    end
    object RadioButton1: TRadioButton
      Left = 472
      Top = 80
      Width = 113
      Height = 17
      Caption = 'RadioButton1'
      TabOrder = 2
      OnClick = RadioButton1Click
    end
    object RadioButton2: TRadioButton
      Left = 632
      Top = 80
      Width = 113
      Height = 17
      Caption = 'RadioButton2'
      TabOrder = 3
      OnClick = RadioButton2Click
    end
    object RadioButton3: TRadioButton
      Left = 472
      Top = 136
      Width = 113
      Height = 17
      Caption = 'RadioButton3'
      TabOrder = 4
      OnClick = RadioButton3Click
    end
    object RadioButton4: TRadioButton
      Left = 632
      Top = 136
      Width = 113
      Height = 17
      Caption = 'RadioButton4'
      TabOrder = 5
      OnClick = RadioButton4Click
    end
  end
end
