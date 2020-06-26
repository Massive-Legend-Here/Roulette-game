//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
#include "Unit2.h"
#include "Unit5.h"
#include "popis.h"
#include <vector>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <time.h>
using namespace std;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
HINSTANCE RouletteBrojevi;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
}
//--------------------------------------------------------------------------
 extern "C" int __declspec(dllexport) __stdcall DLL_igraci_poziv();
 extern "C" int __declspec(dllexport) __stdcall DLL_ulozi_poziv();


 //napraviti fiju koja poziva playere s unit2 i inicijalizira svakoga za odabranu tezinu
class Player{
public:
	//tezina je int od 0-3, nula je igrac, 1 je easy, dva je normal, 3 je hard
	int iznos, tezina;
	Player(int _tezina){
		switch(_tezina){
			case 0:
				tezina=_tezina;
				iznos=100;
				break;
			case 1:
				tezina=_tezina;
				iznos=80;
				break;
			case 2:
				tezina=_tezina;
				iznos=100;
				break;
			case 3:
				tezina=_tezina;
				iznos=120;
				break;
			default:
			tezina=_tezina;
				iznos=0;
				break;
		}
	}

	void setIznos(int _ulog){
		if(iznos>= _ulog){iznos=iznos - _ulog;}
		else iznos=iznos;
	}

	int getIznos(){
		return iznos;
	}

	void setXMLpocetak(int pocetak){
		  iznos=pocetak;
	}

	void setDobitak(int dobitak, int kofa){
		iznos += dobitak*kofa;
	}

};





class Chip{
private:
	int odabrani_chip;
public:
	Chip(){	odabrani_chip=0;}

	Chip(int a){
	   odabrani_chip= a;
	}
	void setOdabir(int odabir){
		odabrani_chip=odabir;
	}
	int getOdabir(){
		return odabrani_chip;
	}
};

class Array_ulog_broj{
public:
	static const int dimenzija = 48;
	int array[dimenzija];


	Array_ulog_broj() {}
	//pozivamo na kraju runde kad se vidi jesmo li dobili il ne
	//switch statement 0-48 sto odgovara poljima i onda na svakom se poziva
	//funkcija ispod, a on odgovara broju switch statementu..
	//za brojeve posebno, a za "igre" posebno
	int getArray_ulog_broj(int broj) const
	{
		if((0 <= broj) && (dimenzija > broj)){
			return array[broj];
		}
		else return 0;
	}
	 //rand fija za playere koja poziva fiju ispod
	void setArray_ulog_broj(int broj, int ulog)
	{
		if((0 <= broj) && (dimenzija > broj))
			array[broj] += ulog;
	}
	   //kad se stisne na novu rundu" onda se poziva reset array za svaki objekt od arraya
	void resetArray_ulog_broj(){
		for(int i=0; i <= dimenzija; i++){
			array[i]=0;
		}
	}

	~Array_ulog_broj() {}
};


//inicijaliziramo klasu chip, klasu igrac(mi kao igrac), array koji povezuje ulog sa brojem polja,


Chip chip;

vector <Player> igraci;
vector <Array_ulog_broj> polje;





//------------------------------------------------------------------

//funkcija koja postavlja vrijednosti za chip
void chip_click(int chip_vrijednost){

	chip.setOdabir(chip_vrijednost);
	//ShowMessage(chip_vrijednost);
}
//-------------------------------------------------------------------




int randomulog(int i){
	int ulozi =  DLL_ulozi_poziv();
	int polje1;
		if(igraci[i].getIznos()>= ulozi){
			polje1 = rand() % 49;
			igraci[i].setIznos(ulozi);
			polje[i].setArray_ulog_broj(polje1, ulozi);
		}
	return polje1;
 }


