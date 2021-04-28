#include "MapOutput.h"
#include "TreeTraversals/PreorderTraversal.h"
#include "TreeTraversals/InorderTraversal.h"
#include "ReadFile.h"
#include "avltree.h"
#include <vector>
#include <iostream>
using namespace std;

//here is where we will create a map object. We will specify what kind of map where are working with meaning
//that if we want a map for deaths, we create a map object called deaths. If we do a map for deaths, then we will
//create a tree of states where each value is a vector full of deaths for each month. If we do a map for positive cases, 
//then we create a tree of states where each value is a vector full of positive cases for each month

//map should have a constructor where it takes a csv file. it will then call the read in file function where 
//a vector of total data is created. then that data will be used to create a binary tree

//Private member: binary tree
//when a binary tree is constructed, it will become the private variable for that map object

//Private member: vector<PNG> mapPictures
//each index will be a map for a certain date. we have to create a function that uses the binary tree to get data,
//and then access this vector, and alter the png image for the corresponding month




//One function we have to consider is editing the Binary tree as we read in the Dataset. In orders
Map::Map(){
    insertStates();
    AVLTree<string,vector<int> > * tree = new AVLTree<string,vector<int> >();
    for(int i = 0; i < 50; i++){
        //vector<int> * empty = new vector<int>;
        vector<int> empty (15);
        //empty->resize(15);
        tree->replace(States[i], empty);
    }
    _tree = tree;
};
Map::Map(vector<vector<string> > file){
    Map();
    for(unsigned i = 0; i < file.size(); i++){
        vector<string> curr_line = file[i];
        string curr_date = curr_line[1];
        string curr_state = curr_line[2];
        string curr_deaths = curr_line[3];
        vector<int> * temp = tree->find(curr_state);
        int date = finddate(curr_date);
        temp->at(date) = curr_deaths;
    }

};
void Map::insertStates(){
    States = new vector<string>{"AK",
"AL",
"AR",
"AZ",
"CA",
"CO",
"CT",
"DE",
"FL",
"GA",
"HI",
"IA",
"ID",
"IL",
"IN",
"KS",
"KY",
"LA",
"MA",
"MD",
"ME",
"MI",
"MN",
"MO",
"MS",
"MT",
"NC",
"ND",
"NE",
"NH",
"NJ",
"NM",
"NV",
"NY",
"OH",
"OK",
"OR",
"PA",
"RI",
"SC",
"SD",
"TN",
"TX",
"UT",
"VA",
"VT",
"WA",
"WI",
"WV",
"WY"};
};