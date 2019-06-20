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


