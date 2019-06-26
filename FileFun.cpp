#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include "zapisz_do_pliku.h"
#include "odczytaj_z_pliku.h"
#include "szukacz.h"

using namespace std;

int main()
{
	string txt{ "In Visual Studio, you can create a New Project (or open an existing one).\n"
		"All installed libraries are immediately ready to be " 
		"`#include`'d and used in your project without additional configuration."};
		
	istringstream nastawy(
				R"(nastawa1 3
				wzmocnienie 3 5 7
				wspolczynnik_kalibracji 9.5 1 5.6)"
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

	//zapis_1_param_txt(nastawy,"wzmocnienie");
	string do_zapisu{"wspolczynnik_kalibracji"};
	zapis_1_param_bin(nastawy, do_zapisu);
	vector<double> data = odczyt_bin("wspolczynnik_kalibracji.bin",do_zapisu);
	double a, b, c;
	
	a = data[0];
	b = data[1];
	c = data[2];
	cout << do_zapisu << ": "<< a << endl;
	cout << do_zapisu << ": "<< b << endl;
	cout << do_zapisu << ": "<< c << endl;
}

