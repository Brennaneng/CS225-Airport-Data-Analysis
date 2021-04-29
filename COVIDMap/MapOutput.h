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

    string getValue(int key);

    void insertStates();

    
    private:

    vector<pair<bool,string>> allAirports_;

    vector<pair<int,int>> routes_;


    struct Node {
        int key;
        string value;
        int currentWeight;
        vector<Node*> nodes;

        /**
         * Node constructor; sets children to point to `NULL`.
         * @param newKey The object to use as a key
         * @param newValue The templated data element that the constructed
         *  node will hold.
         */
        Node(const int& newKey, const string& newValue)
            : key(newKey), value(newValue), currentWeight(-1)
        {
        }
    };
    AVLTree<int,string> * _tree;

    vector<string> * States; 

};