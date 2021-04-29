CC = g++
CFLAGS = -Wall -g

COVIDMap: main.o ReadFile.o
	$(CC) $(CFLAGS) -o COVIDMap main.o ReadFile.o

<<<<<<< HEAD
main.o: main.cpp #ReadFile.h AVL/avltree.cpp AVL/avltree_given.cpp AVL/avltree.h AVL/printtree.h
	$(CC) $(CFLAGS) -std=c++11 -c main.cpp

ReadFile.o: ReadFile.cpp #ReadFile.h
	$(CC) $(CFLAGS) -std=c++11 -c ReadFile.cpp

clean:
	rm *.o COVIDMap
=======
main.o: main.cpp 
	$(CC) $(CFLAGS) -std=c++11 -c main.cpp

ReadFile.o: ReadFile.cpp ReadFile.h
	$(CC) $(CFLAGS) -std=c++11 -c ReadFile.cpp 

MapOutput.o: MapOutput.cpp MapOutput.h
	$(CC) $(CFLAGS) -std=c++11 -c MapOutput.cpp 
>>>>>>> 84efd7bbd55a37a2248baa2b38f356181a735cbc

# Use the cs225 makefile template:
include cs225/make/cs225.mk

