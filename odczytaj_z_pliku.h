#pragma once
#include <iostream>
#include <string>

using namespace std;

unique_ptr<string> odczyt_txt(const char* nazwa_pliku);
unique_ptr<string> odczyt_bin(const char* nazwa_pliku);

bool szukacz(istringstream&, string, double&);