//brojevi od 0-36, ostalo su parni, neparni....
void ulog_click(int broj_uloga){
	 if (multi == 1) {
         srand(rand());
			vector<int> broj_polja_na_kojem_je_ulog;

			if(igraci[0].getIznos()>=chip.getOdabir()){
				igraci[0].setIznos(chip.getOdabir());
				polje[0].setArray_ulog_broj(broj_uloga, chip.getOdabir());
				broj_polja_na_kojem_je_ulog.push_back(broj_uloga);
			}

			UnicodeString abcd = "P: " + String(broj_polja_na_kojem_je_ulog[0]) + "- U: " + String(polje[0].getArray_ulog_broj(broj_uloga));
            Form4->Label1->Caption = igraci[0].getIznos();
			Form4->Label29->Caption = abcd;

		 Form4->ChatClient->Host = IP_adresa;

		Form4->ChatClient->Connect();
		UnicodeString poruka = "#" + Form4->Label32->Caption;
		Form4->ChatClient->Socket->Write(poruka.Length());
		Form4->ChatClient->Socket->Write(poruka);
		Form4->ChatClient->Disconnect();
		poruka ="";

		Form4->ChatClient->Host = IP_adresa;
		Form4->ChatClient->Connect();
		poruka = "$" + Form4->Label1->Caption;
		Form4->ChatClient->Socket->Write(poruka.Length());
		Form4->ChatClient->Socket->Write(poruka);
		Form4->ChatClient->Disconnect();
		poruka ="";

        Form4->ChatClient->Host = IP_adresa;
		Form4->ChatClient->Connect();
		poruka = "%" + Form4->Label29->Caption;
		Form4->ChatClient->Socket->Write(poruka.Length());
		Form4->ChatClient->Socket->Write(poruka);
		Form4->ChatClient->Disconnect();
        poruka ="";

	 }
	 else{
	//predaje ulog u array, te ga array zbraja -----------------------
	//oduzima ulog sa broja, te oduzima uloga sa iznosa---------------
	//for(i//i je za igrace)
			srand(rand());
			vector<int> broj_polja_na_kojem_je_ulog;

			if(igraci[0].getIznos()>=chip.getOdabir()){
				igraci[0].setIznos(chip.getOdabir());
				polje[0].setArray_ulog_broj(broj_uloga, chip.getOdabir());
				broj_polja_na_kojem_je_ulog.push_back(broj_uloga);
			}


			//setarray
			for(int i =1;i <= igraci.size();i++){
				int zasto_neradi = randomulog(i);
				broj_polja_na_kojem_je_ulog.push_back(zasto_neradi);
			}


				for(int i =0;i <= igraci.size();i++){
					UnicodeString abc;
				   if(igraci[i].getIznos()>= 0){
						abc = "P: " + String(broj_polja_na_kojem_je_ulog[i]) + "- U: " + String(polje[i].getArray_ulog_broj(broj_polja_na_kojem_je_ulog[i]));
				   }

						UnicodeString abcd = "P: " + String(broj_polja_na_kojem_je_ulog[i]) + "- U: " + String(polje[i].getArray_ulog_broj(broj_uloga));
						switch(i){
						case 0:
							Form4->Label1->Caption = igraci[0].getIznos();
							Form4->Label29->Caption = abcd;
							break;
						case 1:
							Form4->Label3->Caption = igraci[1].getIznos();
							Form4->Label22->Caption = abc;
							break;
						case 2:
							Form4->Label5->Caption = igraci[2].getIznos();
							Form4->Label23->Caption = abc;
							break;
						case 3:
							Form4->Label10->Caption = igraci[3].getIznos();
							Form4->Label24->Caption = abc;
							break;
						case 4:
							Form4->Label11->Caption = igraci[4].getIznos();
							Form4->Label25->Caption = abc;
							break;
						case 5:
							Form4->Label12->Caption = igraci[5].getIznos();
							Form4->Label26->Caption = abc;
							break;
						case 6:
							Form4->Label13->Caption = igraci[6].getIznos();
							Form4->Label27->Caption = abc;
							break;
						default:
							break;
						}



				}
	 }


}

