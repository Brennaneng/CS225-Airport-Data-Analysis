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
    Map(vector<vector<string>> file); //this takes in the dataset file to be 
    void insertStates();

    
    private:
    struct Node {
        int key;
        string value;
        vector<Node*> nodes;

        /**
         * Node constructor; sets children to point to `NULL`.
         * @param newKey The object to use as a key
         * @param newValue The templated data element that the constructed
         *  node will hold.
         */
        Node(const int& newKey, const string& newValue)
            : key(newKey), value(newValue)
        {
        }
    };
    AVLTree<string,vector<int> > * _tree;

    vector<string> * States; 

};