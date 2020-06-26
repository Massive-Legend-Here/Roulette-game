
// *********************************************************************************************** //
//                                                                                               
//                                       XML Data Binding                                        
//                                                                                               
//         Generated on: 29.5.2020. 18:29:29                                                     
//       Generated from: C:\Users\David\Desktop\Projekti C++\Roullette++\Win32\Debug\popis.xml   
//                                                                                               
// *********************************************************************************************** //

#include <System.hpp>
#pragma hdrstop

#include "popis.h"


// Global Functions 

_di_IXMLPlayeriType __fastcall GetPlayeri(Xml::Xmlintf::_di_IXMLDocument Doc)
{
  return (_di_IXMLPlayeriType) Doc->GetDocBinding("Playeri", __classid(TXMLPlayeriType), TargetNamespace);
};

_di_IXMLPlayeriType __fastcall GetPlayeri(Xml::Xmldoc::TXMLDocument *Doc)
{
  Xml::Xmlintf::_di_IXMLDocument DocIntf;
  Doc->GetInterface(DocIntf);
  return GetPlayeri(DocIntf);
};

_di_IXMLPlayeriType __fastcall LoadPlayeri(const System::UnicodeString& FileName)
{
  return (_di_IXMLPlayeriType) Xml::Xmldoc::LoadXMLDocument(FileName)->GetDocBinding("Playeri", __classid(TXMLPlayeriType), TargetNamespace);
};

_di_IXMLPlayeriType __fastcall  NewPlayeri()
{
  return (_di_IXMLPlayeriType) Xml::Xmldoc::NewXMLDocument()->GetDocBinding("Playeri", __classid(TXMLPlayeriType), TargetNamespace);
};

// TXMLPlayeriType 

void __fastcall TXMLPlayeriType::AfterConstruction(void)
{
  RegisterChildNode(System::UnicodeString("Players"), __classid(TXMLPlayersType));
  ItemTag = "Players";
  ItemInterface = __uuidof(IXMLPlayersType);
  Xml::Xmldoc::TXMLNodeCollection::AfterConstruction();
};

_di_IXMLPlayersType __fastcall TXMLPlayeriType::Get_Players(int Index)
{
  return (_di_IXMLPlayersType) List->Nodes[Index];
};

_di_IXMLPlayersType __fastcall TXMLPlayeriType::Add()
{
  return (_di_IXMLPlayersType) AddItem(-1);
};

_di_IXMLPlayersType __fastcall TXMLPlayeriType::Insert(const int Index)
{
  return (_di_IXMLPlayersType) AddItem(Index);
};

// TXMLPlayersType 

int __fastcall TXMLPlayersType::Get_iznos()
{
  return GetChildNodes()->Nodes[System::UnicodeString("iznos")]->NodeValue.operator int();
};

void __fastcall TXMLPlayersType::Set_iznos(int Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("iznos")]->NodeValue = Value;
};
