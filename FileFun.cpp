// FileFun.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include "zapisz_do_pliku.h"
#include "odczytaj_z_pliku.h"

using namespace std;

int main()
{
	string txt{ "In Visual Studio, you can create a New Project (or open an existing one).\n"
		"All installed libraries are immediately ready to be " 
		"`#include`'d and used in your project without additional configuration."};
		
	istringstream nastawy(
				R"(nastawa1 3
				wzmocnienie 3 5 7
				wspolczynnik_kalibracji 9.5)"
	);

	//cout << txt;
	//zapis_txt(&txt);

	//cout << *odczyt_txt("tmp.txt");
	//unique_ptr<string> data = odczyt_txt("tmp.txt");
	//for (auto& c : *data) c = toupper((unsigned char) c);
	//zapis_txt(data.get(), "wielkie_litery.txt");
	//cout << *data;

	//zapis_bin(&txt,"");
	//unique_ptr<string> data = odczyt_bin("");
	//cout << *data;

	double var;
	string etykieta{"wzmocnienie"};
	vector<double> wartosci;

	if (szukacz(nastawy, etykieta, var))
	{
		cout << "znaleziono " << etykieta << ": " << var << " ";
		wartosci.push_back(var);

		while (nastawy >> var)
		{
			wartosci.push_back(var);
		}
	}
	if (wartosci.size() > 1)
	{
	for (int i=1; i < wartosci.size();i++)
		cout << wartosci[i] << " ";
	}
	
	if (nastawy.fail())
		nastawy.clear(nastawy.rdstate() & ~ios::failbit);
	if(nastawy.eof())
		nastawy.clear(nastawy.rdstate() & ~ios::failbit);

}

