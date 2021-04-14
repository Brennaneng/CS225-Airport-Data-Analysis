CC = g++
CFLAGS = -Wall -g

COVIDMap: MapOutput.o MapTree.o binarytree.o binarytree_given.o
	$(CC) $(CFLAGS) -o COVIDMap MapOutput.o MapTree.o binarytree.o binarytree_given.o

MapOutput.o: MapOutput.cpp
	$(CC) $(CFLAGS) -c MapOutput.cpp

MapTree.o: MapTree.cpp 
	$(CC) $(CFLAGS) -c MapTree.cpp 

binarytree.o: binarytree.cpp 
	$(CC) $(CFLAGS) -c binarytree.cpp

binarytree_given.o: binarytree_given.cpp
	$(CC) $(CFLAGS) -c binarytree_given.cpp

clean:
	rm *.o COVIDMap

# include TreeTraversals/
