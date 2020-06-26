//---------------------------------------------------------------------------

#include <vcl.h>
#include <string>
#pragma hdrstop

#include "pocetna.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
#include "Unit5.h"
#include "reinit.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	  Form2->Show();
	  Form1->Hide();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	 Form3->Show();
	  Form1->Hide();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
	Application->Terminate();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button4Click(TObject *Sender)
{   Form3->ADOConnection1->Connected =0;
	Form4->ADOConnection1->Connected =0;
	Form5->ADOConnection1->Connected =0;
    const CROATIAN = (SUBLANG_CROATIAN_CROATIA << 10) | LANG_CROATIAN;
	if (LoadNewResourceModule(CROATIAN))
		ReinitializeForms();
	Form3->ADOConnection1->Connected =1;
	Form4->ADOConnection1->Connected =1;
	Form5->ADOConnection1->Connected =1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
    Form3->ADOConnection1->Connected =0;
	Form4->ADOConnection1->Connected =0;
	Form5->ADOConnection1->Connected =0;
   const ENGLISH = (SUBLANG_ENGLISH_UK << 10) | LANG_ENGLISH;
	if (LoadNewResourceModule(ENGLISH))
			ReinitializeForms();
    Form3->ADOConnection1->Connected =1;
	Form4->ADOConnection1->Connected =1;
	Form5->ADOConnection1->Connected =1;
}
//---------------------------------------------------------------------------

