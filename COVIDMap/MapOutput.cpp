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
    //File is total data.
    for(unsigned i = 0; i < file.size(); i++){
        //grabs the ID from the current line in the file
        int ID = stoi(file[i][0]);
        //this is important to the implemenatation
        //creates a MapNode to be inserted to the hashtable
        MapNode curr(ID,file[i][1], stod(file[i][3]), stod(file[i][4]));
        IDTable_.insert(ID, curr);

    }
    //this creates the routes_ vector and adds the connections to each MapNode
    readRoutes(routeFile);
};

Map::~Map(){
    airports.clear();
    hasVisited_.clear();
    routes_.clear();
   //~IDTable_;
}

void Map::printName(int ID){
    //this prints the corresponding airport to the ID if it exists
    if(!IDTable_.keyExists(ID)){
        cout<<"ID doesn't exist"<<endl;
        return;
    }
    cout<<"ID "<<ID<<" is airport "<<IDTable_[ID].value<<endl;
};

void Map::findPath(int startID, int finalID){
    //this finds a path between any two IDs using BFS

    //if neither ID exists, then a path cannot exist
    if(!IDTable_.keyExists(startID) || !IDTable_.keyExists(finalID)){
        cout<<"A path does not exist"<<endl;
        return;
    }

    queue<int> traversal;
    traversal.push(startID);
    //if the flag remains false by the end of the BFS, a path doesn't exist
    bool flag = false;
    while(!traversal.empty()){
        int currID = traversal.front();
        MapNode *curr = &IDTable_[currID];
        traversal.pop();

        while(!traversal.empty() && curr->currentWeight!=-1){
            currID = traversal.front();
            curr = &IDTable_[currID];
            traversal.pop();
        }

        curr->currentWeight = 1;
        //this for loop iterates through all the nodes the current node points to
        //if the next potential node has already been visited, we don't care about it
        for(unsigned i = 0; i < curr->nodes.size(); i++){
            int nextID = curr->nodes[i];
            MapNode *nextPotential = &IDTable_[nextID];
            if(nextPotential->currentWeight == -1){
                traversal.push(nextID);
                nextPotential->prev = currID;
                if(nextID == finalID){
                    flag = true;
                    break;
                }
            }
        }
        if(flag)
            break;
    }
    if(!flag){
        cout<<"No path exists"<<endl;
        return;
    }
    //this prints the path to the terminal
    int from = -1;
    int to = finalID;
    while(to != startID){
        MapNode &curr = IDTable_[to];
        from = curr.prev;
        cout<<"From "<<from<<" to "<<to<<endl;
        to = from;
    }


};

void Map::readRoutes(vector<pair<int,int>> file){
//this iterates through the entire routes csv
 for(unsigned i = 0; i < file.size(); i++){
    int firstID = file[i].first;
    int secondID = file[i].second;
    //if neither ID exists, then a route cannot exist
    if(IDTable_.keyExists(firstID) && IDTable_.keyExists(secondID)) {
        MapNode &firstNode = IDTable_[firstID];
        //the connection is added to the first node
        //the connection pair is pushed to the routes vector
        firstNode.nodes.push_back(secondID);
        routes_.push_back(make_pair(firstID,secondID));        
        }
    }
};

void Map::printAirports(){
    for(int i = 0; i < 14410; i++){
        if(IDTable_.keyExists(i)){
        cout<< "Current airport is "<< IDTable_[i].value<<endl;
        for(unsigned j = 0; j < IDTable_[i].nodes.size(); j++){
            int connID = IDTable_[i].nodes[j];
            cout<<"--->"<<IDTable_[connID].value<<endl;
        }
        }
    }
};

vector<pair<int,int>> Map::printRoutes(){
    return routes_;
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
