**CS 225 Data Structures**

**Team Members (alpizar2-bheng2-jorgejc2-miguel5)**

**READFILE Important Information**

1. **Major Code, Data, Results and Their Locations** The files that hold all the code that you will need to run this code are found in the following files: 

* MapOutput.cpp/h - containts all the code for our three algorithms and their helper functions

* 1. vector<int> findSCC (vector<vector<string>> file) - this finds the strongly connected component of our dataset 

* 2. void dijkstra(int src, int des) - this find the shortest path between the source and destination 

* 3. void findPath(int StartID, int finaID) - this finds a bfs path between the source and destination 

* 4. double EulerPath(double lat1, double long1, double lat2, double long2) - the code for this was taken from: https://www.geeksforgeeks.org/program-distance-two-points-earth/

* 5. Struct MapNode - this is used to hold the information from the CSV file 

* 6. LPHashTable<int, MapNode> IDTable_ - this is where our hash table is made with the MapNode that holds all our information 

* ReadFile.cpp/h - contains the code to read the csv files and organize the data 

* 1. vector<vector<string>> read_file() - this is where all the important information of airports_fitered.csv will be stored 

* 2. vector<pair<int , int>> read_routes() - this is where all the routes from routes_filtered.csv will be stored 

* HashTable.cpp/h - contains the code to create the hash table that will help us organize important information 

* main.cpp - this is where we set up for the test cases by getting the file and making the appropriates structs  

* 1. vector<vector<string>> file = read_file() - will initialize the information we need fromm airports_fitered.csv

* 2. vector<pair<int,int>> routeFile = read_routes() - will initialize the routes we need from routes_filtered.csv

* 3. Map airports(file, routeFile) - this will make the map that will have all the information we need to run our test cases 

* Other files in the COVIDMap folder are imported from past labs and helped out with the creation of the hash table 

* Our data is in 2 CSV files those being "airports_fitered.csv", and "routes_filtered.csv"

* Our results will be displayed in the terminal after modifying the main.cpp file and running the code. 

2. **How to Run Our Code** We are under the assumption that you have not cloned our repository so the instructions for that can be accessed here: 

https://docs.github.com/en/github/creating-cloning-and-archiving-repositories/cloning-a-repository

After cloning the repository you will follow these commands:

* 1. To access the correct files you will have to run $ cd alpizar2-bheng2-jorgejc2-miguel5/COVIDMap in the terminal 

* 2. You will then open main.cpp with your preferred source code editor. 

* 3. Next you will look through lines "" - "" of main.cpp to see what test cases you want to run :

* After finding the test case you want to test you will: 

* Find a specific airport. You can open the airport_fitered.csv file with your preferred source code editor and find a specific airport ID and destination ID there. 

* You then will go to your terminal and type $ make && ./COVIDMap "name of algorithm" "start ID" "end ID"

* The algorithm options are "BFS", "DIJKSTRAS", or "SCC". *Disclaimer: the algorithm has to be typed in all caps"

* If you have questions on how to run our test cases you can just run $ ./COVIDMap in the terminal and you will be given more information on how to do so 

* After running the command on the terminal the results will be displayed on the terminal. 

3. **Using Another DataSet** When creating this code we based it on the CSV files we used. That is why our readfile functions and hash table are very specific to accomodate the information we needed such as the coordinates of an airport, there ID and the routes a specific airport can have. If you were to use a different dataset some changes would have to be made in our READFILE.cpp. These changes would cause more changes in later functions such as the Hash table and would be troublesosme since you would have modify our "structs". If you were to use a different dataset the CSV file would have to be exactly in the style of our CSV file. This is why it is recommended to use our CSV file since there is no direct instructions we can give if you were to use a different data set. 




