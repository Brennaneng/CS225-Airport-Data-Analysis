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
#include "lphashtable.h"

using namespace functions;
using namespace std;

class Map{
    public:

    Map();
    
    //Map(); //this will create the binary tree
    Map(vector<vector<string>> file, vector<pair<int,int>> routeFile);
    
    vector<pair<int,string>> printAirports();

    vector<pair<int,int>> printRoutes();

    void readRoutes(vector<pair<int,int>> file);

    double toRadians(const double degree);

    double Eulerpath(double lat1, double long1, double lat2, double long2);
    // string getValue(int key);

    void insertStates();

    vector<int> BFSPath(int finalID);

    double EulerPath(double x1, double x2, double y1, double y2);

    int returnNode(int ID);
    
    int minDistance(int dist[], bool sprSet[]);
    void dijkstra(int src);
    void printSolution(int dist[]);

    private:

    

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

    LPHashTable<int,MapNode> IDTable_;

    vector<MapNode*> airports;
    
    vector<int> hasVisited_;

    int mapStartNode_;

    //vector<AirPortNode> allAirports_;

    vector<MapNode> usedAirports_;

    vector<pair<int,int>> routes_;

    queue<MapNode*> createMapNodes;

};