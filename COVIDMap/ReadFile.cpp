 #include "ReadFile.h"
 
using namespace std;
namespace functions {
<<<<<<< HEAD
vector<pair<int,int> > read_routes()  {
    
    //creating file pointer
    ifstream file;

    //opens file to be read
    //Gives us Source airport ID,Destination airport ID
    file.open("routes_filtered.csv");

    //Creates a vector of pairs
    vector<pair<int,int> > TotalFile;
    //Creates pair
    pair<int,int> datapair(0,0);
    //creates a temporary string called line to take each cell
    string line;
    //counter to determine place in airport
    int counter = 0;
    //reads while the file still has values to be read
    while(file.good()){
        while(getline(file,line) ) {
            stringstream ss(line);
            counter = 0;
            while (getline(ss,line,',') ) {
                if(counter == 0) {
                    int x = stoi(line);
                    datapair.first = x;
                }
                else if(counter == 1) {
                    int x = stoi(line);
                    datapair.second = x;
                }
                counter++;
            }
            TotalFile.push_back(datapair);
            datapair.first = 0;
            datapair.second = 0;
        }    
    }
    return TotalFile;
}
vector<vector<string> > read_file() {
=======

vector<vector<string>> read_file() {
>>>>>>> 84efd7bbd55a37a2248baa2b38f356181a735cbc
    //creating file pointer
    ifstream file;

    //opens file to be read
    file.open("airports_filtered.csv");

    //Created two vectors, TotalFile creates a vector of vectors that takes in each row called a vector datapoint
    //datapoint creates a set of values enumerated by ',' which means each index of the datapoint will be date, state, and deaths
    vector<vector<string> > TotalFile;
    vector<string> line;
    //reads while the file still has values to be read
    while(file.good()){
        //creates a temporary string called line to take each 
<<<<<<< HEAD
        string line;
        for(int count = 0; count < 3; count++){
            getline(file, line, ',');
            datapoint.push_back(line); 
=======
        string datapoint;
        for(int count = 0; count < 5; count++){
            std::getline(file, datapoint, ',');
            if(count == 2){
                if(datapoint != 'United States'){
                    line.clear();
                    std::getline(file, datapoint, ','); //skips next two datapoints which are coordinates
                    std::getline(file, datapoint, ',');
                    continue; //continues onto next iteration which should be next line

                }
            }
            line.push_back(datapoint); 
>>>>>>> 84efd7bbd55a37a2248baa2b38f356181a735cbc
        }
        TotalFile.push_back(line);
        line.clear();
    }

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
    int x = std::stoi(month); 
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