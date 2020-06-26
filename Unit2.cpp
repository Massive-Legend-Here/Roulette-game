//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------

class Tezina{
public:
	int easy, normal, hard;

	Tezina(){
		easy = 0;
		normal = 0;
		hard = 0;
	}

	void odabir(int a){
		switch (a) {
			case 0:{ easy++; break; }
			case 1:{ normal++; break; }
			case 2:{ hard++; break; }
			default:break;
		}
	}

	getTezinaEasy(){
		 return easy  ;
	}

	getTezinaNormal(){
		 return normal  ;
	}

	getTezinaHard(){
		 return hard  ;
	}

};




__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{

}


//---------------------------------------------------------------------------
int tezinaEasy;
int tezinaNormal;
int tezinaHard;
void __fastcall TForm2::Button1Click(TObject *Sender)
{


	 Tezina tezina;
	 tezina.odabir(ComboBox1->ItemIndex);
	 tezina.odabir(ComboBox2->ItemIndex);
	 tezina.odabir(ComboBox3->ItemIndex);
	 tezina.odabir(ComboBox4->ItemIndex);
	 tezina.odabir(ComboBox5->ItemIndex);
	 tezina.odabir(ComboBox6->ItemIndex);

	tezinaEasy= tezina.easy;
	tezinaNormal= tezina.getTezinaNormal();
	tezinaHard =tezina.getTezinaHard();

	 //ShowMessage(tezina.easy);
	 //ShowMessage(tezina.normal);
	 //ShowMessage(tezina.hard);




      // Sleep(90000);
	Form4->Show();
	Form2->Hide();

}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action)
{
    Application->Terminate();
}
//---------------------------------------------------------------------------

int load =0;
void __fastcall TForm2::Button2Click(TObject *Sender)
{
 	  load=1;
	  //TForm4 *Form = new TForm4( this );
	 // Form->ShowModal();
	  Form2->Hide();
      Form4->Show();
}
//---------------------------------------------------------------------------

