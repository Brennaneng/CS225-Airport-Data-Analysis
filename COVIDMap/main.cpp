#include "ReadFile.h"
#include "MapOutput.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;
using namespace functions;

int main() {

    // cout<< "hello world" << endl;
    // AVLTree<int, int> tree;
    // tree.insert(1,2);
    // tree.insert(4,5);
    // tree.insert(5,4);
    // vector<int> traversal = tree.getInorderTraversal();
    // for(unsigned i = 0; i < traversal.size(); i++){
    //     cout<<traversal[i]<<" ";
    // }
    // cout<<endl;
    vector<vector<string>> file = read_file();
    vector<pair<int,int>> routeFile = read_routes();
    Map test(file, routeFile);
    vector<int> print = test.printTree();
    for(unsigned i = 0; i < print.size(); i++){
        cout<< print[i] << " " << file[i][1] <<endl;
    }
    vector<pair<int,int>> routes = test.printRoutes();
    for(unsigned i = 0; i < routes.size(); i++){
        cout<< test.getValue(routes[i].first)<< " goes to "<< test.getValue(routes[i].second)<<endl;
    }


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
    
    return 0;
}