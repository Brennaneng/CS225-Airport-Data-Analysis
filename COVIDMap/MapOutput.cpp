#include "MapOutput.h"
#include <stack>

#define V 14110
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

// void Map::findSCC(vector<vector<string>> file, vector<pair<int,int>> routeFile) {
//     // # of nodes = airports
//     int n = file.size();
//     // # SCC's found
//     int sccCount = 0;
//     // # i in the vector represents the airport in index i in the file
//     ids.resize(n,-1);
//     low.resize(n,0);
//     onStack.resize(n,false);

//     cout <<onStack.size()<<"hey"<<endl;
//     stack<int> stack;

//     // for(int i = 0; i < n; i++) {
//     //     if(ids[i] == -1){
//     //         dfs(i)
//     //     }
//     // }
//     //return low;
// };

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
    for(int i = 0; i < 14111; i++){
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
    double R = 3956; //MI
    //double R = 6371; //KM
     
    // Calculate the result
    ans = ans * R;
    //ans = abs(ans);
    return ans;
};


double Map::minDistance(double dist[], bool visited[], MapNode & curr)
{
    // Initialize min value
    double min = INT_MAX, min_index;
    // iterate through the routes 
    for (unsigned int v = 0; v < curr.nodes.size(); v++){
        MapNode * temp = &IDTable_[curr.nodes[v]];
        double distance = Eulerpath(curr.x, curr.y, temp->x, temp->y);
        if(dist[temp->key] >= distance + curr.currentWeight){
            dist[temp->key] = distance + curr.currentWeight;
            temp->currentWeight = dist[temp->key];
        }
        if (visited[v] == false && dist[temp->key] <= min)
            min = dist[temp->key], min_index = temp->key;
    }
    return min_index;
}

void Map::printPath(int parent[], int j){
    if(parent[j] == -1){
        return;
    }
    printPath(parent, parent[j]);
    printf("->%d",j);
}


//A utility function to print the constructed distance array
void Map::printSolution(double dist[], int parent[], int src)
{
    printf("Vertex \t\t Distance from Source \t Path \n");
    for (unsigned int i = 0; i < 1000; i++){
        if(dist[i] == INT_MAX){
            //printf("airport doesn't exist\n");
            continue;
        }
        printf("\n %d -> %d \t\t %f \t\t %d", src, i, (dist[i]), src);
        printPath(parent, src);
    }

    // for(unsigned int i = 0; i < IDTable_[714].nodes.size(); i++){
    //     cout << IDTable_[714].nodes[i] << endl;
    // }
 }
  
// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void Map::dijkstra(int src)
{
    double dist[V]; // The output array.  dist[i] will hold the shortest
    // // distance from src to i
  
    bool visited[V]; // visited[i] will be true if vertex i is included in shortest
    // path tree or shortest distance from src to i is finalized
    
    int parent[V]; //Parent array to store shortest path tree

    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++) {
       dist[i] = INT_MAX, visited[i] = false;
       parent[src] = -1;
    }
    // Distance of source vertex from itself is always 0
    IDTable_[src].currentWeight = 0;
    dist[src] = 0;

  
    // Find shortest path for all vertices
    for(int airID = 0; airID < V-1; airID++){ //curr airport node
    //for (unsigned int count = 0; count != V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in the first iteration.
        MapNode & curr = IDTable_[airID];
    
        int u = minDistance(dist, visited, IDTable_[airID]); //min distance from first airport node
        //MapNode &pickedcurr = IDTable_[u];
        // Mark the picked vertex as processed
        visited[u] = true;
  
        // Update dist value of the adjacent vertices of the picked vertex.
        
        for (unsigned int v = 0; v < curr.nodes.size(); v++){ //size of routes available from current airport
  
            // Update dist[v] only if is not in visited, there is an edge from
            // u to v, and total weight of path from src to  v through u is
            // smaller than current value of dist[v]
          // int mindist = minDistance(dist, visited, pickedcurr);

        //    if (!visited[v] && mindist != INT_MAX
        //         && mindist + pickedcurr.nodes[v].currentWeight < curr.nodes[v].currentWeight){
        //         dist[v] = dist[u] + graph[u][v];
        //         }    
            if (curr.nodes[v] == u) {
                MapNode * temp2 = &IDTable_[curr.nodes[v]];
                MapNode * temp3 = &IDTable_[u];
                double newDist = Eulerpath(temp2->x, temp2->y, temp3->x, temp3->y);
                if (!visited[v]  && dist[u] != INT_MAX && dist[u] + newDist < dist[temp2->key]) {
                    parent[temp2->key] = temp3->key;
                    dist[temp2->key] = dist[u] + newDist;
                    temp2->currentWeight = dist[temp2->key];
                    //test
                }
            }
        }
    }
  
    // print the constructed distance array
    printSolution(dist, parent, src);
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
