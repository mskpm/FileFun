#include <iostream>
#include <fstream>
#include <string>				//function getline

using namespace std;

unique_ptr<string> odczyt_txt(const char* nazwa_pliku)
{
	if (nazwa_pliku == "")
	{
		nazwa_pliku = "tmp.txt";
	}

	if (fstream z_pliku{ nazwa_pliku, ios::in | ios::beg })
	{
		string linia;
		string co_jest_w_pliku;

		while (getline(z_pliku, linia))
		{
			co_jest_w_pliku.append(linia);
		}
		z_pliku.close();
		return make_unique<string>(co_jest_w_pliku);
	}
	else
	{
		cout << "Nie mo¿na otworzyæ pliku do czytania";
		return nullptr;
	}
}

unique_ptr<string> odczyt_bin(const char* nazwa_pliku)
{
	if (nazwa_pliku == "")
	{
		nazwa_pliku = "tmp.bin";
	}

	if (fstream z_pliku{ nazwa_pliku, ios::in | ios::binary })
	{
		int dlugosc_txt;
		string txt{};
		z_pliku.read((char*)&dlugosc_txt, sizeof(int));

		char* tab = new char[dlugosc_txt + 1]{};
		z_pliku.read(tab, dlugosc_txt);
		txt = tab;
		delete [] tab;
		if (!z_pliku)
		{
			cout << "Blad czytania tekstu z pliku " << nazwa_pliku;
		}

		z_pliku.close();
		return make_unique<string>(txt);
	}
	else
	{
		cout << "Nie mo¿na otworzyæ pliku " << nazwa_pliku << " do czytania";
		return nullptr;
	}
}