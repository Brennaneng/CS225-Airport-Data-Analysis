**CS 225 Data Structures**

**Project Proposal (alpizar2-bheng2-jorgejc2-miguel5)**

1. **Leading Question** Given a dataset of COVID positive people throughout the US, create a gradient visualization of COVID positive people within a US map PNG based on location of where people became positive.

1. **Dataset Acquisition and Processing** We propose using the http://link.com. We will focus on the US map and major cities located within that map. The data that we will obtain from each case will be state and city. Our graph structure will consist of arrays and a BST. There will be an initial BST of states with coordinate values that the alogrithm can access. The array will be the PNG of the United States which will contain an x, y, and value. 

1. **Graph Algorithms** Once we obtain the state, we will look through a vector of states with a key-value pair of coordinates located in the top-left block of the state in order to reduce the run-time of our algorithm. Once we initialize our traversal at the top-left block of the specified state, the program will choose the main color of the state as the traversing color. Because states are not uniform, if the alogrithm steps out of the state boundary, then it will do nothing. 

One of our algorithms will be Graph output where we will manipulate the PNG of the United States graph in order to reflect visually how severe the case based on color.

The last of our algorithms is going to be a binary search tree (BST) Once there is an active case, it will be incremented into the state counter and it will be placed into a BST ranked based on most covid cases as the most far right value. These will be used to judge the gradient that needs to be colored.f

1. **Timeline**