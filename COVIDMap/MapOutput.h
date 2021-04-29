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
    Map(vector<vector<string> > file); //this takes in the dataset file to be 
    void insertStates();

    struct Node {
        string StateName;
        //index refers to date;
        std::vector<int> stats;
        Node * left;
        Node * right;
    };
    private:
    AVLTree<string,vector<int> > * _tree;

    vector<string> * States; 

};