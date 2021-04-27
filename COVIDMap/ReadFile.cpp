#include <string>
#include <iostream>
#include <fstream>
#include <vector>
 #include "ReadFile.h"
using namespace std;

namespace functions{
vector<vector<string> > * read_file(){
    //creating file pointer
    ifstream file;

    //opens file to be read
    file.open("all-states-history-death.csv");

    //Created two vectors, TotalFile creates a vector of vectors that takes in each row called a vector datapoint
    //datapoint creates a set of values enumerated by ',' which means each index of the datapoint will be date, state, and deaths
    vector<vector<string> > * TotalFile;
    vector<string> datapoint;
    //reads while the file still has values to be read
    while(file.good()){
        //creates a temporary string called line to take each 
        string line;
        for(int count = 0; count < 3; count++){
            std::getLine(file, line, ',');
            datapoint.push_back(line); 
        }
        TotalFile->push_back(datapoint);
        datapoint.clear();
    }
    cout<<"Done"<<endl;
    return TotalFile;
}
// divides the date to 3 strings. To access dates easier 
//@param string full_date: the full date (e.g 3/6/2021)
vector<string> * read_date(string full_date) {
	istringstream ss = full_date ;
	string token;
	vector<string> dates;
	while(std::getline(ss, token, '/')) {
		dates.push_back(token);
	}

	return dates;
}
}