CC = g++
CFLAGS = -Wall -g

COVIDMap: main.o ReadFile.o
	$(CC) $(CFLAGS) -o COVIDMap main.o ReadFile.o

main.o: main.cpp #ReadFile.h AVL/avltree.cpp AVL/avltree_given.cpp AVL/avltree.h AVL/printtree.h
	$(CC) $(CFLAGS) -std=c++11 main.cpp

ReadFile.o: ReadFile.cpp #ReadFile.h
	$(CC) $(CFLAGS) -std=c++11 ReadFile.cpp



# Use the cs225 makefile template:
include cs225/make/cs225.mk

