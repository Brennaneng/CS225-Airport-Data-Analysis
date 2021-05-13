#include "ReadFile.h"
#include "MapOutput.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include "lphashtable.h"
#include <string>


using namespace std;
using namespace functions;

int main(int argc, char** param) {
    if(argc == 1){
        cout<<"Good morning, this is our final CS project!"<<endl;
        cout<<"In order to get started, type ./COVIDMap [string algorithm] [int parameter 1] [int parameter 2] in your terminal."<<endl;
        cout<<"The following algorithms can be run:"<<endl;
        cout<<"SCC, BFS, DIJSKTRA, TEST1, TEST2, TEST3"<<endl;
        cout<<"BFS and DIJSKTRA need at least two integer parameters to run correctly"<<endl;
        cout<<"Have fun testing our code!"<<endl;
        return 1;
    }
    vector<vector<string>> file = read_file();
    vector<pair<int,int>> routeFile = read_routes();

    vector<vector<string>> file_test = read_file_test();
    vector<pair<int,int>> routeFile_test = read_routes_test();

    int startID = -1;
    int destinationID = -1;
    string alg(param[1]);
    if(argc >= 4){
        string temp1(param[2]);
        string temp2(param[3]);
        startID = stoi(temp1);
        destinationID = stoi(temp2);
    }
    cout<<"Running algorithm: "<<alg;
    if(startID == -1)
        cout<<" No startID is being used";
    else
        cout<<" startID: "<<startID;
    if(destinationID == -1)
        cout<< " No destinationID is being used"<<endl;
    else
        cout<< " destinationID: "<<destinationID<<endl;
    if(alg == "SCC"){
        Map SCC(file, routeFile);
        vector<int> sccs = SCC.findSCC(file);
    }
    else if (alg == "BFS") {
        //type BFS as the first parameter to call this algorithm
        //a source ID and a destination ID is necessary to run this algorithm
        if(startID == -1 || destinationID == -1){
            cout<<"Not enough parameters to run this algorithm. Please enter a source and destination ID"<<endl;
            return 1;
        }
        Map BFS(file,routeFile);
        BFS.printData(startID);
        BFS.printData(destinationID);
        BFS.findPath(startID, destinationID);

    }
    else if (alg == "DIJKSTRA"){
        if(startID == -1 || destinationID == -1){
            cout<<"Not enough parameters to run this algorithm. Please enter a source and destination ID"<<endl;
            return 1;
        }
        Map Dij(file, routeFile);
        Dij.printData(startID);
        Dij.printData(destinationID);
        Dij.dijkstra(startID, destinationID);
    }
    else if (alg == "TEST1"){
    cout<<"This test case shows that our Map object can take in CSV data and print the data correctly to the terminal"<<endl;
    cout<<"Every single airport ID is printed along with their corresponding name, latitude, longitude, and where they point to "<<endl;
    cout<<"which is denoted by -->"<<endl;
    Map test_one(file_test, routeFile_test);
    test_one.printAirports();
    return 1;
    }
    else if (alg == "TEST2"){
        cout<<"This test case runs BFS to find a path between to airport IDs [1] and [4]"<<endl;
        cout<<"This BFS algorithm assumes the distances between all paths are equal, so that printed path "<<endl;
        cout<<"isn't necessarily the shortest path. If you want the shortest path, try out DIJKSTRA's algorithm"<<endl;
        Map BFS(file_test,routeFile_test);
        BFS.printData(1);
        BFS.printData(4);
        BFS.findPath(1, 4);
    }
    else if (alg == "TEST3"){
        cout<<"This test case runs BFS to find a path between to airport IDs [1] and [9]"<<endl;
        cout<<"There is no path between these two ID's, so no path should be printed "<<endl;
        Map BFS(file_test,routeFile_test);
        BFS.printData(1);
        BFS.printData(9);
        BFS.findPath(1, 9);

    }
    else if (alg == "TEST4"){
        cout<<"This test case runs BFS to find a path between to airport IDs [1] and [4]"<<endl;
        cout<<"This BFS algorithm assumes the distances between all paths are equal, so that printed path "<<endl;
        cout<<"isn't necessarily the shortest path. If you want the shortest path, try out DIJKSTRA's algorithm"<<endl;
        Map BFS(file_test,routeFile_test);
        BFS.printData(1);
        BFS.printData(9);
        BFS.findPath(1, 9);

    }
    else{
        cout<<"Invalid Algortihm"<<endl;
        return 1;
    }


        // LPHashTable<int,MapNode> hello(5);
        // MapNode temp (1,"mr world wide", 2, 3);
        // hello.insert(1, temp);
        // MapNode &curr = hello[1];
        // curr.value = "not mr world wide >:(";
        // temp = hello.find(1);
        // cout<<"ID 1 has a name of "<<temp.value<< endl;
        // for( int i = 0; i < 14410; i++) {
        //     if(hello.keyExists(i)) {
        //         cout <<"----------------------\n";
        //         cout <<"Index = "<< i << endl;
        //         cout <<"Airport ID = "<< hello[i].key << endl;
        //         cout <<"Airport Name = "<< hello[i].value << endl;
        //         cout <<"Longitude/Latitude = "<< hello[i].x <<"/"<< hello[i].y << endl;
        //         cout <<"----------------------\n";
        //     }
        // }
        // vector<vector<string>> file = read_file();
        // vector<pair<int,int>> routeFile = read_routes();
        // Map airports(file, routeFile);
        // vector<int> sccs = airports.findSCC(file);

        // //Print Nodes in SuperNode 0:
        // cout<<"Super Node: 0 "<< endl;
        // for(unsigned int i = 0; i < sccs.size(); i++) {
        //     if(sccs[i]==0) {
        //         cout<<"------->"<<file[i][1]<<" is part of Super Node: "<< sccs[i]<< endl;
        //     }
        // }
        //airports.dijkstra(3830);
        //airports.dijkstra(3830, 3000);
        //airports.findSCC(file, routeFile);
        // airports.printAirports();
        // airports.printName(100);
        // airports.printName(3599);
        // airports.findPath(100,3599);


        return 0;
    }








        // AirPortNode curr(true,"airport", 120, 1221);
        // AirPortNode temp = curr;
        // AVLTree<int,AirPortNode> tree;
        // tree.insert(1,curr);
        // cout<<curr.exists<< " "<<curr.name<<" "<<curr.x<<" "<<curr.y<<endl;
        // curr.exists = false;
        // curr.name = "land";
        // tree.replace(1,curr);
        // temp = tree.find(1);
        // cout<<temp.exists<< " "<<temp.name<<" "<<temp.x<<" "<<temp.y<<endl;

        //presenting demo BFS
        // Map demo;
        // demo.democreateMap();
        
    //set up for next part
        // vector<vector<string>> file = read_file();
        // vector<pair<int,int>> routeFile = read_routes();
        // Map airports(file, routeFile);
        // airports.printName(9739);
        // airports.printName(9744);
        // airports.printName(3599);
        // airports.findPath(9739,3599);

        // vector<pair<int,string>> airportsToPrint = airports.printAirports();
        // vector<pair<int,int>> routesUsed = airports.printRoutes();

    //presenting all airports being used in our project
    // for(unsigned i = 0; i < airportsToPrint.size(); i++){
    //     pair<int,string> curr = airportsToPrint[i];
    //     cout<<"Airport ID: "<<curr.first<<" is associated with the airport "<<curr.second<<endl;
    //}

    //presenting the routes between all the airports we analyze
    // for(unsigned i = 0; i < routesUsed.size(); i++){
    //     pair<int,int> curr = routesUsed[i];
    //     cout<<"Airport ID: "<<curr.first<<" points to Airport ID: "<<curr.second<<endl;
    // }





        // string test = "hello" + " world " + " ! ";
        // cout<<test<<endl;
        