void kraj_runde2(int bacanje3){

   if (bacanje3 == 123456) {

	if(multi == 0){
				srand(time(NULL));
			 int  broj_win =   DLL_igraci_poziv();

			Form4->Label14->Caption = broj_win;

			for(int i=0; i<igraci.size();i++){
					int koeficijent;
				   if (polje[i].array[broj_win] > 0) {
						koeficijent = 36;
						//setDobitak(int dobitak, int kofa)
						igraci[i].setDobitak(polje[i].array[broj_win], koeficijent);
					   //tu vidimo dali je dobitni od 1-36
					   // verijabla j je za ostale, kao even i oodd
					  // provjeri_dobitak(broj_win, i, j);
				   }


				   for(int k=37; k <= 49;k++){

						switch(k){
							 case 37:
								koeficijent = 3;
									if (((broj_win+2)%3)==0 ) {
									igraci[i].setDobitak(polje[i].array[37], koeficijent);
									//ShowMessage(polje[i].array[37]);
									}
								break;

							 case 38:
								koeficijent = 3;
									if (((broj_win+1)%3)==0 ) {
									igraci[i].setDobitak(polje[i].array[38], koeficijent);
									}
								break;

							 case 39:
								koeficijent = 3;
									if ((broj_win%3)==0 ) {
									igraci[i].setDobitak(polje[i].array[39], koeficijent);
									}
								break;

								case 40:
								koeficijent = 3;
									if ((broj_win > 0) && (broj_win < 13) ) {
									igraci[i].setDobitak(polje[i].array[40], koeficijent);
									//ShowMessage(polje[i].array[37]);
									}
								break;

							 case 41:
								koeficijent = 3;
									if ((broj_win > 12) && (broj_win < 25) ) {
									igraci[i].setDobitak(polje[i].array[41], koeficijent);
									}
								break;

							 case 42:
								koeficijent = 3;
									if ((broj_win > 24) && (broj_win < 37) ) {
									igraci[i].setDobitak(polje[i].array[42], koeficijent);
									}
								break;

								case 43:
								koeficijent = 2;
									if ((broj_win > 0) && (broj_win < 19) ) {
									igraci[i].setDobitak(polje[i].array[43], koeficijent);
									}
								break;

								case 44:
								koeficijent = 2;
									if ((broj_win%2)==0 ) {
									igraci[i].setDobitak(polje[i].array[44], koeficijent);
									}
								break;

								case 45:
								koeficijent = 2;
									if (broj_win==2 || broj_win==4 || broj_win==6 || broj_win==8 || broj_win==10 || broj_win==11 || broj_win==13 || broj_win==15 || broj_win==17 || broj_win==20 || broj_win==22 || broj_win==24 || broj_win==26 || broj_win==28 || broj_win==29 || broj_win==31 || broj_win==33 ||  broj_win==35) {
									igraci[i].setDobitak(polje[i].array[45], koeficijent);
									}
								break;

								case 46:
								koeficijent = 2;
									if (broj_win==1 || broj_win==3 || broj_win==5 || broj_win==7 || broj_win==9 || broj_win==12 || broj_win==14 || broj_win==16 || broj_win==18 || broj_win==19 || broj_win==21 || broj_win==23 || broj_win==25 || broj_win==27 || broj_win==30 || broj_win==32 || broj_win==34 ||  broj_win==36) {
									igraci[i].setDobitak(polje[i].array[46], koeficijent);
									}
								break;

								case 47:
								koeficijent = 2;
									if (((broj_win +1 )%2)==0 ) {
									igraci[i].setDobitak(polje[i].array[47], koeficijent);
									}
								break;

								case 48:
								koeficijent = 2;
									if ((broj_win > 18) && (broj_win < 37) ) {
									igraci[i].setDobitak(polje[i].array[48], koeficijent);
									}
								break;

							 default:
								break;





						}

				   }

			}


			for(int i =0;i<=igraci.size();i++){

					   UnicodeString abc = "";
					switch(i){
							case 0:
								Form4->Label1->Caption = igraci[0].getIznos();
								Form4->Label29->Caption = abc;
								break;
							case 1:
								Form4->Label3->Caption = igraci[1].getIznos();
								Form4->Label22->Caption = abc;
								break;
							case 2:
								Form4->Label5->Caption = igraci[2].getIznos();
								Form4->Label23->Caption = abc;
								break;
							case 3:
								Form4->Label10->Caption = igraci[3].getIznos();
								Form4->Label24->Caption = abc;
								break;
							case 4:
								Form4->Label11->Caption = igraci[4].getIznos();
								Form4->Label25->Caption = abc;
								break;
							case 5:
								Form4->Label12->Caption = igraci[5].getIznos();
								Form4->Label26->Caption = abc;
								break;
							case 6:
								Form4->Label13->Caption = igraci[6].getIznos();
								Form4->Label27->Caption = abc;
								break;
							default:
								break;
							}

			}

			for(int i =0;i<=polje.size();i++){
			polje[i].resetArray_ulog_broj();
			}
	}
    //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
   //ovo dolje je za mp kad mi pozivamo
   //----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

	else{
			srand(time(NULL));
			int  broj_win =   DLL_igraci_poziv();
		 //saljemo dobitni broj
		Form4->ChatClient->Host = IP_adresa;
		Form4->ChatClient->Connect();
		UnicodeString poruka = "*" + broj_win;
		Form4->ChatClient->Socket->Write(poruka.Length());
		Form4->ChatClient->Socket->Write(poruka);
		Form4->ChatClient->Disconnect();
        poruka ="";


			Form4->Label14->Caption = broj_win;

			for(int i=0; i<1;i++){
					int koeficijent;
				   if (polje[i].array[broj_win] > 0) {
						koeficijent = 36;
						//setDobitak(int dobitak, int kofa)
						igraci[0].setDobitak(polje[0].array[broj_win], koeficijent);
					   //tu vidimo dali je dobitni od 1-36
					   // verijabla j je za ostale, kao even i oodd
					  // provjeri_dobitak(broj_win, i, j);
				   }


				   for(int k=37; k <= 49;k++){

						switch(k){
							 case 37:
								koeficijent = 3;
									if (((broj_win+2)%3)==0 ) {
									igraci[i].setDobitak(polje[i].array[37], koeficijent);
									//ShowMessage(polje[i].array[37]);
									}
								break;

							 case 38:
								koeficijent = 3;
									if (((broj_win+1)%3)==0 ) {
									igraci[i].setDobitak(polje[i].array[38], koeficijent);
									}
								break;

							 case 39:
								koeficijent = 3;
									if ((broj_win%3)==0 ) {
									igraci[i].setDobitak(polje[i].array[39], koeficijent);
									}
								break;

								case 40:
								koeficijent = 3;
									if ((broj_win > 0) && (broj_win < 13) ) {
									igraci[i].setDobitak(polje[i].array[40], koeficijent);
									//ShowMessage(polje[i].array[37]);
									}
								break;

							 case 41:
								koeficijent = 3;
									if ((broj_win > 12) && (broj_win < 25) ) {
									igraci[i].setDobitak(polje[i].array[41], koeficijent);
									}
								break;

							 case 42:
								koeficijent = 3;
									if ((broj_win > 24) && (broj_win < 37) ) {
									igraci[i].setDobitak(polje[i].array[42], koeficijent);
									}
								break;

								case 43:
								koeficijent = 2;
									if ((broj_win > 0) && (broj_win < 19) ) {
									igraci[i].setDobitak(polje[i].array[43], koeficijent);
									}
								break;

								case 44:
								koeficijent = 2;
									if ((broj_win%2)==0 ) {
									igraci[i].setDobitak(polje[i].array[44], koeficijent);
									}
								break;

								case 45:
								koeficijent = 2;
									if (broj_win==2 || broj_win==4 || broj_win==6 || broj_win==8 || broj_win==10 || broj_win==11 || broj_win==13 || broj_win==15 || broj_win==17 || broj_win==20 || broj_win==22 || broj_win==24 || broj_win==26 || broj_win==28 || broj_win==29 || broj_win==31 || broj_win==33 ||  broj_win==35) {
									igraci[i].setDobitak(polje[i].array[45], koeficijent);
									}
								break;

								case 46:
								koeficijent = 2;
									if (broj_win==1 || broj_win==3 || broj_win==5 || broj_win==7 || broj_win==9 || broj_win==12 || broj_win==14 || broj_win==16 || broj_win==18 || broj_win==19 || broj_win==21 || broj_win==23 || broj_win==25 || broj_win==27 || broj_win==30 || broj_win==32 || broj_win==34 ||  broj_win==36) {
									igraci[i].setDobitak(polje[i].array[46], koeficijent);
									}
								break;

								case 47:
								koeficijent = 2;
									if (((broj_win +1 )%2)==0 ) {
									igraci[i].setDobitak(polje[i].array[47], koeficijent);
									}
								break;

								case 48:
								koeficijent = 2;
									if ((broj_win > 18) && (broj_win < 37) ) {
									igraci[i].setDobitak(polje[i].array[48], koeficijent);
									}
								break;

							 default:
								break;





						}

				   }

			}


			for(int i =0;i<=igraci.size();i++){

					   UnicodeString abc = "";
					switch(i){
							case 0:
								Form4->Label1->Caption = igraci[0].getIznos();
								Form4->Label29->Caption = abc;
								break;
							default:
								break;
							}

			}

		Form4->ChatClient->Host = IP_adresa;
		Form4->ChatClient->Connect();
		poruka = "#" + Form4->Label32->Caption;
		Form4->ChatClient->Socket->Write(poruka.Length());
		Form4->ChatClient->Socket->Write(poruka);
		Form4->ChatClient->Disconnect();
		poruka ="";

		Form4->ChatClient->Host = IP_adresa;
		Form4->ChatClient->Connect();
		poruka = "$" + Form4->Label1->Caption;
		Form4->ChatClient->Socket->Write(poruka.Length());
		Form4->ChatClient->Socket->Write(poruka);
		Form4->ChatClient->Disconnect();
		poruka ="";

        Form4->ChatClient->Host = IP_adresa;
		Form4->ChatClient->Connect();
		poruka = "%" + Form4->Label29->Caption;
		Form4->ChatClient->Socket->Write(poruka.Length());
		Form4->ChatClient->Socket->Write(poruka);
		Form4->ChatClient->Disconnect();
        poruka ="";

			for(int i =0;i<=polje.size();i++){
			polje[i].resetArray_ulog_broj();
			}



	}

   }

   //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
   //ovo dolje je za mp server kada dobivamo
   //----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

   else{
       		srand(time(NULL));
			 int  broj_win = bacanje3;

			Form4->Label14->Caption = broj_win;

			for(int i=0; i<igraci.size();i++){
					int koeficijent;
				   if (polje[i].array[broj_win] > 0) {
						koeficijent = 36;
						//setDobitak(int dobitak, int kofa)
						igraci[i].setDobitak(polje[i].array[broj_win], koeficijent);
					   //tu vidimo dali je dobitni od 1-36
					   // verijabla j je za ostale, kao even i oodd
					  // provjeri_dobitak(broj_win, i, j);
				   }


				   for(int k=37; k <= 49;k++){

						switch(k){
							 case 37:
								koeficijent = 3;
									if (((broj_win+2)%3)==0 ) {
									igraci[i].setDobitak(polje[i].array[37], koeficijent);
									//ShowMessage(polje[i].array[37]);
									}
								break;

							 case 38:
								koeficijent = 3;
									if (((broj_win+1)%3)==0 ) {
									igraci[i].setDobitak(polje[i].array[38], koeficijent);
									}
								break;

							 case 39:
								koeficijent = 3;
									if ((broj_win%3)==0 ) {
									igraci[i].setDobitak(polje[i].array[39], koeficijent);
									}
								break;

								case 40:
								koeficijent = 3;
									if ((broj_win > 0) && (broj_win < 13) ) {
									igraci[i].setDobitak(polje[i].array[40], koeficijent);
									//ShowMessage(polje[i].array[37]);
									}
								break;

							 case 41:
								koeficijent = 3;
									if ((broj_win > 12) && (broj_win < 25) ) {
									igraci[i].setDobitak(polje[i].array[41], koeficijent);
									}
								break;

							 case 42:
								koeficijent = 3;
									if ((broj_win > 24) && (broj_win < 37) ) {
									igraci[i].setDobitak(polje[i].array[42], koeficijent);
									}
								break;

								case 43:
								koeficijent = 2;
									if ((broj_win > 0) && (broj_win < 19) ) {
									igraci[i].setDobitak(polje[i].array[43], koeficijent);
									}
								break;

								case 44:
								koeficijent = 2;
									if ((broj_win%2)==0 ) {
									igraci[i].setDobitak(polje[i].array[44], koeficijent);
									}
								break;

								case 45:
								koeficijent = 2;
									if (broj_win==2 || broj_win==4 || broj_win==6 || broj_win==8 || broj_win==10 || broj_win==11 || broj_win==13 || broj_win==15 || broj_win==17 || broj_win==20 || broj_win==22 || broj_win==24 || broj_win==26 || broj_win==28 || broj_win==29 || broj_win==31 || broj_win==33 ||  broj_win==35) {
									igraci[i].setDobitak(polje[i].array[45], koeficijent);
									}
								break;

								case 46:
								koeficijent = 2;
									if (broj_win==1 || broj_win==3 || broj_win==5 || broj_win==7 || broj_win==9 || broj_win==12 || broj_win==14 || broj_win==16 || broj_win==18 || broj_win==19 || broj_win==21 || broj_win==23 || broj_win==25 || broj_win==27 || broj_win==30 || broj_win==32 || broj_win==34 ||  broj_win==36) {
									igraci[i].setDobitak(polje[i].array[46], koeficijent);
									}
								break;

								case 47:
								koeficijent = 2;
									if (((broj_win +1 )%2)==0 ) {
									igraci[i].setDobitak(polje[i].array[47], koeficijent);
									}
								break;

								case 48:
								koeficijent = 2;
									if ((broj_win > 18) && (broj_win < 37) ) {
									igraci[i].setDobitak(polje[i].array[48], koeficijent);
									}
								break;

							 default:
								break;





						}

				   }

			}


			for(int i =0;i<=igraci.size();i++){

					   UnicodeString abc = "";
					switch(i){
							case 0:
								Form4->Label1->Caption = igraci[0].getIznos();
								Form4->Label29->Caption = abc;
								break;
							case 1:
								Form4->Label3->Caption = igraci[1].getIznos();
								Form4->Label22->Caption = abc;
								break;
							case 2:
								Form4->Label5->Caption = igraci[2].getIznos();
								Form4->Label23->Caption = abc;
								break;
							case 3:
								Form4->Label10->Caption = igraci[3].getIznos();
								Form4->Label24->Caption = abc;
								break;
							case 4:
								Form4->Label11->Caption = igraci[4].getIznos();
								Form4->Label25->Caption = abc;
								break;
							case 5:
								Form4->Label12->Caption = igraci[5].getIznos();
								Form4->Label26->Caption = abc;
								break;
							case 6:
								Form4->Label13->Caption = igraci[6].getIznos();
								Form4->Label27->Caption = abc;
								break;
							default:
								break;
							}

			}

			for(int i =0;i<=polje.size();i++){
			polje[i].resetArray_ulog_broj();
			}
   }

}

