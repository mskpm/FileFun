#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

#include "odczytaj_z_pliku.h"


using namespace std;


bool zapis_all_txt(string* tekst, const char* nazwa_pliku)
{
	if (nazwa_pliku=="")
	{
		nazwa_pliku = "tmp.txt";
	}

	if (fstream do_pliku{ nazwa_pliku, ios::out })
	{
		do_pliku << *tekst;
		do_pliku.close();
		return true;
	}
	else
	{
		cout << "Nie mozna otworzyc pliku do pisania.";
		return false;
	}
	
	
}

//********************************************************************

bool zapis_1_param_txt(istringstream &source, const char* wzor)
{
	double var;
	string etykieta{ wzor };
	string nazwa_pliku{wzor};
	nazwa_pliku.append(".txt");
	vector<double> wartosci;
	ostringstream dane{};

	if (szukacz(source, etykieta, var))
	{
		wartosci.push_back(var);

		while (source >> var)
		{
			wartosci.push_back(var);
		}
	}
	else
	{
		cout << "Nie znaleziono: " << etykieta << endl;
		if (source.fail())
			source.clear(source.rdstate() & ~ios::failbit);
		if (source.eof())
			source.clear(source.rdstate() & ~ios::failbit);

		return false;
	}

	dane << etykieta << " ";
	for (size_t i = 0; i < wartosci.size(); i++)
	{
		dane << wartosci[i] << " ";
	}

	string dane_s = dane.str();
	zapis_all_txt(&dane_s, nazwa_pliku.c_str());


	if (source.fail())
		source.clear(source.rdstate() & ~ios::failbit);
	if (source.eof())
		source.clear(source.rdstate() & ~ios::failbit);
	return true;
}
//********************************************************************
bool zapis_all_bin(string* tekst, const char* nazwa_pliku)
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
		return true;
	}
	else
	{
		cout << "Nie mo¿na otworzyc pliku " << nazwa_pliku << " do zapisu";
		return false;
	}
}



