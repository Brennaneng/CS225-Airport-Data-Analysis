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
    // for (unsigned i = 0; i < allAirports_.size(); i++){
    //     allAirports_[i].exists = false;
    //     allAirports_[i].name = "n/a";
    //     allAirports_[i].x = 0;
    //     allAirports_[i].y = 0;
    // }
    // AVLTree<int,vector<vector<double>>> * tree = new AVLTree<int,vector<vector<double>>>();
    // _tree = tree;
};
Map::Map(vector<vector<string>> file, vector<pair<int,int>> routeFile){
    mapStartNode_ = NULL;
    allAirports_.resize(14111);
    usedAirports_.clear();
    for (unsigned i = 0; i < allAirports_.size(); i++){
        allAirports_[i].exists = false;
        allAirports_[i].name = "n/a";
        allAirports_[i].x = 0;
        allAirports_[i].y = 0;
        allAirports_[i].key = 0;
    }
    // AVLTree<int,vector<vector<double>>> * tree = new AVLTree<int,vector<vector<double>>>();
    // _tree = tree;

    //File is total data.
    for(unsigned i = 0; i < file.size(); i++){
        int ID = stoi(file[i][0]);
        // AirPortNode curr (true, ID,file[i][1], stod(file[i][3]), stod(file[i][4]) );
        // usedAirports_.push_back(curr);
        allAirports_[ID].exists = true;
        allAirports_[ID].name = file[i][1];
        allAirports_[ID].x = stod(file[i][3]);
        allAirports_[ID].y = stod(file[i][4]);
        allAirports_[ID].key = ID;
        // vector<vector<double>> toInsert (4);
        // toInsert[0].push_back(allAirports_[ID].x);
        // toInsert[1].push_back(allAirports_[ID].y);
        // _tree->insert(ID, toInsert);

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
        // int idx = binarySearch(usedAirports_, curr.first, 0, usedAirports_.size());
        // AirPortNode & currNode = usedAirports_[idx];
        // vector<vector<double>> firstValue = _tree->find(curr.first);
        // vector<vector<double>> secondValue = _tree->find(curr.second);

        double x1 = allAirports_[curr.first].x;
        double x2 = allAirports_[curr.first].y;
        double y1 = allAirports_[curr.second].x;
        double y2 = allAirports_[curr.second].y;
        // firstValue[2].push_back(curr.second);
        // firstValue[3].push_back(EulerPath(x1,x2,y1,y2));
        //currNode.destinationIDs.push_back(curr.second);
        //allAirports_[curr.first].destinationIDs.push_back(curr.second);
        allAirports_[curr.first].distances.push_back(EulerPath(x1,x2,y1,y2));
        //_tree->replace(curr.first, firstValue);
    }
    cout<<"Size of used airports is "<<usedAirports_.size()<<endl;
    cout<<"Size of allAirports is "<<allAirports_.size()<<endl;

    for(unsigned i = 0; i < allAirports_.size(); i++){
        if(allAirports_[i].exists){
            usedAirports_.push_back(allAirports_[i]);
            cout<<"Number of connections: "<<allAirports_[i].destinationIDs.size()<<endl;
        }
    }
    allAirports_.clear();

    cout<<"Size of used airports is "<<usedAirports_.size()<<endl;

};

string Map::generateMap(int startID){
    // allAirports_[startID].thisPtr = new MapNode(startID, allAirports_[startID].name);
    // mapStartNode_ = allAirports_[startID].thisPtr;
    int startIdx = binarySearch(usedAirports_, 0,usedAirports_.size()-1, startID);
    if(startIdx == -1)
        return "Cannot generate a map with this ID";
    hasVisited_.resize(usedAirports_.size());

    // for(unsigned i = 0; i < allAirports_.size(); i++){
    //     if(allAirports_[i].exists){
    //         allAirports_[i].thisPtr = new MapNode(i, allAirports_[i].name);
    //     }
    //     hasVisited_[i] = false;
    // }
    for(unsigned i = 0; i < usedAirports_.size(); i++){
        int currKey = usedAirports_[i].key;
        string currName = usedAirports_[i].name;
        usedAirports_[i].thisPtr = new MapNode(currKey, currName);
        hasVisited_[i] = false;
    }

    mapStartNode_ = usedAirports_[startIdx].thisPtr;

    while(!createMapNodes.empty())
        createMapNodes.pop();
    
    createMapNodes.push(mapStartNode_);
    while(!createMapNodes.empty()){
        MapNode * currMapNode = createMapNodes.front();
        int currKey = currMapNode->key;
        int currIdx = binarySearch(usedAirports_, 0,usedAirports_.size()-1, currKey);
        createMapNodes.pop();

    for(unsigned i = 0; i < usedAirports_[currIdx].destinationIDs.size(); i++){
        int nextID = usedAirports_[currIdx].destinationIDs[i];
        int nextIndex = binarySearch(usedAirports_,0, usedAirports_.size()-1, nextID);
        MapNode * nextNode = usedAirports_[nextIndex].thisPtr;
        if(hasVisited_[nextIndex])
            continue;
        currMapNode->nodes.push_back(nextNode);
        createMapNodes.push(nextNode);
        }
    }
return "Successfully generated a map";
};

