// FileFun.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <fstream>
#include <string>

#include "zapisz_do_pliku.h"
#include "odczytaj_z_pliku.h"

using namespace std;

int main()
{
	string txt{ "In Visual Studio, you can create a New Project (or open an existing one).\n"
		"All installed libraries are immediately ready to be " 
		"`#include`'d and used in your project without additional configuration."};
		
	//cout << txt;
	//zapis_txt(&txt);

	//cout << *odczyt_txt("tmp.txt");
	unique_ptr<string> data = odczyt_txt("tmp.txt");
	for (auto& c : *data) c = toupper((unsigned char) c);
	zapis_txt(data.get(), "wielkie_litery.txt");
	//cout << *data;
}

