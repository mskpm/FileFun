#pragma once

#include <string>
#include <sstream>
using namespace std;

bool zapis_all_txt(std::string *, string);
bool zapis_all_bin(std::string *, std::string);
bool zapis_1_param_txt(std::istringstream &, string);
bool zapis_1_param_bin(istringstream &, string);
