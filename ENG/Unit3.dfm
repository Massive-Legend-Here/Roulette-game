object Form3: TForm3
  Left = 0
  Top = 0
  BorderStyle = bsSingle
  Caption = 'Multyplayer'
  ClientHeight = 295
  ClientWidth = 262
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 40
    Top = 29
    Width = 67
    Height = 13
    Caption = 'Username:'
  end
  object Label2: TLabel
    Left = 40
    Top = 88
    Width = 35
    Height = 13
    Caption = 'Password:'
  end
  object Label3: TLabel
    Left = 40
    Top = 144
    Width = 46
    Height = 13
    Caption = 'IP adresa'
  end
  object Edit1: TEdit
    Left = 40
    Top = 48
    Width = 169
    Height = 21
    TabOrder = 0
  end
  object Edit2: TEdit
    Left = 40
    Top = 107
    Width = 169
    Height = 21
    TabOrder = 1
  end
  object Button1: TButton
    Left = 40
    Top = 208
    Width = 169
    Height = 33
    Caption = 'Login'
    TabOrder = 2
    OnClick = Button1Click
  end
  object Edit3: TEdit
    Left = 40
    Top = 163
    Width = 169
    Height = 21
    TabOrder = 3
  end
  object ADOConnection1: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=Microsoft.Jet.OLEDB.4.0;User ID=Admin;Data Source=Login' +
      '.mdb;Mode=Share Deny None;Persist Security Info=False;Jet OLEDB:' +
      'System database="";Jet OLEDB:Registry Path="";Jet OLEDB:Database' +
      ' Password="";Jet OLEDB:Engine Type=5;Jet OLEDB:Database Locking ' +
      'Mode=1;Jet OLEDB:Global Partial Bulk Ops=2;Jet OLEDB:Global Bulk' +
      ' Transactions=1;Jet OLEDB:New Database Password="";Jet OLEDB:Cre' +
      'ate System Database=False;Jet OLEDB:Encrypt Database=False;Jet O' +
      'LEDB:Don'#39't Copy Locale on Compact=False;Jet OLEDB:Compact Withou' +
      't Replica Repair=False;Jet OLEDB:SFP=False'
    LoginPrompt = False
    Mode = cmShareDenyNone
    Provider = 'Microsoft.Jet.OLEDB.4.0'
    Left = 224
    Top = 16
  end
  object Tlogin: TADOTable
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = 'Login'
    Left = 224
    Top = 64
  end
  object Dlogin: TDataSource
    DataSet = Tlogin
    Left = 224
    Top = 120
  end
end
