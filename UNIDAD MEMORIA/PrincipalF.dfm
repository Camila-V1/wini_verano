object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 624
  ClientWidth = 943
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Button1: TButton
    Left = 24
    Top = 32
    Width = 89
    Height = 25
    Caption = 'Crear'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 24
    Top = 63
    Width = 89
    Height = 25
    Caption = 'pedir Espacio'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 24
    Top = 94
    Width = 89
    Height = 25
    Caption = 'Liberar Espacio'
    TabOrder = 2
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 24
    Top = 125
    Width = 89
    Height = 25
    Caption = 'Mostrar M'
    TabOrder = 3
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 24
    Top = 156
    Width = 89
    Height = 25
    Caption = 'Poner Dato'
    TabOrder = 4
    OnClick = Button5Click
  end
  object Edit1: TEdit
    Left = 128
    Top = 64
    Width = 177
    Height = 23
    TabOrder = 5
    Text = 'hola,como,estas'
  end
  object Edit2: TEdit
    Left = 128
    Top = 95
    Width = 121
    Height = 23
    TabOrder = 6
    Text = '0'
  end
  object Edit3: TEdit
    Left = 128
    Top = 126
    Width = 49
    Height = 23
    TabOrder = 7
    Text = '0'
  end
  object Edit4: TEdit
    Left = 200
    Top = 126
    Width = 65
    Height = 23
    TabOrder = 8
    Text = '11'
  end
  object Edit5: TEdit
    Left = 128
    Top = 155
    Width = 49
    Height = 23
    TabOrder = 9
    Text = '0'
  end
  object Edit6: TEdit
    Left = 200
    Top = 158
    Width = 81
    Height = 23
    TabOrder = 10
    Text = '->como'
  end
  object Edit7: TEdit
    Left = 304
    Top = 158
    Width = 57
    Height = 23
    TabOrder = 11
    Text = '100'
  end
end
