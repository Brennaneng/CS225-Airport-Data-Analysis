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
    
};
Map::Map(vector<vector<string>> file, vector<pair<int,int>> routeFile){
    usedAirports_.clear();

    //File is total data.
    for(unsigned i = 0; i < file.size(); i++){
        int ID = stoi(file[i][0]);
        //this is important to the implemenatation
        MapNode curr(ID,file[i][1], stod(file[i][3]), stod(file[i][4]));
        IDTable_.insert(ID, curr);

        //IDTable_.insert(ID,)
        // allAirports_[ID].exists = true;
        // allAirports_[ID].name = file[i][1];
        // allAirports_[ID].x = stod(file[i][3]);
        // allAirports_[ID].y = stod(file[i][4]);
        // allAirports_[ID].key = ID;
        
    }
    readRoutes(routeFile);

    //uncomment this to print all the airports and their connections

    // for(int i = 0; i < 14410; i++){
    //     if(IDTable_.keyExists(i)){
    //     cout<< "Current airport is "<< IDTable_[i].value<<endl;
    //     for(unsigned j = 0; j < IDTable_[i].nodes.size(); j++){
    //         int connID = IDTable_[i].nodes[j];
    //         cout<<"--->"<<IDTable_[connID].value<<endl;
    //     }
    //     }
    // }


};



vector<int> Map::BFSPath(int finalID){
    vector<int> nothing {0};
    return nothing;
};

void Map::readRoutes(vector<pair<int,int>> file){
 for(unsigned i = 0; i < file.size(); i++){
    int firstID = file[i].first;
    int secondID = file[i].second;
    if(IDTable_.keyExists(firstID) && IDTable_.keyExists(secondID)) {
        MapNode &firstNode = IDTable_[firstID];
        firstNode.nodes.push_back(secondID);
        routes_.push_back(make_pair(firstID,secondID));        
        }
    }
};

vector<pair<int,string>> Map::printAirports(){
    //return _tree->getInorderTraversal();
    vector<pair<int,string>> temp;
    for(unsigned i = 0; i < usedAirports_.size(); i++){
        temp.push_back(make_pair(usedAirports_[i].key,usedAirports_[i].value));
    }
    return temp;
};

// string Map::getValue(int key){
//     return _tree->find(key);
// }

vector<pair<int,int>> Map::printRoutes(){
    return routes_;
};
// Map::generateMap(Node* start_){
int Map::returnNode(int ID){
    // int idx = binarySearch(usedAirports_,0,usedAirports_.size()-1, ID);
    // if(idx==-1)
    //     return -1;
    // MapNode * value = new MapNode(ID, usedAirports_[idx].name);
    //return value->key;
    return -1;
};
    
double Map::EulerPath(double x1, double x2, double y1, double y2){
    return 0;
};


double Map::toRadians(const double degree)
{
    // cmath library in C++
    // defines the constant
    // M_PI as the value of
    // pi accurate to 1e-30
    double one_deg = (M_PI) / 180;
    return (one_deg * degree);
}
 
double Map::Eulerpath(double lat1, double long1, double lat2, double long2){

    // Convert the latitudes
    // and longitudes
    // from degree to radians.
    lat1 = toRadians(lat1);
    long1 = toRadians(long1);
    lat2 = toRadians(lat2);
    long2 = toRadians(long2);
     
    // Haversine Formula
    double dlong = long2 - long1;
    double dlat = lat2 - lat1;
 
    double ans = pow(sin(dlat / 2), 2) +
                          cos(lat1) * cos(lat2) *
                          pow(sin(dlong / 2), 2);
 
    ans = 2 * asin(sqrt(ans));
 
    // Radius of Earth in
    // Kilometers, R = 6371
    // Use R = 3956 for miles
    double R = 6371;
     
    // Calculate the result
    ans = ans * R;
 
    return ans;
};





// }
/*
void Map::insertStates()
{
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
}
};*/
