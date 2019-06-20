#include <iostream>
#include <fstream>
#include <string>				//function getline

using namespace std;

unique_ptr<string> odczyt_txt(const char* nazwa_pliku)
{
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
