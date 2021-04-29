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

using namespace functions;
using namespace std;

class Map{
    public:
    Map(); //this will create the binary tree
    Map(vector<vector<string>> file, vector<pair<int,int>> routeFile);

    vector<int> printTree();

    void readRoutes(vector<pair<int,int>> file);

    vector<pair<int,int>> printRoutes();
    double toRadians(const double degree);
    double Eulerpath(double lat1, double long1, double lat2, double long2);
    // string getValue(int key);

    //void insertStates();

    
    private:

    struct AirPortNode{
        bool exists;
        string name;
        double x;
        double y;

        AirPortNode(const bool& exists_, const string& name_,const double& x_, const double& y_) : exists(exists_), name(name_),x(x_),y(y_)
        {}
        AirPortNode() : exists(NULL), name("n/a"), x(0), y(0)
        {}

    };

    struct MapNode {
        int key;
        string value;
        int currentWeight;
        vector<MapNode*> nodes;

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

    vector<AirPortNode> allAirports_;

    vector<pair<int,int>> routes_;

    AVLTree<int,vector<vector<double>>> * _tree;

    vector<string> * States; 

};