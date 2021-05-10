#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "ReadFile.h"
#include <sstream>
#include <fstream>
#include <queue>
#include <list>
#include <algorithm>
#include<limits.h>
#include "lphashtable.h"

using namespace functions;
using namespace std;

class Map{
    public:

    Map();

    ~Map();
    
    //Map(); //this will create the binary tree
    Map(vector<vector<string>> file, vector<pair<int,int>> routeFile);

    void printName(int ID);
    
    void printAirports();

    vector<pair<int,int>> printRoutes();

    void readRoutes(vector<pair<int,int>> file);

    double toRadians(const double degree);

    double Eulerpath(double lat1, double long1, double lat2, double long2);
    // string getValue(int key);

    void insertStates();

    void findPath(int startID, int finalID);

    void findSCC(vector<vector<string>> file, vector<pair<int,int>> routeFile);
    void printPath(int parent[], int j);
    void dijkstra(int src);
    void printSolution(double dist[], int parent[], int src);

    private:

    
    //this MapNode struct is how we create our graph of airports and connections
    struct MapNode {
        int key;
        string value;
        int currentWeight;
        vector<int> nodes;
        double x;
        double y;
        int prev;
        int sCC;

        /**
         * Node constructor; sets children to point to `NULL`.
         * @param newKey The object to use as a key
         * @param newValue The templated data element that the constructed
         *  node will hold.
         */
        MapNode(const int& newKey, const string& newValue, double lat, double lon)
            : key(newKey), value(newValue), currentWeight(-1), x(lat), y(lon), prev(-1)
        {
        }
        MapNode() : key(-1), value("n/a"), currentWeight(-1), x(-1), y(-1), prev(-1)
        {}
    };
    double minDistance(double dist[], bool visited[], MapNode & curr);
    //this hash table holds our map
    LPHashTable<int,MapNode> IDTable_;

    vector<MapNode*> airports;
    
    vector<int> hasVisited_;

    vector<pair<int,int>> routes_;
    
    // variables used for SCC
    vector<int> ids;
    vector<int> low;
    vector<bool> onStack;
    //test
};