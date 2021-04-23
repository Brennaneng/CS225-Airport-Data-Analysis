#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "binarytree.h"

class Map{
    public:
    Map(); //this will create the binary tree
    Map(vector<vector<string>> file); //this takes in the dataset file to be organized

    struct Node {
        string StateName;
        //index refers to date;
        std::vector<int> stats;
        Node * left;
        Node * right;
    }
    private:
    BinaryTree<string> * _tree;

}