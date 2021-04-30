#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "avltree.h"
#include "ReadFile.h"
#include <sstream>
#include <fstream>
#include "TreeTraversals/PreorderTraversal.h"
#include "TreeTraversals/InorderTraversal.h"
#include <queue>

using namespace functions;
using namespace std;

class Map{
    public:
    
    Map(); //this will create the binary tree
    Map(vector<vector<string>> file, vector<pair<int,int>> routeFile);
    
    vector<int> printAirports();

    vector<pair<int,int>> printRoutes();

    void readRoutes(vector<pair<int,int>> file);

    vector<pair<int,int>> printRoutes();
    double toRadians(const double degree);
    double Eulerpath(double lat1, double long1, double lat2, double long2);
    // string getValue(int key);

    void insertStates();
    //must generate map before conducting BFSPath
    string generateMap(int startID);

    vector<int> BFSPath(int finalID);

    double EulerPath(double x1, double x2, double y1, double y2);

    int returnNode(int ID);
    
    private:

    

    struct MapNode {
        int key;
        string value;
        int currentWeight;
        vector<MapNode*> nodes;
        MapNode* prev;

        /**
         * Node constructor; sets children to point to `NULL`.
         * @param newKey The object to use as a key
         * @param newValue The templated data element that the constructed
         *  node will hold.
         */
        MapNode(const int& newKey, const string& newValue)
            : key(newKey), value(newValue), currentWeight(-1)
        {
        }
    };
    

    struct AirPortNode{
        bool exists;
        int key;
        string name;
        double x;
        double y;
        MapNode * thisPtr;
        vector<int> destinationIDs;
        vector<double> distances;

        AirPortNode(const bool& exists_, const int& key_, const string& name_,const double& x_, const double& y_) : 
        exists(exists_),key(key_), name(name_),x(x_),y(y_),thisPtr(NULL)
        {}
        AirPortNode() : exists(false),key(0), name("n/a"), x(0), y(0), thisPtr(NULL)
        {}

    };

    int binarySearch(const vector<AirPortNode>& elements, int start, int end, const int& val);
    
    vector<int> hasVisited_;

    MapNode * mapStartNode_;

    vector<AirPortNode> allAirports_;

    vector<AirPortNode> usedAirports_;

    vector<pair<int,int>> routes_;

    AVLTree<int,vector<vector<double>>> * _tree;

    vector<string> * States; 

    queue<MapNode*> createMapNodes;

};