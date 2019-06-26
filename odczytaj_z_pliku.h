#pragma once
#include <iostream>
#include <string>

using namespace std;

unique_ptr<string> odczyt_txt(const char* nazwa_pliku);
vector<double> odczyt_bin(const char* , string);
