#include "MapTree.h"
#include "TreeTraversals/PreorderTraversal.h"
#include "TreeTraversals/InorderTraversal.h"
#include "ReadFile.h"
#include <vector>
#include <iostream>
using namespace std;

int main() {

    stateMap hello;
    hello.printHello("ar", "az");
    hello.printPeepeePoopoo();
    vector<vector<string> > * s = read_file();
    for(unsigned int i = 0; i < s->size(); i++){
        vector<string> v = s[i];
        cout << v[0] << endl;
    }


    return 0;
}