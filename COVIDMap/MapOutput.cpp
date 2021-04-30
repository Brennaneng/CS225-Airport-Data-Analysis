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
    mapStartNode_ = NULL;
    allAirports_.resize(14111);
    for (unsigned i = 0; i < allAirports_.size(); i++){
        allAirports_[i].exists = false;
        allAirports_[i].name = "n/a";
        allAirports_[i].x = 0;
        allAirports_[i].y = 0;
    }
    AVLTree<int,vector<vector<double>>> * tree = new AVLTree<int,vector<vector<double>>>();
    _tree = tree;
};
Map::Map(vector<vector<string>> file, vector<pair<int,int>> routeFile){
    mapStartNode_ = NULL;
    allAirports_.resize(14111);
    for (unsigned i = 0; i < allAirports_.size(); i++){
        allAirports_[i].exists = false;
        allAirports_[i].name = "n/a";
        allAirports_[i].x = 0;
        allAirports_[i].y = 0;
    }
    AVLTree<int,vector<vector<double>>> * tree = new AVLTree<int,vector<vector<double>>>();
    _tree = tree;

    //File is total data.
    for(unsigned i = 0; i < file.size(); i++){
        int ID = stoi(file[i][0]);
        //pair<bool,string> curr = allAirports_[ID];
        allAirports_[ID].exists = true;
        allAirports_[ID].name = file[i][1];
        allAirports_[ID].x = stod(file[i][3]);
        allAirports_[ID].y = stod(file[i][4]);
        vector<vector<double>> toInsert (4);
        toInsert[0].push_back(allAirports_[ID].x);
        toInsert[1].push_back(allAirports_[ID].y);
        _tree->insert(ID, toInsert);

        //_tree->insert(ID,allAirports_[ID].second);




        // //Accesses the data from one line which is in a vector (e.g <3/15/2021,GA,299>)
        // vector<string> curr_line = file[i];
        // string curr_state = curr_line[1];
        // string curr_deaths = curr_line[2];
        // int curr_deaths_int = stoi(curr_deaths);
        // //since the date in the data is given like (3/15/2021) we need to access the month and the year so we put it in a vector and return that vector.
        // vector<string> curr_date = {"2020","2020"};//read_date(curr_line[0]);
        // string cur_month = curr_date[0];
        // string cur_year = curr_date[2];
        // int idx = 1;//returnDateIndex(cur_month, cur_year);
        // vector<int> nodeData = _tree->find(curr_state);
        // nodeData[idx] = curr_deaths_int;
        // _tree->replace(curr_state,nodeData);
    }
    readRoutes(routeFile);

    //this sets up our AVL Tree
    for(unsigned i = 0; i < routes_.size(); i++){
        pair<int,int> curr = routes_[i];
        vector<vector<double>> firstValue = _tree->find(curr.first);
        vector<vector<double>> secondValue = _tree->find(curr.second);
        double x1 = firstValue[0][0];
        double x2 = firstValue[1][0];
        double y1 = secondValue[0][0];
        double y2 = secondValue[1][0];
        firstValue[2].push_back(curr.second);
        firstValue[3].push_back(EulerPath(x1,x2,y1,y2));
        allAirports_[curr.first].destinationIDs.push_back(curr.second);
        allAirports_[curr.first].distances.push_back(EulerPath(x1,x2,y1,y2));
        _tree->replace(curr.first, firstValue);
    }

};

void Map::generateMap(int startID){
    // allAirports_[startID].thisPtr = new MapNode(startID, allAirports_[startID].name);
    // mapStartNode_ = allAirports_[startID].thisPtr;

    hasVisited_.resize(14111);
    for(unsigned i = 0; i < allAirports_.size(); i++){
        if(allAirports_[i].exists){
            allAirports_[i].thisPtr = new MapNode(i, allAirports_[i].name);
        }
        hasVisited_[i] = false;
    }

    mapStartNode_ = allAirports_[startID].thisPtr;
    MapNode *& mapStartNode = mapStartNode_;

    while(!createMapNodes.empty())
        createMapNodes.pop();
    
    createMapNodes.push(mapStartNode);
    while(!createMapNodes.empty()){
        MapNode *& currMapNode = createMapNodes.front();
        int currKey = currMapNode->key;
        createMapNodes.pop();

    for(unsigned i = 0; i < allAirports_[currKey].destinationIDs.size(); i++){
        int nextID = allAirports_[currKey].destinationIDs[i];
        MapNode * nextNode = allAirports_[nextID].thisPtr;
        if(hasVisited_[nextID])
            continue;
        currMapNode->nodes.push_back(nextNode);
        createMapNodes.push(nextNode);
        }
    }

};

vector<int> Map::BFSPath(int finalID){
    vector<int> nothing {0};
    return nothing;
};

void Map::readRoutes(vector<pair<int,int>> file){
for(unsigned i = 0; i < file.size(); i++){
    if(allAirports_[file[i].first].exists && allAirports_[file[i].second].exists){
        routes_.push_back(make_pair(file[i].first,file[i].second));
        allAirports_[file[i].first].destinationIDs.push_back(file[i].second);
        }
    }
};

vector<int> Map::printTree(){
    return _tree->getInorderTraversal();
};

// string Map::getValue(int key){
//     return _tree->find(key);
// }

vector<pair<int,int>> Map::printRoutes(){
    return routes_;
};
// Map::generateMap(Node* start_){
    
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
{
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
}



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
}