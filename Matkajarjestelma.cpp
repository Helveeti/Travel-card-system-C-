// Matkajarjestelma.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Matkakortti.h"
#include "Leimaaja.h"
#include "Yksittaislippu.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	Matkakortti kortti;
	Leimaaja leimaaja;
	Yksittaislippu lippu = Yksittaislippu(SEUTU);
	int v;
	string rivi;
	float raha;

	do
	{
		system("cls");
		cout <<"-------------------Matkakortin testausvalikko--------------------";
		cout <<"\n\n\n\n";
		cout << "\t\t\t\tAlusta matkakortti 1.\n";
		cout << "\t\t\t\tLataa matkakortti 2.\n";
		cout << "\t\t\t\tMatkusta Helsingissä 3.\n";
		cout << "\t\t\t\tMatkusta Seudulla 4.\n";
		cout << "\t\t\t\tTulosta kortin tiedot 5.\n";
		cout << "\t\t\t\tTulosta leimaajan tiedot 6.\n";
		cout << "\t\t\t\tLopeta 7.\n";
		cout << "\t\t\t\tTehtävä 12 esimerkki 8.\n";
		cout << "\t\t\t\tYksittäislippu SEUTU 9.\n";
		gotoxy(43,15);
		v=getIntFromStream();
		switch (v)
		{
			case 1:
				gotoxy(25, 17);
				cout << "Anna kortin omistajan nimi: ";
				getline(cin, rivi);
				kortti.alusta(rivi);
			break;
			case 2:
				gotoxy(30, 17);
				cout << "Anna lisättävä saldo: ";
				raha = getFloatFromStream();
				kortti.lataa(raha);
			break;
			case 3:
				gotoxy(25, 17);

				if (leimaaja << kortti) {
					gotoxy(25, 15);
					cout << "Maksu suoritettu. Hyvää matkaa!"; 
				}
				else {
					gotoxy(25, 15);
					cout << "Maksua ei pystytty suorittamaan.";
				}

				cin.get();
			break;
			case 4:       
				gotoxy(25, 17);

				if (leimaaja >> kortti) {
					gotoxy(25, 15);
					cout << "Maksu suoritettu. Hyvää matkaa!"; 
				}
				else {
					gotoxy(25, 15);
					cout << "Maksua ei pystytty suorittamaan.";
				}

				cin.get();
			break;
			case 5:       //
				gotoxy(30, 17);
				cout << kortti;
				cin.get();
			break;
			case 6:       //
				cout << leimaaja;
				cin.get();
			break;
			case 7:       //
				cout << "Ohjelma loptetetaan...";
				cin.get();
			break;
			case 8:       //
				gotoxy(25, 18);

				kortti.i = 5;
				kortti.j = 10;
				kortti.k = 15;

				cout << kortti.summa();

				cin.get();
				break;
			case 9:       //
				if (leimaaja >> lippu) {
					gotoxy(25, 18);
					cout << "Maksu suoritettu. Hyvää matkaa!";
				}
				else {
					gotoxy(25, 18);
					cout << "Maksua ei pystytty suorittamaan.";
				}

				cin.get();
				break;
						
		}
	}
	while (v!=7);
	return 0;
}



