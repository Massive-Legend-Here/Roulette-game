//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "string.h"
#include "Unit3.h"
#include "Unit4.h"
#include <idhashmessagedigest.hpp>
#include <idhashsha.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
int multi = 0;
UnicodeString korisnicko_ime;
UnicodeString korisnicko_ime_server;
UnicodeString IP_adresa;
void __fastcall TForm3::Button1Click(TObject *Sender)
{       //string a = Edit1->Text;
		//ShowMessage(a);
		//ShowMessage(Edit2->Text);
		korisnicko_ime = Edit1->Text;
		korisnicko_ime_server  = korisnicko_ime;
		UnicodeString hash_lozinka = Edit2->Text;
        IP_adresa = Edit3->Text;
		TIdHashSHA1 * sha1 = new TIdHashSHA1;
        hash_lozinka = sha1->HashStringAsHex(hash_lozinka);
		//ShowMessage(korisnicko_ime + "    " + hash_lozinka);

		multi=1;

		Tlogin->Insert();
		Tlogin->FieldByName("K_ime")->AsString = Edit1->Text;
		Tlogin->FieldByName("Pass")->AsString = hash_lozinka;
		Tlogin->Post();

        TLocateOptions Opts;
		Opts.Clear();
		Opts << loCaseInsensitive;
		bool x = Form3->Tlogin->Locate("Pass",hash_lozinka, Opts );
		if ( x == true) {
			Form4->Show();
			Form3->Hide();
		}
		else {
		   int odgovor2 = Application->MessageBox(L"There is no user with this username. Register?", L"Registration",  MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2);
			if (odgovor2 == IDYES){
                Form4->Show();
				Form3->Hide();
				return;
			}else{
				return;
			}

        }

}
//---------------------------------------------------------------------------
void __fastcall TForm3::FormClose(TObject *Sender, TCloseAction &Action)
{
    Application->Terminate();
}
//---------------------------------------------------------------------------



