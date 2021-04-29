#include "MapOutput.h"


//here is where we will create a map object. We will specify what kind of map where are working with meaning
//that if we want a map for deaths, we create a map object called deaths. If we do a map for deaths, then we will
//create a tree of states where each value is a vector full of deaths for each month. If we do a map for positive cases, 
//then we create a tree of states where each value is a vector full of positive cases for each month

//map should have a constructor where it takes a csv file. it will then call the read in file function where 
//a vector of total data is created. then that data will be used to create a binary tree

//Private member: binary tree
//when a binary tree is constructed, it will become the private variable for that map object

//Private member: vector<PNG> mapPictures
//each index will be a map for a certain date. we have to create a function that uses the binary tree to get data,
//and then access this vector, and alter the png image for the corresponding month




//One function we have to consider is editing the Binary tree as we read in the Dataset. In orders
Map::Map(){
    insertStates();
    AVLTree<string,vector<int>> * tree = new AVLTree<string,vector<int> >();
    for(int i = 0; i < 50; i++){
        //vector<int> * empty = new vector<int>;
        vector<int> empty;
        empty.resize(15);
        string currState = States->at(i);;
        tree->insert(currState, empty);
    }
    _tree = tree;
};
Map::Map(vector<vector<string>> file){
    Map();
    //File is total data.
    for(unsigned i = 0; i < file.size(); i++){
        //Accesses the data from one line which is in a vector (e.g <3/15/2021,GA,299>)
        vector<string> curr_line = file[i];
        string curr_state = curr_line[1];
        string curr_deaths = curr_line[2];
        int curr_deaths_int = stoi(curr_deaths);
        //since the date in the data is given like (3/15/2021) we need to access the month and the year so we put it in a vector and return that vector.
        vector<string> curr_date = read_date(curr_line[0]);
        string cur_month = curr_date[0];
        string cur_year = curr_date[2];
        int idx = returnDateIndex(cur_month, cur_year);
        vector<int> nodeData = _tree->find(curr_state);
        nodeData[idx] = curr_deaths_int;
        _tree->replace(curr_state,nodeData);
    }

};
void Map::insertStates(){
States = new vector<string> ({"AK",
"AL",
"AR",
"AZ",
"CA",
"CO",
"CT",
"DE",
"FL",
"GA",
"HI",
"IA",
"ID",
"IL",
"IN",
"KS",
"KY",
"LA",
"MA",
"MD",
"ME",
"MI",
"MN",
"MO",
"MS",
"MT",
"NC",
"ND",
"NE",
"NH",
"NJ",
"NM",
"NV",
"NY",
"OH",
"OK",
"OR",
"PA",
"RI",
"SC",
"SD",
"TN",
"TX",
"UT",
"VA",
"VT",
"WA",
"WI",
"WV",
"WY"});
};