 #include "ReadFile.h"

namespace functions {

vector<vector<string>> read_file() {
    //creating file pointer
    ifstream file;

    //opens file to be read
    file.open("airports_fitered.csv");

    //Created two vectors, TotalFile creates a vector of vectors that takes in each row called a vector datapoint
    //datapoint creates a set of values enumerated by ',' which means each index of the datapoint will be date, state, and deaths
    vector<vector<string> > TotalFile;
    vector<string> line;
    //reads while the file still has values to be read
    while(file.good()){
        //creates a temporary string called line to take each 
        string datapoint;
        while(getline(file,datapoint)){
            std::stringstream ss(datapoint);
            while(getline(ss,datapoint, ',')){
                line.push_back(datapoint);
            }
            if(line[2] == "United States"){
                TotalFile.push_back(line);
            }
            line.clear();
        }
        // for(int count = 0; count < 5; count++){
        //     std::getline(file, datapoint, ',');
        //     line.push_back(datapoint); 
        // }
        // if(line[2] == "United States"){
        //     TotalFile.push_back(line);
        // }
        // line.clear();
    }


    cout<<"Done"<<endl;
    return TotalFile;
};

vector<string> read_date(string full_date) {
    std::istringstream ss(full_date);
    string token;
    vector<string> dates;
    while(std::getline(ss, token, '/')) {
        dates.push_back(token);
    }

    return dates;
};
int returnDateIndex(string month, string year){
int x = stoi(month); 
--x;
if(year == "2020"){
    return x;
}
else{
x = x + 12;
return x;
}
return -1;
}
void clean_data() {
    
};
}