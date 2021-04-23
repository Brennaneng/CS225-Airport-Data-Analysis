#include "avltree.h"
#include "ReadFile.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;
using namespace functions;

int main(){

    cout<< "hello world" << endl;
    AVLTree<int, int> tree;
    tree.insert(1,2);
    tree.insert(4,5);
    tree.insert(5,4);
    std::vector<int> solnTraversal;
    solnTraversal.push_back(4);
    solnTraversal.push_back(1);
    solnTraversal.push_back(5);
    std::vector<string> solnFuncCalls;
    solnFuncCalls.push_back("rotateLeft");

    vector<vector<string> >  dataVector = functions::read_file();
    
    

    return 0;
}