
// *********************************************************************************************** //
//                                                                                               
//                                       XML Data Binding                                        
//                                                                                               
//         Generated on: 29.5.2020. 18:29:29                                                     
//       Generated from: C:\Users\David\Desktop\Projekti C++\Roullette++\Win32\Debug\popis.xml   
//                                                                                               
// *********************************************************************************************** //

#ifndef   popisH
#define   popisH

#include <System.hpp>
#include <Xml.Xmldom.hpp>
#include <Xml.XMLIntf.hpp>
#include <Xml.XMLDoc.hpp>
#include <XMLNodeImp.h>
#include <Xml.xmlutil.hpp>


// Forward Decls 

__interface IXMLPlayeriType;
typedef System::DelphiInterface<IXMLPlayeriType> _di_IXMLPlayeriType;
__interface IXMLPlayersType;
typedef System::DelphiInterface<IXMLPlayersType> _di_IXMLPlayersType;

// IXMLPlayeriType 

__interface INTERFACE_UUID("{DA7C0AA8-8D0E-40EF-AC12-78AB3A6FFA93}") IXMLPlayeriType : public Xml::Xmlintf::IXMLNodeCollection
{
public:
public:
  // Property Accessors 
  virtual _di_IXMLPlayersType __fastcall Get_Players(int Index) = 0;
  // Methods & Properties 
  virtual _di_IXMLPlayersType __fastcall Add() = 0;
  virtual _di_IXMLPlayersType __fastcall Insert(const int Index) = 0;
  __property _di_IXMLPlayersType Players[int Index] = { read=Get_Players };/* default */
};

// IXMLPlayersType 

__interface INTERFACE_UUID("{8DEAFB21-5B08-4EFE-92FB-685AD5CE18CE}") IXMLPlayersType : public Xml::Xmlintf::IXMLNode
{
public:
  // Property Accessors 
  virtual int __fastcall Get_iznos() = 0;
  virtual void __fastcall Set_iznos(int Value) = 0;
  // Methods & Properties 
  __property int iznos = { read=Get_iznos, write=Set_iznos };
};

// Forward Decls 

class TXMLPlayeriType;
class TXMLPlayersType;

// TXMLPlayeriType 

class TXMLPlayeriType : public Xml::Xmldoc::TXMLNodeCollection, public IXMLPlayeriType
{
  __IXMLNODECOLLECTION_IMPL__
protected:
  // IXMLPlayeriType 
  virtual _di_IXMLPlayersType __fastcall Get_Players(int Index);
  virtual _di_IXMLPlayersType __fastcall Add();
  virtual _di_IXMLPlayersType __fastcall Insert(const int Index);
public:
  virtual void __fastcall AfterConstruction(void);
};

// TXMLPlayersType 

class TXMLPlayersType : public Xml::Xmldoc::TXMLNode, public IXMLPlayersType
{
  __IXMLNODE_IMPL__
protected:
  // IXMLPlayersType 
  virtual int __fastcall Get_iznos();
  virtual void __fastcall Set_iznos(int Value);
};

// Global Functions 

_di_IXMLPlayeriType __fastcall GetPlayeri(Xml::Xmlintf::_di_IXMLDocument Doc);
_di_IXMLPlayeriType __fastcall GetPlayeri(Xml::Xmldoc::TXMLDocument *Doc);
_di_IXMLPlayeriType __fastcall LoadPlayeri(const System::UnicodeString& FileName);
_di_IXMLPlayeriType __fastcall  NewPlayeri();

#define TargetNamespace ""

#endif