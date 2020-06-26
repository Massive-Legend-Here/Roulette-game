object DataModule1: TDataModule1
  OldCreateOrder = False
  Height = 227
  Width = 316
  object ADOConnection1: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=Microsoft.Jet.OLEDB.4.0;Data Source=C:\Users\David\Desk' +
      'top\Projekti C++\Roullette++\Login.mdb;Persist Security Info=Fal' +
      'se'
    LoginPrompt = False
    Mode = cmShareDenyNone
    Provider = 'Microsoft.Jet.OLEDB.4.0'
    Left = 40
    Top = 8
  end
  object ADOTable1: TADOTable
    Connection = ADOConnection1
    TableName = 'Login'
    Left = 112
    Top = 8
  end
  object DataSource1: TDataSource
    DataSet = ADOTable1
    Left = 176
    Top = 8
  end
end
