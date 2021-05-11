#include "MapOutput.h"
#include <stack>

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


using namespace std;

//One function we have to consider is editing the Binary tree as we read in the Dataset. In orders
Map::Map(){
    
};
Map::Map(vector<vector<string>> file, vector<pair<int,int>> routeFile){
    //File is total data.
    for(unsigned i = 0; i < file.size(); i++){
        //grabs the ID from the current line in the file
        //cout<<file[i][0]<<file[i][1]<<file[i][2]<<file[i][3]<<file[i][4]<<endl;
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

void Map::printSCC(vector<int> low, vector<vector<string>> file) {
    for(int i = 0; i<low.size(); i++) {
        cout<<file[i][1]<<" is part of Super Node: "<< low[i]<< endl;
    }
};

vector<int> Map::findSCC(vector<vector<string>> file) {
    // # of nodes = airports
    int n = file.size();
    // # SCC's found
    id = 0;
    int sccCount = 0;
    // # i in the vector represents the airport in index i in the file
    ids.resize(n,-1);
    low.resize(n,0);
    onStack.resize(n,false);

    for(int i = 0; i < n; i++) {
        if(ids[i] == -1){
            dfs(i,file);
        }
    }
    printSCC(low,file);
    return low;
};
void Map::dfs(int i, vector<vector<string>> file) {
    mystack.push(i);
    onStack[i] = true;
    ids[i] = id;
    low[i] = ids[i];
    id++;
    //Get the id from the corresponding node from the file. Turn the string into an int.
    string airportid = file[i][0];
    int airID = stoi(airportid);
    //Search for the node in the table;
    MapNode airport = IDTable_.find(airID);
    for(int x : airport.nodes) {
        // find the index of the ID in the file vector;
        int index = 0;
        for(unsigned int j = 0; j < file.size(); j++) {
            if(to_string(x) == file[j][0]) {
                break;
            }
            index++;
        }

        if(ids[index] == -1) {
            dfs(index,file);
        }
        if(onStack[index]){
            low[i] = min(low[i],low[index]);
        }

        //After having visited all the neighbours of 'i'
        //if we're at the start of the SCC empty the seen
        //stack until we're back to the start of the SCC
        if(ids[i] == low[i]){
            while(!mystack.empty()) {
                onStack[mystack.top()] = false;
                low[mystack.top()] = ids[i];
                if(mystack.top() == i) {
                    break;
                }
                mystack.pop();
            }
            sccCount++;
        }
    }
};
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


// int Map::minDistance(int dist[], bool sptSet[])
// {
//     // Initialize min value
//     int min = INT_MAX, min_index;
  
//     for (int v = 0; v < V; v++)
//         if (sptSet[v] == false && dist[v] <= min)
//             min = dist[v], min_index = v;
  
//     return min_index;
// }
  
// A utility function to print the constructed distance array
// void Map::printSolution(int dist[])
// {
//     printf("Vertex \t\t Distance from Source\n");
//     for (int i = 0; i < V; i++)
//         printf("%d \t\t %d\n", i, dist[i]);
// }
  
// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
// void Map::dijkstra(int src)
// {
//     int dist[IDTable_.size()]; // The output array.  dist[i] will hold the shortest
//     // distance from src to i
  
//     bool sptSet[IDTable_.size()]; // sptSet[i] will be true if vertex i is included in shortest
//     // path tree or shortest distance from src to i is finalized
  
//     // Initialize all distances as INFINITE and stpSet[] as false
//     for (int i = 0; i < IDTable_.size(); i++)
//         dist[i] = -1, sptSet[i] = false;
  
//     // Distance of source vertex from itself is always 0
//     dist[src] = 0;
  
//     // Find shortest path for all vertices
//     for (int count = 0; count < IDTable_.size() - 1; count++) {
//         // Pick the minimum distance vertex from the set of vertices not
//         // yet processed. u is always equal to src in the first iteration.
//         int u = minDistance(dist, sptSet);
  
//         // Mark the picked vertex as processed
//         sptSet[u] = true;
  
//         // Update dist value of the adjacent vertices of the picked vertex.
//         for (int v = 0; v < V; v++)
  
//             // Update dist[v] only if is not in sptSet, there is an edge from
//             // u to v, and total weight of path from src to  v through u is
//             // smaller than current value of dist[v]
//             if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
//                 && dist[u] + graph[u][v] < dist[v])
//                 dist[v] = dist[u] + graph[u][v];
//     }
  
//     // print the constructed distance array
//     printSolution(dist);
// }




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