void __fastcall TForm4::kraj_rundeClick(TObject *Sender)
{
	kraj_runde2(123456);

}
//---------------------------------------------------------------------------


//postavlja sve uloge na nula pri otvaranju aplikacije
 void __fastcall TForm4::FormCreate(TObject *Sender)
{
//ovo je isto i za kraj runde
   //	for(int i =0;i<=polje.size();i++){
   //	polje[i].resetArray_ulog_broj();
   //	}



}
//---------------------------------------------------------------------------

void mp_ostali_korisnici()
{

	  Form4->Label34->Visible = 0;
	  Form4->Label33->Visible = 0;
	  Form4->Label31->Visible = 0;
	  Form4->Label30->Visible = 0;
	  Form4->Label15->Visible = 0;

	  Form4->Igrac2_slika->Visible = 0;
	  Form4->Igrac3_slika->Visible = 0;
	  Form4->Igrac4_slika->Visible = 0;
	  Form4->Igrac5_slika->Visible = 0;
	  Form4->Igrac6_slika->Visible = 0;

	  Form4->Label4->Visible = 0;
	  Form4->Label6->Visible = 0;
	  Form4->Label7->Visible = 0;
	  Form4->Label8->Visible = 0;
	  Form4->Label9->Visible = 0;

	  Form4->Label13->Visible = 0;
	  Form4->Label12->Visible = 0;
	  Form4->Label11->Visible = 0;
	  Form4->Label10->Visible = 0;
	  Form4->Label5->Visible = 0;

	  Form4->Label17->Visible = 0;
	  Form4->Label18->Visible = 0;
	  Form4->Label19->Visible = 0;
	  Form4->Label20->Visible = 0;
	  Form4->Label21->Visible = 0;

	  Form4->Label23->Visible = 0;
	  Form4->Label24->Visible = 0;
	  Form4->Label25->Visible = 0;
	  Form4->Label26->Visible = 0;
	  Form4->Label27->Visible = 0;

	  Form4->Button2->Visible = 0;



}

