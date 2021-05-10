#include "ReadFile.h"
#include "MapOutput.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include "lphashtable.h"

using namespace std;
using namespace functions;

struct MapNode {
        int key;
        string value;
        int currentWeight;
        vector<int> nodes;
        double x;
        double y;
        int prev;

        /**
         * Node constructor; sets children to point to `NULL`.
         * @param newKey The object to use as a key
         * @param newValue The templated data element that the constructed
         *  node will hold.
         */
        MapNode(const int& newKey, const string& newValue, int lat, int lon)
            : key(newKey), value(newValue), currentWeight(-1), x(lat), y(lon), prev(-1)
        {
        }
        MapNode() : key(-1), value("n/a"), currentWeight(-1), x(-1), y(-1), prev(-1)
        {}
    };

int main() {

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
        vector<vector<string>> file = read_file();
        vector<pair<int,int>> routeFile = read_routes();
        Map airports(file, routeFile);
        airports.dijkstra(714);
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
