#include <iostream>
#include <fstream>
#include <string>				//function getline
#include <sstream>
#include <vector>

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

//********************************************************************

vector<double> odczyt_bin(const char* nazwa_pliku, string etykieta)
{
	if (nazwa_pliku == "")
	{
		nazwa_pliku = "tmp.bin";
	}

	vector<double> wartosci;
	double tmp = 0;
	
	if (fstream z_pliku{ nazwa_pliku, ios::in | ios::binary })
	{
		while (z_pliku)
		{
			z_pliku.read((char*)& tmp, sizeof(double));
			wartosci.push_back(tmp);
		}
	

		z_pliku.close();
		/*cout << wartosci[0] << endl;
		cout << wartosci[1] << endl;
		cout << wartosci[2] << endl;*/
		
		return wartosci;
	}
	else
	{
		cout << "Nie mo¿na otworzyæ pliku " << nazwa_pliku << " do czytania";
		exit(-1);
	}
}

//********************************************************************
