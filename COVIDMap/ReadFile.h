#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>


using namespace std;

namespace functions{
vector<vector<string>> read_file();

vector<string> read_date(string full_date);

int returnDateIndex(string month, string year);
}