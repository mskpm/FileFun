#include <iostream>
#include <fstream>
using namespace std;


void zapis_txt(string* tekst, const char* nazwa_pliku )
{
	if (nazwa_pliku=="")
	{
		nazwa_pliku = "tmp.txt";
	}

	if (fstream do_pliku{ nazwa_pliku, ios::out })
	{
		do_pliku << *tekst;
		do_pliku.close();
	}
	else
	{
		cout << "Nie mozna otworzyc pliku do pisania.";
	}
}

void zapis_bin(string* tekst, const char* nazwa_pliku)
{
	if (nazwa_pliku=="")
	{
		nazwa_pliku = "tmp.bin";
	}

	if (fstream do_pliku{ nazwa_pliku, ios::out | ios::binary })
	{
		string txt{ *tekst };
		int dlugosc_txt = txt.size();
		do_pliku.write((char*) &dlugosc_txt, sizeof(int));
		do_pliku.write((char*) txt.data(), sizeof(char)*dlugosc_txt);
		if (!do_pliku)
		{
			cout << "Blad w pisaniu do pliku " << nazwa_pliku;
		}

		do_pliku.close();
	}
	else
	{
		cout << "Nie mo¿na otworzyc pliku " << nazwa_pliku << " do zapisu";
	}
}
