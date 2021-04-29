#pragma once

#include <iostream>
#include <vector>
using namespace std;

namespace functions{
/**
* Creates and returns a vector of vectors containing strings of the lines.
*/
vector<vector<string> > read_file();

/** divides the date to 3 strings. To access dates easier 
*@param string full_date: the full date (e.g 3/6/2021)*/
//Returns <'3','6','2021'>
vector<string> read_date(string full_date);

/**
* Cleans the data field by remoing rows that have any empty cells.
*/
void clean_data();
}