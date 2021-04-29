#include "ReadFile.h"
#include "MapOutput.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;
using namespace functions;

int main() {

    /*cout<< "hello world" << endl;
    AVLTree<int, int> tree;
    tree.insert(1,2);
    tree.insert(4,5);
    tree.insert(5,4);
    vector<int> solnTraversal;
    solnTraversal.push_back(4);
    solnTraversal.push_back(1);
    solnTraversal.push_back(5);
<<<<<<< HEAD
    vector<string> solnFuncCalls;
    solnFuncCalls.push_back("rotateLeft");*/

    /*vector<vector<string> >  dataVector= read_file();
    for(unsigned int i = 0; i < dataVector.size(); i++){
        for(int j =0; j < 3; j++){
            cout<<dataVector[i][j] <<endl;
        }
    }*/
    //Map currMap;
    

    vector<pair<int,int> >  dataVector = functions::read_routes();
    for(unsigned int i = 0; i < dataVector.size(); i++) {
        cout<< (dataVector[i]).first<< " " << (dataVector[i]).second << endl;
    }
=======
    std::vector<string> solnFuncCalls;
    solnFuncCalls.push_back("rotateLeft");*/
    //
    // CSV reading;
    // vector<vector<string> >  dataVector = reading.read_file();
    // for(unsigned int i = 0; i < dataVector.size(); i++){
    //     for(unsigned int j = 0; j < dataVector[0].size(); j++){
    //         cout<<dataVector[i][j] <<" ";
    //     }
    // }
    // if ((dataVector.back()).back() == "/n") {
    //     cout<< (dataVector.back()).back()<< "ok" << endl;
    // } 
    cout<< "hello" <<endl;
    vector<int> hi {111,111};
>>>>>>> 84efd7bbd55a37a2248baa2b38f356181a735cbc
    return 0;
}