vector<int> Map::BFSPath(int finalID){
    vector<int> nothing {0};
    return nothing;
};

void Map::readRoutes(vector<pair<int,int>> file){
for(unsigned i = 0; i < file.size(); i++){
    if(allAirports_[file[i].first].exists && allAirports_[file[i].second].exists){
            allAirports_[file[i].first].destinationIDs.push_back(file[i].second);
            routes_.push_back(make_pair(file[i].first,file[i].second));
        }
    }
};

vector<pair<int,string>> Map::printAirports(){
    //return _tree->getInorderTraversal();
    vector<pair<int,string>> temp;
    for(unsigned i = 0; i < usedAirports_.size(); i++){
        temp.push_back(make_pair(usedAirports_[i].key,usedAirports_[i].name));
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
    int idx = binarySearch(usedAirports_,0,usedAirports_.size()-1, ID);
    if(idx==-1)
        return -1;
    MapNode * value = new MapNode(ID, usedAirports_[idx].name);
    return value->key;
}
    
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

int Map::binarySearch(const vector<AirPortNode>& elements, int start, int end, const int& val){

    int midPoint = (start + end)/2;

    if(end - start == 0 && elements[midPoint].key != val){
        return -1;
    }
    if(elements[midPoint].key == val){
        return midPoint;
    }
    if(elements[midPoint].key < val){
        return binarySearch(elements, midPoint+1, end, val);
    }
    else{
        return binarySearch(elements, start, midPoint, val);
    }
    
    //return -1;


};

void Map::addPath(int x, int y){
    airports[x]->nodes.push_back(airports[y]);
}
void Map::democreateMap(){
    MapNode * ORD = new MapNode(0, "ORD");
    MapNode * SFA = new MapNode(1, "SFA");
    MapNode * JFK = new MapNode(2, "JFK");
    MapNode * JAK = new MapNode(3, "JAK");
    MapNode * FOO = new MapNode(4, "FOO");
    airports.push_back(ORD);
    airports.push_back(SFA);
    airports.push_back(JFK);
    airports.push_back(JAK); 
    airports.push_back(FOO);
    addPath(0, 3);
    addPath(3, 2);
    addPath(2, 1);
    addPath(4, 0);
    addPath(0, 4);
    addPath(1, 4);
    addPath(4, 3);

    demoBFS(airports);


}
vector<string> Map::demoBFS(vector<MapNode*> airports){
    bool *visited = new bool[airports.size()];
    for(unsigned i = 0; i < airports.size(); i++){
        visited[i] = false;
    }
    vector<string> returnPaths;
    queue<MapNode*> Mapqueue;
    Mapqueue.push(airports[0]);
    while(!Mapqueue.empty()){
        MapNode * curr = Mapqueue.front();
        cout<<"Curr mapnode value is "<<curr->value<<endl;
        visited[curr->key] = true;
        Mapqueue.pop();

        while(!Mapqueue.empty() && visited[curr->key]){
            curr = Mapqueue.front();
            Mapqueue.pop();
        }

        for(unsigned i = 0; i < curr->nodes.size(); i++){
            MapNode* nextPotential = curr->nodes[i];
            if(!visited[nextPotential->key]){
                cout<<nextPotential->value<<" has a path to "<<curr->value<<endl;
                Mapqueue.push(nextPotential);
                nextPotential->prev = curr;
                
                // returnPaths.push_back()
            }
        }

    }
// reverse(returnPaths.begin(),returnPaths.end());
returnPaths.push_back("finished BFS");
return returnPaths;
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