//     vector<vector<string>> file = read_file();
//     vector<pair<int,int>> routeFile = read_routes();
//     Map test(file, routeFile);

//    int temp = test.returnNode(3214);
//     cout<< temp <<endl;

//     cout<< test.generateMap(3411)<<endl;
    // vector<int> print = test.printTree();
    // for(unsigned i = 0; i < print.size(); i++){
    //     cout<< print[i] << " " << file[i][1] <<endl;
    // }
    // vector<pair<int,int>> routes = test.printRoutes();
    // for(unsigned i = 0; i < routes.size(); i++){
    //     cout<< test.getValue(routes[i].first)<< " goes to "<< test.getValue(routes[i].second)<<endl;
    // }


    // vector<int> solnTraversal;
    // solnTraversal.push_back(4);
    // solnTraversal.push_back(1);
    // solnTraversal.push_back(5);
    // std::vector<string> solnFuncCalls;
    // solnFuncCalls.push_back("rotateLeft");
    //
    // CSV reading;
    // vector<vector<string> >  dataVector = read_file();
    // for(unsigned int i = 0; i < dataVector.size(); i++){
    //     for(unsigned int j = 0; j < dataVector[0].size(); j++){
    //         cout<<dataVector[i][j] <<" ";
    //     }
    // }
    // if ((dataVector.back()).back() == "/n") {
    //     cout<< (dataVector.back()).back()<< "ok" << endl;
    // } 
