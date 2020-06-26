//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit4.h"
#include "Unit5.h"
#include "pocetna.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5 *Form5;
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

//prosljedit iznose igraca na kraju igre, te ih tako poredati
void __fastcall TForm5::Button2Click(TObject *Sender)
{
	Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TForm5::FormClose(TObject *Sender, TCloseAction &Action)
{
    Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Button1Click(TObject *Sender)
{
	Form1->Show();
	Form5->Hide();
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

