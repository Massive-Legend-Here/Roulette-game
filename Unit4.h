//---------------------------------------------------------------------------

#ifndef Unit4H
#define Unit4H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.Grids.hpp>
#include <Xml.XMLDoc.hpp>
#include <Xml.xmldom.hpp>
#include <Xml.XMLIntf.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdContext.hpp>
#include <IdCustomTCPServer.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <IdTCPServer.hpp>
#include <IdIcmpClient.hpp>
#include <IdRawBase.hpp>
#include <IdRawClient.hpp>
//---------------------------------------------------------------------------
class TForm4 : public TForm
{
__published:	// IDE-managed Components
	TControlBar *Ulog_1;
	TImage *slika_roulette_stol;
	TControlBar *Ulog_2;
	TControlBar *Ulog_3;
	TControlBar *Ulog_4;
	TControlBar *Ulog_5;
	TControlBar *Ulog_6;
	TControlBar *Ulog_7;
	TControlBar *Ulog_8;
	TControlBar *Ulog_9;
	TControlBar *Ulog_10;
	TControlBar *Ulog_11;
	TControlBar *Ulog_12;
	TControlBar *Ulog_13;
	TControlBar *Ulog_14;
	TControlBar *Ulog_15;
	TControlBar *Ulog_16;
	TControlBar *Ulog_17;
	TControlBar *Ulog_18;
	TControlBar *Ulog_19;
	TControlBar *Ulog_20;
	TControlBar *Ulog_21;
	TControlBar *Ulog_22;
	TControlBar *Ulog_23;
	TControlBar *Ulog_24;
	TControlBar *Ulog_25;
	TControlBar *Ulog_26;
	TControlBar *Ulog_27;
	TControlBar *Ulog_28;
	TControlBar *Ulog_29;
	TControlBar *Ulog_30;
	TControlBar *Ulog_31;
	TControlBar *Ulog_32;
	TControlBar *Ulog_33;
	TControlBar *Ulog_34;
	TControlBar *Ulog_35;
	TControlBar *Ulog_36;
	TControlBar *Ulog_3_36;
	TControlBar *Ulog_2_35;
	TControlBar *Ulog_1_34;
	TControlBar *Ulog_prvih_12;
	TControlBar *Ulog_drugih_12;
	TControlBar *Ulog_trecih_12;
	TControlBar *Ulog_0;
	TControlBar *Ulog_1_do_18;
	TControlBar *Ulog_parni;
	TControlBar *Ulog_crni;
	TControlBar *Ulog_crveni;
	TControlBar *Ulog_neparni;
	TControlBar *Ulog_19_do_36;
	TSpeedButton *Chip_1;
	TSpeedButton *Chip_2;
	TSpeedButton *Chip_5;
	TLabel *Label_iznos_igrac;
	TImage *Igrac_main_slika;
	TLabel *Label1;
	TImage *Igrac1_slika;
	TImage *Igrac4_slika;
	TImage *Igrac2_slika;
	TImage *Igrac3_slika;
	TImage *Igrac6_slika;
	TImage *Igrac5_slika;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label12;
	TLabel *Label13;
	TImage *RouletteBrojevi;
	TButton *Button1;
	TButton *Button2;
	TLabel *Label16;
	TLabel *Label17;
	TLabel *Label18;
	TLabel *Label19;
	TLabel *Label20;
	TLabel *Label21;
	TLabel *Label22;
	TLabel *Label23;
	TLabel *Label24;
	TLabel *Label25;
	TLabel *Label26;
	TLabel *Label27;
	TLabel *Label28;
	TLabel *Label29;
	TSpeedButton *kraj_runde;
	TLabel *Label14;
	TXMLDocument *XMLDocument1;
	TLabel *Label32;
	TLabel *Label15;
	TLabel *Label30;
	TLabel *Label31;
	TLabel *Label33;
	TLabel *Label34;
	TLabel *Label35;
	TADOConnection *ADOConnection1;
	TADOTable *THighscore;
	TDataSource *DHighscore;
	TIdTCPClient *ChatClient;
	TIdTCPServer *ChatServer;
	TListBox *LMessage;
	TEdit *EMessage;
	TButton *Button3;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Ulog_0Click(TObject *Sender);
	void __fastcall Ulog_1Click(TObject *Sender);
	void __fastcall Ulog_2Click(TObject *Sender);
	void __fastcall Ulog_3Click(TObject *Sender);
	void __fastcall Ulog_4Click(TObject *Sender);
	void __fastcall Ulog_5Click(TObject *Sender);
	void __fastcall Ulog_6Click(TObject *Sender);
	void __fastcall Ulog_7Click(TObject *Sender);
	void __fastcall Ulog_8Click(TObject *Sender);
	void __fastcall Ulog_9Click(TObject *Sender);
	void __fastcall Ulog_10Click(TObject *Sender);
	void __fastcall Ulog_11Click(TObject *Sender);
	void __fastcall Ulog_12Click(TObject *Sender);
	void __fastcall Ulog_13Click(TObject *Sender);
	void __fastcall Ulog_14Click(TObject *Sender);
	void __fastcall Ulog_15Click(TObject *Sender);
	void __fastcall Ulog_16Click(TObject *Sender);
	void __fastcall Ulog_17Click(TObject *Sender);
	void __fastcall Ulog_18Click(TObject *Sender);
	void __fastcall Ulog_19Click(TObject *Sender);
	void __fastcall Ulog_20Click(TObject *Sender);
	void __fastcall Ulog_21Click(TObject *Sender);
	void __fastcall Ulog_22Click(TObject *Sender);
	void __fastcall Ulog_23Click(TObject *Sender);
	void __fastcall Ulog_24Click(TObject *Sender);
	void __fastcall Ulog_25Click(TObject *Sender);
	void __fastcall Ulog_26Click(TObject *Sender);
	void __fastcall Ulog_27Click(TObject *Sender);
	void __fastcall Ulog_28Click(TObject *Sender);
	void __fastcall Ulog_29Click(TObject *Sender);
	void __fastcall Ulog_30Click(TObject *Sender);
	void __fastcall Ulog_31Click(TObject *Sender);
	void __fastcall Ulog_32Click(TObject *Sender);
	void __fastcall Ulog_33Click(TObject *Sender);
	void __fastcall Ulog_34Click(TObject *Sender);
	void __fastcall Ulog_35Click(TObject *Sender);
	void __fastcall Ulog_36Click(TObject *Sender);
	void __fastcall Ulog_1_34Click(TObject *Sender);
	void __fastcall Ulog_2_35Click(TObject *Sender);
	void __fastcall Ulog_3_36Click(TObject *Sender);
	void __fastcall Ulog_prvih_12Click(TObject *Sender);
	void __fastcall Ulog_drugih_12Click(TObject *Sender);
	void __fastcall Ulog_trecih_12Click(TObject *Sender);
	void __fastcall Ulog_1_do_18Click(TObject *Sender);
	void __fastcall Ulog_parniClick(TObject *Sender);
	void __fastcall Ulog_crniClick(TObject *Sender);
	void __fastcall Ulog_crveniClick(TObject *Sender);
	void __fastcall Ulog_neparniClick(TObject *Sender);
	void __fastcall Ulog_19_do_36Click(TObject *Sender);
	void __fastcall Chip_1Click(TObject *Sender);
	void __fastcall Chip_2Click(TObject *Sender);
	void __fastcall Spremi_igru(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Prekid_igre(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall kraj_rundeClick(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall ChatServerExecute(TIdContext *AContext);
private:	// User declarations
public:		// User declarations
	__fastcall TForm4(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm4 *Form4;
extern int tezinaEasy;
extern int tezinaNormal;
extern int tezinaHard;
extern int load;
extern int multi;
extern  UnicodeString korisnicko_ime;
extern UnicodeString korisnicko_ime_server;
extern UnicodeString IP_adresa;
//---------------------------------------------------------------------------
#endif