void __fastcall TForm4::FormClose(TObject *Sender, TCloseAction &Action)
{
    Application->Terminate();
}
//---------------------------------------------------------------------------

 //sprema korisnicka imena u  vektor
vector <UnicodeString> korisnici;

void __fastcall TForm4::FormShow(TObject *Sender){
  if (multi == 0) {
  		Form4->Width = 866;

	   if (load == 0) {
			igraci.push_back(Player(0));
			polje.push_back(Array_ulog_broj());
			for(int i=0;i < tezinaEasy;i++){
				igraci.push_back(Player(1));
				polje.push_back(Array_ulog_broj());
			}

			for(int i=0;i < tezinaNormal;i++){
				igraci.push_back(Player(2));
				polje.push_back(Array_ulog_broj());
			}

			for(int i=0;i < tezinaHard;i++){
			   igraci.push_back(Player(3));
			   polje.push_back(Array_ulog_broj());
			}
	   }

	   else{

			_di_IXMLPlayeriType igraci_xml =  GetPlayeri(XMLDocument1);
			for(int i = 0; i< 7;i++){
				 igraci.push_back(0);
				polje.push_back(Array_ulog_broj());
				igraci[i].setXMLpocetak(igraci_xml->Players[i]->Get_iznos());
			}


	   }

	Form4->Label1->Caption = igraci[0].getIznos();
   Form4->Label3->Caption = igraci[1].getIznos();
   Form4->Label5->Caption = igraci[2].getIznos();
   Form4->Label10->Caption = igraci[3].getIznos();
   Form4->Label11->Caption = igraci[4].getIznos();
   Form4->Label12->Caption = igraci[5].getIznos();
   Form4->Label13->Caption = igraci[6].getIznos();
  }

  else{

        ChatClient->Host = IP_adresa;
		ChatClient->Connect();
		UnicodeString poruka = "*" + korisnicko_ime_server;
		ChatClient->Socket->Write(poruka.Length());
		ChatClient->Socket->Write(poruka);
		ChatClient->Disconnect();
		mp_ostali_korisnici();
        poruka ="";

	  for(int i=0;i < 7;i++){
		igraci.push_back(Player(0));
		polje.push_back(Array_ulog_broj());
	  }

		Form4->Label1->Caption = igraci[0].getIznos();
		Form4->Label32->Caption = korisnicko_ime;

		for(int i=0;i < korisnici.size();i++){
		//korisnici.push_back(ono sta dobijem od servera)
		}


  }






   for(int i =0;i<=polje.size();i++){
	polje[i].resetArray_ulog_broj();
   }
}

