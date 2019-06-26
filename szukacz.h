#pragma once
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template <typename T>
bool szukacz(istringstream& str, string etykieta, T& zmienna)
{
	string tr = str.str();
	size_t nr = tr.find(etykieta);

	if (nr == string::npos)
	{
		cout << "Blad wyszukiwania etykiety " << etykieta << endl;
		return false;
	}

	str.seekg(nr + etykieta.length());

	T wartosc;
	str >> wartosc;

	if (!str)
	{
		cout << "Blad wczytywania wartosci po etykiecie: " << etykieta << endl;
		return false;
	}
	else
	{
		zmienna = wartosc;
		return true;
	}
}