//---------------------------------------------------------------------------









void __fastcall TForm4::Ulog_0Click(TObject *Sender)
{
   ulog_click(0);

}
//---------------------------------------------------------------------------

void __fastcall TForm4::Ulog_1Click(TObject *Sender)
{
	ulog_click(1);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Ulog_2Click(TObject *Sender)
{
   ulog_click(2);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Ulog_3Click(TObject *Sender)
{
   ulog_click(3);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Ulog_4Click(TObject *Sender)
{
	ulog_click(4);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Ulog_5Click(TObject *Sender)
{
	ulog_click(5);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Ulog_6Click(TObject *Sender)
{
	ulog_click(6);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Ulog_7Click(TObject *Sender)
{
	ulog_click(7);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Ulog_8Click(TObject *Sender)
{
	ulog_click(8);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Ulog_9Click(TObject *Sender)
{
   ulog_click(9);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Ulog_10Click(TObject *Sender)
{
   ulog_click(10);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Ulog_11Click(TObject *Sender)
{
	ulog_click(11);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Ulog_12Click(TObject *Sender)
{
   ulog_click(12);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Ulog_13Click(TObject *Sender)
{
	ulog_click(13);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Ulog_14Click(TObject *Sender)
{
	ulog_click(14);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Ulog_15Click(TObject *Sender)
{
	 ulog_click(15);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Ulog_16Click(TObject *Sender)
{
   ulog_click(16);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Ulog_17Click(TObject *Sender)
{
   ulog_click(17);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Ulog_18Click(TObject *Sender)
{
   ulog_click(18);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Ulog_19Click(TObject *Sender)
{
   ulog_click(19);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Ulog_20Click(TObject *Sender)
{
	ulog_click(20);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Ulog_21Click(TObject *Sender)
{
	ulog_click(21);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Ulog_22Click(TObject *Sender)
{
	ulog_click(22);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Ulog_23Click(TObject *Sender)
{
	ulog_click(23);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Ulog_24Click(TObject *Sender)
{
	ulog_click(24);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Ulog_25Click(TObject *Sender)
{
	  ulog_click(25);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Ulog_26Click(TObject *Sender)
{
	ulog_click(26);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Ulog_27Click(TObject *Sender)
{
	 ulog_click(27);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Ulog_28Click(TObject *Sender)
{
	 ulog_click(28);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Ulog_29Click(TObject *Sender)
{
	  ulog_click(29);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Ulog_30Click(TObject *Sender)
{
	ulog_click(30);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Ulog_31Click(TObject *Sender)
{
	  ulog_click(31);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Ulog_32Click(TObject *Sender)
{
	  ulog_click(32);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Ulog_33Click(TObject *Sender)
{
	  ulog_click(33);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Ulog_34Click(TObject *Sender)
{
	ulog_click(34);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Ulog_35Click(TObject *Sender)
{
   ulog_click(35);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Ulog_36Click(TObject *Sender)
{
   ulog_click(36);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Ulog_1_34Click(TObject *Sender)
{
	ulog_click(37);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Ulog_2_35Click(TObject *Sender)
{
	ulog_click(38);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Ulog_3_36Click(TObject *Sender)
{
	ulog_click(39);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Ulog_prvih_12Click(TObject *Sender)
{
	  ulog_click(40);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Ulog_drugih_12Click(TObject *Sender)
{
	 ulog_click(41);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Ulog_trecih_12Click(TObject *Sender)
{
	 ulog_click(42);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Ulog_1_do_18Click(TObject *Sender)
{
	ulog_click(43);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Ulog_parniClick(TObject *Sender)
{
	  ulog_click(44);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Ulog_crniClick(TObject *Sender)
{
	  ulog_click(45);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Ulog_crveniClick(TObject *Sender)
{
	 ulog_click(46);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Ulog_neparniClick(TObject *Sender)
{
	ulog_click(47);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Ulog_19_do_36Click(TObject *Sender)
{
	ulog_click(48);
}



//---------------------------------------------------------------------------
//
//
//
//
//----------------------------------------------------------------------------



void __fastcall TForm4::Chip_1Click(TObject *Sender)
{
	chip_click(1);
}
//---------------------------------------------------------------------------


void __fastcall TForm4::Chip_2Click(TObject *Sender)
{
	chip_click(2);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Spremi_igru(TObject *Sender)
{
	chip_click(5);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Prekid_igre(TObject *Sender)
{
   vector <int> a;
    for(int i = 0; i<igraci.size();i++){

		THighscore->Insert();

		a.push_back(igraci[i].getIznos());
		THighscore->FieldByName("Highscore")->AsInteger = a[i];
	    korisnici.push_back(i);
		THighscore->FieldByName("Ime")->AsString = "Igrač "+ korisnici[i];


		THighscore->Post();

	}

	Form5->Show();
	Form4->Hide();
}
//---------------------------------------------------------------------------


  //ovo je za spremit igru
void __fastcall TForm4::Button2Click(TObject *Sender)
{
    _di_IXMLPlayeriType igraci_xml =  GetPlayeri(XMLDocument1);
		for(int i = 0; i< 7;i++){
           igraci_xml->Players[i]->Set_iznos(igraci[i].getIznos());
		}
	  XMLDocument1->SaveToFile(XMLDocument1->FileName);
}
//---------------------------------------------------------------------------


void __fastcall TForm4::Button3Click(TObject *Sender)
{

	ChatClient->Host = IP_adresa;
	ChatClient->Connect();
	UnicodeString poruka = "  User - " + korisnicko_ime + ": " + EMessage->Text;
   // UnicodeString poruka = EMessage->Text;
	ChatClient->Socket->Write(poruka.Length());
	ChatClient->Socket->Write(poruka);
	LMessage->Items->Add(poruka);
	ChatClient->Disconnect();
	poruka ="";
}
//---------------------------------------------------------------------------


void __fastcall TForm4::ChatServerExecute(TIdContext *AContext)
{
	int length = AContext->Connection->Socket->ReadLongInt();
	UnicodeString Message = AContext->Connection->Socket->ReadString(length);
	AContext->Connection->Disconnect();

	 if(Message[1] == L'#'){
		//prima ime korisnika
	   UnicodeString korisnik1 = Message.Delete(1,1);
	   Form4->Label35->Caption = korisnik1;
	 }
	 else if(Message[1] == L'$'){
		//prima iznos od korisnika
	   UnicodeString korisnik1 = Message.Delete(1,1);
	   Form4->Label3->Caption = korisnik1;
	 }
	 else if(Message[1] == L'*'){
		//prima broj na koji je pala kuglica u ruletu
	   UnicodeString korisnik1 = Message.Delete(1,1);
	  int broj_bacanja = korisnik1.ToInt();
      kraj_runde2(broj_bacanja);
	 }
	 else if(Message[1] == L'%'){
		//prima ulog od korisnika
	   UnicodeString ulog1 = Message.Delete(1,1);
	   Form4->Label22->Caption = ulog1;
	 }
	 else{
	   UnicodeString ZastoNeradi2 = Message.Delete(1,1);
	   Form4->LMessage->Items->Add(ZastoNeradi2);
	 }

	 /*
      else if(Message.FirstChar() == "?"){
	   UnicodeString string_server = Message.TrimLeft();
	   Form4->Label3->Caption = string_server;
	 }
     */


}
//---------------------------------------------------------------------------

